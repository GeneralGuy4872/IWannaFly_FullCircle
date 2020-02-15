#include <stdlib.h>
#include <stdio.h>
#include "raylib.h"
#include "raymath.h"

#define SCREENH 800
#define SCREENV 600
#define VGA(R,G,B,A) (Color){R,G,B,A}

typedef void (*funcptr)();

struct trampolinestack {
struct trampolinestack * prev;
funcptr exec;
};

struct trampolinestack * TOPTRAMPOLINE;

void PUSHTRAMPOLINE (funcptr this) {
	struct trampolinestack * new = malloc(sizeof(struct trampolinestack));
	new->exec = this;
	new->prev = TOPTRAMPOLINE;
	TOPTRAMPOLINE = new;
	}

void POPTRAMPOLINE () {
	struct trampolinestack * deadbeef = TOPTRAMPOLINE;
	TOPTRAMPOLINE = TOPTRAMPOLINE->prev;
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

Camera CAMERA;
int ECODE;

void initialize () {
	TOPTRAMPOLINE = malloc(sizeof(struct trampolinestack));
	}

main () {
	initialize();
	TOPTRAMPOLINE->exec = &ping;
	InitWindow(SCREENH,SCREENV,"IWANNAFLY VALENTINE DEVTEST");
	CAMERA.position = (Vector3){10.0,10.0,10.0};
	CAMERA.target = (Vector3){0.0,0.0,0.0};
	CAMERA.up = (Vector3){0.0,0.0,1.0};
	CAMERA.fovy = 45 * ((double) SCREENV / SCREENH);
	CAMERA.type = CAMERA_PERSPECTIVE;
	SetTargetFPS(60);
	while(!ECODE) {
		TOPTRAMPOLINE->exec();	// aren't lisp trampolines fun? boingboing!
		}
	exit(ECODE);
	}
	
