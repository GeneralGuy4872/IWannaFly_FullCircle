IWannaFly (working title)
=========================

***Pre-Alpha version...idek***

A Nearly Realtime RPG Engine written in C, C++, and lua
-------------------------------------------------------

The game engine uses the
[Irrlicht Engine](http://irrlicht.sourceforge.net/) for rendering 3d
graphics, [Cairo Graphics](https://www.cairographics.org/) for rendering
pictures, [NCurses](https://invisible-island.net/ncurses/) for rendering
in-game dialog, and [lua](http://www.lua.org/) for both extensions and a
command line\
  *additional dependancies will follow...*

use of an [external debugger](https://www.gnu.org/software/gdb/) is
recommended if **Bad Things** start happening.

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

BUILDING
========

to compile, `cd` into `src/` and run the `build.sh` script. please report
any bugs that occur, according to the instructions at the
[devel](https://github.com/GeneralGuy4872/IWannaFly_FullCircle/tree/devel)
branch.

LICENSE
=======

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
