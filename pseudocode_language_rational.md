PSEUDOCODE LANGUAGE EXPLINATION
===============================

The most abstrsct level of pseudocode in this project will heretoforth use
a custom pseudolanguage of a very rough specification, that falls better
inline with the novel programming paradigm(s) used, and with my thought
processes upon whict they are based. the rational that forms the notation
will follow; any interpretation of this rational shall be considered valid,
so long as it assists a programmer in formulating code.
it is based on lisp, but has different syntax for many operators.

- the NIL variable is ∅
- (foo ¶ bar) is equivilant to (foo(bar)) and is the opposite of .
- both associative arrays and C structs use ⇒ instead of .
	- C structs are additionally enclosed with {}
- moving between namespaces and stack frames is thought of as equivilant
 to moving between directories, and is specifyed by SGML notation.
 the malformatted tag "...>" is used to indicate that the block does not
 begin at the start of a scope.
- move is used to indicate variable copying, set and setq are used to
 indicate the assignment of a literal to a variable
- blackboxes noted by «» may be employed frequently as a means of
 facilitating breadth-first outlining of code, rather than blindly writing
 it depth-first

this pidgon may eventually be turned into an extention language, but for
now is mearly a stepping stone between natural language and C-like
pseudocode.

