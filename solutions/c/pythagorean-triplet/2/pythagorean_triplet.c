#include "pythagorean_triplet.h"
#include <stdio.h>


triplets_t * triplets_with_sum(uint16_t sum){
    triplets_t * triplets = malloc(sizeof(triplets));
    triplets->count=0;
    for(uint16_t a=1; a<=sum-2; a++) {
        for(uint16_t b=sum-(a+1); b>a; b--) {
            uint16_t c=sum-(a+b);
             //printf("a=%d,b=%d,c=%d\n",a,b,c);
            //if (c<a || c<b) break;
            if (a*a + b*b == c*c){
                triplets->count++;
                printf("c=%lu,a=%d,b=%d,c=%d\n",triplets->count,a,b,c);
                triplets->triplets[triplets->count-1].a=a;
                triplets->triplets[triplets->count-1].b=b;
                triplets->triplets[triplets->count-1].c=c;
            }
        }
    }
    printf("c=%lu\n",triplets->count);
    return triplets;
}
void free_triplets(triplets_t* triplets){
    free(triplets);
}
