
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
