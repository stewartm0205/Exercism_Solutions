#include "prime_factors.h"
#include <stdio.h>
size_t find_factors(uint64_t n, uint64_t factors[static MAXFACTORS]){
    if (n==1) return 0;
    uint64_t fi=0;
    uint64_t f=2;
    while (f<=n){
        if (n%f==0){
            if (fi<MAXFACTORS) {
                factors[fi++]=f;
                n=n/f;
            }

        } else {
            f++;
        }
    }
    return fi;
}