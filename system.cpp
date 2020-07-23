
#include "system.h"



System::System( int N, double L, double T, double gamma,
			double size0, double TS, double gammaS,
            Potential U, double dt, long int seed)
	: N(N), L(L), T(T), gamma(gamma), size0(size0), TS(TS),
        gammaS(gammaS), U(U), dt(dt), particles(N), forces(N),
        ndist(0., 1.), rng(seed), rndist(rng, ndist)
{
	double d = L/N;
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
		forces[i] = U.f( particles[i], particles[i+1], L );
	}
	forces[N-1] = U.f( particles[N-1], particles[0], L );


	for( int i=0; i<N ; ++i) {
        if( i == 0 ) {
            particles[i].x += dt * ( forces[N-1] - forces[i] ) / gamma;
        } else {
            particles[i].x += dt * ( forces[i-1] - forces[i] ) / gamma;
        }
        particles[i].x += sqrt_2Ddt * rndist();


		// change size
        particles[i].s +=  sqrt_2DSdt * rndist();
        particles[i].s += dt*gammaS*( size0 - particles[i].s );
        particles[i].s = fabs( particles[i].s );
	}


}

void System::integrate( double t )
{
    while( t > dt) {
        next_time();
        t -= dt;
    }
}



