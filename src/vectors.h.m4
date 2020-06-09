m4_changequote(`,´)
m4_define(`NIL´)
m4_define(`makevector2´,`STRUCTTYPE(Vector2$2,{$1 x;$1 y;})´)
m4_define(`makevector3´,`STRUCTTYPE(Vector3$2,{$1 x;$1 y;$1 z;})´)
m4_define(`makevector4´,`STRUCTTYPE(Vector4$2,{$1 x;$1 y;$1 z;$1 w;})´)

m4_define(`vector2linkage´,`
$1 Vector2$2__at (Vector2$2 input,int n);
IMPLICIT Vector2$2__setall (Vector2$2 input,$1 xx,$1 yy);´)

m4_define(`vector3linkage´,`
$1 Vector3$2__at (Vector3$2 input,int n);
IMPLICIT Vector3$2__setall (Vector3$2 input,$1 xx,$1 yy,$1 zz);´)

m4_define(`vector4linkage´,`
$1 Vector4$2__at (Vector4$2 input,int n);
IMPLICIT Vector4$2__setall (Vector4$2 input,$1 xx,$1 yy,$1 zz,$1 ww);´)
