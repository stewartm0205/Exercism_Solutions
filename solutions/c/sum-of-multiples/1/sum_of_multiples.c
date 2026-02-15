#include "sum_of_multiples.h"
#include <stdio.h>

unsigned int sum(const unsigned int *factors,
                 const size_t number_of_factors, const unsigned int limit){

    unsigned int s = 0;
    for (unsigned int n=1; n<limit; n++) {
        for (unsigned int i=0; i<number_of_factors; i++){

            if (factors[i]>0 && n % factors[i]==0){ 
                s+=n;
                break;
            }    
        }
    }                
    return s;
}
