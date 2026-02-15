#include "rna_transcription.h"
#include <stdlib.h>

char *to_rna(const char *dna){
    char* rna = malloc(100*sizeof(char));
    rna[0]='\0';
    for (int i = 0; dna[i]; i++) {
        switch (dna[i]) {
            case 'G': rna[i] = 'C'; break;
            case 'C': rna[i] = 'G'; break;
            case 'T': rna[i] = 'A'; break;
            case 'A': rna[i] = 'U'; break;
        }
    }
    return rna;
}
