#include "resistor_color.h"


int color_code (resistor_band_t band) {
    return band;
}
int* colors(void){
    static int color[10];
    for (int i=BLACK; i<=WHITE; i++){
        color[i] = i;
    }
    return color;
}