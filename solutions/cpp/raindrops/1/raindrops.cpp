#include "raindrops.h"
using namespace std;
namespace raindrops {
    string convert(int number) {
       string ret = ""; 
       if (number % 3 ==0 ) ret+="Pling";
       if (number % 5 ==0 ) ret+="Plang";
       if (number % 7 ==0 ) ret+="Plong";
       if (ret=="") ret=to_string(number);
       return ret;
    }
}  // namespace raindrops
