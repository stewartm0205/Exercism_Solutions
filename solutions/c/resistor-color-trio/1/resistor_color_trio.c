#include "resistor_color_trio.h"
#include <math.h>
#include <stdio.h>

resistor_value_t color_code(resistor_band_t* resistor_color){
    resistor_value_t cc;
    cc.value = (resistor_color[0]*10+resistor_color[1])*pow(10,resistor_color[2]);
    if (cc.value>1000) {
        cc.value = cc.value / 1000;
        cc.unit = KILOOHMS;
    } else {
        cc.unit = OHMS;
    }
    return cc;
} 