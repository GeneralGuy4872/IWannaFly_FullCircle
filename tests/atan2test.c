#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define GON2RAD (M_PI / 200)
#define RAD2GON (200 / M_PI)
#define DEG2RAD (M_PI / 180)
#define RAD2DEG (180 / M_PI)

#define BOUND_LAW_LAWGOOD (60 * DEG2RAD)
#define BOUND_GOOD_LAWGOOD (30 * DEG2RAD)
#define BOUND_GOOD_CHAGOOD (-30 * DEG2RAD)
#define BOUND_CHA_CHAGOOD (-60 * DEG2RAD)
#define BOUND_CHA_CHAEVIL (-120 * DEG2RAD)
#define BOUND_EVIL_CHAEVIL (-150 * DEG2RAD)
#define BOUND_EVIL_LAWEVIL (150 * DEG2RAD)
#define BOUND_LAW_LAWEVIL (120 * DEG2RAD)

main () {
	float x;
	float y;
	double angle;
	puts("input a number:");
	scanf("%f",&x);
	puts("input a number:");
	scanf("%f",&y);
	angle = atan2(y,x);
	if ((angle <= BOUND_GOOD_LAWGOOD) && (angle >= BOUND_GOOD_CHAGOOD)) {
		puts("GOOD");
	} else if (angle > 0) {
		if ((angle > BOUND_GOOD_LAWGOOD) && (angle < BOUND_LAW_LAWGOOD)) {
			puts("LAWFUL GOOD");
		} else if ((angle >= BOUND_LAW_LAWGOOD) && (angle <= BOUND_LAW_LAWEVIL)) {
			puts("LAWFUL");
		} else if ((angle > BOUND_LAW_LAWEVIL) && (angle < BOUND_EVIL_LAWEVIL)) {
			puts("LAWFUL EVIL");
		} else {
			puts("EVIL");
		}
	} else {
		if ((angle > BOUND_GOOD_CHAGOOD) && (angle < BOUND_CHA_CHAGOOD)) {
			puts("CHAOTIC GOOD");
		} else if ((angle >= BOUND_CHA_CHAGOOD) && (angle <= BOUND_CHA_CHAEVIL)) {
			puts("CHAOTIC");
		} else if ((angle > BOUND_CHA_CHAEVIL) && (angle < BOUND_EVIL_CHAEVIL)) {
			puts("CHAOTIC EVIL");
		} else {
			puts("EVIL");
		}}
	printf("azimuth of {%f,%f} is %f°\n",x,y,angle * RAD2DEG);
	}
	

