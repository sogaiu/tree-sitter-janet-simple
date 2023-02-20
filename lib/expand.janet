(import ./common :prefix "")

# XXX: use postwalk for tree construction from existing tree

#      for processing :rules, have an "in-progress" table that
#      contains things that have been "expanded" keyed by name
#      (e.g. :_lit)

#      in postwalk's function argument, examine the current "node".
#      if it's something to be "expanded" (e.g. keyword that has a
#      name thats' all uppercase + underscores), look up what it
#      should be replaced with in the in-progress table.  if something
#      is there already, use it.  if there is nothing there for a
#      particular key, initiate a process to build / expand
#      appropriately.  when done, put the result in the in-progress
#      table.  then return to the point after the lookup and use the
#      built result.

#      similar process seems like it should be doable for :_tokens.
#      tokens handling may require at least one more pass or more
#      processing to handle :regex arg concatenation

# XXX: there's no attempt to detect infinite loops

(defn expand-tokens
  [grammar]
  (assert (indexed? grammar)
          (string/format "Expected indexed ds for grammar, but found: %s"
                         (type grammar)))
  (def tokens
    (table ;(get-val grammar :_tokens)))
  (assert (dictionary? tokens)
          (string/format "Expected dictionary for tokens, but found: %s"
                         (type tokens)))
  #
  (def expansions @{})
  # XXX: seems like it could be a little nicer?
  (defn expand-if-needed
    [x]
    (cond
      (and (keyword? x)
           (token-name? x))
      (if-let [replacement (get expansions x)]
        (do
          (deprintf "  found expansion for: %M - %M" x replacement)
          replacement)
        (let [unexpanded (get tokens x)]
          (unless unexpanded
            (errorf "Unexpanded form not found for: %M" x))
          (deprintf "  expanding: %M" x)
          (def expanded
            (postwalk (fn [x]
                        (cond
                          (and (keyword? x)
                               (token-name? x))
                          (let [replacement (expand-if-needed x)]
                            (put expansions
                                 x replacement)
                            replacement)
                          #
                          (do
                            (deprintf "  (i) expansion not needed for: %M" x)
                            x)))
                      unexpanded))
          (deprintf "  expanded: %M to %M" x expanded)
          expanded))
      #
      (do
        (deprintf "  (o) expansion not needed for: %M" x)
        x)))
  #
  # XXX: single pass would be nice?
  #
  # XXX: is swapping the pass order a good idea?  might be in general, but
  #      in practice may be not much difference as :regex arg concat doesn't
  #      require much work anyway?
  #
  # pass 1 - variable substitution
  (eachp [name expr] tokens
    (deprintf "name: %M" name)
    (deprintf "expr: %M" expr)
    #
    (def traversed
      (postwalk expand-if-needed
                expr))
    (put expansions
         name traversed))
  # pass 2 - [:regex ...] argument concatenation
  (postwalk (fn [x]
                (cond
                  (and (tuple? x)
                       (= (first x) :regex))
                  (tuple :regex
                         (string ;(tuple/slice x 1)))
                  #
                  x))
            expansions))

(defn has-unexpanded?
  [dict]
  (def unexpanded @[])
  #
  (eachp [name expr] dict
    (postwalk (fn [x]
                (when (and (keyword? x)
                           (token-name? x))
                  (array/push unexpanded [name x]))
                  x)
              expr))
  (if (empty? unexpanded)
    false
    unexpanded))

(comment

  #(os/setenv "VERBOSE" "1")
  
  (def dict
    (expand-tokens
      [:_tokens
       [:SIGN [:choice "+" "-"]

        :DIGIT [:regex "["
                "0-9"
                "]"]

        :INTEGER [:seq [:repeat1 :DIGIT]
                       [:optional [:regex "[" "MN" "]"]]]

        :NUMBER [:token [:prec 10
                               [:seq [:optional :SIGN]
                                    :INTEGER]]]
        ]]))

  (has-unexpanded? dict)
  # => false

  dict
  # =>
  @{:SIGN [:choice "+" "-"]

    :DIGIT [:regex "[0-9]"]

    :INTEGER [:seq [:repeat1 [:regex "[0-9]"]]
                   [:optional [:regex "[MN]"]]]

    :NUMBER [:token [:prec 10
                           [:seq [:optional [:choice "+" "-"]]
                                 [:seq [:repeat1 [:regex "[0-9]"]]
                                       [:optional [:regex "[MN]"]]]]]]
    }

  )

(comment

  #(os/setenv "VERBOSE" "1")

  (def dict
    (expand-tokens
      [:_tokens
       [:SIGN [:choice "+" "-"]

        :DIGIT [:regex "[0-9]"]

        :HEX_DIGIT [:regex "[" "0-9" "a-f" "A-F" "]"]

        :OCTAL_DIGIT [:regex "[" "0-7" "]"]

        :HEX_NUMBER [:seq "0"
                          [:regex "[xX]"]
                          [:repeat1 :HEX_DIGIT]
                          [:optional "N"]]

        :OCTAL_NUMBER [:seq "0"
                            [:repeat1 :OCTAL_DIGIT]
                            [:optional "N"]]

        :INTEGER [:seq [:repeat1 :DIGIT]
                       [:optional [:regex "[" "MN" "]"]]]

        :NUMBER [:token [:prec 10
                               [:seq [:optional :SIGN]
                                     [:choice :HEX_NUMBER
                                              :OCTAL_NUMBER
                                              :INTEGER]]]]
        ]]))

  (has-unexpanded? dict)
  # =>
  false
  
  )

# XXX: if expand-tokens gets to a nicer point, consider reflecting
#      code here
#
# XXX: in theory, there could be [:regex ...] containing multiple arguments,
#      that's not handled here yet
(defn expand-rules
  [grammar tokens &opt drop-tokens]
  (assert (indexed? grammar)
          (string/format "Expected indexed ds for grammar, but found: %s"
                         (type grammar)))
  (assert (dictionary? tokens)
          (string/format "Expected dictionary for tokens, but found: %s"
                         (type tokens)))
  #
  (def rules
    (get-val grammar :rules))
  (assert (indexed? rules)
          (string/format "Expected indexed ds for rules, but found: %s"
                         (type rules)))
  #
  (defn find-replacement
    [x]
    (let [replacement (get tokens x)]
      (unless replacement
        (errorf "Replacement not found for: %s" x))
      replacement))
  #
  (def expansions @{})
  (eachp [name expr] (table ;rules)
    (put expansions
         name
         (postwalk (fn [x]
                     (cond
                       (and (keyword? x)
                            (token-name? x))
                       (if-let [replacement (get expansions x)]
                         replacement
                         (let [replacement (find-replacement x)]
                           (put expansions
                                x replacement)
                           replacement))
                       #
                       x))
                   expr)))
  (def indexed-expns @[])
  (each i (range 0 (length rules) 2)
    (def key (get rules i))
    (unless (and drop-tokens
                 (token-name? key))
      (array/push indexed-expns key)
      (def expn (get expansions key))
      (array/push indexed-expns expn)))
  #
  indexed-expns)

(defn expand-grammar
  [grammar]
  (def tokens
    (expand-tokens grammar))
  #
  (def rules
    (expand-rules grammar tokens true))
  #
  (def expanded
    (table/to-struct
      (merge grammar-defaults
             (table ;grammar)
             {:rules rules})))
  #
  expanded)

