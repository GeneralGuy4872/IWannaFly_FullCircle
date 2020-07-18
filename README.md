IWannaFly (working title)
=========================

***Pre-Pre-Alpha version...idek***

A Nearly Realtime RPG Engine written in C, C++, and lua
-------------------------------------------------------

At this point, I've learned a bunch of stuff on both the programming and
metaprogramming\* level, and I think I have a pretty good idea of how to
move forward. This project was started primarily as a self-study
opportunity, and it's been a fun journey.


I have now settled on a language, an overall structure, and some
libraries. from here, I do not forsee any further false starts and hope
to have smooth(ish) sailing through to a working alpha!

The game engine uses the
[Irrlicht Engine](http://irrlicht.sourceforge.net/) for rendering 3d
graphics, [Cairo Graphics](https://www.cairographics.org/) for rendering
pictures, [NCurses](https://invisible-island.net/ncurses/) for rendering
in-game dialog, and [lua](http://www.lua.org/) for both extensions and a
command line\
  *additional dependancies will follow...*

use of an [external debugger](https://www.gnu.org/software/gdb/) is
recommended if **Bad Things** start happening.

C code will use notation in variable names to seperate namespaces, using
`$$` in place of `::` *(this requires that a compiler support the
extension detailed in ISO 9899 Annex J.5.2)*

2 example games will be provided: a high fantasy game with a wide cast of
playable characters, and a cyberpunk game with a single customizable
character. chunks can be connected in such a way to form wormholes that
are one-way or bidirectional.

when reporting bugs, please note if the bug concerns the engine, or one
of the games, and which part of the engine or game; additionally, if the
bug concerns a freshly loaded state, try *turning it off and on again*.

BUILDING
========

at the moment, compilable code lives in `/src/working/*`. to compile, run
the `build.sh` script from the same directory. please report any bugs that
occur:
- if the problem is during compilation, include your toolchain's name,
  version, naitive architecture, and target architecture, as well as
  command-line flags and steps you have taken to fix the bug.
- if the problem is in the linking stage, please include the above as well
  as the versions of the libraries you are linking to, your opengl and glsl
  versions, and your system os/kernel/distribution.
- if the program has an error while running, include all of the above and
  any error output. also include the state of the second terminal (i.e. can
  you type on it? is the cursor in the correct place? is the text the
  correct color?)

if you found a bug and were able to fix it yourself, please report it
anyway.

CODING STYLE
============

occasionally, a type of C coding called "Object Style C" will be used,
which takes the following form:
`namespace$$pseudo_class$$method(pseudo_object,arg,arg,arg...)`

functions that in fortran would be called "subroutines" are also used,
and will be denoted by returning an implicit int or the SYSINT macro
(which evaluates to the empty string *(implicit int)* in C and to `int`
in C++)

the types in `<stdint.h>` (or <cstdint>) should be used when an integer
of a specific width is required, with the exception that `char` should be
prefferred to `int8_t`, and `unsigned char` should be prefferred to
`uint8_t`. if an interger bitfield uses less than the full number of
bytes in an int, then it should be signed; otherwise it should
(*usually*) be unsigned.

`struct`s should be catagorized into bitpacked structs and loosly-packed
structs. every field of a bitpacked struct should have an explicit width,
and should be of type `signed`, `unsigned`, or `bool`. a loosly-packed
struct should never use explicit-width fields. bitpacked structs should
eventually be replaced with interger bitfields.

since `this` is a reserved word in C++, and `self` is a reserved word in
Objective-C, when using Object-Style-C, the object variable will be named
`opaque` for `void *` pointers to C++ objects, or `object` for pointers
whose type is known; the variable will be named `here` for lowlevel
functions using an opaque pointer to operate on contiguous memory.
similarly, since `new` is a keyword in C++ with a compleatly different
meaning, an object that is being constructed by a function will be named
`nova`. `input` may be employed as the primary, or only, argument of a
function. `output` will be the return value. `acc` is an **acc**umulator,
and should be a register variable.

variables with generic names follow the following conventions:
- `x`, `y`, `z`, and `w` refer to coordinates. `w` isn't used often.
- `i` and `j` are `for`-loop iterators, either in the sense of  C++
  `::iterator`s or in the sense of intergal counters
- `n` and `m` are generic numbers, usually for-loop intergal counters
- `tmp` is a temporary variable, usually holding an intermidiate value.
- `T` is a type in a template
- `L` is a length (ℓ); it breaks from the usual capitalization rules
  because of the `1`/`l`/`I` rule
- `data` is the main data member of an object

a naming system similar to
[Systems Hungarian](https://en.wikipedia.org/wiki/Hungarian_notation)
is revived for the pourpose of manually mangling C functions that can
take multiple argument types, as this allows such functions to maintain C
linkage while also having faux overloads. this is similar to functions in
the C standard library such as `abs()` and `fabs()`.

FILENAMES
=========
files should use the following extensions:
- C preprocessor files
  - `*.def` : C preprocessor macros
- C files
  - `*.c` : C code
  - `*.h` : C header
  - `*.inl` : inline functions
- C++ files
  - `*.cc` : C++ code
  - `*.hh` : C++ header
  - `*.tmpl` : C++ template
- C or C++ files
  - `*.H` : C or C++ header
  - `*.inc` : transclusion, for editing conveniance
- data files
  - `*.txt` : raw utf-8 text
  - `*.strings` : nul-terminated utf-8 strings, formatted with CGI codes
    (don't open in an editor that cannot handle C0 control characters)
  - `*.ro4` : ciphertext (see below)
  - `*.lua` : a lua script

files ending in .ro4 contain severe spoilers, and have been ciphered by
applying a [Circular Shift](https://en.wikipedia.org/wiki/Circular_shift)
of 4 to every byte of the file (the result is the same in either
direction like in a rot13 cipher); the program I use is provided in
`nybbleswap.c`, which is designed to be used in a shell pipeline.\
to cipher a file:
`cat plaintext.txt | nybbleswap > ciptertext.ro4`\
to uncipher a file:
`cat ciphertext.ro4 | nybbleswap > plaintext.txt`\
to view a file:
`cat ciphertext.ro4 | nybbleswap`\
to edit a file:
`cat ciphertext.ro4 | nybbleswap | vim -`

---

*at various points in development, I have entertained using the following
libraries, but have since decided to go with a different design:
- Guile
- Perl
- Raylib
- GLX
- Angelscript
- s7 scheme
- Chaiscript
earlier branches of the source tree may include broken code that uses
these libraries.*

---

The project, as a complete entity, is licensed under the terms of the GNU
General Public License, Version 2.0, or at your option, any later version.

I reserve the right to republish some libraries which I consider to be
modularly independant of the project, but which are being published for the
first time as part of the project, at a later date under a less restrictive
liscense.

*note: I originally intended to liscense the project under the GPLv3, and
some parts of the source code archive have comments to this intent; I have
since chosen to commit to the GPLv2 "or later" because of various potential
complications regarding liscense propagation and the linux kernel.*

***this is not legal advice, and I am not a lawyer. I am a programmer with
signifigant disdain for legal trolls suppressing the advancement of
knowladge, and I personally believe this liscense to be the best way of
preventing such from happening in my relm of works.***

---

\**note: as I've been learning, one of the things I've been teaching myself
has also been the git system; as a result, instead of branching the repo
at two specific "flag day" points of development, I *forked* it instead.
Mistakes were made. If you want to see these relics (you really don't),
I will leave them as-is.*
