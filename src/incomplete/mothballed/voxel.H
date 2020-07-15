#ifndef USING___IWF__DATATYPES__VOXEL
#define USING___IWF__DATATYPES__VOXEL
STRUCTTYPE_BEGIN(iwf$$datatypes$$voxel_t)
	unsigned octant : 8;
	unsigned yz : 12;
	unsigned xz : 12;
	unsigned xy : 12;
	unsigned vert : 27;
	bool bank : 1;
	unsigned tile : 8;
STRUCTTYPE_END(iwf$$datatypes$$voxel_t)
#endif
