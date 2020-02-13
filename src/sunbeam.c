Vector3 sunbeam_declination (float lat,float lon,float axis,struct turntyp * turn) {
	Vector2 source;
	source.x = asin(sin(axis) * -sin(turn->dayear);
	source.y = (sin(lat) * sin(source.x)) + (cos(lat) * cos(source.x) * cos((turn->hour * (M_PI / 12)) + (turn->mm * ((M_PI / 12) / 60)) + (turn->second * (((M_PI / 12) / 60) / 60));
	Vector2 cast = Vector2Normalize(source.x + M_PI,source.y + M_PI);
	return Spherical2Vector(cast);
	}/* for now, rays going up make for nice indoor lighting effect
	  * todo: adjust warping because timezones and causality
	  */

Vector3 Spherical2Vector(Vector2 sphere) {
	Vector3 tmp = { cos(sphere.x) * cos(sphere.y) * DEG2RAD , sin(sphere.x) * cos(sphere.y) * DEG2RAD , sin(sphere.y) * DEG2RAD };
	return Vector3Normalize(tmp);
	}

void ticktock_seconds (struct turntyp * this,int t) {
	div_t carry = div(this->second + t,60);
	this->second = carry.rem;
	if (carry.quot) {
		ticktock_mms(carry.quot);
	}	

void ticktock_mms (struct turntyp * this,int t) {
	div_t carry = div(this->mm + t,60);
	this->mm = carry.rem;
	if (carry.quot) {
		ticktock_hours(carry.quot);
	}
	
void ticktock_hours (struct turntyp * this,int t) {
	carry = div(this->hour + t,24);
	this->hour = carry.rem;
	if (carry.quot) {
		ticktock_days(carry.quot);
	}

void ticktock_days (struct turntyp * this,int d) {
	div_t carry = div(this->dayear + d,360);
	this->dayear = carry.rem;

	carry = div(this->daymonth + d,30);
	this->daymonth = carry.rem;
		if (carry.quot) {
			carry = div(this->month + carry.quot,12);
			this->month = carry.rem;
			this->season = this->month % 4;
			}

	carry = div(this->weekday + d,7);
	this->weekday = carry.rem;
	if (carry.quot) {
		this->moonphase++;
		}
	}
