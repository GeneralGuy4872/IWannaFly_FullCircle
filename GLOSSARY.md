because of the multi-paradigm nature of the project, I will begin labling
functions, macros, and certain labels according to these terms

types of stand-alone functions:

SUBROUTINE : a small function or a macro function that has no side-effects
	many subroutines take no arguments,
	but not everything that has no arguments is a subroutine

PROGRAM : a complex function. anything ambiguously mislabled "function"
	probably means this. the criteria that makes a subroutine a
	program is that it requires user input.

FSAUTOMATA : a multiple-entry function that holds continuations

	STATE : a lable that acts as a state in a finite state automata

types of OO methods :

ALLOCATOR : indicates that the function's main pourpose is to
	allocate dynamic memory

DEALLOCATOR : indicates that the function's main pourpose is to free memory

SETVALUE : indicates that the function's main pourpose is to change the
	value of an address

METHOD : indicates that the function is a method for an object not
	otherwise listed

LEAKY : does not collect garbage

modifyer words :

SUBOPTIMAL : modifyer word. self-explanitory.

GLOBAL : for OO methods, specifys that the object in question is
	global data instead of an object.

STACKY : for OO methods, relates to a stack operation
