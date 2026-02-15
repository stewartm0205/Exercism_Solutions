#include "resistor_color.h"


int color_code (resistor_band_t band) {
    return (int)band;
}
int* colors(){
    static int color[10];
    for (int i=BLACK; i<10; i++){
        color[i] = i;
    }
    return color;
}