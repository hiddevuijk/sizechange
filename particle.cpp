#include "particle.h"


double particle_distance( const Particle a, const Particle b, double L)
{
    
    if( L < 0 ) return  a.x < b.x? b.x-a.x : a.x-b.x;
    double d = b.x - a.x;   
    if( d < 0 ) d += L;
    return d;
}


