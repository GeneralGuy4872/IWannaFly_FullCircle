#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "raylib.h"
#include "raymath.h"

#define SCREENH 800
#define SCREENV 600
#define EYEFOV 120.0
#define FILMFOV 55.0

//define G_EARTH 9.80665
//define G_MOON 1.625
//define G_MARS 3.72076

typedef void (*tcallptr)();
typedef void *registers[8];

struct trampolinestack {
struct trampolinestack * prev;
tcallptr exec;
void *(*r)[8];
};

/* trampoline functions manipulate a callstack manually.
 * extra returns are placed in the oroborus array.
 */
struct trampolinestack * TOPTRAMPOLINE;
unsigned SP = 1;
#define EXEC TOPTRAMPOLINE->exec
#define RP TOPTRAMPOLINE->r
#define R0 (*(RP))[0]
#define R1 (*(RP))[1]
#define R2 (*(RP))[2]
#define R3 (*(RP))[3]
#define R4 (*(RP))[4]
#define R5 (*(RP))[5]
#define R6 (*(RP))[6]
#define R7 (*(RP))[7]
#define UP TOPTRAMPILINE->prev->r
#define U0 (*(UP))[0]
#define U1 (*(UP))[1]
#define U2 (*(UP))[2]
#define U3 (*(UP))[3]
#define U4 (*(UP))[4]
#define U5 (*(UP))[5]
#define U6 (*(UP))[6]
#define U7 (*(UP))[7]

void PUSHTRAMPOLINE (tcallptr this,intptr_t frame[8]) {
	struct trampolinestack * new = malloc(sizeof(struct trampolinestack));
	new->exec = this;
	new->prev = TOPTRAMPOLINE;
	new->r = calloc(8,sizeof(void*));
	memcpy(new->r,frame,8 * sizeof(intptr_t));
	TOPTRAMPOLINE = new;
	}

void POPTRAMPOLINE () {
	struct trampolinestack * deadbeef = TOPTRAMPOLINE;
	TOPTRAMPOLINE = TOPTRAMPOLINE->prev;
	free(deadbeef->r);
	free(deadbeef);
	}

void flip ();
void flop ();
void ping ();

void pong () {
	printf("PONG!!!");
	R1 += 1;
	int next;
	next = rand() % 4;
	switch (next) {
		case 0 : EXEC = &ping; break;
		case 1 : EXEC = &pong; break;
		case 2 : EXEC = &flip; break;
		case 3 : EXEC = &flop; break;
		default : break;
		}
	}

void ping () {
	printf("PING!!!");
	R0 += 1;
	int next;
	next = rand() % 4;
	switch (next) {
		case 0 : EXEC = &ping; break;
		case 1 : EXEC = &pong; break;
		case 2 : EXEC = &flip; break;
		case 3 : EXEC = &flop; break;
		default : break;
		}
	}

void flip () {
	printf("FLIP!!!");
	R2 += 1;
	int next;
	next = rand() % 4;
	switch (next) {
		case 0 : EXEC = &ping; break;
		case 1 : EXEC = &pong; break;
		case 2 : EXEC = &flip; break;
		case 3 : EXEC = &flop; break;
		default : break;
		}
	}

void flop () {
	printf("FLOP!!!");
	R3 += 1;
	int next;
	next = rand() % 4;
	switch (next) {
		case 0 : EXEC = &ping; break;
		case 1 : EXEC = &pong; break;
		case 2 : EXEC = &flip; break;
		case 3 : EXEC = &flop; break;
		default : break;
		}
	}

Camera3D CAMERA;
int CAMERAMODE;
int ECODE;

void initialize () {
	TOPTRAMPOLINE = calloc(1,(sizeof(struct trampolinestack)));
	TOPTRAMPOLINE->r = calloc(8,(sizeof(void*)));
	}

render () {	//will be replaced with iterators to render moving objects
	UpdateCamera(&CAMERA);
	BeginDrawing();
		ClearBackground((Color){0,0,0,0xFF});
		BeginMode3D(CAMERA);
		DrawCube((Vector3){10.0,0.0,0.0},1.0,1.0,1.0,(Color){0,0,0xFF,0xFF});
		DrawCube((Vector3){-10.0,0.0,0.0},1.0,1.0,1.0,(Color){0xFF,0xFF,0,0xFF});
		DrawCube((Vector3){0.0,10.0,0.0},1.0,1.0,1.0,(Color){0xFF,0,0,0xFF});
		DrawCube((Vector3){0.0,-10.0,0.0},1.0,1.0,1.0,(Color){0,0xFF,0xFF,0xFF});
		DrawCube((Vector3){0.0,0.0,10.0},1.0,1.0,1.0,(Color){0,0xFF,0,0xFF});
		DrawCube((Vector3){0.0,0.0,-10.0},1.0,1.0,1.0,(Color){0xFF,0,0xFF,0xFF});
		DrawCube((Vector3){0.0,0.0,0.0},1.0,1.0,1.0,(Color){0x7F,0x7F,0x7F,0xFF});
		DrawCube((Vector3){((float)((intptr_t)R0))/100.0,0.0,((float)((intptr_t)R0))/100.0},0.5,0.5,0.5,(Color){0xFF,0,0,0xFF});
		DrawCube((Vector3){-((float)((intptr_t)R1))/100.0,0.0,((float)((intptr_t)R1))/100.0},0.5,0.5,0.5,(Color){0xFF,0xFF,0,0xFF});
		DrawCube((Vector3){-((float)((intptr_t)R2))/100.0,0.0,-((float)((intptr_t)R2))/100.0},0.5,0.5,0.5,(Color){0,0xFF,0,0xFF});
		DrawCube((Vector3){((float)((intptr_t)R3))/100.0,0.0,-((float)((intptr_t)R3))/100.0},0.5,0.5,0.5,(Color){0,0,0xFF,0xFF});
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
	while(!ECODE && SP) {
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
		render();
		EXEC();	// aren't lisp trampolines fun? boingboing!
		}
	exit(ECODE);
	}
	
