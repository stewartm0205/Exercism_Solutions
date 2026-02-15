#include "roman_numerals.h"
using namespace std;
namespace roman_numerals {
    string convert(int num){
        vector<int> a_num = {1000, 900, 500, 400, 100, 90, 50 , 40,
            10, 9,5,4,1};
        vector<string> r_d = {"M", "CM", "D", "CD",
            "C", "XC", "L", "XL", "X", "IX", "V","IV", "I"};
    string rnum ="";
        for (size_t i=0; i<a_num.size(); i++) {
            while (a_num[i] <= num) {
                rnum+=r_d[i];
                num-=a_num[i];
            }
        }
    return rnum;


    }
}  // namespace roman_numerals
