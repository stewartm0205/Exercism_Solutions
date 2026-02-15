#include "pangram.h"

using namespace std;
namespace pangram {
    bool is_pangram (const char* sentence){
        int lc[26] = {};

        if (strlen(sentence)==0) return false;
        for (size_t si = 0; si<strlen(sentence); si++){
            if (tolower(sentence[si])>='a' && 
                tolower(sentence[si])<='z') {
                lc[tolower(sentence[si])-'a']++;
            }
        }
        for (size_t lci = 0; lci<26; lci++){
            if (lc[lci]==0) {        
                return false;
            }
        }
        return true;
    }
}  // namespace pangram
