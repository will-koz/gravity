#include "configuration.hpp"

namespace utils {
	double random_float (double a, double b);

	class vtr {
		// C++11 has nice, formal, standardized, vector classes. So logically, I implement my own

		public:
			double x;
			double y;

			void print (int tabs);
			void zero ();

		vtr () {
			x, y = 0.0;
		}
	};

	double distance (vtr a, vtr b, double* xptr, double* yptr);

	class planet {
		public:
			double mass;

			vtr position;
			vtr velocity;
			vtr acclrton;

			void initialize ();
			void print ();

		planet () {
			;
		}
	};
}
