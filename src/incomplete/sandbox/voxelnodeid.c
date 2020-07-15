int32_t iwf$$raw32$$voxelnodeid$$pack (
  unsigned char octant_x,unsigned char octant_y,unsigned char octant_z,
  unsigned char coord_x, unsigned char coord_y, unsigned char coord_z,
  bool large,bool octree_x,bool octree_y,bool octree_z) {
	if ((octant_x < 7) && (octant_y < 7) && (octant_z < 7) &&
	  (coord_x < 0x20) && (coord_y < 0x20) && (coord_z < 0x20)) {
		return ((1 << 31) | (iwf::private::voxelnodeid::cachedvoxelid[octant_z][octant_y][octant_x] << 19) |
		  (coord_x << 14) | (coord_y << 9) | (coord_z << 4) |
		  (parent << 3) | (octree_z << 2) | (octree_y << 1) |
		  octree_x);

uint16_t iwf$$raw32$$voxelnodeid$$get$chunkhash (int32_t input) {
	return ((input >> 19) & 0x0FFF);

unsigned char iwf$$raw32$$voxelnodeid$$get$coord$z (int32_t input) {
	return ((input >> 14) & 0x1F);
	}

unsigned char iwf$$raw32$$voxelnodeid$$get$coord$y (int32_t input) {
	return ((input >> 9) & 0x1F);
	}

unsigned char iwf$$raw32$$voxelnodeid$$get$coord$x (int32_t input) {
	return ((input >> 4) & 0x1F);
	}

int16_t iwf$$raw32$$voxelnodeid$$get$coord (int32_t input) {
	return ((input >> 4) & 077777);
	}

bool iwf$$raw32$$voxelnodeid$$get$parent (int32_t input) {
	return (input & 8);
	}

bool iwf$$raw32$$voxelnodeid$$get$octree$z (int32_t input) {
	return (input & 4);
	}

bool iwf$$raw32$$voxelnodeid$$get$octree$y (int32_t input) {
	return (input & 2);
	}

bool iwf$$raw32$$voxelnodeid$$get$octree$x (int32_t input) {
	return (input & 1);
	}
