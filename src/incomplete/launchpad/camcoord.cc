class iwf::datatypes::camcoord {
	double az;
	double el;
	double r;

	irr::core::vector3df normal () {
		irr::core::vector3df tmp;
		tmp.X = sin(this->el) * cos(this->az);
		tmp.Y = sin(this->el) * sin(this->az);
		tmp.Z = cos(this->el);
		return tmp;
		}

	irr::core::vector3df euclid () {
		irr::core::vector3df tmp;
		tmp.X = this->r * sin(this->el) * cos(this->az);
		tmp.Y = this->r * sin(this->el) * sin(this->az);
		tmp.Z = this->r * cos(this->el);
		return tmp;
	}}

/**Camera Coordinate oject
 * the pourpose of this object is to provide callbacks for moving the
 * camera.
 *
 * - azimuth has a value of {-π < x ≤ π} by modulo
 *
 * - elevation has a value of {-π + π/1000 ≤ x ≤ 0 - π/1000} by clamping
 *
 * - the normal() method is intended to be used with
 *   irr::scene::ICameraSceneNode::setTarget(), to provide a first-person
 *   camera.
 *
 * - the euclid() method is intended to be added to used with
 *   irr::scene::ISceneNode::setPosition(), to provide an orbiting third-
 *   person camera.
 */
