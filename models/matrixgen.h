//HERE BE DRAGONS

#define M_TAU (2 * M_PI) //was worried about float errors, now too hard to remove the macro. It's also conviniant.
#define matgen_master_deg (R,P,A,X,Y,Z) (X*cos(radians(mod(A,360)))*cos(radians(mod(P,360))),X*sin(radians(mod(A,360)))*cos(radians(mod(P,360))),X*cos(radians(mod(A,360)))*-1*sin(radians(mod(A,360))),0, Y*(-1*sin(radians(mod(A,360)))*cos(radians(mod(R,360)))+cos(radians(mod(A,360)))*sin(radians(mod(P,360)))*sin(radians(mod(R,360)))),Y*(cos(radians(mod(A,360)))*cos(radians(mod(R,360)))+sin(radians(mod(A,360)))*sin(radians(mod(P,360)))*sin(radians(mod(R,360)))),Y*(sin(radians(mod(A,360)))*sin(radians(mod(P,360)))*cos(radians(mod(R,360)))+cos(radians(mod(P,360)))*sin(radians(mod(R,360)))),0, Z*(sin(radians(mod(A,360)))*sin(radians(mod(R,360)))+cos(radians(mod(A,360)))*sin(radians(mod(P,360)))*cos(radians(mod(R,360)))),Z*(cos(radians(mod(A,360)))*-1*sin(radians(mod(R,360)))+sin(radians(mod(A,360)))*sin(radians(mod(P,360)))*sin(radians(mod(R,360)))),Z*(sin(radians(mod(A,360)))*sin(radians(mod(P,360)))*-1*sin(radians(mod(R,360)))+cos(radians(mod(P,360)))*cos(radians(mod(R,360)))),0, 0,0,0,1)
#define matgen_master_rad (R,P,A,X,Y,Z) (X*cos(mod(A,M_TAU))*cos(mod(P,M_TAU)),X*sin(mod(A,M_TAU))*cos(mod(P,M_TAU)),X*cos(mod(A,M_TAU))*-1*sin(mod(A,M_TAU)),0, Y*(-1*sin(mod(A,M_TAU))*cos(mod(R,M_TAU))+cos(mod(A,M_TAU))*sin(mod(P,M_TAU))*sin(mod(R,M_TAU))),Y*(cos(mod(A,M_TAU))*cos(mod(R,M_TAU))+sin(mod(A,M_TAU))*sin(mod(P,M_TAU))*sin(mod(R,M_TAU))),Y*(sin(mod(A,M_TAU))*sin(mod(P,M_TAU))*cos(mod(R,M_TAU))+cos(mod(P,M_TAU))*sin(mod(R,M_TAU))),0, Z*(sin(mod(A,M_TAU))*sin(mod(R,M_TAU))+cos(mod(A,M_TAU))*sin(mod(P,M_TAU))*cos(mod(R,M_TAU))),Z*(cos(mod(A,M_TAU))*-1*sin(mod(R,M_TAU))+sin(mod(A,M_TAU))*sin(mod(P,M_TAU))*sin(mod(R,M_TAU))),Z*(sin(mod(A,M_TAU))*sin(mod(P,M_TAU))*-1*sin(mod(R,M_TAU))+cos(mod(P,M_TAU))*cos(mod(R,M_TAU))),0, 0,0,0,1)
#define matgen_x_deg (R,X,Y,Z) (X,0,0,0, 0,Y*cos(radians(mod(R,360))),Y*sin(radians(mod(R,360))),0, 0,Z*-1*sin(radians(mod(R,360))),Z*cos(radians(mod(R,360))),0, 0,0,0,1)
#define matgen_x_rad (R,X,Y,Z) (X,0,0,0, 0,Y*cos(mod(R,M_TAU)),Y*sin(mod(R,M_TAU)),0, 0,Z*-1*sin(mod(R,M_TAU)),Z*cos(mod(R,M_TAU)),0, 0,0,0,1)
#define matgen_y_deg (P,X,Y,Z) (X*cos(radians(mod(P,360))),0,X*-1*sin(radians(mod(P,360))),0, 0,Y,0,0, Z*sin(radians(mod(P,360))),0,Z*cos(radians(mod(P,360))),0, 0,0,0,1)
#define matgen_y_rad (P,X,Y,Z) (X*cos(mod(P,M_TAU)),0,X*-1*sin(mod(P,M_TAU)),0, 0,Y,0,0, Z*sin(mod(P,M_TAU)),0,Z*cos(mod(P,M_TAU)),0, 0,0,0,1)
#define matgen_z_deg (A,X,Y,Z) (X*cos(radians(mod(A,360))),X*sin(radians(mod(A,360))),0,0, Y*-1*sin(radians(mod(A,360))),Y*cos(radians(mod(A,360))),0,0, 0,0,Z,0, 0,0,0,1)
#define matgen_z_rad (A,X,Y,Z) (X*cos(mod(A,M_TAU)),X*sin(mod(A,M_TAU)),0,0, Y*-1*sin(mod(A,M_TAU)),Y*cos(mod(A,M_TAU)),0,0, 0,0,Z,0, 0,0,0,1)
#define matgen_translate (L,W,H) (1,0,0,0, 0,1,0,0, 0,0,1,0, L,W,H,1)
#define matgen_ident (1,0,0,0, 0,1,0,0, 0,0,1,0, 0,0,0,1)
