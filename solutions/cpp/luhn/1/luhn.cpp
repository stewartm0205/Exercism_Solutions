#include "luhn.h"
using namespace std;
namespace luhn {
    bool valid(string num)  {
        
        string nbnum = "";
        for (size_t i=0; i<num.length();i++){
            if (num.at(i)>='0' && num.at(i)<='9') nbnum+=num.at(i);
            else if (num.at(i)!=' ') return false;          
        }
        if (nbnum.length()<=1) return false;
        int s=0;
        bool even = false;
        for (int i=(int)nbnum.length()-1; i>=0; i--) {
            int d=nbnum.at(i)-'0';
            if (even) {
                d*=2;
                if (d>9) d-=9;
                even = false;
            }
            else even=true;  
            s+=d;  
        }
        if (s % 10 == 0) return true;
        else return false;
    }
}  // namespace luhn
