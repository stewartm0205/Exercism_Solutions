#include "nucleotide_count.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *count(const char *dna_strand) {
    int a = 0;
    int c = 0;
    int g = 0;
    int t = 0;
    char* nc = (char*) malloc(24);
    for (int i=0; dna_strand[i]; i++){
        switch (dna_strand[i]) {
            case 'A': a++; break;
            case 'C': c++; break;
            case 'G': g++; break;
            case 'T': t++; break;
            default: {strcpy(nc,""); return nc;}
        }
    }
    
    printf("A:%d C:%d G:%d T:%d", a, c, g, t);
    sprintf(nc,"A:%d C:%d G:%d T:%d", a, c, g, t);
    return nc;
    
}
