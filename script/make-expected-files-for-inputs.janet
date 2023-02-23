(def expected-file-ext ".txt")

(def proj-dir (os/cwd))

(defn main
  [& args]
  (unless (> (length args) 1)
    (eprintf "need at least one file path, got: %d" (length args))
    (os/exit 1))
  #
  (when-let [src-paths (slice args 1)]
    (each s-path src-paths
      (unless (= :file
                 (os/stat s-path :mode))
        (eprintf "path was not a file: %s" s-path)
        (os/exit 1)))
    #
    (def buf @"")
    #
    (each s-path src-paths
      (def pieces
        (string/split "/" s-path))
      (assert (= "test"
                 (first pieces))
              (string/format "\"test\" expected as root, got: %s"
                             (first pieces)))
      (assert (= "input"
                 (get pieces 1))
              (string/format "\"input\" subdir expected, got: %s"
                             (get pieces 1)))
      # some of this is duplicated from project.janet...
      (os/setenv "TREE_SITTER_DIR"
                 (string proj-dir "/.tree-sitter"))
      (os/setenv "TREE_SITTER_LIBDIR"
                 (string proj-dir "/.tree-sitter/lib"))
      #
      (buffer/clear buf)
      (def tf (file/temp))
      (os/execute ["bin/tree-sitter"
                   "parse" s-path]
                  :p
                  {:out tf})
      (file/seek tf :set 0)
      (file/read tf :all buf)
      (file/close tf)
      #
      (def fname-pos
        (last (string/find-all "/" s-path)))
      (def ext-pos
        (last (string/find-all ".janet" s-path)))
      (def o-path
        (string "test/expected"
                ;(slice pieces 2 -2)
                (string/slice s-path fname-pos ext-pos)
                expected-file-ext))
      #
      (spit o-path buf)
      (print o-path))))

