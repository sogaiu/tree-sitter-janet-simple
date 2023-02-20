(import ./common :prefix "")

########################################################################

(defn emit-nl!
  [buf]
  (buffer/push-string buf "\n"))

(defn emit-comma-space!
  [buf]
  (buffer/push-string buf ", "))

(defn pop-comma-space-maybe!
  [buf]
  (when (string/has-suffix? ", " (slice buf -3))
    (buffer/popn buf 2)))

(defn emit-comma-nl!
  [buf]
  (buffer/push-string buf ",\n"))

(defn pop-comma-nl-maybe!
  [buf]
  (when (string/has-suffix? ",\n" (slice buf -3))
    (buffer/popn buf 2)))

########################################################################

(defn emit-id!
  [item buf]
  (buffer/push-string buf (string item)))

# XXX: compare naming with below
(defn emit-sym!
  [item buf]
  (buffer/push-string buf
                      "$."
                      (string item)))

# XXX: compare naming with above
(defn emit-raw-sym!
  [item buf]
  (buffer/push-string buf (string item)))

(defn emit-str!
  [item buf]
  (buffer/push-string buf
                      "\"" (escape-string item) "\""))

(defn emit-num!
  [item buf]
  (buffer/push-string buf (string item)))

########################################################################

(defn emit-key!
  [item buf]
  (buffer/push-string buf "\"" (string item) "\": "))

(defn emit-bare-key!
  [item buf]
  (buffer/push-string buf (string item) ": "))

########################################################################

(defn emit-end-statement!
  [buf]
  (buffer/push-string buf ";"))

########################################################################

(defn emit-start-const-decl!
  [name-kwd buf]
  (buffer/push-string buf
                      "const " (string name-kwd) " = "))

(defn emit-end-const-decl!
  [buf]
  (buffer/push-string buf ";"))

########################################################################

(defn emit-start-func-call!
  [name-kwd buf]
  (buffer/push-string buf
                      (string name-kwd)
                      "("))

(defn emit-end-func-call!
  [buf]
  (buffer/push-string buf ")"))

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

(defn emit-start-arrow-func!
  [buf]
  (buffer/push-string buf "$ =>"))

########################################################################

(defn emit-left-assign!
  [id buf]
  (buffer/push-string buf
                      id " = "))
