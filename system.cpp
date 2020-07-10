
#include "system.h"

double Potential::f( const Particle left, const Particle right) const
{


	return 1.;
}


System::System( int N, double L, double T, double gamma,
			double size0, double gammaS, double TS,
            Potential U, double dt, long int seed)
	: N(N), L(L), T(T), gamma(gamma), size0(size0), TS(TS),
        gammaS(gammaS), U(U), dt(dt), particles(N),
        ndist(0., 1.), rng(seed), rndist(rng, ndist)
{
	double d = L/(N+1);
	for(int i=0; i<N; ++i) {
		particles[i].x = i*d;
		particles[i].s = size0;
	}

}


void System::next_time()
{

    double sqrt_2Ddt = std::sqrt(2*T*dt/gamma);
    double sqrt_2DSdt = std::sqrt(2*TS*dt/gammaS);

    // calculate force
	for( int i=0; i<N-1; ++i) {
		forces[i] = U.f( particles[i], particles[i+1] );
	}
	forces[N-1] = U.f( particles[N-1], particles[0] );


	particles[0].x += dt*gamma * ( forces[0] - forces[N-1] );
	for( int i=1; i<N ; ++i) {
		particles[i].x += dt*gamma * ( forces[i] - forces[i-1] );
        particles[i].x += sqrt_2Ddt * rndist();
        // periodic boundary conditions
        if( particles[i].x > L) particles[i].x -= L;
        if( particles[i].x < L) particles[i].x += L;

		// change size
        particles[i].s -= dt*gammaS*( size0 - particles[i].s );
        particles[i].s +=  sqrt_2DSdt * rndist();
	}


}

void System::integrate( double t )
{
    while( t > dt) {
        next_time();
        t -= dt;
    }
    
    

}

