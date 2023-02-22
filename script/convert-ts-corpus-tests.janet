(def test-corpus-dir
  "test/corpus")

(def input-files-dir
  "test/input")

########################################################################

(def ts-test-grammar
  ~{:main (some :section)
    :section (sequence :header :code-strs :trees)
    :header (sequence :equalses "\n"
                      (capture (to "\n")) "\n"
                      :equalses "\n")
    :equalses (at-least 8 "=")
    :code-strs (sequence (capture (to (sequence "\n" :minuses "\n")))
                         (sequence "\n" :minuses "\n"))
    :minuses (at-least 3 "-")
    :trees (choice (to :equalses)
                   (to -1))})

(defn desc-to-fs-safe-str
  [desc]
  (->> desc
       (string/replace-all " " "-")
       string/ascii-lower))

(comment

  (desc-to-fs-safe-str "Integer With Sequential Underscores")
  # =>
  "integer-with-sequential-underscores"

  )

(defn convert
  [src-dir dest-dir]
  (assert (and (os/stat src-dir)
               (os/stat dest-dir))
          (string/format "src and dest dirs should exist:\n  %s\n  %s"
                         src-dir
                         dest-dir))

  (def filenames
    (os/dir src-dir))

  (each fn filenames

    (def ext-pos
      (last (string/find-all ".txt" fn)))

    (assert ext-pos
            (string/format "failed to find .txt extension for: %s" fn))

    (def node-name
      (slice fn 0 ext-pos))

    (def src-file-path
      (string src-dir "/" fn))

    (assert (os/stat src-file-path)
            (string/format "path does not exist: %s" src-file-path))

    (def src
      (slurp src-file-path))

    (def parsed
      (peg/match ts-test-grammar src))

    (each i (range 0 (length parsed) 2)
      (def desc
        (get parsed i))
      (def safe-str
        (desc-to-fs-safe-str desc))

      (def input-filename
        (string node-name "-" safe-str ".janet"))

      (def dest-file-path
        (string dest-dir "/" input-filename))

      (spit dest-file-path
            (string/trim (get parsed (inc i))))

      )))

(convert test-corpus-dir input-files-dir)
