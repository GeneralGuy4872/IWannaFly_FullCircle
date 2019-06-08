#include "./bonegroups.h"
#include "./avian.c"
#include "./human.c"
#include "./merfolk.c"
#include "./feline.c"
#include "./draconic.c"
/*

*skeleton sculpt_foo() provided in each included file

polymorph_foo(entity *bar) changes an existing entity to the default values of foo, keeping velocity, rotation, and position

*entity summon_foo() creates a new entity of the species foo and appends it to the list of entitys

*/

polymorph_avian(target,geomet)
	entity target
	mesurements geomet
	{
	target.dembones = sculpt_avian(geomet)
	target.hitbox = {SUITFIT(geomet,hbradius),SUITFIT(geomet,hbheight),SUITFIT(geomet,hbeyes),SUITFIT(geomet,hboffset)}
	target.stat.horiz = FALSE
	target.stat.uv = TRUE
	target.stat.infra = FALSE
	target.Ff = {AVE_FRIC,AVE_DRAG_W,AVE_DRAG_Z}
	target.Spd = {AVE_SPD_X,AVE_SPD_M,AVE_SPD_Z,AVE_SPD_W}
	forcebaseten ? NOP : CAMERA.base = TRISTATE
	}

*entity summon_avian(xcoord,ycoord,zcoord,geomet)
	float xcoord
	float ycoord
	float zcoord
	mesurements geomet
	{
	entity *parent
	entity tmp = malloc(sizeof(struct entity))
	if (WORLD.ent_tail != NULL)
  		{
		parent = WORLD.ent_tail
		WORLD.ent_tail = &tmp
		}
	else
		{
		if (world.ent == NULL)
			{
			WORLD.ent = &tmp
			WORLD.ent_tail = &tmp
			}
		else
			{
			WORLD.ent_tail = &tmp
			parent = WORLD.ent
			while (parent->next != NULL)
				{
				parent = parent->next
				}
			}
  		}
	struct entity tmp = {WORLD.ent_tail,NULL,{xcoord,ycoord,zcoord},{SUITFIT(geomet,hbradius),SUITFIT(geomet,hbheight),SUITFIT(geomet,hbeyes),SUITFIT(geomet,hboffset)},{0,0,0},{0,0,0},matgen_ident,'\0','\0',255,{AVE_FRIC,AVE_DRAG_W,AVE_DRAG_Z},{AVE_SPD_X,AVE_SPD_M,AVE_SPD_Z,AVE_SPD_W},sculpt_avian(geomet)}
	}
