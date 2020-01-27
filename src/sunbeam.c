sunbeam_declination (int x,int y,int z,float latitude,float axial) {
if (DAY) {
	Vector3Normalize(
		Vector3Add(
			Vector3Transform(
				

Vector3 Spherical2Vector(Vector2 sphere) {
	Vector3 tmp = { cos(sphere.x) * cos(sphere.y) * DEG2RAD , sin(sphere.x) * cos(sphere.y) * DEG2RAD , sin(sphere.y) * DEG2RAD };
	return Vector3Normalize(tmp);
	}
