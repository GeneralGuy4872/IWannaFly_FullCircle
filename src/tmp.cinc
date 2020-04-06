
render3D () {	//will be replaced with iterators to render moving objects
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

