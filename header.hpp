#include "configuration.hpp"

namespace utils {
	double random_float (double a, double b);

	class vtr {
		// C++11 has nice, formal, standardized, vector classes. So logically, I implement my own

		public:
			double x;
			double y;

			void print ();
			void zero ();

		vtr () {
			x = 0.0; y = 0.0;
		}
	};

	double distance (vtr a, vtr b, double* xptr, double* yptr);

	class planet {
		public:
			double mass;
			// int radius; // Currently unused

			vtr position;
			vtr velocity;
			vtr acclrton;

			void initialize ();
			void print (unsigned char has_comma);
			void set_radius ();

		planet () {
			;
		}
	};

	namespace io {
		void json_data_footer ();
		void json_data_header (unsigned int seed, double bigg, unsigned int planets);
		void json_data_dump (planet* system, int bodies, unsigned char has_comma);
	}
}
