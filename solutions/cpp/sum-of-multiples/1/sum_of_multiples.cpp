#include "sum_of_multiples.h"
using namespace std;
namespace sum_of_multiples {
    size_t to (vector<size_t> factors, size_t num) {
        size_t s=0;
        vector<size_t> uniq_mult;
        for (size_t n=1; n<num;n++) {
            for (size_t fi=0; fi<factors.size(); fi++){
                if (n % factors[fi] == 0 ) {
                    size_t ui;
                    for (ui=0; ui<uniq_mult.size(); ui++){
                        if (uniq_mult[ui]==n) break;
                    } 
                    if (ui>=uniq_mult.size()) {
                        uniq_mult.push_back(n);
                        s+=n;
                    } 
                }
            }        
        }
        return s;
        
    }
}  // namespace sum_of_multiples
