(import ../conf/common-paths :prefix "")

########################################################################

(comment

  (def src
    ``
    (source [0, 0] - [1, 0]
      (list_lit [0, 0] - [0, 12]
        meta: (meta_lit [0, 0] - [0, 4]
          value: (kwd_lit [0, 1] - [0, 4]
            name: (kwd_name [0, 2] - [0, 4])))
        value: (sym_lit [0, 6] - [0, 7]
          name: (sym_name [0, 6] - [0, 7]))
        value: (num_lit [0, 8] - [0, 9])
        value: (num_lit [0, 10] - [0, 11])))
    ``)

  )

# look at example src above
#
# every line has an opening paren somewhere
#
# 3 cases (in ascending order of complexity):
#
# 1. line starts with open paren
# 2. line has only spaces before first open paren
# 3. line has spaces followed by field name + colon + space,
#    then open paren
#
# in the initial `choice` in the peg below, the 3 cases are listed in
# reverse
#
# goal is to strip:
#
# * the field names (+ colons)
# * the position info
# * extraneous space
#
# this should produce something that tree-sitter's corpus tests
# will tolerate

(def line-peg
  ~(sequence
     (choice (sequence (capture (some " "))
                       (sequence (range "az" "AZ" "__")
                                 (any (range "az" "AZ" "09" "__"))
                                 ": "))
             (sequence (capture (some " "))
                       (to "("))
             "")
     (capture "(")
     (capture (sequence (range "az" "AZ" "__")
                        (any (range "az" "AZ" "09" "__"))))
     (any " ")
     (thru "]")
     (thru "]")
     (capture (any ")"))))

(defn strip-positions
  [src]
  (def res @"")
  (each line (string/split "\n" src)
    # should not fail though
    (when-let [m (peg/match line-peg line)]
      (buffer/push res ;m "\n")))
  res)

(comment

  (def src
    ``
    (source [0, 0] - [1, 0]
      (list_lit [0, 0] - [0, 12]
        meta: (meta_lit [0, 0] - [0, 4]
          value: (kwd_lit [0, 1] - [0, 4]
            name: (kwd_name [0, 2] - [0, 4])))
        value: (sym_lit [0, 6] - [0, 7]
          name: (sym_name [0, 6] - [0, 7]))
        value: (num_lit [0, 8] - [0, 9])
        value: (num_lit [0, 10] - [0, 11])))
    ``)

  (strip-positions src)
  # =>
  @``
   (source
     (list_lit
       (meta_lit
         (kwd_lit
           (kwd_name)))
       (sym_lit
         (sym_name))
       (num_lit)
       (num_lit)))
   ``

  (def src-2
    ``
    (source [0, 0] - [1, 0]
      (set_lit [0, 0] - [0, 16]
        meta: (meta_lit [0, 0] - [0, 12]
          value: (map_lit [0, 1] - [0, 12]
            value: (kwd_lit [0, 2] - [0, 4]
              name: (kwd_name [0, 3] - [0, 4]))
            value: (num_lit [0, 5] - [0, 6])
            value: (kwd_lit [0, 7] - [0, 9]
              name: (kwd_name [0, 8] - [0, 9]))
            value: (num_lit [0, 10] - [0, 11])))))
    ``)

  (strip-positions src-2)
  # =>
  @``
   (source
     (set_lit
       (meta_lit
         (map_lit
           (kwd_lit
             (kwd_name))
           (num_lit)
           (kwd_lit
             (kwd_name))
           (num_lit)))))
   ``

  )

(defn decode-description
  [safe-desc]
  (string/join (map |(let [head (string/slice $ 0 1)
                           rest (string/slice $ 1)]
                       (string (string/ascii-upper head) rest))
                    (string/split "-" safe-desc))
               " "))

(comment

  (decode-description "with-utf8-four-hex-digits-escape")
  # =>
  "With Utf8 Four Hex Digits Escape"

  )

(defn make-corpus-tests
  [input-dir expected-dir out-dir]
  (def equalses-buf
    (buffer/new-filled 72 (chr "=")))

  (def minuses-buf
    (buffer/new-filled 72 (chr "-")))

  (each fp (os/dir input-dir)

    (def i-fp
      (string input-dir "/" fp))

    (def ext-pos
      (last (string/find-all ".janet" fp)))

    (def e-fname
      (string (string/slice fp 0 ext-pos) ".txt"))

    (def e-fp
      (string expected-dir "/" e-fname))

    (when (os/stat e-fp)

      (def [initial safe-desc-and-ext]
        (string/split "-" fp 0 2))
      (def [safe-desc ext]
        (string/split "." safe-desc-and-ext))
      (def desc (decode-description safe-desc))

      (def input (slurp i-fp))
      (def expected (slurp e-fp))

      # prepare output file to append to
      (def o-fp
        (string out-dir "/" initial ".txt"))
      (def of
        (file/open o-fp :a))
      (assert of
              (string/format "failed to open output file: %s" o-fp))
      # append output
      (file/write of equalses-buf)
      (file/write of "\n")
      (file/write of desc)
      (file/write of "\n")
      (file/write of equalses-buf)
      (file/write of "\n\n")
      (file/write of input)
      (file/write of "\n")
      (file/write of minuses-buf)
      (file/write of "\n\n")
      (file/write of (strip-positions expected))
      (file/write of "\n")
      # clean up
      (file/close of))))

(make-corpus-tests input-files-dir
                   expected-files-dir
                   corpus-dir)
