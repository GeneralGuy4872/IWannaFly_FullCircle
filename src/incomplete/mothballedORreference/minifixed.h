//uses vectors.h.m4

NEWSTRUCT minifixed {
	unsigned whole : 1;
	unsigned part : 7;
	}

makevector2(STRUCT minifixed,minifixed);
makevector3(STRUCT minifixed,minifixed);
makevector4(STRUCT minifixed,minifixed);
vector2linkage(STRUCT minifixed,minifixed);
vector3linkage(STRUCT minifixed,minifixed);
vector4linkage(STRUCT minifixed,minifixed);
