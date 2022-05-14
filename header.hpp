#include "configuration.hpp"

namespace utils {
	class vtr {
		public:
			double x;
			double y;

			void print (int tabs);
			void zero ();

		vtr () {
			x, y = 0.0;
		}
	};

	class planet {
		public:
			vtr position;
			vtr velocity;
			vtr acclrton;

			void print ();

		planet () {
			;
		}
	};
}
