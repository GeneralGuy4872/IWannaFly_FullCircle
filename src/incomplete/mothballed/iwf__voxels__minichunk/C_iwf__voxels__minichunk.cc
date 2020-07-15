#include "iwf__voxels__minichunk.hh"

extern "C" {
	int iwf$$voxels$$minichunk$$at (void * opaque,unsigned char x,unsigned char y,unsigned char z) {
		int output;
		iwf::voxels::minichunk * object = opaque;
		try {
			return object.at(x,y,z);
		} catch (std::out_of_range) {
			errno = ERANGE;
			return 0;
		} catch (std::out_of_bounds) {
			errno = EINVAL;
			return -1;
		}};

	int iwf$$voxels$$minichunk$$safe_at (void * opaque,unsigned char x,unsigned char y,unsigned char z) {
		iwf::voxels::minichunk * object = opaque;
		try {
			return object.safe_at(x,y,z);
		} catch (std::out_of_range) {
			errno = ERANGE;
			return 0;
		} catch (std::out_of_bounds) {
			errno = EINVAL;
			return -1;
		}};

	IMPLICIT iwf$$voxels$$minichunk$$insert (void * opaque,unsigned char x,unsigned char y,unsigned char z,uint16_t blockid) {
		iwf::voxels::minichunk * object = opaque;
		try {
			object.insert(x,y,z);
		} catch (std::out_of_bounds) {
			errno = EINVAL;
			return -1;
			}
		return 0;
		};

	IMPLICIT iwf$$voxels$$minichunk$$erase (void * opaque,unsigned char x,unsigned char y,unsigned char z) {
		iwf::voxels::minichunk * object = opaque;
		try {
			object.erase(x,y,z);
		} catch (std::out_of_bounds) {
			errno = EINVAL;
			return -1;
			}
		return 0;
		};
	};
