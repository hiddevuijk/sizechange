#include "particle.h"


double particle_distance( const Particle a, const Particle b, double L=-1)
{
    if( L < 0 ) return  a.x < b.x? b.x-a.x : a.x-b.x;

    // periodic boundaries
    return  a.x < b.x? b.x-a.x : a.x-b.x;

}


