
#include "distributions.h"



void Distributions::sample_pair_correlations( const System& system)
{
    int N = system.get_N();
    double norm = N*dx*N/system.get_L();
    double dist;
    for( int i=0; i<N; ++i ) {
        for( int j=i+1; j<N; ++j) {
            dist = particle_distance(system.get_particle(i), system.get_particle(j),L ); 
            assert(dist>0);
            assert(dist<L/2);
            p[ (int) (dist/dx) ] += 1./norm;
        }
    }

    ++N_sample_p;
}

void  Distributions::sample_distributions( const System& system)
{
    
    int N = system.get_N();
    for(int ni=0; ni<n; ++ni) {
        for(int i=0; i<N; ++i) {
            double dist = particle_distance(system.get_particle(i), system.get_particle((i+n)%N),L ); 
            int index = (int) fabs(dist)/dx;
            distributions[ni][index] += 1./N; 
        }
    }


    ++N_sample_distributions;
};


void Distributions::save_pair_correlations(std::string outname) const
{
    std::ofstream out(outname);
    if( out.is_open() ) {
        for(int i=0; i<Nx; ++i) {
            out << (i+0.5)*dx << '\t' << p[i]/N_sample_p;
            if( i < Nx-1) out << '\n';
        }
    }
    out.close();
}

