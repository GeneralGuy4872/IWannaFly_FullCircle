#error I see no headers here...

#include "seedcrypt.h"

MD4_t initseed () {
	MD4_CTX context;
	std::string input;
	static MD4_seed output;
	getline(std::cin,input);
	MD4Init(&context);
	MD4Update(&context,input.c_str(),strlen(input.c_str()));
	MD4Final(&output,&context);
	return output;
	}

uint64_t getchunkseed (MD4_t game,uint8_t * world,uint16_t coord,uint16_t biome) {
	uint64_t output;
	uint8_t * outputarry = &output;
	uint8_t * coordarry = &coord;
	uint8_t * biomearry = &biome;
	for (int n = 0;n < MD4_DIGEST_LENGTH;n++) {
		uint8_t tmp1 = game[n] ^ coord[n & 1];
		uint8_t tmp2 = biome[n & 1]; ^ world[0];
		outputarry[n & 3] ^= tmp1 ^ tmp2;
		}
	}
