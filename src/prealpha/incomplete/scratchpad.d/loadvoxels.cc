static const float eightpieces[2][2][2][3] = {
	-0.5,-0.5,-0.5,
	-0.5,-0.5, 0.5,
	-0.5, 0.5,-0.5,
	-0.5, 0.5, 0.5,
	 0.5,-0.5,-0.5,
	 0.5,-0.5, 0.5,
	 0.5, 0.5,-0.5,
	 0.5, 0.5, 0.5};

for (int x = 0;x < 32;x++) {
	for (int y = 0;y < 32;y++) {
		for (int z = 0;z < 32;z++) {
			irr::core::vector3df vtmp((32 * (xxx - 3)) + (x - 15.5),(32 * (yyy - 3)) + (y - 15.5),(32 * (zzz - 3)) + (z - 15.5));
			if (irrcontext::voxels.contains(iwf$$raw32$$voxelnodeid$$pack(xxx,yyy,zzz,x,y,z,1,0,0,0)) {
				irrcontext::voxels.at(iwf$$raw32$$voxelnodeid$$pack(xxx,yyy,zzz,x,y,z,1,0,0,0))->remove();
				irrcontext::voxels.erase(iwf$$raw32$$voxelnodeid$$pack(xxx,yyy,zzz,x,y,z,1,0,0,0));
				}
			for (int octx = 0;octx < 2;octx++) {
				for (int octy = 0;octy < 2;octy++) {
					for (int octz = 0;octz < 2;octz++) {
						if (irrcontext::voxels.contains(iwf$$raw32$$voxelnodeid$$pack(xxx,yyy,zzz,x,y,z,0,octx,octy,octz)) {
							irrcontext::voxels.at(iwf$$raw32$$voxelnodeid$$pack(xxx,yyy,zzz,x,y,z,0,octx,octy,octz))->remove();
							irrcontext::voxels.erase(iwf$$raw32$$voxelnodeid$$pack(xxx,yyy,zzz,x,y,z,0,octx,octy,octz));
				}}}}
			if (object->subtiles[z][y][x] == -1) {
				irrcontext::voxels[iwf$$raw32$$voxelnodeid$$pack(xxx,yyy,zzz,x,y,z,1,0,0,0)] = irrcontext::sm->addCubeSceneNode(1,irrcontext::chunks[zzz][yyy][xxx],iwf$$raw32$$voxelnodeid$$pack(xxx,yyy,zzz,x,y,z,1,0,0,0),vtmp);
				irrcontext::voxels.at(iwf$$raw32$$voxelnodeid$$pack(xxx,yyy,zzz,x,y,z,1,0,0,0))->setMaterialTexture(0,irrcontext::textures::cache.get((*(object->tilesets[iwf$$raw8$$tileref$$getbank(object->tiles[z][y][x])]))[iwf$$raw8$$tileref$$gettile(object->tiles[z][y][x])]);	//resolve a dispatch table
			} else {
				irr::core::vector3df vtmp2;
					for (int d;d < 2;d++) {
						for (int e;e < 2;e++) {
							for (int f;f < 2;f++) {
								if (object->subtiles & (1 << ((d << 2)|(e << 1)|f))) {
									irr::core::vector3df vtmp2 = vtmp;
									irr::core::vector3df vtmp2.x += eightpieces[a][b][c][0];
									irr::core::vector3df vtmp2.y += eightpieces[a][b][c][1];
									irr::core::vector3df vtmp2.z += eightpieces[a][b][c][2];
									irrcontext::voxels[iwf$$raw32$$voxelnodeid$$pack(xxx,yyy,zzz,x,y,z,0,d,e,f)] = irrcontext::sm->addCubeSceneNode(1,irrcontext::chunks[zzz][yyy][xxx],iwf$$raw32$$voxelnodeid$$pack(xxx,yyy,zzz,x,y,z,0,d,e,f),vtmp2);
									irrcontext::voxels.at(iwf$$raw32$$voxelnodeid$$pack(xxx,yyy,zzz,x,y,z,0,d,e,f))->setMaterialTexture(0,irrcontext::textures::cache.get((*(object->tilesets[iwf$$raw8$$tileref$$getbank(object->tiles[z][y][x])]))[iwf$$raw8$$tileref$$gettile(object->tiles[z][y][x])]);	//resolve a dispatch table
	}}}}}}}}	//the heck is this, lisp?
