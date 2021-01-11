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

struct CounterweightsInternalData {
	dJointGroupID group;
	dJointID bolts[6];
	}

struct Counterweights {
	CounterweightsInternalData data;
	dBodyID body[6];
	double upvector[3];
	double rightfactor;
	}

iwf$$physics$$update_counterweights_direct (Counterweights * object) {
	dMass tmp;
	
	dMassSetTotalSphere(&tmp,
		(object->upvector[0] * object->rightfactor * -1),
		0.00001);
	dBodySetMass(object->body[0] , &tmp);

	dMassSetTotalSphere(&tmp,
		(object->upvector[0] * object->rightfactor)
		0.00001);
	dBodySetMass(object->body[1] , &tmp);

	dMassSetTotalSphere(&tmp,
		(object->upvector[1] * object->rightfactor * -1),
		0.00001);
	dBodySetMass(object->body[2] , &tmp);

	dMassSetTotalSphere(&tmp,
		(object->upvector[1] * object->rightfactor),
		0.00001);
	dBodySetMass(object->body[3] , &tmp);

	dMassSetTotalSphere(&tmp,
		(object->upvector[2] * object->rightfactor * -1),
		0.00001);
	dBodySetMass(object->body[4] , &tmp);

	dMassSetTotalSphere(&tmp,
		(object->upvector[2] * object->rightfactor),
		0.00001);
	dBodySetMass(object->body[5] , &tmp);

	return 0;
	}

struct EntTag {
	IMeshSceneNode * irrnode;
	dBodyID body;
	dGeomID geom;
	Counterweights cwt;
	};

#define IWF__PHYSICS__SET_COUNTERWEIGHT_MASS(O,F) O->cwt->rightfactor = F
#define IWF__PHYSICS__SET_COUNTERWEIGHT_DIRECTION(O,X,Y,Z) O->cwt->upvector[0] = X,O->cwt->upvector[1] = Y,O->cwt->upvector[2] = Z
#define IWF__PHYSICS__UPDATE_COUNTERWEIGHT(O) iwf$$physics$$update_counterweights_direct(O->cwt)

iwf$$physics$$create_entity (IMeshSceneNode * node,double x,double y,double z,double r,double l,double m,int ode_direction) {
	EntTag * nova = calloc(1,sizeof(EntTag));
	nova->irrnode = node;
	nova->body = dBodyCreate(WORLD);
	dBodySetPosition(nova->body,x,y,z);
	{
	dMass tmp;
	dMassSetCappedCylinderTotal(&tmp,m,ode_direction,r,l);
	dBodySetMass(nova->body,mass);
	}
	nova->geom = dCreateCCylinder(SPACE,r,l);
	dGeomSetBody(nova->geom,nova->body);

	nova->cwt->data->group = dJointGroupCreate(0);
	{
	dMass tmp;
	dMassSetTotalSphere(&tmp,0,0.00001);
	for (int i = 0;i < 6;i++) {
		nova->cwt->body[i] = dBodyCreate(WORLD);
		dBodySetMass(&tmp);
	}}

	dBodySetPosition(nova->cwt->body[0] , 0.9 * r , 0.0 , 0.0);
	dBodySetPosition(nova->cwt->body[1] ,-0.9 * r , 0.0 , 0.0);
	dBodySetPosition(nova->cwt->body[2] , 0.0 , 0.9 * r , 0.0);
	dBodySetPosition(nova->cwt->body[3] , 0.0 ,-0.9 * r , 0.0);
	dBodySetPosition(nova->cwt->body[4] , 0.0 , 0.0 , 0.9 * r);
	dBodySetPosition(nova->cwt->body[5] , 0.0 , 0.0 ,-0.9 * r);
	for (int i = 0;i < 6;i++) {
		nova->cwt->data->bolt[i] = dJointCreateFixed(WORLD,nova->cwt->data->group);
		dJointAttatch(nova->cwt->data->bolt[i] , nova->body , nova->cwt->body[i]);
		}

	ENTITIES.push_back(nova);
	return 0;
	}

std::vector<EntTag *> ENTITIES;
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
