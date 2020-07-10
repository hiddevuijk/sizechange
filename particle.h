#ifndef GUARD_PARTICLE_H
#define GUARD_PARTICLE_H


class Particle
{
public:

	// postion
	double x;
	// size
	double s;
};

double particle_distance( const Particle, const Particle, double L = -1 );

#endif
