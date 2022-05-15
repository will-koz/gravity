#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>

#include "header.hpp"

#include "utilities.cpp"
#include "general.cpp"

utils::planet planets[PLANETS];

int main (int argc, char** argv) {
	time_t t; // Set random seed
	unsigned int seed = (unsigned int) time(&t);
	srand(seed);

	for (int i = 0; i < PLANETS; i++) planets[i].initialize();

	utils::io::json_data_header(seed, BIGG, PLANETS);

	for (int i = 0; i < ITERATIONS; i++) {
		general::update_accelerations(planets, PLANETS);
		general::update_locations(planets, PLANETS, DELTA);
		utils::io::json_data_dump(planets, PLANETS, i != ITERATIONS - 1);
	}

	utils::io::json_data_footer();

	return 0;
}
