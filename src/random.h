#ifndef __IWF_RANDOMH__
#define __IWF_RANDOMH__

#ifndef __cplusplus
#include <stdlib.h>
#endif
#include <stdbool.h>
#ifdef __cplusplus
extern "C" {
#endif

#define coin_flip (rand() % 2)

extern int coin_flip_nickel();
extern unsigned roll(unsigned number,unsigned sides,_Bool off);
extern signed short roll_bonus(unsigned number);
extern char randchar();

#ifdef __cplusplus
}
#endif
#endif
