NOTES
=====

kanban filing system
--------------------
- files in the `//src/stable` directory are finished; they can be used with relative safety as-is
- files in the `//src/unstable` directory are finished but may be subject to change due to depending on unfinished work
- files in the `//src/broken` directory have become broken due to changes to their dependancies.
- files in the `//src/reference` directory are kept because they may be needed later; they will not be used in the finished program
- files in the `//src/deprecated` directory have been superceded by other files
- files in the `//src/ongoing` directory are being updated as more stuff is finished
- files in the `//src/incomplete/mothballed` subdirectory have been abandoned in favor of other ideas; they may be revisited later
- files in the `//src/incomplete/sandbox` subdirectory are currently being worked on
- files in the `//src/incomplete/launchpad` subdirectory are almost finished

---

above is depracated and will be changed now that a working main exists.

---

editorial marks
---------------
none of these will remain once the code is ready to compile
- `※include` is an `#include` line that refers to a file that has been or may be moved
- `«`...`»` contains pseudocode
- `⟦`...`⟧` block of pseudocode
- `⸘`...`‽` dubious
- `...` block of code that needs to be written. usually, this is expressed in a comment.

---

formatting marks
================

markup
------
- `// ---` or `// <HR>` imagine a horizontal rule here
- *‹random comment mentioning dragons in ALL CAPS and ye fake olde english›*
  the following code is complex, kludgey, or harmful to the eyes.
- `/***TITLE***/` imagine header text here

odd conventions
---------------
(besides those listed in the project's main README)
- `/*C++ type*/ void *`
  - in C: an opaque pointer to a C++ object
  - in C++: a dangerous typo (please send a bug report)
- `!!xyzzy` extract the logical value of xyzzy
  - invalid if the ajacent function does this automatically (`&&`/`||`), if
    used as the only function in a predicate, when applied to a `bool`, if
    `util.def` was `#include`d (replace all instances of `!!` with the
    `istrue()` macro), or if `!` was ment instead.
- `{bool again = 1;while(again) { again = 0;` a brute-force loop
- 

special comment blocks
----------------------

<PRE>/**************
 * Project    *
 * Titlecard  *
 **************/</PRE>

<PRE>/** doxygen
 * this style of comment,
 * with 2 astrikses at the
 * top, is used by doxygen
 * to generate documentation
 */</PRE>

`//! small doxygen notation`

---

misc.
=====

most files are created, formatted, and edited on a 80 column XTerm in vim;
complex files frequently using fully-quantified object names may use a 132
column XTerm instead.

---

the problem of 32/64 bit architecture portability is circumvented by using
`<stdint.h>` instead of `int`, `short`, and `long`.

---

all finished headers use the `#ifndef`/`#define` method of preventing
double-inclusion.

a "smart header" is an experiment I'm trying based on how perl modules
work. they use a preceeding `#define` to know what to import; it's like
several small headers in one file. these `#define`s are like arguments for
the header, and mostly use the prefix `IMPORT___`*‹stuff›*.

---

almost all C++ files will require the type safety to be turned off to be
compiled; this may or may not eventually be fixed, but is considered a low
priority annoyance. it is for primarily this reason that some files are
marked as C-only.

---

several features require that structs specifying sub-byte fields are
"tightly packed" and truncated to the smallest possible **-multiple- of 8
bits** (not mearly power of 2) that can contain the data. a kludgy
work-around may be provided in future as an alternative to structs, but it
requires that an `unsigned char` is 8 bits wide, and that address
arithmatic on `unsigned char *` is bytewise and not word-wise.

---

ENIGNE DESIGN
=============

the engine is NOT turn based; instead, it is based on a chaiscript event
pump. every entity has it's own thread that creates events, and the
chaiscript engine has full access to the C/C++ api underneath, thus having
the ability to create or destroy threads. most api calls are also
threadsafe, and can be invoked directly.

all threads also have direct read-only access to a filesystem-like database
of internal atomic-access data, which can be modified through C api calls
with or without the chaiscript interface. 
