# helpful resources
#
# 1. grammar-schema.json in tree-sitter repos (incomplete though)
# 2. tree-sitter.github.io/tree-sitter/creating-parsers#the-grammar-dsl

(import ./emit-json :prefix "")
(import ./common :prefix "")

########################################################################

# this order might matter
(def grammar-keys-in-order
  [:name
   :word
   :rules
   :extras
   :conflicts
   :precedences
   :externals
   :inline
   :supertypes])

(defn emit-name!
  [grammar buf]
  (def name-maybe
    (get grammar :name))
  (assert (peg/match ~(sequence (range "az" "AZ" "__")
                                (any (range "az" "AZ" "09" "__"))
                                # XXX: not in original schema, but may be it
                                #      should be?
                                -1)
                     name-maybe)
          (string/format "name should be a valid c identifier but isn't: %s"
                         name-maybe))
  #
  (emit-str! name-maybe buf))

(comment

  (let [buf @""]
    (emit-name! {:name "janet_simple"} buf))
  # =>
  @"\"janet_simple\""

  (let [buf @""
        result
        (try
          (emit-name! {:name "2fun"} buf)
          ([err]
            err))]
    (string/has-prefix? "name should be a valid c" result))
  # =>
  true

  (let [buf @""]
    (emit-name! {:name "clojure"} buf))
  # =>
  @"\"clojure\""
  )

(defn emit-word!
  [grammar buf]
  (def word-maybe
    (get grammar :word))
  (def type-of-wm
    (type word-maybe))
  (assert (= :keyword type-of-wm)
          (string/format "word should be a keyword, found a %M"
                         type-of-wm))
  #
  (def word-as-str
    (string word-maybe))
  (assert (peg/match ~(sequence (range "az" "AZ" "__")
                                (any (range "az" "AZ" "09" "__"))
                                -1)
                     word-as-str)
          (string/format "word contains unallowed chars: %s"
                         word-as-str))
  #
  (emit-str! word-as-str buf)
  #
  buf)

(comment

  (let [buf @""]
    (emit-word! {:word :basic_identifier} buf))
  # =>
  @"\"basic_identifier\""

  )

# see "definitions" in grammar-schema.json
#
# * blank-rule
# * string-rule
# * pattern-rule
# * symbol-rule
# * seq-rule
# * choice-rule
# * alias-rule
# * repeat-rule
# * repeat1-rule
# * token-rule <- token, token.immediate
# * field-rule
# * prec-rule <- prec, prec.left, prec.right, prec.dynamic

(defn emit-defs-rule!
  [item buf]
  (def type-of-item (type item))
  (assert (or (= :tuple type-of-item)
              (= :keyword type-of-item)
              (= :string type-of-item))
          (string/format "should be a tuple, keyword, or string, found %M"
                         type-of-item))
  #
  (case type-of-item
    :keyword
    (do
      (emit-sym-obj! item buf)
      # early return
      (break buf))
    #
    :string
    (do
      (emit-str-obj! item buf)
      # early return
      (break buf)))
  # item is a tuple at this point
  (def head (first item))
  #
  (cond
    (index-of head [:repeat :repeat1
                    :token :immediate_token])
    (do
      (emit-start-tc-obj! head buf)
      (emit-defs-rule! (get item 1) buf)
      (emit-end-tc-obj! buf))
    #
    (index-of head [:choice :seq])
    (do
      (emit-start-tm-obj! head buf)
      #
      (each member (slice item 1)
        (emit-defs-rule! member buf)
        (emit-comma-nl! buf))
      (pop-comma-nl-maybe! buf)
      #
      (emit-end-tm-obj! buf))
    #
    (= :optional head)
    (do
      # optional is implemented in terms of CHOICE and BLANK
      (emit-start-tm-obj! "choice" buf)
      #
      (emit-defs-rule! (get item 1) buf)
      (emit-comma-nl! buf)
      (emit-t-obj! "blank" buf)
      #
      (emit-end-tm-obj! buf))
    #
    (index-of head [:prec :prec_dynamic])
    (do
      # prec / prec.dynamic takes 2 arguments
      (def prec-val
        # first argument to prec can be an integer or string
        (let [val (get item 1)
              type-of-v (type val)]
          (cond
            (= :number type-of-v)
            (string val)
            #
            (= :string type-of-v)
            (string "\"" val "\"")
            #
            (errorf "unexpected val: %M" val))))
      (emit-start-tvc-obj! head prec-val buf)
      #
      (emit-defs-rule! (get item 2) buf)
      #
      (emit-end-tvc-obj! buf))
    #
    (index-of head [:prec_left :prec_right])
    (do
      (def n-args
        (dec (length item)))
      # prec.left / prec.right can take 1 or 2 arguments
      (def prec-val
        (cond
          (= 1 n-args)
          "0"
          #
          (= 2 n-args)
          (let [val (get item 1)
                type-of-v (type val)]
            (cond
              (= :number type-of-v)
              (string val)
              #
              (= :string type-of-v)
              (string "\"" val "\"")
              #
              (errorf "unexpected val: %M" val)))
          #
          (errorf "%M takes 1 or 2 arguments, not: %d"
                  head n-args)))
      (emit-start-tvc-obj! head prec-val buf)
      #
      (emit-defs-rule! (get item n-args) buf)
      #
      (emit-end-tvc-obj! buf))
    #
    (= :alias head)
    (do
      # alias takes 2 arguments
      (def alias-name
        (get item 2))
      (def is-named?
        (let [type-of-v (type alias-name)]
          (cond
            (= :keyword type-of-v)
            true
            #
            (= :string type-of-v)
            false
            #
            (errorf "unexpected type for alias-name: %M" alias-name))))
      # may look a bit weird, but don't worry
      (emit-start-tc-obj! head buf)
      (emit-defs-rule! (get item 1) buf)
      (emit-comma-nl! buf)
      (emit-indentation! buf)
      (emit-property! "named" is-named? buf)
      (emit-comma-nl! buf)
      (emit-indentation! buf)
      (emit-property! "value" (string "\"" alias-name "\"") buf)
      (emit-end-obj! buf))
    #
    (= :field head)
    (do
      # field takes 2 arguments
      (emit-start-tnc-obj! head (get item 1) buf)
      #
      (emit-defs-rule! (get item 2) buf)
      #
      (emit-end-tnc-obj! buf))
    #
    (= :regex head)
    (do
      (def re-pattern
        (escape-string (string ;(slice item 1))))
      (emit-tv-obj! "pattern" re-pattern buf))
    # XXX: prec.left and prec.right not done yet
    #
    (errorf "Unknown item: %M" head))
  #
  buf)

(comment

  (let [buf @""]
    (emit-defs-rule! [:regex "[" "0-9" "]"] buf))
  # =>
  @``
   {
     "type": "PATTERN",
     "value": "[0-9]"
   }
   ``

  (let [buf @""]
    (emit-defs-rule! :num_lit buf))
  # =>
  @``
   {
     "type": "SYMBOL",
     "name": "num_lit"
   }
   ``

  (let [buf @""]
    (emit-defs-rule! "nil" buf))
  # =>
  @``
   {
     "type": "STRING",
     "value": "nil"
   }
   ``

  (let [buf @""]
    (emit-defs-rule! [:repeat :_lit] buf))
  # =>
  @``
   {
     "type": "REPEAT",
     "content": {
     "type": "SYMBOL",
     "name": "_lit"
   }
   }
   ``

  (let [buf @""]
    (emit-defs-rule! [:choice "-" "+"] buf))
  # =>
  @``
   {
     "type": "CHOICE",
     "members": [
   {
     "type": "STRING",
     "value": "-"
   },
   {
     "type": "STRING",
     "value": "+"
   }
   ]
   }
   ``

  )

(defn emit-rules!
  [grammar buf]
  (def rules-maybe
    (get grammar :rules))
  (assert (indexed? rules-maybe)
          (string/format "rules should be indexed, found a %M"
                         (type rules-maybe)))
  #
  (def rules rules-maybe)
  #
  (emit-start-obj! buf)
  #
  (each i (range 0 (length rules) 2)
    (def key (get rules i))
    (def expr (get rules (inc i)))
    (emit-indentation! buf)
    (emit-key! key buf)
    (emit-defs-rule! expr buf)
    (emit-comma-nl! buf))
  (pop-comma-nl-maybe! buf)
  #
  (emit-end-obj! buf)
  #
  buf)

(defn emit-extras!
  [grammar buf]
  (def extras-maybe
    (get grammar :extras))
  (def type-of-em
    (type extras-maybe))
  (assert (or (nil? extras-maybe)
              (= :tuple type-of-em))
          (string/format "extras should be a tuple or nil, found a %M"
                         type-of-em))
  (def extras extras-maybe)
  #
  (emit-start-array! buf)
  #
  (each extra extras
    (emit-defs-rule! extra buf)
    (emit-comma-nl! buf))
  (pop-comma-nl-maybe! buf)
  #
  (emit-end-array! buf)
  #
  buf)

(comment

  (let [buf @""]
    (emit-extras! {:extras [[:regex "\\s|\\x0b|\\x0c|\\x00"]
                           [:regex "#.*"]]}
                 buf))
  # =>
  @``
   [
   {
     "type": "PATTERN",
     "value": "\\s|\\x0b|\\x0c|\\x00"
   },
   {
     "type": "PATTERN",
     "value": "#.*"
   }
   ]
   ``

  )

(defn emit-conflicts!
  [grammar buf]
  (def conflicts-maybe
    (get grammar :conflicts))
  (def type-of-em
    (type conflicts-maybe))
  (assert (or (nil? conflicts-maybe)
              (= :tuple type-of-em))
          (string/format "conflicts should be a tuple or nil, found a %M"
                         type-of-em))
  (def conflicts conflicts-maybe)
  #
  (emit-start-array! buf)
  #
  (each conflict conflicts
    # each conflict is expected to be a tuple
    (def type-of-conf
      (type conflict))
    (assert (= :tuple type-of-conf)
            (string/format "conflict should be a tuple, found a %M"
                           type-of-conf))
    #
    (emit-start-array! buf)
    #
    (each item conflict
      (emit-indentation! buf)
      (emit-str! item buf)
      (emit-comma-nl! buf))
    (pop-comma-nl-maybe! buf)
    #
    (emit-end-array! buf)
    #
    (emit-comma-nl! buf))
  (pop-comma-nl-maybe! buf)
  #
  (emit-end-array! buf)
  #
  buf)

(comment

  (let [buf @""]
    (emit-conflicts! {:conflicts [[:constant_primary :primary]
                                 [:primary :implicit_class_handle]]}
                    buf))
  # =>
  @``
   [
   [
     "constant_primary",
     "primary"
   ],
   [
     "primary",
     "implicit_class_handle"
   ]
   ]
   ``
  )

(defn emit-externals!
  [grammar buf]
  (def externals-maybe
    (get grammar :externals))
  (def type-of-em
    (type externals-maybe))
  (assert (or (nil? externals-maybe)
              (= :tuple type-of-em))
          (string/format "externals should be a tuple or nil, found a %M"
                         type-of-em))
  (def externals externals-maybe)
  #
  (emit-start-array! buf)
  #
  (each external externals
    (emit-defs-rule! external buf)
    (emit-comma-nl! buf))
  (pop-comma-nl-maybe! buf)
  #
  (emit-end-array! buf)
  #
  buf)

(comment

  (let [buf @""]
    (emit-externals! {:externals [:long_buf_lit :long_str_lit]}
                    buf))
  # =>
  @``
   [
   {
     "type": "SYMBOL",
     "name": "long_buf_lit"
   },
   {
     "type": "SYMBOL",
     "name": "long_str_lit"
   }
   ]
   ``

  )

(defn emit-precedences!
  [grammar buf]
  (def precedences-maybe
    (get grammar :precedences))
  (def type-of-em
    (type precedences-maybe))
  (assert (or (nil? precedences-maybe)
              (= :tuple type-of-em))
          (string/format "precedences should be a tuple or nil, found a %M"
                         type-of-em))
  (def precedences precedences-maybe)
  #
  (emit-start-array! buf)
  #
  (each precedence precedences
    # each precedence is expected to be a tuple
    (def type-of-prec
      (type precedence))
    (assert (= :tuple type-of-prec)
            (string/format "precedence should be a tuple, found a %M"
                           type-of-prec))
    #
    (emit-start-array! buf)
    #
    (each item precedence
      (emit-defs-rule! item buf)
      (emit-comma-nl! buf))
    (pop-comma-nl-maybe! buf)
    #
    (emit-end-array! buf)
    #
    (emit-comma-nl! buf))
  (pop-comma-nl-maybe! buf)
  #
  (emit-end-array! buf)
  #
  buf)

(comment

  (let [buf @""]
    (emit-precedences! {:precedences [["document_directive" "body_directive"]
                                     ["special" "immediate" "non-immediate"]]}
                      buf))
  # =>
  @``
   [
   [
   {
     "type": "STRING",
     "value": "document_directive"
   },
   {
     "type": "STRING",
     "value": "body_directive"
   }
   ],
   [
   {
     "type": "STRING",
     "value": "special"
   },
   {
     "type": "STRING",
     "value": "immediate"
   },
   {
     "type": "STRING",
     "value": "non-immediate"
   }
   ]
   ]
   ``
  )

(defn emit-inline!
  [grammar buf]
  (def inline-maybe
    (get grammar :inline))
  (def type-of-em
    (type inline-maybe))
  (assert (or (nil? inline-maybe)
              (= :tuple type-of-em))
          (string/format "inline should be a tuple or nil, found a %M"
                         type-of-em))
  (def inline inline-maybe)
  #
  (emit-start-array! buf)
  #
  (each item inline
    (emit-str! item buf)
    (emit-comma-nl! buf))
  (pop-comma-nl-maybe! buf)
  #
  (emit-end-array! buf)
  #
  buf)

(comment

  (let [buf @""]
    (emit-inline! {:inline [:_sym_qualified
                           :_sym_unqualified]}
                    buf))
  # =>
  @``
   [
   "_sym_qualified",
   "_sym_unqualified"
   ]
   ``

  )

(defn emit-supertypes!
  [grammar buf]
  (def supertypes-maybe
    (get grammar :supertypes))
  (def type-of-em
    (type supertypes-maybe))
  (assert (or (nil? supertypes-maybe)
              (= :tuple type-of-em))
          (string/format "supertypes should be a tuple or nil, found a %M"
                         type-of-em))
  (def supertypes supertypes-maybe)
  #
  (emit-start-array! buf)
  #
  (each supertype supertypes
    (emit-defs-rule! supertype buf)
    (emit-comma-nl! buf))
  (pop-comma-nl-maybe! buf)
  #
  (emit-end-array! buf)
  #
  buf)

(comment

  (let [buf @""]
    (emit-supertypes! {:supertypes [:_declaration
                                   :_expression
                                   :_statement
                                   :_type]} buf))
  # =>
  @``
   [
   {
     "type": "SYMBOL",
     "name": "_declaration"
   },
   {
     "type": "SYMBOL",
     "name": "_expression"
   },
   {
     "type": "SYMBOL",
     "name": "_statement"
   },
   {
     "type": "SYMBOL",
     "name": "_type"
   }
   ]
   ``

  )

(defn emit-json!
  [grammar buf]
  (assert (and (get grammar :name)
               (get grammar :rules))
          (string/format "grammar's keys missing name and/or rules: %M"
                         (keys grammar)))
  #
  (emit-start-obj! buf)
  #
  # XXX: consider fancier indentation later
  (each key grammar-keys-in-order
    (when (or (get grammar key)
              # some keys need special handling - dsl.js / grammar.json
              (index-of key [:extras :conflicts :precedences
                             :externals :inline :supertypes]))
      (emit-indentation! buf)
      (emit-key! key buf)
      (case key
        :name
        (emit-name! grammar buf)
        #
        :word
        (emit-word! grammar buf)
        #
        :rules
        (emit-rules! grammar buf)
        #
        :extras
        (emit-extras! grammar buf)
        #
        :conflicts
        (emit-conflicts! grammar buf)
        #
        :precedences
        (emit-precedences! grammar buf)
        #
        :externals
        (emit-externals! grammar buf)
        #
        :inline
        (emit-inline! grammar buf)
        #
        :supertypes
        (emit-supertypes! grammar buf)
        # defensive measure
        (errorf "Unknown key: %M" key))
      #
      (emit-comma-nl! buf)))
  (pop-comma-nl-maybe! buf)
  #
  (emit-end-obj! buf)
  #
  buf)

(defn gen-json
  ``
  Generate `grammar.json` content from an expanded `grammar`.

  `grammar` is typically expanded from `grammar.jdn` by `expand-grammar`
  in `expand.janet`.
  ``
  [grammar]
  #
  (let [buf @""]
    (emit-json! grammar buf)
    buf))

(comment

  # note: extras has implicit value if unspecified
  (gen-json (merge grammar-defaults
                   {:name "hello"
                    :rules [:source "1"]}))
  # =>
  @``
   {
     "name": "hello",
     "rules": {
     "source": {
     "type": "STRING",
     "value": "1"
   }
   },
     "extras": [
   {
     "type": "PATTERN",
     "value": "\\s"
   }
   ],
     "conflicts": [

   ],
     "precedences": [

   ],
     "externals": [

   ],
     "inline": [

   ],
     "supertypes": [

   ]
   }
   ``

  )
