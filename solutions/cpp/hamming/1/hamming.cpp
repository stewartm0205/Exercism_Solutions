#include "hamming.h"

namespace hamming {
    int compute(const char* s1, const char* s2){
        int d=0;
        if (strlen(s1)!=strlen(s2)) throw std::domain_error("Unequal strands");
        for (int i=0;i<(int)strlen(s1);i++){
            if (s1[i]!=s2[i]) d++;
        }
        return d;
    }
}  // namespace hamming
