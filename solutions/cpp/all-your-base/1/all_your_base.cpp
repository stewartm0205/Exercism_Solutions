#include "all_your_base.h"
using namespace std;
namespace all_your_base {
    vector<unsigned int> convert(int base_in, 
                           vector<unsigned int> in_digits, int base_out) {
        if (base_in<=1) throw invalid_argument("");
        if (base_out<=1) throw invalid_argument("");
        if (in_digits.size()==0) return {};
        int num = 0;
        int mult = 1;
        for (int i=(int)in_digits.size()-1;i>=0;i--) {
            if ((int)in_digits[i]>=base_in) throw invalid_argument("");
            num+=in_digits[i] * mult;
            mult*=base_in;
        }  
        if (num==0) return {};
        vector<unsigned int> digits = {};
        while(true) {
            digits.push_back(num % base_out);
            num/=base_out;
            if(num==0) break;
        } 
        vector<unsigned int> out_digits = {};    
        for (int i=(int)digits.size()-1;i>=0;i--){
            out_digits.push_back(digits[i]);
        }  
        return out_digits;      
    }
}  // namespace all_your_base
