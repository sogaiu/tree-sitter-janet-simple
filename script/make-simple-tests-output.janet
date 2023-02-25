(import ../conf/common-paths :prefix "")

########################################################################

(defn parse-and-write
  [src-dir dest-dir]
  (if (os/stat dest-dir)
    (eprintf "warning: %s exists already" dest-dir)
    (os/mkdir dest-dir))

  (var i 0)

  (def tf
    (file/temp))

  (def buf @"")

  (var last-end 0)

  (each fp (os/dir src-dir)

    (def src-fp
      (string src-dir "/" fp))

    (eprintf "src-fp: %s" src-fp)

    (assert (string/has-suffix? ".janet" src-fp)
            (string/format "path should end in .janet: %s" src-fp))

    (def ext-pos
      (last (string/find-all ".janet" fp)))

    (def name-no-ext
      (string/slice fp 0 ext-pos))

    (def dest-fp
      (string dest-dir "/" name-no-ext ".txt"))

    (eprintf "dest-fp: %s" dest-fp)

    # XXX: somehow this keeps appending to tf, ignoring where the current
    #      file position is (as reported by file/tell)
    (os/execute [ts-bin-path
                 "parse" src-fp]
                :p
                {:out tf})

    (file/flush tf)

    (def pos
      (file/tell tf))

    (def n-bytes
      (- pos last-end))

    (file/seek tf :set last-end)

    (set last-end pos)

    (file/read tf n-bytes buf)

    (def of
      (file/open dest-fp :w))

    (file/write of buf)

    (buffer/clear buf)

    (file/close of)

    (++ i))

  (file/close tf)

  #
  i)

(def n-processed
  (parse-and-write input-files-dir output-files-dir))

(printf "%d files processed" n-processed)
