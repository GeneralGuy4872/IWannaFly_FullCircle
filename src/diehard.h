#include <stdlib.h>
#include <stdio.h>
#define diehard(F,L) fprintf(stderr,"illegal state, cosmic rays, or hardware failure\nfile: %s\nline: %ul\n",F,L);abort()