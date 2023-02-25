# fetch (shallow clone) git repositories in git-repos-list.txt

########################################################################

(def proj-dir (os/cwd))

########################################################################

# XXX: modified andrewchambers' original uri handling code

# RFC 3986                   URI Generic Syntax

#    URI           = scheme ":" hier-part [ "?" query ] [ "#" fragment ]

#    hier-part     = "//" authority path-abempty
#                  / path-absolute
#                  / path-rootless
#                  / path-empty

#    URI-reference = URI / relative-ref

#    absolute-URI  = scheme ":" hier-part [ "?" query ]

#    relative-ref  = relative-part [ "?" query ] [ "#" fragment ]

#    relative-part = "//" authority path-abempty
#                  / path-absolute
#                  / path-noscheme
#                  / path-empty

#    scheme        = ALPHA *( ALPHA / DIGIT / "+" / "-" / "." )

#    authority     = [ userinfo "@" ] host [ ":" port ]
#    userinfo      = *( unreserved / pct-encoded / sub-delims / ":" )
#    host          = IP-literal / IPv4address / reg-name
#    port          = *DIGIT

#    IP-literal    = "[" ( IPv6address / IPvFuture  ) "]"

#    IPvFuture     = "v" 1*HEXDIG "." 1*( unreserved / sub-delims / ":" )

#    IPv6address   =                            6( h16 ":" ) ls32
#                  /                       "::" 5( h16 ":" ) ls32
#                  / [               h16 ] "::" 4( h16 ":" ) ls32
#                  / [ *1( h16 ":" ) h16 ] "::" 3( h16 ":" ) ls32
#                  / [ *2( h16 ":" ) h16 ] "::" 2( h16 ":" ) ls32
#                  / [ *3( h16 ":" ) h16 ] "::"    h16 ":"   ls32
#                  / [ *4( h16 ":" ) h16 ] "::"              ls32
#                  / [ *5( h16 ":" ) h16 ] "::"              h16
#                  / [ *6( h16 ":" ) h16 ] "::"

#    h16           = 1*4HEXDIG
#    ls32          = ( h16 ":" h16 ) / IPv4address
#    IPv4address   = dec-octet "." dec-octet "." dec-octet "." dec-octet
#    dec-octet     = DIGIT                 ; 0-9
#                  / %x31-39 DIGIT         ; 10-99
#                  / "1" 2DIGIT            ; 100-199
#                  / "2" %x30-34 DIGIT     ; 200-249
#                  / "25" %x30-35          ; 250-255

#    reg-name      = *( unreserved / pct-encoded / sub-delims )

#    path          = path-abempty    ; begins with "/" or is empty
#                  / path-absolute   ; begins with "/" but not "//"
#                  / path-noscheme   ; begins with a non-colon segment
#                  / path-rootless   ; begins with a segment
#                  / path-empty      ; zero characters

#    path-abempty  = *( "/" segment )
#    path-absolute = "/" [ segment-nz *( "/" segment ) ]
#    path-noscheme = segment-nz-nc *( "/" segment )
#    path-rootless = segment-nz *( "/" segment )
#    path-empty    = 0<pchar>

#    segment       = *pchar
#    segment-nz    = 1*pchar
#    segment-nz-nc = 1*( unreserved / pct-encoded / sub-delims / "@" )
#                  ; non-zero-length segment without any colon ":"

#    pchar         = unreserved / pct-encoded / sub-delims / ":" / "@"

#    query         = *( pchar / "/" / "?" )

#    fragment      = *( pchar / "/" / "?" )

#    pct-encoded   = "%" HEXDIG HEXDIG

#    unreserved    = ALPHA / DIGIT / "-" / "." / "_" / "~"
#    reserved      = gen-delims / sub-delims
#    gen-delims    = ":" / "/" / "?" / "#" / "[" / "]" / "@"
#    sub-delims    = "!" / "$" / "&" / "'" / "(" / ")"
#                  / "*" / "+" / "," / ";" / "="

(defn- named-capture
  [rule &opt name]
  (default name rule)
  ~(sequence (constant ,name) (capture ,rule)))

(def- uri-grammar
  (peg/compile
   ~{:main (sequence :URI-reference (not 1))
     #
     :URI-reference (choice :URI :relative-ref)
     #
     :URI
     (sequence ,(named-capture :scheme) ":"
               :hier-part (opt (sequence "?"
                                         ,(named-capture :query :raw-query)))
               (opt (sequence "#" ,(named-capture :fragment :raw-fragment))))
     #
     :relative-ref
     (sequence :relative-part
               (opt (sequence "?"
                              ,(named-capture :query :raw-query)))
               (opt (sequence "#" ,(named-capture :fragment :raw-fragment))))
     #
     :hier-part
     (choice (sequence "//" :authority :path-abempty)
             :path-absolute
             :path-rootless
             :path-empty)
     #
     :relative-part (choice (sequence "//" :authority :path-abempty)
                            :path-absolute
                            :path-noscheme
                            :path-empty)
     #
     :scheme (sequence :a (any (choice :a :d "+" "-" ".")))
     #
     :authority (sequence (opt (sequence ,(named-capture :userinfo) "@"))
                          ,(named-capture :host)
                          (opt (sequence ":" ,(named-capture :port))))
     #
     :userinfo (any (choice :unreserved :pct-encoded :sub-delims ":"))
     #
     :host (choice :IP-literal :IPv4address :reg-name)
     #
     :port (any :d)
     #
     :IP-literal (sequence "[" (choice :IPv6address :IPvFuture) "]")
     #
     :IPv4address (sequence :dec-octet "."
                            :dec-octet "."
                            :dec-octet "."
                            :dec-octet)
     #
     :IPvFuture (sequence "v" (at-least 1 :hexdig) "."
                          (at-least 1 (sequence :unreserved :sub-delims ":")))
     #
     :IPv6address
     (choice
       (sequence (repeat 6 (sequence :h16 ":")) :ls32)
       (sequence "::" (repeat 5 (sequence :h16 ":")) :ls32)
       (sequence (opt :h16) "::" (repeat 4 (sequence :h16 ":")) :ls32)
       (sequence (opt (sequence (at-most 1 (sequence :h16 ":")) :h16)) "::"
                 (repeat 3 (sequence :h16 ":")) :ls32)
       (sequence (opt (sequence (at-most 2 (sequence :h16 ":")) :h16)) "::"
                 (repeat 2 (sequence :h16 ":")) :ls32)
       (sequence (opt (sequence (at-most 3 (sequence :h16 ":")) :h16)) "::"
                 (sequence :h16 ":") :ls32)
       (sequence (opt (sequence (at-most 4 (sequence :h16 ":")) :h16)) "::"
                 :ls32)
       (sequence (opt (sequence (at-most 5 (sequence :h16 ":")) :h16)) "::"
                 :h16)
       (sequence (opt (sequence (at-most 6 (sequence :h16 ":")) :h16)) "::"))
     #
     :h16 (between 1 4 :hexdig)
     #
     :ls32 (choice (sequence :h16 ":" :h16) :IPv4address)
     #
     :dec-octet (choice (sequence "25" (range "05"))
                        (sequence "2" (range "04") :d)
                        (sequence "1" :d :d)
                        (sequence (range "19") :d) :d)
     #
     :reg-name (any (choice :unreserved :pct-encoded :sub-delims))
     #
     :path (choice :path-abempty
                   :path-absolute
                   :path-noscheme
                   :path-rootless
                   :path-empty)
     :path-abempty ,(named-capture ~(any (sequence "/" :segment)) :raw-path)
     #
     :path-absolute
     ,(named-capture ~(sequence "/"
                                (opt (sequence :segment-nz
                                               (any (sequence "/" :segment)))))
                     :raw-path)
     #
     :path-noscheme
     ,(named-capture ~(sequence :segment-nz-nc
                                (any (sequence "/" :segment))) :raw-path)
     #
     :path-rootless
     ,(named-capture ~(sequence :segment-nz
                                (any (sequence "/" :segment))) :raw-path)
     #
     :path-empty (not :pchar)
     #
     :segment (any :pchar)
     #
     :segment-nz (some :pchar)
     #
     :segment-nz-nc (some (choice :unreserved :pct-encoded :sub-delims "@"))
     #
     :pchar (choice :unreserved :pct-encoded :sub-delims ":" "@")
     #
     :query (any (choice :pchar (set "/?")))
     #
     :fragment (any (choice :pchar (set "/?")))
     #
     :pct-encoded (sequence "%" :hexdig :hexdig)
     #
     :unreserved (choice :a :d (set "-._~"))
     #
     :gen-delims (set ":/?#[]@")
     #
     :sub-delims (set "!$&'()*+,;=")
     #
     :hexdig (choice :d (range "AF") (range "af"))
    }))

(defn parse-raw
  "Parse a uri-reference following rfc3986.

   Returns a table with elements that may include:

   :scheme :host :port :userinfo
   :raw-path :raw-query :raw-fragment

   The returned elements are not normalized or decoded.
   The returned elements are always strings.
   returns nil if the input is not a valid uri.
  "
  [u]
  (when-let [matches (peg/match uri-grammar u)]
    (table ;matches)))

(defn uri-to-dir-path
  [uri]
  (when-let [u (parse-raw uri)
             rp (u :raw-path)
             host (u :host)]
    # XXX: works for our case?
    (string host rp)))

(comment

  (def lines
    (slurp "../data/git-repos-list.txt"))

  (each line (string/split "\n" lines)
    (def url (string/trimr line))
    (print (uri-to-dir-path url)))

  )

(defn mkdir-p
  [path]
  (each idx (string/find-all "/" path)
    (when (< 0 idx)
      (let [curr-path (string/slice path 0 idx)]
        (when (not (os/lstat curr-path))
          (os/mkdir curr-path)))))
  (os/mkdir path))

(comment

  (def lines
    (slurp "../data/git-repos-list.txt"))

  (def repos-path "../repos")

  (os/mkdir repos-path)

  (each line (string/split "\n" lines)
    (when-let [url (string/trimr line)
               path (uri-to-dir-path url)]
      (mkdir-p (string repos-path "/" path))))

  )

########################################################################

(defn git-shallow-clone
  [repos-root url]
  (def old-dir (os/cwd))
  #
  (os/mkdir repos-root)
  (os/cd repos-root)
  #
  (def dest-dir
    (uri-to-dir-path url))
  # skip if dest-dir already exists
  (var res nil)
  (unless (os/stat dest-dir)
    # XXX: no method to check success...
    (mkdir-p dest-dir)
    (set res
      (os/execute ["git"
                   "clone" "--depth=1"
                   url dest-dir]
                  :p)))
  (os/cd old-dir)
  #
  res)

(comment

  (git-shallow-clone "../repos" "https://git.sr.ht/~bakpakin/bee-server")

  )

(defn choose-n
  [list n &opt rng]
  (def actual-n
    (min n (length list)))
  (default rng (math/rng))
  #
  (def index-pool (range 0 (length list)))
  (def new-list @[])
  #
  (for i 0 actual-n
    (let [r-idx (math/rng-int rng (length index-pool))
          index (get index-pool r-idx)
          choice (get list index)]
      (array/push new-list choice)
      (array/remove index-pool r-idx)))
  #
  new-list)

(comment

  (let [an-rng (math/rng (os/cryptorand 8))
        list @[:a :b :c :x :y :z]
        n 3
        choices (choose-n list n an-rng)]
    (truthy?
      (and (= n (length choices))
           (all |(index-of $ list)
                choices)
           (= n (length (table ;(interleave choices choices)))))))
  # =>
  true

  )

(defn main
  [& args]
  (def n
    (if (> (length args) 1)
      (scan-number (get args 1))
      10))
  #
  (def repos-root (string proj-dir "/repos"))
  (os/mkdir repos-root)
  (assert (= :directory
             (os/stat repos-root :mode))
          (string/format "repositories root needs to be a directory: %s"
                         repos-root))
  #
  (def repos-list-path
    "data/git-repos-list.txt")
  (assert (= :file
             (os/stat repos-list-path :mode))
          (string/format "%s should be a file"
                         repos-list-path))
  #
  (def repo-lines
    (slurp repos-list-path))
  (def urls
    (keep |(when (pos? (length $))
             (string/trimr $))
          (string/split "\n" repo-lines)))
  #
  (def actual-n
    (min n (length urls)))
  (def n-urls
    (if (neg? n)
      urls
      (choose-n urls actual-n (math/rng (os/cryptorand 8)))))
  (def results @{})
  #
  (each url n-urls
    # skip git's prompts
    (os/setenv "GIT_TERMINAL_PROMPT" "0")
    (def exit-code
      (git-shallow-clone repos-root url))
    (def results-for-code
      (array/push (or (get results exit-code)
                      @[])
                  url))
    (put results
         exit-code results-for-code))
  #
  (when (not (empty? results))
    (printf "%M" results)
    (printf "Successfully fetched repos: %d" (length (get results 0)))
    (eachk ret results
      (when (not (zero? ret))
        (printf "Error code %d: %d" (length (get results ret)))))))

