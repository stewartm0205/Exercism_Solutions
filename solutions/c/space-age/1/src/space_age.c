#include "space_age.h"
#include "stdio.h"
#include "math.h"

float convert_planet_age(const int planet, long sec)
{
  float planet_year_in_earth_years []={0.2408467, 0.61519726, 1.0, 1.8808158,
                      11.862615, 29.447498, 84.016846, 164.79132};
  float fsec;
  float eyis; 
  
  fsec = sec;
  eyis = EARTH_YEAR_IN_SECS;

	return (fsec/eyis)/planet_year_in_earth_years[planet];
}
