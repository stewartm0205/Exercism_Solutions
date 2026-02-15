#include "rna_transcription.h"

namespace rna_transcription {
    char to_rna(char dna) {
        if (dna=='G') return 'C';
        if (dna=='C') return 'G';
        if (dna=='T') return 'A';
        return 'U';
    }
    std::string to_rna(std::string dna) {
        std::string rna="";
        for (size_t i=0;i<dna.length(); i++) {
            if (dna.substr(i,1)=="G") rna+="C";
            else if (dna.substr(i,1)=="C") rna+="G";
            else if (dna.substr(i,1)=="T") rna+="A";
            else rna+="U";
        }
        return rna;
    }
}  // namespace rna_transcription
