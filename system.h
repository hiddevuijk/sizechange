#ifndef	GUARD_SYSTEM_H
#define	GUARD_SYSTEM_H

#include "particle.h"
#include "potential.h"

#include <vector>


class System
{
public:
	System( int N, double L, double T, double gamma,
			double TS, double gammaS, Potential U);

	void next_time(double dt);


private:
	int N;
	double L;
	double T,gamma;
	double TS, gammaS;
	Potential U;


	std::vector<Particle> particles;

	std::vector<double> forces;
};

System::System( int N, double L, double T, double gamma,
			double gammaS, double TS, Potential U)
	: N(N), L(L), T(T), gamma(gamma), TS(TS), gammaS(gammaS), U(U), particles(N)
{
	double d = L/(N+1);
	for(int i=0; i<N; ++i) {
		particles[i].x = i*d;
		particles[i].s = 1.;
	}

}


void System::next_time( double dt)
{

	for( int i=0; i<N  - 1; ++i) {
		forces[i] = U.f( particles[i], particles[i+1] );
	}
	forces[N-1] = U.f( particles[N-1], particles[0] );


	particles[0].x += gamma * ( forces[0] - forces[N-1] );
	for( int i=1; i<N ; ++i) {
		particles[i].x += gamma * ( forces[i] - forces[i-1] );
		// stochastic

		// change size
	}


}




#endif
