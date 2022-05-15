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

	utils::io::json_data_header(seed);

	general::update_accelerations(planets, PLANETS);
	planets[0].print();
	planets[1].print();

	general::update_locations(planets, PLANETS, DELTA);

	planets[0].print();
	planets[1].print();

	utils::io::json_data_footer();

	return 0;
}
