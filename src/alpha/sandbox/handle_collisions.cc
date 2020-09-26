/* This file is derived from an example in the documentation at
 * http://www.ode.org/ode-latest-userguide.html
 *
 * This file is released under the same terms as the OpenDynamics Engine
 */

#define MAX_NUM_CONTACTS 3
#define ODE_MU
#define ODE_SOFT_ERP
#define ODE_SOFT_CFM
#define ODE_BOUNCY
#define TIME_STEP

void handle_collisions (void * data, dGeomID geom1, dGeomID geom2) {
	if (dGeomIsSpace(o1) || dGeomIsSpace(o2)) {
		dSpaceCollide2(o1,o2,data,&handle_collisions);
		if (dGeomIsSpace(o1))
			dSpaceCollide(o1,data,&handle_collisions);
		if (dGeomIsSpace(o2))
			dSpaceCollide(o2,data,&handle_collisions);
		}

	dBodyID body1 = dGeomGetBody(geom1);
	dBodyID body2 = dGeomGetBody(geom2);

	dContact contacts[MAX_NUM_CONTACTS];
	int numc = dCollide(geom1, geom2, MAX_NUM_CONTACTS, &contacts[0].geom, sizeof(dContact));

	for (int i = 0; i < numc; ++i) {
		contacts[i].surface.mode =
			dContactBounce
			|
			dContactSoftERP
			|
			dContactSoftCFM
			|
			dContactApprox1
			|
			dContactSlip1
			|
			dContactSlip2;

		contacts[i].surface.mu = ODE_MU;
		contacts[i].surface.soft_erp = ODE_SOFT_ERP;
		contacts[i].surface.soft_cfm = ODE_SOFT_CFM;
		contacts[i].surface.bounce = ODE_BOUNCINESS;

		dJointID contact =
			dJointCreateContact(
				WORLD,
				COLLISIONS,
				&contacts[i]);

		dJointAttach(contact, body1, body2);
	}}

for (;;) {
	for (std::map<int16_t,EntTag>::iterator i = ENTITIES.begin();i != ENTITIES.end();i++) {
		
	dSpaceCollide(SPACE,NULL,&handle_collisions);
	dWorldStep(WORLD,TIME_STEP);
