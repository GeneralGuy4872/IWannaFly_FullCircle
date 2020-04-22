- `(foo} bar)` is `((foo) bar)`
- `(foo {bar)` is `(foo (bar))`
- `«T»` denotes a type template
---
- `.` creates a key-value pair
   -they can be used to create alists
- single token `}{` denotes a tree root. only 1 may appear in a group of `(`...`)`
  - any combination resulting in `{`...`}` without a tree root present in the same `(`...`)` is ambiguous and not allowed
    - to the left of tree root, `{` is closed by `}` but `}` is closed by `(`
    - to the right of tree root, `}` is closed by `{` but `{` is closed by `)`
---
- single token `)(` is the same as `) (`
  - except that the `(` has the same quotation as whatever `)` closes
---
- postfix `^` is Pascal's deref
- prefix `*` is C's deref
- prefix `&` is address of, but has lowest precedance
- prefix `$` is pass-by-reference
---
- prefix <CODE>`</CODE> is quote one level
- prefix `'` is quote recursively
- m4 quotes are `‘foo’`
- metavariables are `<foo>`
- `#include` directives may be used
---
- `¶foo` is a goto label
---
- `[`...`]` is bytewise address arithmatic (without deref)
- `%[`...`]` is bitwise address arithmatic (without deref)
- `foo.bar` is a record or object member
- `foo.;bar` is an object method
  -not used for C++
---
*next paragraph is not used for C++*
- tables and classes are namespaces
- namespaces are like directories
- `:foo` is in the current namespace
- `::foo` is in the master namespace
- `:foo;bar` is a namespace tree path
---
- postfix `foo=n` is set result into nth field.
  - default `foo=` is 0th (car)
- prefix `?` is logic identity
- prefix `!` is logic negation
- prefix `~` is bitwise negation
- prefix `@` is octal literal
- prefix `%` is binary literal
- prefix `0x` is hex literal
---
- `define` defines a pointer. implicit is void*
- `defvar` defines a variable. implicit is int
- `class` defines a class type
- `struct` defines a bitpacked struct
- `record` defines a record
- `defun` defines a function. implicit is int
- `defsub` defines a function returning void
- templates and blackboxes use metavariables.
---
bitwise ops are written in lowercase

LOGICAL OPS ARE WRITTEN IN CAPS

icon-style comparisons use 2-letter lowercase abbriviations

TRADITIONAL COMPARISONS USE 2-LETTER CAPS ABBRIVIATIONS

unsigned is assumed unless otherwise specifyed. ± specifys signed bitfields.

`(atan2 y x)` syntax is used, other syntax may change

C style comments

rules listed here incompatible with the target language can be ignored
---
```
(define name name name)
(defvar (name name name))
(defvar «T» (name name name))
(defsub (name . args) {...)
(defun (name . args) {...)
(defun «T» (name . args) {...)
(defun «Template» (name . args) {...)
(struct «allocT» name {
	(name . bitsize)
	(name . bitsize))
(record name {
	(name . «T»)
	(name . «T»))
(class name {
	(defvar...)
	(defun...)
	(defsub...)
	)
```
