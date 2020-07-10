#ifndef GUARD_DISTRIBUTIONS_H
#define GUARD_DISTRIBUTIONS_H

#include "particle.h"
#include "system.h"

#include <vector>


class Distributions
{
    Distributions(double dx, double L, int n=0)
        : dx(dx), L(L), n(n), Nx(1+L/dx), p(Nx),
            distributions(n, std::vector<double>(Nx) ),
            N_sample_p(0), N_sample_distributions(0)
        {}

    void sample_pair_correlations(const System&);
    void sample_distributions(const System&);

    std::vector<double> get_pair_correlations() const;
    std::vector<std::vector<double> > get_distributions() const;

    void save_pair_correlations() const;
    void save_distributions() const;

private:
    double dx;
    double L;
    int n;
    int Nx;
    std::vector<double> p; 
    std::vector<std::vector<double> > distributions;

    int N_sample_p;
    int N_sample_distributions;
};




#endif
