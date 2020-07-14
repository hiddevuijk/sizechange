#include "particle.h"


double particle_distance( const Particle& a, const Particle& b, double L)
{
    
    double d = b.x - a.x;   
    d -= round(d/L)*L;
    return  fabs(d);
}


