

#include "system.h"



using namespace std;

int main()
{

    double N = 3;
    double L = 10;

    double T = 1;
    double gamma = 1;

    double size0 = 1;
    double TS = 1;
    double gammaS = 1;

    double e = 1;
    double d = 1;

    double dt = 0.1;

    int seed = 123456789;

    Potential U(e,d);


    System system(N, L, T, gamma, size0, TS, gammaS, U,dt, seed);


	return 0;
}
