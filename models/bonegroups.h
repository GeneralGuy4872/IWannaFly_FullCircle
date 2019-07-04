#define doublelink(M) M->prev->next = M
#define macrodelete(T,M) {M.prev != NULL ? ((T*)M.prev)->next = M.next : noop(); M.next != NULL ? ((T*)M.next)->prev = M.prev : noop(); free(&M)}

void deletent(xyzzy)
	entity xyzzy;
	{
	if (xyzzy.prev != NULL)
		{
		((entity*)xyzzy.prev)->next = xyzzy.next;
		}
	else
		{
		HARD_ERROR_MACRO;
		}
	if (xyzzy.next != NULL)
		{
		((entity*)xyzzy.next)->prev = xyzzy.prev;
		}
	else
		{
		WORLD.ent_tail = xyzzy.prev;
		}
	free(&xyzzy);
	}

void deletscn(xyzzy)
	thing xyzzy;
	{
	if (xyzzy.prev != NULL)
		{
		((thing*)xyzzy.prev)->next = xyzzy.next;
		}
	else
		{
		WORLD.scen = xyzzy.next;
		}
	if (xyzzy.next != NULL)
		{
		((thing*)xyzzy.next)->prev = xyzzy.prev;
		}
	else
		{
		WORLD.scen_tail = xyzzy.prev;
		}
	free(&xyzzy);
	}

void deletevnt(xyzzy)
	mainh_event xyzzy;
	{
	if (xyzzy.prev != NULL)
		{
		((mainh_event*)xyzzy.prev)->next = xyzzy.next;
		}
	else
		{
		WORLD.evnt = xyzzy.next;
		}
	if (xyzzy.next != NULL)
		{
		((mainh_event*)xyzzy.next)->prev = xyzzy.prev;
		}
	else
		{
		WORLD.evnt_tail = xyzzy.prev;
		}
	free(&xyzzy);
	}

//use of irrational constants is as a starting point, will fine-tune values later

struct bone* spine(root,prev,nmax,fr_len,color)
  struct bone *prev;
  struct bone *root;
  unsigned char nmax;
  unsigned short fr_len;
  rgbi_param color;
  {
  float len = frfl(fr_len);
  struct bone verta[10];
  for (unsigned char n = 0;n < nmax;n++)
    {
    verta[n] = (bone){root,prev,NULL,{0,0,n!=0 * FR_ONE},{0,0,len/nmax},matgen_ident,matgen_ident,rgbi(color.r,color.g,color.b,color.i,color.a),color.uv,TRUE,NULL};
    prev->next = &verta[n];
    prev = &verta[n];
    }
  return &verta[nmax-1];
  }

struct bone* offspine(root,prev,nmax,fr_len,color)
  struct bone *prev;
  struct bone *root;
  unsigned char nmax;
  unsigned short fr_len;
  rgbi_param color;
  {
  float len = frfl(fr_len);
  struct bone verta[10];
  for (unsigned char n = 0;n < nmax;n++)
    {
    verta[n] = (bone){root,prev,NULL,{0,0,FR_ONE},{0,0,len/nmax},matgen_ident,matgen_ident,rgbi(color.r,color.g,color.b,color.i,color.a),color.uv,TRUE,NULL};
    prev->next = &verta[n];
    prev = &verta[n];
    }
  return &verta[nmax-1];
  }
  
struct bone* xtail(root,prev,nmax,fr_len,color)
  struct bone *prev;
  struct bone *root;
  unsigned char nmax;
  unsigned short fr_len;
  rgbi_param color;
  {
  float len = frfl(fr_len);
  struct bone verta[10];
  for (unsigned char n = 0;n < nmax;n++)
    {
    verta[n] = (bone){root,prev,NULL,{-FR_ONE,0,0},{-len/nmax,0,0},matgen_ident,matgen_ident,rgbi(color.r,color.g,color.b,color.i,color.a),color.uv,TRUE,NULL};
    prev->next = &verta[n];
    prev = &verta[n];
    }
  return &verta[nmax-1];
  }
  
struct bone* ztail(root,prev,nmax,fr_len,color)
  struct bone *prev;
  struct bone *root;
  unsigned char nmax;
  unsigned short fr_len;
  rgbi_param color;
  {
  float len = flfr(fr_len);
  struct bone verta[10];
  for (unsigned char n = 0;n < nmax;n++)
    {
    verta[n] = (bone){root,prev,NULL,{0,0,-FR_ONE},{-len/nmax,0,0},matgen_ident,matgen_ident,rgbi(color.r,color.g,color.b,color.i,color.a),color.uv,TRUE,NULL};
    prev->next = &verta[n];
    prev = &verta[n];
    }
  return &verta[nmax-1];
  }

struct bone* handphalanges(root,prev,nmax,fr_rot,color)
  struct bone *prev;
  struct bone *root;
  unsigned char nmax;
  ushortvector3 fr_rot;
  rgbi_param color;
  {
  vector3 rot = {frfl(fr_rot.x),frfl(fr_rot.y),frfl(fr_rot.z)};
  struct bone phalng[nmax];
  for (unsigned char n = 0;n < nmax;n++)
    {
    float len = len/G_RATIO;
    phalng[n] = (bone){root,prev,NULL,{FR_ONE,0,0},{len,0,0},matgen_master_deg(rot.x,rot.y,rot.z,1,1,1),matgen_ident,rgbi(color.r,color.g,color.b,color.i,color.a),color.uv,TRUE,NULL};
    prev->next = &phalng[n];
    prev = &phalng[n];
    rot.x = 0;
    rot.y = 0;
    rot.z = 0;
    }
  return &phalng[nmax-1];
  }

struct bone* finger(root,prev,nmax,fr_rot,factor,color)
  struct bone *prev;
  struct bone *root;
  unsigned char nmax;
  ushortvector3 fr_rot;
  double factor;
  rgbi_param color;
  {
  vector3 rot = {frfl(fr_rot.x),frfl(fr_rot.y),frfl(fr_rot.z)};
  struct bone *carple = malloc(sizeof(struct bone));
  *carple = (bone){root,prev,NULL,{FR_ONE,0,0},{(root->len.x / M_E) * factor,0,0},matgen_master_deg(rot.x,rot.y,rot.z,1,1,1),matgen_ident,rgbi(color.r,color.g,color.b,color.i,color.a),color.uv,TRUE,NULL};
  doublelink(carple);
  rot.x = NEG(rot.x);
  rot.y = NEG(rot.y);
  rot.z = NEG(rot.z);
  return handphalanges(carple,carple,nmax,(shortvector3){NEG(fr_rot.x),NEG(fr_rot.y),NEG(fr_rot.z)},color);
  }

struct bone* thumbphalanges(root,prev,nmax,fr_rot,color)
  struct bone *prev;
  struct bone *root;
  unsigned char nmax;
  struct ushortvector3 fr_rot;
  rgbi_param color;
  {
  vector3 rot = {frfl(fr_rot.x),frfl(fr_rot.y),frfl(fr_rot.z)};
  float len = root->len.x / M_PI;
  struct bone phalng[nmax];
  for (unsigned char n = 0;n < nmax;n++)
    {
    phalng[n] = (bone){root,prev,NULL,{FR_ONE,0,0},{len,0,0},matgen_master_deg(rot.x,rot.y,rot.z,1,1,1),matgen_ident,rgbi(color.r,color.g,color.b,color.i,color.a),color.uv,TRUE,NULL};
    prev->next = &phalng[n];
    prev = &phalng[n];
    rot.x = 0;
    rot.y = 0;
    rot.z = 0;
    len = len/((n==0) + 1);
    }
  return &phalng[nmax-1];
  }

struct bone* footphalanges(root,prev,nmax,fr_rot,color)
  struct bone *prev;
  struct bone *root;
  unsigned char nmax;
  struct ushortvector3 fr_rot;
  rgbi_param color;
  {
  struct vector3 rot = {frfl(fr_rot.x),frfl(fr_rot.y),frfl(fr_rot.z)};
  float len = root->len.x / M_PI;
  struct bone phalng[nmax];
  for (unsigned char n = 0;n < nmax;n++)
    {
    phalng[n] = (bone){root,prev,NULL,{0,0,FR_ONE},{len,0,0},matgen_master_deg(rot.x,rot.y,rot.z,1,1,1),matgen_ident,rgbi(color.r,color.g,color.b,color.i,color.a),color.uv,TRUE,NULL};
    prev->next = &phalng[n];
    prev = &phalng[n];
    rot = (vector3){0,0,0};
    len = len * M_SQRT1_2;
    }
  return &phalng[nmax-1];
  }

struct bone* toe(root,prev,nmax,fr_rot,factor,color)
  struct bone *prev;
  struct bone *root;
  unsigned char nmax;
  struct ushortvector3 fr_rot;
  double factor;
  rgbi_param color;
  {
  struct vector3 rot = {frfl(fr_rot.x),frfl(fr_rot.y),frfl(fr_rot.z)};
  struct bone *carple = malloc(sizeof(struct bone));
  *carple = (bone){root,prev,NULL,{FR_ONE,0,0},{(root->len.z / M_PI) * factor,0,0},matgen_master_deg(rot.x,rot.y,rot.z,1,1,1),matgen_ident,rgbi(color.r,color.g,color.b,color.i,color.a),color.uv,TRUE,NULL};
  doublelink(carple);
  rot.x = NEG(rot.x);
  rot.y = NEG(rot.y);
  rot.z = NEG(rot.z);
  return footphalanges(carple,carple,nmax,(shortvector3){NEG(fr_rot.x),NEG(fr_rot.y),NEG(fr_rot.z)},color);
  }

struct bone *talonphalanges(root,prev,nmax,fr_rot,factor,color)
  struct bone *prev;
  struct bone *root;
  unsigned char nmax;
  struct ushortvector3 fr_rot;
  double factor;
  rgbi_param color;
  {
  vector3 rot = {frfl(fr_rot.x),frfl(fr_rot.y),frfl(fr_rot.z)};
  float len = ((root->len.z * -1) / M_E) * factor;
  struct bone phalng[nmax];
  for (unsigned char n = 0;n < nmax;n++)
    {
    len = len/G_RATIO;
    phalng[n] = (bone){root,prev,NULL,{n!=0 * FR_ONE,0,n==0 * FR_ONE},{len,0,0},matgen_master_deg(rot.x,rot.y,rot.z,1,1,1),matgen_ident,rgbi(color.r,color.g,color.b,color.i,color.a),color.uv,TRUE,NULL};
    prev->next = &phalng[n];
    prev = &phalng[n];
    rot = (vector3){0,0,0};
    }
  return &phalng[nmax-1];
  }

struct bone *arm(root,prev,fr_len,side,color)
  struct bone *prev;
  struct bone *root;
  unsigned short fr_len;
  tern side;
  rgbi_param color;
  {
  float len = frfl(fr_len);
  struct bone limb[2];
    {
    prev->next = &limb[0];
    limb[0] = (bone){root,prev,&limb[1],{FR_ONE,0,0},{len,0,0},matgen_ident,matgen_ident,rgbi(color.r,color.g,color.b,color.i,color.a),color.uv,TRUE,NULL};
    len = len/G_RATIO;
    limb[1] = (bone){root,&limb[0],NULL,{FR_ONE,0,0},{len,0,0},matgen_x_deg(90,side),matgen_ident,rgbi(color.r,color.g,color.b,color.i,color.a),color.uv,TRUE,NULL};
    }
  return &limb[1];
  }

struct bone *leg(root,prev,fr_len,fr_Q,side,color)
  struct bone *prev;
  struct bone *root;
  unsigned short fr_len;
  unsigned short fr_Q;
  tern side;
  rgbi_param color;
  {
  float len = frfl(fr_len);
  float Q = frfl(fr_Q);
  struct bone limb[2];
    {
    prev->next = &limb[0];
    limb[0] = (bone){root,prev,&limb[1],{0,side * FR_ONE/2,FR_ONE},{0,0,-1*len},matgen_x_deg(Q,side),matgen_ident,rgbi(color.r,color.g,color.b,color.i,color.a),color.uv,TRUE,NULL};
    len = len * LOG_3_E;
    Q = Q * -1;
    limb[1] = (bone){root,&limb[0],NULL,{0,0,FR_ONE},{0,0,-1*len},matgen_x_deg(Q,side),matgen_ident,rgbi(color.r,color.g,color.b,color.i,color.a),color.uv,TRUE,NULL};
    }
  return &limb[1];
  }

float cosine_leg (fr_len,fr_Q)
  unsigned short fr_len;
  unsigned short fr_Q;
  {
  float len = frfl(fr_len);
  float Q = frfl(fr_Q);
  float accum = cos(Q) * len;
  len = len * LOG_3_E;
  accum = accum + len;
  return accum;
  }

struct bone *digiti(root,prev,fr_len,fr_Q,side,color)
  struct bone *prev;
  struct bone *root;
  unsigned short fr_len;
  struct ushortvector2 fr_Q;
  tern side;
  rgbi_param color;
  {
  float len = frfl(fr_len);
  vector2 Q = {frfl(fr_Q.x),frfl(fr_Q.y)};
  struct bone limb[3];
    {
    len = len * -1;
    prev->next = &limb[0];
    limb[0] = (bone){root,prev,&limb[1],{0,side * FR_ONE/2,FR_ONE},{0,0,len},matgen_master_deg(Q.x,Q.y,0,side,side,1),matgen_ident,rgbi(color.r,color.g,color.b,color.i,color.a),color.uv,TRUE,NULL};
    Q = (vector2){Q.x * -1,Q.y * 2 * -1};
    len = len * M_SQRT1_2;
    limb[1] = (bone){root,&limb[0],&limb[2],{0,0,FR_ONE},{0,0,len},matgen_master_deg(Q.x,Q.y,0,side,side,1),matgen_ident,rgbi(color.r,color.g,color.b,color.i,color.a),color.uv,TRUE,NULL};
    Q = (vector2){0,Q.y * -1};
    len = len * LOG_3_E;
    limb[2] = (bone){root,&limb[1],NULL,{0,0,FR_ONE},{0,0,len},matgen_master_deg(Q.x,Q.y,0,side,side,1),matgen_ident,rgbi(color.r,color.g,color.b,color.i,color.a),color.uv,TRUE,NULL};
    }
  return &limb[2];
  }

float cosine_digiti (fr_len,fr_Q)
  unsigned short fr_len;
  ushortvector2 fr_Q;
  {
  float len = frfl(fr_len);
  vector2 Q = {frfl(fr_Q.x),frfl(fr_Q.y)};
  float accum = cos(Q.x) * cos(Q.y) * len;
  len = len * M_SQRT1_2;
  accum = accum + (cos(Q.y) * len);
  len = len * LOG_3_E;
  accum = accum + len;
  return accum;
  }

struct bone *avewing(root,prev,fr_len,side,color)
  struct bone *prev;
  struct bone *root;
  unsigned short fr_len;
  tern side;
  rgbi_param color;
  {
  float len = frfl(fr_len)
  struct bone limb[3];
    {
    prev->next = &limb[0];
    limb[0] = (bone){root,prev,&limb[1],{0,0,FR_ONE},{0,0,len},matgen_x_deg(135,side),matgen_ident,rgbi(color.r,color.g,color.b,color.i,color.a),color.uv,TRUE,NULL};
    len = len * S_RATIO
    limb[1] = (bone){root,&limb[0],&limb[2],{0,0,FR_ONE},{0,0,len},matgen_x_deg(108,side),matgen_ident,rgbi(color.r,color.g,color.b,color.i,color.a),color.uv,TRUE,NULL};
    limb[2] = (bone){root,&limb[1],NULL,{0,0,FR_ONE},{0,0,len},matgen_x_deg(-150,side),matgen_ident,rgbi(color.r,color.g,color.b,color.i,color.a),color.uv,TRUE,NULL};
    }
  return &limb[2];
  }
