#include "rna_transcription.h"
#include <stdlib.h>

char *to_rna(const char *dna){
    char* rna = malloc(100*sizeof(char));
    int i=0;
    for (i = 0; dna[i]; i++) {
        switch (dna[i]) {
            case 'G': rna[i] = 'C'; break;
            case 'C': rna[i] = 'G'; break;
            case 'T': rna[i] = 'A'; break;
            case 'A': rna[i] = 'U'; break;
        }
    }
    rna[i]='\0';
    return rna;
}
