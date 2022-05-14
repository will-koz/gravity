#include <cstdio>

#include "header.hpp"

#include "utilities.cpp"

utils::planet planets[PLANETS];

int main (int argc, char** argv) {
	planets[0].print();
	return 0;
}
