(declare-project
  :name "tree-sitter-janet-simple"
  :description "A Janet grammar for tree-sitter"
  :url "https://github.com/sogaiu/tree-sitter-janet-simple"
  :repo "git+https://github.com/sogaiu/tree-sitter-janet-simple")

(def ts-sha
  "c51896d32dcc11a38e41f36e3deb1a6a9c4f4b14")

(def ts-abi (string 13))

(def proj-dir (os/cwd))

(put (dyn :rules) "test" nil)
(task "test" []
  (print "Sorry, no tests here, try `jpm tasks`."))

## cleanup tasks

(task "clean-src" []
  (os/execute ["rm" "-rf"
               "src/parser.c"
               "src/grammar.json"
               "src/node-types.json"
               "src/tree_sitter"]
              :p))

(task "clean-dot-ts" []
  (os/execute ["rm" "-rf"
               ".tree-sitter/lib/janet_simple.so"]
              :p))

(task "clean" ["clean-src" "clean-dot-ts"])

## grammar generation tasks

(task "gen-grammar-json" []
  (os/execute ["janet"
               "script/make-grammar-json.janet"]
              :p))

(task "gen-grammar-js" []
  (os/execute ["janet"
               "script/make-grammar-js.janet"]
              :p))

## rust tooling and tree-sitter cli existence tasks

# XXX: could check versions?
(task "ensure-rust-bits" []
  (defn ensure-bin
    [name]
    (try
      (zero? (let [f (file/temp)
                   r (os/execute ["which" name]
                                 :px
                                 {:out f})]
               (file/close f)
               r))
      ([e]
        (eprintf "%s does not appear to be on PATH" name)
        false)))
  (and (ensure-bin "cargo")
       (ensure-bin "rustc")))

(task "ensure-tree-sitter" ["ensure-rust-bits"]
  (unless (os/stat "tree-sitter/target/release/tree-sitter")
    (def dir (os/cwd))
    (os/execute ["git"
                 "clone"
                 "https://github.com/tree-sitter/tree-sitter"]
                :p)
    (os/cd "tree-sitter")
    (os/execute ["git"
                 "checkout" ts-sha]
                :p)
    (os/execute ["cargo"
                 "build"
                 "--release"]
                :p)
    (os/cd dir)))

## diagnostic tasks

(task "dump-lang" ["ensure-tree-sitter"]
  (os/setenv "TREE_SITTER_DIR"
             (string proj-dir "/.tree-sitter"))
  (os/setenv "TREE_SITTER_LIBDIR"
             (string proj-dir "/.tree-sitter/lib"))
  (os/execute ["./bin/tree-sitter"
               "dump-languages"]
              :p))

## parser generation tasks

(task "gen-parser" ["ensure-tree-sitter" "gen-grammar-json"]
  (os/setenv "TREE_SITTER_DIR"
             (string proj-dir "/.tree-sitter"))
  (os/setenv "TREE_SITTER_LIBDIR"
             (string proj-dir "/.tree-sitter/lib"))
  (os/execute ["./bin/tree-sitter"
               "generate"
               "--abi" ts-abi
               "--no-bindings"
               "grammar.json"]
              :p)
  (os/execute ["cp"
               "grammar.json"
               "src/grammar.json"]
              :p))

(task "ts-gen-parser" ["clean" "ensure-tree-sitter"]
  (os/setenv "TREE_SITTER_DIR"
             (string proj-dir "/.tree-sitter"))
  (os/setenv "TREE_SITTER_LIBDIR"
             (string proj-dir "/.tree-sitter/lib"))
  (os/execute ["./bin/tree-sitter"
               "generate"
               "--abi" ts-abi
               "--no-bindings"]
              :p))

## parsing tasks

(task "parse" ["ensure-tree-sitter" "gen-parser"]
  (def file-path
    (let [from-args (get (dyn :args) 3)]
      (assert (= :file
                 (os/stat from-args :mode))
              (string/format "need a file-path as an argument: %s"
                             from-args))
      from-args))
  (os/setenv "TREE_SITTER_DIR"
             (string proj-dir "/.tree-sitter"))
  (os/setenv "TREE_SITTER_LIBDIR"
             (string proj-dir "/.tree-sitter/lib"))
  (os/execute ["./bin/tree-sitter"
               "parse"
               file-path]
              :p))

(task "ts-parse" ["ensure-tree-sitter" "ts-gen-parser"]
  (def file-path
    (let [from-args (get (dyn :args) 3)]
      (assert (= :file
                 (os/stat from-args :mode))
              (string/format "need a file-path as an argument: %s"
                             from-args))
      from-args))
  (os/setenv "TREE_SITTER_DIR"
             (string proj-dir "/.tree-sitter"))
  (os/setenv "TREE_SITTER_LIBDIR"
             (string proj-dir "/.tree-sitter/lib"))
  (os/execute ["./bin/tree-sitter"
               "parse"
               file-path]
              :p))

## testing tasks

(task "corpus-test" ["clean" "ensure-tree-sitter" "ts-gen-parser"]
  (os/setenv "TREE_SITTER_DIR"
             (string proj-dir "/.tree-sitter"))
  (os/setenv "TREE_SITTER_LIBDIR"
             (string proj-dir "/.tree-sitter/lib"))
  (os/execute ["./bin/tree-sitter"
               "test"]
              :p))

(task "simple-tests" ["clean" "ensure-tree-sitter" "gen-parser"]
  (os/execute ["janet"
               "script/run-simple-tests.janet"]
              :p))

(task "fetch-some-janet-code" []
  (def n
    (if-let [from-args (get (dyn :args) 3)]
      from-args
      3))
  (os/execute ["janet"
               "script/fetch-git-repositories.janet"
               (string n)]
              :p))
