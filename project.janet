(declare-project
  :name "tree-sitter-janet-simple"
  :description "A Janet grammar for tree-sitter"
  :url "https://github.com/sogaiu/tree-sitter-janet-simple"
  :repo "git+https://github.com/sogaiu/tree-sitter-janet-simple")

(def ts-ref "v0.20.8")

(def ts-abi (string 13))

(def proj-dir (os/cwd))

########################################################################

(defn bin-exists?
  [name]
  (with [of (file/temp)]
    (with [ef (file/temp)]
      # of and ef are here to swallow output
      (def r (os/execute ["which" name] :p {:out of :err ef}))
      #
      (zero? r))))

(defn run
  [args]
  (def r (os/execute args :p))
  (def success? (zero? r))
  (when (not success?)
    (eprintf "%n failed with exit code %d" args r))
  #
  success?)

(defn ts-command
  [args]
  (os/setenv "TREE_SITTER_DIR"
             (string proj-dir "/.tree-sitter"))
  (os/setenv "TREE_SITTER_LIBDIR"
             (string proj-dir "/.tree-sitter/lib"))
  (run ["./bin/tree-sitter" ;args]))

########################################################################

# disable `jpm test`
(put (dyn :rules) "test" nil)
(task "test" []
  (print "Sorry, no tests here, try `jpm tasks`."))

## cleanup tasks

(task "clean-src"
  []
  (assert (run ["rm" "-rf"
                "src/parser.c" "src/grammar.json" "src/node-types.json"
                "src/tree_sitter"])))

(task "clean-dot-ts"
  []
  (assert (run ["rm" "-rf" ".tree-sitter/lib/janet_simple.so"])))

(task "clean"
  ["clean-src" "clean-dot-ts"])

## rust tooling and tree-sitter cli existence tasks

# XXX: could check versions?
(task "ensure-rust-bits"
  []
  (and (bin-exists? "cargo") (bin-exists? "rustc")))

(task "ensure-tree-sitter"
  ["ensure-rust-bits"]
  (unless (os/stat "tree-sitter/target/release/tree-sitter")
    (def dir (os/cwd))
    (assert (run ["git" "clone"
                  "https://github.com/tree-sitter/tree-sitter"]))
    (os/cd "tree-sitter")
    (assert (run ["git" "checkout" ts-ref]))
    (assert (run ["cargo" "build" "--release"]))
    # `os/cd` returns `nil` on success...
    (nil? (os/cd dir))))

## diagnostic tasks

(task "dump-lang"
  ["ensure-tree-sitter"]
  (assert (ts-command ["dump-languages"])))

## parser generation tasks

(task "gen-parser"
  ["clean" "ensure-tree-sitter"]
  (assert (ts-command ["generate" "--abi" ts-abi "--no-bindings"])))

## parsing tasks

(task "parse"
  ["gen-parser"]
  (def file-path
    (let [from-args (get (dyn :args) 3)]
      (assert (= :file (os/stat from-args :mode))
              (string/format "need a file-path as an argument: %s"
                             from-args))
      from-args))
  (assert (ts-command ["parse" file-path])))

## testing tasks

(task "corpus-test"
  ["gen-parser"]
  (assert (ts-command ["test"])))

(task "simple-tests"
  ["gen-parser"]
  (assert (run ["janet" "script/run-simple-tests.janet"])))

(task "fetch-some-janet-code"
  []
  (def n
    (if-let [from-args (get (dyn :args) 3)]
      from-args
      3))
  (assert (run ["janet"
                "script/fetch-git-repositories.janet" (string n)])))

(task "real-world-code-test"
  ["gen-parser"]
  (assert (os/stat "repos") 
          (string "samples directory 'repos' doesn't exist\n"
                  "hint: use 'fetch-some-janet-code' task"))
  (assert (run ["janet" "script/parse-tree.janet"])))
