#ifndef __GG4872_VECTOR_H__
#define __GG4872_VECTOR_H__

#ifndef __cplusplus
#include <stdlib.h>
#include <stdint.h>
#else
#include <cstdint>
extern "C" {
#endif

#include "cppkeyword.h"

makevector2(char8_t,s8)
makevector2(uchar8_t,u8)
makevector2(char16_t,s16)
makevector2(uchar16_t,u16)
makevector2(char32_t,s32)
makevector2(uchar32_t,u32)
makevector2(char64_t,s64)
makevector2(uchar64_t,u64)
makevector2(int,i)
makevector2(float,f)
makevector2(double,NIL)

makevector3(char8_t,s8)
makevector3(uchar8_t,u8)
makevector3(char16_t,s16)
makevector3(uchar16_t,u16)
makevector3(char32_t,s32)
makevector3(uchar32_t,u32)
makevector3(char64_t,s64)
makevector3(uchar64_t,u64)
makevector3(int,i)
makevector3(float,f)
makevector3(double,NIL)

makevector4(char8_t,s8)
makevector4(uchar8_t,u8)
makevector4(char16_t,s16)
makevector4(uchar16_t,u16)
makevector4(char32_t,s32)
makevector4(uchar32_t,u32)
makevector4(char64_t,s64)
makevector4(uchar64_t,u64)
makevector4(int,i)
makevector4(float,f)
makevector4(double,NIL)

STRUCTTYPE(Vector2sNybble,{signed y : 4;signed x : 4;})
STRUCTTYPE(Vector2uNybble,{unsigned y : 4;unsigned x : 4;})
STRUCTTYPE(Vector4sNybble,{signed w : 4;signed z : 4;signed y : 4;signed x : 4;})
STRUCTTYPE(Vector4uNybble,{unsigned w : 4;unsigned z : 4;unsigned y : 4;unsigned x : 4;})
Vector2sNybble LiteralVector2sNybble(signed x,signed y) {return (Vector2sNybble){y,x};}
Vector2uNybble LiteralVector2uNybble(unsigned x,unsigned y) {return (Vector2uNybble){y,x};}
Vector4sNybble LiteralVector4sNybble(signed x,signed y,signed z,signed w) {return (Vector4sNybble){w,z,y,x};}
Vector4uNybble LiteralVector4uNybble(unsigned x,unsigned y,unsigned z,unsigned w) {return (Vector4uNybble){w,z,y,x};}

STRUCTTYPE(SphereCoord2f,{float az;float el;})
STRUCTTYPE(SphereCoord2,{double az;double el;})
STRUCTTYPE(SphereCoord3f,{float az;float el;float rho;})
STRUCTTYPE(SphereCoord3,{double az;double el;double rho;})

STRUCTTYPE(LowColor,{unsigned r : 3;unsigned g : 3;unsigned b : 2;})
STRUCTTYPE(HighColor,{unsigned r : 5;unsigned g : 6;unsigned b : 5})
STRUCTTYPE(HighColorA,{unsigned r : 5;unsigned g : 5;unsigned b : 5;_Bool a : 1})
STRUCTTYPE(TrueColor,{uint8_t r;uint8_t g;uint8_t b})
STRUCTTYPE(TrueColorA,{uint8_t r;uint8_t g;uint8_t b;uint8_t a})

vector2linkage(char8_t,s8)
vector2linkage(uchar8_t,u8)
vector2linkage(char16_t,s16)
vector2linkage(uchar16_t,u16)
vector2linkage(char32_t,s32)
vector2linkage(uchar32_t,u32)
vector2linkage(char64_t,s64)
vector2linkage(uchar64_t,u64)
vector2linkage(int,i)
vector2linkage(float,f)
vector2linkage(double,NIL)

vector3linkage(char8_t,s8)
vector3linkage(uchar8_t,u8)
vector3linkage(char16_t,s16)
vector3linkage(uchar16_t,u16)
vector3linkage(char32_t,s32)
vector3linkage(uchar32_t,u32)
vector3linkage(char64_t,s64)
vector3linkage(uchar64_t,u64)
vector3linkage(int,i)
vector3linkage(float,f)
vector3linkage(double,NIL)

vector4linkage(char8_t,s8)
vector4linkage(uchar8_t,u8)
vector4linkage(char16_t,s16)
vector4linkage(uchar16_t,u16)
vector4linkage(char32_t,s32)
vector4linkage(uchar32_t,u32)
vector4linkage(char64_t,s64)
vector4linkage(uchar64_t,u64)
vector4linkage(int,i)
vector4linkage(float,f)
vector4linkage(double,NIL)

vector2linkage(unsigned,uNybble)
vector2linkage(signed,sNybble)
vector4linkage(unsigned,uNybble)
vector4linkage(signed,sNybble)

float SphereCoord2f__at (SphereCoord2f * input,int n);
IMPLICIT SphereCoord2f__setall (SphereCoord2f * input,float az,float el);
double SphereCoord2__at (SphereCoord2 * input,int n);
IMPLICIT SphereCoord2__setall (SphereCoord2 * input,double az,double el);

float SphereCoord3f__at (SphereCoord3f * input,int n);
IMPLICIT SphereCoord3f__setall (SphereCoord3f * input,float az,float el,float rho);
double SphereCoord3__at (SphereCoord3 * input,int n);
IMPLICIT SphereCoord3__setall (SphereCoord3 * input,double az,double el);

IMPLICIT LowColor__setall (unsigned red,unsigned green,unsigned blue);
IMPLICIT HighColor__setall (unsigned red,unsigned green,unsigned blue);
IMPLICIT HighColorA__setall (unsigned red,unsigned green,unsigned blue,_Bool alpha);
IMPLICIT TrueColor__setall (unsigned red,unsigned green,unsigned blue);
IMPLICIT TrueColorA__setall (unsigned red,unsigned green,unsigned blue,unsigned alpha);

#ifdef __cplusplus
}
#endif
#endif
