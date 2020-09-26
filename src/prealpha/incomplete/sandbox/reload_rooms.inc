/***ORIGIN***/
	iwf::roomcache::current[3][3][3] = input;
	iwf::roomcache::increment(input);
//END ORIGIN
/***AXES***/
/***UP***/
	for (int n = 2;n >= 0;n++) {
	iwf::roomcache::current[n][3][3] = iwf::roomcache::data.at(iwf::roomcache::current[n + 1][3][3]).first->neighbors[UP];
	if (iwf::roomcache::current[n][3][3] >= 0) {
		iwf::roomcache::increment(iwf::roomcache::current[n][3][3]);
	} else {
		break;
		}
//END UP
/***DOWN***/
	for (int n = 4;n < 7;n++) {
	iwf::roomcache::current[n][3][3] = iwf::roomcache::data.at(iwf::roomcache::current[n - 1][3][3]).first->neighbors[DOWN];
	if (iwf::roomcache::current[n][3][3] >= 0) {
		iwf::roomcache::increment(iwf::roomcache::current[n][3][3]);
	} else {
		break;
		}
//END DOWN
/***NORTH***/
	for (int n = 2;n >= 0;n++) {
	iwf::roomcache::current[3][n][3] = iwf::roomcache::data.at(iwf::roomcache::current[3][n + 1][3]).first->neighbors[NORTH];
	if (iwf::roomcache::current[3][n][3] >= 0) {
		iwf::roomcache::increment(iwf::roomcache::current[3][n][3]);
	} else {
		break;
		}
//END NORTH
/***SOUTH***/
	for (int n = 4;n < 7;n++) {
	iwf::roomcache::current[3][n][3] = iwf::roomcache::data.at(iwf::roomcache::current[3][n - 1][3]).first->neighbors[SOUTH];
	if (iwf::roomcache::current[3][n][3] >= 0) {
		iwf::roomcache::increment(iwf::roomcache::current[3][n][3]);
	} else {
		break;
		}
//END SOUTH
/***WEST***/
	for (int n = 2;n >= 0;n++) {
	iwf::roomcache::current[3][3][n] = iwf::roomcache::data.at(iwf::roomcache::current[3][3][n + 1]).first->neighbors[WEST];
	if (iwf::roomcache::current[3][3][n] >= 0) {
		iwf::roomcache::increment(iwf::roomcache::current[3][3][n]);
	} else {
		break;
		}
//END WEST
/***EAST***/
	for (int n = 4;n < 7;n++) {
	iwf::roomcache::current[3][3][n] = iwf::roomcache::data.at(iwf::roomcache::current[3][3][n - 1]).first->neighbors[EAST];
	if (iwf::roomcache::current[3][3][n] >= 0) {
		iwf::roomcache::increment(iwf::roomcache::current[3][3][n]);
	} else {
		break;
		}
//END EAST
//END AXES
/***PLANES***/
/***XY***/
/***NW***/
	for (size_t y = 2;y >= 0;y--) {for (size_t x = 2;x >= 0;x--) {
		if ((
		  iwf::roomcache::current[3][y + 1][x] >= 0
		  ) && (
		  iwf::roomcache::current[3][y][x + 1] >= 0
		  ) && (
		  iwf::roomcache::data[iwf::roomcache::current[3][y + 1][x]].first->neighbors[NORTH]
		   ==
		  iwf::roomcache::data[iwf::roomcache::current[3][y][x + 1]].first->neighbors[WEST]
		  )) {
			iwf::roomcache::current[3][y][x] = iwf::roomcache::data[iwf::roomcache::current[3][y + 1][x]].first->neighbors[NORTH];
		}}}
//END NW
/***NE***/
	for (size_t y = 2;y >= 0;y--) {for (size_t x = 4;x < 7;x++) {
		if ((
		  iwf::roomcache::current[3][y + 1][x] >= 0
		  ) && (
		  iwf::roomcache::current[3][y][x - 1] >= 0
		  ) && (
		  iwf::roomcache::data[iwf::roomcache::current[3][y + 1][x]].first->neighbors[NORTH]
		   ==
		  iwf::roomcache::data[iwf::roomcache::current[3][y][x - 1]].first->neighbors[EAST]
		  )) {
			iwf::roomcache::current[3][y][x] = iwf::roomcache::data[iwf::roomcache::current[3][y + 1][x]].first->neighbors[NORTH];
		}}}
//END NE
/***SW***/
	for (size_t y = 4;y < 7;y++) {for (size_t x = 2;x >= 0;x--) {
		if ((
		  iwf::roomcache::current[3][y - 1][x] >= 0
		  ) && (
		  iwf::roomcache::current[3][y][x + 1] >= 0
		  ) && (
		  iwf::roomcache::data[iwf::roomcache::current[3][y - 1][x]].first->neighbors[SOUTH]
		   ==
		  iwf::roomcache::data[iwf::roomcache::current[3][y][x + 1]].first->neighbors[WEST]
		  )) {
			iwf::roomcache::current[3][y][x] = iwf::roomcache::data[iwf::roomcache::current[3][y - 1][x]].first->neighbors[SOUTH];
		}}}
//END SW
/***SE***/
	for (size_t y = 4;y < 7;y++) {for (size_t x = 4;x < 7;x++) {
		if ((
		  iwf::roomcache::current[3][y - 1][x] >= 0
		  ) && (
		  iwf::roomcache::current[3][y][x - 1] >= 0
		  ) && (
		  iwf::roomcache::data[iwf::roomcache::current[3][y - 1][x]].first->neighbors[SOUTH]
		   ==
		  iwf::roomcache::data[iwf::roomcache::current[3][y][x - 1]].first->neighbors[EAST]
		  )) {
			iwf::roomcache::current[3][y][x] = iwf::roomcache::data[iwf::roomcache::current[3][y - 1][x]].first->neighbors[SOUTH];
		}}}
//END SE
//END XY
/***XZ***/
/***upW***/
	for (size_t z = 2;z >= 0;z--) {for (size_t x = 2;x >= 0;x--) {
		if ((
		  iwf::roomcache::current[z + 1][3][x] >= 0
		  ) && (
		  iwf::roomcache::current[z][3][x + 1] >= 0
		  ) && (
		  iwf::roomcache::data[iwf::roomcache::current[z + 1][3][x]].first->neighbors[UP]
		   ==
		  iwf::roomcache::data[iwf::roomcache::current[z][3][x + 1]].first->neighbors[WEST]
		  )) {
			iwf::roomcache::current[z][3][x] = iwf::roomcache::data[iwf::roomcache::current[z + 1][3][x]].first->neighbors[UP];
		}}}
//END upW
/***upE***/
	for (size_t z = 2;z >= 0;z--) {for (size_t x = 4;x < 7;x++) {
		if ((
		  iwf::roomcache::current[z + 1][3][x] >= 0
		  ) && (
		  iwf::roomcache::current[z][3][x - 1] >= 0
		  ) && (
		  iwf::roomcache::data[iwf::roomcache::current[z + 1][3][x]].first->neighbors[UP]
		   ==
		  iwf::roomcache::data[iwf::roomcache::current[z][3][x - 1]].first->neighbors[EAST]
		  )) {
			iwf::roomcache::current[z][3][x] = iwf::roomcache::data[iwf::roomcache::current[z + 1][3][x]].first->neighbors[UP];
		}}}
//END upE
/***downW***/
	for (size_t z = 4;z < 7;z++) {for (size_t x = 2;x >= 0;x--) {
		if ((
		  iwf::roomcache::current[z - 1][3][x] >= 0
		  ) && (
		  iwf::roomcache::current[z][3][x + 1] >= 0
		  ) && (
		  iwf::roomcache::data[iwf::roomcache::current[z - 1][3][x]].first->neighbors[DOWN]
		   ==
		  iwf::roomcache::data[iwf::roomcache::current[z][3][x + 1]].first->neighbors[WEST]
		  ) {
			iwf::roomcache::current[z][3][x] = iwf::roomcache::data[iwf::roomcache::current[z - 1][3][x]].first->neighbors[DOWN];
		}}}
//END downW
/***downE***/
	for (size_t z = 4;z < 7;z++) {for (size_t x = 4;x < 7;x++) {
		if ((
		  iwf::roomcache::current[z - 1][3][x] >= 0
		  ) && (
		  iwf::roomcache::current[z][3][x - 1] >= 0
		  ) && (
		  iwf::roomcache::data[iwf::roomcache::current[z - 1][3][x]].first->neighbors[DOWN]
		   ==
		  iwf::roomcache::data[iwf::roomcache::current[z][3][x - 1]].first->neighbors[EAST]
		  ) {
			iwf::roomcache::current[z][3][x] = iwf::roomcache::data[iwf::roomcache::current[z - 1][3][x]].first->neighbors[DOWN];
		}}}
//END downE
//END XZ
/***YZ***/
/***upN***/
	for (size_t z = 2;z >= 0;z--) {for (size_t y = 2;y >= 0;y--) {
		if ((
		  iwf::roomcache::current[z + 1][y][3] >= 0
		  ) && (
		  iwf::roomcache::current[z][y + 1][3] >= 0
		  ) && (
		  iwf::roomcache::data[iwf::roomcache::current[z + 1][y][3]].first->neighbors[UP]
		   ==
		  iwf::roomcache::data[iwf::roomcache::current[z][y + 1][3]].first->neighbors[NORTH]
		  )) {
			iwf::roomcache::current[z][y][3] = iwf::roomcache::data[iwf::roomcache::current[z + 1][y][3]].first->neighbors[UP];
		}}}
//END upN
/***upS***/
	for (size_t z = 2;z >= 0;z--) {for (size_t y = 4;y < 7;y++) {
		if ((
		  iwf::roomcache::current[z + 1][y][3] >= 0
		  ) && (
		  iwf::roomcache::current[z][y - 1][3] >= 0
		  ) && (
		  iwf::roomcache::data[iwf::roomcache::current[z + 1][y][3]].first->neighbors[UP]
		   ==
		  iwf::roomcache::data[iwf::roomcache::current[z][y - 1][3]].first->neighbors[SOUTH]
		  )) {
			iwf::roomcache::current[z][y][3] = iwf::roomcache::data[iwf::roomcache::current[z + 1][y][3]].first->neighbors[UP];
		}}}
//END upS
/***downN***/
	for (size_t z = 4;z < 7;z++) {for (size_t y = 2;y >= 0;y--) {
		if ((
		  iwf::roomcache::current[y - 1][y][3] >= 0
		  ) && (
		  iwf::roomcache::current[z][y + 1][3] >= 0
		  ) && (
		  iwf::roomcache::data[iwf::roomcache::current[z - 1][y][3]].first->neighbors[DOWN]
		   ==
		  iwf::roomcache::data[iwf::roomcache::current[z][y + 1][3]].first->neighbors[NORTH]
		  ) {
			iwf::roomcache::current[z][y][3] = iwf::roomcache::data[iwf::roomcache::current[z - 1][y][3]].first->neighbors[DOWN];
		}}}
//END downN
/***downS***/
	for (size_t z = 4;z < 7;z++) {for (size_t y = 4;y < 7;y++) {
		if ((
		  iwf::roomcache::current[z - 1][y][3] >= 0
		  ) && (
		  iwf::roomcache::current[z][y - 1][3] >= 0
		  ) && (
		  iwf::roomcache::data[iwf::roomcache::current[z - 1][y][3]].first->neighbors[DOWN]
		   ==
		  iwf::roomcache::data[iwf::roomcache::current[z][y - 1][3]].first->neighbors[SOUTH]
		  ) {
			iwf::roomcache::current[z][y][3] = iwf::roomcache::data[iwf::roomcache::current[z - 1][y][3]].first->neighbors[DOWN];
		}}}
//END downS
//END YZ
//END PLANE
/***OCTANT***/
/***upNW***/
	for (size_t z = 2;z >= 0;z--) {for (size_t y = 2;y >= 0;y--) {for (size_t x = 2;x >= 0;x--) {
		if ((
		  iwf::roomcache::current[z][y][x + 1] >= 0
		  ) && (
		  iwf::roomcache::current[z][y + 1][x] >= 0
		  ) && (
		  iwf::roomcache::current[z + 1][y][x] >= 0
		  ) && (
		  THREEQUAL<int16_t>(
		    iwf::roomcache::data[iwf::roomcache::current[z][y][x + 1]].first->neighbors[WEST],
		    iwf::roomcache::data[iwf::roomcache::current[z][y + 1][x]].first->neighbors[NORTH],
		    iwf::roomcache::data[iwf::roomcache::current[z + 1][y][x]].first->neighbors[UP]))) {
			iwf::roomcache::current[z][y][x] = iwf::roomcache::data[iwf::roomcache::current[z + 1][y][x]].first->neighbors[UP];
			}}}}
//END upNW
/***upNE***/
	for (size_t z = 2;z >= 0;z--) {for (size_t y = 2;y >= 0;y--) {for (size_t x = 4;x < 7;x++) {
		if ((
		  iwf::roomcache::current[z][y][x - 1] >= 0
		  ) && (
		  iwf::roomcache::current[z][y + 1][x] >= 0
		  ) && (
		  iwf::roomcache::current[z + 1][y][x] >= 0
		  ) && (
		  THREEQUAL<int16_t>(
		    iwf::roomcache::data[iwf::roomcache::current[z][y][x - 1]].first->neighbors[EAST],
		    iwf::roomcache::data[iwf::roomcache::current[z][y + 1][x]].first->neighbors[NORTH],
		    iwf::roomcache::data[iwf::roomcache::current[z + 1][y][x]].first->neighbors[UP]))) {
			iwf::roomcache::current[z][y][x] = iwf::roomcache::data[iwf::roomcache::current[z + 1][y][x]].first->neighbors[UP];
			}}}}
//END upNE
/***upSW***/
	for (size_t z = 2;z >= 0;z--) {for (size_t y = 4;y < 7;y++) {for (size_t x = 2;x >= 0;x--) {
		if ((
		  iwf::roomcache::current[z][y][x + 1] >= 0
		  ) && (
		  iwf::roomcache::current[z][y - 1][x] >= 0
		  ) && (
		  iwf::roomcache::current[z + 1][y][x] >= 0
		  ) && (
		  THREEQUAL<int16_t>(
		    iwf::roomcache::data[iwf::roomcache::current[z][y][x + 1]].first->neighbors[WEST],
		    iwf::roomcache::data[iwf::roomcache::current[z][y - 1][x]].first->neighbors[SOUTH],
		    iwf::roomcache::data[iwf::roomcache::current[z + 1][y][x]].first->neighbors[UP]))) {
			iwf::roomcache::current[z][y][x] = iwf::roomcache::data[iwf::roomcache::current[z + 1][y][x]].first->neighbors[UP];
			}}}}
//END upSW
/***upSE***/
	for (size_t z = 2;z >= 0;z--) {for (size_t y = 4;y < 7;y++) {for (size_t x = 4;x < 7;x++) {
		if ((
		  iwf::roomcache::current[z][y][x - 1] >= 0
		  ) && (
		  iwf::roomcache::current[z][y - 1][x] >= 0
		  ) && (
		  iwf::roomcache::current[z + 1][y][x] >= 0
		  ) && (
		  THREEQUAL<int16_t>(
		    iwf::roomcache::data[iwf::roomcache::current[z][y][x - 1]].first->neighbors[EAST],
		    iwf::roomcache::data[iwf::roomcache::current[z][y - 1][x]].first->neighbors[SOUTH],
		    iwf::roomcache::data[iwf::roomcache::current[z + 1][y][x]].first->neighbors[UP]))) {
			iwf::roomcache::current[z][y][x] = iwf::roomcache::data[iwf::roomcache::current[z + 1][y][x]].first->neighbors[UP];
			}}}}
//END upSE
/***downNW***/
	for (size_t z = 4;z < 7;z++) {for (size_t y = 2;y >= 0;y--) {for (size_t x = 2;x >= 0;x--) {
		if ((
		  iwf::roomcache::current[z][y][x + 1] >= 0
		  ) && (
		  iwf::roomcache::current[z][y + 1][x] >= 0
		  ) && (
		  iwf::roomcache::current[z - 1][y][x] >= 0
		  ) && (
		  THREEQUAL<int16_t>(
		    iwf::roomcache::data[iwf::roomcache::current[z][y][x + 1]].first->neighbors[WEST],
		    iwf::roomcache::data[iwf::roomcache::current[z][y + 1][x]].first->neighbors[NORTH],
		    iwf::roomcache::data[iwf::roomcache::current[z - 1][y][x]].first->neighbors[DOWN]))) {
			iwf::roomcache::current[z][y][x] = iwf::roomcache::data[iwf::roomcache::current[z - 1][y][x]].first->neighbors[DOWN];
			}}}}
//END downNW
/***downNE***/
	for (size_t z = 4;z < 7;z++) {for (size_t y = 2;y >= 0;y--) {for (size_t x = 4;x < 7;x++) {
		if ((
		  iwf::roomcache::current[z][y][x - 1] >= 0
		  ) && (
		  iwf::roomcache::current[z][y + 1][x] >= 0
		  ) && (
		  iwf::roomcache::current[z - 1][y][x] >= 0
		  ) && (
		  THREEQUAL<int16_t>(
		    iwf::roomcache::data[iwf::roomcache::current[z][y][x - 1]].first->neighbors[EAST],
		    iwf::roomcache::data[iwf::roomcache::current[z][y + 1][x]].first->neighbors[NORTH],
		    iwf::roomcache::data[iwf::roomcache::current[z - 1][y][x]].first->neighbors[DOWN]))) {
			iwf::roomcache::current[z][y][x] = iwf::roomcache::data[iwf::roomcache::current[z - 1][y][x]].first->neighbors[DOWN];
			}}}}
//END downNE
/***downSW***/
	for (size_t z = 4;z < 7;z--) {for (size_t y = 4;y < 7;y++) {for (size_t x = 2;x >= 0;x--) {
		if ((
		  iwf::roomcache::current[z][y][x + 1] >= 0
		  ) && (
		  iwf::roomcache::current[z][y - 1][x] >= 0
		  ) && (
		  iwf::roomcache::current[z - 1][y][x] >= 0
		  ) && (
		  THREEQUAL<int16_t>(
		    iwf::roomcache::data[iwf::roomcache::current[z][y][x + 1]].first->neighbors[WEST],
		    iwf::roomcache::data[iwf::roomcache::current[z][y - 1][x]].first->neighbors[SOUTH],
		    iwf::roomcache::data[iwf::roomcache::current[z - 1][y][x]].first->neighbors[DOWN]))) {
			iwf::roomcache::current[z][y][x] = iwf::roomcache::data[iwf::roomcache::current[z - 1][y][x]].first->neighbors[DOWN];
			}}}}
//END downSW
/***downSE***/
	for (size_t z = 4;z < 7;z++) {for (size_t y = 4;y < 7;y++) {for (size_t x = 4;x < 7;x++) {
		if ((
		  iwf::roomcache::current[z][y][x - 1] >= 0
		  ) && (
		  iwf::roomcache::current[z][y - 1][x] >= 0
		  ) && (
		  iwf::roomcache::current[z - 1][y][x] >= 0
		  ) && (
		  THREEQUAL<int16_t>(
		    iwf::roomcache::data[iwf::roomcache::current[z][y][x - 1]].first->neighbors[EAST],
		    iwf::roomcache::data[iwf::roomcache::current[z][y - 1][x]].first->neighbors[SOUTH],
		    iwf::roomcache::data[iwf::roomcache::current[z - 1][y][x]].first->neighbors[DOWN]))) {
			iwf::roomcache::current[z][y][x] = iwf::roomcache::data[iwf::roomcache::current[z - 1][y][x]].first->neighbors[DOWN];
			}}}}
//END downSE
//END octant
