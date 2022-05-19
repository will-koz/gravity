#include "general.hpp"

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

					double dx = 0.0; double dy = 0.0; // Not instantaneous change, but difference
					double coefficient = 0.0; // The GM(r^-2)

					// TODO : collision detection?

					double radius = distance(system[i].position, system[j].position, &dx, &dy);
					coefficient = BIGG * system[j].mass;
					coefficient /= pow(radius, 2.0);

					system[i].acclrton.x -= coefficient * (dx / radius);
					system[i].acclrton.y -= coefficient * (dy / radius);
				}
			}
		}
	}

	void update_locations (utils::planet* system, int bodies, double delta) {
		/* Finding the exact location of two bodies can be done given their initial velocities and
		 * positions. However this cannot be done for three (or more) bodies. This is known as the
		 * three body problem. https://en.wikipedia.org/wiki/Three-body_problem
		 *
		 * Or at least in general, this is a problem. There are some cases where it is solved. This
		 * problem also extends to the general n-body problem. Fortunately, this can be estimated
		 * given a displacement of time (this method is known as Euler's three-body problem).
		 *
		 * This method is not a perfect solution, but it looks realistic, and looks more realistic
		 * as the change in time approaches 0. (Actually, it is one for one as dt approaches 0.) A
		 * similar phenomenon can be seen in a Lorenz attractor, and iirc the Lorenz attractor is
		 * deterministic.
		 *
		 * The equations used in this simulation are just the kinematic equations.
		 *  Xf = Xi + ViT + A(T ^ 2) / 2 ==> dX = ViT + A(T ^ 2) / 2
		 *  Vf = Vi + AT ==> dV = AT
		 */

		for (int i = 0; i < bodies; i++) {
			system[i].position.x = system[i].position.x + (system[i].velocity.x * delta) ;// +
				// (system[i].acclrton.x * delta * delta / 2);
			system[i].position.y = system[i].position.y + (system[i].velocity.y * delta) ;//+
				// (system[i].acclrton.y * delta * delta / 2);
			system[i].velocity.x = system[i].velocity.x + (system[i].acclrton.x * delta);
			system[i].velocity.y = system[i].velocity.y + (system[i].acclrton.y * delta);
		}
	}
}
