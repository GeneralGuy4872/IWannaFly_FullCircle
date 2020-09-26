std::atomic_bool ODE_FINISH_SYNC;
std::atomic_bool ODE_INTREQ;
std::atomic_bool ODE_IACK;

std::atomic_bool IRR_FINISH_SYNC;
std::atomic_bool IRR_INTREQ;
std::atomic_bool IRR_IACK;

dWorldID WORLD;
dSpaceID SPACE;
dJointGroupID COLLISIONGROUP;

struct BlockTag {
	IMeshSceneNode * node;
	dGeomID geom;
	};

std::vector<BlockTag> BLOCKBANK;

struct EntTag {
	IMeshSceneNode * irrnode;
	dBodyID body;
	dGeomID geom;
	dMass mass;
	};

std::vector<EntTag> ENTITIES;
//will be seperated into different kinds of entities later

initialize () {
	dInitODE2(0);
	WORLD = dWorldCreate();
	dWorldSetGravity(WORLD,0,0,-1.5);
	SPACE = dSimpleSpaceCreate(0);
	COLLISION = dJointGroupCreate(0);
	…


//add to main
for (;;) {
	if (ODE_IREQ) {
		ODE_IACK = true;
		while (ODE_IREQ);
		ODE_IACK = false;
		}
	
	ODE_FINISH_SYNC = true;
	while (IRR_FINISH_SYNC != ODE_FINISH_SYNC);
	{
	dReal * tmp;
	dMatrix3 ident;
	dRSetIdentity(ident);
	for (std::map<int16_t,EntTag>::iterator i = ENTITIES.begin();i != ENTITIES.end();i++) {
		tmp = dGeomGetPosition(i->geom);
		i->node->SetPosition(irr::core::vector3df(tmp[0],tmp[1],tmp[2]));
		dGeomSetRotation(i->geom,ident);
	}}}


iwf$$DEBUGcreatevoxel() {
	BlockTag nova;
	{
	dReal tmpX = iwf$$raw16$$coord3$$get$x(coord);
	dReal tmpY = iwf$$raw16$$coord3$$get$y(coord);
	dReal tmpZ = iwf$$raw16$$coord3$$get$z(coord);
	dGeomID tmp = dCreateBox(SPACE, 2.5 , 2.5 , 2.5);
	dGeomSetPosition(tmp,tmpX,tmpY,tmpZ);
	nova.geom = tmp;
	}{
	irr::scene::IMeshSceneNode * tmp = irrcontext::addCubeSceneNode(
		2.5f,
		NULL,
		0,
		irr::core::vector3df(
			iwf$$raw16$$coord$$get$x(coord),
			iwf$$raw16$$coord$$get$y(coord),
			iwf$$raw16$$coord$$get$z(coord)
		);
	nova.node = tmp;
	}
	BLOCKBANK.push_back(nova);
	}
