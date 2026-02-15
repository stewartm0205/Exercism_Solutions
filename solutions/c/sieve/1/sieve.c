#include "sieve.h"
#include <stdio.h>

uint32_t sieve(uint32_t limit, uint32_t *primes, size_t max_primes){
    printf("limit=%d\n",limit);
    if (limit<2) return 0;
    uint32_t pi=0;
    for (uint32_t n=2;n<=limit;n++) {
        uint32_t i;
        for (i=0;i<pi;i++) {
            if (n%primes[i]==0) break;
        }
        if (i==pi && pi<max_primes) {
            primes[pi++]=n;
        }
    }
    return pi;
}