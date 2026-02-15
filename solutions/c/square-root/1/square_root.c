#include "square_root.h"
#include <math.h>

uint16_t square_root(uint16_t n){
    double sr;
    sr=n;
    while(fabs(sr*sr-n)>0.001){
        sr=(sr+n/sr)/2;
    }   
    return sr;
}
