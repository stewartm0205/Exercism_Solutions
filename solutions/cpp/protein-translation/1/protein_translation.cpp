#include "protein_translation.h"
using namespace std;
namespace protein_translation {
    vector<string> proteins(string rna){
        map<string,string> rtop = {
            {"AUG",	"Methionine"},
            {"UUU", "Phenylalanine"},
            {"UUC", "Phenylalanine"},
            {"UUA", "Leucine"},
            {"UUG", "Leucine"},
            {"UCU", "Serine"},
            {"UCC", "Serine"},
            {"UCA", "Serine"},
            {"UCG", "Serine"},
            {"UAU", "Tyrosine"},
            {"UAC", "Tyrosine"},
            {"UGU", "Cysteine"},
            {"UGC", "Cysteine"},
            {"UGG", "Tryptophan"},
            {"UAA", "STOP"},
            {"UAG", "STOP"},
            {"UGA", "STOP"}
        };

        vector<string> prots;
        for (size_t i=0; i<rna.length(); i+=3){
            string codon = rna.substr(i,3);
            string p = rtop[codon];
            if (p=="STOP") return prots;
            else prots.push_back(p);
        }
        return prots;

    }
}  // namespace protein_translation
