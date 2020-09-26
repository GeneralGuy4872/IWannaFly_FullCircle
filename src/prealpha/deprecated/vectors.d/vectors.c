#include "vectors.h"

vector2functions(char8_t,s8)
vector2functions(uchar8_t,u8)
vector2functions(char16_t,s16)
vector2functions(uchar16_t,u16)
vector2functions(char32_t,s32)
vector2functions(uchar32_t,u32)
vector2functions(char64_t,s64)
vector2functions(uchar64_t,u64)
vector2functions(int,i)
vector2functions(float,f)
vector2functions(double,NIL)

vector3functions(char8_t,s8)
vector3functions(uchar8_t,u8)
vector3functions(char16_t,s16)
vector3functions(uchar16_t,u16)
vector3functions(char32_t,s32)
vector3functions(uchar32_t,u32)
vector3functions(char64_t,s64)
vector3functions(uchar64_t,u64)
vector3functions(int,i)
vector3functions(float,f)
vector3functions(double,NIL)

vector4functions(char8_t,s8)
vector4functions(uchar8_t,u8)
vector4functions(char16_t,s16)
vector4functions(uchar16_t,u16)
vector4functions(char32_t,s32)
vector4functions(uchar32_t,u32)
vector4functions(char64_t,s64)
vector4functions(uchar64_t,u64)
vector4functions(int,i)
vector4functions(float,f)
vector4functions(double,NIL)

vector2functions(unsigned,uNybble)
vector2functions(signed,sNybble)
vector4functions(unsigned,uNybble)
vector4functions(signed,sNybble)

float SphereCoord2f$$at (SphereCoord2f * input,int n) {
	switch (n) {
		case 0 : return input->az;
		case 1 : return input->el;
		default : errno = EINVAL; return -1;
		}}

IMPLICIT SphereCoord2f$$setall (SphereCoord2f * input,float azimuth,float elevation) {
	input->az = azimuth;
	input->el = elevation;
	}

double SphereCoord2$$at (SphereCoord2 * input,int n) {
	switch (n) {
		case 0 : return input.az;
		case 1 : return input.el;
		default : errno = EINVAL; return -1;
		}}

IMPLICIT SphereCoord2$$setall (SphereCoord2 * input,double azimuth,double elevation) {
	input->az = azimuth;
	input->el = elevation;
	}

float SphereCoord3f$$at (SphereCoord3f * input,int n) {
	switch (n) {
		case 0 : return input->az;
		case 1 : return input->el;
		case 3 : return input->rho;
		default : errno = EINVAL; return -1;
		}}

IMPLICIT SphereCoord3f$$setall (SphereCoord2f * input,float azimuth,float elevation,float range) {
	input->az = azimuth;
	input->el = elevation;
	input->rho = range;
	}

double SphereCoord3$$at (SphereCoord3 * input,int n) {
	switch (n) {
		case 0 : return input->az;
		case 1 : return input->el;
		case 2 : return input->rho;
		default : errno = EINVAL; return -1;
		}}

IMPLICIT SphereCoord3$$setall (SphereCoord3 * input,double azimuth,double elevation,double range) {
	input->az = azimuth;
	input->el = elevation;
	input->rho = range;
	}

IMPLICIT LowColor$$setall (LowColor * input,unsigned red,unsigned green,unsigned blue) {
	input->r = red;
	input->g = green;
	input->b = blue;
	}

IMPLICIT HighColor$$setall (HighColor * input,unsigned red,unsigned green,unsigned blue,_Bool alpha) {
	input->r = red;
	input->g = green;
	input->b = blue;
	}

IMPLICIT HighColorA$$setall (HighColorA * input,unsigned red,unsigned green,unsigned blue,_Bool alpha) {
	input->r = red;
	input->g = green;
	input->b = blue;
	input->a = alpha;
	}

IMPLICIT TrueColor$$setall (TrueColor * input,unsigned red,unsigned green,unsigned blue) {
	input->r = red;
	input->g = green;
	input->b = blue;
	}

IMPLICIT TrueColorA$$setall (TrueColorA * input,unsigned red,unsigned green,unsigned blue,unsigned alpha) {
	input->r = red;
	input->g = green;
	input->b = blue;
	input->a = alpha;
	}
