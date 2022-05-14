namespace general {
	void update_accelerations (utils::planet* system, int bodies) {
		// Look at every body in the system and update the individual accelerations.
		for (int i = 0; i < bodies; i++) {
			// Remember not to include calculations from before
			system[i].acclrton.zero();

			for (int j = 0; j < bodies; j++) {
				if (i != j) { // make sure object doesn't get a force from itself
					// F = GmM(r^-2)(r'), so a = GM(r^-2)(r')
					// r' is the normalized radius vector between two points, pronounced r-hat

					double dx, dy = 0.0; // Not instantaneous change, but difference
					double coefficient = 0.0; // The GM(r^-2)

					// TODO : collision detection?

					double radius = distance(system[i].position, system[j].position, &dx, &dy);
					coefficient = BIGG * system[j].mass;
					coefficient /= pow(radius, 2);

					system[i].acclrton.x += coefficient * (dx / radius);
					system[i].acclrton.y += coefficient * (dy / radius);
				}
			}
		}
	}
}
