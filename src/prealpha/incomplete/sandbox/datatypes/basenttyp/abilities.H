// 32 bits
STRUCTTYPE_BEGIN(iwf$$datatypes$$body_combat_metadata)
	bool gills : 1;
	bool lungs : 1;
	bool can_fly : 1;
	bool can_swim : 1;
	bool can_phase : 1;
	bool caffinated : 1;
	bool fireproof : 1;
	bool iceproof : 1;
	bool elecproof : 1;
	bool stoneproof : 1;
	bool poisonproof : 1;
	bool paralzproof : 1;
	bool lightproof : 1;
	bool darkproof : 1;
	bool voidproof : 1;
	unsigned hands : 3;	// none, hands, claws, poison claws, paws, hook, blade, tentacle
	unsigned legs : 3;	// none, humanoid legs, talons, poison talons, paws, blade, hooves, spider
	unsigned wings : 2;	// none, feathery, leathery, fairy
	unsigned tail : 3;	// none, bird, dragon, cat, spiked, fish, snake, pointy
	bool fangs : 1;
	unsigned venom : 2;
	bool stare : 1;
	bool shootweb : 1;
	bool sting : 1;
STRUCTTYPE_END(iwf$$datatypes$$body_combat_metadata);

// 7 bytes
STRUCTTYPE_BEGIN(iwf$$datatypes$$skilltyp)
	unsigned sword : 4;	//! flat bonus to sword damage
	unsigned knife : 4;	//! flat bonus to knife damage
	unsigned stave : 4;	//! flat bonus to stave damage
	unsigned spear : 4;	//! flat bonus to spear damage
	unsigned whip : 4;	//! flat bonus to whip range (extra range is added to damage)
	unsigned club : 4;	//! flat bonus to club damage
	unsigned bow : 4;	//! double bonus to bow range (extra range is added to damage)
	unsigned throw : 4;	//! double bonus to throwing range (extra range is added to damage iff not an improvised weapon)
	unsigned hands : 4;	//! triple bonus to unarmed attack
	unsigned shield : 4;	//! x in (damage - def) + |damage - def| chance of blocking attack
	unsigned locks : 4;	//! 1 in 2^(locklevel - x) chance of picking lock
	unsigned caster : 5;	//! casting cost is reduced by (x-1)/4. spatk and spdef are increased by same.
	unsigned swim : 2;	//! 0: sink, 1: swim accross surface, 2: dive, but positively bouyent, 3: neutraly bouyent
	unsigned fly : 2;	//! 0: regular falling, 1: feather falling, 2: glide, 3: free flight
	bool walk : 1;
	bool sink : 1;	//! overrides swim
	bool magnetic : 1	//! attracted to magnets
STRUCTTYPE_END(iwf$$datatypes$$skilltyp);
