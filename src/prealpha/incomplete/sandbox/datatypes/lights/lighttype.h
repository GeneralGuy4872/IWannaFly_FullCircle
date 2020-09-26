※include "../../cppkeywords.def"
※include "../color.H"

STRUCTTYPE_BEGIN(iwf$$datatypes$$lightbeam_t)
	uint16_t coord[2];
	htmlcolor color;
	unsigned char alpha[2];
STRUCTTYPE_END(iwf$$datatypes$$lightbeam_t);

STRUCTTYPE_BEGIN(iwf$$datatypes$$lightsource_t)
	uint16_t coord;
	htmlcolor_alpha color;
	float lum;
STRUCTTYPE_END(iwf$$datatypes$$lightsource_t);
