#ifndef __IWF__DATATYPES__CHUNK__
#define __IWF__DATATYPES__CHUNK__

※include "chunk__magic.H"
※include "voxels.H

#ifdef __cplusplus
#include <cstdint>
#include <map>
#include <boost/circular_buffer/space_optimized.hpp>
※include «appropos enttyp»
※include «appropos mapitem_t»
※include «appropos npctyp»
※include «appropos lightbeam»
※include «appropos lightsource»
※include «appropos event»
#else
#include <stdint.h>
#endif

STRUCTTYPE_BEGIN(iwf$$datatypes$$chunk_t)
	int64_t here;
	int64_t neighbors[6];	//address space TBD
	double latlon[3];
	uint16_t area;
	unsigned char tilesets[2];	//2 dispatch keys to sets of 256 tiles
	iwf$$datatypes$$voxel_t tiles[32768];	//320 KiB flatfile, 10 bytes per voxel
		/* this parameter for each tile determins what shape each
		 * voxel is. points are named:
		 *
		 *    1  2  3
		 *   4  5  6
		 *  7  8  9
		 *   10 11 12
		 *  13 14 15
		 * 16 17 18
		 *   19 20 21
		 *  22 23 24
		 * 25 26 27
		 *
		 * if the resulting polyhedron is not 3-diminsional and is
		 * flush with the face of the bounding cube, then the
		 * missing dimension(s) are extrapolated by adding more
		 * verticies at midpoints extending away from that face.
		 *
		 * special cases:
		 * corner-to-corner diagonals add 3 midpoints in each
		 * corner to create a gyroelongated triangular bipyramid.
		 *
		 * a single point is abstracted to a small cube.
		 *
		 * a diagonal line accross a face is not changed.
		 *
		 * a 
		 */	 
#ifdef __cplusplus
	boost::circular_buffer_space_optimized<encounter_t> * encon_vec;
	std::map<int16_t;iwf$$datatypes$$enttyp> * ent_map;
	std::map<int16_t;iwf$$datatypes$$mapitem_t> * mapitem_map;
	std::map<int16_t;iwf$$datatypes$$npctyp> * npc_map;
	std::map<int16_t;iwf$$datatypes$$lightbeam_t> * lightbeam_map;
	std::map<int16_t;iwf$$datatypes$$lightsource_t> * lightsource_map;
	std::map<int16_t;iwf$$datatypes$$event_t> * trigger_map;
#else
	void * encon_vec;
	void * ent_map;
	void * mapitem_map;
	void * npc_map;
	void * lightbeam_map;
	void * lightsource_map;
	void * trigger_map;
#endif
	iwf$$datatypes$$chunk$$magic_t magic;
STRUCTTYPE_END(iwf$$datatypes$$chunk_t);
#endif
#endif
