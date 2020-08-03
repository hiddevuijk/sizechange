

#include "system.h"
#include "distributions.h"



using namespace std;

int main()
{

    double N = 5;
    double L = 20; 
    double T = 1.;
    double gamma = 1;

    double size0 = 1;
    double TS = 5.;
    double gammaS = 1;

    double e = 1.;
    double sig = 1.0;
    double d = 16;

    double dt = 0.000001;

    int seed = 123456789;

    double dx = 0.1;
    int n = 2;

    Potential U(e,sig,d);


    System system(N, L, T, gamma, size0, TS, gammaS, U,dt, seed);
    Distributions distributions(dx,L, n);

    int Ni = 10000;


    for( int i=0; i< Ni; ++i ) {
        cout << i << endl;
        system.integrate(1.);
        distributions.sample_pair_correlations(system);
    }

    string outname = "gr.dat";
    distributions.save_pair_correlations(outname);

     



	return 0;
}
