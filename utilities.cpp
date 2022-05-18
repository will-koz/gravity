namespace utils {
	double distance (vtr a, vtr b, double* xptr, double* yptr) {
		double dx = a.x - b.x; // Not instantaneous change in x. distance in x direction
		double dy = a.y - b.y;
		*xptr = dx;
		*yptr = dy;
		return hypot(dx, dy);
	}

	double random_pseudogaussian (double a, double b, int random_sign) {
		// Returns a random number roughly between 1e(a-1) and 1e(b-1)
		double mantissa = (double) rand() / RAND_MAX;
		mantissa *= (random_sign && rand() % 2) ? -1 : 1; // Put it evenly around midpoint
		double power = ((double) rand() / RAND_MAX) * (b - a) + a;
		return mantissa * pow(BASE, power);
	}

	void vtr::print () {
		printf("[%0.16f, %0.16f]", x, y);
	}

	void vtr::zero () {
		x, y = 0.0;
	}

	void planet::initialize () {
		mass = random_pseudogaussian(MIN_PLANET_MASS, MAX_PLANET_MASS, 0);
		position.x = random_pseudogaussian(MIN_PLANET_POS, MAX_PLANET_POS, 1);
		position.y = random_pseudogaussian(MIN_PLANET_POS, MAX_PLANET_POS, 1);
		// velocity.x = rand() % MAX_PLANET_SPEED1D;
		// velocity.y = rand() % MAX_PLANET_SPEED1D;
		velocity.x = 0;
		velocity.y = 0;
	}

	void planet::print (unsigned char has_comma) {
		printf("{\"mass\": %0.16f, \"position\":", mass);
		position.print();
		printf(", \"velocity\":");
		velocity.print();
		printf(", \"acceleration\":");
		acclrton.print();
		printf("}%s", (has_comma) ? ", " : "");
	}

	void io::json_data_footer () {
		printf("]}\n"); // End data array and general object, add newline
	}

	void io::json_data_header (unsigned int seed, double bigg, unsigned int planets) {
		printf("{\"header\":{"); // Start with header object inside of general object

		printf("\"seed\":%d, ", seed); // Print out seed
		printf("\"G\":%0.16f, ", bigg); // print out value for G
		printf("\"planets\":%d", planets); // print out number of planets

		printf("}, \"data\":["); // End header object, begin data array
	}

	void io::json_data_dump (planet* system, int bodies, unsigned char has_comma) {
		printf("["); // Begin array

		for (int i = 0; i < bodies; i++) {
			system[i].print(i != bodies - 1);
		}

		printf("]%s", (has_comma) ? ", " : ""); // End array
	}
}
