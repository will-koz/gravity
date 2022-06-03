// While I wish I could specify floating point precision in this configuration, I don't know how to
// change it using C++ macros. 16 digits should be enough, though if it isn't just do `grep -r %`

#define BASE 10
#define BIGG 0.00000000006744

// This uses a delta of 1 day, or 24 hours, or 1440 minutes, or 86400 seconds
#define DELTA (60 * 60 * 24)

#ifndef ITERATIONS
#define ITERATIONS 1024
#endif

#define MIN_PLANET_MASS 24
#define MIN_PLANET_POS 10
#define MAX_PLANET_MASS 27
#define MAX_PLANET_POS 11
#define MAX_PLANET_SPEED1D 10000

#define PLANET_DENSITY 5514 // Density of Earth in kg/m3, currently unused

#ifndef PLANETS
#define PLANETS 512
#endif
