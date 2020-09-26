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
graphics, the [Open Dynamics Engine](http://www.ode.org/) for physics,
[Cairo Graphics](https://www.cairographics.org/) for 2d graphics,
[NCurses](https://invisible-island.net/ncurses/) for interactive menus,
`<stdio.h>` for story dialog, and [lua](https://www.lua.org/) for scripting
and a command line.\
  *additional dependancies will follow...*

use of an [external debugger](https://www.gnu.org/software/gdb/) is
recommended if **Bad Things** start happening.

C code will use notation in variable names to seperate namespaces, using
`$$` in place of `::` *(this requires that a compiler support the
extension detailed in ISO 9899 Annex J.5.2)*

2 example games will be provided: a high fantasy game with a wide cast of
playable characters and fixed story, and a cyberpunk game with a single
custom character and dynamic story.

one of the primary features of the game is that it involves full 3D
navigation, through the inclusion of characters have free flight or
underwater breathing capabilities.

another feature is that chunks _do not have to be_ connected in a way that
forms a flat manifold, which when combined with the above, can form
interesting and mind-bending mazes, similar to the ones found in
[early text adventure games](https://en.wikipedia.org/wiki/Colossal_Cave_Adventure).

when reporting bugs, please note if the bug concerns the engine, or one
of the games, and which part of the engine or game; additionally, if the
bug concerns a freshly loaded state, try *turning it off and on again*.

BUILDING
========

compilable code lives in `/src/working/*`. to compile, cd there and run
the `build.sh` script. please report any bugs that occur:

- if the problem is during compilation, include your toolchain's name,
  version, naitive architecture, and target architecture, as well as
  command-line flags and steps you have taken to fix the bug.

- if the problem is in the linking stage, please include the above as
  well as the versions of the libraries you are linking to, your opengl
  and glsl versions, and your system os/kernel/distribution.

- if the program has an error while running, include all of the above,
  the terminal programs, the invocation, and any error output. also
  include the state of both terminals (screenshots, what happens if you
  type on them, etc) and if the savefile is corrupted.

- if you found a bug and were able to fix it yourself, please report it
  anyway. please include what you did to fix it!

CODING STYLE
============

occasionally, a type of C coding called "Object Style C" will be used,
which takes the following form: 
`namespace$$pseudo_class$$method(pseudo_object,arg,arg,arg...)` 
The order of the method call and the object are just reversed.

functions that in fortran would be called "subroutines" are also used,
and will be denoted by returning an implicit int or the SYSINT macro
(which evaluates to the empty string *(implicit int)* in C and to `int`
in C++)

the types in `<stdint.h>` (or `<cstdint>`) should be used when an integer
of a specific width is required, with the exception that `char` should be
prefferred to `int8_t`, and `unsigned char` should be prefferred to
`uint8_t`. if an interger bitfield uses less than the full number of
bytes in an int, then it should be signed; otherwise it should (*usually*)
be unsigned.

`struct`s should be catagorized into bitpacked structs and loosly-packed
structs. every field of a bitpacked struct should have an explicit width,
and should be of type `signed`, `unsigned`, or `bool`. a loosly-packed
struct should never use explicit-width fields; a bitpacked struct should
never contain a type with implementation defined width (i.e. pointers). all
bitpacked structs should be replaced with intergals and manual packing
functions before beta.

single-pourpose classes for storing global state should be avoided in
favor of namespaces. these namespaces will be called "daemons" (cf. system
daemon) if they contain functions.

`goto` may be used in place of `break` when the latter looks ambiguous.

since `this` is a reserved word in C++, and `self` is a reserved word in
Objective-C, when using Object-Style-C, the object variable will be named
`opaque` for `void *` pointers to C++ objects, or `object` for pointers
whose type is known; the variable will be named `here` for lowlevel
functions using an opaque pointer to operate on contiguous memory.
similarly, since `new` is a keyword in C++ with a compleatly different
meaning, an object that is being constructed by a function will be named
`nova`. `input` may be employed as the primary, or only, argument of a
function. `output` will be the return value. `acc` is an **acc**umulator,
and should always (and only) be a register variable.

variables with generic names follow the following conventions:
- `x`, `y`, `z`, and `w` refer to coordinates. `w` isn't used often.
- `i` and `j` are `for`-loop iterators, either a C++ `::iterator` or an
  intergal counter
- `n` and `m` are generic numbers, usually `for`-loop intergal counters
- `tmp` is a temporary variable, usually holding an intermidiate value or
  a local copy of a shared resource.
- `T` is a type in a template
- `L` is a lua engine
- `data` is the main data member of an object

some library functions use a naming system similar to the standard library
to denote the type of argument that they take (c.f. `man abs`, `man fabs`,
[Systems Hungarian](https://en.wikipedia.org/wiki/Hungarian_notation)). the
libraries that do this are written in C, and do not use operator
overloading.

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

at various points in development, I have tried using the following
libraries, but have moved away for them:

- Guile
- Raylib
- Perl
- OpenGL/GLX
- Python
- tcl
- s7 scheme
- TinyScheme
- Chaiscript
- SQLite

earlier branches of the source tree may include broken code that uses
these libraries. the reasons for changing are varied, and variously include
the APIs being too low level, not lowlevel enough, too big, inadequate
documentation, and license propagation conflict (specifically, using some
libraries listed here would have resulted in a malformed combination of
incompatible licenses).

LICENSE
=======

The project, as a complete entity, is licensed under the terms of the GNU
General Public License, Version 2.0, or at your option, any later version.

I reserve the right to republish some libraries which I consider to be
modularly independant of the project, but which are being published for the
first time as part of the project, at a later date under a less restrictive
liscense.

Additionally, there are some files in the project that are offered under
the terms of the license that applies to the toutorials that I used to
create their initial contents.

*note: I originally intended to liscense the project under the GPLv3, and
some parts of the source code archive have comments to this intent; I have
since chosen to commit to the GPLv2 "or later" because of various potential
complications regarding liscense propagation and the linux kernel.*

***this is not legal advice, and I am not a lawyer. I am a programmer with
signifigant disdain for legal trolls suppressing the advancement of
knowladge, and I personally believe this liscense to be the best way of
preventing such from happening in my relm of works.***

(even minimalizing the number of dependancies as I have, the license
propogation portion of my project has been extreamly time-consuming and
stressful)
