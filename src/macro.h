/*TYPES*/
//ensure size names work on all systems
#define ≥ >=
#define ≤ <=
#define forever for (;;)
#define END return 0;}

#ifndef EOF
#error now you're just TRYING to break stuff...
#endif

#ifndef NULL
#warning ... ...wh ... ... how??
#define NULL ((void*)0)
#endif

#define TRUE true
#define True true
#define FALSE false
#define False false

/*FUNCTION MACROS*/
#define BALTERNOCT(X,Y,Z) ((sgn(Z) * 9) + (sgn(Y) * 3) + sgn(X))
#define SUBSCR(Z,Y,X) ((CHUNK * CHUNK * Z) + (CHUNK * Y) + X)
#define SUBSCRV(Z,Y,X,A,B) ((A * B * Z) + (B * Y) + X)
