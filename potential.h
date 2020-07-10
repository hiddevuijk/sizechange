#ifndef GUARD_POTENTIAL_H
#define GUARD_POTENTIAL_H

#include "particle.h"


class Potential
{
public:
	Potential(double e, double d)
		: e(e), d(d) {}

	Potential(const Potential& U)
		{ 
			e = U.e;
			d = U.d;	
		}

	double f(double r) const  { return e*r; }
	//double f(const Particle left, const Particle right) const {return 1;}
	double f(const Particle, const Particle) const;

private:
	double e,d;

};


double Potential::f( const Particle left, const Particle right) const
{


	return 1.;
}

#endif
