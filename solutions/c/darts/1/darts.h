#ifndef DARTS_H
#define DARTS_H
#include <stdint.h>
typedef struct coordinate_t{
    float x;
    float y;
} coordinate_t;
uint8_t score (coordinate_t landing_position);
float distance(coordinate_t landing_position);
#endif
