# functions for emitting json bits

########################################################################

(import ./common :prefix "")

########################################################################

# glossary
#
# nl -> newline
# key -> key of an object
# property -> property (key, value pair) of an object
# str -> string
# sym -> symbol
# obj -> object
# array -> array
# tc -> type, content
# tm -> type, members
# t -> type
# tnc -> type, name, content
# tv -> type, value

########################################################################

(defn emit-indentation!
  [buf]
  (buffer/push-string buf "  "))

########################################################################

(defn emit-nl!
  [buf]
  (buffer/push-string buf "\n"))

(defn emit-comma-nl!
  [buf]
  (buffer/push-string buf ",\n"))

(defn pop-comma-nl-maybe!
  [buf]
  (when (string/has-suffix? ",\n" (slice buf -3))
    (buffer/popn buf 2)))

########################################################################

(defn emit-key!
  [item buf]
  (buffer/push-string buf "\"" (string item) "\": "))

(defn emit-property!
  [key val buf]
  (buffer/push-string buf
                      "\"" (string key) "\": " (string val)))

(defn emit-str!
  [item buf]
  (buffer/push-string buf "\"" (string item) "\""))

########################################################################

(defn emit-sym-obj!
  [item buf]
  (buffer/push-string buf
                      "{\n"
                      "  \"type\": \"SYMBOL\",\n"
                      "  \"name\": \"" (string item) "\"\n"
                      "}"))

(defn emit-str-obj!
  [item buf]
  (buffer/push-string buf
                      "{\n"
                      "  \"type\": \"STRING\",\n"
                      "  \"value\": \"" (escape-string item) "\"\n"
                      "}"))

########################################################################

(defn emit-start-obj!
  [buf]
  (buffer/push-string buf "{\n"))

(defn emit-end-obj!
  [buf]
  (buffer/push-string buf "\n}"))

########################################################################

(defn emit-start-array!
  [buf]
  (buffer/push-string buf "[\n"))

(defn emit-end-array!
  [buf]
  (buffer/push-string buf "\n]"))

########################################################################

(defn emit-start-tc-obj!
  [item buf]
  (buffer/push-string buf
                      "{\n"
                      "  \"type\": \"" (string/ascii-upper item) "\",\n"
                      "  \"content\": "))

(defn emit-end-tc-obj!
  [buf]
  (emit-end-obj! buf))

########################################################################

(defn emit-start-tm-obj!
  [item buf]
  (buffer/push-string buf
                      "{\n"
                      "  \"type\": \"" (string/ascii-upper item) "\",\n"
                      "  \"members\": [\n"))

(defn emit-end-tm-obj!
  [buf]
  (->> (emit-end-array! buf)
       (emit-end-obj!)))

########################################################################

(defn emit-t-obj!
  [item buf]
  (buffer/push-string buf
                      "{\n"
                      "  \"type\": \"" (string/ascii-upper item) "\"\n"
                      "}"))

########################################################################

(defn emit-start-tvc-obj!
  [item prec buf]
  (buffer/push-string buf
                      "{\n"
                      "  \"type\": \"" (string/ascii-upper item) "\",\n"
                      "  \"value\": " prec ",\n"
                      "  \"content\": "))

(defn emit-end-tvc-obj!
  [buf]
  (emit-end-obj! buf))

########################################################################

(defn emit-start-tnc-obj!
  [item name buf]
  (buffer/push-string buf
                      "{\n"
                      "  \"type\": \"" (string/ascii-upper item) "\",\n"
                      "  \"name\": \"" (string name) "\",\n"
                      "  \"content\": "))

(defn emit-end-tnc-obj!
  [buf]
  (emit-end-obj! buf))

########################################################################

(defn emit-tv-obj!
  [item val buf]
  (buffer/push-string buf
                      "{\n"
                      "  \"type\": \"" (string/ascii-upper item) "\",\n"
                      "  \"value\": \"" val "\"\n"
                      "}"))

