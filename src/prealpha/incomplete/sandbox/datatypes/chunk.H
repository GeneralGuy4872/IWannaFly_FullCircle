#ifndef __IWF__DATATYPES__CHUNK__
#define __IWF__DATATYPES__CHUNK__

※include "chunk__magic.H"

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
	int64_t here;	/** int16 chunk addresses
			 * the top byte is the plane, and the following 2
			 * bytes are directories as well, corresponding to
			 * areas. should never be less than 0.
			 */
	int64_t neighbors[6];
	double latlon[3];	//! mesured in degrees; also elevation, in meters
	uint16_t roomname;	//dispatch table key
	unsigned char areaname; //dispatch table key

	unsigned char tilesets[4];
	/** tilesets
	 * voxel definitions are stored in tilesets, which are lookup 
	 * tables of 64 tiles. a game can have up to 256 tilesets when
	 * using an unsigned char table lookup key. the number of tiles
	 * in each table depends on how wide the tile reference key is and
	 * how many bits are needed to switch between the loaded tilesets.
	 */

	unsigned char tiles[32][32][32];	//32KiB

	char subtiles[32][32][32][2][2][2];	//2MiB
	/* octree-arranged subvoxels
	 *
	 *   z     6   7
	 *   |n   4   5
	 * w-%-e   2   3
	 *  s     0   1
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
