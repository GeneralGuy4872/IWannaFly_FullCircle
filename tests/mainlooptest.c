#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include "raylib.h"
#include "raymath.h"

#define SCREENH 800
#define SCREENV 600
#define EYEFOV 120.0
#define FILMFOV 55.0
#define VGA(R,G,B,A) (Color){R,G,B,A}

typedef void (*funcptr)();

struct trampolinestack {
struct trampolinestack * prev;
funcptr exec;
intptr_t (*r)[8];
void * x;
void * y;
};

struct trampolinestack * TOPTRAMPOLINE;
intptr_t ACC[8];
#define R0 TOPTRAMPOLINE->r[0];
#define R1 TOPTRAMPOLINE->r[1];
#define R2 TOPTRAMPOLINE->r[2];
#define R3 TOPTRAMPOLINE->r[3];
#define R4 TOPTRAMPOLINE->r[4];
#define R5 TOPTRAMPOLINE->r[5];
#define R6 TOPTRAMPOLINE->r[6];
#define R7 TOPTRAMPOLINE->r[7];
#define IX TOPTRAMPOLINE->x;
#define IY TOPTRAMPOLINE->y;

void PUSHTRAMPOLINE (funcptr this) {
	struct trampolinestack * new = malloc(sizeof(struct trampolinestack));
	new->exec = this;
	new->prev = TOPTRAMPOLINE;
	new->r = calloc(8,sizeof(int));
	new->x = TOPTRAMPOLINE->x;
	new->y = TOPTRAMPOLINE->y;
	TOPTRAMPOLINE = new;
	}

void POPTRAMPOLINE () {
	struct trampolinestack * deadbeef = TOPTRAMPOLINE;
	TOPTRAMPOLINE = TOPTRAMPOLINE->prev;
	free(deadbeef->r);
	if (deadbeef->x != TOPTRAMPOLINE->x) {free(deadbeef->x);};
	if (deadbeef->y != TOPTRAMPOLINE->y) {free(deadbeef->y);};
	free(deadbeef);
	}

void flip ();
void flop ();
void ping ();

void pong () {
	printf("PONG!!!");
	int next;
	next = rand() % 4;
	switch (next) {
		case 0 : TOPTRAMPOLINE->exec = &ping; break;
		case 1 : TOPTRAMPOLINE->exec = &pong; break;
		case 2 : TOPTRAMPOLINE->exec = &flip; break;
		case 3 : TOPTRAMPOLINE->exec = &flop; break;
		default : break;
		}
	}

void ping () {
	printf("PING!!!");
	int next;
	next = rand() % 4;
	switch (next) {
		case 0 : TOPTRAMPOLINE->exec = &ping; break;
		case 1 : TOPTRAMPOLINE->exec = &pong; break;
		case 2 : TOPTRAMPOLINE->exec = &flip; break;
		case 3 : TOPTRAMPOLINE->exec = &flop; break;
		default : break;
		}
	}

void flip () {
	printf("FLIP!!!");
	int next;
	next = rand() % 4;
	switch (next) {
		case 0 : TOPTRAMPOLINE->exec = &ping; break;
		case 1 : TOPTRAMPOLINE->exec = &pong; break;
		case 2 : TOPTRAMPOLINE->exec = &flip; break;
		case 3 : TOPTRAMPOLINE->exec = &flop; break;
		default : break;
		}
	}

void flop () {
	printf("FLOP!!!");
	int next;
	next = rand() % 4;
	switch (next) {
		case 0 : TOPTRAMPOLINE->exec = &ping; break;
		case 1 : TOPTRAMPOLINE->exec = &pong; break;
		case 2 : TOPTRAMPOLINE->exec = &flip; break;
		case 3 : TOPTRAMPOLINE->exec = &flop; break;
		default : break;
		}
	}

Camera3D CAMERA;
int CAMERAMODE;
int ECODE;

void initialize () {
	TOPTRAMPOLINE = malloc(sizeof(struct trampolinestack));
	}

render () {
	UpdateCamera(&CAMERA);
	BeginDrawing();
		ClearBackground(VGA(0,0,0,0xFF));
		BeginMode3D(CAMERA);
		DrawCube((Vector3){10.0,0.0,0.0},1.0,1.0,1.0,VGA(0,0,0xFF,0xFF));
		DrawCube((Vector3){-10.0,0.0,0.0},1.0,1.0,1.0,VGA(0xFF,0xFF,0,0xFF));
		DrawCube((Vector3){0.0,10.0,0.0},1.0,1.0,1.0,VGA(0xFF,0,0,0xFF));
		DrawCube((Vector3){0.0,-10.0,0.0},1.0,1.0,1.0,VGA(0,0xFF,0xFF,0xFF));
		DrawCube((Vector3){0.0,0.0,10.0},1.0,1.0,1.0,VGA(0,0xFF,0,0xFF));
		DrawCube((Vector3){0.0,0.0,-10.0},1.0,1.0,1.0,VGA(0xFF,0,0xFF,0xFF));
		DrawCube((Vector3){0.0,0.0,0.0},1.0,1.0,1.0,VGA(0x7F,0x7F,0x7F,0xFF));
		EndMode3D();
	EndDrawing();
	return 0;
	}

main () {
	initialize();
	TOPTRAMPOLINE->exec = &ping;
	InitWindow(SCREENH,SCREENV,"IWANNAFLY DEVTEST 2");
	CAMERA.position = (Vector3){0.0,0.0,0.0};
	CAMERA.target = (Vector3){1.0,0.0,0.0};
	CAMERA.up = (Vector3){0.0,1.0,0.0};
	CAMERA.fovy = EYEFOV;
	CAMERA.type = CAMERA_PERSPECTIVE;
	SetCameraMode(CAMERA,CAMERA_FIRST_PERSON);
	CAMERAMODE = CAMERA_FIRST_PERSON;
	SetTargetFPS(60);
	while(!ECODE) {
		if ((IsKeyDown(KEY_F1)) && (CAMERAMODE != CAMERA_FIRST_PERSON)) {
			CAMERA.fovy = EYEFOV;
			CAMERA.position = (Vector3){0.0,0.0,0.0};
			SetCameraMode(CAMERA,CAMERA_FIRST_PERSON);
			CAMERAMODE = CAMERA_FIRST_PERSON;
		} else if ((IsKeyDown(KEY_F2)) && (CAMERAMODE != CAMERA_CUSTOM)) {	
			SetCameraMode(CAMERA,CAMERA_CUSTOM);
			EnableCursor();
			CAMERAMODE = CAMERA_CUSTOM;
		} else if ((IsKeyDown(KEY_F3)) && (CAMERAMODE != CAMERA_THIRD_PERSON)) {	
			CAMERA.fovy = FILMFOV;
			SetCameraMode(CAMERA,CAMERA_THIRD_PERSON);
			CAMERAMODE = CAMERA_THIRD_PERSON;
			};
		if ((IsKeyDown(KEY_PAGE_UP)) && (CAMERA.fovy >= 5)) {
			CAMERA.fovy -= 1.0;
		} else if ((IsKeyDown(KEY_PAGE_DOWN)) && (CAMERA.fovy < 179)) {
			CAMERA.fovy += 1.0;
		} else if (IsKeyDown(KEY_HOME)) {
			switch (CAMERAMODE) {
				case CAMERA_FIRST_PERSON : CAMERA.fovy = EYEFOV; break;
				case CAMERA_THIRD_PERSON : CAMERA.fovy = FILMFOV; break;
				default : break;
				}
			};
		render();	/* will be replaced by seperate iterators,
				 * which will be stored so that only one from each list
				 * needs to be rendered each loop
				 */
		TOPTRAMPOLINE->exec();	// aren't lisp trampolines fun? boingboing!
		}
	exit(ECODE);
	}
	
