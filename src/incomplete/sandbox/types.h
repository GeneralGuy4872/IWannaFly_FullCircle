#ifndef IWF_TYPES_H
#define IWF_TYPES_H

#include <stdint.h>
#include <stdbool.h>

struct encontyp;
struct enttyp;
struct eventtyp;
struct mapobjtyp;
struct ray_vfx_typ;

typedef struct iwf$$datatypes$$plane_bf {
	bool shadow : 1;
	unsigned rho : 2;
	unsigned az : 3;
	signed el : 2;
	} planetype;

struct iwf$$datatypes$$chunk_t {
	Vector2u16 chunkpos;
	Vector2u16 filename;
	iwf$$datatypes$$chunk_bf plane;
	Vector3 latlon; 	//the reported latitude, longitude, and elevation of the chunk
	intptr_t area : 16;	//key to a table of area names
	intptr_t tiles : 8;	//key to a table of alternate tilesets
	uint8_t tiles[4096];	//16x16x16 cube, X=0x00F,Y=0x0F0,Z=0xF00
	struct encontyp * encon_ptr;
	struct /*enttyp*/ kdtree * ent_ptr;
	struct /*mapitemtyp*/ kdtree * mitem_ptr;
	struct /*npctyp*/ kdtree * npc_ptr;
	struct /*char **/ kdtree * npc_ptr;
	struct /*ray_vfx_typ*/ kdtree * ray_ptr;
	struct /*ray_vfx_typ*/ kdtree * light_ptr;
	struct /*evtriggertyp*/ kdtree * ev_ptr;
	}
