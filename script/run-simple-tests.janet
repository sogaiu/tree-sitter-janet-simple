(def ts-bin-path
  "bin/tree-sitter")

(def input-files-dir
  "test/input")

(def expected-files-dir
  "test/expected")

########################################################################

(defn deprintf
  [fmt & args]
  (when (os/getenv "VERBOSE")
    (eprintf fmt ;args)))

(def tap-version 14)

(defn print-tap-version
  [n]
  (printf "TAP Version %d" n))

########################################################################

(defn run-tests
  [input-dir expected-dir]
  (when (or (not (os/stat input-dir))
            (not (os/stat expected-dir)))
    (eprint "input and expected directories must both exist")
    (break nil))

  (def stats @[])

  (var i 0)

  (def tf
    (file/temp))

  (def actual @"")

  (var last-end 0)

  (def src-paths
    (filter |(= :file
                (os/stat (string input-dir "/" $)
                         :mode))
            (os/dir input-dir)))

  # XXX: tappy doesn't seem to like this
  #(print-tap-version tap-version)

  (var result nil)

  (printf "1..%d" (length src-paths))

  (each fp src-paths

    # result may be set to return value of deep= below
    # which is true or false - nil means test skipped
    (set result nil)

    (def input-fp
      (string input-dir "/" fp))

    (assert (string/has-suffix? ".janet" input-fp)
            (string/format "path should end in .janet: %s" input-fp))

    (def ext-pos
      (last (string/find-all ".janet" fp)))

    (def name-no-ext
      (string/slice fp 0 ext-pos))

    (def expected-fp
      (string expected-dir "/" name-no-ext ".txt"))

    # only makes sense to test if there is an expected value
    (when (os/stat expected-fp)

      # XXX: somehow this keeps appending to tf, ignoring where the current
      #      file position is (as reported by file/tell)
      (def ret
        (os/execute [ts-bin-path
                     "parse" input-fp]
                    :p
                    {:out tf}))

      (deprintf "os/execute returned: %d" ret)

      (file/flush tf)

      (def pos
        (file/tell tf))

      (def n-bytes
        (- pos last-end))

      (deprintf "bytes read according to tell: %d" n-bytes)

      (file/seek tf :set last-end)

      (set last-end pos)

      (file/read tf n-bytes actual)

      (deprintf "length read: %d" (length actual))

      (def expected
        (slurp expected-fp))

      (set result
        (deep= actual expected))

      (deprintf "actual: %M" actual)
      (deprintf "expected: %M" expected)

      (buffer/clear actual))

    (cond
      (true? result)
      (do
        (printf "ok %d" (inc i))
        (array/push stats [i :ok]))
      #
      (false? result)
      (do
        (printf "not ok %d - %s"
                (inc i) input-fp)
        (array/push stats [i :not-ok]))
      #
      (nil? result)
      (do
        (printf "not ok %d - %s # SKIP"
                (inc i) input-fp)
        (array/push stats [i :skip]))
      # defensive
      (eprintf "unexpected result: %M" result))

    (++ i))

  (file/close tf)

  [stats i])

(def test-info
  (run-tests input-files-dir expected-files-dir))

#(printf "%M" test-info)
