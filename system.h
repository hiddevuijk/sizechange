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
		: e(e), sig(sig), d(d), U0( e*pow(sig,d) ) {}

	Potential(const Potential& U)
		{ 
			e = U.e;
            sig = U.sig;
			d = U.d;	
            U0 = U.U0;
            
		}

	double f(double r) const  {
            if( r < 0)  return -e*pow(-r,d) ;
            else return 0;
    }
	double f(const Particle left, const Particle right, double L) const
        {
            double dist = particle_distance(left, right, L);
            dist -= (left.s + right.s)/2;
            return f(dist);
        }


private:
	double e,sig, d, U0;
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
