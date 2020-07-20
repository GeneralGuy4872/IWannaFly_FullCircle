double round (double n) {
	double tmp = n + (0.5 * sgnfd(n));
	return tmp - fmod(tmp,1);
	}

float round (float n) {
	float tmp = n + (0.5 * sgnf(n));
	return tmp - fmod(tmp,1);
	}
