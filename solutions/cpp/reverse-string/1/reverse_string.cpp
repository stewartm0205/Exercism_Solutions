#include "reverse_string.h"


namespace reverse_string {
std::string reverse_string(std::string str){
    std::string rstr="";
    if (str.length()==0) return "";
    for (size_t i=str.length()-1;; i--) {
        rstr.push_back(str[i]);
        if (i==0) break;
    }    
    return rstr;
}
}  // namespace reverse_string
