m4_changequote(`,´)

m4_define(`vector2functions´,`
$1 Vector2$2__at (Vector2$2 * input,int n) {
	switch (n) {
		case 0 : return input->x;
		case 1 : return input->y;
		default : errno = EINVAL; return -1;
		}}

IMPLICIT Vector2$2__setall (Vector2$2 * input,$1 xx,$1 yy) {
	input->x = xx;
	input->y = yy;
		}´)

m4_define(`vector3functions´,`
$1 Vector3$2__at (Vector3$2 * input,int n) {
	switch (n) {
		case 0 : return input->x;
		case 1 : return input->y;
		case 2 : return input->z;
		default : errno = EINVAL; return -1;
		}}

IMPLICIT Vector3$2__setall (Vector3$2 * input,$1 xx,$1 yy,$1 zz) {
	input->x = xx;
	input->y = yy;
	input->z = zz;
		}´)

m4_define(`vector4functions´,`
$1 Vector4$2__at (Vector4$2 * input,int n) {
	switch (n) {
		case 0 : return input->x;
		case 1 : return input->y;
		case 2 : return input->z;
		case 4 : return input->w;
		default : errno = EINVAL; return -1;
		}}

IMPLICIT Vector3$2__setall (Vector3$2 * input,$1 xx,$1 yy,$1 zz,$1 ww) {
	input->x = xx;
	input->y = yy;
	input->z = zz;
	input->w = ww;
		}´)

#include <stdlib.h>
#include <stdint.h>
#include "cppkeyword.h"
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

float SphereCoord2f__at (SphereCoord2f * input,int n) {
	switch (n) {
		case 0 : return input->az;
		case 1 : return input->el;
		default : errno = EINVAL; return -1;
		}}

IMPLICIT SphereCoord2f__setall (SphereCoord2f * input,float azimuth,float elevation) {
	input->az = azimuth;
	input->el = elevation;
	}

double SphereCoord2__at (SphereCoord2 * input,int n) {
	switch (n) {
		case 0 : return input.az;
		case 1 : return input.el;
		default : errno = EINVAL; return -1;
		}}

IMPLICIT SphereCoord2__setall (SphereCoord2 * input,double azimuth,double elevation) {
	input->az = azimuth;
	input->el = elevation;
	}

float SphereCoord3f__at (SphereCoord3f * input,int n) {
	switch (n) {
		case 0 : return input->az;
		case 1 : return input->el;
		case 3 : return input->rho;
		default : errno = EINVAL; return -1;
		}}

IMPLICIT SphereCoord3f__setall (SphereCoord2f * input,float azimuth,float elevation,float range) {
	input->az = azimuth;
	input->el = elevation;
	input->rho = range;
	}

double SphereCoord3__at (SphereCoord3 * input,int n) {
	switch (n) {
		case 0 : return input->az;
		case 1 : return input->el;
		case 2 : return input->rho;
		default : errno = EINVAL; return -1;
		}}

IMPLICIT SphereCoord3__setall (SphereCoord3 * input,double azimuth,double elevation,double range) {
	input->az = azimuth;
	input->el = elevation;
	input->rho = range;
	}

IMPLICIT LowColor__setall (LowColor * input,unsigned red,unsigned green,unsigned blue) {
	input->r = red;
	input->g = green;
	input->b = blue;
	}

IMPLICIT HighColor__setall (HighColor * input,unsigned red,unsigned green,unsigned blue,_Bool alpha) {
	input->r = red;
	input->g = green;
	input->b = blue;
	}

IMPLICIT HighColorA__setall (HighColorA * input,unsigned red,unsigned green,unsigned blue,_Bool alpha) {
	input->r = red;
	input->g = green;
	input->b = blue;
	input->a = alpha;
	}

IMPLICIT TrueColor__setall (TrueColor * input,unsigned red,unsigned green,unsigned blue) {
	input->r = red;
	input->g = green;
	input->b = blue;
	}

IMPLICIT TrueColorA__setall (TrueColorA * input,unsigned red,unsigned green,unsigned blue,unsigned alpha) {
	input->r = red;
	input->g = green;
	input->b = blue;
	input->a = alpha;
	}
