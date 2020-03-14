/*1000*/ /* todo:
/*2000*/  * rework roomstack neighbors:
/*3000*/  * 	render all king's norm adjacent rooms
/*4000*/  *	instead of taxicab norm adjacent
/*5000*/  *	(if two different rooms are not occupying the same space)
/*6000*/  * redo language tables
/*7000*/  */
/*8000*/ 
/*9000*/ /* uuid's are used to cache dynamiclly allocated memory into the savefile;
/*10000*/  * think of them like shared pointers.
/*11000*/  */
/*12000*/ 
/*13000*/ #ifndef IWANNAFLY_TYPES_H_REENTRANT
/*14000*/ #define IWANNAFLY_TYPES_H_REENTRANT 1
/*15000*/ 
/*16000*/ /* note: if the compiler complains about mixing tightly packed and loosly packed fields,
/*17000*/  * the tightly packed ones will be split off into a seperate type with "_bits" affixed to
/*18000*/  * the name, which will be placed in a member "_bits" at the end of the struct.
/*19000*/  *
/*20000*/  * only structs that mix odd-sized members and subcontainer structs or true pointers will have this problem;
/*21000*/  * technically, even true pointers can be size-allocated if you want to maintain seperate 32 and 64 bit sources,
/*22000*/  * but I don't. debugging multiple builds from a single source will be difficult enough.
/*23000*/  */
/*24000*/ 
/*25000*/ #define uint unsigned int
/*26000*/ #define uchar unsigned char
/*27000*/ #define ushort unsigned short
/*28000*/ #define ulong unsigned long
/*29000*/ #define ptrchar uint8_t
/*30000*/ #define ptrshort uint16_t
/*31000*/ 
/*32000*/ struct stringlistyp <%
/*33000*/ (self) *prev
/*34000*/ (self) *next
/*35000*/ char* text
/*36000*/ %>
/*37000*/ /* used to store a list of strings
/*38000*/  * may be from a data object, or
/*39000*/  * stored in a tsv
/*40000*/  */
/*41000*/ 
/*42000*/ struct singlestringlistyp <%
/*43000*/ (self) * next
/*44000*/ char * text
/*45000*/ %>
/*46000*/ 
/*47000*/ struct filelinetyp {
/*48000*/ (self) *prev
/*49000*/ (self) *next
/*50000*/ ushort lineno
/*51000*/ char* text
/*52000*/ }
/*53000*/ // used by the line editor
/*54000*/ 
/*55000*/ struct singlestringlistyp {
/*56000*/ (self) * next
/*57000*/ ushort lineno
/*58000*/ char * text
/*59000*/ }
/*60000*/ 
/*61000*/ struct chaptertyp {
/*62000*/ unsigned c : 7;	//chapter number
/*63000*/ unsigned a : 9;	//alignment type
/*64000*/ }
/*65000*/ 
/*66000*/ struct turntyp {
/*67000*/ unsigned second : 6;	//mod 60
/*68000*/ unsigned mm : 6;	//mod 60
/*69000*/ unsigned hour : 5;	//mod 24
/*70000*/ unsigned timezone : 5;
/*71000*/ unsigned dayear : 9;	//mod 360
/*72000*/ unsigned weekday : 3;	//mod 7
/*73000*/ unsigned moonphase : 2;	//rollover ; solar-lunar phase shift is deferred
/*74000*/ unsigned daymonth : 5;	//mod 30
/*75000*/ unsigned month : 4;	//mod 12
/*76000*/ unsigned season : 2;	//month % 4
/*77000*/ 
/*78000*/ }
/*79000*/ /* years will start on the vernal equinox, for multiple reasons:
/*80000*/  *	- it adds to the exotic feel of the world
/*81000*/  *	- it makes more sense than some random day in the middle of winter
/*82000*/  *	->it's easier to the program the equinoxes/solstices that way
/*83000*/  */
/*84000*/ 
/*85000*/ struct sphere {
/*86000*/ Vector3 center
/*87000*/ float radius
/*88000*/ }
/*89000*/ 
/*90000*/ typedef uchar ucoord4[4];
/*91000*/ typedef uchar ucoord3[3];
/*92000*/ typedef uchar ucoord2[2];
/*93000*/ typedef char scoord4[4];
/*94000*/ typedef char scoord3[3];
/*95000*/ typedef char scoord2[2];
/*96000*/ 
/*97000*/ struct setcoord3 <%
/*98000*/ struct setcoord3 * prev;
/*99000*/ struct setcoord3 * next;
/*100000*/ uchar x;
/*101000*/ uchar y;
/*102000*/ uchar z;
/*103000*/ %>
/*104000*/ 
/*105000*/ typedef char *strarry[]
/*106000*/ typedef void *ptrarry[]
/*107000*/ 
/*108000*/ struct lightyp <%
/*109000*/ struct lightyp * prev;
/*110000*/ struct lightyp * next;
/*111000*/ ucoord2 x;
/*112000*/ ucoord2 y;
/*113000*/ ucoord2 z;
/*114000*/ %>
/*115000*/ 
/*116000*/ struct agetyp {
/*117000*/ 	unsigned chrono : 16;
/*118000*/ 	signed bio : 8;	//entity dies on overflow
/*119000*/ 	unsigned rem : 8;	// bio's remainder after chrono;
/*120000*/ 	}			/* bio increments on the next modulo0 of
/*121000*/ 				 * the entity's current aging factor
/*122000*/ 				 * (href basentyp). exploiting the
/*123000*/ 				 * immediately apparent flaw of this
/*124000*/ 				 * behavior by frequently shapeshifting
/*125000*/ 				 * is allowed; but has it's own side
/*126000*/ 				 * effects. (href shiftstackobj)
/*127000*/ 				 */
/*128000*/ 
/*129000*/ struct nibbles {
/*130000*/ unsigned lo : 4
/*131000*/ unsigned hi : 4
/*132000*/ }
/*133000*/ 
/*134000*/ struct snibbles {
/*135000*/ signed lo : 4
/*136000*/ signed hi : 4
/*137000*/ }
/*138000*/ 
/*139000*/ struct racetyp {
/*140000*/ intptr_t race : 8
/*141000*/ intptr_t table : 4
/*142000*/ unsigned meta : 4
/*143000*/ 	// 00,0,F is nul
/*144000*/ }
/*145000*/ 
/*146000*/ struct microvector {
/*147000*/ unsigned x : 2
/*148000*/ unsigned y : 2
/*149000*/ unsigned z : 2
/*150000*/ unsigned w : 2
/*151000*/ }
/*152000*/ 
/*153000*/ struct nanovector {
/*154000*/ signed x : 2
/*155000*/ signed y : 2
/*156000*/ signed z : 2
/*157000*/ signed w : 2
/*158000*/ }
/*159000*/ 
/*160000*/ typedef char *pluralwords[3];
/*161000*/ 
/*162000*/ #define MOVETOKEN_ICE 8
/*163000*/ #define MOVETOKEN_LAND 4
/*164000*/ #define MOVETOKEN_FLY 1
/*165000*/ #define MOVETOKEN_SWIM 2
/*166000*/ 
/*167000*/ struct selftyp {
/*168000*/ unsigned az : 3	//yaw in eighth turns
/*169000*/ unsigned phi : 3	//polar angle in eighth turns
/*170000*/ unsigned movetoken : 4
/*171000*/ unsigned gravdir : 5	//changes the up vector, must be a valid octant
/*172000*/ bool weightless : 1
/*173000*/ }
/*174000*/ 
/*175000*/ struct beamtyp {
/*176000*/ unsigned az : 3	//azimuth
/*177000*/ unsigned phi : 3	//elevation in eighth turns. 07 is omnidirectional.
/*178000*/ unsigned ang : 4	//total solid angle of spread in twelfths of a circle.
/*179000*/ unsigned range : 6
/*180000*/ }
/*181000*/ /* for all azimuths:
/*182000*/  *
/*183000*/  * 701
/*184000*/  * 6 2
/*185000*/  * 543
/*186000*/  *
/*187000*/  * for all elevations:
/*188000*/  *
/*189000*/  * +1
/*190000*/  *  0  ?-2?
/*191000*/  * -1
/*192000*/  */
/*193000*/ 
/*194000*/ struct diceodds:
/*195000*/ unsigned num : 3
/*196000*/ unsigned side : 5
/*197000*/ unsigned tobeat : 8
/*198000*/ 
/*199000*/ struct planetyp {
/*200000*/ bool shadow : 1
/*201000*/ unsigned rho : 2
/*202000*/ unsigned az : 3
/*203000*/ signed el : 2
/*204000*/ }
/*205000*/ 
/*206000*/ /* if the poles of a sphere are unaccessible, it may be cylindrically
/*207000*/  * projected; otherwise, it must be cube mapped
/*208000*/  *
/*209000*/  * rho 0 is the prime plane
/*210000*/  * rho 1 are the elemental planes
/*211000*/  * rho 2 are afterlives
/*212000*/  * rho 3 can be used for areas that are meant to not show up on a map.
/*213000*/  *			(said map would be implemented with pipes)
/*214000*/  *
/*215000*/  * az	elemental	afterlife	corrilation
/*216000*/  * 0	water		neutral good	nurturer
/*217000*/  * 1	ice		chaotic good	the ends justify the means
/*218000*/  * 2	air		chaotic neutral	insert obscure fourswords reference here
/*219000*/  * 3	electricity	chaotic evil	force lightning
/*220000*/  * 4	fire		neutral evil	obviously
/*221000*/  * 5	metal		lawful evil	greed
/*222000*/  * 6	earth		lawful neutral	stubborn
/*223000*/  * 7	trees		lawful good	knowladge
/*224000*/  *
/*225000*/  * az rotates by 45 degree steps and el by 90 degree steps.
/*226000*/  * a nonzero el causes az to gimbal lock.
/*227000*/  * also best not to think about where exactly -2 is pointing.
/*228000*/  *
/*229000*/  * el	"		"		"
/*230000*/  * +1	light		true neutral	enlightenment
/*231000*/  * -1	darkness	uncomitted	meh, I'll think of one later
/*232000*/  * -2	entropy		oathbreakers	abandon all hope ye who enter here
/*233000*/  *
/*234000*/  * errors related to this section may generate one of 2 errors:
/*235000*/  * "fell off the edge of the world", N1=±lat,N2=±lon
/*236000*/  * "froze to death on pluto", N1=+az,N2=±el
/*237000*/  *
/*238000*/  * a room stack exists that keeps a number of rooms loaded
/*239000*/  * if a room is not on the stack, it is loaded from the save file and
/*240000*/  * pushed to the stack. this may cause the stack to intentionally drop
/*241000*/  * the room at the bottom to prevent eating too much ram. if the file
/*242000*/  * does not yet exist, the room is generated according to a dispatch table
/*243000*/  * in a shared object. if the function and file are both NULL and the
/*244000*/  * room is being entered, a lost in space death is called. if only the
/*245000*/  * function is NULL, the file is executed in perl. if only the file is
/*246000*/  * NULL, no shared objects are loaded before the function is called. 
/*247000*/  *
/*248000*/  * a swap array keeps track of gating between the 23 major planes,
/*249000*/  * saving the player's position, but not keeping the room loaded.
/*250000*/  */
/*251000*/ 
/*252000*/ struct placetyp {
/*253000*/ (self) *prev
/*254000*/ (self) *next
/*255000*/ uuid_t uuid
/*256000*/ char* name
/*257000*/ ucoord4 globpos
/*258000*/ planetyp plane
/*259000*/ Vector2 latlon
/*260000*/ ucoord3 pos
/*261000*/ }
/*262000*/ 
/*263000*/ typedef float trackaligntyp[2]
/*264000*/ typedef float trackalignplayertyp[3]
/*265000*/ /* alignments satisfy the equasion { x^2 + y^2 ≤ 1000^2 }
/*266000*/  * neutral is the area satisfying { x^2 + y^2 ≤ 100^2 }
/*267000*/  * other alignments are deternmined by lines extending at the following
/*268000*/  * azimuths: 30, 60, 120, 150, -150, -120, -60, -30 (use atan2)
/*269000*/  * corner cases round twords a cardinal direction
/*270000*/  *	
/*271000*/  * actions, quests, and being polymorphed into
/*272000*/  * certain monsters can alter your alignment
/*273000*/  * [0] is {+good,-evil}, [1] is {+lawful,-chaotic}
/*274000*/  *
/*275000*/  * for players, proactivness/passivity is also
/*276000*/  * tracked
/*277000*/  */
/*278000*/ 
/*279000*/ struct ray_vfx_typ {
/*280000*/ (self) * prev
/*281000*/ (self) * next
/*282000*/ Ray this
/*283000*/ Color color
/*284000*/ }
/*285000*/ 
/*286000*/ struct multiclasstyp:
/*287000*/ (self) *prev
/*288000*/ (self) *next
/*289000*/ bool notnull : 1
/*290000*/ unsigned role : 2
/*291000*/ unsigned class : 3
/*292000*/ unsigned mastery : 2
/*293000*/ 
/*294000*/ struct classtyp {
/*295000*/ bool notnull : 1
/*296000*/ unsigned role : 2
/*297000*/ unsigned class : 3
/*298000*/ unsigned mastery : 2
/*299000*/ }
/*300000*/ 
/*301000*/ struct baseclasstyp {
/*302000*/ struct paffectyp bonus
/*303000*/ uchar spd
/*304000*/ char airspd
/*305000*/ uchar air
/*306000*/ struct conlangtyp lang
/*307000*/ cantriptyp spell[2]
/*308000*/ bool mindless : 1
/*309000*/ bool shadow : 1
/*310000*/ bool incoporeal : 1
/*311000*/ bool immortal : 1
/*312000*/ unsigned lde : 3	//grants
/*313000*/ unsigned alignment : 9	//requires
/*314000*/ unsigned element : 8	//grants
/*315000*/ }
/*316000*/ 
/*317000*/ struct the8stats:	//8* 5D6
/*318000*/ stren : u5
/*319000*/ psy : u5
/*320000*/ dex : u5
/*321000*/ con : u5
/*322000*/ fort : u5
/*323000*/ intl : u5
/*324000*/ wis : u5
/*325000*/ bluff : u5
/*326000*/ struct movelimit {
/*327000*/ float spd
/*328000*/ float airspd
/*329000*/ float watspd
/*330000*/ uchar lung
/*331000*/ uchar wing
/*332000*/ }
/*333000*/ 
/*334000*/ struct movecount {
/*335000*/ float spd //added to move each turn
/*336000*/ float airspd	/* if this is negative, then it's value is immediately
/*337000*/ 		 * subtracted from move whenever flying is attempted.
/*338000*/ 		 * otherwise, added to fly each turn
/*339000*/ 		 */
/*340000*/ float watspd //ditto but added to swim
/*341000*/ float move //value is capped at 2*spd
/*342000*/ float fly 	/* carries the extra moves that can be used in the air;
/*343000*/ 		 * they are used first when applicable
/*344000*/ 		 */
/*345000*/ float swim //ditto but used in water
/*346000*/ ucoord3 skillgain	/* [0] = ground, [1] = water, [2] = air.
/*347000*/ 			 * when these overflow, a skill level is
/*348000*/ 			 * gained if applicable.
/*349000*/ 			 */
/*350000*/ ucoord2 lung //number of turns that you can go without air.
/*351000*/ ucoord2 wing //number of turns left before you fall
/*352000*/ }
/*353000*/ 
/*354000*/ struct conlangtype:
/*355000*/ unsigned id : 5
/*356000*/ bool r : 1
/*357000*/ bool w : 1
/*358000*/ bool x : 1
/*359000*/ 
/*360000*/ struct xtraplayertyp {
/*361000*/ uuid_t partyid;	//the folder in the savefile to save to
/*362000*/ chaptertyp chapter;
/*363000*/ uint64_t kills;
/*364000*/ uchar elecollect[8];
/*365000*/ uchar questcollect[3];
/*366000*/ bagitemptr * bag;
/*367000*/ walletyp wallet;
/*368000*/ turntyp date;
/*369000*/ uint64_t turn;
/*370000*/ ushort roomturn;
/*371000*/ }
/*372000*/ 
/*373000*/ /* note: everything related to players and entitys is
/*374000*/  * copied into the struct, because it might be changed.
/*375000*/  * the base entities and base classes are only templates.
/*376000*/  *
/*377000*/  * whenever you "rest" in-game, all entities are re-verified;
/*378000*/  * meaning that all effect registers are recalculated. this
/*379000*/  * has the side effect of removing any non-item based buffs
/*380000*/  * and debuffs. this should be one of the only times that
/*381000*/  * a baseclasstyp or basentyp are referenced; the others
/*382000*/  * being adding a class, looseing a class, advancing in a class,
/*383000*/  * polymorphing, polylocking, by the renderer,
/*384000*/  * and when spawning a new entity.
/*385000*/  *
/*386000*/  * some stats are spread out accross multiple fields in the structure;
/*387000*/  * most effects have one field for permenant and one field for temporary
/*388000*/  * versions of the effect. a handful of alteration spells have a third
/*389000*/  * register, with the polymorph stack, for timed spells, since the
/*390000*/  * other temporary slot has no timer.
/*391000*/  *
/*392000*/  * nearly all fields of the player struct are created by COMBINING the
/*393000*/  * basentyp and baseclasstyp chosen at the creation of the savefile.
/*394000*/  * the remainder are based on backstory and user input.
/*395000*/  */
/*396000*/ 
/*397000*/ walletyp {
/*398000*/ unsigned whole : 25
/*399000*/ unsigned cent : 7
/*400000*/ }
/*401000*/ 
/*402000*/ struct playertyp:
/*403000*/ playertyp * prev
/*404000*/ playertyp * next
/*405000*/ char * name
/*406000*/ ushort storyseed	//the story entrypoint for this player
/*407000*/ uuid_t root	//the uuid for this player's story; should they die, everything with this uuid as a parent is garbage collected
/*408000*/ classtyp class[3]
/*409000*/ uchar element
/*410000*/ agetyp age
/*411000*/ struct shiftstackobj race
/*412000*/ ucoord3 pos
/*413000*/ selftyp etc
/*414000*/ struct movecount move
/*415000*/ paffectyp paffect	//permenant
/*416000*/ effectyp effect	//from equipment
/*417000*/ trackalignplayertyp align
/*418000*/ ushort hp	//they're fun and easy to...wait
/*419000*/ ushort mp
/*420000*/ uint32_t xp
/*421000*/ uchar lvl
/*422000*/ Vector2 hunger
/*423000*/ langlistele *lang_ptr
/*424000*/ spellistele *spell_ptr
/*425000*/ cantriplistele *cant_ptr
/*426000*/ helditemtyp helm	//any item
/*427000*/ helditemtyp shield	//shld
/*428000*/ helditemtyp bow	//weapon
/*429000*/ helditemtyp armor	//armor
/*430000*/ helditemtyp cape	//armor
/*431000*/ helditemtyp amul	//baub
/*432000*/ unsigned n_arms : 4
/*433000*/ unsigned n_legs : 4
/*434000*/ armtyp * arms
/*435000*/ legtyp * legs
/*436000*/ 
/*437000*/ struct armtyp {
/*438000*/ struct armtyp * next
/*439000*/ helditemtyp weap[2]
/*440000*/ helditemtyp ring[2]
/*441000*/ helditemtyp wrist[2]
/*442000*/ helditemtyp gloves
/*443000*/ helditemtyp cannon
/*444000*/ }
/*445000*/ 
/*446000*/ struct legtyp {
/*447000*/ legtyp * next
/*448000*/ helditemtyp boots
/*449000*/ helditemtyp greev
/*450000*/ }
/*451000*/ 
/*452000*/ enum equipenum = {ENUM_WEAP_LEFT,ENUM_WEAP_RIGHT,ENUM_SHIELD_ENUM_BOW,ENUM_ARMOR,ENUM_CAPE,ENUM_HELM,
/*453000*/ ENUM_GLOVES,ENUM_CANNON,ENUM_BOOTS,ENUM_GREEV,ENUM_AMUL,ENUM_RING_LEFT,ENUM_RING_RIGHT,ENUM_WRIST_LEFT,
/*454000*/ ENUM_WRIST_RIGHT}
/*455000*/ 
/*456000*/ struct basentyp:
/*457000*/ aggrotyp aggro	//here, shiftable denotes a monster's aggro state is locked. also gives the value that patience is set to when a monster calms down, the value that cooldown is set to when it is angered, and the default AI.
/*458000*/ paffectyp base
/*459000*/ struct movelimit move
/*460000*/ unsigned n_arms : 4
/*461000*/ unsigned n_legs : 4
/*462000*/ uchar hplvl
/*463000*/ uchar mplvl
/*464000*/ uchar xplvl
/*465000*/ struct conlangtyp lang[2]
/*466000*/ spelltyp spell[4]
/*467000*/ Mesh * shape
/*468000*/ Texture2D * texture
/*469000*/ signed size : 2
/*470000*/ bool mindless : 1
/*471000*/ bool shadow : 1
/*472000*/ bool incoporeal : 1
/*473000*/ unsigned age_rate : 8
/*474000*/ unsigned element : 8
/*475000*/ unsigned lde : 3
/*476000*/ float hunger
/*477000*/ /* entitys of size 1 or -2 cannot use armor.
/*478000*/  * entitys of larger size automaticly win grapples.
/*479000*/  * entitys of 2 sizes smaller can be picked up and thrown.
/*480000*/  * entitys of size 1 can instakill entitys of size -2. squish.
/*481000*/  * size 1: dragon, size 0: human, size -1: dwarf, size -2: pixie
/*482000*/  */
/*483000*/ 
/*484000*/ struct aggrotyp:
/*485000*/ bool unhinged : 1
/*486000*/ unsigned patience : 3
/*487000*/ unsigned ai_type : 4
/*488000*/ unsigned anger : 8
/*489000*/ 
/*490000*/ struct enttyp:
/*491000*/ (self) *prev
/*492000*/ (self) *next
/*493000*/ npctyp * depth
/*494000*/ agetyp age
/*495000*/ classtyp class
/*496000*/ uchar element
/*497000*/ aggrotyp aggro
/*498000*/ struct shiftstackobj race
/*499000*/ ucoord3 pos
/*500000*/ selftyp etc
/*501000*/ struct movecount move
/*502000*/ paffectyp paffect
/*503000*/ effectyp effect
/*504000*/ ushort hp
/*505000*/ ushort mp
/*506000*/ uint32_t xp
/*507000*/ uchar lvl
/*508000*/ float wallet
/*509000*/ spellistele *spell_ptr
/*510000*/ cantriplistele *cant_ptr
/*511000*/ helditemtyp loot
/*512000*/ helditemtyp helm
/*513000*/ helditemtyp shield
/*514000*/ helditemtyp bow
/*515000*/ helditemtyp armor
/*516000*/ helditemtyp cape
/*517000*/ helditemtyp amul
/*518000*/ unsigned n_arms : 4
/*519000*/ unsigned n_legs : 4
/*520000*/ armtyp * arms
/*521000*/ legtyp * legs
/*522000*/ 
/*523000*/ struct npctyp {
/*524000*/ (self) *prev
/*525000*/ (self) *next
/*526000*/ ucoord3 * path
/*527000*/ char * describe
/*528000*/ uchar lang
/*529000*/ char **lines[9];	//accessor: (lines[n])[m]
/*530000*/ }
/*531000*/ /* npc data is controlled by events, and is stored by room or in
/*532000*/  * global space. more complex actors, such as shopkeepers,
/*533000*/  * should be events.
/*534000*/  */
/*535000*/ 
/*536000*/ 
/*537000*/ struct spawntyp:
/*538000*/ npctyp * depth
/*539000*/ classtyp class
/*540000*/ uchar element
/*541000*/ aggrotyp aggro
/*542000*/ struct shiftstackobj race
/*543000*/ paffectyp paffect
/*544000*/ effectyp effect
/*545000*/ helditemtyp loot
/*546000*/ helditemtyp helm
/*547000*/ helditemtyp shield
/*548000*/ helditemtyp bow
/*549000*/ helditemtyp armor
/*550000*/ helditemtyp cape
/*551000*/ helditemtyp amul
/*552000*/ unsigned n_arms : 4
/*553000*/ unsigned n_legs : 4
/*554000*/ armtyp * arms
/*555000*/ legtyp * legs
/*556000*/ 
/*557000*/ struct helditemtyp {
/*558000*/ masteritemptr itemid;
/*559000*/ uuid_t uuid;	//the null uuid for no extended metadata
/*560000*/ extendedmetadata * data;	//the null pointer for no extended metadata
/*561000*/ }
/*562000*/ 
/*563000*/ struct bagitemtyp:
/*564000*/ (self) *prev
/*565000*/ (self) *next
/*566000*/ masteritemptr itemid;
/*567000*/ extendedmetadata * data;
/*568000*/ 
/*569000*/ struct langlistele {
/*570000*/ (self) * prev
/*571000*/ (self) * next
/*572000*/ struct conlangtyp data
/*573000*/ }
/*574000*/ 
/*575000*/ struct spellistele {
/*576000*/ (self) * prev
/*577000*/ (self) * next
/*578000*/ spelltyp this
/*579000*/ }
/*580000*/ 
/*581000*/ struct cantriplistele {
/*582000*/ (self) * prev
/*583000*/ (self) * next
/*584000*/ cantriptyp this
/*585000*/ }
/*586000*/ 
/*587000*/ /*replace
/*588000*/ struct subobjtyp:
/*589000*/ intptr_t itemid : 8
/*590000*/ bool cursed : 1
/*591000*/ bool oxide : 1
/*592000*/ bool burned : 1
/*593000*/ signed bonus : 5
/*594000*/ intptr_t metadata : 8 //secondary _8bitPtr for legendary objects
/*595000*/ */
/*596000*/ 
/*597000*/ struct magictyp:
/*598000*/ bool fire : 1
/*599000*/ bool air : 1
/*600000*/ bool water : 1
/*601000*/ bool earth : 1
/*602000*/ unsigned lde : 3
/*603000*/ bool planer : 1
/*604000*/ 
/*605000*/ struct shiftstackobj {
/*606000*/ bool topdeck : 1; //does every shift change base[0]?
/*607000*/ bool lycan : 1;	//is base[1] valid?
/*608000*/ bool swap : 1 //base[swap]
/*609000*/ signed depth : 5;	//on overflow, the stack is freed an topdeck is set
/*610000*/ struct racetyp base[2];
/*611000*/ struct shiftstackele * poly;	//unless this is NULL, this overrides base[]
/*612000*/ struct shiftertyp alters;
/*613000*/ }
/*614000*/ 
/*615000*/ struct shiftstackele {
/*616000*/ struct shiftstackele * prev;
/*617000*/ unsigned polytimer : 8;	//time remaining in the current polymorph.
/*618000*/ intptr_t race : 8;
/*619000*/ intptr_t table : 4;
/*620000*/ unsigned meta : 4;
/*621000*/ }/* polymorphing to the same form twice causes your active base form to change.
/*622000*/   * some ways of aquireing multi-form abilities may place restrictions on what your second form may be.
/*623000*/   */
/*624000*/ 
/*625000*/ struct altertimertyp {
/*626000*/ 	signed n : 5;	//permenant on overflow
/*627000*/ 	bool q : 1;
/*628000*/ 	char : 0;
/*629000*/ 	unsigned t : 8;
/*630000*/ 	}
/*631000*/ 
/*632000*/ struct altertimerwtyp {
/*633000*/ 	signed n : 5;	//permenant on overflow
/*634000*/ 	bool q : 1;
/*635000*/ 	unsigned w_typ : 2;
/*636000*/ 	bool w_sgn : 1;
/*637000*/ 	unsigned t : 7;
/*638000*/ 	}
/*639000*/ 
/*640000*/ struct shiftertyp {
/*641000*/ struct altertimertyp gills;	//using an alteration spell, including intrensics from polymorph spells, 10 times will make them permenent.
/*642000*/ struct altertimertyp lungs;	//these counters can be reset by rest or spells
/*643000*/ struct altertimerwtyp wings;
/*644000*/ struct altertimertyp tail;
/*645000*/ struct altertimertyp claws;
/*646000*/ struct altertimertyp fangs;
/*647000*/ struct altertimertyp talons;
/*648000*/ }/* non-player, non-follower entitys do not have this field,
/*649000*/   * and any polymorph or alteration is permenent. this may be
/*650000*/   * changed in future if memory footprint allows.
/*651000*/   */
/*652000*/ 
/*653000*/ struct cantriptyp {
/*654000*/ funcptr spell;
/*655000*/ diceodds odds;
/*656000*/ uchar prof;
/*657000*/ char cost_typ : 2 //0 = at will, 1 = gold, -1 = mp, -2 = hp
/*658000*/ unsigned cost_amnt : 6
/*659000*/ }
/*660000*/ 
/*661000*/ struct spelltyp {
/*662000*/ basespelltyp * spell;
/*663000*/ diceodds odds;
/*664000*/ uchar prof;
/*665000*/ char cost_typ : 2 //0 = at will, 1 = gold, -1 = mp, -2 = hp
/*666000*/ unsigned cost_amnt : 6
/*667000*/ }
/*668000*/ 
/*669000*/ typedef int (*funcptr)();
/*670000*/ typedef int (*funcptr_1arg)(intptr_t);
/*671000*/ typedef int (*funcptr_2arg)(intptr_t,intptr_t);
/*672000*/ typedef int (*funcptr_3arg)(intptr_t,intptr_t,intptr_t);
/*673000*/ typedef int (*funcptr_4arg)(intptr_t,intptr_t,intptr_t,intptr_t);
/*674000*/ typedef int (*funcptr_multi)(uint,intptr_t*);
/*675000*/ typedef int (*eventcleanup)(eventdatastack_ele,bool);
/*676000*/ 
/*677000*/ struct trampolinestackele {
/*678000*/ struct trampolinestackele * prev;
/*679000*/ funcptr exec;
/*680000*/ }
/*681000*/ 
/*682000*/ struct passiveffectlistele {
/*683000*/ struct passiveffectlistele * prev;
/*684000*/ struct passiveffectlistele * next;
/*685000*/ funcptr whenthis;
/*686000*/ funcptr dothis;
/*687000*/ funcptr undothis;
/*688000*/ intptr_t statedata;
/*689000*/ }
/*690000*/ 
/*691000*/ struct basespelltyp:
/*692000*/ unsigned lvl : 6
/*693000*/ char : 0
/*694000*/ magictyp type
/*695000*/ potiontyp effect
/*696000*/ missiletyp delivery
/*697000*/ 
/*698000*/ struct missiletyp {
/*699000*/ bool vamp : 1
/*700000*/ unsigned damage : 7
/*701000*/ signed recoil : 8
/*702000*/ float range;
/*703000*/ float spread;
/*704000*/ float splash;
/*705000*/ }
/*706000*/ 
/*707000*/ struct baseweaptyp:
/*708000*/ bool fire : 1
/*709000*/ bool air : 1
/*710000*/ bool water : 1
/*711000*/ bool earth : 1
/*712000*/ bool entro : 1
/*713000*/ bool light : 1
/*714000*/ bool dark : 1
/*715000*/ bool fireproof : 1
/*716000*/ bool waterproof : 1
/*717000*/ bool elecproof : 1
/*718000*/ bool iceproof : 1
/*719000*/ bool warded : 1
/*720000*/ bool illum : 1
/*721000*/ unsigned skill : 3
/*722000*/ unsigned damage : 8
/*723000*/ 
/*724000*/ legendtyp:
/*725000*/ paffectyp magic
/*726000*/ symtableref base
/*727000*/ symtableref spell
/*728000*/ legendflagtyp flags
/*729000*/ 
/*730000*/ legendflagtyp:
/*731000*/ bool fire : 1
/*732000*/ bool air : 1
/*733000*/ bool water : 1
/*734000*/ bool earth : 1
/*735000*/ bool entro : 1
/*736000*/ bool light : 1
/*737000*/ bool dark : 1
/*738000*/ bool fireproof : 1
/*739000*/ bool waterproof : 1
/*740000*/ bool elecproof : 1
/*741000*/ bool iceproof : 1
/*742000*/ bool warded : 1
/*743000*/ bool unbreak : 1
/*744000*/ bool infinate : 1
/*745000*/ bool spelled : 1
/*746000*/ bool vamp : 1
/*747000*/ bool drain : 1
/*748000*/ bool interest : 1
/*749000*/ bool useless : 1
/*750000*/ unsigned powermag : 5
/*751000*/ 
/*752000*/ struct basearmortyp:
/*753000*/ effectyp effect
/*754000*/ uchar def
/*755000*/ uchar spdef
/*756000*/ uchar extfort
/*757000*/ 
/*758000*/ struct baseshldtyp:
/*759000*/ bool fireproof : 1
/*760000*/ bool waterproof : 1
/*761000*/ bool elecproof : 1
/*762000*/ bool iceproof : 1
/*763000*/ bool reflect : 1
/*764000*/ bool entro : 1
/*765000*/ bool light : 1
/*766000*/ bool dark : 1
/*767000*/ effectyp effect
/*768000*/ unsigned def : 8
/*769000*/ unsigned spdef : 8
/*770000*/ 
/*771000*/ struct bodytyp {
/*772000*/ bool gills : 1;	//affects breathing underwater
/*773000*/ bool wings : 1;	//affects flying
/*774000*/ bool tail : 1;	//affects unarmed attacks, swimming, flying
/*775000*/ bool claws : 1;	//affects unarmed attacks, writing
/*776000*/ bool hoof : 1;	//affects walking, swimming, unarmed attacks
/*777000*/ bool talon : 1;	//affects walking, swimming, unarmed attacks 
/*778000*/ bool fangs : 1;	//affects unarmed attacks
/*779000*/ bool legs : 1;	//affects walking, swimming, unarmed attacks
/*780000*/ bool arms : 1;	//affects walking, swimming, unarmed attacks, writing
/*781000*/ bool nolungs : 1;	//affects breathing above water
/*782000*/ bool noswim : 1;	//affects swimming
/*783000*/ bool nofly : 1;
/*784000*/ bool atktail : 1;	//affects unarmed attacks, swimming, flying
/*785000*/ bool atkwing : 1;	//affects unarmed attacks, swimming, flying
/*786000*/ bool bite : 1;
/*787000*/ bool breath : 1;
/*788000*/ bool engulf : 1;
/*789000*/ bool permwings : 1;
/*790000*/ bool wingsign : 1;
/*791000*/ unsigned wingtype : 2;
/*792000*/ char : 0;
/*793000*/ }
/*794000*/ 
/*795000*/ struct stattyp {
/*796000*/ unsigned dizzy : 3;
/*797000*/ unsigned psn : 4;
/*798000*/ unsigned prlz : 4;
/*799000*/ unsigned frz : 4;
/*800000*/ unsigned brn : 4;
/*801000*/ signed stone : 8;	//inverse one's complement; 0x00 is inactive (-0), 0xFF is dead (+0). overflows can be used to extend time to live
/*802000*/ signed slime : 8;	//inverse one's complement
/*803000*/ unsigned slp : 8;
/*804000*/ unsigned invis : 6;
/*805000*/ unsigned blind : 8;
/*806000*/ signed eaten : 7;	//inverse one's complement
/*807000*/ }
/*808000*/ 
/*809000*/ struct elixtyp:
/*810000*/ dizzy : 1
/*811000*/ psn : 1
/*812000*/ prlz : 1
/*813000*/ frz : 1
/*814000*/ brn : 1
/*815000*/ stone : 1
/*816000*/ slp : 1
/*817000*/ invis : 1
/*818000*/ 
/*819000*/ struct cursetyp:
/*820000*/ stattyp type
/*821000*/ uchar polytimer
/*822000*/ intptr_t poly : 8
/*823000*/ 
/*824000*/ struct resistyp:
/*825000*/ bool fireproof : 1
/*826000*/ bool waterproof : 1
/*827000*/ bool elecproof : 1
/*828000*/ bool iceproof : 1
/*829000*/ bool stoneproof : 1
/*830000*/ bool polyproof : 1
/*831000*/ bool sleepproof : 1
/*832000*/ bool poisonproof : 1
/*833000*/ 
/*834000*/ struct sensetyp:
/*835000*/ bool trouble : 1
/*836000*/ bool invis : 1
/*837000*/ bool infra : 1
/*838000*/ bool blind : 1
/*839000*/ bool good : 1
/*840000*/ bool evil : 1
/*841000*/ bool law : 1
/*842000*/ bool chaos : 1
/*843000*/ 
/*844000*/ struct effectyp:
/*845000*/ the8stats eight
/*846000*/ bodytyp shape
/*847000*/ stattyp stat
/*848000*/ resistyp resist
/*849000*/ sensetyp sense
/*850000*/ skilltyp skill
/*851000*/ char atk
/*852000*/ char spatk
/*853000*/ char def
/*854000*/ char spdef
/*855000*/ 
/*856000*/ struct paffectyp:
/*857000*/ the8stats eight
/*858000*/ bodytyp shape
/*859000*/ elixtyp ails_ya
/*860000*/ resistyp resist
/*861000*/ sensetyp sense
/*862000*/ skilltyp skill
/*863000*/ venomtyp venom
/*864000*/ char atk
/*865000*/ char spatk
/*866000*/ char def
/*867000*/ char spdef
/*868000*/ 
/*869000*/ struct potiontyp:
/*870000*/ bodytyp shape
/*871000*/ elixtyp ails_ya
/*872000*/ cursetyp curse
/*873000*/ resistyp resist
/*874000*/ sensetyp sense
/*875000*/ short hp
/*876000*/ short mp
/*877000*/ diceodds odds
/*878000*/ 
/*879000*/ struct skilltyp {
/*880000*/ unsigned sword : 4; //+skill to sword-type weapon attack
/*881000*/ unsigned knife : 4; //+skill to knife-type weapon attack
/*882000*/ unsigned stave : 4; //+skill to stave-type weapon attack
/*883000*/ unsigned spear : 4; //+skill to spear-type weapon attack
/*884000*/ unsigned whip : 4; //+skill to whip-type weapon range (unused range added to attack)
/*885000*/ unsigned club : 4; //+skill to club-type weapon attack
/*886000*/ unsigned bow : 4; //+(2 * skill) to bow-type weapon range
/*887000*/ unsigned throw : 4; //+(2 * skill) to javalin-type weapon range
/*888000*/ unsigned monk : 4; //+(2*skill) to unarmed attack, unlocks more modes of attack.
/*889000*/ unsigned shield : 4; //skill in (damage-defense)+abs(damage-defense) chance of blocking
/*890000*/ unsigned locks : 4; //1 in 2^(lock.level - (skill)) chance of picking
/*891000*/ unsigned caster : 6; //-(skill-1)/4 to casting cost, +(skill-1)/4 to spatk and spdef, unlocks spells, 0 is non-caster
/*892000*/ bool swim : 1; //may be lost by polymorphing to a form with different locomotion.
/*893000*/ bool walk : 1; //may be lost by polymorphing to a form with different locomotion.
/*894000*/ unsigned fly : 2; //0 = never had wings, 1 = slow falling, 2 = cannot gain altitude, 3 = free flight. lvl1 learned by falling
/*895000*/ bool sink : 1; //overrides any swim or fly skills
/*896000*/ bool magnetic : 1;
/*897000*/ }
/*898000*/ /* damage = MAX( incoming-defense , 0 )
/*899000*/  *
/*900000*/  * polyshock = base.hplvl - ((poly.hplvl * (util__roll(1,20,1) / 20)) * util__roll(1,3,0))
/*901000*/  * ⎧if n < -HPMAX     : Instakill (deathmessage: miscalculated a crucial equivilant-exchange parameter,hath choose...poorly)
/*902000*/  * ⎪if n = -HPMAX     : Stoning
/*903000*/  * ⎨if -HPMAX < n < 0 : abs(n) Damage (deathmessage: could not withstand the cost of transmutation)
/*904000*/  * ⎪if n = 0          : stun for 1D16 (standardmessage: your mind reels from the transformation...)
/*905000*/  * ⎩if n > 0          : success
/*906000*/  *
/*907000*/  * writing =
/*908000*/  * succeed if 4D6 < dex if !talons, break pen on fail if 1D20 < stren
/*909000*/  * succeed if 6D6 < dex if talons, break pen on fail if coinflip
/*910000*/  * talons can engrave without tools
/*911000*/  */
/*912000*/ 
/*913000*/ readtyp:
/*914000*/ unsigned locale : 6
/*915000*/ bool multiuse : 1
/*916000*/ bool scroll : 1
/*917000*/ unsigned subject : 2 //0 = cooking, 1 = weapons, 2 = language, 3 = spellcraft
/*918000*/ unsigned uses : 6
/*919000*/ void* contents
/*920000*/ 
/*921000*/ wandtyp:
/*922000*/ unsigned matter : 4
/*923000*/ unsigned uses : 4
/*924000*/ intptr_t bound : 8
/*925000*/ 
/*926000*/ baubtype :
/*927000*/ signed type : 2 //0=ring, 1=bracelet, -1=amulet, -2=tiara
/*928000*/ unsigned matter : 3
/*929000*/ unsigned color : 3
/*930000*/ paffectyp enchnt
/*931000*/ 
/*932000*/ struct roomneighbors {
/*933000*/ ucoord4 * north
/*934000*/ ucoord4 * south
/*935000*/ ucoord4 * east
/*936000*/ ucoord4 * west
/*937000*/ ucoord4 * up
/*938000*/ ucoord4 * down
/*939000*/ microvector * north_offset
/*940000*/ microvector * south_offset
/*941000*/ microvector * east_offset
/*942000*/ microvector * west_offset
/*943000*/ microvector * up_offset
/*944000*/ microvector * down_offset
/*945000*/ bool upstair : 1
/*946000*/ bool downstair : 1
/*947000*/ bool show_north : 1
/*948000*/ bool show_south : 1
/*949000*/ bool show_east : 1
/*950000*/ bool show_west : 1
/*951000*/ bool show_up : 1
/*952000*/ bool show_down : 1
/*953000*/ }
/*954000*/ 
/*955000*/ struct chunktyp {
/*956000*/ char* tiledata[CHUNK][CHUNK][CHUNK]
/*957000*/ shadowmask * seen
/*958000*/ shadowmask * light
/*959000*/ shadowmask * collimap	//entity collision mask
/*960000*/ }
/*961000*/ 
/*962000*/ struct roomtyp:
/*963000*/ ucoord4 globpos
/*964000*/ struct planetyp plane
/*965000*/ Vector3 latlon	//reported as the latitude, longitude, and elevation of the current room. NaN may be helpful.
/*966000*/ intptr_t area : 16 //the name of the area from a table of names
/*967000*/ tileset *hightiles
/*968000*/ struct chunktyp * chunks
/*969000*/ struct microvector size //field w has no effect, other fields bias +1
/*970000*/ encontyp *encon_ptr
/*971000*/ enttyp *ent_ptr
/*972000*/ eventtyp *ev_ptr
/*973000*/ mapobjtyp *obj_ptr
/*974000*/ ray_vfx_typ *ray_ptr
/*975000*/ lightyp *light_ptr
/*976000*/ ucoord3 ** path_ptr
/*977000*/ ucoord2 downstair
/*978000*/ ucoord2 upstair
/*979000*/ ucoord3 home
/*980000*/ char filltile
/*981000*/ bool visited : 1
/*982000*/ unsigned meta : 7
/*983000*/ struct roomneighbors neighborhood
/*984000*/ /* if invalid coords are given for a warp (typically {$FF,$FF}),
/*985000*/  * then the player is dumped at the location indicated by home.
/*986000*/  *
/*987000*/  * if the player has invalid coords, then the error string "fell out of terminal",N1=x,N2=y is generated.
/*988000*/  */
/*989000*/ 
/*990000*/ /* the world of the game will be referred to using two different grids of
/*991000*/  * discreet coordinates. the primary grid is the cell space, which is
/*992000*/  * interleaved octohedrally with the boundry space, such that if a given
/*993000*/  * diminsion in cell space has n points, the same dimension in boundry
/*994000*/  * space has n+1 points. the cell space referes to the cells that are
/*995000*/  * displayed (the "cells"), while the boundry space referes to their
/*996000*/  * boundries. exact boundry space coordinates are not expected to be used;
/*997000*/  * only planes and polytopes are meaningful in boundry space.
/*998000*/  *
/*999000*/  * some notable uses of boundry space are in describing the emulated
/*1000000*/  * cull plane of the "camera", and as the boundries of a given room.
/*1001000*/  */
/*1002000*/ 
/*1003000*/ typedef uint32_t shadowmask[CHUNK][CHUNK]
/*1004000*/ typedef tilemeta tileset[128]
/*1005000*/ 
/*1006000*/ struct tilemeta {
/*1007000*/ bool ladder : 1
/*1008000*/ bool solid : 1
/*1009000*/ bool liquid : 1
/*1010000*/ bool conductive : 1
/*1011000*/ bool burns : 1
/*1012000*/ bool hypotherm : 1
/*1013000*/ bool sharp : 1
/*1014000*/ bool entropy : 1
/*1015000*/ 
/*1016000*/ bool shiney : 1
/*1017000*/ bool slip : 1
/*1018000*/ signed speed : 2
/*1019000*/ 
/*1020000*/ bool freezes : 1
/*1021000*/ bool melts : 1
/*1022000*/ bool petrif : 1
/*1023000*/ 
/*1024000*/ bool dig : 1
/*1025000*/ bool fence : 1
/*1026000*/ 
/*1027000*/ intptr_t freeze : 8
/*1028000*/ intptr_t melt : 8
/*1029000*/ intptr_t stone : 8
/*1030000*/ unsigned density
/*1031000*/ 
/*1032000*/ bool blink : 1
/*1033000*/ unsigned color : 6
/*1034000*/ 
/*1035000*/ Mesh * shape
/*1036000*/ Texture2D * texture
/*1037000*/ }
/*1038000*/ /* tiles can be effected by stuff happening around them.
/*1039000*/  *
/*1040000*/  * if a tile is flammable, a fire is summoned when fire magic
/*1041000*/  * enters the space or 1d6 chance if there is fire within 1 taxicab of it.
/*1042000*/  *
/*1043000*/  * if a tile is conductive, then electricity is summoned for the instant
/*1044000*/  * that electrical magic strikes it, and propagates through contiguous tiles.
/*1045000*/  *
/*1046000*/  * if a tile can freeze, it's _8BITPTR is changed to the number indicated by ice.
/*1047000*/  * when ice magic intersects it.
/*1048000*/  *
/*1049000*/  * if a tile can melt, it's _8bitPtr is changed to the number indicated by melt
/*1050000*/  * when fire or electrical magic intersect it.
/*1051000*/  *
/*1052000*/  * if a tile can be petrified, it is changed to the tile indicated by stone.
/*1053000*/  *
/*1054000*/  * if a tile can be dug, using a ↧digging tool on it will remove it
/*1055000*/  * digging something triggers updates which cause gravity to affect gases (!liquid,!solid),
/*1056000*/  * liquids(+liquid,!solid), and granulars(+liquid,+solid), wherin less dense
/*1057000*/  * tiles will swap with more dense ones. this effect travels outwards, to the edge of the room,
/*1058000*/  * but will not be applied to the border tiles. in the default set, water has a density of 10, snow
/*1059000*/  * has a density of -1, and air has a density of -100. 
/*1060000*/  */
/*1061000*/ 
/*1062000*/ mapobjflags:
/*1063000*/ bool hidden : 1
/*1064000*/ bool moves : 1
/*1065000*/ bool rclass : 1
/*1066000*/ unsigned class : 4
/*1067000*/ unsigned alignment : 9
/*1068000*/ 
/*1069000*/ struct mapobjtyp:
/*1070000*/ (self) *prev
/*1071000*/ (self) *next
/*1072000*/ uuid_t uuid
/*1073000*/ ucoord3 pos
/*1074000*/ masteritemptr itemid;
/*1075000*/ extendedmetadata * data;
/*1076000*/ mapobjflags flags
/*1077000*/ 
/*1078000*/ struct signtyp {
/*1079000*/ Mesh * shape
/*1080000*/ Texture2D * texture
/*1081000*/ conlangtyp lang
/*1082000*/ char* lines
/*1083000*/ char* gibber
/*1084000*/ }
/*1085000*/ 
/*1086000*/ struct chestyp:
/*1087000*/ heldobjtyp *bag_ptr
/*1088000*/ cursetyp curse
/*1089000*/ locktype locked
/*1090000*/ 
/*1091000*/ struct doortyp {
/*1092000*/ bool open : 1
/*1093000*/ unsigned hp : 7
/*1094000*/ locktype lock : 8
/*1095000*/ 
/*1096000*/ struct locktype {
/*1097000*/ unsigned level : 4;
/*1098000*/ bool locked : 1;
/*1099000*/ unsigned pins : 7;
/*1100000*/ trapflag flags;
/*1101000*/ }
/*1102000*/ /* lockpicking requires the player to enter
/*1103000*/  * 0 and + in the correct order to turn the
/*1104000*/  * tumblers. in addition to making the correct
/*1105000*/  * guess, one must make a skill check:
/*1106000*/  * 1 in 2^(lock.level - (skill/2)) chance
/*1107000*/  *
/*1108000*/  * lockpicking will play an ascending chromatic
/*1109000*/  * scale on a loop, starting on C3 and ending
/*1110000*/  * at G3, on synthbass (triangle wave)
/*1111000*/  */
/*1112000*/ 
/*1113000*/ struct encontyp {
/*1114000*/ (self) *prev
/*1115000*/ (self) *next
/*1116000*/ uuid_t uuid
/*1117000*/ uchar tobeat	//of 10D20
/*1118000*/ spawntyp spawn
/*1119000*/ 
/*1120000*/ struct masteritemptr {
/*1121000*/ intptr_t id : 16;
/*1122000*/ unsigned meta : 8;
/*1123000*/ unsigned n : 8;
/*1124000*/ }
/*1125000*/ 
/*1126000*/ struct extendedmetadata {
/*1127000*/ char * name;
/*1128000*/ void * data;
/*1129000*/ }
/*1130000*/ 
/*1131000*/ struct masteritemlistentry {
/*1132000*/ objid type
/*1133000*/ void * data
/*1134000*/ }
/*1135000*/ 
/*1136000*/ typedef struct masteritemlistentry *(*(*(*(const * masteritemlist)[16])[16])[16])[16];
/*1137000*/ //array of 16 pointers to arrays of 16 pointers to arrays of 16 pointers to arrays of 16 pointers to string-like arrays
/*1138000*/ 
/*1139000*/ struct toolsublistyp {
/*1140000*/ struct toolsublistyp * prev;	//the previous tools block
/*1141000*/ struct toolsublistyp * next;	//the next tools block
/*1142000*/ ushort first;
/*1143000*/ ushort last;
/*1144000*/ unsigned n;
/*1145000*/ funcptr * funcs;
/*1146000*/ }
/*1147000*/ 
/*1148000*/ /*to be replaced
/*1149000*/ struct miscitembasetyp:
/*1150000*/ bool key : 1
/*1151000*/ bool pick : 1
/*1152000*/ bool dig : 1
/*1153000*/ bool music : 1
/*1154000*/ bool light : 1
/*1155000*/ bool book : 1
/*1156000*/ bool spark : 1
/*1157000*/ bool quest : 1
/*1158000*/ bool fireproof : 1
/*1159000*/ bool waterproof : 1
/*1160000*/ bool elecproof : 1
/*1161000*/ bool iceproof : 1
/*1162000*/ bool stoneproof : 1
/*1163000*/ bool arrow : 1
/*1164000*/ bool poisoned : 1
/*1165000*/ bool unbreak : 1
/*1166000*/ unsigned uses : 8
/*1167000*/ intptr_t metadata : 8
/*1168000*/ */
/*1169000*/ 
/*1170000*/ struct eventdatastack_uuidptr {
/*1171000*/ uuid_t uuid;
/*1172000*/ void * ptr;
/*1173000*/ }
/*1174000*/ 
/*1175000*/ struct eventdatastack_top {
/*1176000*/ struct eventdatastack_top * prev;
/*1177000*/ struct eventdatastack_top * next;
/*1178000*/ struct eventdatastack_sub * this;
/*1179000*/ struct eventdatastacl_uuidptr * up;	//what events depend on this one
/*1180000*/ uuid_t uuid;
/*1181000*/ unsigned cleanup[2];	//keys to a dispatch table
/*1182000*/ }
/*1183000*/ 
/*1184000*/ struct eventdatastack_sub {
/*1185000*/ (self)* prev;
/*1186000*/ (self)* next;
/*1187000*/ uuid_t uuid;
/*1188000*/ void * data;
/*1189000*/ size_t length;
/*1190000*/ }
/*1191000*/ 
/*1192000*/ union hitboxuni {
/*1193000*/ BoundingBox square
/*1194000*/ struct sphere
/*1195000*/ Vector3 geom
/*1196000*/ Ray ray
/*1197000*/ }
/*1198000*/ 
/*1199000*/ struct hitboxtyp {
/*1200000*/ union hitboxuni
/*1201000*/ uchar type
/*1202000*/ }
/*1203000*/ 
/*1204000*/ struct eventtyp:
/*1205000*/ (self) *prev
/*1206000*/ (self) *next
/*1207000*/ ucoord3 pos
/*1208000*/ uuid_t uuid
/*1209000*/ unsigned hours : 24
/*1210000*/ int (*dothis)(intptr_t,intptr_t,intptr_t,intptr_t)
/*1211000*/ bool interact : 1
/*1212000*/ bool look : 1
/*1213000*/ unsigned duration : 15
/*1214000*/ unsigned remduration : 15
/*1215000*/ Mesh * shape
/*1216000*/ Texture2D * texture
/*1217000*/ 
/*1218000*/ struct triggertyp {
/*1219000*/ triggerenum key : 4
/*1220000*/ unsigned value : 4
/*1221000*/ }
/*1222000*/ 
/*1223000*/ struct qglobev { //queued global event. can be modifications to distant rooms, or stuff like cutscenes.
/*1224000*/ (self) *prev;
/*1225000*/ (self) *next;
/*1226000*/ uuid_t parent;
/*1227000*/ ucoord4 globpos;
/*1228000*/ funcptr dothis;
/*1229000*/ bool pres;	//whether to act as soon as the room is on the stack, or if the player must be present
/*1230000*/ }
/*1231000*/ 
/*1232000*/ struct traptyp:
/*1233000*/ Mesh * shape
/*1234000*/ Texture2D * texture
/*1235000*/ ushort duration
/*1236000*/ magictyp element
/*1237000*/ stattyp stat
/*1238000*/ cursetyp curse
/*1239000*/ diceodds odds
/*1240000*/ trapflags flags
/*1241000*/ sensetyp sense
/*1242000*/ short hp
/*1243000*/ short mp
/*1244000*/ 
/*1245000*/ struct trapflags:
/*1246000*/ bool fireproof : 1
/*1247000*/ bool waterproof : 1
/*1248000*/ bool elecproof : 1
/*1249000*/ bool iceproof : 1
/*1250000*/ bool tamperproof : 1
/*1251000*/ bool stoneproof : 1
/*1252000*/ bool warded : 1
/*1253000*/ unsigned attack_alignments : 9
/*1254000*/ bool multiuse : 1
/*1255000*/ bool magic : 1	//whether the trap is a mechanism or a rune
/*1256000*/ unsigned color : 6
/*1257000*/ 
/*1258000*/ struct subwarptyp {
/*1259000*/ bool perm : 1
/*1260000*/ bool blink : 1
/*1261000*/ unsigned color : 6
/*1262000*/ ucoord3 pos
/*1263000*/ ucoord3 dest
/*1264000*/ short duration	//negative are uses, positive are turns
/*1265000*/ }
/*1266000*/ 
/*1267000*/ struct warptyp:
/*1268000*/ bool perm : 1
/*1269000*/ bool blink : 1
/*1270000*/ unsigned color : 6
/*1271000*/ ucoord4 glob_loc
/*1272000*/ ucoord3 pos
/*1273000*/ ucoord4 glob_dest
/*1274000*/ ucoord3 dest
/*1275000*/ short duration
/*1276000*/ 
/*1277000*/ struct gemstonetyp:
/*1278000*/ unsigned color : 5
/*1279000*/ unsigned cut : 3
/*1280000*/ unsigned quality : 8
/*1281000*/ 
/*1282000*/ /* to be replaced
/*1283000*/ struct meattyp:
/*1284000*/ struct racetyp race
/*1285000*/ uchar sellby
/*1286000*/ uchar amount
/*1287000*/ 
/*1288000*/ struct foodtyp:
/*1289000*/ intptr_t itemid : 8
/*1290000*/ intptr_t metadata : 8
/*1291000*/ unsigned sellby : 8
/*1292000*/ unsigned amount : 8
/*1293000*/ 
/*1294000*/ foodbasetyp:
/*1295000*/ effectyp effect
/*1296000*/ diceodds odds
/*1297000*/ uchar keepsfor	//0 means non-perishable
/*1298000*/ uchar hp
/*1299000*/ uchar nutri
/*1300000*/ */
/*1301000*/ 
/*1302000*/ /* rework be a type enum for unified object table
/*1303000*/ enum objid:
/*1304000*/ WEAPON_FLAG : contains subobjtyp calling baseweaptyp
/*1305000*/ LEGEND_FLAG : contains subobjtyp calling baseweaptyp
/*1306000*/ POTION_FLAG : contains potiontyp
/*1307000*/ READ_FLAG : contains readtyp
/*1308000*/ FOOD_FLAG : contains subobjtyp containing foodtyp
/*1309000*/ MEAT_FLAG : contains subobjtyp containing meattyp
/*1310000*/ ARMOR_FLAG : contains subobjtyp calling basearmortyp
/*1311000*/ SHLD_FLAG : contains subobjtyp calling baseshldtyp
/*1312000*/ BAUB_FLAG : contains subobjtyp calling baubtyp
/*1313000*/ CONLANG_FLAG : contains conlangtyp
/*1314000*/ MISC_FLAG : contains ptrchar or ptrshort
/*1315000*/ GEM_FLAG : contains gemstonetyp
/*1316000*/ TRAP_FLAG : contains traptyp
/*1317000*/ WARP_FLAG : contains warptyp
/*1318000*/ SUBWARP_FLAG : contains subwarptyp
/*1319000*/ CHEST_FLAG : contains chestyp
/*1320000*/ DOOR_FLAG : contains doortyp
/*1321000*/ LOCK_FLAG : contains locktyp (gates are this)
/*1322000*/ MONEY_FLAG : contains float
/*1323000*/ SPAWN_FLAG : contains spawntyp
/*1324000*/ SIGN_FLAG : contains signtyp
/*1325000*/ */
/*1326000*/ 
/*1327000*/ #endif
