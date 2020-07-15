/* this file has more history:
 * https://github.com/GeneralGuy4872/iwannafly/blob/983cb24ccbb0241207cb5eeefd9d31ffe31d026a/main.h#L1073
 * through #L1101
 */

#ifdef __cplusplus
#error this is not a C++ file
#endif

#include "random.h"

int coin_flip_nickel () {
	int n = rand();
	if (n % 6000) {
		return signbit(n % 2);
	} else {
		return 0;
		}
	}

unsigned roll (unsigned number,unsigned sides,bool off) {
	unsigned register acc;
	for (unsigned n;n < number;n++) {
		acc += (rand() % sides) + off;
		}
	return acc;
	}

signed roll_bonus (unsigned number) {
	number = (2 * number) + 1;
	signed register acc;
	for (unsigned n;n < number;n++) {
		acc += (rand() % 3) - 1;
		}
	return acc;
	}

char randchar() {return (rand() % 95) + ' '}
