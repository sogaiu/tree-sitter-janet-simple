# tree-sitter-janet-simple

A [Janet](https://janet-lang.org) grammar for tree-sitter.

## Status

Usable, but as tree-sitter is pre-1.0, don't forget the salt.

Coincidentally, it appears [another effort by
GrayJack](https://github.com/GrayJack/tree-sitter-janet/) was started
at about the same time.

The main difference between these two are that GrayJack's grammar
supports higher level constructs (e.g. `def` is recognized by the
grammar) at the cost of accuracy.

There might end up being different trade-offs in either approach and
my belief is that there is room in the world for multiple attempts
(especially for lisp-like languages).

## Content

This repository currently provides "source" files such as:

* `grammar.jdn` - can be used to generate a `grammar.js` and/or
  `grammar.json` if one uses
  [janet-ts-dsl](https://github.com/sogaiu/janet-ts-dsl)
* `grammar.js` - can be used to generate `parser.c` using the
  `tree-sitter` `generate` subcommand, but `node` is then required
* `package.json` - without this file, the `tree-sitter` cli's
  capabilities will be impacted.

Also, things that are provided (which are actually generated) but
might disappear at some point:

* `src/parser.c` and friends [1] - other projects have come to expect
  these to be committed to a grammar repository, but [there are forces
  in the world wanting to remove
  them](https://github.com/sogaiu/ts-questions/blob/master/questions/should-parser-source-be-committed/README.md),
  so depending on how things go, these may disappear.
* Rust bindings - tempted to remove these as I did with the Node.js
  bindings (see below) but Rust bindings seem to be looked after a bit
  better and there is much more evidence that tree-sitter grammar /
  parser code is being used in Rust programs.

Used to provide but no longer do:

* Node.js bindings - it seems there isn't much love and care going to
  node-tree-sitter upstream and I don't use or test these.  I felt it
  was a bit misleading to be providing them so I removed them.  They
  can be regenerated using an appropriate invocation of `tree-sitter
  generate` though.

---

[1] Currently these files are generated to have ABI 13.

---

## Credits

* 314eter - handling null characters
* Aerijo - Guide to your first Tree-sitter grammar
* ahelwer - tree-sitter discussions
* ahlinc - tree-sitter work and discussions
* andrewchambers - janet-uri
* bakpakin - janet
* dannyfreeman - tree-sitter-clojure discussions, investigations, and
  work
* GrayJack - tree-sitter-janet
* maxbrunsfeld - tree-sitter and related
* NoahTheDuke - tree-sitter-clojure discussions and investigations
* pyrmont - various discussions

