function regex(patt) {
  return RegExp(patt);
}

// numbers
const SIGN =
  choice('-', '+');
const DIGIT =
  regex("[0-9]");
const DEC_CHUNK =
  regex("[0-9][0-9_]*");

const HEX_CHUNK =
  regex("[a-fA-F0-9][a-fA-F0-9_]*");

const RADIX =
  choice('2', '3', '4', '5', '6', '7', '8', '9', '10',
         '11', '12', '13', '14', '15', '16', '17', '18', '19', '20',
         '21', '22', '23', '24', '25', '26', '27', '28', '29', '30',
         '31', '32', '33', '34', '35', '36');
const ALPHA =
  regex("[a-zA-Z]");
const ALPHA_NUM =
  regex("[a-zA-Z0-9]");
const RADIX_CHUNK =
  regex("[a-zA-Z0-9][a-zA-Z0-9_]*");

// symbols and keywords
const SYM_CHAR_NO_DIGIT_NO_COLON =
  regex("[" +
        "a-zA-Z" +
        "!$%&*+\\-./<=>?@^_" +
        "]");
// see is_symbol_char_gen in janet's tools/symcharsgen.c
const SYM_CHAR =
  regex("[" +
        "0-9:" +
        "a-zA-Z" +
        "!$%&*+\\-./<=>?@^_" +
        "]");

// strings
const STRING_DOUBLE_QUOTE_CONTENT =
  repeat(choice(regex("[^" +
                      "\\\\" +
                      "\"" +
                      "]"),
                regex("\\\\" +
                      "(.|\\n)"))); // thanks to tree-sitter-haskell

module.exports = grammar({
  name: 'janet_simple',

  extras: $ => [
    // see is_whitespace in janet's parser.c
    regex("\x00|" +
          "\x09|\x0a|\x0b|\x0c|\x0d|" +
          "\x20"),
    $.comment
  ],

  externals: $ => [
    $.long_buf_lit,
    $.long_str_lit
  ],

  rules: {
    // THIS MUST BE FIRST -- even though this doesn't look like it matters
    source: $ =>
      repeat($._lit),

    comment: $ =>
      regex("#.*"),

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
      choice('false',
             'true'),

    kwd_lit: $ =>
      prec(2,
           token(seq(':',
                     repeat(SYM_CHAR)))),

    nil_lit: $ =>
      'nil',

    num_lit: $ =>
      prec(5,
           choice($._radix,
                  $._hex,
		  $._dec)),

    _radix: $ =>
      token(seq(optional(SIGN),
                RADIX,
                'r',
                choice(seq(optional('.'), RADIX_CHUNK),
                       seq(RADIX_CHUNK, '.', optional(RADIX_CHUNK))),
                optional(seq('&',
                             optional(SIGN),
                             repeat1(ALPHA_NUM))),
                optional(seq(':', ALPHA)))),

    _hex: $ =>
      token(seq(optional(SIGN),
                '0x',
                choice(seq(optional('.'), HEX_CHUNK),
                       seq(HEX_CHUNK, '.', optional(HEX_CHUNK))),
                optional(seq(choice('p', 'P'),
                             optional(SIGN),
                             repeat1(DIGIT))),
                optional(seq(':', ALPHA)))),

    _dec: $ =>
      token(seq(optional(SIGN),
                choice(seq(optional('.'), DEC_CHUNK),
                       seq(DEC_CHUNK, '.', optional(DEC_CHUNK))),
                optional(seq(choice('e', 'E'),
                             optional(SIGN),
                             repeat1(DIGIT))),
                optional(seq(':', ALPHA)))),

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
          repeat($._lit),
          ')'),

    sqr_arr_lit: $ =>
      seq('@[',
          repeat($._lit),
          ']'),

    struct_lit: $ =>
      seq('{',
          repeat($._lit),
          '}'),

    tbl_lit: $ =>
      seq('@{',
          repeat($._lit),
          '}'),

    par_tup_lit: $ =>
      seq('(',
          repeat($._lit),
          ')'),

    sqr_tup_lit: $ =>
      seq('[',
          repeat($._lit),
          ']'),

    // macro-related

    qq_lit: $ =>
      seq('~',
          $._lit),

    quote_lit: $ =>
      seq("'",
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
    //   |()
    short_fn_lit: $ =>
      seq('|',
          $._lit),

    // XXX: ?
    splice_lit: $ =>
      seq(';',
          $._lit),

    unquote_lit: $ =>
      seq(',',
          $._lit),

  }
});
