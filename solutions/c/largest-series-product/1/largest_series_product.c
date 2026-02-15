#include "largest_series_product.h"
#include <string.h>
#include <stdio.h>
#include <ctype.h>

int64_t largest_series_product(char *digits, size_t span){
    size_t dl=strlen(digits);
    int64_t lp=0;
    if (span>dl) return -1;
    for (size_t di=0; di<dl-span+1; di++){
        int64_t p=1;
        for (size_t si=0; si<span; si++) {
            if (!isdigit(digits[di+si])) return -1;
            p*=(int)(digits[di+si]-'0'); 
        }
        if (p>lp) lp=p;
    }
    return lp;
}