#ifndef GUARD_PARTICLE_H
#define GUARD_PARTICLE_H

#include <math.h>

class Particle
{
public:

	// postion
	double x;
	// size
	double s;
};

double particle_distance( const Particle&, const Particle&, double L );
double particle_directed_distance( const Particle&, const Particle&, double L );

#endif
