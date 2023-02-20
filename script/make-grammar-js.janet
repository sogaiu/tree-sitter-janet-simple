(import ../lib/common :prefix "")
(import ../lib/jdn-to-js :prefix "")
  
(def src
  (slurp "grammar.jdn"))

(def parsed
  (parse src))

(unless (and (get-val parsed :name)
             (get-val parsed :_tokens)
             (get-val parsed :rules))
  (eprint "Grammar needs at least :name, :_tokens, and :rules.")
  (os/exit 1))

(def grammar-js-as-str
  (gen-js parsed))

(spit "grammar.js" grammar-js-as-str)

