(import ../conf/common-paths :prefix "")

########################################################################

(defn is-dir?
  [path]
  (when-let [path path
             stat (os/stat path)]
    (= :directory (stat :mode))))

(defn is-file?
  ``
  Returns true if `path` is an ordinary file (e.g. not a directory).
  Otherwise, returns false.
  ``
  [path]
  (truthy?
    (when-let [path path
               mode-stat (os/stat path :mode)]
      (= :file mode-stat))))

(def fs-sep
  (if (= :windows (os/which))
    "\\"
    "/"))

(defn path-join
  [left-part right-part &opt sep]
  (default sep fs-sep)
  (string/join @[left-part right-part] sep))

(comment

  (path-join "/root" ".local/share" "/")
  # =>
  "/root/.local/share"

  )

(defn just-files
  ``
  Recursively visit directory tree starting at `path`, accumulating
  file (not directory) paths by default into array `acc`.  If optional
  argument `a-fn` is specified, instead accumulate only file paths
  for which `a-fn` applied to the file path returns a truthy result.
  ``
  [path acc &opt a-fn]
  (default a-fn identity)
  (when (is-dir? path)
    (each thing (os/dir path)
      (def thing-path
        (path-join path thing))
      (cond
        (and (is-file? thing-path)
             (a-fn thing-path))
        (array/push acc thing-path)
        #
        (is-dir? thing-path)
        (just-files thing-path acc a-fn))))
  acc)

(comment

  (def paths @[])

  (just-files (string/join (os/getenv "HOME")
                           "/src/tree-sitter-janet-simple/repos")
              paths
              |(string/has-suffix? ".janet" $))

  )

(defn main
  [& args]
  (def path (get args 1
                 (string (os/cwd) "/repos")))
  (assert (is-dir? path)
          (string/format "expected a directory for: %s" path))

  (def src-paths @[])
  (just-files path
              src-paths
              |(string/has-suffix? ".janet" $))

  (def paths-file "__paths.txt")
  (assert (not (os/stat paths-file))
          (string/format "please move %s out of the way" paths-file))
  (spit paths-file
        (string/join src-paths "\n"))

  (def tf (file/temp))
  (def ret
    (os/execute [ts-bin-path "parse"
                 "--paths" paths-file
                 "--quiet"]
                :p
                {:out tf}))
  (file/flush tf)
  (file/seek tf :set 0)

  (def out-lines
    (file/read tf :all))

  (file/close tf)

  (os/rm paths-file)

  (def results @[])

  (def parse-peg
    ~(sequence (capture (some :S))
               (some " ")
               (capture (thru "ms"))
               (capture (to "("))
               (sequence "("
                         (capture (some :S))
                         " "
                         (capture (to ")"))
                         ")")))

  (var i 0)
  (each line (string/split "\n" out-lines)
    (when (not (empty? line))
      (if-let [parsed (peg/match parse-peg line)]
        (do
          (printf "%M" parsed)
          (++ i))
        (printf "failed to parse: %s" line))))
  #
  (printf "Anomalous events recognized: %d" i))

