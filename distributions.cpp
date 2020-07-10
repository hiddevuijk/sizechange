
#include "distributions.h"



void Distributions::sample_pair_correlations( const System& system)
{
    int N = system.get_N();
    double dist;
    for( int i=0; i<N; ++i ) {
        for( int j=i+1; j<N; ++j) {
            dist = particle_distance(system.get_particle(i), system.get_particle(j) ); 
            p[ (int) (dist/dx) ] += 1;
        }
    }

    ++N_sample_p;
}

void  Distributions::sample_distributions( const System& system)
{
    int N = system.get_N();
    for(int i=0; i<N; ++i) {
    }


    ++N_sample_distributions;
};


