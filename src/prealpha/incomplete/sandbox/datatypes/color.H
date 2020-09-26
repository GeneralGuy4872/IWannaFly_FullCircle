STRUCTTYPE_BEGIN(htmlcolor)
	unsigned r : 8;
	unsigned g : 8;
	unsigned b : 8;
STRUCTTYPE_END(htmlcolor);

STRUCTTYPE_BEGIN(htmlcolor_alpha)
	unsigned r : 8;
	unsigned g : 8;
	unsigned b : 8;
	unsigned a : 8;
STRUCTTYPE_END(htmlcolor_alpha);

STRUCTTYPE_BEGIN(hicolor)
	unsigned r : 5;
	unsigned g : 6;
	unsigned b : 5;
STRUCTTYPE_END(hicolor);

STRUCTTYPE_BEGIN(hicolor_alpha)
	unsigned r : 5;
	unsigned g : 5;
	unsigned b : 5;
	unsigned a : 1;
STRUCTTYPE_END(hicolor_alpha);

STRUCTTYPE_BEGIN(lowcolor)
	unsigned r : 3;
	unsigned g : 3;
	unsigned b : 2;
STRUCTTYPE_END(lowcolor);
