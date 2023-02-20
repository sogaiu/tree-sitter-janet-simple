# invoke this from the project directory like this:
#
#   janet script/ts-generate-from-jdn.janet

(import ../lib/common :prefix "")
(import ../lib/expand :prefix "")
(import ../lib/jdn-to-json :prefix "")

(defn main
  [& args]
  (def src-path
       "grammar.jdn")
  #
  (def src
    (slurp src-path))
  #
  (def parsed
    (parse src))
  #
  (unless (and (get-val parsed :name)
               (get-val parsed :_tokens)
               (get-val parsed :rules))
    (eprint "Grammar needs at least :name, :_tokens, and :rules.")
    (os/exit 1))
  #
  (def expanded-grammar
    (expand-grammar parsed))
  #
  (when-let [uns (has-unexpanded? (get expanded-grammar :rules))]
    (eprintf "warning unexpanded bits found: %M" uns))
  #
  (def grammar-json-as-str
    (gen-json expanded-grammar))
  #
  (spit "grammar.json" grammar-json-as-str))
