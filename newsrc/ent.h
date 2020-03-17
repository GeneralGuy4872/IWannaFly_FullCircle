structblackbox entlist {
	entlist * prev
	entlist * next
	key
	entkdtree * value
	}

structblackbox entkdtree {
	entkdback pr
	entkdtree * less
	entkdtree * more
	int tier	//-1 for top
	enttyp * val
	}

union entkdback {
	entkdtree * ev
	entlist * ior
	}
