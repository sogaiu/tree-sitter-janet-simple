#include "tree_sitter/parser.h"

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 13
#define STATE_COUNT 56
#define LARGE_STATE_COUNT 55
#define SYMBOL_COUNT 48
#define ALIAS_COUNT 0
#define TOKEN_COUNT 29
#define EXTERNAL_TOKEN_COUNT 2
#define FIELD_COUNT 0
#define MAX_ALIAS_SEQUENCE_LENGTH 3
#define PRODUCTION_ID_COUNT 1

enum ts_symbol_identifiers {
  sym__ws = 1,
  sym_comment = 2,
  anon_sym_BSLASH_POUND = 3,
  sym_bool_lit = 4,
  aux_sym_kwd_lit_token1 = 5,
  sym_nil_lit = 6,
  sym__dec = 7,
  sym__hex = 8,
  sym__radix = 9,
  sym_str_lit = 10,
  sym_buf_lit = 11,
  sym_sym_lit = 12,
  anon_sym_AT_LPAREN = 13,
  anon_sym_RPAREN = 14,
  anon_sym_AT_LBRACK = 15,
  anon_sym_RBRACK = 16,
  anon_sym_LBRACE = 17,
  anon_sym_RBRACE = 18,
  anon_sym_AT_LBRACE = 19,
  anon_sym_LPAREN = 20,
  anon_sym_LBRACK = 21,
  anon_sym_TILDE = 22,
  anon_sym_SQUOTE = 23,
  anon_sym_PIPE = 24,
  anon_sym_SEMI = 25,
  anon_sym_COMMA = 26,
  sym_long_buf_lit = 27,
  sym_long_str_lit = 28,
  sym_source = 29,
  sym__gap = 30,
  sym_dis_expr = 31,
  sym__lit = 32,
  sym_kwd_lit = 33,
  sym_num_lit = 34,
  sym_par_arr_lit = 35,
  sym_sqr_arr_lit = 36,
  sym_struct_lit = 37,
  sym_tbl_lit = 38,
  sym_par_tup_lit = 39,
  sym_sqr_tup_lit = 40,
  sym_qq_lit = 41,
  sym_quote_lit = 42,
  sym_short_fn_lit = 43,
  sym_splice_lit = 44,
  sym_unquote_lit = 45,
  aux_sym_source_repeat1 = 46,
  aux_sym_dis_expr_repeat1 = 47,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [sym__ws] = "_ws",
  [sym_comment] = "comment",
  [anon_sym_BSLASH_POUND] = "\\#",
  [sym_bool_lit] = "bool_lit",
  [aux_sym_kwd_lit_token1] = "kwd_lit_token1",
  [sym_nil_lit] = "nil_lit",
  [sym__dec] = "_dec",
  [sym__hex] = "_hex",
  [sym__radix] = "_radix",
  [sym_str_lit] = "str_lit",
  [sym_buf_lit] = "buf_lit",
  [sym_sym_lit] = "sym_lit",
  [anon_sym_AT_LPAREN] = "@(",
  [anon_sym_RPAREN] = ")",
  [anon_sym_AT_LBRACK] = "@[",
  [anon_sym_RBRACK] = "]",
  [anon_sym_LBRACE] = "{",
  [anon_sym_RBRACE] = "}",
  [anon_sym_AT_LBRACE] = "@{",
  [anon_sym_LPAREN] = "(",
  [anon_sym_LBRACK] = "[",
  [anon_sym_TILDE] = "~",
  [anon_sym_SQUOTE] = "'",
  [anon_sym_PIPE] = "|",
  [anon_sym_SEMI] = ";",
  [anon_sym_COMMA] = ",",
  [sym_long_buf_lit] = "long_buf_lit",
  [sym_long_str_lit] = "long_str_lit",
  [sym_source] = "source",
  [sym__gap] = "_gap",
  [sym_dis_expr] = "dis_expr",
  [sym__lit] = "_lit",
  [sym_kwd_lit] = "kwd_lit",
  [sym_num_lit] = "num_lit",
  [sym_par_arr_lit] = "par_arr_lit",
  [sym_sqr_arr_lit] = "sqr_arr_lit",
  [sym_struct_lit] = "struct_lit",
  [sym_tbl_lit] = "tbl_lit",
  [sym_par_tup_lit] = "par_tup_lit",
  [sym_sqr_tup_lit] = "sqr_tup_lit",
  [sym_qq_lit] = "qq_lit",
  [sym_quote_lit] = "quote_lit",
  [sym_short_fn_lit] = "short_fn_lit",
  [sym_splice_lit] = "splice_lit",
  [sym_unquote_lit] = "unquote_lit",
  [aux_sym_source_repeat1] = "source_repeat1",
  [aux_sym_dis_expr_repeat1] = "dis_expr_repeat1",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [sym__ws] = sym__ws,
  [sym_comment] = sym_comment,
  [anon_sym_BSLASH_POUND] = anon_sym_BSLASH_POUND,
  [sym_bool_lit] = sym_bool_lit,
  [aux_sym_kwd_lit_token1] = aux_sym_kwd_lit_token1,
  [sym_nil_lit] = sym_nil_lit,
  [sym__dec] = sym__dec,
  [sym__hex] = sym__hex,
  [sym__radix] = sym__radix,
  [sym_str_lit] = sym_str_lit,
  [sym_buf_lit] = sym_buf_lit,
  [sym_sym_lit] = sym_sym_lit,
  [anon_sym_AT_LPAREN] = anon_sym_AT_LPAREN,
  [anon_sym_RPAREN] = anon_sym_RPAREN,
  [anon_sym_AT_LBRACK] = anon_sym_AT_LBRACK,
  [anon_sym_RBRACK] = anon_sym_RBRACK,
  [anon_sym_LBRACE] = anon_sym_LBRACE,
  [anon_sym_RBRACE] = anon_sym_RBRACE,
  [anon_sym_AT_LBRACE] = anon_sym_AT_LBRACE,
  [anon_sym_LPAREN] = anon_sym_LPAREN,
  [anon_sym_LBRACK] = anon_sym_LBRACK,
  [anon_sym_TILDE] = anon_sym_TILDE,
  [anon_sym_SQUOTE] = anon_sym_SQUOTE,
  [anon_sym_PIPE] = anon_sym_PIPE,
  [anon_sym_SEMI] = anon_sym_SEMI,
  [anon_sym_COMMA] = anon_sym_COMMA,
  [sym_long_buf_lit] = sym_long_buf_lit,
  [sym_long_str_lit] = sym_long_str_lit,
  [sym_source] = sym_source,
  [sym__gap] = sym__gap,
  [sym_dis_expr] = sym_dis_expr,
  [sym__lit] = sym__lit,
  [sym_kwd_lit] = sym_kwd_lit,
  [sym_num_lit] = sym_num_lit,
  [sym_par_arr_lit] = sym_par_arr_lit,
  [sym_sqr_arr_lit] = sym_sqr_arr_lit,
  [sym_struct_lit] = sym_struct_lit,
  [sym_tbl_lit] = sym_tbl_lit,
  [sym_par_tup_lit] = sym_par_tup_lit,
  [sym_sqr_tup_lit] = sym_sqr_tup_lit,
  [sym_qq_lit] = sym_qq_lit,
  [sym_quote_lit] = sym_quote_lit,
  [sym_short_fn_lit] = sym_short_fn_lit,
  [sym_splice_lit] = sym_splice_lit,
  [sym_unquote_lit] = sym_unquote_lit,
  [aux_sym_source_repeat1] = aux_sym_source_repeat1,
  [aux_sym_dis_expr_repeat1] = aux_sym_dis_expr_repeat1,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [sym__ws] = {
    .visible = false,
    .named = true,
  },
  [sym_comment] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_BSLASH_POUND] = {
    .visible = true,
    .named = false,
  },
  [sym_bool_lit] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_kwd_lit_token1] = {
    .visible = false,
    .named = false,
  },
  [sym_nil_lit] = {
    .visible = true,
    .named = true,
  },
  [sym__dec] = {
    .visible = false,
    .named = true,
  },
  [sym__hex] = {
    .visible = false,
    .named = true,
  },
  [sym__radix] = {
    .visible = false,
    .named = true,
  },
  [sym_str_lit] = {
    .visible = true,
    .named = true,
  },
  [sym_buf_lit] = {
    .visible = true,
    .named = true,
  },
  [sym_sym_lit] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_AT_LPAREN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RPAREN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_AT_LBRACK] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RBRACK] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LBRACE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RBRACE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_AT_LBRACE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LPAREN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LBRACK] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_TILDE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_SQUOTE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_PIPE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_SEMI] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_COMMA] = {
    .visible = true,
    .named = false,
  },
  [sym_long_buf_lit] = {
    .visible = true,
    .named = true,
  },
  [sym_long_str_lit] = {
    .visible = true,
    .named = true,
  },
  [sym_source] = {
    .visible = true,
    .named = true,
  },
  [sym__gap] = {
    .visible = false,
    .named = true,
  },
  [sym_dis_expr] = {
    .visible = true,
    .named = true,
  },
  [sym__lit] = {
    .visible = false,
    .named = true,
  },
  [sym_kwd_lit] = {
    .visible = true,
    .named = true,
  },
  [sym_num_lit] = {
    .visible = true,
    .named = true,
  },
  [sym_par_arr_lit] = {
    .visible = true,
    .named = true,
  },
  [sym_sqr_arr_lit] = {
    .visible = true,
    .named = true,
  },
  [sym_struct_lit] = {
    .visible = true,
    .named = true,
  },
  [sym_tbl_lit] = {
    .visible = true,
    .named = true,
  },
  [sym_par_tup_lit] = {
    .visible = true,
    .named = true,
  },
  [sym_sqr_tup_lit] = {
    .visible = true,
    .named = true,
  },
  [sym_qq_lit] = {
    .visible = true,
    .named = true,
  },
  [sym_quote_lit] = {
    .visible = true,
    .named = true,
  },
  [sym_short_fn_lit] = {
    .visible = true,
    .named = true,
  },
  [sym_splice_lit] = {
    .visible = true,
    .named = true,
  },
  [sym_unquote_lit] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_source_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_dis_expr_repeat1] = {
    .visible = false,
    .named = false,
  },
};

static const TSSymbol ts_alias_sequences[PRODUCTION_ID_COUNT][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
};

static const uint16_t ts_non_terminal_alias_map[] = {
  0,
};

static inline bool sym_sym_lit_character_set_1(int32_t c) {
  return (c < ','
    ? (c < '"'
      ? (c < 0
        ? c == 0
        : c <= ' ')
      : (c <= '#' || (c >= '\'' && c <= ')')))
    : (c <= ',' || (c < '`'
      ? (c < '['
        ? c == ';'
        : c <= ']')
      : (c <= '`' || (c >= '{' && c <= 255)))));
}

static inline bool sym_sym_lit_character_set_2(int32_t c) {
  return (c < ','
    ? (c < '#'
      ? (c < 0
        ? c == 0
        : c <= ' ')
      : (c <= '#' || (c >= '\'' && c <= ')')))
    : (c <= ',' || (c < '`'
      ? (c < '\\'
        ? c == ';'
        : c <= ']')
      : (c <= '`' || (c >= '|' && c <= 255)))));
}

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  switch (state) {
    case 0:
      if (eof) ADVANCE(17);
      if (!eof && lookahead == 0 ||
          ('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(18);
      if (lookahead == '"') ADVANCE(1);
      if (lookahead == '#') ADVANCE(20);
      if (lookahead == '\'') ADVANCE(96);
      if (lookahead == '(') ADVANCE(93);
      if (lookahead == ')') ADVANCE(87);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(64);
      if (lookahead == ',') ADVANCE(99);
      if (lookahead == '.') ADVANCE(66);
      if (lookahead == '0') ADVANCE(26);
      if (lookahead == '1') ADVANCE(30);
      if (lookahead == '2') ADVANCE(31);
      if (lookahead == '3') ADVANCE(29);
      if (('4' <= lookahead && lookahead <= '9')) ADVANCE(25);
      if (lookahead == ':') ADVANCE(23);
      if (lookahead == ';') ADVANCE(98);
      if (lookahead == '@') ADVANCE(63);
      if (lookahead == '[') ADVANCE(94);
      if (lookahead == '\\') ADVANCE(3);
      if (lookahead == ']') ADVANCE(89);
      if (lookahead == 'f') ADVANCE(71);
      if (lookahead == 'n') ADVANCE(73);
      if (lookahead == 't') ADVANCE(76);
      if (lookahead == '{') ADVANCE(90);
      if (lookahead == '|') ADVANCE(97);
      if (lookahead == '}') ADVANCE(91);
      if (lookahead == '~') ADVANCE(95);
      if (lookahead != 0 &&
          (lookahead < 1 || 31 < lookahead) &&
          lookahead != '`' &&
          (lookahead < 127 || 255 < lookahead)) ADVANCE(85);
      END_STATE();
    case 1:
      if (lookahead == '"') ADVANCE(61);
      if (lookahead == '\\') ADVANCE(15);
      if (lookahead != 0) ADVANCE(1);
      END_STATE();
    case 2:
      if (lookahead == '"') ADVANCE(62);
      if (lookahead == '\\') ADVANCE(16);
      if (lookahead != 0) ADVANCE(2);
      END_STATE();
    case 3:
      if (lookahead == '#') ADVANCE(21);
      END_STATE();
    case 4:
      if (lookahead == '.') ADVANCE(13);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(47);
      END_STATE();
    case 5:
      if (lookahead == '_') ADVANCE(5);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(28);
      END_STATE();
    case 6:
      if (lookahead == '_') ADVANCE(6);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(48);
      END_STATE();
    case 7:
      if (lookahead == '_') ADVANCE(7);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(41);
      END_STATE();
    case 8:
      if (lookahead == '_') ADVANCE(8);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(51);
      END_STATE();
    case 9:
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(11);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(45);
      END_STATE();
    case 10:
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(12);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(59);
      END_STATE();
    case 11:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(45);
      END_STATE();
    case 12:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(59);
      END_STATE();
    case 13:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(52);
      END_STATE();
    case 14:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(57);
      END_STATE();
    case 15:
      if (lookahead != 0) ADVANCE(1);
      END_STATE();
    case 16:
      if (lookahead != 0) ADVANCE(2);
      END_STATE();
    case 17:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 18:
      ACCEPT_TOKEN(sym__ws);
      if (!eof && lookahead == 0 ||
          ('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(18);
      END_STATE();
    case 19:
      ACCEPT_TOKEN(sym_comment);
      END_STATE();
    case 20:
      ACCEPT_TOKEN(sym_comment);
      if (lookahead == '\n') ADVANCE(19);
      if (lookahead != 0) ADVANCE(20);
      END_STATE();
    case 21:
      ACCEPT_TOKEN(anon_sym_BSLASH_POUND);
      END_STATE();
    case 22:
      ACCEPT_TOKEN(sym_bool_lit);
      if (!sym_sym_lit_character_set_1(lookahead)) ADVANCE(85);
      END_STATE();
    case 23:
      ACCEPT_TOKEN(aux_sym_kwd_lit_token1);
      if (!sym_sym_lit_character_set_1(lookahead)) ADVANCE(23);
      END_STATE();
    case 24:
      ACCEPT_TOKEN(sym_nil_lit);
      if (!sym_sym_lit_character_set_1(lookahead)) ADVANCE(85);
      END_STATE();
    case 25:
      ACCEPT_TOKEN(sym__dec);
      if (lookahead == '.') ADVANCE(39);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(9);
      if (lookahead == '_') ADVANCE(5);
      if (lookahead == 'r') ADVANCE(14);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(28);
      END_STATE();
    case 26:
      ACCEPT_TOKEN(sym__dec);
      if (lookahead == '.') ADVANCE(39);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(9);
      if (lookahead == '_') ADVANCE(5);
      if (lookahead == 'x') ADVANCE(4);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(28);
      END_STATE();
    case 27:
      ACCEPT_TOKEN(sym__dec);
      if (lookahead == '.') ADVANCE(39);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(9);
      if (lookahead == '_') ADVANCE(28);
      if (lookahead == 'r') ADVANCE(14);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(28);
      END_STATE();
    case 28:
      ACCEPT_TOKEN(sym__dec);
      if (lookahead == '.') ADVANCE(39);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(9);
      if (lookahead == '_') ADVANCE(28);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(28);
      END_STATE();
    case 29:
      ACCEPT_TOKEN(sym__dec);
      if (lookahead == '.') ADVANCE(39);
      if (('0' <= lookahead && lookahead <= '6')) ADVANCE(27);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(9);
      if (lookahead == '_') ADVANCE(5);
      if (lookahead == 'r') ADVANCE(14);
      if (('7' <= lookahead && lookahead <= '9')) ADVANCE(28);
      END_STATE();
    case 30:
      ACCEPT_TOKEN(sym__dec);
      if (lookahead == '.') ADVANCE(39);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(27);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(9);
      if (lookahead == '_') ADVANCE(5);
      END_STATE();
    case 31:
      ACCEPT_TOKEN(sym__dec);
      if (lookahead == '.') ADVANCE(39);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(27);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(9);
      if (lookahead == '_') ADVANCE(5);
      if (lookahead == 'r') ADVANCE(14);
      END_STATE();
    case 32:
      ACCEPT_TOKEN(sym__dec);
      if (lookahead == '.') ADVANCE(42);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(79);
      if (lookahead == '_') ADVANCE(33);
      if (lookahead == 'r') ADVANCE(84);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(33);
      if (!sym_sym_lit_character_set_1(lookahead)) ADVANCE(85);
      END_STATE();
    case 33:
      ACCEPT_TOKEN(sym__dec);
      if (lookahead == '.') ADVANCE(42);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(79);
      if (lookahead == '_') ADVANCE(33);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(33);
      if (!sym_sym_lit_character_set_1(lookahead)) ADVANCE(85);
      END_STATE();
    case 34:
      ACCEPT_TOKEN(sym__dec);
      if (lookahead == '.') ADVANCE(42);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(79);
      if (lookahead == '_') ADVANCE(68);
      if (lookahead == 'r') ADVANCE(84);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(33);
      if (!sym_sym_lit_character_set_1(lookahead)) ADVANCE(85);
      END_STATE();
    case 35:
      ACCEPT_TOKEN(sym__dec);
      if (lookahead == '.') ADVANCE(42);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(79);
      if (lookahead == '_') ADVANCE(68);
      if (lookahead == 'x') ADVANCE(65);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(33);
      if (!sym_sym_lit_character_set_1(lookahead)) ADVANCE(85);
      END_STATE();
    case 36:
      ACCEPT_TOKEN(sym__dec);
      if (lookahead == '.') ADVANCE(42);
      if (('0' <= lookahead && lookahead <= '6')) ADVANCE(32);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(79);
      if (lookahead == '_') ADVANCE(68);
      if (lookahead == 'r') ADVANCE(84);
      if (('7' <= lookahead && lookahead <= '9')) ADVANCE(33);
      if (!sym_sym_lit_character_set_1(lookahead)) ADVANCE(85);
      END_STATE();
    case 37:
      ACCEPT_TOKEN(sym__dec);
      if (lookahead == '.') ADVANCE(42);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(32);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(79);
      if (lookahead == '_') ADVANCE(68);
      if (lookahead == 'r') ADVANCE(84);
      if (!sym_sym_lit_character_set_1(lookahead)) ADVANCE(85);
      END_STATE();
    case 38:
      ACCEPT_TOKEN(sym__dec);
      if (lookahead == '.') ADVANCE(42);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(32);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(79);
      if (lookahead == '_') ADVANCE(68);
      if (!sym_sym_lit_character_set_1(lookahead)) ADVANCE(85);
      END_STATE();
    case 39:
      ACCEPT_TOKEN(sym__dec);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(9);
      if (lookahead == '_') ADVANCE(39);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(40);
      END_STATE();
    case 40:
      ACCEPT_TOKEN(sym__dec);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(9);
      if (lookahead == '_') ADVANCE(7);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(41);
      END_STATE();
    case 41:
      ACCEPT_TOKEN(sym__dec);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(9);
      if (lookahead == '_') ADVANCE(41);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(41);
      END_STATE();
    case 42:
      ACCEPT_TOKEN(sym__dec);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(79);
      if (lookahead == '_') ADVANCE(42);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(44);
      if (!sym_sym_lit_character_set_1(lookahead)) ADVANCE(85);
      END_STATE();
    case 43:
      ACCEPT_TOKEN(sym__dec);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(79);
      if (lookahead == '_') ADVANCE(43);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(43);
      if (!sym_sym_lit_character_set_1(lookahead)) ADVANCE(85);
      END_STATE();
    case 44:
      ACCEPT_TOKEN(sym__dec);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(79);
      if (lookahead == '_') ADVANCE(70);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(43);
      if (!sym_sym_lit_character_set_1(lookahead)) ADVANCE(85);
      END_STATE();
    case 45:
      ACCEPT_TOKEN(sym__dec);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(45);
      END_STATE();
    case 46:
      ACCEPT_TOKEN(sym__dec);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(46);
      if (!sym_sym_lit_character_set_1(lookahead)) ADVANCE(85);
      END_STATE();
    case 47:
      ACCEPT_TOKEN(sym__hex);
      if (lookahead == '.') ADVANCE(55);
      if (lookahead == '_') ADVANCE(6);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(48);
      END_STATE();
    case 48:
      ACCEPT_TOKEN(sym__hex);
      if (lookahead == '.') ADVANCE(55);
      if (lookahead == '_') ADVANCE(48);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(48);
      END_STATE();
    case 49:
      ACCEPT_TOKEN(sym__hex);
      if (lookahead == '.') ADVANCE(56);
      if (lookahead == '_') ADVANCE(67);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(50);
      if (!sym_sym_lit_character_set_1(lookahead)) ADVANCE(85);
      END_STATE();
    case 50:
      ACCEPT_TOKEN(sym__hex);
      if (lookahead == '.') ADVANCE(56);
      if (lookahead == '_') ADVANCE(50);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(50);
      if (!sym_sym_lit_character_set_1(lookahead)) ADVANCE(85);
      END_STATE();
    case 51:
      ACCEPT_TOKEN(sym__hex);
      if (lookahead == '_') ADVANCE(51);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(51);
      END_STATE();
    case 52:
      ACCEPT_TOKEN(sym__hex);
      if (lookahead == '_') ADVANCE(8);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(51);
      END_STATE();
    case 53:
      ACCEPT_TOKEN(sym__hex);
      if (lookahead == '_') ADVANCE(53);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(53);
      if (!sym_sym_lit_character_set_1(lookahead)) ADVANCE(85);
      END_STATE();
    case 54:
      ACCEPT_TOKEN(sym__hex);
      if (lookahead == '_') ADVANCE(69);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(53);
      if (!sym_sym_lit_character_set_1(lookahead)) ADVANCE(85);
      END_STATE();
    case 55:
      ACCEPT_TOKEN(sym__hex);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(52);
      END_STATE();
    case 56:
      ACCEPT_TOKEN(sym__hex);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(54);
      if (!sym_sym_lit_character_set_1(lookahead)) ADVANCE(85);
      END_STATE();
    case 57:
      ACCEPT_TOKEN(sym__radix);
      if (lookahead == '&') ADVANCE(10);
      if (lookahead == '_') ADVANCE(57);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(57);
      END_STATE();
    case 58:
      ACCEPT_TOKEN(sym__radix);
      if (lookahead == '&') ADVANCE(80);
      if (lookahead == '_') ADVANCE(58);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(58);
      if (lookahead != 0 &&
          lookahead > ' ' &&
          lookahead != '"' &&
          lookahead != '#' &&
          (lookahead < '\'' || ')' < lookahead) &&
          lookahead != ',' &&
          lookahead != ';' &&
          (lookahead < '[' || ']' < lookahead) &&
          (lookahead < '`' || 255 < lookahead)) ADVANCE(85);
      END_STATE();
    case 59:
      ACCEPT_TOKEN(sym__radix);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(59);
      END_STATE();
    case 60:
      ACCEPT_TOKEN(sym__radix);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(60);
      if (!sym_sym_lit_character_set_1(lookahead)) ADVANCE(85);
      END_STATE();
    case 61:
      ACCEPT_TOKEN(sym_str_lit);
      END_STATE();
    case 62:
      ACCEPT_TOKEN(sym_buf_lit);
      END_STATE();
    case 63:
      ACCEPT_TOKEN(sym_sym_lit);
      if (lookahead == '"') ADVANCE(2);
      if (lookahead == '(') ADVANCE(86);
      if (lookahead == '[') ADVANCE(88);
      if (lookahead == '{') ADVANCE(92);
      if (!sym_sym_lit_character_set_2(lookahead)) ADVANCE(85);
      END_STATE();
    case 64:
      ACCEPT_TOKEN(sym_sym_lit);
      if (lookahead == '.') ADVANCE(66);
      if (lookahead == '0') ADVANCE(35);
      if (lookahead == '1') ADVANCE(38);
      if (lookahead == '2') ADVANCE(37);
      if (lookahead == '3') ADVANCE(36);
      if (('4' <= lookahead && lookahead <= '9')) ADVANCE(34);
      if (!sym_sym_lit_character_set_1(lookahead)) ADVANCE(85);
      END_STATE();
    case 65:
      ACCEPT_TOKEN(sym_sym_lit);
      if (lookahead == '.') ADVANCE(83);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(49);
      if (!sym_sym_lit_character_set_1(lookahead)) ADVANCE(85);
      END_STATE();
    case 66:
      ACCEPT_TOKEN(sym_sym_lit);
      if (lookahead == '_') ADVANCE(66);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(44);
      if (!sym_sym_lit_character_set_1(lookahead)) ADVANCE(85);
      END_STATE();
    case 67:
      ACCEPT_TOKEN(sym_sym_lit);
      if (lookahead == '_') ADVANCE(67);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(50);
      if (!sym_sym_lit_character_set_1(lookahead)) ADVANCE(85);
      END_STATE();
    case 68:
      ACCEPT_TOKEN(sym_sym_lit);
      if (lookahead == '_') ADVANCE(68);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(33);
      if (!sym_sym_lit_character_set_1(lookahead)) ADVANCE(85);
      END_STATE();
    case 69:
      ACCEPT_TOKEN(sym_sym_lit);
      if (lookahead == '_') ADVANCE(69);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(53);
      if (!sym_sym_lit_character_set_1(lookahead)) ADVANCE(85);
      END_STATE();
    case 70:
      ACCEPT_TOKEN(sym_sym_lit);
      if (lookahead == '_') ADVANCE(70);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(43);
      if (!sym_sym_lit_character_set_1(lookahead)) ADVANCE(85);
      END_STATE();
    case 71:
      ACCEPT_TOKEN(sym_sym_lit);
      if (lookahead == 'a') ADVANCE(74);
      if (!sym_sym_lit_character_set_1(lookahead)) ADVANCE(85);
      END_STATE();
    case 72:
      ACCEPT_TOKEN(sym_sym_lit);
      if (lookahead == 'e') ADVANCE(22);
      if (!sym_sym_lit_character_set_1(lookahead)) ADVANCE(85);
      END_STATE();
    case 73:
      ACCEPT_TOKEN(sym_sym_lit);
      if (lookahead == 'i') ADVANCE(75);
      if (!sym_sym_lit_character_set_1(lookahead)) ADVANCE(85);
      END_STATE();
    case 74:
      ACCEPT_TOKEN(sym_sym_lit);
      if (lookahead == 'l') ADVANCE(77);
      if (!sym_sym_lit_character_set_1(lookahead)) ADVANCE(85);
      END_STATE();
    case 75:
      ACCEPT_TOKEN(sym_sym_lit);
      if (lookahead == 'l') ADVANCE(24);
      if (!sym_sym_lit_character_set_1(lookahead)) ADVANCE(85);
      END_STATE();
    case 76:
      ACCEPT_TOKEN(sym_sym_lit);
      if (lookahead == 'r') ADVANCE(78);
      if (!sym_sym_lit_character_set_1(lookahead)) ADVANCE(85);
      END_STATE();
    case 77:
      ACCEPT_TOKEN(sym_sym_lit);
      if (lookahead == 's') ADVANCE(72);
      if (!sym_sym_lit_character_set_1(lookahead)) ADVANCE(85);
      END_STATE();
    case 78:
      ACCEPT_TOKEN(sym_sym_lit);
      if (lookahead == 'u') ADVANCE(72);
      if (!sym_sym_lit_character_set_1(lookahead)) ADVANCE(85);
      END_STATE();
    case 79:
      ACCEPT_TOKEN(sym_sym_lit);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(81);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(46);
      if (!sym_sym_lit_character_set_1(lookahead)) ADVANCE(85);
      END_STATE();
    case 80:
      ACCEPT_TOKEN(sym_sym_lit);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(82);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(60);
      if (!sym_sym_lit_character_set_1(lookahead)) ADVANCE(85);
      END_STATE();
    case 81:
      ACCEPT_TOKEN(sym_sym_lit);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(46);
      if (!sym_sym_lit_character_set_1(lookahead)) ADVANCE(85);
      END_STATE();
    case 82:
      ACCEPT_TOKEN(sym_sym_lit);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(60);
      if (!sym_sym_lit_character_set_1(lookahead)) ADVANCE(85);
      END_STATE();
    case 83:
      ACCEPT_TOKEN(sym_sym_lit);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(54);
      if (!sym_sym_lit_character_set_1(lookahead)) ADVANCE(85);
      END_STATE();
    case 84:
      ACCEPT_TOKEN(sym_sym_lit);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(58);
      if (lookahead != 0 &&
          lookahead > ' ' &&
          lookahead != '"' &&
          lookahead != '#' &&
          (lookahead < '\'' || ')' < lookahead) &&
          lookahead != ',' &&
          lookahead != ';' &&
          (lookahead < '[' || ']' < lookahead) &&
          (lookahead < '`' || 255 < lookahead)) ADVANCE(85);
      END_STATE();
    case 85:
      ACCEPT_TOKEN(sym_sym_lit);
      if (!sym_sym_lit_character_set_1(lookahead)) ADVANCE(85);
      END_STATE();
    case 86:
      ACCEPT_TOKEN(anon_sym_AT_LPAREN);
      END_STATE();
    case 87:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    case 88:
      ACCEPT_TOKEN(anon_sym_AT_LBRACK);
      END_STATE();
    case 89:
      ACCEPT_TOKEN(anon_sym_RBRACK);
      END_STATE();
    case 90:
      ACCEPT_TOKEN(anon_sym_LBRACE);
      END_STATE();
    case 91:
      ACCEPT_TOKEN(anon_sym_RBRACE);
      END_STATE();
    case 92:
      ACCEPT_TOKEN(anon_sym_AT_LBRACE);
      END_STATE();
    case 93:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      END_STATE();
    case 94:
      ACCEPT_TOKEN(anon_sym_LBRACK);
      END_STATE();
    case 95:
      ACCEPT_TOKEN(anon_sym_TILDE);
      END_STATE();
    case 96:
      ACCEPT_TOKEN(anon_sym_SQUOTE);
      END_STATE();
    case 97:
      ACCEPT_TOKEN(anon_sym_PIPE);
      END_STATE();
    case 98:
      ACCEPT_TOKEN(anon_sym_SEMI);
      END_STATE();
    case 99:
      ACCEPT_TOKEN(anon_sym_COMMA);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0, .external_lex_state = 1},
  [1] = {.lex_state = 0, .external_lex_state = 1},
  [2] = {.lex_state = 0, .external_lex_state = 1},
  [3] = {.lex_state = 0, .external_lex_state = 1},
  [4] = {.lex_state = 0, .external_lex_state = 1},
  [5] = {.lex_state = 0, .external_lex_state = 1},
  [6] = {.lex_state = 0, .external_lex_state = 1},
  [7] = {.lex_state = 0, .external_lex_state = 1},
  [8] = {.lex_state = 0, .external_lex_state = 1},
  [9] = {.lex_state = 0, .external_lex_state = 1},
  [10] = {.lex_state = 0, .external_lex_state = 1},
  [11] = {.lex_state = 0, .external_lex_state = 1},
  [12] = {.lex_state = 0, .external_lex_state = 1},
  [13] = {.lex_state = 0, .external_lex_state = 1},
  [14] = {.lex_state = 0, .external_lex_state = 1},
  [15] = {.lex_state = 0, .external_lex_state = 1},
  [16] = {.lex_state = 0, .external_lex_state = 1},
  [17] = {.lex_state = 0, .external_lex_state = 1},
  [18] = {.lex_state = 0, .external_lex_state = 1},
  [19] = {.lex_state = 0, .external_lex_state = 1},
  [20] = {.lex_state = 0, .external_lex_state = 1},
  [21] = {.lex_state = 0, .external_lex_state = 1},
  [22] = {.lex_state = 0, .external_lex_state = 1},
  [23] = {.lex_state = 0, .external_lex_state = 1},
  [24] = {.lex_state = 0, .external_lex_state = 1},
  [25] = {.lex_state = 0, .external_lex_state = 1},
  [26] = {.lex_state = 0, .external_lex_state = 1},
  [27] = {.lex_state = 0, .external_lex_state = 1},
  [28] = {.lex_state = 0, .external_lex_state = 1},
  [29] = {.lex_state = 0, .external_lex_state = 1},
  [30] = {.lex_state = 0, .external_lex_state = 1},
  [31] = {.lex_state = 0, .external_lex_state = 1},
  [32] = {.lex_state = 0, .external_lex_state = 1},
  [33] = {.lex_state = 0, .external_lex_state = 1},
  [34] = {.lex_state = 0, .external_lex_state = 1},
  [35] = {.lex_state = 0, .external_lex_state = 1},
  [36] = {.lex_state = 0, .external_lex_state = 1},
  [37] = {.lex_state = 0, .external_lex_state = 1},
  [38] = {.lex_state = 0, .external_lex_state = 1},
  [39] = {.lex_state = 0, .external_lex_state = 1},
  [40] = {.lex_state = 0, .external_lex_state = 1},
  [41] = {.lex_state = 0, .external_lex_state = 1},
  [42] = {.lex_state = 0, .external_lex_state = 1},
  [43] = {.lex_state = 0, .external_lex_state = 1},
  [44] = {.lex_state = 0, .external_lex_state = 1},
  [45] = {.lex_state = 0, .external_lex_state = 1},
  [46] = {.lex_state = 0, .external_lex_state = 1},
  [47] = {.lex_state = 0, .external_lex_state = 1},
  [48] = {.lex_state = 0, .external_lex_state = 1},
  [49] = {.lex_state = 0, .external_lex_state = 1},
  [50] = {.lex_state = 0, .external_lex_state = 1},
  [51] = {.lex_state = 0, .external_lex_state = 1},
  [52] = {.lex_state = 0, .external_lex_state = 1},
  [53] = {.lex_state = 0, .external_lex_state = 1},
  [54] = {.lex_state = 0, .external_lex_state = 1},
  [55] = {.lex_state = 0},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [sym__ws] = ACTIONS(1),
    [sym_comment] = ACTIONS(1),
    [anon_sym_BSLASH_POUND] = ACTIONS(1),
    [sym_bool_lit] = ACTIONS(1),
    [aux_sym_kwd_lit_token1] = ACTIONS(1),
    [sym_nil_lit] = ACTIONS(1),
    [sym__dec] = ACTIONS(1),
    [sym__hex] = ACTIONS(1),
    [sym__radix] = ACTIONS(1),
    [sym_str_lit] = ACTIONS(1),
    [sym_buf_lit] = ACTIONS(1),
    [sym_sym_lit] = ACTIONS(1),
    [anon_sym_AT_LPAREN] = ACTIONS(1),
    [anon_sym_RPAREN] = ACTIONS(1),
    [anon_sym_AT_LBRACK] = ACTIONS(1),
    [anon_sym_RBRACK] = ACTIONS(1),
    [anon_sym_LBRACE] = ACTIONS(1),
    [anon_sym_RBRACE] = ACTIONS(1),
    [anon_sym_AT_LBRACE] = ACTIONS(1),
    [anon_sym_LPAREN] = ACTIONS(1),
    [anon_sym_LBRACK] = ACTIONS(1),
    [anon_sym_TILDE] = ACTIONS(1),
    [anon_sym_SQUOTE] = ACTIONS(1),
    [anon_sym_PIPE] = ACTIONS(1),
    [anon_sym_SEMI] = ACTIONS(1),
    [anon_sym_COMMA] = ACTIONS(1),
    [sym_long_buf_lit] = ACTIONS(1),
    [sym_long_str_lit] = ACTIONS(1),
  },
  [1] = {
    [sym_source] = STATE(55),
    [sym__gap] = STATE(15),
    [sym_dis_expr] = STATE(15),
    [sym__lit] = STATE(15),
    [sym_kwd_lit] = STATE(15),
    [sym_num_lit] = STATE(15),
    [sym_par_arr_lit] = STATE(15),
    [sym_sqr_arr_lit] = STATE(15),
    [sym_struct_lit] = STATE(15),
    [sym_tbl_lit] = STATE(15),
    [sym_par_tup_lit] = STATE(15),
    [sym_sqr_tup_lit] = STATE(15),
    [sym_qq_lit] = STATE(15),
    [sym_quote_lit] = STATE(15),
    [sym_short_fn_lit] = STATE(15),
    [sym_splice_lit] = STATE(15),
    [sym_unquote_lit] = STATE(15),
    [aux_sym_source_repeat1] = STATE(15),
    [ts_builtin_sym_end] = ACTIONS(3),
    [sym__ws] = ACTIONS(5),
    [sym_comment] = ACTIONS(5),
    [anon_sym_BSLASH_POUND] = ACTIONS(7),
    [sym_bool_lit] = ACTIONS(9),
    [aux_sym_kwd_lit_token1] = ACTIONS(11),
    [sym_nil_lit] = ACTIONS(9),
    [sym__dec] = ACTIONS(13),
    [sym__hex] = ACTIONS(13),
    [sym__radix] = ACTIONS(13),
    [sym_str_lit] = ACTIONS(5),
    [sym_buf_lit] = ACTIONS(5),
    [sym_sym_lit] = ACTIONS(9),
    [anon_sym_AT_LPAREN] = ACTIONS(15),
    [anon_sym_AT_LBRACK] = ACTIONS(17),
    [anon_sym_LBRACE] = ACTIONS(19),
    [anon_sym_AT_LBRACE] = ACTIONS(21),
    [anon_sym_LPAREN] = ACTIONS(23),
    [anon_sym_LBRACK] = ACTIONS(25),
    [anon_sym_TILDE] = ACTIONS(27),
    [anon_sym_SQUOTE] = ACTIONS(29),
    [anon_sym_PIPE] = ACTIONS(31),
    [anon_sym_SEMI] = ACTIONS(33),
    [anon_sym_COMMA] = ACTIONS(35),
    [sym_long_buf_lit] = ACTIONS(5),
    [sym_long_str_lit] = ACTIONS(5),
  },
  [2] = {
    [sym__gap] = STATE(2),
    [sym_dis_expr] = STATE(2),
    [sym__lit] = STATE(2),
    [sym_kwd_lit] = STATE(2),
    [sym_num_lit] = STATE(2),
    [sym_par_arr_lit] = STATE(2),
    [sym_sqr_arr_lit] = STATE(2),
    [sym_struct_lit] = STATE(2),
    [sym_tbl_lit] = STATE(2),
    [sym_par_tup_lit] = STATE(2),
    [sym_sqr_tup_lit] = STATE(2),
    [sym_qq_lit] = STATE(2),
    [sym_quote_lit] = STATE(2),
    [sym_short_fn_lit] = STATE(2),
    [sym_splice_lit] = STATE(2),
    [sym_unquote_lit] = STATE(2),
    [aux_sym_source_repeat1] = STATE(2),
    [ts_builtin_sym_end] = ACTIONS(37),
    [sym__ws] = ACTIONS(39),
    [sym_comment] = ACTIONS(39),
    [anon_sym_BSLASH_POUND] = ACTIONS(42),
    [sym_bool_lit] = ACTIONS(45),
    [aux_sym_kwd_lit_token1] = ACTIONS(48),
    [sym_nil_lit] = ACTIONS(45),
    [sym__dec] = ACTIONS(51),
    [sym__hex] = ACTIONS(51),
    [sym__radix] = ACTIONS(51),
    [sym_str_lit] = ACTIONS(39),
    [sym_buf_lit] = ACTIONS(39),
    [sym_sym_lit] = ACTIONS(45),
    [anon_sym_AT_LPAREN] = ACTIONS(54),
    [anon_sym_RPAREN] = ACTIONS(37),
    [anon_sym_AT_LBRACK] = ACTIONS(57),
    [anon_sym_RBRACK] = ACTIONS(37),
    [anon_sym_LBRACE] = ACTIONS(60),
    [anon_sym_RBRACE] = ACTIONS(37),
    [anon_sym_AT_LBRACE] = ACTIONS(63),
    [anon_sym_LPAREN] = ACTIONS(66),
    [anon_sym_LBRACK] = ACTIONS(69),
    [anon_sym_TILDE] = ACTIONS(72),
    [anon_sym_SQUOTE] = ACTIONS(75),
    [anon_sym_PIPE] = ACTIONS(78),
    [anon_sym_SEMI] = ACTIONS(81),
    [anon_sym_COMMA] = ACTIONS(84),
    [sym_long_buf_lit] = ACTIONS(39),
    [sym_long_str_lit] = ACTIONS(39),
  },
  [3] = {
    [sym__gap] = STATE(2),
    [sym_dis_expr] = STATE(2),
    [sym__lit] = STATE(2),
    [sym_kwd_lit] = STATE(2),
    [sym_num_lit] = STATE(2),
    [sym_par_arr_lit] = STATE(2),
    [sym_sqr_arr_lit] = STATE(2),
    [sym_struct_lit] = STATE(2),
    [sym_tbl_lit] = STATE(2),
    [sym_par_tup_lit] = STATE(2),
    [sym_sqr_tup_lit] = STATE(2),
    [sym_qq_lit] = STATE(2),
    [sym_quote_lit] = STATE(2),
    [sym_short_fn_lit] = STATE(2),
    [sym_splice_lit] = STATE(2),
    [sym_unquote_lit] = STATE(2),
    [aux_sym_source_repeat1] = STATE(2),
    [sym__ws] = ACTIONS(87),
    [sym_comment] = ACTIONS(87),
    [anon_sym_BSLASH_POUND] = ACTIONS(7),
    [sym_bool_lit] = ACTIONS(89),
    [aux_sym_kwd_lit_token1] = ACTIONS(11),
    [sym_nil_lit] = ACTIONS(89),
    [sym__dec] = ACTIONS(13),
    [sym__hex] = ACTIONS(13),
    [sym__radix] = ACTIONS(13),
    [sym_str_lit] = ACTIONS(87),
    [sym_buf_lit] = ACTIONS(87),
    [sym_sym_lit] = ACTIONS(89),
    [anon_sym_AT_LPAREN] = ACTIONS(15),
    [anon_sym_RPAREN] = ACTIONS(91),
    [anon_sym_AT_LBRACK] = ACTIONS(17),
    [anon_sym_LBRACE] = ACTIONS(19),
    [anon_sym_AT_LBRACE] = ACTIONS(21),
    [anon_sym_LPAREN] = ACTIONS(23),
    [anon_sym_LBRACK] = ACTIONS(25),
    [anon_sym_TILDE] = ACTIONS(27),
    [anon_sym_SQUOTE] = ACTIONS(29),
    [anon_sym_PIPE] = ACTIONS(31),
    [anon_sym_SEMI] = ACTIONS(33),
    [anon_sym_COMMA] = ACTIONS(35),
    [sym_long_buf_lit] = ACTIONS(87),
    [sym_long_str_lit] = ACTIONS(87),
  },
  [4] = {
    [sym__gap] = STATE(2),
    [sym_dis_expr] = STATE(2),
    [sym__lit] = STATE(2),
    [sym_kwd_lit] = STATE(2),
    [sym_num_lit] = STATE(2),
    [sym_par_arr_lit] = STATE(2),
    [sym_sqr_arr_lit] = STATE(2),
    [sym_struct_lit] = STATE(2),
    [sym_tbl_lit] = STATE(2),
    [sym_par_tup_lit] = STATE(2),
    [sym_sqr_tup_lit] = STATE(2),
    [sym_qq_lit] = STATE(2),
    [sym_quote_lit] = STATE(2),
    [sym_short_fn_lit] = STATE(2),
    [sym_splice_lit] = STATE(2),
    [sym_unquote_lit] = STATE(2),
    [aux_sym_source_repeat1] = STATE(2),
    [sym__ws] = ACTIONS(87),
    [sym_comment] = ACTIONS(87),
    [anon_sym_BSLASH_POUND] = ACTIONS(7),
    [sym_bool_lit] = ACTIONS(89),
    [aux_sym_kwd_lit_token1] = ACTIONS(11),
    [sym_nil_lit] = ACTIONS(89),
    [sym__dec] = ACTIONS(13),
    [sym__hex] = ACTIONS(13),
    [sym__radix] = ACTIONS(13),
    [sym_str_lit] = ACTIONS(87),
    [sym_buf_lit] = ACTIONS(87),
    [sym_sym_lit] = ACTIONS(89),
    [anon_sym_AT_LPAREN] = ACTIONS(15),
    [anon_sym_AT_LBRACK] = ACTIONS(17),
    [anon_sym_RBRACK] = ACTIONS(93),
    [anon_sym_LBRACE] = ACTIONS(19),
    [anon_sym_AT_LBRACE] = ACTIONS(21),
    [anon_sym_LPAREN] = ACTIONS(23),
    [anon_sym_LBRACK] = ACTIONS(25),
    [anon_sym_TILDE] = ACTIONS(27),
    [anon_sym_SQUOTE] = ACTIONS(29),
    [anon_sym_PIPE] = ACTIONS(31),
    [anon_sym_SEMI] = ACTIONS(33),
    [anon_sym_COMMA] = ACTIONS(35),
    [sym_long_buf_lit] = ACTIONS(87),
    [sym_long_str_lit] = ACTIONS(87),
  },
  [5] = {
    [sym__gap] = STATE(2),
    [sym_dis_expr] = STATE(2),
    [sym__lit] = STATE(2),
    [sym_kwd_lit] = STATE(2),
    [sym_num_lit] = STATE(2),
    [sym_par_arr_lit] = STATE(2),
    [sym_sqr_arr_lit] = STATE(2),
    [sym_struct_lit] = STATE(2),
    [sym_tbl_lit] = STATE(2),
    [sym_par_tup_lit] = STATE(2),
    [sym_sqr_tup_lit] = STATE(2),
    [sym_qq_lit] = STATE(2),
    [sym_quote_lit] = STATE(2),
    [sym_short_fn_lit] = STATE(2),
    [sym_splice_lit] = STATE(2),
    [sym_unquote_lit] = STATE(2),
    [aux_sym_source_repeat1] = STATE(2),
    [sym__ws] = ACTIONS(87),
    [sym_comment] = ACTIONS(87),
    [anon_sym_BSLASH_POUND] = ACTIONS(7),
    [sym_bool_lit] = ACTIONS(89),
    [aux_sym_kwd_lit_token1] = ACTIONS(11),
    [sym_nil_lit] = ACTIONS(89),
    [sym__dec] = ACTIONS(13),
    [sym__hex] = ACTIONS(13),
    [sym__radix] = ACTIONS(13),
    [sym_str_lit] = ACTIONS(87),
    [sym_buf_lit] = ACTIONS(87),
    [sym_sym_lit] = ACTIONS(89),
    [anon_sym_AT_LPAREN] = ACTIONS(15),
    [anon_sym_RPAREN] = ACTIONS(95),
    [anon_sym_AT_LBRACK] = ACTIONS(17),
    [anon_sym_LBRACE] = ACTIONS(19),
    [anon_sym_AT_LBRACE] = ACTIONS(21),
    [anon_sym_LPAREN] = ACTIONS(23),
    [anon_sym_LBRACK] = ACTIONS(25),
    [anon_sym_TILDE] = ACTIONS(27),
    [anon_sym_SQUOTE] = ACTIONS(29),
    [anon_sym_PIPE] = ACTIONS(31),
    [anon_sym_SEMI] = ACTIONS(33),
    [anon_sym_COMMA] = ACTIONS(35),
    [sym_long_buf_lit] = ACTIONS(87),
    [sym_long_str_lit] = ACTIONS(87),
  },
  [6] = {
    [sym__gap] = STATE(3),
    [sym_dis_expr] = STATE(3),
    [sym__lit] = STATE(3),
    [sym_kwd_lit] = STATE(3),
    [sym_num_lit] = STATE(3),
    [sym_par_arr_lit] = STATE(3),
    [sym_sqr_arr_lit] = STATE(3),
    [sym_struct_lit] = STATE(3),
    [sym_tbl_lit] = STATE(3),
    [sym_par_tup_lit] = STATE(3),
    [sym_sqr_tup_lit] = STATE(3),
    [sym_qq_lit] = STATE(3),
    [sym_quote_lit] = STATE(3),
    [sym_short_fn_lit] = STATE(3),
    [sym_splice_lit] = STATE(3),
    [sym_unquote_lit] = STATE(3),
    [aux_sym_source_repeat1] = STATE(3),
    [sym__ws] = ACTIONS(97),
    [sym_comment] = ACTIONS(97),
    [anon_sym_BSLASH_POUND] = ACTIONS(7),
    [sym_bool_lit] = ACTIONS(99),
    [aux_sym_kwd_lit_token1] = ACTIONS(11),
    [sym_nil_lit] = ACTIONS(99),
    [sym__dec] = ACTIONS(13),
    [sym__hex] = ACTIONS(13),
    [sym__radix] = ACTIONS(13),
    [sym_str_lit] = ACTIONS(97),
    [sym_buf_lit] = ACTIONS(97),
    [sym_sym_lit] = ACTIONS(99),
    [anon_sym_AT_LPAREN] = ACTIONS(15),
    [anon_sym_RPAREN] = ACTIONS(101),
    [anon_sym_AT_LBRACK] = ACTIONS(17),
    [anon_sym_LBRACE] = ACTIONS(19),
    [anon_sym_AT_LBRACE] = ACTIONS(21),
    [anon_sym_LPAREN] = ACTIONS(23),
    [anon_sym_LBRACK] = ACTIONS(25),
    [anon_sym_TILDE] = ACTIONS(27),
    [anon_sym_SQUOTE] = ACTIONS(29),
    [anon_sym_PIPE] = ACTIONS(31),
    [anon_sym_SEMI] = ACTIONS(33),
    [anon_sym_COMMA] = ACTIONS(35),
    [sym_long_buf_lit] = ACTIONS(97),
    [sym_long_str_lit] = ACTIONS(97),
  },
  [7] = {
    [sym__gap] = STATE(14),
    [sym_dis_expr] = STATE(14),
    [sym__lit] = STATE(14),
    [sym_kwd_lit] = STATE(14),
    [sym_num_lit] = STATE(14),
    [sym_par_arr_lit] = STATE(14),
    [sym_sqr_arr_lit] = STATE(14),
    [sym_struct_lit] = STATE(14),
    [sym_tbl_lit] = STATE(14),
    [sym_par_tup_lit] = STATE(14),
    [sym_sqr_tup_lit] = STATE(14),
    [sym_qq_lit] = STATE(14),
    [sym_quote_lit] = STATE(14),
    [sym_short_fn_lit] = STATE(14),
    [sym_splice_lit] = STATE(14),
    [sym_unquote_lit] = STATE(14),
    [aux_sym_source_repeat1] = STATE(14),
    [sym__ws] = ACTIONS(103),
    [sym_comment] = ACTIONS(103),
    [anon_sym_BSLASH_POUND] = ACTIONS(7),
    [sym_bool_lit] = ACTIONS(105),
    [aux_sym_kwd_lit_token1] = ACTIONS(11),
    [sym_nil_lit] = ACTIONS(105),
    [sym__dec] = ACTIONS(13),
    [sym__hex] = ACTIONS(13),
    [sym__radix] = ACTIONS(13),
    [sym_str_lit] = ACTIONS(103),
    [sym_buf_lit] = ACTIONS(103),
    [sym_sym_lit] = ACTIONS(105),
    [anon_sym_AT_LPAREN] = ACTIONS(15),
    [anon_sym_AT_LBRACK] = ACTIONS(17),
    [anon_sym_RBRACK] = ACTIONS(107),
    [anon_sym_LBRACE] = ACTIONS(19),
    [anon_sym_AT_LBRACE] = ACTIONS(21),
    [anon_sym_LPAREN] = ACTIONS(23),
    [anon_sym_LBRACK] = ACTIONS(25),
    [anon_sym_TILDE] = ACTIONS(27),
    [anon_sym_SQUOTE] = ACTIONS(29),
    [anon_sym_PIPE] = ACTIONS(31),
    [anon_sym_SEMI] = ACTIONS(33),
    [anon_sym_COMMA] = ACTIONS(35),
    [sym_long_buf_lit] = ACTIONS(103),
    [sym_long_str_lit] = ACTIONS(103),
  },
  [8] = {
    [sym__gap] = STATE(13),
    [sym_dis_expr] = STATE(13),
    [sym__lit] = STATE(13),
    [sym_kwd_lit] = STATE(13),
    [sym_num_lit] = STATE(13),
    [sym_par_arr_lit] = STATE(13),
    [sym_sqr_arr_lit] = STATE(13),
    [sym_struct_lit] = STATE(13),
    [sym_tbl_lit] = STATE(13),
    [sym_par_tup_lit] = STATE(13),
    [sym_sqr_tup_lit] = STATE(13),
    [sym_qq_lit] = STATE(13),
    [sym_quote_lit] = STATE(13),
    [sym_short_fn_lit] = STATE(13),
    [sym_splice_lit] = STATE(13),
    [sym_unquote_lit] = STATE(13),
    [aux_sym_source_repeat1] = STATE(13),
    [sym__ws] = ACTIONS(109),
    [sym_comment] = ACTIONS(109),
    [anon_sym_BSLASH_POUND] = ACTIONS(7),
    [sym_bool_lit] = ACTIONS(111),
    [aux_sym_kwd_lit_token1] = ACTIONS(11),
    [sym_nil_lit] = ACTIONS(111),
    [sym__dec] = ACTIONS(13),
    [sym__hex] = ACTIONS(13),
    [sym__radix] = ACTIONS(13),
    [sym_str_lit] = ACTIONS(109),
    [sym_buf_lit] = ACTIONS(109),
    [sym_sym_lit] = ACTIONS(111),
    [anon_sym_AT_LPAREN] = ACTIONS(15),
    [anon_sym_AT_LBRACK] = ACTIONS(17),
    [anon_sym_LBRACE] = ACTIONS(19),
    [anon_sym_RBRACE] = ACTIONS(113),
    [anon_sym_AT_LBRACE] = ACTIONS(21),
    [anon_sym_LPAREN] = ACTIONS(23),
    [anon_sym_LBRACK] = ACTIONS(25),
    [anon_sym_TILDE] = ACTIONS(27),
    [anon_sym_SQUOTE] = ACTIONS(29),
    [anon_sym_PIPE] = ACTIONS(31),
    [anon_sym_SEMI] = ACTIONS(33),
    [anon_sym_COMMA] = ACTIONS(35),
    [sym_long_buf_lit] = ACTIONS(109),
    [sym_long_str_lit] = ACTIONS(109),
  },
  [9] = {
    [sym__gap] = STATE(12),
    [sym_dis_expr] = STATE(12),
    [sym__lit] = STATE(12),
    [sym_kwd_lit] = STATE(12),
    [sym_num_lit] = STATE(12),
    [sym_par_arr_lit] = STATE(12),
    [sym_sqr_arr_lit] = STATE(12),
    [sym_struct_lit] = STATE(12),
    [sym_tbl_lit] = STATE(12),
    [sym_par_tup_lit] = STATE(12),
    [sym_sqr_tup_lit] = STATE(12),
    [sym_qq_lit] = STATE(12),
    [sym_quote_lit] = STATE(12),
    [sym_short_fn_lit] = STATE(12),
    [sym_splice_lit] = STATE(12),
    [sym_unquote_lit] = STATE(12),
    [aux_sym_source_repeat1] = STATE(12),
    [sym__ws] = ACTIONS(115),
    [sym_comment] = ACTIONS(115),
    [anon_sym_BSLASH_POUND] = ACTIONS(7),
    [sym_bool_lit] = ACTIONS(117),
    [aux_sym_kwd_lit_token1] = ACTIONS(11),
    [sym_nil_lit] = ACTIONS(117),
    [sym__dec] = ACTIONS(13),
    [sym__hex] = ACTIONS(13),
    [sym__radix] = ACTIONS(13),
    [sym_str_lit] = ACTIONS(115),
    [sym_buf_lit] = ACTIONS(115),
    [sym_sym_lit] = ACTIONS(117),
    [anon_sym_AT_LPAREN] = ACTIONS(15),
    [anon_sym_AT_LBRACK] = ACTIONS(17),
    [anon_sym_LBRACE] = ACTIONS(19),
    [anon_sym_RBRACE] = ACTIONS(119),
    [anon_sym_AT_LBRACE] = ACTIONS(21),
    [anon_sym_LPAREN] = ACTIONS(23),
    [anon_sym_LBRACK] = ACTIONS(25),
    [anon_sym_TILDE] = ACTIONS(27),
    [anon_sym_SQUOTE] = ACTIONS(29),
    [anon_sym_PIPE] = ACTIONS(31),
    [anon_sym_SEMI] = ACTIONS(33),
    [anon_sym_COMMA] = ACTIONS(35),
    [sym_long_buf_lit] = ACTIONS(115),
    [sym_long_str_lit] = ACTIONS(115),
  },
  [10] = {
    [sym__gap] = STATE(5),
    [sym_dis_expr] = STATE(5),
    [sym__lit] = STATE(5),
    [sym_kwd_lit] = STATE(5),
    [sym_num_lit] = STATE(5),
    [sym_par_arr_lit] = STATE(5),
    [sym_sqr_arr_lit] = STATE(5),
    [sym_struct_lit] = STATE(5),
    [sym_tbl_lit] = STATE(5),
    [sym_par_tup_lit] = STATE(5),
    [sym_sqr_tup_lit] = STATE(5),
    [sym_qq_lit] = STATE(5),
    [sym_quote_lit] = STATE(5),
    [sym_short_fn_lit] = STATE(5),
    [sym_splice_lit] = STATE(5),
    [sym_unquote_lit] = STATE(5),
    [aux_sym_source_repeat1] = STATE(5),
    [sym__ws] = ACTIONS(121),
    [sym_comment] = ACTIONS(121),
    [anon_sym_BSLASH_POUND] = ACTIONS(7),
    [sym_bool_lit] = ACTIONS(123),
    [aux_sym_kwd_lit_token1] = ACTIONS(11),
    [sym_nil_lit] = ACTIONS(123),
    [sym__dec] = ACTIONS(13),
    [sym__hex] = ACTIONS(13),
    [sym__radix] = ACTIONS(13),
    [sym_str_lit] = ACTIONS(121),
    [sym_buf_lit] = ACTIONS(121),
    [sym_sym_lit] = ACTIONS(123),
    [anon_sym_AT_LPAREN] = ACTIONS(15),
    [anon_sym_RPAREN] = ACTIONS(125),
    [anon_sym_AT_LBRACK] = ACTIONS(17),
    [anon_sym_LBRACE] = ACTIONS(19),
    [anon_sym_AT_LBRACE] = ACTIONS(21),
    [anon_sym_LPAREN] = ACTIONS(23),
    [anon_sym_LBRACK] = ACTIONS(25),
    [anon_sym_TILDE] = ACTIONS(27),
    [anon_sym_SQUOTE] = ACTIONS(29),
    [anon_sym_PIPE] = ACTIONS(31),
    [anon_sym_SEMI] = ACTIONS(33),
    [anon_sym_COMMA] = ACTIONS(35),
    [sym_long_buf_lit] = ACTIONS(121),
    [sym_long_str_lit] = ACTIONS(121),
  },
  [11] = {
    [sym__gap] = STATE(4),
    [sym_dis_expr] = STATE(4),
    [sym__lit] = STATE(4),
    [sym_kwd_lit] = STATE(4),
    [sym_num_lit] = STATE(4),
    [sym_par_arr_lit] = STATE(4),
    [sym_sqr_arr_lit] = STATE(4),
    [sym_struct_lit] = STATE(4),
    [sym_tbl_lit] = STATE(4),
    [sym_par_tup_lit] = STATE(4),
    [sym_sqr_tup_lit] = STATE(4),
    [sym_qq_lit] = STATE(4),
    [sym_quote_lit] = STATE(4),
    [sym_short_fn_lit] = STATE(4),
    [sym_splice_lit] = STATE(4),
    [sym_unquote_lit] = STATE(4),
    [aux_sym_source_repeat1] = STATE(4),
    [sym__ws] = ACTIONS(127),
    [sym_comment] = ACTIONS(127),
    [anon_sym_BSLASH_POUND] = ACTIONS(7),
    [sym_bool_lit] = ACTIONS(129),
    [aux_sym_kwd_lit_token1] = ACTIONS(11),
    [sym_nil_lit] = ACTIONS(129),
    [sym__dec] = ACTIONS(13),
    [sym__hex] = ACTIONS(13),
    [sym__radix] = ACTIONS(13),
    [sym_str_lit] = ACTIONS(127),
    [sym_buf_lit] = ACTIONS(127),
    [sym_sym_lit] = ACTIONS(129),
    [anon_sym_AT_LPAREN] = ACTIONS(15),
    [anon_sym_AT_LBRACK] = ACTIONS(17),
    [anon_sym_RBRACK] = ACTIONS(131),
    [anon_sym_LBRACE] = ACTIONS(19),
    [anon_sym_AT_LBRACE] = ACTIONS(21),
    [anon_sym_LPAREN] = ACTIONS(23),
    [anon_sym_LBRACK] = ACTIONS(25),
    [anon_sym_TILDE] = ACTIONS(27),
    [anon_sym_SQUOTE] = ACTIONS(29),
    [anon_sym_PIPE] = ACTIONS(31),
    [anon_sym_SEMI] = ACTIONS(33),
    [anon_sym_COMMA] = ACTIONS(35),
    [sym_long_buf_lit] = ACTIONS(127),
    [sym_long_str_lit] = ACTIONS(127),
  },
  [12] = {
    [sym__gap] = STATE(2),
    [sym_dis_expr] = STATE(2),
    [sym__lit] = STATE(2),
    [sym_kwd_lit] = STATE(2),
    [sym_num_lit] = STATE(2),
    [sym_par_arr_lit] = STATE(2),
    [sym_sqr_arr_lit] = STATE(2),
    [sym_struct_lit] = STATE(2),
    [sym_tbl_lit] = STATE(2),
    [sym_par_tup_lit] = STATE(2),
    [sym_sqr_tup_lit] = STATE(2),
    [sym_qq_lit] = STATE(2),
    [sym_quote_lit] = STATE(2),
    [sym_short_fn_lit] = STATE(2),
    [sym_splice_lit] = STATE(2),
    [sym_unquote_lit] = STATE(2),
    [aux_sym_source_repeat1] = STATE(2),
    [sym__ws] = ACTIONS(87),
    [sym_comment] = ACTIONS(87),
    [anon_sym_BSLASH_POUND] = ACTIONS(7),
    [sym_bool_lit] = ACTIONS(89),
    [aux_sym_kwd_lit_token1] = ACTIONS(11),
    [sym_nil_lit] = ACTIONS(89),
    [sym__dec] = ACTIONS(13),
    [sym__hex] = ACTIONS(13),
    [sym__radix] = ACTIONS(13),
    [sym_str_lit] = ACTIONS(87),
    [sym_buf_lit] = ACTIONS(87),
    [sym_sym_lit] = ACTIONS(89),
    [anon_sym_AT_LPAREN] = ACTIONS(15),
    [anon_sym_AT_LBRACK] = ACTIONS(17),
    [anon_sym_LBRACE] = ACTIONS(19),
    [anon_sym_RBRACE] = ACTIONS(133),
    [anon_sym_AT_LBRACE] = ACTIONS(21),
    [anon_sym_LPAREN] = ACTIONS(23),
    [anon_sym_LBRACK] = ACTIONS(25),
    [anon_sym_TILDE] = ACTIONS(27),
    [anon_sym_SQUOTE] = ACTIONS(29),
    [anon_sym_PIPE] = ACTIONS(31),
    [anon_sym_SEMI] = ACTIONS(33),
    [anon_sym_COMMA] = ACTIONS(35),
    [sym_long_buf_lit] = ACTIONS(87),
    [sym_long_str_lit] = ACTIONS(87),
  },
  [13] = {
    [sym__gap] = STATE(2),
    [sym_dis_expr] = STATE(2),
    [sym__lit] = STATE(2),
    [sym_kwd_lit] = STATE(2),
    [sym_num_lit] = STATE(2),
    [sym_par_arr_lit] = STATE(2),
    [sym_sqr_arr_lit] = STATE(2),
    [sym_struct_lit] = STATE(2),
    [sym_tbl_lit] = STATE(2),
    [sym_par_tup_lit] = STATE(2),
    [sym_sqr_tup_lit] = STATE(2),
    [sym_qq_lit] = STATE(2),
    [sym_quote_lit] = STATE(2),
    [sym_short_fn_lit] = STATE(2),
    [sym_splice_lit] = STATE(2),
    [sym_unquote_lit] = STATE(2),
    [aux_sym_source_repeat1] = STATE(2),
    [sym__ws] = ACTIONS(87),
    [sym_comment] = ACTIONS(87),
    [anon_sym_BSLASH_POUND] = ACTIONS(7),
    [sym_bool_lit] = ACTIONS(89),
    [aux_sym_kwd_lit_token1] = ACTIONS(11),
    [sym_nil_lit] = ACTIONS(89),
    [sym__dec] = ACTIONS(13),
    [sym__hex] = ACTIONS(13),
    [sym__radix] = ACTIONS(13),
    [sym_str_lit] = ACTIONS(87),
    [sym_buf_lit] = ACTIONS(87),
    [sym_sym_lit] = ACTIONS(89),
    [anon_sym_AT_LPAREN] = ACTIONS(15),
    [anon_sym_AT_LBRACK] = ACTIONS(17),
    [anon_sym_LBRACE] = ACTIONS(19),
    [anon_sym_RBRACE] = ACTIONS(135),
    [anon_sym_AT_LBRACE] = ACTIONS(21),
    [anon_sym_LPAREN] = ACTIONS(23),
    [anon_sym_LBRACK] = ACTIONS(25),
    [anon_sym_TILDE] = ACTIONS(27),
    [anon_sym_SQUOTE] = ACTIONS(29),
    [anon_sym_PIPE] = ACTIONS(31),
    [anon_sym_SEMI] = ACTIONS(33),
    [anon_sym_COMMA] = ACTIONS(35),
    [sym_long_buf_lit] = ACTIONS(87),
    [sym_long_str_lit] = ACTIONS(87),
  },
  [14] = {
    [sym__gap] = STATE(2),
    [sym_dis_expr] = STATE(2),
    [sym__lit] = STATE(2),
    [sym_kwd_lit] = STATE(2),
    [sym_num_lit] = STATE(2),
    [sym_par_arr_lit] = STATE(2),
    [sym_sqr_arr_lit] = STATE(2),
    [sym_struct_lit] = STATE(2),
    [sym_tbl_lit] = STATE(2),
    [sym_par_tup_lit] = STATE(2),
    [sym_sqr_tup_lit] = STATE(2),
    [sym_qq_lit] = STATE(2),
    [sym_quote_lit] = STATE(2),
    [sym_short_fn_lit] = STATE(2),
    [sym_splice_lit] = STATE(2),
    [sym_unquote_lit] = STATE(2),
    [aux_sym_source_repeat1] = STATE(2),
    [sym__ws] = ACTIONS(87),
    [sym_comment] = ACTIONS(87),
    [anon_sym_BSLASH_POUND] = ACTIONS(7),
    [sym_bool_lit] = ACTIONS(89),
    [aux_sym_kwd_lit_token1] = ACTIONS(11),
    [sym_nil_lit] = ACTIONS(89),
    [sym__dec] = ACTIONS(13),
    [sym__hex] = ACTIONS(13),
    [sym__radix] = ACTIONS(13),
    [sym_str_lit] = ACTIONS(87),
    [sym_buf_lit] = ACTIONS(87),
    [sym_sym_lit] = ACTIONS(89),
    [anon_sym_AT_LPAREN] = ACTIONS(15),
    [anon_sym_AT_LBRACK] = ACTIONS(17),
    [anon_sym_RBRACK] = ACTIONS(137),
    [anon_sym_LBRACE] = ACTIONS(19),
    [anon_sym_AT_LBRACE] = ACTIONS(21),
    [anon_sym_LPAREN] = ACTIONS(23),
    [anon_sym_LBRACK] = ACTIONS(25),
    [anon_sym_TILDE] = ACTIONS(27),
    [anon_sym_SQUOTE] = ACTIONS(29),
    [anon_sym_PIPE] = ACTIONS(31),
    [anon_sym_SEMI] = ACTIONS(33),
    [anon_sym_COMMA] = ACTIONS(35),
    [sym_long_buf_lit] = ACTIONS(87),
    [sym_long_str_lit] = ACTIONS(87),
  },
  [15] = {
    [sym__gap] = STATE(2),
    [sym_dis_expr] = STATE(2),
    [sym__lit] = STATE(2),
    [sym_kwd_lit] = STATE(2),
    [sym_num_lit] = STATE(2),
    [sym_par_arr_lit] = STATE(2),
    [sym_sqr_arr_lit] = STATE(2),
    [sym_struct_lit] = STATE(2),
    [sym_tbl_lit] = STATE(2),
    [sym_par_tup_lit] = STATE(2),
    [sym_sqr_tup_lit] = STATE(2),
    [sym_qq_lit] = STATE(2),
    [sym_quote_lit] = STATE(2),
    [sym_short_fn_lit] = STATE(2),
    [sym_splice_lit] = STATE(2),
    [sym_unquote_lit] = STATE(2),
    [aux_sym_source_repeat1] = STATE(2),
    [ts_builtin_sym_end] = ACTIONS(139),
    [sym__ws] = ACTIONS(87),
    [sym_comment] = ACTIONS(87),
    [anon_sym_BSLASH_POUND] = ACTIONS(7),
    [sym_bool_lit] = ACTIONS(89),
    [aux_sym_kwd_lit_token1] = ACTIONS(11),
    [sym_nil_lit] = ACTIONS(89),
    [sym__dec] = ACTIONS(13),
    [sym__hex] = ACTIONS(13),
    [sym__radix] = ACTIONS(13),
    [sym_str_lit] = ACTIONS(87),
    [sym_buf_lit] = ACTIONS(87),
    [sym_sym_lit] = ACTIONS(89),
    [anon_sym_AT_LPAREN] = ACTIONS(15),
    [anon_sym_AT_LBRACK] = ACTIONS(17),
    [anon_sym_LBRACE] = ACTIONS(19),
    [anon_sym_AT_LBRACE] = ACTIONS(21),
    [anon_sym_LPAREN] = ACTIONS(23),
    [anon_sym_LBRACK] = ACTIONS(25),
    [anon_sym_TILDE] = ACTIONS(27),
    [anon_sym_SQUOTE] = ACTIONS(29),
    [anon_sym_PIPE] = ACTIONS(31),
    [anon_sym_SEMI] = ACTIONS(33),
    [anon_sym_COMMA] = ACTIONS(35),
    [sym_long_buf_lit] = ACTIONS(87),
    [sym_long_str_lit] = ACTIONS(87),
  },
  [16] = {
    [sym__gap] = STATE(19),
    [sym_dis_expr] = STATE(19),
    [sym__lit] = STATE(38),
    [sym_kwd_lit] = STATE(38),
    [sym_num_lit] = STATE(38),
    [sym_par_arr_lit] = STATE(38),
    [sym_sqr_arr_lit] = STATE(38),
    [sym_struct_lit] = STATE(38),
    [sym_tbl_lit] = STATE(38),
    [sym_par_tup_lit] = STATE(38),
    [sym_sqr_tup_lit] = STATE(38),
    [sym_qq_lit] = STATE(38),
    [sym_quote_lit] = STATE(38),
    [sym_short_fn_lit] = STATE(38),
    [sym_splice_lit] = STATE(38),
    [sym_unquote_lit] = STATE(38),
    [aux_sym_dis_expr_repeat1] = STATE(19),
    [sym__ws] = ACTIONS(141),
    [sym_comment] = ACTIONS(141),
    [anon_sym_BSLASH_POUND] = ACTIONS(7),
    [sym_bool_lit] = ACTIONS(143),
    [aux_sym_kwd_lit_token1] = ACTIONS(11),
    [sym_nil_lit] = ACTIONS(143),
    [sym__dec] = ACTIONS(13),
    [sym__hex] = ACTIONS(13),
    [sym__radix] = ACTIONS(13),
    [sym_str_lit] = ACTIONS(145),
    [sym_buf_lit] = ACTIONS(145),
    [sym_sym_lit] = ACTIONS(143),
    [anon_sym_AT_LPAREN] = ACTIONS(15),
    [anon_sym_AT_LBRACK] = ACTIONS(17),
    [anon_sym_LBRACE] = ACTIONS(19),
    [anon_sym_AT_LBRACE] = ACTIONS(21),
    [anon_sym_LPAREN] = ACTIONS(23),
    [anon_sym_LBRACK] = ACTIONS(25),
    [anon_sym_TILDE] = ACTIONS(27),
    [anon_sym_SQUOTE] = ACTIONS(29),
    [anon_sym_PIPE] = ACTIONS(31),
    [anon_sym_SEMI] = ACTIONS(33),
    [anon_sym_COMMA] = ACTIONS(35),
    [sym_long_buf_lit] = ACTIONS(145),
    [sym_long_str_lit] = ACTIONS(145),
  },
  [17] = {
    [sym__gap] = STATE(24),
    [sym_dis_expr] = STATE(24),
    [sym__lit] = STATE(32),
    [sym_kwd_lit] = STATE(32),
    [sym_num_lit] = STATE(32),
    [sym_par_arr_lit] = STATE(32),
    [sym_sqr_arr_lit] = STATE(32),
    [sym_struct_lit] = STATE(32),
    [sym_tbl_lit] = STATE(32),
    [sym_par_tup_lit] = STATE(32),
    [sym_sqr_tup_lit] = STATE(32),
    [sym_qq_lit] = STATE(32),
    [sym_quote_lit] = STATE(32),
    [sym_short_fn_lit] = STATE(32),
    [sym_splice_lit] = STATE(32),
    [sym_unquote_lit] = STATE(32),
    [aux_sym_dis_expr_repeat1] = STATE(24),
    [sym__ws] = ACTIONS(147),
    [sym_comment] = ACTIONS(147),
    [anon_sym_BSLASH_POUND] = ACTIONS(7),
    [sym_bool_lit] = ACTIONS(149),
    [aux_sym_kwd_lit_token1] = ACTIONS(11),
    [sym_nil_lit] = ACTIONS(149),
    [sym__dec] = ACTIONS(13),
    [sym__hex] = ACTIONS(13),
    [sym__radix] = ACTIONS(13),
    [sym_str_lit] = ACTIONS(151),
    [sym_buf_lit] = ACTIONS(151),
    [sym_sym_lit] = ACTIONS(149),
    [anon_sym_AT_LPAREN] = ACTIONS(15),
    [anon_sym_AT_LBRACK] = ACTIONS(17),
    [anon_sym_LBRACE] = ACTIONS(19),
    [anon_sym_AT_LBRACE] = ACTIONS(21),
    [anon_sym_LPAREN] = ACTIONS(23),
    [anon_sym_LBRACK] = ACTIONS(25),
    [anon_sym_TILDE] = ACTIONS(27),
    [anon_sym_SQUOTE] = ACTIONS(29),
    [anon_sym_PIPE] = ACTIONS(31),
    [anon_sym_SEMI] = ACTIONS(33),
    [anon_sym_COMMA] = ACTIONS(35),
    [sym_long_buf_lit] = ACTIONS(151),
    [sym_long_str_lit] = ACTIONS(151),
  },
  [18] = {
    [sym__gap] = STATE(54),
    [sym_dis_expr] = STATE(54),
    [sym__lit] = STATE(33),
    [sym_kwd_lit] = STATE(33),
    [sym_num_lit] = STATE(33),
    [sym_par_arr_lit] = STATE(33),
    [sym_sqr_arr_lit] = STATE(33),
    [sym_struct_lit] = STATE(33),
    [sym_tbl_lit] = STATE(33),
    [sym_par_tup_lit] = STATE(33),
    [sym_sqr_tup_lit] = STATE(33),
    [sym_qq_lit] = STATE(33),
    [sym_quote_lit] = STATE(33),
    [sym_short_fn_lit] = STATE(33),
    [sym_splice_lit] = STATE(33),
    [sym_unquote_lit] = STATE(33),
    [aux_sym_dis_expr_repeat1] = STATE(54),
    [sym__ws] = ACTIONS(153),
    [sym_comment] = ACTIONS(153),
    [anon_sym_BSLASH_POUND] = ACTIONS(7),
    [sym_bool_lit] = ACTIONS(155),
    [aux_sym_kwd_lit_token1] = ACTIONS(11),
    [sym_nil_lit] = ACTIONS(155),
    [sym__dec] = ACTIONS(13),
    [sym__hex] = ACTIONS(13),
    [sym__radix] = ACTIONS(13),
    [sym_str_lit] = ACTIONS(157),
    [sym_buf_lit] = ACTIONS(157),
    [sym_sym_lit] = ACTIONS(155),
    [anon_sym_AT_LPAREN] = ACTIONS(15),
    [anon_sym_AT_LBRACK] = ACTIONS(17),
    [anon_sym_LBRACE] = ACTIONS(19),
    [anon_sym_AT_LBRACE] = ACTIONS(21),
    [anon_sym_LPAREN] = ACTIONS(23),
    [anon_sym_LBRACK] = ACTIONS(25),
    [anon_sym_TILDE] = ACTIONS(27),
    [anon_sym_SQUOTE] = ACTIONS(29),
    [anon_sym_PIPE] = ACTIONS(31),
    [anon_sym_SEMI] = ACTIONS(33),
    [anon_sym_COMMA] = ACTIONS(35),
    [sym_long_buf_lit] = ACTIONS(157),
    [sym_long_str_lit] = ACTIONS(157),
  },
  [19] = {
    [sym__gap] = STATE(54),
    [sym_dis_expr] = STATE(54),
    [sym__lit] = STATE(44),
    [sym_kwd_lit] = STATE(44),
    [sym_num_lit] = STATE(44),
    [sym_par_arr_lit] = STATE(44),
    [sym_sqr_arr_lit] = STATE(44),
    [sym_struct_lit] = STATE(44),
    [sym_tbl_lit] = STATE(44),
    [sym_par_tup_lit] = STATE(44),
    [sym_sqr_tup_lit] = STATE(44),
    [sym_qq_lit] = STATE(44),
    [sym_quote_lit] = STATE(44),
    [sym_short_fn_lit] = STATE(44),
    [sym_splice_lit] = STATE(44),
    [sym_unquote_lit] = STATE(44),
    [aux_sym_dis_expr_repeat1] = STATE(54),
    [sym__ws] = ACTIONS(153),
    [sym_comment] = ACTIONS(153),
    [anon_sym_BSLASH_POUND] = ACTIONS(7),
    [sym_bool_lit] = ACTIONS(159),
    [aux_sym_kwd_lit_token1] = ACTIONS(11),
    [sym_nil_lit] = ACTIONS(159),
    [sym__dec] = ACTIONS(13),
    [sym__hex] = ACTIONS(13),
    [sym__radix] = ACTIONS(13),
    [sym_str_lit] = ACTIONS(161),
    [sym_buf_lit] = ACTIONS(161),
    [sym_sym_lit] = ACTIONS(159),
    [anon_sym_AT_LPAREN] = ACTIONS(15),
    [anon_sym_AT_LBRACK] = ACTIONS(17),
    [anon_sym_LBRACE] = ACTIONS(19),
    [anon_sym_AT_LBRACE] = ACTIONS(21),
    [anon_sym_LPAREN] = ACTIONS(23),
    [anon_sym_LBRACK] = ACTIONS(25),
    [anon_sym_TILDE] = ACTIONS(27),
    [anon_sym_SQUOTE] = ACTIONS(29),
    [anon_sym_PIPE] = ACTIONS(31),
    [anon_sym_SEMI] = ACTIONS(33),
    [anon_sym_COMMA] = ACTIONS(35),
    [sym_long_buf_lit] = ACTIONS(161),
    [sym_long_str_lit] = ACTIONS(161),
  },
  [20] = {
    [sym__gap] = STATE(54),
    [sym_dis_expr] = STATE(54),
    [sym__lit] = STATE(43),
    [sym_kwd_lit] = STATE(43),
    [sym_num_lit] = STATE(43),
    [sym_par_arr_lit] = STATE(43),
    [sym_sqr_arr_lit] = STATE(43),
    [sym_struct_lit] = STATE(43),
    [sym_tbl_lit] = STATE(43),
    [sym_par_tup_lit] = STATE(43),
    [sym_sqr_tup_lit] = STATE(43),
    [sym_qq_lit] = STATE(43),
    [sym_quote_lit] = STATE(43),
    [sym_short_fn_lit] = STATE(43),
    [sym_splice_lit] = STATE(43),
    [sym_unquote_lit] = STATE(43),
    [aux_sym_dis_expr_repeat1] = STATE(54),
    [sym__ws] = ACTIONS(153),
    [sym_comment] = ACTIONS(153),
    [anon_sym_BSLASH_POUND] = ACTIONS(7),
    [sym_bool_lit] = ACTIONS(163),
    [aux_sym_kwd_lit_token1] = ACTIONS(11),
    [sym_nil_lit] = ACTIONS(163),
    [sym__dec] = ACTIONS(13),
    [sym__hex] = ACTIONS(13),
    [sym__radix] = ACTIONS(13),
    [sym_str_lit] = ACTIONS(165),
    [sym_buf_lit] = ACTIONS(165),
    [sym_sym_lit] = ACTIONS(163),
    [anon_sym_AT_LPAREN] = ACTIONS(15),
    [anon_sym_AT_LBRACK] = ACTIONS(17),
    [anon_sym_LBRACE] = ACTIONS(19),
    [anon_sym_AT_LBRACE] = ACTIONS(21),
    [anon_sym_LPAREN] = ACTIONS(23),
    [anon_sym_LBRACK] = ACTIONS(25),
    [anon_sym_TILDE] = ACTIONS(27),
    [anon_sym_SQUOTE] = ACTIONS(29),
    [anon_sym_PIPE] = ACTIONS(31),
    [anon_sym_SEMI] = ACTIONS(33),
    [anon_sym_COMMA] = ACTIONS(35),
    [sym_long_buf_lit] = ACTIONS(165),
    [sym_long_str_lit] = ACTIONS(165),
  },
  [21] = {
    [sym__gap] = STATE(54),
    [sym_dis_expr] = STATE(54),
    [sym__lit] = STATE(53),
    [sym_kwd_lit] = STATE(53),
    [sym_num_lit] = STATE(53),
    [sym_par_arr_lit] = STATE(53),
    [sym_sqr_arr_lit] = STATE(53),
    [sym_struct_lit] = STATE(53),
    [sym_tbl_lit] = STATE(53),
    [sym_par_tup_lit] = STATE(53),
    [sym_sqr_tup_lit] = STATE(53),
    [sym_qq_lit] = STATE(53),
    [sym_quote_lit] = STATE(53),
    [sym_short_fn_lit] = STATE(53),
    [sym_splice_lit] = STATE(53),
    [sym_unquote_lit] = STATE(53),
    [aux_sym_dis_expr_repeat1] = STATE(54),
    [sym__ws] = ACTIONS(153),
    [sym_comment] = ACTIONS(153),
    [anon_sym_BSLASH_POUND] = ACTIONS(7),
    [sym_bool_lit] = ACTIONS(167),
    [aux_sym_kwd_lit_token1] = ACTIONS(11),
    [sym_nil_lit] = ACTIONS(167),
    [sym__dec] = ACTIONS(13),
    [sym__hex] = ACTIONS(13),
    [sym__radix] = ACTIONS(13),
    [sym_str_lit] = ACTIONS(169),
    [sym_buf_lit] = ACTIONS(169),
    [sym_sym_lit] = ACTIONS(167),
    [anon_sym_AT_LPAREN] = ACTIONS(15),
    [anon_sym_AT_LBRACK] = ACTIONS(17),
    [anon_sym_LBRACE] = ACTIONS(19),
    [anon_sym_AT_LBRACE] = ACTIONS(21),
    [anon_sym_LPAREN] = ACTIONS(23),
    [anon_sym_LBRACK] = ACTIONS(25),
    [anon_sym_TILDE] = ACTIONS(27),
    [anon_sym_SQUOTE] = ACTIONS(29),
    [anon_sym_PIPE] = ACTIONS(31),
    [anon_sym_SEMI] = ACTIONS(33),
    [anon_sym_COMMA] = ACTIONS(35),
    [sym_long_buf_lit] = ACTIONS(169),
    [sym_long_str_lit] = ACTIONS(169),
  },
  [22] = {
    [sym__gap] = STATE(54),
    [sym_dis_expr] = STATE(54),
    [sym__lit] = STATE(52),
    [sym_kwd_lit] = STATE(52),
    [sym_num_lit] = STATE(52),
    [sym_par_arr_lit] = STATE(52),
    [sym_sqr_arr_lit] = STATE(52),
    [sym_struct_lit] = STATE(52),
    [sym_tbl_lit] = STATE(52),
    [sym_par_tup_lit] = STATE(52),
    [sym_sqr_tup_lit] = STATE(52),
    [sym_qq_lit] = STATE(52),
    [sym_quote_lit] = STATE(52),
    [sym_short_fn_lit] = STATE(52),
    [sym_splice_lit] = STATE(52),
    [sym_unquote_lit] = STATE(52),
    [aux_sym_dis_expr_repeat1] = STATE(54),
    [sym__ws] = ACTIONS(153),
    [sym_comment] = ACTIONS(153),
    [anon_sym_BSLASH_POUND] = ACTIONS(7),
    [sym_bool_lit] = ACTIONS(171),
    [aux_sym_kwd_lit_token1] = ACTIONS(11),
    [sym_nil_lit] = ACTIONS(171),
    [sym__dec] = ACTIONS(13),
    [sym__hex] = ACTIONS(13),
    [sym__radix] = ACTIONS(13),
    [sym_str_lit] = ACTIONS(173),
    [sym_buf_lit] = ACTIONS(173),
    [sym_sym_lit] = ACTIONS(171),
    [anon_sym_AT_LPAREN] = ACTIONS(15),
    [anon_sym_AT_LBRACK] = ACTIONS(17),
    [anon_sym_LBRACE] = ACTIONS(19),
    [anon_sym_AT_LBRACE] = ACTIONS(21),
    [anon_sym_LPAREN] = ACTIONS(23),
    [anon_sym_LBRACK] = ACTIONS(25),
    [anon_sym_TILDE] = ACTIONS(27),
    [anon_sym_SQUOTE] = ACTIONS(29),
    [anon_sym_PIPE] = ACTIONS(31),
    [anon_sym_SEMI] = ACTIONS(33),
    [anon_sym_COMMA] = ACTIONS(35),
    [sym_long_buf_lit] = ACTIONS(173),
    [sym_long_str_lit] = ACTIONS(173),
  },
  [23] = {
    [sym__gap] = STATE(20),
    [sym_dis_expr] = STATE(20),
    [sym__lit] = STATE(29),
    [sym_kwd_lit] = STATE(29),
    [sym_num_lit] = STATE(29),
    [sym_par_arr_lit] = STATE(29),
    [sym_sqr_arr_lit] = STATE(29),
    [sym_struct_lit] = STATE(29),
    [sym_tbl_lit] = STATE(29),
    [sym_par_tup_lit] = STATE(29),
    [sym_sqr_tup_lit] = STATE(29),
    [sym_qq_lit] = STATE(29),
    [sym_quote_lit] = STATE(29),
    [sym_short_fn_lit] = STATE(29),
    [sym_splice_lit] = STATE(29),
    [sym_unquote_lit] = STATE(29),
    [aux_sym_dis_expr_repeat1] = STATE(20),
    [sym__ws] = ACTIONS(175),
    [sym_comment] = ACTIONS(175),
    [anon_sym_BSLASH_POUND] = ACTIONS(7),
    [sym_bool_lit] = ACTIONS(177),
    [aux_sym_kwd_lit_token1] = ACTIONS(11),
    [sym_nil_lit] = ACTIONS(177),
    [sym__dec] = ACTIONS(13),
    [sym__hex] = ACTIONS(13),
    [sym__radix] = ACTIONS(13),
    [sym_str_lit] = ACTIONS(179),
    [sym_buf_lit] = ACTIONS(179),
    [sym_sym_lit] = ACTIONS(177),
    [anon_sym_AT_LPAREN] = ACTIONS(15),
    [anon_sym_AT_LBRACK] = ACTIONS(17),
    [anon_sym_LBRACE] = ACTIONS(19),
    [anon_sym_AT_LBRACE] = ACTIONS(21),
    [anon_sym_LPAREN] = ACTIONS(23),
    [anon_sym_LBRACK] = ACTIONS(25),
    [anon_sym_TILDE] = ACTIONS(27),
    [anon_sym_SQUOTE] = ACTIONS(29),
    [anon_sym_PIPE] = ACTIONS(31),
    [anon_sym_SEMI] = ACTIONS(33),
    [anon_sym_COMMA] = ACTIONS(35),
    [sym_long_buf_lit] = ACTIONS(179),
    [sym_long_str_lit] = ACTIONS(179),
  },
  [24] = {
    [sym__gap] = STATE(54),
    [sym_dis_expr] = STATE(54),
    [sym__lit] = STATE(51),
    [sym_kwd_lit] = STATE(51),
    [sym_num_lit] = STATE(51),
    [sym_par_arr_lit] = STATE(51),
    [sym_sqr_arr_lit] = STATE(51),
    [sym_struct_lit] = STATE(51),
    [sym_tbl_lit] = STATE(51),
    [sym_par_tup_lit] = STATE(51),
    [sym_sqr_tup_lit] = STATE(51),
    [sym_qq_lit] = STATE(51),
    [sym_quote_lit] = STATE(51),
    [sym_short_fn_lit] = STATE(51),
    [sym_splice_lit] = STATE(51),
    [sym_unquote_lit] = STATE(51),
    [aux_sym_dis_expr_repeat1] = STATE(54),
    [sym__ws] = ACTIONS(153),
    [sym_comment] = ACTIONS(153),
    [anon_sym_BSLASH_POUND] = ACTIONS(7),
    [sym_bool_lit] = ACTIONS(181),
    [aux_sym_kwd_lit_token1] = ACTIONS(11),
    [sym_nil_lit] = ACTIONS(181),
    [sym__dec] = ACTIONS(13),
    [sym__hex] = ACTIONS(13),
    [sym__radix] = ACTIONS(13),
    [sym_str_lit] = ACTIONS(183),
    [sym_buf_lit] = ACTIONS(183),
    [sym_sym_lit] = ACTIONS(181),
    [anon_sym_AT_LPAREN] = ACTIONS(15),
    [anon_sym_AT_LBRACK] = ACTIONS(17),
    [anon_sym_LBRACE] = ACTIONS(19),
    [anon_sym_AT_LBRACE] = ACTIONS(21),
    [anon_sym_LPAREN] = ACTIONS(23),
    [anon_sym_LBRACK] = ACTIONS(25),
    [anon_sym_TILDE] = ACTIONS(27),
    [anon_sym_SQUOTE] = ACTIONS(29),
    [anon_sym_PIPE] = ACTIONS(31),
    [anon_sym_SEMI] = ACTIONS(33),
    [anon_sym_COMMA] = ACTIONS(35),
    [sym_long_buf_lit] = ACTIONS(183),
    [sym_long_str_lit] = ACTIONS(183),
  },
  [25] = {
    [sym__gap] = STATE(21),
    [sym_dis_expr] = STATE(21),
    [sym__lit] = STATE(36),
    [sym_kwd_lit] = STATE(36),
    [sym_num_lit] = STATE(36),
    [sym_par_arr_lit] = STATE(36),
    [sym_sqr_arr_lit] = STATE(36),
    [sym_struct_lit] = STATE(36),
    [sym_tbl_lit] = STATE(36),
    [sym_par_tup_lit] = STATE(36),
    [sym_sqr_tup_lit] = STATE(36),
    [sym_qq_lit] = STATE(36),
    [sym_quote_lit] = STATE(36),
    [sym_short_fn_lit] = STATE(36),
    [sym_splice_lit] = STATE(36),
    [sym_unquote_lit] = STATE(36),
    [aux_sym_dis_expr_repeat1] = STATE(21),
    [sym__ws] = ACTIONS(185),
    [sym_comment] = ACTIONS(185),
    [anon_sym_BSLASH_POUND] = ACTIONS(7),
    [sym_bool_lit] = ACTIONS(187),
    [aux_sym_kwd_lit_token1] = ACTIONS(11),
    [sym_nil_lit] = ACTIONS(187),
    [sym__dec] = ACTIONS(13),
    [sym__hex] = ACTIONS(13),
    [sym__radix] = ACTIONS(13),
    [sym_str_lit] = ACTIONS(189),
    [sym_buf_lit] = ACTIONS(189),
    [sym_sym_lit] = ACTIONS(187),
    [anon_sym_AT_LPAREN] = ACTIONS(15),
    [anon_sym_AT_LBRACK] = ACTIONS(17),
    [anon_sym_LBRACE] = ACTIONS(19),
    [anon_sym_AT_LBRACE] = ACTIONS(21),
    [anon_sym_LPAREN] = ACTIONS(23),
    [anon_sym_LBRACK] = ACTIONS(25),
    [anon_sym_TILDE] = ACTIONS(27),
    [anon_sym_SQUOTE] = ACTIONS(29),
    [anon_sym_PIPE] = ACTIONS(31),
    [anon_sym_SEMI] = ACTIONS(33),
    [anon_sym_COMMA] = ACTIONS(35),
    [sym_long_buf_lit] = ACTIONS(189),
    [sym_long_str_lit] = ACTIONS(189),
  },
  [26] = {
    [sym__gap] = STATE(18),
    [sym_dis_expr] = STATE(18),
    [sym__lit] = STATE(40),
    [sym_kwd_lit] = STATE(40),
    [sym_num_lit] = STATE(40),
    [sym_par_arr_lit] = STATE(40),
    [sym_sqr_arr_lit] = STATE(40),
    [sym_struct_lit] = STATE(40),
    [sym_tbl_lit] = STATE(40),
    [sym_par_tup_lit] = STATE(40),
    [sym_sqr_tup_lit] = STATE(40),
    [sym_qq_lit] = STATE(40),
    [sym_quote_lit] = STATE(40),
    [sym_short_fn_lit] = STATE(40),
    [sym_splice_lit] = STATE(40),
    [sym_unquote_lit] = STATE(40),
    [aux_sym_dis_expr_repeat1] = STATE(18),
    [sym__ws] = ACTIONS(191),
    [sym_comment] = ACTIONS(191),
    [anon_sym_BSLASH_POUND] = ACTIONS(7),
    [sym_bool_lit] = ACTIONS(193),
    [aux_sym_kwd_lit_token1] = ACTIONS(11),
    [sym_nil_lit] = ACTIONS(193),
    [sym__dec] = ACTIONS(13),
    [sym__hex] = ACTIONS(13),
    [sym__radix] = ACTIONS(13),
    [sym_str_lit] = ACTIONS(195),
    [sym_buf_lit] = ACTIONS(195),
    [sym_sym_lit] = ACTIONS(193),
    [anon_sym_AT_LPAREN] = ACTIONS(15),
    [anon_sym_AT_LBRACK] = ACTIONS(17),
    [anon_sym_LBRACE] = ACTIONS(19),
    [anon_sym_AT_LBRACE] = ACTIONS(21),
    [anon_sym_LPAREN] = ACTIONS(23),
    [anon_sym_LBRACK] = ACTIONS(25),
    [anon_sym_TILDE] = ACTIONS(27),
    [anon_sym_SQUOTE] = ACTIONS(29),
    [anon_sym_PIPE] = ACTIONS(31),
    [anon_sym_SEMI] = ACTIONS(33),
    [anon_sym_COMMA] = ACTIONS(35),
    [sym_long_buf_lit] = ACTIONS(195),
    [sym_long_str_lit] = ACTIONS(195),
  },
  [27] = {
    [sym__gap] = STATE(22),
    [sym_dis_expr] = STATE(22),
    [sym__lit] = STATE(34),
    [sym_kwd_lit] = STATE(34),
    [sym_num_lit] = STATE(34),
    [sym_par_arr_lit] = STATE(34),
    [sym_sqr_arr_lit] = STATE(34),
    [sym_struct_lit] = STATE(34),
    [sym_tbl_lit] = STATE(34),
    [sym_par_tup_lit] = STATE(34),
    [sym_sqr_tup_lit] = STATE(34),
    [sym_qq_lit] = STATE(34),
    [sym_quote_lit] = STATE(34),
    [sym_short_fn_lit] = STATE(34),
    [sym_splice_lit] = STATE(34),
    [sym_unquote_lit] = STATE(34),
    [aux_sym_dis_expr_repeat1] = STATE(22),
    [sym__ws] = ACTIONS(197),
    [sym_comment] = ACTIONS(197),
    [anon_sym_BSLASH_POUND] = ACTIONS(7),
    [sym_bool_lit] = ACTIONS(199),
    [aux_sym_kwd_lit_token1] = ACTIONS(11),
    [sym_nil_lit] = ACTIONS(199),
    [sym__dec] = ACTIONS(13),
    [sym__hex] = ACTIONS(13),
    [sym__radix] = ACTIONS(13),
    [sym_str_lit] = ACTIONS(201),
    [sym_buf_lit] = ACTIONS(201),
    [sym_sym_lit] = ACTIONS(199),
    [anon_sym_AT_LPAREN] = ACTIONS(15),
    [anon_sym_AT_LBRACK] = ACTIONS(17),
    [anon_sym_LBRACE] = ACTIONS(19),
    [anon_sym_AT_LBRACE] = ACTIONS(21),
    [anon_sym_LPAREN] = ACTIONS(23),
    [anon_sym_LBRACK] = ACTIONS(25),
    [anon_sym_TILDE] = ACTIONS(27),
    [anon_sym_SQUOTE] = ACTIONS(29),
    [anon_sym_PIPE] = ACTIONS(31),
    [anon_sym_SEMI] = ACTIONS(33),
    [anon_sym_COMMA] = ACTIONS(35),
    [sym_long_buf_lit] = ACTIONS(201),
    [sym_long_str_lit] = ACTIONS(201),
  },
  [28] = {
    [ts_builtin_sym_end] = ACTIONS(203),
    [sym__ws] = ACTIONS(203),
    [sym_comment] = ACTIONS(203),
    [anon_sym_BSLASH_POUND] = ACTIONS(203),
    [sym_bool_lit] = ACTIONS(205),
    [aux_sym_kwd_lit_token1] = ACTIONS(203),
    [sym_nil_lit] = ACTIONS(205),
    [sym__dec] = ACTIONS(205),
    [sym__hex] = ACTIONS(205),
    [sym__radix] = ACTIONS(205),
    [sym_str_lit] = ACTIONS(203),
    [sym_buf_lit] = ACTIONS(203),
    [sym_sym_lit] = ACTIONS(205),
    [anon_sym_AT_LPAREN] = ACTIONS(203),
    [anon_sym_RPAREN] = ACTIONS(203),
    [anon_sym_AT_LBRACK] = ACTIONS(203),
    [anon_sym_RBRACK] = ACTIONS(203),
    [anon_sym_LBRACE] = ACTIONS(203),
    [anon_sym_RBRACE] = ACTIONS(203),
    [anon_sym_AT_LBRACE] = ACTIONS(203),
    [anon_sym_LPAREN] = ACTIONS(203),
    [anon_sym_LBRACK] = ACTIONS(203),
    [anon_sym_TILDE] = ACTIONS(203),
    [anon_sym_SQUOTE] = ACTIONS(203),
    [anon_sym_PIPE] = ACTIONS(203),
    [anon_sym_SEMI] = ACTIONS(203),
    [anon_sym_COMMA] = ACTIONS(203),
    [sym_long_buf_lit] = ACTIONS(203),
    [sym_long_str_lit] = ACTIONS(203),
  },
  [29] = {
    [ts_builtin_sym_end] = ACTIONS(207),
    [sym__ws] = ACTIONS(207),
    [sym_comment] = ACTIONS(207),
    [anon_sym_BSLASH_POUND] = ACTIONS(207),
    [sym_bool_lit] = ACTIONS(209),
    [aux_sym_kwd_lit_token1] = ACTIONS(207),
    [sym_nil_lit] = ACTIONS(209),
    [sym__dec] = ACTIONS(209),
    [sym__hex] = ACTIONS(209),
    [sym__radix] = ACTIONS(209),
    [sym_str_lit] = ACTIONS(207),
    [sym_buf_lit] = ACTIONS(207),
    [sym_sym_lit] = ACTIONS(209),
    [anon_sym_AT_LPAREN] = ACTIONS(207),
    [anon_sym_RPAREN] = ACTIONS(207),
    [anon_sym_AT_LBRACK] = ACTIONS(207),
    [anon_sym_RBRACK] = ACTIONS(207),
    [anon_sym_LBRACE] = ACTIONS(207),
    [anon_sym_RBRACE] = ACTIONS(207),
    [anon_sym_AT_LBRACE] = ACTIONS(207),
    [anon_sym_LPAREN] = ACTIONS(207),
    [anon_sym_LBRACK] = ACTIONS(207),
    [anon_sym_TILDE] = ACTIONS(207),
    [anon_sym_SQUOTE] = ACTIONS(207),
    [anon_sym_PIPE] = ACTIONS(207),
    [anon_sym_SEMI] = ACTIONS(207),
    [anon_sym_COMMA] = ACTIONS(207),
    [sym_long_buf_lit] = ACTIONS(207),
    [sym_long_str_lit] = ACTIONS(207),
  },
  [30] = {
    [ts_builtin_sym_end] = ACTIONS(211),
    [sym__ws] = ACTIONS(211),
    [sym_comment] = ACTIONS(211),
    [anon_sym_BSLASH_POUND] = ACTIONS(211),
    [sym_bool_lit] = ACTIONS(213),
    [aux_sym_kwd_lit_token1] = ACTIONS(211),
    [sym_nil_lit] = ACTIONS(213),
    [sym__dec] = ACTIONS(213),
    [sym__hex] = ACTIONS(213),
    [sym__radix] = ACTIONS(213),
    [sym_str_lit] = ACTIONS(211),
    [sym_buf_lit] = ACTIONS(211),
    [sym_sym_lit] = ACTIONS(213),
    [anon_sym_AT_LPAREN] = ACTIONS(211),
    [anon_sym_RPAREN] = ACTIONS(211),
    [anon_sym_AT_LBRACK] = ACTIONS(211),
    [anon_sym_RBRACK] = ACTIONS(211),
    [anon_sym_LBRACE] = ACTIONS(211),
    [anon_sym_RBRACE] = ACTIONS(211),
    [anon_sym_AT_LBRACE] = ACTIONS(211),
    [anon_sym_LPAREN] = ACTIONS(211),
    [anon_sym_LBRACK] = ACTIONS(211),
    [anon_sym_TILDE] = ACTIONS(211),
    [anon_sym_SQUOTE] = ACTIONS(211),
    [anon_sym_PIPE] = ACTIONS(211),
    [anon_sym_SEMI] = ACTIONS(211),
    [anon_sym_COMMA] = ACTIONS(211),
    [sym_long_buf_lit] = ACTIONS(211),
    [sym_long_str_lit] = ACTIONS(211),
  },
  [31] = {
    [ts_builtin_sym_end] = ACTIONS(215),
    [sym__ws] = ACTIONS(215),
    [sym_comment] = ACTIONS(215),
    [anon_sym_BSLASH_POUND] = ACTIONS(215),
    [sym_bool_lit] = ACTIONS(217),
    [aux_sym_kwd_lit_token1] = ACTIONS(215),
    [sym_nil_lit] = ACTIONS(217),
    [sym__dec] = ACTIONS(217),
    [sym__hex] = ACTIONS(217),
    [sym__radix] = ACTIONS(217),
    [sym_str_lit] = ACTIONS(215),
    [sym_buf_lit] = ACTIONS(215),
    [sym_sym_lit] = ACTIONS(217),
    [anon_sym_AT_LPAREN] = ACTIONS(215),
    [anon_sym_RPAREN] = ACTIONS(215),
    [anon_sym_AT_LBRACK] = ACTIONS(215),
    [anon_sym_RBRACK] = ACTIONS(215),
    [anon_sym_LBRACE] = ACTIONS(215),
    [anon_sym_RBRACE] = ACTIONS(215),
    [anon_sym_AT_LBRACE] = ACTIONS(215),
    [anon_sym_LPAREN] = ACTIONS(215),
    [anon_sym_LBRACK] = ACTIONS(215),
    [anon_sym_TILDE] = ACTIONS(215),
    [anon_sym_SQUOTE] = ACTIONS(215),
    [anon_sym_PIPE] = ACTIONS(215),
    [anon_sym_SEMI] = ACTIONS(215),
    [anon_sym_COMMA] = ACTIONS(215),
    [sym_long_buf_lit] = ACTIONS(215),
    [sym_long_str_lit] = ACTIONS(215),
  },
  [32] = {
    [ts_builtin_sym_end] = ACTIONS(219),
    [sym__ws] = ACTIONS(219),
    [sym_comment] = ACTIONS(219),
    [anon_sym_BSLASH_POUND] = ACTIONS(219),
    [sym_bool_lit] = ACTIONS(221),
    [aux_sym_kwd_lit_token1] = ACTIONS(219),
    [sym_nil_lit] = ACTIONS(221),
    [sym__dec] = ACTIONS(221),
    [sym__hex] = ACTIONS(221),
    [sym__radix] = ACTIONS(221),
    [sym_str_lit] = ACTIONS(219),
    [sym_buf_lit] = ACTIONS(219),
    [sym_sym_lit] = ACTIONS(221),
    [anon_sym_AT_LPAREN] = ACTIONS(219),
    [anon_sym_RPAREN] = ACTIONS(219),
    [anon_sym_AT_LBRACK] = ACTIONS(219),
    [anon_sym_RBRACK] = ACTIONS(219),
    [anon_sym_LBRACE] = ACTIONS(219),
    [anon_sym_RBRACE] = ACTIONS(219),
    [anon_sym_AT_LBRACE] = ACTIONS(219),
    [anon_sym_LPAREN] = ACTIONS(219),
    [anon_sym_LBRACK] = ACTIONS(219),
    [anon_sym_TILDE] = ACTIONS(219),
    [anon_sym_SQUOTE] = ACTIONS(219),
    [anon_sym_PIPE] = ACTIONS(219),
    [anon_sym_SEMI] = ACTIONS(219),
    [anon_sym_COMMA] = ACTIONS(219),
    [sym_long_buf_lit] = ACTIONS(219),
    [sym_long_str_lit] = ACTIONS(219),
  },
  [33] = {
    [ts_builtin_sym_end] = ACTIONS(223),
    [sym__ws] = ACTIONS(223),
    [sym_comment] = ACTIONS(223),
    [anon_sym_BSLASH_POUND] = ACTIONS(223),
    [sym_bool_lit] = ACTIONS(225),
    [aux_sym_kwd_lit_token1] = ACTIONS(223),
    [sym_nil_lit] = ACTIONS(225),
    [sym__dec] = ACTIONS(225),
    [sym__hex] = ACTIONS(225),
    [sym__radix] = ACTIONS(225),
    [sym_str_lit] = ACTIONS(223),
    [sym_buf_lit] = ACTIONS(223),
    [sym_sym_lit] = ACTIONS(225),
    [anon_sym_AT_LPAREN] = ACTIONS(223),
    [anon_sym_RPAREN] = ACTIONS(223),
    [anon_sym_AT_LBRACK] = ACTIONS(223),
    [anon_sym_RBRACK] = ACTIONS(223),
    [anon_sym_LBRACE] = ACTIONS(223),
    [anon_sym_RBRACE] = ACTIONS(223),
    [anon_sym_AT_LBRACE] = ACTIONS(223),
    [anon_sym_LPAREN] = ACTIONS(223),
    [anon_sym_LBRACK] = ACTIONS(223),
    [anon_sym_TILDE] = ACTIONS(223),
    [anon_sym_SQUOTE] = ACTIONS(223),
    [anon_sym_PIPE] = ACTIONS(223),
    [anon_sym_SEMI] = ACTIONS(223),
    [anon_sym_COMMA] = ACTIONS(223),
    [sym_long_buf_lit] = ACTIONS(223),
    [sym_long_str_lit] = ACTIONS(223),
  },
  [34] = {
    [ts_builtin_sym_end] = ACTIONS(227),
    [sym__ws] = ACTIONS(227),
    [sym_comment] = ACTIONS(227),
    [anon_sym_BSLASH_POUND] = ACTIONS(227),
    [sym_bool_lit] = ACTIONS(229),
    [aux_sym_kwd_lit_token1] = ACTIONS(227),
    [sym_nil_lit] = ACTIONS(229),
    [sym__dec] = ACTIONS(229),
    [sym__hex] = ACTIONS(229),
    [sym__radix] = ACTIONS(229),
    [sym_str_lit] = ACTIONS(227),
    [sym_buf_lit] = ACTIONS(227),
    [sym_sym_lit] = ACTIONS(229),
    [anon_sym_AT_LPAREN] = ACTIONS(227),
    [anon_sym_RPAREN] = ACTIONS(227),
    [anon_sym_AT_LBRACK] = ACTIONS(227),
    [anon_sym_RBRACK] = ACTIONS(227),
    [anon_sym_LBRACE] = ACTIONS(227),
    [anon_sym_RBRACE] = ACTIONS(227),
    [anon_sym_AT_LBRACE] = ACTIONS(227),
    [anon_sym_LPAREN] = ACTIONS(227),
    [anon_sym_LBRACK] = ACTIONS(227),
    [anon_sym_TILDE] = ACTIONS(227),
    [anon_sym_SQUOTE] = ACTIONS(227),
    [anon_sym_PIPE] = ACTIONS(227),
    [anon_sym_SEMI] = ACTIONS(227),
    [anon_sym_COMMA] = ACTIONS(227),
    [sym_long_buf_lit] = ACTIONS(227),
    [sym_long_str_lit] = ACTIONS(227),
  },
  [35] = {
    [ts_builtin_sym_end] = ACTIONS(231),
    [sym__ws] = ACTIONS(231),
    [sym_comment] = ACTIONS(231),
    [anon_sym_BSLASH_POUND] = ACTIONS(231),
    [sym_bool_lit] = ACTIONS(233),
    [aux_sym_kwd_lit_token1] = ACTIONS(231),
    [sym_nil_lit] = ACTIONS(233),
    [sym__dec] = ACTIONS(233),
    [sym__hex] = ACTIONS(233),
    [sym__radix] = ACTIONS(233),
    [sym_str_lit] = ACTIONS(231),
    [sym_buf_lit] = ACTIONS(231),
    [sym_sym_lit] = ACTIONS(233),
    [anon_sym_AT_LPAREN] = ACTIONS(231),
    [anon_sym_RPAREN] = ACTIONS(231),
    [anon_sym_AT_LBRACK] = ACTIONS(231),
    [anon_sym_RBRACK] = ACTIONS(231),
    [anon_sym_LBRACE] = ACTIONS(231),
    [anon_sym_RBRACE] = ACTIONS(231),
    [anon_sym_AT_LBRACE] = ACTIONS(231),
    [anon_sym_LPAREN] = ACTIONS(231),
    [anon_sym_LBRACK] = ACTIONS(231),
    [anon_sym_TILDE] = ACTIONS(231),
    [anon_sym_SQUOTE] = ACTIONS(231),
    [anon_sym_PIPE] = ACTIONS(231),
    [anon_sym_SEMI] = ACTIONS(231),
    [anon_sym_COMMA] = ACTIONS(231),
    [sym_long_buf_lit] = ACTIONS(231),
    [sym_long_str_lit] = ACTIONS(231),
  },
  [36] = {
    [ts_builtin_sym_end] = ACTIONS(235),
    [sym__ws] = ACTIONS(235),
    [sym_comment] = ACTIONS(235),
    [anon_sym_BSLASH_POUND] = ACTIONS(235),
    [sym_bool_lit] = ACTIONS(237),
    [aux_sym_kwd_lit_token1] = ACTIONS(235),
    [sym_nil_lit] = ACTIONS(237),
    [sym__dec] = ACTIONS(237),
    [sym__hex] = ACTIONS(237),
    [sym__radix] = ACTIONS(237),
    [sym_str_lit] = ACTIONS(235),
    [sym_buf_lit] = ACTIONS(235),
    [sym_sym_lit] = ACTIONS(237),
    [anon_sym_AT_LPAREN] = ACTIONS(235),
    [anon_sym_RPAREN] = ACTIONS(235),
    [anon_sym_AT_LBRACK] = ACTIONS(235),
    [anon_sym_RBRACK] = ACTIONS(235),
    [anon_sym_LBRACE] = ACTIONS(235),
    [anon_sym_RBRACE] = ACTIONS(235),
    [anon_sym_AT_LBRACE] = ACTIONS(235),
    [anon_sym_LPAREN] = ACTIONS(235),
    [anon_sym_LBRACK] = ACTIONS(235),
    [anon_sym_TILDE] = ACTIONS(235),
    [anon_sym_SQUOTE] = ACTIONS(235),
    [anon_sym_PIPE] = ACTIONS(235),
    [anon_sym_SEMI] = ACTIONS(235),
    [anon_sym_COMMA] = ACTIONS(235),
    [sym_long_buf_lit] = ACTIONS(235),
    [sym_long_str_lit] = ACTIONS(235),
  },
  [37] = {
    [ts_builtin_sym_end] = ACTIONS(239),
    [sym__ws] = ACTIONS(239),
    [sym_comment] = ACTIONS(239),
    [anon_sym_BSLASH_POUND] = ACTIONS(239),
    [sym_bool_lit] = ACTIONS(241),
    [aux_sym_kwd_lit_token1] = ACTIONS(239),
    [sym_nil_lit] = ACTIONS(241),
    [sym__dec] = ACTIONS(241),
    [sym__hex] = ACTIONS(241),
    [sym__radix] = ACTIONS(241),
    [sym_str_lit] = ACTIONS(239),
    [sym_buf_lit] = ACTIONS(239),
    [sym_sym_lit] = ACTIONS(241),
    [anon_sym_AT_LPAREN] = ACTIONS(239),
    [anon_sym_RPAREN] = ACTIONS(239),
    [anon_sym_AT_LBRACK] = ACTIONS(239),
    [anon_sym_RBRACK] = ACTIONS(239),
    [anon_sym_LBRACE] = ACTIONS(239),
    [anon_sym_RBRACE] = ACTIONS(239),
    [anon_sym_AT_LBRACE] = ACTIONS(239),
    [anon_sym_LPAREN] = ACTIONS(239),
    [anon_sym_LBRACK] = ACTIONS(239),
    [anon_sym_TILDE] = ACTIONS(239),
    [anon_sym_SQUOTE] = ACTIONS(239),
    [anon_sym_PIPE] = ACTIONS(239),
    [anon_sym_SEMI] = ACTIONS(239),
    [anon_sym_COMMA] = ACTIONS(239),
    [sym_long_buf_lit] = ACTIONS(239),
    [sym_long_str_lit] = ACTIONS(239),
  },
  [38] = {
    [ts_builtin_sym_end] = ACTIONS(243),
    [sym__ws] = ACTIONS(243),
    [sym_comment] = ACTIONS(243),
    [anon_sym_BSLASH_POUND] = ACTIONS(243),
    [sym_bool_lit] = ACTIONS(245),
    [aux_sym_kwd_lit_token1] = ACTIONS(243),
    [sym_nil_lit] = ACTIONS(245),
    [sym__dec] = ACTIONS(245),
    [sym__hex] = ACTIONS(245),
    [sym__radix] = ACTIONS(245),
    [sym_str_lit] = ACTIONS(243),
    [sym_buf_lit] = ACTIONS(243),
    [sym_sym_lit] = ACTIONS(245),
    [anon_sym_AT_LPAREN] = ACTIONS(243),
    [anon_sym_RPAREN] = ACTIONS(243),
    [anon_sym_AT_LBRACK] = ACTIONS(243),
    [anon_sym_RBRACK] = ACTIONS(243),
    [anon_sym_LBRACE] = ACTIONS(243),
    [anon_sym_RBRACE] = ACTIONS(243),
    [anon_sym_AT_LBRACE] = ACTIONS(243),
    [anon_sym_LPAREN] = ACTIONS(243),
    [anon_sym_LBRACK] = ACTIONS(243),
    [anon_sym_TILDE] = ACTIONS(243),
    [anon_sym_SQUOTE] = ACTIONS(243),
    [anon_sym_PIPE] = ACTIONS(243),
    [anon_sym_SEMI] = ACTIONS(243),
    [anon_sym_COMMA] = ACTIONS(243),
    [sym_long_buf_lit] = ACTIONS(243),
    [sym_long_str_lit] = ACTIONS(243),
  },
  [39] = {
    [ts_builtin_sym_end] = ACTIONS(247),
    [sym__ws] = ACTIONS(247),
    [sym_comment] = ACTIONS(247),
    [anon_sym_BSLASH_POUND] = ACTIONS(247),
    [sym_bool_lit] = ACTIONS(249),
    [aux_sym_kwd_lit_token1] = ACTIONS(247),
    [sym_nil_lit] = ACTIONS(249),
    [sym__dec] = ACTIONS(249),
    [sym__hex] = ACTIONS(249),
    [sym__radix] = ACTIONS(249),
    [sym_str_lit] = ACTIONS(247),
    [sym_buf_lit] = ACTIONS(247),
    [sym_sym_lit] = ACTIONS(249),
    [anon_sym_AT_LPAREN] = ACTIONS(247),
    [anon_sym_RPAREN] = ACTIONS(247),
    [anon_sym_AT_LBRACK] = ACTIONS(247),
    [anon_sym_RBRACK] = ACTIONS(247),
    [anon_sym_LBRACE] = ACTIONS(247),
    [anon_sym_RBRACE] = ACTIONS(247),
    [anon_sym_AT_LBRACE] = ACTIONS(247),
    [anon_sym_LPAREN] = ACTIONS(247),
    [anon_sym_LBRACK] = ACTIONS(247),
    [anon_sym_TILDE] = ACTIONS(247),
    [anon_sym_SQUOTE] = ACTIONS(247),
    [anon_sym_PIPE] = ACTIONS(247),
    [anon_sym_SEMI] = ACTIONS(247),
    [anon_sym_COMMA] = ACTIONS(247),
    [sym_long_buf_lit] = ACTIONS(247),
    [sym_long_str_lit] = ACTIONS(247),
  },
  [40] = {
    [ts_builtin_sym_end] = ACTIONS(251),
    [sym__ws] = ACTIONS(251),
    [sym_comment] = ACTIONS(251),
    [anon_sym_BSLASH_POUND] = ACTIONS(251),
    [sym_bool_lit] = ACTIONS(253),
    [aux_sym_kwd_lit_token1] = ACTIONS(251),
    [sym_nil_lit] = ACTIONS(253),
    [sym__dec] = ACTIONS(253),
    [sym__hex] = ACTIONS(253),
    [sym__radix] = ACTIONS(253),
    [sym_str_lit] = ACTIONS(251),
    [sym_buf_lit] = ACTIONS(251),
    [sym_sym_lit] = ACTIONS(253),
    [anon_sym_AT_LPAREN] = ACTIONS(251),
    [anon_sym_RPAREN] = ACTIONS(251),
    [anon_sym_AT_LBRACK] = ACTIONS(251),
    [anon_sym_RBRACK] = ACTIONS(251),
    [anon_sym_LBRACE] = ACTIONS(251),
    [anon_sym_RBRACE] = ACTIONS(251),
    [anon_sym_AT_LBRACE] = ACTIONS(251),
    [anon_sym_LPAREN] = ACTIONS(251),
    [anon_sym_LBRACK] = ACTIONS(251),
    [anon_sym_TILDE] = ACTIONS(251),
    [anon_sym_SQUOTE] = ACTIONS(251),
    [anon_sym_PIPE] = ACTIONS(251),
    [anon_sym_SEMI] = ACTIONS(251),
    [anon_sym_COMMA] = ACTIONS(251),
    [sym_long_buf_lit] = ACTIONS(251),
    [sym_long_str_lit] = ACTIONS(251),
  },
  [41] = {
    [ts_builtin_sym_end] = ACTIONS(255),
    [sym__ws] = ACTIONS(255),
    [sym_comment] = ACTIONS(255),
    [anon_sym_BSLASH_POUND] = ACTIONS(255),
    [sym_bool_lit] = ACTIONS(257),
    [aux_sym_kwd_lit_token1] = ACTIONS(255),
    [sym_nil_lit] = ACTIONS(257),
    [sym__dec] = ACTIONS(257),
    [sym__hex] = ACTIONS(257),
    [sym__radix] = ACTIONS(257),
    [sym_str_lit] = ACTIONS(255),
    [sym_buf_lit] = ACTIONS(255),
    [sym_sym_lit] = ACTIONS(257),
    [anon_sym_AT_LPAREN] = ACTIONS(255),
    [anon_sym_RPAREN] = ACTIONS(255),
    [anon_sym_AT_LBRACK] = ACTIONS(255),
    [anon_sym_RBRACK] = ACTIONS(255),
    [anon_sym_LBRACE] = ACTIONS(255),
    [anon_sym_RBRACE] = ACTIONS(255),
    [anon_sym_AT_LBRACE] = ACTIONS(255),
    [anon_sym_LPAREN] = ACTIONS(255),
    [anon_sym_LBRACK] = ACTIONS(255),
    [anon_sym_TILDE] = ACTIONS(255),
    [anon_sym_SQUOTE] = ACTIONS(255),
    [anon_sym_PIPE] = ACTIONS(255),
    [anon_sym_SEMI] = ACTIONS(255),
    [anon_sym_COMMA] = ACTIONS(255),
    [sym_long_buf_lit] = ACTIONS(255),
    [sym_long_str_lit] = ACTIONS(255),
  },
  [42] = {
    [ts_builtin_sym_end] = ACTIONS(259),
    [sym__ws] = ACTIONS(259),
    [sym_comment] = ACTIONS(259),
    [anon_sym_BSLASH_POUND] = ACTIONS(259),
    [sym_bool_lit] = ACTIONS(261),
    [aux_sym_kwd_lit_token1] = ACTIONS(259),
    [sym_nil_lit] = ACTIONS(261),
    [sym__dec] = ACTIONS(261),
    [sym__hex] = ACTIONS(261),
    [sym__radix] = ACTIONS(261),
    [sym_str_lit] = ACTIONS(259),
    [sym_buf_lit] = ACTIONS(259),
    [sym_sym_lit] = ACTIONS(261),
    [anon_sym_AT_LPAREN] = ACTIONS(259),
    [anon_sym_RPAREN] = ACTIONS(259),
    [anon_sym_AT_LBRACK] = ACTIONS(259),
    [anon_sym_RBRACK] = ACTIONS(259),
    [anon_sym_LBRACE] = ACTIONS(259),
    [anon_sym_RBRACE] = ACTIONS(259),
    [anon_sym_AT_LBRACE] = ACTIONS(259),
    [anon_sym_LPAREN] = ACTIONS(259),
    [anon_sym_LBRACK] = ACTIONS(259),
    [anon_sym_TILDE] = ACTIONS(259),
    [anon_sym_SQUOTE] = ACTIONS(259),
    [anon_sym_PIPE] = ACTIONS(259),
    [anon_sym_SEMI] = ACTIONS(259),
    [anon_sym_COMMA] = ACTIONS(259),
    [sym_long_buf_lit] = ACTIONS(259),
    [sym_long_str_lit] = ACTIONS(259),
  },
  [43] = {
    [ts_builtin_sym_end] = ACTIONS(263),
    [sym__ws] = ACTIONS(263),
    [sym_comment] = ACTIONS(263),
    [anon_sym_BSLASH_POUND] = ACTIONS(263),
    [sym_bool_lit] = ACTIONS(265),
    [aux_sym_kwd_lit_token1] = ACTIONS(263),
    [sym_nil_lit] = ACTIONS(265),
    [sym__dec] = ACTIONS(265),
    [sym__hex] = ACTIONS(265),
    [sym__radix] = ACTIONS(265),
    [sym_str_lit] = ACTIONS(263),
    [sym_buf_lit] = ACTIONS(263),
    [sym_sym_lit] = ACTIONS(265),
    [anon_sym_AT_LPAREN] = ACTIONS(263),
    [anon_sym_RPAREN] = ACTIONS(263),
    [anon_sym_AT_LBRACK] = ACTIONS(263),
    [anon_sym_RBRACK] = ACTIONS(263),
    [anon_sym_LBRACE] = ACTIONS(263),
    [anon_sym_RBRACE] = ACTIONS(263),
    [anon_sym_AT_LBRACE] = ACTIONS(263),
    [anon_sym_LPAREN] = ACTIONS(263),
    [anon_sym_LBRACK] = ACTIONS(263),
    [anon_sym_TILDE] = ACTIONS(263),
    [anon_sym_SQUOTE] = ACTIONS(263),
    [anon_sym_PIPE] = ACTIONS(263),
    [anon_sym_SEMI] = ACTIONS(263),
    [anon_sym_COMMA] = ACTIONS(263),
    [sym_long_buf_lit] = ACTIONS(263),
    [sym_long_str_lit] = ACTIONS(263),
  },
  [44] = {
    [ts_builtin_sym_end] = ACTIONS(267),
    [sym__ws] = ACTIONS(267),
    [sym_comment] = ACTIONS(267),
    [anon_sym_BSLASH_POUND] = ACTIONS(267),
    [sym_bool_lit] = ACTIONS(269),
    [aux_sym_kwd_lit_token1] = ACTIONS(267),
    [sym_nil_lit] = ACTIONS(269),
    [sym__dec] = ACTIONS(269),
    [sym__hex] = ACTIONS(269),
    [sym__radix] = ACTIONS(269),
    [sym_str_lit] = ACTIONS(267),
    [sym_buf_lit] = ACTIONS(267),
    [sym_sym_lit] = ACTIONS(269),
    [anon_sym_AT_LPAREN] = ACTIONS(267),
    [anon_sym_RPAREN] = ACTIONS(267),
    [anon_sym_AT_LBRACK] = ACTIONS(267),
    [anon_sym_RBRACK] = ACTIONS(267),
    [anon_sym_LBRACE] = ACTIONS(267),
    [anon_sym_RBRACE] = ACTIONS(267),
    [anon_sym_AT_LBRACE] = ACTIONS(267),
    [anon_sym_LPAREN] = ACTIONS(267),
    [anon_sym_LBRACK] = ACTIONS(267),
    [anon_sym_TILDE] = ACTIONS(267),
    [anon_sym_SQUOTE] = ACTIONS(267),
    [anon_sym_PIPE] = ACTIONS(267),
    [anon_sym_SEMI] = ACTIONS(267),
    [anon_sym_COMMA] = ACTIONS(267),
    [sym_long_buf_lit] = ACTIONS(267),
    [sym_long_str_lit] = ACTIONS(267),
  },
  [45] = {
    [ts_builtin_sym_end] = ACTIONS(271),
    [sym__ws] = ACTIONS(271),
    [sym_comment] = ACTIONS(271),
    [anon_sym_BSLASH_POUND] = ACTIONS(271),
    [sym_bool_lit] = ACTIONS(273),
    [aux_sym_kwd_lit_token1] = ACTIONS(271),
    [sym_nil_lit] = ACTIONS(273),
    [sym__dec] = ACTIONS(273),
    [sym__hex] = ACTIONS(273),
    [sym__radix] = ACTIONS(273),
    [sym_str_lit] = ACTIONS(271),
    [sym_buf_lit] = ACTIONS(271),
    [sym_sym_lit] = ACTIONS(273),
    [anon_sym_AT_LPAREN] = ACTIONS(271),
    [anon_sym_RPAREN] = ACTIONS(271),
    [anon_sym_AT_LBRACK] = ACTIONS(271),
    [anon_sym_RBRACK] = ACTIONS(271),
    [anon_sym_LBRACE] = ACTIONS(271),
    [anon_sym_RBRACE] = ACTIONS(271),
    [anon_sym_AT_LBRACE] = ACTIONS(271),
    [anon_sym_LPAREN] = ACTIONS(271),
    [anon_sym_LBRACK] = ACTIONS(271),
    [anon_sym_TILDE] = ACTIONS(271),
    [anon_sym_SQUOTE] = ACTIONS(271),
    [anon_sym_PIPE] = ACTIONS(271),
    [anon_sym_SEMI] = ACTIONS(271),
    [anon_sym_COMMA] = ACTIONS(271),
    [sym_long_buf_lit] = ACTIONS(271),
    [sym_long_str_lit] = ACTIONS(271),
  },
  [46] = {
    [ts_builtin_sym_end] = ACTIONS(275),
    [sym__ws] = ACTIONS(275),
    [sym_comment] = ACTIONS(275),
    [anon_sym_BSLASH_POUND] = ACTIONS(275),
    [sym_bool_lit] = ACTIONS(277),
    [aux_sym_kwd_lit_token1] = ACTIONS(275),
    [sym_nil_lit] = ACTIONS(277),
    [sym__dec] = ACTIONS(277),
    [sym__hex] = ACTIONS(277),
    [sym__radix] = ACTIONS(277),
    [sym_str_lit] = ACTIONS(275),
    [sym_buf_lit] = ACTIONS(275),
    [sym_sym_lit] = ACTIONS(277),
    [anon_sym_AT_LPAREN] = ACTIONS(275),
    [anon_sym_RPAREN] = ACTIONS(275),
    [anon_sym_AT_LBRACK] = ACTIONS(275),
    [anon_sym_RBRACK] = ACTIONS(275),
    [anon_sym_LBRACE] = ACTIONS(275),
    [anon_sym_RBRACE] = ACTIONS(275),
    [anon_sym_AT_LBRACE] = ACTIONS(275),
    [anon_sym_LPAREN] = ACTIONS(275),
    [anon_sym_LBRACK] = ACTIONS(275),
    [anon_sym_TILDE] = ACTIONS(275),
    [anon_sym_SQUOTE] = ACTIONS(275),
    [anon_sym_PIPE] = ACTIONS(275),
    [anon_sym_SEMI] = ACTIONS(275),
    [anon_sym_COMMA] = ACTIONS(275),
    [sym_long_buf_lit] = ACTIONS(275),
    [sym_long_str_lit] = ACTIONS(275),
  },
  [47] = {
    [ts_builtin_sym_end] = ACTIONS(279),
    [sym__ws] = ACTIONS(279),
    [sym_comment] = ACTIONS(279),
    [anon_sym_BSLASH_POUND] = ACTIONS(279),
    [sym_bool_lit] = ACTIONS(281),
    [aux_sym_kwd_lit_token1] = ACTIONS(279),
    [sym_nil_lit] = ACTIONS(281),
    [sym__dec] = ACTIONS(281),
    [sym__hex] = ACTIONS(281),
    [sym__radix] = ACTIONS(281),
    [sym_str_lit] = ACTIONS(279),
    [sym_buf_lit] = ACTIONS(279),
    [sym_sym_lit] = ACTIONS(281),
    [anon_sym_AT_LPAREN] = ACTIONS(279),
    [anon_sym_RPAREN] = ACTIONS(279),
    [anon_sym_AT_LBRACK] = ACTIONS(279),
    [anon_sym_RBRACK] = ACTIONS(279),
    [anon_sym_LBRACE] = ACTIONS(279),
    [anon_sym_RBRACE] = ACTIONS(279),
    [anon_sym_AT_LBRACE] = ACTIONS(279),
    [anon_sym_LPAREN] = ACTIONS(279),
    [anon_sym_LBRACK] = ACTIONS(279),
    [anon_sym_TILDE] = ACTIONS(279),
    [anon_sym_SQUOTE] = ACTIONS(279),
    [anon_sym_PIPE] = ACTIONS(279),
    [anon_sym_SEMI] = ACTIONS(279),
    [anon_sym_COMMA] = ACTIONS(279),
    [sym_long_buf_lit] = ACTIONS(279),
    [sym_long_str_lit] = ACTIONS(279),
  },
  [48] = {
    [ts_builtin_sym_end] = ACTIONS(283),
    [sym__ws] = ACTIONS(283),
    [sym_comment] = ACTIONS(283),
    [anon_sym_BSLASH_POUND] = ACTIONS(283),
    [sym_bool_lit] = ACTIONS(285),
    [aux_sym_kwd_lit_token1] = ACTIONS(283),
    [sym_nil_lit] = ACTIONS(285),
    [sym__dec] = ACTIONS(285),
    [sym__hex] = ACTIONS(285),
    [sym__radix] = ACTIONS(285),
    [sym_str_lit] = ACTIONS(283),
    [sym_buf_lit] = ACTIONS(283),
    [sym_sym_lit] = ACTIONS(285),
    [anon_sym_AT_LPAREN] = ACTIONS(283),
    [anon_sym_RPAREN] = ACTIONS(283),
    [anon_sym_AT_LBRACK] = ACTIONS(283),
    [anon_sym_RBRACK] = ACTIONS(283),
    [anon_sym_LBRACE] = ACTIONS(283),
    [anon_sym_RBRACE] = ACTIONS(283),
    [anon_sym_AT_LBRACE] = ACTIONS(283),
    [anon_sym_LPAREN] = ACTIONS(283),
    [anon_sym_LBRACK] = ACTIONS(283),
    [anon_sym_TILDE] = ACTIONS(283),
    [anon_sym_SQUOTE] = ACTIONS(283),
    [anon_sym_PIPE] = ACTIONS(283),
    [anon_sym_SEMI] = ACTIONS(283),
    [anon_sym_COMMA] = ACTIONS(283),
    [sym_long_buf_lit] = ACTIONS(283),
    [sym_long_str_lit] = ACTIONS(283),
  },
  [49] = {
    [ts_builtin_sym_end] = ACTIONS(287),
    [sym__ws] = ACTIONS(287),
    [sym_comment] = ACTIONS(287),
    [anon_sym_BSLASH_POUND] = ACTIONS(287),
    [sym_bool_lit] = ACTIONS(289),
    [aux_sym_kwd_lit_token1] = ACTIONS(287),
    [sym_nil_lit] = ACTIONS(289),
    [sym__dec] = ACTIONS(289),
    [sym__hex] = ACTIONS(289),
    [sym__radix] = ACTIONS(289),
    [sym_str_lit] = ACTIONS(287),
    [sym_buf_lit] = ACTIONS(287),
    [sym_sym_lit] = ACTIONS(289),
    [anon_sym_AT_LPAREN] = ACTIONS(287),
    [anon_sym_RPAREN] = ACTIONS(287),
    [anon_sym_AT_LBRACK] = ACTIONS(287),
    [anon_sym_RBRACK] = ACTIONS(287),
    [anon_sym_LBRACE] = ACTIONS(287),
    [anon_sym_RBRACE] = ACTIONS(287),
    [anon_sym_AT_LBRACE] = ACTIONS(287),
    [anon_sym_LPAREN] = ACTIONS(287),
    [anon_sym_LBRACK] = ACTIONS(287),
    [anon_sym_TILDE] = ACTIONS(287),
    [anon_sym_SQUOTE] = ACTIONS(287),
    [anon_sym_PIPE] = ACTIONS(287),
    [anon_sym_SEMI] = ACTIONS(287),
    [anon_sym_COMMA] = ACTIONS(287),
    [sym_long_buf_lit] = ACTIONS(287),
    [sym_long_str_lit] = ACTIONS(287),
  },
  [50] = {
    [ts_builtin_sym_end] = ACTIONS(291),
    [sym__ws] = ACTIONS(291),
    [sym_comment] = ACTIONS(291),
    [anon_sym_BSLASH_POUND] = ACTIONS(291),
    [sym_bool_lit] = ACTIONS(293),
    [aux_sym_kwd_lit_token1] = ACTIONS(291),
    [sym_nil_lit] = ACTIONS(293),
    [sym__dec] = ACTIONS(293),
    [sym__hex] = ACTIONS(293),
    [sym__radix] = ACTIONS(293),
    [sym_str_lit] = ACTIONS(291),
    [sym_buf_lit] = ACTIONS(291),
    [sym_sym_lit] = ACTIONS(293),
    [anon_sym_AT_LPAREN] = ACTIONS(291),
    [anon_sym_RPAREN] = ACTIONS(291),
    [anon_sym_AT_LBRACK] = ACTIONS(291),
    [anon_sym_RBRACK] = ACTIONS(291),
    [anon_sym_LBRACE] = ACTIONS(291),
    [anon_sym_RBRACE] = ACTIONS(291),
    [anon_sym_AT_LBRACE] = ACTIONS(291),
    [anon_sym_LPAREN] = ACTIONS(291),
    [anon_sym_LBRACK] = ACTIONS(291),
    [anon_sym_TILDE] = ACTIONS(291),
    [anon_sym_SQUOTE] = ACTIONS(291),
    [anon_sym_PIPE] = ACTIONS(291),
    [anon_sym_SEMI] = ACTIONS(291),
    [anon_sym_COMMA] = ACTIONS(291),
    [sym_long_buf_lit] = ACTIONS(291),
    [sym_long_str_lit] = ACTIONS(291),
  },
  [51] = {
    [ts_builtin_sym_end] = ACTIONS(295),
    [sym__ws] = ACTIONS(295),
    [sym_comment] = ACTIONS(295),
    [anon_sym_BSLASH_POUND] = ACTIONS(295),
    [sym_bool_lit] = ACTIONS(297),
    [aux_sym_kwd_lit_token1] = ACTIONS(295),
    [sym_nil_lit] = ACTIONS(297),
    [sym__dec] = ACTIONS(297),
    [sym__hex] = ACTIONS(297),
    [sym__radix] = ACTIONS(297),
    [sym_str_lit] = ACTIONS(295),
    [sym_buf_lit] = ACTIONS(295),
    [sym_sym_lit] = ACTIONS(297),
    [anon_sym_AT_LPAREN] = ACTIONS(295),
    [anon_sym_RPAREN] = ACTIONS(295),
    [anon_sym_AT_LBRACK] = ACTIONS(295),
    [anon_sym_RBRACK] = ACTIONS(295),
    [anon_sym_LBRACE] = ACTIONS(295),
    [anon_sym_RBRACE] = ACTIONS(295),
    [anon_sym_AT_LBRACE] = ACTIONS(295),
    [anon_sym_LPAREN] = ACTIONS(295),
    [anon_sym_LBRACK] = ACTIONS(295),
    [anon_sym_TILDE] = ACTIONS(295),
    [anon_sym_SQUOTE] = ACTIONS(295),
    [anon_sym_PIPE] = ACTIONS(295),
    [anon_sym_SEMI] = ACTIONS(295),
    [anon_sym_COMMA] = ACTIONS(295),
    [sym_long_buf_lit] = ACTIONS(295),
    [sym_long_str_lit] = ACTIONS(295),
  },
  [52] = {
    [ts_builtin_sym_end] = ACTIONS(299),
    [sym__ws] = ACTIONS(299),
    [sym_comment] = ACTIONS(299),
    [anon_sym_BSLASH_POUND] = ACTIONS(299),
    [sym_bool_lit] = ACTIONS(301),
    [aux_sym_kwd_lit_token1] = ACTIONS(299),
    [sym_nil_lit] = ACTIONS(301),
    [sym__dec] = ACTIONS(301),
    [sym__hex] = ACTIONS(301),
    [sym__radix] = ACTIONS(301),
    [sym_str_lit] = ACTIONS(299),
    [sym_buf_lit] = ACTIONS(299),
    [sym_sym_lit] = ACTIONS(301),
    [anon_sym_AT_LPAREN] = ACTIONS(299),
    [anon_sym_RPAREN] = ACTIONS(299),
    [anon_sym_AT_LBRACK] = ACTIONS(299),
    [anon_sym_RBRACK] = ACTIONS(299),
    [anon_sym_LBRACE] = ACTIONS(299),
    [anon_sym_RBRACE] = ACTIONS(299),
    [anon_sym_AT_LBRACE] = ACTIONS(299),
    [anon_sym_LPAREN] = ACTIONS(299),
    [anon_sym_LBRACK] = ACTIONS(299),
    [anon_sym_TILDE] = ACTIONS(299),
    [anon_sym_SQUOTE] = ACTIONS(299),
    [anon_sym_PIPE] = ACTIONS(299),
    [anon_sym_SEMI] = ACTIONS(299),
    [anon_sym_COMMA] = ACTIONS(299),
    [sym_long_buf_lit] = ACTIONS(299),
    [sym_long_str_lit] = ACTIONS(299),
  },
  [53] = {
    [ts_builtin_sym_end] = ACTIONS(303),
    [sym__ws] = ACTIONS(303),
    [sym_comment] = ACTIONS(303),
    [anon_sym_BSLASH_POUND] = ACTIONS(303),
    [sym_bool_lit] = ACTIONS(305),
    [aux_sym_kwd_lit_token1] = ACTIONS(303),
    [sym_nil_lit] = ACTIONS(305),
    [sym__dec] = ACTIONS(305),
    [sym__hex] = ACTIONS(305),
    [sym__radix] = ACTIONS(305),
    [sym_str_lit] = ACTIONS(303),
    [sym_buf_lit] = ACTIONS(303),
    [sym_sym_lit] = ACTIONS(305),
    [anon_sym_AT_LPAREN] = ACTIONS(303),
    [anon_sym_RPAREN] = ACTIONS(303),
    [anon_sym_AT_LBRACK] = ACTIONS(303),
    [anon_sym_RBRACK] = ACTIONS(303),
    [anon_sym_LBRACE] = ACTIONS(303),
    [anon_sym_RBRACE] = ACTIONS(303),
    [anon_sym_AT_LBRACE] = ACTIONS(303),
    [anon_sym_LPAREN] = ACTIONS(303),
    [anon_sym_LBRACK] = ACTIONS(303),
    [anon_sym_TILDE] = ACTIONS(303),
    [anon_sym_SQUOTE] = ACTIONS(303),
    [anon_sym_PIPE] = ACTIONS(303),
    [anon_sym_SEMI] = ACTIONS(303),
    [anon_sym_COMMA] = ACTIONS(303),
    [sym_long_buf_lit] = ACTIONS(303),
    [sym_long_str_lit] = ACTIONS(303),
  },
  [54] = {
    [sym__gap] = STATE(54),
    [sym_dis_expr] = STATE(54),
    [aux_sym_dis_expr_repeat1] = STATE(54),
    [sym__ws] = ACTIONS(307),
    [sym_comment] = ACTIONS(307),
    [anon_sym_BSLASH_POUND] = ACTIONS(310),
    [sym_bool_lit] = ACTIONS(313),
    [aux_sym_kwd_lit_token1] = ACTIONS(315),
    [sym_nil_lit] = ACTIONS(313),
    [sym__dec] = ACTIONS(313),
    [sym__hex] = ACTIONS(313),
    [sym__radix] = ACTIONS(313),
    [sym_str_lit] = ACTIONS(315),
    [sym_buf_lit] = ACTIONS(315),
    [sym_sym_lit] = ACTIONS(313),
    [anon_sym_AT_LPAREN] = ACTIONS(315),
    [anon_sym_AT_LBRACK] = ACTIONS(315),
    [anon_sym_LBRACE] = ACTIONS(315),
    [anon_sym_AT_LBRACE] = ACTIONS(315),
    [anon_sym_LPAREN] = ACTIONS(315),
    [anon_sym_LBRACK] = ACTIONS(315),
    [anon_sym_TILDE] = ACTIONS(315),
    [anon_sym_SQUOTE] = ACTIONS(315),
    [anon_sym_PIPE] = ACTIONS(315),
    [anon_sym_SEMI] = ACTIONS(315),
    [anon_sym_COMMA] = ACTIONS(315),
    [sym_long_buf_lit] = ACTIONS(315),
    [sym_long_str_lit] = ACTIONS(315),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 1,
    ACTIONS(317), 1,
      ts_builtin_sym_end,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(55)] = 0,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source, 0),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(23),
  [9] = {.entry = {.count = 1, .reusable = false}}, SHIFT(15),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(42),
  [13] = {.entry = {.count = 1, .reusable = false}}, SHIFT(31),
  [15] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
  [17] = {.entry = {.count = 1, .reusable = true}}, SHIFT(7),
  [19] = {.entry = {.count = 1, .reusable = true}}, SHIFT(8),
  [21] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
  [23] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [25] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [27] = {.entry = {.count = 1, .reusable = true}}, SHIFT(17),
  [29] = {.entry = {.count = 1, .reusable = true}}, SHIFT(27),
  [31] = {.entry = {.count = 1, .reusable = true}}, SHIFT(25),
  [33] = {.entry = {.count = 1, .reusable = true}}, SHIFT(16),
  [35] = {.entry = {.count = 1, .reusable = true}}, SHIFT(26),
  [37] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_source_repeat1, 2),
  [39] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_repeat1, 2), SHIFT_REPEAT(2),
  [42] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_repeat1, 2), SHIFT_REPEAT(23),
  [45] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_repeat1, 2), SHIFT_REPEAT(2),
  [48] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_repeat1, 2), SHIFT_REPEAT(42),
  [51] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_repeat1, 2), SHIFT_REPEAT(31),
  [54] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_repeat1, 2), SHIFT_REPEAT(6),
  [57] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_repeat1, 2), SHIFT_REPEAT(7),
  [60] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_repeat1, 2), SHIFT_REPEAT(8),
  [63] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_repeat1, 2), SHIFT_REPEAT(9),
  [66] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_repeat1, 2), SHIFT_REPEAT(10),
  [69] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_repeat1, 2), SHIFT_REPEAT(11),
  [72] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_repeat1, 2), SHIFT_REPEAT(17),
  [75] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_repeat1, 2), SHIFT_REPEAT(27),
  [78] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_repeat1, 2), SHIFT_REPEAT(25),
  [81] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_repeat1, 2), SHIFT_REPEAT(16),
  [84] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_repeat1, 2), SHIFT_REPEAT(26),
  [87] = {.entry = {.count = 1, .reusable = true}}, SHIFT(2),
  [89] = {.entry = {.count = 1, .reusable = false}}, SHIFT(2),
  [91] = {.entry = {.count = 1, .reusable = true}}, SHIFT(45),
  [93] = {.entry = {.count = 1, .reusable = true}}, SHIFT(50),
  [95] = {.entry = {.count = 1, .reusable = true}}, SHIFT(49),
  [97] = {.entry = {.count = 1, .reusable = true}}, SHIFT(3),
  [99] = {.entry = {.count = 1, .reusable = false}}, SHIFT(3),
  [101] = {.entry = {.count = 1, .reusable = true}}, SHIFT(39),
  [103] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
  [105] = {.entry = {.count = 1, .reusable = false}}, SHIFT(14),
  [107] = {.entry = {.count = 1, .reusable = true}}, SHIFT(37),
  [109] = {.entry = {.count = 1, .reusable = true}}, SHIFT(13),
  [111] = {.entry = {.count = 1, .reusable = false}}, SHIFT(13),
  [113] = {.entry = {.count = 1, .reusable = true}}, SHIFT(35),
  [115] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
  [117] = {.entry = {.count = 1, .reusable = false}}, SHIFT(12),
  [119] = {.entry = {.count = 1, .reusable = true}}, SHIFT(28),
  [121] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [123] = {.entry = {.count = 1, .reusable = false}}, SHIFT(5),
  [125] = {.entry = {.count = 1, .reusable = true}}, SHIFT(41),
  [127] = {.entry = {.count = 1, .reusable = true}}, SHIFT(4),
  [129] = {.entry = {.count = 1, .reusable = false}}, SHIFT(4),
  [131] = {.entry = {.count = 1, .reusable = true}}, SHIFT(30),
  [133] = {.entry = {.count = 1, .reusable = true}}, SHIFT(48),
  [135] = {.entry = {.count = 1, .reusable = true}}, SHIFT(47),
  [137] = {.entry = {.count = 1, .reusable = true}}, SHIFT(46),
  [139] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source, 1),
  [141] = {.entry = {.count = 1, .reusable = true}}, SHIFT(19),
  [143] = {.entry = {.count = 1, .reusable = false}}, SHIFT(38),
  [145] = {.entry = {.count = 1, .reusable = true}}, SHIFT(38),
  [147] = {.entry = {.count = 1, .reusable = true}}, SHIFT(24),
  [149] = {.entry = {.count = 1, .reusable = false}}, SHIFT(32),
  [151] = {.entry = {.count = 1, .reusable = true}}, SHIFT(32),
  [153] = {.entry = {.count = 1, .reusable = true}}, SHIFT(54),
  [155] = {.entry = {.count = 1, .reusable = false}}, SHIFT(33),
  [157] = {.entry = {.count = 1, .reusable = true}}, SHIFT(33),
  [159] = {.entry = {.count = 1, .reusable = false}}, SHIFT(44),
  [161] = {.entry = {.count = 1, .reusable = true}}, SHIFT(44),
  [163] = {.entry = {.count = 1, .reusable = false}}, SHIFT(43),
  [165] = {.entry = {.count = 1, .reusable = true}}, SHIFT(43),
  [167] = {.entry = {.count = 1, .reusable = false}}, SHIFT(53),
  [169] = {.entry = {.count = 1, .reusable = true}}, SHIFT(53),
  [171] = {.entry = {.count = 1, .reusable = false}}, SHIFT(52),
  [173] = {.entry = {.count = 1, .reusable = true}}, SHIFT(52),
  [175] = {.entry = {.count = 1, .reusable = true}}, SHIFT(20),
  [177] = {.entry = {.count = 1, .reusable = false}}, SHIFT(29),
  [179] = {.entry = {.count = 1, .reusable = true}}, SHIFT(29),
  [181] = {.entry = {.count = 1, .reusable = false}}, SHIFT(51),
  [183] = {.entry = {.count = 1, .reusable = true}}, SHIFT(51),
  [185] = {.entry = {.count = 1, .reusable = true}}, SHIFT(21),
  [187] = {.entry = {.count = 1, .reusable = false}}, SHIFT(36),
  [189] = {.entry = {.count = 1, .reusable = true}}, SHIFT(36),
  [191] = {.entry = {.count = 1, .reusable = true}}, SHIFT(18),
  [193] = {.entry = {.count = 1, .reusable = false}}, SHIFT(40),
  [195] = {.entry = {.count = 1, .reusable = true}}, SHIFT(40),
  [197] = {.entry = {.count = 1, .reusable = true}}, SHIFT(22),
  [199] = {.entry = {.count = 1, .reusable = false}}, SHIFT(34),
  [201] = {.entry = {.count = 1, .reusable = true}}, SHIFT(34),
  [203] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_tbl_lit, 2),
  [205] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_tbl_lit, 2),
  [207] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dis_expr, 2),
  [209] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_dis_expr, 2),
  [211] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_sqr_tup_lit, 2),
  [213] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_sqr_tup_lit, 2),
  [215] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_num_lit, 1),
  [217] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_num_lit, 1),
  [219] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_qq_lit, 2),
  [221] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_qq_lit, 2),
  [223] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_unquote_lit, 3),
  [225] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_unquote_lit, 3),
  [227] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_quote_lit, 2),
  [229] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_quote_lit, 2),
  [231] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_struct_lit, 2),
  [233] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_struct_lit, 2),
  [235] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_short_fn_lit, 2),
  [237] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_short_fn_lit, 2),
  [239] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_sqr_arr_lit, 2),
  [241] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_sqr_arr_lit, 2),
  [243] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_splice_lit, 2),
  [245] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_splice_lit, 2),
  [247] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_par_arr_lit, 2),
  [249] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_par_arr_lit, 2),
  [251] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_unquote_lit, 2),
  [253] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_unquote_lit, 2),
  [255] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_par_tup_lit, 2),
  [257] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_par_tup_lit, 2),
  [259] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_kwd_lit, 1),
  [261] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_kwd_lit, 1),
  [263] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dis_expr, 3),
  [265] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_dis_expr, 3),
  [267] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_splice_lit, 3),
  [269] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_splice_lit, 3),
  [271] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_par_arr_lit, 3),
  [273] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_par_arr_lit, 3),
  [275] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_sqr_arr_lit, 3),
  [277] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_sqr_arr_lit, 3),
  [279] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_struct_lit, 3),
  [281] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_struct_lit, 3),
  [283] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_tbl_lit, 3),
  [285] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_tbl_lit, 3),
  [287] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_par_tup_lit, 3),
  [289] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_par_tup_lit, 3),
  [291] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_sqr_tup_lit, 3),
  [293] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_sqr_tup_lit, 3),
  [295] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_qq_lit, 3),
  [297] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_qq_lit, 3),
  [299] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_quote_lit, 3),
  [301] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_quote_lit, 3),
  [303] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_short_fn_lit, 3),
  [305] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_short_fn_lit, 3),
  [307] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_dis_expr_repeat1, 2), SHIFT_REPEAT(54),
  [310] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_dis_expr_repeat1, 2), SHIFT_REPEAT(23),
  [313] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_dis_expr_repeat1, 2),
  [315] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_dis_expr_repeat1, 2),
  [317] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
};

enum ts_external_scanner_symbol_identifiers {
  ts_external_token_long_buf_lit = 0,
  ts_external_token_long_str_lit = 1,
};

static const TSSymbol ts_external_scanner_symbol_map[EXTERNAL_TOKEN_COUNT] = {
  [ts_external_token_long_buf_lit] = sym_long_buf_lit,
  [ts_external_token_long_str_lit] = sym_long_str_lit,
};

static const bool ts_external_scanner_states[2][EXTERNAL_TOKEN_COUNT] = {
  [1] = {
    [ts_external_token_long_buf_lit] = true,
    [ts_external_token_long_str_lit] = true,
  },
};

#ifdef __cplusplus
extern "C" {
#endif
void *tree_sitter_janet_simple_external_scanner_create(void);
void tree_sitter_janet_simple_external_scanner_destroy(void *);
bool tree_sitter_janet_simple_external_scanner_scan(void *, TSLexer *, const bool *);
unsigned tree_sitter_janet_simple_external_scanner_serialize(void *, char *);
void tree_sitter_janet_simple_external_scanner_deserialize(void *, const char *, unsigned);

#ifdef _WIN32
#define extern __declspec(dllexport)
#endif

extern const TSLanguage *tree_sitter_janet_simple(void) {
  static const TSLanguage language = {
    .version = LANGUAGE_VERSION,
    .symbol_count = SYMBOL_COUNT,
    .alias_count = ALIAS_COUNT,
    .token_count = TOKEN_COUNT,
    .external_token_count = EXTERNAL_TOKEN_COUNT,
    .state_count = STATE_COUNT,
    .large_state_count = LARGE_STATE_COUNT,
    .production_id_count = PRODUCTION_ID_COUNT,
    .field_count = FIELD_COUNT,
    .max_alias_sequence_length = MAX_ALIAS_SEQUENCE_LENGTH,
    .parse_table = &ts_parse_table[0][0],
    .small_parse_table = ts_small_parse_table,
    .small_parse_table_map = ts_small_parse_table_map,
    .parse_actions = ts_parse_actions,
    .symbol_names = ts_symbol_names,
    .symbol_metadata = ts_symbol_metadata,
    .public_symbol_map = ts_symbol_map,
    .alias_map = ts_non_terminal_alias_map,
    .alias_sequences = &ts_alias_sequences[0][0],
    .lex_modes = ts_lex_modes,
    .lex_fn = ts_lex,
    .external_scanner = {
      &ts_external_scanner_states[0][0],
      ts_external_scanner_symbol_map,
      tree_sitter_janet_simple_external_scanner_create,
      tree_sitter_janet_simple_external_scanner_destroy,
      tree_sitter_janet_simple_external_scanner_scan,
      tree_sitter_janet_simple_external_scanner_serialize,
      tree_sitter_janet_simple_external_scanner_deserialize,
    },
  };
  return &language;
}
#ifdef __cplusplus
}
#endif
