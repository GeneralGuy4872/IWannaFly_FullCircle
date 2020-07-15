extern std::map<short;boost::simple_segregated_storage<size_t> *> POOLS;
// for saving and loading. the entire memory pool is saved as a file.

struct persistantptr {
	void * offset;
	short pool;
	};

void * truncateptr (void * input,size_t size) {
	void * mask = base1(void*,((unsigned)floor(log2(size) + 1)));
	return input & mask;
	}

int makepool (size_t size) {
	boost::simple_segregated_storage<size_t> pool;
	void * block;
	posix_memalign(&block,size,size);
	pool.add_block(block,size,sizeof(char));
	short key = NEXTPOOL;
	POOLS[key] = &pool;
	NEXTPOOL++;
	while ((POOLS.contains(NEXTPOOL)) && (NEXTPOOL != key)) {
		NEXTPOOL++;
		}
	if (NEXTPOOL == key) {
		POOLSMAXED = 1;
		}
	return key;
	}
