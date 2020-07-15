m4_changequote(`,´)

m4_define(`vector2functions´,`
$1 Vector2$2`$$´at (Vector2$2 * input,int n) {
	switch (n) {
		case 0 : return input->x;
		case 1 : return input->y;
		default : errno = EINVAL; return -1;
		}}

IMPLICIT Vector2$2`$$´setall (Vector2$2 * input,$1 xx,$1 yy) {
	input->x = xx;
	input->y = yy;
		}´)

m4_define(`vector3functions´,`
$1 Vector3$2`$$´at (Vector3$2 * input,int n) {
	switch (n) {
		case 0 : return input->x;
		case 1 : return input->y;
		case 2 : return input->z;
		default : errno = EINVAL; return -1;
		}}

IMPLICIT Vector3$2`$$´setall (Vector3$2 * input,$1 xx,$1 yy,$1 zz) {
	input->x = xx;
	input->y = yy;
	input->z = zz;
		}´)

m4_define(`vector4functions´,`
$1 Vector4$2`$$´at (Vector4$2 * input,int n) {
	switch (n) {
		case 0 : return input->x;
		case 1 : return input->y;
		case 2 : return input->z;
		case 4 : return input->w;
		default : errno = EINVAL; return -1;
		}}

IMPLICIT Vector4$2__setall (Vector4$2 * input,$1 xx,$1 yy,$1 zz,$1 ww) {
	input->x = xx;
	input->y = yy;
	input->z = zz;
	input->w = ww;
		}´)
