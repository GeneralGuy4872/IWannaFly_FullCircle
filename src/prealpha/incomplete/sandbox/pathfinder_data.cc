iwf::ai::pathfinder::data::node {
	bool obstruction;
	double distance;	/** reverse distance
				 * for an A★ algorithem
				 */
	double swimtime;
	double airtime;
	double phasetime;
	};

iwf::ai::pathfinder::data_t {
	std::pair<char;int16_t> here;
	std::pair<char;int16_t> there;
	/** pair coords
	 * .first is the octant relative to the player's chunk. only 27
	 * chunks are animate at a time. .second is the coordinate in the
	 * chunk.
	 */
	std::map<std::pair<char;int16_t>;iwf::ai::pathfinder::data::node> nodes;
	iwf$$datatypes$$body_combat_metadata * body_combat_metadata;
	iwf$$datatypes$$skilltyp * skills
	}

