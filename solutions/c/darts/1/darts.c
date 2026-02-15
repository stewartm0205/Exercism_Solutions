#include "darts.h"
#include <math.h>

uint8_t score (coordinate_t landing_position){
    if (distance(landing_position) > 10.0F) return 0;
    if (distance(landing_position) > 5.0F) return 1;
    if (distance(landing_position) > 1.0F) return 5;
    return 10;
}
float distance(coordinate_t landing_position) {
    float d = sqrt(landing_position.x * landing_position.x + 
                landing_position.y * landing_position.y);
    return d;            
}   
