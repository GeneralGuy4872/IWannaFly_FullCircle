/* todo:
 * tools??? - segment item table like an address space, then do
 *	glue to route relavant bits to smaller dispatch tableS?
 * variable room size (in multiples of 32 to align with neighbors)
 * 	[1] cast each chunk's stringy pointer to a multidiminsional
 *	array, or implement array unflattening manually
 *	- implement chunk scrolling
 * rework roomstack neighbors:
 * 	render all king's norm adjacent rooms (if two different rooms are not occupying the same space)
 * redo language
 */

/* uuid's are used to cache dynamiclly allocated memory into the savefile;
 * think of them like portable pointers.
 */

#ifndef IWANNAFLY_TYPES_H_REENTRANT
#define IWANNAFLY_TYPES_H_REENTRANT 1

/* note: if the compiler complains about mixing tightly packed and loosly packed fields,
 * the tightly packed ones will be split off into a seperate type with "_bits" affixed to
 * the name, which will be placed in a member "_bits" at the end of the struct.
 *
 * only structs that mix odd-sized members and subcontainer structs or true pointers will have this problem;
 * technically, even true pointers can be size-allocated if you want to maintain seperate 32 and 64 bit sources,
 * but I don't. debugging multiple builds from a single source will be difficult enough.
 */

#define uint unsigned int
#define uchar unsigned char
#define ushort unsigned short
#define ulong unsigned long
#define ptrchar uint8_t
#define ptrshort uint16_t

struct odds_n_ends {
uint64_t turn;
turntype date;
ushort roomturn;
}

struct stringlistyp {
(self) *prev
(self) *next
char* text
}
/* used to store a list of strings
 * may be from a data object, or
 * stored in a tsv
 */

struct singlestringlistyp {
(self) * next
char * text
}

struct filelinetyp {
(self) *prev
(self) *next
ushort lineno
char* text
}
// used by the line editor

struct singlestringlistyp {
(self) * next
ushort lineno
char * text
}

struct chaptertyp {
unsigned c : 7;	//chapter number
unsigned a : 9;	//alignment type
}

struct turntyp {
unsigned second : 6;	//mod 60
unsigned mm : 6;	//mod 60
unsigned hour : 5;	//mod 24
unsigned dayhour : 5	//mod 24, set to hour + sunrise
unsigned dayear : 9;	//mod 360
unsigned weekday : 3;	//mod 7
unsigned moonphase : 2;	//rollover
unsigned moonhour : 4;	//mod 15
unsigned daymonth : 5;	//mod 30
unsigned month : 4;	//mod 12
unsigned seasoncounter : 2;	//rollover
unsigned season : 2;	//rollover
char : 0;
}

struct sphere {
Vector3 center
float radius
}

typedef uchar ucoord4[4];
typedef uchar ucoord3[3];
typedef uchar ucoord2[2];
typedef char scoord4[4];
typedef char scoord3[3];
typedef char scoord2[2];

struct setcoord3 {
struct setcoord3 * prev;
struct setcoord3 * next;
uchar x;
uchar y;
uchar z;
}

typedef char *strarry[]
typedef void *ptrarry[]

struct lightyp {
struct lightyp * prev;
struct lightyp * next;
ucoord2 x;
ucoord2 y;
ucoord2 z;
}

struct agetyp {
	unsigned chrono : 16;
	signed bio : 8;	//entity dies on overflow
	unsigned rem : 8;	// bio's remainder after chrono;
	}			/* bio increments on the next modulo0 of
				 * the entity's current aging factor
				 * (href basentyp). exploiting the
				 * immediately apparent flaw of this
				 * behavior by frequently shapeshifting
				 * is allowed; but has it's own side
				 * effects. (href shiftstackobj)
				 */

struct nibbles {
unsigned lo : 4
unsigned hi : 4
}

struct snibbles {
signed lo : 4
signed hi : 4
}

struct racetyp {
intptr_t race : 8
intptr_t table : 4
unsigned meta : 4
	// 00,0,F is nul
}

struct microvector {
unsigned x : 2
unsigned y : 2
unsigned z : 2
unsigned w : 2
}

struct nanovector {
signed x : 2
signed y : 2
signed z : 2
signed w : 2
}

typedef char *pluralwords[3];

#define MOVETOKEN_ICE 8
#define MOVETOKEN_LAND 4
#define MOVETOKEN_FLY 1
#define MOVETOKEN_SWIM 2

struct selftyp {
unsigned az : 3	//yaw in eighth turns
unsigned phi : 3	//polar angle in eighth turns
unsigned movetoken : 4
unsigned gravdir : 5	//changes the up vector, must be a valid octant
bool weightless : 1
}

struct beamtyp {
unsigned az : 3	//azimuth
unsigned phi : 3	//elevation in eighth turns. 07 is omnidirectional.
unsigned ang : 4	//total solid angle of spread in twelfths of a circle.
unsigned range : 6
}
/* for all azimuths:
 *
 * 701
 * 6 2
 * 543
 *
 * for all elevations:
 *
 * +1
 *  0  ?-2?
 * -1
 */

struct diceodds:
unsigned num : 3
unsigned side : 5
unsigned tobeat : 8

struct planetyp {
bool shadow : 1
unsigned rho : 2
unsigned az : 3
signed el : 2
}

/* if the poles of a sphere are unaccessible, it may be cylindrically
 * projected; otherwise, it must be cube mapped
 *
 * rho 0 is the prime plane
 * rho 1 are the elemental planes
 * rho 2 are afterlives
 * rho 3 can be used for areas that are meant to not show up on a map.
 *			(said map would be implemented with pipes)
 *
 * az	elemental	afterlife	corrilation
 * 0	water		neutral good	nurturer
 * 1	ice		chaotic good	the ends justify the means
 * 2	air		chaotic neutral	insert obscure fourswords reference here
 * 3	electricity	chaotic evil	force lightning
 * 4	fire		neutral evil	obviously
 * 5	metal		lawful evil	greed
 * 6	earth		lawful neutral	stubborn
 * 7	trees		lawful good	knowladge
 *
 * az rotates by 45 degree steps and el by 90 degree steps.
 * a nonzero el causes az to gimbal lock.
 * also best not to think about where exactly -2 is pointing.
 *
 * el	"		"		"
 * +1	light		true neutral	enlightenment
 * -1	darkness	uncomitted	meh, I'll think of one later
 * -2	entropy		oathbreakers	abandon all hope ye who enter here
 *
 * errors related to this section may generate one of 2 errors:
 * "fell off the edge of the world", N1=±lat,N2=±lon
 * "froze to death on pluto", N1=+az,N2=±el
 *
 * a room stack exists that keeps a number of rooms loaded
 * if a room is not on the stack, it is loaded from the save file and
 * pushed to the stack. this may cause the stack to intentionally drop
 * the room at the bottom to prevent eating too much ram. if the file
 * does not yet exist, the room is generated according to a dispatch table
 * in a shared object. if the function and file are both NULL and the
 * room is being entered, a lost in space death is called. if only the
 * function is NULL, the file is executed in perl. if only the file is
 * NULL, no shared objects are loaded before the function is called. 
 *
 * a swap array keeps track of gating between the 23 major planes,
 * saving the player's position, but not keeping the room loaded.
 */

struct placetyp {
(self) *prev
(self) *next
uuid_t uuid
char* name
ucoord4 globpos
planetyp plane
Vector2 latlon
ucoord3 pos
}

typedef float trackaligntyp[2]
typedef float trackalignplayertyp[3]
/* alignments satisfy the equasion { x^2 + y^2 ≤ 1000^2 }
 * neutral is the area satisfying { x^2 + y^2 ≤ 100^2 }
 * other alignments are deternmined by lines extending at the following
 * azimuths: 30, 60, 120, 150, -150, -120, -60, -30 (use atan2)
 * corner cases round twords a cardinal direction
 *	
 * actions, quests, and being polymorphed into
 * certain monsters can alter your alignment
 * [0] is {+good,-evil}, [1] is {+lawful,-chaotic}
 *
 * for players, proactivness/passivity is also
 * tracked
 */

struct ray_vfx_typ {
(self) * prev
(self) * next
Ray this
Color color
}

struct multiclasstyp:
(self) *prev
(self) *next
bool notnull : 1
unsigned role : 2
unsigned class : 3
unsigned mastery : 2

struct classtyp {
bool notnull : 1
unsigned role : 2
unsigned class : 3
unsigned mastery : 2
}

struct baseclasstyp {
struct paffectyp bonus
uchar spd
char airspd
uchar air
struct conlangtyp lang
cantriptyp spell[2]
bool mindless : 1
bool shadow : 1
bool incoporeal : 1
bool immortal : 1
unsigned lde : 3	//grants
unsigned alignment : 9	//requires
unsigned element : 8	//grants
}

struct the8stats:	//8* 5D6
stren : u5
psy : u5
dex : u5
con : u5
fort : u5
intl : u5
wis : u5
bluff : u5
struct movelimit {
float spd
float airspd
float watspd
uchar lung
uchar wing
}

struct movecount {
float spd //added to move each turn
float airspd	/* if this is negative, then it's value is immediately
		 * subtracted from move whenever flying is attempted.
		 * otherwise, added to fly each turn
		 */
float watspd //ditto but added to swim
float move //value is capped at 2*spd
float fly 	/* carries the extra moves that can be used in the air;
		 * they are used first when applicable
		 */
float swim //ditto but used in water
ucoord3 skillgain	/* [0] = ground, [1] = water, [2] = air.
			 * when these overflow, a skill level is
			 * gained if applicable.
			 */
ucoord2 lung //number of turns that you can go without air.
ucoord2 wing //number of turns left before you fall
}

struct conlangtype:
unsigned id : 5
bool r : 1
bool w : 1
bool x : 1

struct xtraplayertyp {
chaptertyp chapter;
uint64_t kills;
uchar elecollect[8];
uchar questcollect[3];
bagitemptr * bag;
walletyp wallet;
}

/* note: everything related to players and entitys is
 * copied into the struct, because it might be changed.
 * the base entities and base classes are only templates.
 *
 * whenever you "rest" in-game, all entities are re-verified;
 * meaning that all effect registers are recalculated. this
 * has the side effect of removing any non-item based buffs
 * and debuffs. this should be one of the only times that
 * a baseclasstyp or basentyp are referenced; the others
 * being adding a class, looseing a class, advancing in a class,
 * polymorphing, polylocking, by the renderer,
 * and when spawning a new entity.
 *
 * some stats are spread out accross multiple fields in the structure;
 * most effects have one field for permenant and one field for temporary
 * versions of the effect. a handful of alteration spells have a third
 * register, with the polymorph stack, for timed spells, since the
 * other temporary slot has no timer.
 *
 * nearly all fields of the player struct are created by COMBINING the
 * basentyp and baseclasstyp chosen at the creation of the savefile.
 * the remainder are based on backstory and user input.
 */

walletyp {
unsigned whole : 25
unsigned cent : 7
}

struct playertyp:
playertyp * prev
playertyp * next
char * name
ushort storyseed	//the story entrypoint for this player
uuid_t root	//the uuid for this player's story; should they die, everything with this uuid as a parent is garbage collected
classtyp class[3]
uchar element
agetyp age
struct shiftstackobj race
ucoord3 pos
selftyp etc
struct movecount move
paffectyp paffect	//permenant
effectyp effect	//from equipment
trackalignplayertyp align
ushort hp	//they're fun and easy to...wait
ushort mp
uint32_t xp
uchar lvl
Vector2 hunger
langlistele *lang_ptr
spellistele *spell_ptr
cantriplistele *cant_ptr
helditemtyp helm	//any item
helditemtyp shield	//shld
helditemtyp bow	//weapon
helditemtyp armor	//armor
helditemtyp cape	//armor
helditemtyp amul	//baub
unsigned n_arms : 4
unsigned n_legs : 4
armtyp * arms
legtyp * legs

struct armtyp {
struct armtyp * next
helditemtyp weap[2]
helditemtyp ring[2]
helditemtyp wrist[2]
helditemtyp gloves
helditemtyp cannon
}

struct legtyp {
legtyp * next
helditemtyp boots
helditemtyp greev
}

enum equipenum = {ENUM_WEAP_LEFT,ENUM_WEAP_RIGHT,ENUM_SHIELD_ENUM_BOW,ENUM_ARMOR,ENUM_CAPE,ENUM_HELM,
ENUM_GLOVES,ENUM_CANNON,ENUM_BOOTS,ENUM_GREEV,ENUM_AMUL,ENUM_RING_LEFT,ENUM_RING_RIGHT,ENUM_WRIST_LEFT,
ENUM_WRIST_RIGHT}

struct basentyp:
aggrotyp aggro	//here, shiftable denotes a monster's aggro state is locked. also gives the value that patience is set to when a monster calms down, the value that cooldown is set to when it is angered, and the default AI.
paffectyp base
struct movelimit move
unsigned n_arms : 4
unsigned n_legs : 4
uchar hplvl
uchar mplvl
uchar xplvl
struct conlangtyp lang[2]
spelltyp spell[4]
Mesh * shape
Texture2D * texture
signed size : 2
bool mindless : 1
bool shadow : 1
bool incoporeal : 1
unsigned age_rate : 8
unsigned element : 8
unsigned lde : 3
float hunger
/* entitys of size 1 or -2 cannot use armor.
 * entitys of larger size automaticly win grapples.
 * entitys of 2 sizes smaller can be picked up and thrown.
 * entitys of size 1 can instakill entitys of size -2. squish.
 * size 1: dragon, size 0: human, size -1: dwarf, size -2: pixie
 */

struct aggrotyp:
bool unhinged : 1
unsigned patience : 3
unsigned ai_type : 4
unsigned anger : 8

struct enttyp:
(self) *prev
(self) *next
npctyp * depth
agetyp age
classtyp class
uchar element
aggrotyp aggro
struct shiftstackobj race
ucoord3 pos
selftyp etc
struct movecount move
paffectyp paffect
effectyp effect
ushort hp
ushort mp
uint32_t xp
uchar lvl
float wallet
spellistele *spell_ptr
cantriplistele *cant_ptr
helditemtyp loot
helditemtyp helm
helditemtyp shield
helditemtyp bow
helditemtyp armor
helditemtyp cape
helditemtyp amul
unsigned n_arms : 4
unsigned n_legs : 4
armtyp * arms
legtyp * legs

struct npctyp {
(self) *prev
(self) *next
ucoord3 * path
char * describe
uchar lang
char **lines[9];	//accessor: (lines[n])[m]
}
/* npc data is controlled by events, and is stored by room or in
 * global space. more complex actors, such as shopkeepers,
 * should be events.
 */


struct spawntyp:
npctyp * depth
classtyp class
uchar element
aggrotyp aggro
struct shiftstackobj race
paffectyp paffect
effectyp effect
helditemtyp loot
helditemtyp helm
helditemtyp shield
helditemtyp bow
helditemtyp armor
helditemtyp cape
helditemtyp amul
unsigned n_arms : 4
unsigned n_legs : 4
armtyp * arms
legtyp * legs

struct helditemtyp {
masteritemptr itemid;
uuid_t uuid;	//the null uuid for no extended metadata
extendedmetadata * data;	//the null pointer for no extended metadata
}

struct bagitemtyp:
(self) *prev
(self) *next
masteritemptr itemid;
extendedmetadata * data;

struct langlistele {
(self) * prev
(self) * next
struct conlangtyp data
}

struct spellistele {
(self) * prev
(self) * next
spelltyp this
}

struct cantriplistele {
(self) * prev
(self) * next
cantriptyp this
}

/*replace
struct subobjtyp:
intptr_t itemid : 8
bool cursed : 1
bool oxide : 1
bool burned : 1
signed bonus : 5
intptr_t metadata : 8 //secondary _8bitPtr for legendary objects
*/

struct magictyp:
bool fire : 1
bool air : 1
bool water : 1
bool earth : 1
unsigned lde : 3
bool planer : 1

struct shiftstackobj {
bool topdeck : 1; //does every shift change base[0]?
bool lycan : 1;	//is base[1] valid?
bool swap : 1 //base[swap]
signed depth : 5;	//on overflow, the stack is freed an topdeck is set
struct racetyp base[2];
struct shiftstackele * poly;	//unless this is NULL, this overrides base[]
struct shiftertyp alters;
}

struct shiftstackele {
struct shiftstackele * prev;
unsigned polytimer : 8;	//time remaining in the current polymorph.
intptr_t race : 8;
intptr_t table : 4;
unsigned meta : 4;
}/* polymorphing to the same form twice causes your active base form to change.
  * some ways of aquireing multi-form abilities may place restrictions on what your second form may be.
  */

struct altertimertyp {
	signed n : 5;	//permenant on overflow
	bool q : 1;
	char : 0;
	unsigned t : 8;
	}

struct altertimerwtyp {
	signed n : 5;	//permenant on overflow
	bool q : 1;
	unsigned w_typ : 2;
	bool w_sgn : 1;
	unsigned t : 7;
	}

struct shiftertyp {
struct altertimertyp gills;	//using an alteration spell, including intrensics from polymorph spells, 10 times will make them permenent.
struct altertimertyp lungs;	//these counters can be reset by rest or spells
struct altertimerwtyp wings;
struct altertimertyp tail;
struct altertimertyp claws;
struct altertimertyp fangs;
struct altertimertyp talons;
}/* non-player, non-follower entitys do not have this field,
  * and any polymorph or alteration is permenent. this may be
  * changed in future if memory footprint allows.
  */

struct cantriptyp {
funcptr spell;
diceodds odds;
uchar prof;
char cost_typ : 2 //0 = at will, 1 = gold, -1 = mp, -2 = hp
unsigned cost_amnt : 6
}

struct spelltyp {
basespelltyp * spell;
diceodds odds;
uchar prof;
char cost_typ : 2 //0 = at will, 1 = gold, -1 = mp, -2 = hp
unsigned cost_amnt : 6
}

typedef int (*funcptr)();
typedef int (*funcptr_1arg)(intptr_t);
typedef int (*funcptr_2arg)(intptr_t,intptr_t);
typedef int (*funcptr_3arg)(intptr_t,intptr_t,intptr_t);
typedef int (*funcptr_4arg)(intptr_t,intptr_t,intptr_t,intptr_t);
typedef int (*funcptr_multi)(uint,intptr_t*);
typedef int (*eventcleanup)(eventdatastack_ele,bool);

struct passiveffectlistele {
struct passiveffectlistele * prev;
struct passiveffectlistele * next;
funcptr whenthis;
funcptr dothis;
funcptr undothis;
intptr_t statedata;
}

struct basespelltyp:
unsigned lvl : 6
char : 0
magictyp type
potiontyp effect
missiletyp delivery

struct missiletyp {
bool vamp : 1
unsigned damage : 7
signed recoil : 8
float range;
float spread;
float splash;
}

struct baseweaptyp:
bool fire : 1
bool air : 1
bool water : 1
bool earth : 1
bool entro : 1
bool light : 1
bool dark : 1
bool fireproof : 1
bool waterproof : 1
bool elecproof : 1
bool iceproof : 1
bool warded : 1
bool illum : 1
unsigned skill : 3
unsigned damage : 8

legendtyp:
paffectyp magic
symtableref base
symtableref spell
legendflagtyp flags

legendflagtyp:
bool fire : 1
bool air : 1
bool water : 1
bool earth : 1
bool entro : 1
bool light : 1
bool dark : 1
bool fireproof : 1
bool waterproof : 1
bool elecproof : 1
bool iceproof : 1
bool warded : 1
bool unbreak : 1
bool infinate : 1
bool spelled : 1
bool vamp : 1
bool drain : 1
bool interest : 1
bool useless : 1
unsigned powermag : 5

struct basearmortyp:
effectyp effect
uchar def
uchar spdef
uchar extfort

struct baseshldtyp:
bool fireproof : 1
bool waterproof : 1
bool elecproof : 1
bool iceproof : 1
bool reflect : 1
bool entro : 1
bool light : 1
bool dark : 1
effectyp effect
unsigned def : 8
unsigned spdef : 8

struct bodytyp {
bool gills : 1;	//affects breathing underwater
bool wings : 1;	//affects flying
bool tail : 1;	//affects unarmed attacks, swimming, flying
bool claws : 1;	//affects unarmed attacks, writing
bool hoof : 1;	//affects walking, swimming, unarmed attacks
bool talon : 1;	//affects walking, swimming, unarmed attacks 
bool fangs : 1;	//affects unarmed attacks
bool legs : 1;	//affects walking, swimming, unarmed attacks
bool arms : 1;	//affects walking, swimming, unarmed attacks, writing
bool nolungs : 1;	//affects breathing above water
bool noswim : 1;	//affects swimming
bool nofly : 1;
bool atktail : 1;	//affects unarmed attacks, swimming, flying
bool atkwing : 1;	//affects unarmed attacks, swimming, flying
bool bite : 1;
bool breath : 1;
bool engulf : 1;
bool permwings : 1;
bool wingsign : 1;
unsigned wingtype : 2;
char : 0;
}

struct stattyp {
unsigned dizzy : 3;
unsigned psn : 4;
unsigned prlz : 4;
unsigned frz : 4;
unsigned brn : 4;
signed stone : 8;	//inverse one's complement; 0x00 is inactive (-0), 0xFF is dead (+0). overflows can be used to extend time to live
signed slime : 8;	//inverse one's complement
unsigned slp : 8;
unsigned invis : 6;
unsigned blind : 8;
signed eaten : 7;	//inverse one's complement
}

struct elixtyp:
dizzy : 1
psn : 1
prlz : 1
frz : 1
brn : 1
stone : 1
slp : 1
invis : 1

struct cursetyp:
stattyp type
uchar polytimer
intptr_t poly : 8

struct resistyp:
bool fireproof : 1
bool waterproof : 1
bool elecproof : 1
bool iceproof : 1
bool stoneproof : 1
bool polyproof : 1
bool sleepproof : 1
bool poisonproof : 1

struct sensetyp:
bool trouble : 1
bool invis : 1
bool infra : 1
bool blind : 1
bool good : 1
bool evil : 1
bool law : 1
bool chaos : 1

struct effectyp:
the8stats eight
bodytyp shape
stattyp stat
resistyp resist
sensetyp sense
skilltyp skill
char atk
char spatk
char def
char spdef

struct paffectyp:
the8stats eight
bodytyp shape
elixtyp ails_ya
resistyp resist
sensetyp sense
skilltyp skill
venomtyp venom
char atk
char spatk
char def
char spdef

struct potiontyp:
bodytyp shape
elixtyp ails_ya
cursetyp curse
resistyp resist
sensetyp sense
short hp
short mp
diceodds odds

struct skilltyp {
unsigned sword : 4; //+skill to sword-type weapon attack
unsigned knife : 4; //+skill to knife-type weapon attack
unsigned stave : 4; //+skill to stave-type weapon attack
unsigned spear : 4; //+skill to spear-type weapon attack
unsigned whip : 4; //+skill to whip-type weapon range (unused range added to attack)
unsigned club : 4; //+skill to club-type weapon attack
unsigned bow : 4; //+(2 * skill) to bow-type weapon range
unsigned throw : 4; //+(2 * skill) to javalin-type weapon range
unsigned monk : 4; //+(2*skill) to unarmed attack, unlocks more modes of attack.
unsigned shield : 4; //skill in (damage-defense)+abs(damage-defense) chance of blocking
unsigned locks : 4; //1 in 2^(lock.level - (skill)) chance of picking
unsigned caster : 6; //-(skill-1)/4 to casting cost, +(skill-1)/4 to spatk and spdef, unlocks spells, 0 is non-caster
bool swim : 1; //may be lost by polymorphing to a form with different locomotion.
bool walk : 1; //may be lost by polymorphing to a form with different locomotion.
unsigned fly : 2; //0 = never had wings, 1 = slow falling, 2 = cannot gain altitude, 3 = free flight. lvl1 learned by falling
bool sink : 1; //overrides any swim or fly skills
bool magnetic : 1;
}
/* damage = MAX( incoming-defense , 0 )
 *
 * polyshock = base.hplvl - ((poly.hplvl * (util__roll(1,20,1) / 20)) * util__roll(1,3,0))
 * ⎧if n < -HPMAX     : Instakill (deathmessage: miscalculated a crucial equivilant-exchange parameter,hath choose...poorly)
 * ⎪if n = -HPMAX     : Stoning
 * ⎨if -HPMAX < n < 0 : abs(n) Damage (deathmessage: could not withstand the cost of transmutation)
 * ⎪if n = 0          : stun for 1D16 (standardmessage: your mind reels from the transformation...)
 * ⎩if n > 0          : success
 *
 * writing =
 * succeed if 4D6 < dex if !talons, break pen on fail if 1D20 < stren
 * succeed if 6D6 < dex if talons, break pen on fail if coinflip
 * talons can engrave without tools
 */

readtyp:
unsigned locale : 6
bool multiuse : 1
bool scroll : 1
unsigned subject : 2 //0 = cooking, 1 = weapons, 2 = language, 3 = spellcraft
unsigned uses : 6
void* contents

wandtyp:
unsigned matter : 4
unsigned uses : 4
intptr_t bound : 8

baubtype :
signed type : 2 //0=ring, 1=bracelet, -1=amulet, -2=tiara
unsigned matter : 3
unsigned color : 3
paffectyp enchnt

struct roomneighbors {
ucoord4 * north
ucoord4 * south
ucoord4 * east
ucoord4 * west
ucoord4 * up
ucoord4 * down
microvector * north_offset
microvector * south_offset
microvector * east_offset
microvector * west_offset
microvector * up_offset
microvector * down_offset
bool upstair : 1
bool downstair : 1
bool show_north : 1
bool show_south : 1
bool show_east : 1
bool show_west : 1
bool show_up : 1
bool show_down : 1
}

struct chunktyp {
char* tiledata[CHUNK][CHUNK][CHUNK]
shadowmask * seen
shadowmask * light
shadowmask * collimap	//entity collision mask
}

struct roomtyp:
ucoord4 globpos
struct planetyp plane
Vector3 latlon	//reported as the latitude, longitude, and elevation of the current room. NaN may be helpful.
intptr_t area : 16 //the name of the area from a table of names
tileset *hightiles
struct chunktyp * chunks
struct microvector size //field w has no effect, other fields bias +1
encontyp *encon_ptr
enttyp *ent_ptr
eventtyp *ev_ptr
mapobjtyp *obj_ptr
ray_vfx_typ *ray_ptr
lightyp *light_ptr
ucoord3 ** path_ptr
ucoord2 downstair
ucoord2 upstair
ucoord3 home
char filltile
bool visited : 1
unsigned meta : 7
struct roomneighbors neighborhood
/* if invalid coords are given for a warp (typically {$FF,$FF}),
 * then the player is dumped at the location indicated by home.
 *
 * if the player has invalid coords, then the error string "fell out of terminal",N1=x,N2=y is generated.
 */

/* the world of the game will be referred to using two different grids of
 * discreet coordinates. the primary grid is the cell space, which is
 * interleaved octohedrally with the boundry space, such that if a given
 * diminsion in cell space has n points, the same dimension in boundry
 * space has n+1 points. the cell space referes to the cells that are
 * displayed (the "cells"), while the boundry space referes to their
 * boundries. exact boundry space coordinates are not expected to be used;
 * only planes and polytopes are meaningful in boundry space.
 *
 * some notable uses of boundry space are in describing the emulated
 * cull plane of the "camera", and as the boundries of a given room.
 */

typedef uint32_t shadowmask[CHUNK][CHUNK]
typedef tilemeta tileset[128]

struct tilemeta {
bool ladder : 1
bool solid : 1
bool liquid : 1
bool conductive : 1
bool burns : 1
bool hypotherm : 1
bool sharp : 1
bool entropy : 1

bool shiney : 1
bool slip : 1
signed speed : 2

bool freezes : 1
bool melts : 1
bool petrif : 1

bool dig : 1
bool fence : 1

intptr_t freeze : 8
intptr_t melt : 8
intptr_t stone : 8
unsigned density

bool blink : 1
unsigned color : 6

Mesh * shape
Texture2D * texture
}
/* tiles can be effected by stuff happening around them.
 *
 * if a tile is flammable, a fire is summoned when fire magic
 * enters the space or 1d6 chance if there is fire within 1 taxicab of it.
 *
 * if a tile is conductive, then electricity is summoned for the instant
 * that electrical magic strikes it, and propagates through contiguous tiles.
 *
 * if a tile can freeze, it's _8BITPTR is changed to the number indicated by ice.
 * when ice magic intersects it.
 *
 * if a tile can melt, it's _8bitPtr is changed to the number indicated by melt
 * when fire or electrical magic intersect it.
 *
 * if a tile can be petrified, it is changed to the tile indicated by stone.
 *
 * if a tile can be dug, using a ↧digging tool on it will remove it
 * digging something triggers updates which cause gravity to affect gases (!liquid,!solid),
 * liquids(+liquid,!solid), and granulars(+liquid,+solid), wherin less dense
 * tiles will swap with more dense ones. this effect travels outwards, to the edge of the room,
 * but will not be applied to the border tiles. in the default set, water has a density of 10, snow
 * has a density of -1, and air has a density of -100. 
 */

mapobjflags:
bool hidden : 1
bool moves : 1
bool rclass : 1
unsigned class : 4
unsigned alignment : 9

struct mapobjtyp:
(self) *prev
(self) *next
uuid_t uuid
ucoord3 pos
masteritemptr itemid;
extendedmetadata * data;
mapobjflags flags

struct signtyp {
Mesh * shape
Texture2D * texture
conlangtyp lang
char* lines
char* gibber
}

struct chestyp:
heldobjtyp *bag_ptr
cursetyp curse
locktype locked

struct doortyp {
bool open : 1
unsigned hp : 7
locktype lock : 8

struct locktype {
unsigned level : 4;
bool locked : 1;
unsigned pins : 7;
trapflag flags;
}
/* lockpicking requires the player to enter
 * 0 and + in the correct order to turn the
 * tumblers. in addition to making the correct
 * guess, one must make a skill check:
 * 1 in 2^(lock.level - (skill/2)) chance
 *
 * lockpicking will play an ascending chromatic
 * scale on a loop, starting on C3 and ending
 * at G3, on synthbass (triangle wave)
 */

struct encontyp {
(self) *prev
(self) *next
uuid_t uuid
uchar tobeat	//of 10D20
spawntyp spawn

struct masteritemptr {
intptr_t id : 16;
unsigned meta : 8;
unsigned n : 8;
}

struct extendedmetadata {
char * name;
void * data;
}

struct masteritemlistentry {
objid type
void * data
}

typedef struct masteritemlistentry *(*(*(*(const * masteritemlist)[16])[16])[16])[16];
//array of 16 pointers to arrays of 16 pointers to arrays of 16 pointers to arrays of 16 pointers to string-like arrays

/*to be replaced
struct miscitembasetyp:
bool key : 1
bool pick : 1
bool dig : 1
bool music : 1
bool light : 1
bool book : 1
bool spark : 1
bool quest : 1
bool fireproof : 1
bool waterproof : 1
bool elecproof : 1
bool iceproof : 1
bool stoneproof : 1
bool arrow : 1
bool poisoned : 1
bool unbreak : 1
unsigned uses : 8
intptr_t metadata : 8
*/

struct eventdatastack_uuidptr {
uuid_t uuid;
void * ptr;
}

struct eventdatastack_top {
struct eventdatastack_top * prev;
struct eventdatastack_top * next;
struct eventdatastack_sub * this;
struct eventdatastacl_uuidptr * up;	//what events depend on this one
uuid_t uuid;
unsigned cleanup[2];	//keys to a dispatch table
}

struct eventdatastack_sub {
(self)* prev;
(self)* next;
uuid_t uuid;
void * data;
size_t length;
}

union hitboxuni {
BoundingBox square
struct sphere
Vector3 geom
Ray ray
}

struct hitboxtyp {
union hitboxuni
uchar type
}

struct eventtyp:
(self) *prev
(self) *next
ucoord3 pos
uuid_t uuid
unsigned hours : 24
int (*dothis)(intptr_t,intptr_t,intptr_t,intptr_t)
bool interact : 1
bool look : 1
unsigned duration : 15
unsigned remduration : 15
Mesh * shape
Texture2D * texture

struct triggertyp {
triggerenum key : 4
unsigned value : 4
}

struct qglobev { //queued global event. can be modifications to distant rooms, or stuff like cutscenes.
(self) *prev;
(self) *next;
uuid_t parent;
ucoord4 globpos;
funcptr dothis;
bool pres;	//whether to act as soon as the room is on the stack, or if the player must be present
}

struct traptyp:
Mesh * shape
Texture2D * texture
ushort duration
magictyp element
stattyp stat
cursetyp curse
diceodds odds
trapflags flags
sensetyp sense
short hp
short mp

struct trapflags:
bool fireproof : 1
bool waterproof : 1
bool elecproof : 1
bool iceproof : 1
bool tamperproof : 1
bool stoneproof : 1
bool warded : 1
unsigned attack_alignments : 9
bool multiuse : 1
bool magic : 1	//whether the trap is a mechanism or a rune
unsigned color : 6

struct subwarptyp {
bool perm : 1
bool blink : 1
unsigned color : 6
ucoord3 pos
ucoord3 dest
short duration	//negative are uses, positive are turns
}

struct warptyp:
bool perm : 1
bool blink : 1
unsigned color : 6
ucoord4 glob_loc
ucoord3 pos
ucoord4 glob_dest
ucoord3 dest
short duration

struct gemstonetyp:
unsigned color : 5
unsigned cut : 3
unsigned quality : 8

/* to be replaced
struct meattyp:
struct racetyp race
uchar sellby
uchar amount

struct foodtyp:
intptr_t itemid : 8
intptr_t metadata : 8
unsigned sellby : 8
unsigned amount : 8

foodbasetyp:
effectyp effect
diceodds odds
uchar keepsfor	//0 means non-perishable
uchar hp
uchar nutri
*/

/* rework be a type enum for unified object table
enum objid:
WEAPON_FLAG : contains subobjtyp calling baseweaptyp
LEGEND_FLAG : contains subobjtyp calling baseweaptyp
POTION_FLAG : contains potiontyp
READ_FLAG : contains readtyp
FOOD_FLAG : contains subobjtyp containing foodtyp
MEAT_FLAG : contains subobjtyp containing meattyp
ARMOR_FLAG : contains subobjtyp calling basearmortyp
SHLD_FLAG : contains subobjtyp calling baseshldtyp
BAUB_FLAG : contains subobjtyp calling baubtyp
CONLANG_FLAG : contains conlangtyp
MISC_FLAG : contains ptrchar or ptrshort
GEM_FLAG : contains gemstonetyp
TRAP_FLAG : contains traptyp
WARP_FLAG : contains warptyp
SUBWARP_FLAG : contains subwarptyp
CHEST_FLAG : contains chestyp
DOOR_FLAG : contains doortyp
LOCK_FLAG : contains locktyp (gates are this)
MONEY_FLAG : contains float
SPAWN_FLAG : contains spawntyp
SIGN_FLAG : contains signtyp
*/

#endif
