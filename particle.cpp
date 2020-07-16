#include "particle.h"


double particle_distance( const Particle& a, const Particle& b, double L)
{
    
    double d = b.x - a.x;   
    d -= round(d/L)*L;
    return  fabs(d);
}

double particle_directed_distance( const Particle& left, const Particle& right, double L)
{
    double d = right.x - left.x;
    if( right.x < left.x ) d = L - d;
    return d;

}


