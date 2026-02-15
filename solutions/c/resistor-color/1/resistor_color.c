#include "resistor_color.h"
unsigned int color_code(resistor_band_t color) {
    return(color);
}
Int * colors(){
    int c[10] = (int *)malloc(10,sizeof int);
    for (int i=0; i<10; i++){
        c[i] = resistor_band_t (i);
    }
}