namespace utils {
	double distance (vtr a, vtr b, double* xptr, double* yptr) {
		double dx = a.x - b.x; // Not instantaneous change in x. distance in x direction
		double dy = a.y - b.y;
		*xptr = dx;
		*yptr = dy;
		return pow((dx * dx) + (dy * dy), 0.5);
	}

	double random_pseudogaussian (double a, double b, int random_sign) {
		// Returns a random number roughly between 1e(a-1) and 1e(b-1)
		double mantissa = (double) rand() / RAND_MAX;
		mantissa *= (random_sign && rand() % 2) ? -1 : 1; // Put it evenly around midpoint
		double power = ((double) rand() / RAND_MAX) * (b - a) + a;
		return mantissa * pow(BASE, power);
	}

	void vtr::print (int tabs) {
		for (int i = 0; i < tabs; i++) printf("\t");
		printf("X : %g\n", x);
		for (int i = 0; i < tabs; i++) printf("\t");
		printf("Y : %g\n", y);
	}

	void vtr::zero () {
		x, y = 0.0;
	}

	void planet::initialize () {
		mass = random_pseudogaussian(MIN_PLANET_MASS, MAX_PLANET_MASS, 0);
		position.x = random_pseudogaussian(MIN_PLANET_POS, MAX_PLANET_POS, 1);
		position.y = random_pseudogaussian(MIN_PLANET_POS, MAX_PLANET_POS, 1);
		velocity.x = rand() % MAX_PLANET_SPEED1D;
		velocity.y = rand() % MAX_PLANET_SPEED1D;
	}

	void planet::print () {
		printf("\n");
		printf("Mass : %g\n", mass);
		printf("Position:\n");
		position.print(1);
		printf("Velocity:\n");
		velocity.print(1);
		printf("Recent Acceleration:\n");
		acclrton.print(1);
	}

	void io::json_data_footer () {
		printf("]}\n"); // End data array and general object, add newline
	}

	void io::json_data_header (unsigned int seed) {
		printf("{\"header\":{"); // Start with header object inside of general object
		printf("\"seed\":%d", seed); // Print out seed
		printf("}, \"data\":["); // End header object, begin data array
	}
}
