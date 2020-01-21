#define NIL ""

#ifndef OK
#define OK 0
#endif

#ifndef ERR
#define ERR -1
#endif

#define MAX_X 64
#define MAX_Y 64	//MAX_X ≥ MAX_Y ≥ MAX_Z
#define MAX_Z 32

// **.alignmet : 9
#define GOOD_MASK 0700
#define LAWFUL_MASK 0444
#define EVIL_MASK 0007
#define CHAOTIC_MASK 0111
//
#define NEUT_HORIZ_MASK 0070
#define NEUT_VERT_MASK 0222
//
#define LAW_GOOD_BIT 0400
#define NEUT_GOOD_BIT 0200
#define CHAOS_GOOD_BIT 0100
#define LAW_NEUT_BIT 0040
#define TRUE_NEUT_BIT 0020
#define CHAOS_NEUT_BIT 0010
#define LAW_EVIL_BIT 0004
#define NEUT_EVIL_BIT 0002
#define CHAOS_EVIL_BIT 0001
//
#define LAW_GOOD_WIDEMSK 0764
#define CHAOS_GOOD_WIDEMSK 0731
#define LAW_EVIL_WIDEMSK 0467
#define CHAOS_EVIL_WIDEMSK 0137
#define NEUTRAL_WIDEMSK 0272

// **.element : 8 {
#define ELE_WATER_BIT 0x80
#define ELE_ICE_BIT 0x40
#define ELE_AIR_BIT 0x20
#define ELE_ELEC_BIT 0x10
#define ELE_FIRE_BIT 0x08
#define ELE_METAL_BIT 0x04
#define ELE_EARTH_BIT 0x02
#define ELE_TREE_BIT 0x01
//
#define ELE_WATER_WIDEMSK 0xC1
#define ELE_ICE_WIDEMSK 0xE0
#define ELE_AIR_WIDEMSK 0x70
#define ELE_ELEC_WIDEMSK 0x38
#define ELE_FIRE_WIDEMSK 0x1C
#define ELE_METAL_WIDEMSK 0x0C
#define ELE_EARTH_WIDEMSK 0x07
#define ELE_TREE_WIDEMSK 0x83
// }

// **.lde : 3 {
#define LIGHT_BIT 4
#define DARK_BIT 2
#define ENTROPY_BIT 1
// }

#define ROOM_STACK_MAX 40

#define ROOM_NORTH 0
#define ROOM_SOUTH 1
#define ROOM_WEST 2
#define ROOM_EAST 3
#define ROOM_DOWN 4
#define ROOM_UP 5
#define ROOM_DOWNSTAIR 6
#define ROOM_UPSTAIR 7

// **.grav : 3 {
#define GRAV_NONE 0
#define GRAV_UP 4
#define GRAV_DOWN 3
#define GRAV_NORTH 2
#define GRAV_SOUTH 5
#define GRAV_EAST 1
#define GRAV_WEST 6
// }

#define BUFFER_MAX 512
#define FLOPPYSIZE 1474560
#define DRUMSIZE 16384
#define BGCOLORS 8
#define FGCOLORS 8

#define SQRT3 1.732050807568877293528

//hitboxtyp.type
#define HITBOX_BOX 1
#define HITBOX_SPHERE 2
#define HITBOX_RAY 4
#define HITBOX_X 010
#define HITBOX_Y 020
#define HITBOX_Z 040
