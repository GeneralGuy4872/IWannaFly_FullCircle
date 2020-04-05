PSEUDOCODE LANGUAGE EXPLINATION
===============================

The most abstrsct level of pseudocode in this project will heretoforth use
a custom pseudolanguage of a very rough specification, that falls better
inline with the novel programming paradigm(s) used, and with my thought
processes upon whict they are based. the rational that forms the notation
will follow; any interpretation of this rational shall be considered valid,
so long as it assists a programmer in formulating code.

- functions are called as in C, but prefaced with `
- C style declarations of types and structs are used
- associative arrays are noted as in Perl
- Perl associative array notation is used for C structs
- C structs may be bitwise operated and ==ed
 (I have kludgy ways of doing this in C)
- moving between namespaces and stack frames is thought of as equivilant
  to moving between directories, and is specifyed by SGML notation
- assignment uses Perl syntax with Algol/Pascal operators
- in other areas, conventions and syntax is inherited from the lisp family
- blackboxes may be employed frequently as a means of facilitating
 breadth-first outlining of code, rather than blindly writing it depth
 first

this pidgon may eventually be turned into an extention language, but for
now is mearly a stepping stone between natural language and C-like
pseudocode.

