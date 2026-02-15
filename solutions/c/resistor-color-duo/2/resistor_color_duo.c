#include "resistor_color_duo.h"

uint16_t color_code(resistor_band_t* resistor_color){
    uint16_t cc = resistor_color[0]*10+resistor_color[1];
    return cc;
} 
