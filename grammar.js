function regex(...patts) {
  return RegExp(patts.join(""));
}

// see is_whitespace in janet's parser.c
const WHITESPACE_CHAR =
  regex("\x00|",
        "\x09|\x0a|\x0b|\x0c|\x0d|",
        "\x20");

const WHITESPACE =
  token(repeat1(WHITESPACE_CHAR));

const COMMENT =
  token(regex("#.*\n?"));

// numbers
const SIGN =
  choice('-', '+');
const DIGIT =
  regex("[0-9]");
const DEC_CHUNK =
  seq(repeat1(DIGIT),
      repeat(seq(repeat("_"),
                 repeat1(DIGIT),
                 repeat("_"))));
const HEX_DIGIT =
  regex("[0-9A-Fa-f]");
const HEX_CHUNK =
  seq(repeat1(HEX_DIGIT),
      repeat(seq(repeat("_"),
                 repeat1(HEX_DIGIT),
                 repeat("_"))));
const RADIX =
  choice('2', '3', '4', '5', '6', '7', '8', '9', '10',
         '11', '12', '13', '14', '15', '16', '17', '18', '19', '20',
         '21', '22', '23', '24', '25', '26', '27', '28', '29', '30',
         '31', '32', '33', '34', '35', '36');
const ALPHA_NUM =
  regex("[a-zA-Z0-9]");

// symbols and keywords
const SYM_CHAR_NO_DIGIT_NO_COLON =
  regex("[",
        "a-zA-Z",
        "!$%&*+./<?=>@^_",
        "\u{0100}-\u{10ffff}",
        "-", // order matters here
        "]");
// see is_symbol_char_gen in janet's tools/symcharsgen.c
const SYM_CHAR =
  regex("[",
        "0-9:",
        "a-zA-Z",
        "!$%&*+./<?=>@^_",
        "\u{0100}-\u{10ffff}",
        "-", // order matters here
        "]");

// strings
const STRING_DOUBLE_QUOTE_CONTENT =
  repeat(choice(regex("[^",
                      "\\\\",
                      "\"",
                      "]"),
                regex("\\\\",
                      "(.|\\n)"))); // thanks to tree-sitter-haskell

module.exports = grammar({
  name: 'janet_simple',

  extras: $ =>
    [],

  externals: $ => [
    $.long_buf_lit,
    $.long_str_lit
  ],

  rules: {
    // THIS MUST BE FIRST -- even though this doesn't look like it matters
    source: $ =>
      repeat(choice($._lit,
                    $._gap)),

    _gap: $ =>
      choice($._ws,
             $.comment,
             $.dis_expr),

    _ws: $ =>
      WHITESPACE,

    comment: $ =>
      COMMENT,

    dis_expr: $ =>
      seq("\\#",
          repeat($._gap),
          $._lit),

    _lit: $ =>
      choice($.bool_lit,
             $.buf_lit,
             $.kwd_lit,
             $.long_buf_lit,
             $.long_str_lit,
             $.nil_lit,
             $.num_lit,
             $.str_lit,
             $.sym_lit,
             //
             $.par_arr_lit,
             $.sqr_arr_lit,
             $.struct_lit,
             $.tbl_lit,
             $.par_tup_lit,
             $.sqr_tup_lit,
             //
             $.qq_lit,
             $.quote_lit,
             $.short_fn_lit,
             $.splice_lit,
             $.unquote_lit),

    // simplest things

    bool_lit: $ =>
      // XXX: without the token here, false and true are exposed as
      //      anonymous nodes it seems...
      //      yet, the same does not happen for nil...strange
      token(choice('false',
                   'true')),

    kwd_lit: $ =>
      prec(2,
           token(seq(':',
                     repeat(SYM_CHAR)))),

    nil_lit: $ =>
      'nil',

    num_lit: $ =>
      prec(5,
           choice($._dec,
                  $._hex,
                  $._radix)),

    _dec: $ =>
      token(seq(optional(SIGN),
                choice(DEC_CHUNK,
                       seq(".",
                           repeat(optional("_")),
                           DEC_CHUNK),
                       seq(DEC_CHUNK,
                           ".",
                           repeat(optional("_"))),
                       seq(DEC_CHUNK,
                           ".",
                           repeat(optional("_")),
                           DEC_CHUNK)),
                optional(seq(choice('e', 'E'),
                             optional(SIGN),
                             repeat1(DIGIT))))),

    _hex: $ =>
      token(seq(optional(SIGN),
                '0x',
                choice(HEX_CHUNK,
                       seq(".", HEX_CHUNK),
                       seq(HEX_CHUNK, "."),
                       seq(HEX_CHUNK, ".", HEX_CHUNK)))),

    _radix: $ =>
      token(seq(optional(SIGN),
                seq(RADIX,
                    'r',
                    ALPHA_NUM,
                    repeat(choice(repeat(ALPHA_NUM),
                                  repeat('_'))),
                    optional(seq('&',
                                 optional(SIGN),
                                 repeat1(DIGIT)))))),

    str_lit: $ =>
      token(seq('"',
                STRING_DOUBLE_QUOTE_CONTENT,
                '"')),

    buf_lit: $ =>
      token(seq('@"',
                STRING_DOUBLE_QUOTE_CONTENT,
                '"')),

    sym_lit: $ =>
      token(seq(SYM_CHAR_NO_DIGIT_NO_COLON,
                repeat(SYM_CHAR))),

    // collection-ish things

    par_arr_lit: $ =>
      seq('@(',
          repeat(choice($._lit, $._gap)),
          ')'),

    sqr_arr_lit: $ =>
      seq('@[',
          repeat(choice($._lit, $._gap)),
          ']'),

    struct_lit: $ =>
      seq('{',
          repeat(choice($._lit, $._gap)),
          '}'),

    tbl_lit: $ =>
      seq('@{',
          repeat(choice($._lit, $._gap)),
          '}'),

    par_tup_lit: $ =>
      seq('(',
          repeat(choice($._lit, $._gap)),
          ')'),

    sqr_tup_lit: $ =>
      seq('[',
          repeat(choice($._lit, $._gap)),
          ']'),

    // macro-related

    qq_lit: $ =>
      seq('~',
          repeat($._gap),
          $._lit),

    quote_lit: $ =>
      seq("'",
          repeat($._gap),
          $._lit),

    // following all work at the repl..
    //   |(= $ 1)
    //   |[1 2]
    //   |@[8 9]
    //   |@(:fun :time)
    //   |{:a 1}
    //   |@{:pose :sit}
    //   |'(0)
    //   |~(:x)
    //   |:kwd
    //   |a-sym
    //   |"a-str"
    //   |@"buffer"
    //   |``long-string``
    //   |@``long-buffer``
    //   |false
    //   |nil
    //   |8
    //   ||8, |||8, etc.
    // XXX: |() doesn't work...but don't bother disallowing
    short_fn_lit: $ =>
      seq('|',
          repeat($._gap),
          $._lit),

    // XXX: ?
    splice_lit: $ =>
      seq(';',
          repeat($._gap),
          $._lit),

    unquote_lit: $ =>
      seq(',',
          repeat($._gap),
          $._lit),

  }
});
