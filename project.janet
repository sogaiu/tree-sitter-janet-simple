(declare-project
  :name "tree-sitter-janet-simple"
  :description "A Janet grammar for tree-sitter"
  :url "https://github.com/sogaiu/tree-sitter-janet-simple"
  :repo "git+https://github.com/sogaiu/tree-sitter-janet-simple")

(def ts-sha
  "c51896d32dcc11a38e41f36e3deb1a6a9c4f4b14")

(def ts-abi (string 13))

(def proj-dir (os/cwd))

(task "gen-grammar-json" []
  (os/execute ["janet"
               "script/make-grammar-json.janet"]
              :p))

(task "gen-grammar-js" []
  (os/execute ["janet"
               "script/make-grammar-js.janet"]
              :p))

(task "dump-lang" ["ensure-tree-sitter"]
  (os/setenv "TREE_SITTER_DIR"
             (string proj-dir "/.tree-sitter"))
  (os/setenv "TREE_SITTER_LIBDIR"
             (string proj-dir "/.tree-sitter/lib"))
  (os/execute ["./bin/tree-sitter"
               "dump-languages"]
              :p))

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

(task "clean" []
  (os/execute ["rm"
               "-rf"
               "src/parser.c"
               "src/grammar.json"
               "src/node-types.json"
               "src/tree_sitter"]
              :p))

# XXX: having rustup can help
(task "ensure-tree-sitter" []
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
