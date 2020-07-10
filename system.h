#ifndef	GUARD_SYSTEM_H
#define	GUARD_SYSTEM_H

#include "particle.h"

#include <vector>
#include <math.h>
#include <boost/random.hpp>


class Potential
{
public:
	Potential(double e, double sig, double d)
		: e(e), sig(sig), d(d) {}

	Potential(const Potential& U)
		{ 
			e = U.e;
            sig = U.sig;
			d = U.d;	
            
		}

	double f(double r) const  { return e*pow(r,d) ; }
	double f(const Particle left, const Particle right, double L) const
        {
            return f( particle_distance(left, right,L) );
        }


private:
	double e,sig, d;
};


class System
{
public:
	System( int N, double L, double T, double gamma,
            double size0, double TS, double gammaS,
            Potential U, double dt, long int seed);

	void next_time();
	void integrate(double t);
    Particle const& get_particle(int i) const { return particles[i]; };
    int get_N() const { return N;}
private:
	int N;
	double L;
	double T,gamma;
	double size0, TS, gammaS;
	Potential U;
    double dt;


	std::vector<Particle> particles;
	std::vector<double> forces;

    const boost::normal_distribution<double> ndist;
    boost::mt19937 rng;
    boost::variate_generator<boost::mt19937&,
            boost::normal_distribution<double> > rndist;
};


#endif
