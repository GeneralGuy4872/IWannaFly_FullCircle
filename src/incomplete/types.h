#ifndef IWF_TYPES_H
#define IWF_TYPES_H
/* this code is liscensed under the GPL, version 2.0 or at your option,
 * under the same terms of Perl, version 5.24, or under a later version
 * of the GPL or the terms of Perl;
 *
 * concepts and ideas used herein shall not be included under the
 * the terms of the license IFF they are in the public domain
 * or equivilantly classified as common knowlage; such knowlage
 * is not be mine to lend liscense to.
 */

/* many of these types can be thought of as associative arrays with a fixed
 * set of keys, and their relation be visualized in the usual manner of
 * pointers and arrays in C and Pascal.
 *
 * the level of abstraction starts signifigantly lower than most modern
 * programming (with some blackbox exceptions, such as std::string), and
 * then builds a well-defined, consistant higher level API from a sturdy
 * lowlevel foundation.
 */

#include <stdint.h>
#include <stdbool.h>

#define _FH_ int

typedef uint8_t ucoord2[2];
typedef uint8_t ucoord3[3];
typedef uint8_t ucoord4[4];

typedef int8_t scoord2[2];
typedef int8_t scoord3[3];
typedef int8_t scoord4[4];

typedef uint16_t ucoord2w[2];
typedef uint16_t ucoord3w[3];
typedef uint16_t ucoord4w[4];

typedef int16_t scoord2w[2];
typedef int16_t scoord3w[3];
typedef int16_t scoord4w[4];

struct encontyp;
struct enttyp;
struct eventtyp;
struct mapobjtyp;
struct ray_vfx_typ;

struct planetyp {
	bool shadow : 1;
	unsigned rho : 2;
	unsigned az : 3;
	signed el : 2;
	}

struct chunktyp <:
	ucoord2w chunkpos;
	ucoord2w filename;
	struct planetyp plane;
	Vector3 latlon; 	//the reported latitude, longitude, and elevation of the chunk
	intptr_t area : 16;	//key to a table of area names
	intptr_t tiles : 8;	//key to a table of alternate tilesets
	uint8_t tiles[64][64][64];
	struct encontyp * encon_ptr;
	struct /*enttyp*/ kdtree * ent_ptr;
	struct /*mapitemtyp*/ kdtree * mitem_ptr;
	struct /*npctyp*/ kdtree * npc_ptr;
	struct /*char **/ kdtree * npc_ptr;
	struct /*ray_vfx_typ*/ kdtree * ray_ptr;
	struct /*ray_vfx_typ*/ kdtree * light_ptr;
	struct /*evtriggertyp*/ kdtree * ev_ptr;
	:>
	
#endif
