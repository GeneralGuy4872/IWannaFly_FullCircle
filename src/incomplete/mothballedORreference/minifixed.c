//uses vectors.c.m4

double from_minifixed (struct minifixed input) {
	return input.whole + ((double) input.part / 0x80);

struct minifixed to_minifixed (double input) {
	struct minifixed output;
	int tmp = input;
	output.whole = istrue(tmp);
	output.part = (input - tmp) * 0x80;
	return output;
	}

vector2functions(struct minifixed,minifixed);
vector3functions(struct minifixed,minifixed);
vector4functions(struct minifixed,minifixed);

