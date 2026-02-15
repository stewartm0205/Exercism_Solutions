#include "nth_prime.h"
#include <stdio.h>
#include <stdlib.h>

uint32_t nth(uint32_t n){
    if (n<=0) return 0;
    uint32_t np=1;
    uint32_t* primes=malloc(n*sizeof(uint32_t));
    primes[0]=2;
    while(np<n) {
    
        uint32_t i;
        for (i=3;i<primes[np-1]*primes[np-1];i++){
          
            uint32_t pi;
            for (pi=0;pi<np;pi++) {  
                   
                if (i%primes[pi]==0) break;
            }
            if(pi==np) {
                np++;
                primes[np-1]=i;
                if (np==n) break;
            }
        }
     
    }
    return primes[np-1];
}
