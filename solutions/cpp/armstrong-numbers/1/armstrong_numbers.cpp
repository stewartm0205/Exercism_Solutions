#include "armstrong_numbers.h"
using namespace std;
namespace armstrong_numbers {
    bool is_armstrong_number(int num){
        if (num==0) return true;
        char digits[10];
        sprintf(digits,"%d", num);
        int p=strlen(digits);
        int s = 0;
        for (int i=0; i<(int)strlen(digits);i++){
            s+=pow(digits[i]-'0',p);
        }
        if (s==num) return true;
        return false;
    }
}  // namespace armstrong_numbers
