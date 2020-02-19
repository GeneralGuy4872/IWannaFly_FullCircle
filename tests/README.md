previously, I had not been including test programs in my git;
in fact, to conserve hard drive space, I had been overwriting them as I
went. as the game and library have gotten mopre complex, however, this has
prooved to be a mistake, and the test programs will now be placed here.

these programs test the sane-ity of my solutions

ATan2Test
=========
<CODE>cc atan2test.c -lm</CODE>

calculates an alignment given a coordinate

MainLoopTest
============

<CODE>cc mainlooptest.c -lraylib</CODE>

The skeleton of the program

controls:

F1 - First Person Mode

F3 - Third Person Mode

Page Up, Page Down - Change the Field of View
Home - Reset the Field of View

Scrollwheel - Move the Camera closer/further in Third Person

Mouse Movement - Look around (First Person) / Orbit Camera (Third Person)

F2 - Get back the Cursor
