IWannaFly (working title)
=========================

***Pre-Pre-Alpha version...idek***

A Nearly Realtime RPG Engine written in C, C++, and Angelscript
---------------------------------------------------------------
***(And possibly Objective-C and Objective-C++)***

At this point, I've learned a bunch of stuff on both the programming and
metaprogramming\* level, and I think I have a pretty good idea of how to
move forward. This project was started primarily as a self-study
opportunity, and it's been a fun journey.

I have now settled on a language, an overall structure, some libraries,
and a ui/gameplay style. from here, I do not forsee any further false
starts and hope to have smooth(ish) sailing through to a working alpha!

The game engine uses the
[Irrlicht Engine](http://irrlicht.sourceforge.net/) for rendering 3d
graphics, [Cairo Graphics](https://www.cairographics.org/) for rendering
pictures, [NCurses](https://invisible-island.net/ncurses/) for
rendering dialog and menus, and
[AngelScript](https://www.angelcode.com/angelscript/) for general pourpose
scripting and debugging. to save space, the engine uses the half-precision
floating point implementation at http://half.sourceforge.net/

~~despite using C++, the majority of the project should be in C...~~ The
design goal of having a C API has been scrapped, in favor of using the
[AngelScript](https://www.angelcode.com/angelscript/) language. the
advantage to this is that Angelscript is JIT compiled (thus eliminating
pointer persistance problems) and has the crucial ability to directy access
and alter C data, which many of the scripting languages I considered
lacked.

C code will use notation in variable names to seperate namespaces, using
`$$` in place of `::` *(this requires that a compiler support the extension
detailed in ISO 9899 Annex J.5.2)*

2 example games will be provided: a high fantasy game with a wide cast of
playable characters, and a cyberpunk game with a single customizable
character. when reporting bugs, please note if the bug concerns the engine,
or one of the games, and which part of the engine or game.

since `this` is a reserved word in C++, and `self` is a reserved word in
Objective-C, when using Object Style C, the object variable will be named
`adhoc`; the variable will be named `here` for lowlevel functions using an
opaque pointer to operate on contiguous memory.
similarly, since `new` is a keyword in C++ with a compleatly different
meaning, an object that is being constructed by a function will be named
`nova`. `input` may be employed as the primary, or only, argument of a
function. `output` will be the return value. `acc` is an **acc**umulator,
and should be a register variable.

variables with generic names follow the following conventions:
- `x`, `y`, `z`, and `w` refer to coordinates
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
is revived for the pourpose of manually mangling C functions that can take
multiple argument types, as this allows such functions to maintain C
linkage while also having faux overloads. this is similar to functions in
the C standard library such as `abs()` and `fabs()`.

files ending in .ro4 contain severe spoilers, and have been ciphered by
applying a [Circular Shift](https://en.wikipedia.org/wiki/Circular_shift)
of 4 to every byte of the file (the result is the same in either direction
like in a rot13 cipher); the program I use is provided in `nybbleswap.c`,
which is designed to be used in a shell pipeline.\
to cipher a file:\
`cat plaintext.txt | nybbleswap > ciptertext.ro4`\
to uncipher a file:\
`cat ciphertext.ro4 | nybbleswap > plaintext.txt`\
to view a file:\
`cat ciphertext.ro4 | nybbleswap`\
to edit a file:\
`cat ciphertext.ro4 | nybbleswap | vim -`

The code will be liscensed under the terms of the GPL, version 2.0 or, at
your option, any later version; unless the usage kernel calls makes it
impossible on systems using the linux kernel (it *really* shouldn't). some
general pourpose code libraries which are modularly independant of the game
engine may be offered under more permissive liscenses, or under a public
domain release, when not used as part of the whole; these parts will have
their liscense noted seperately. at present, liscensing information may be
absent due to the early stage and bumpy progress of the program's
development; this will be remedied no later than when the program is in a
state such that it can be compiled, however the non-working prealpha code
can be provided with an appropriate liscense upon request.

---

\**note: as I've been learning, one of the things I've been teaching myself
has also been the git system; as a result, instead of branching the repo
at two specific "flag day" points of development, I -forked- it instead.
Mistakes were made. If you want to see these relics (you really don't),
I will leave them as-is.*
