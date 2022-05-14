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
	printf("Seed: %d\n", seed);
	srand(seed);

	for (int i = 0; i < PLANETS; i++) planets[i].initialize();

	general::update_accelerations(planets, PLANETS);

	planets[0].print();
	planets[1].print();
	return 0;
}
