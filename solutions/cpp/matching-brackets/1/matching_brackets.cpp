#include "matching_brackets.h"
using namespace std;
namespace matching_brackets {
    bool check(string sentence) {
        string t;
        t = regex_replace(sentence, 
                   regex("[^[\\]{}()]+"),"");      
        regex b = regex("\\[\\]|\\{\\}|\\(\\)");
        while(regex_search(t,b)>0){
            t = regex_replace(t,b,"");
        }           
        if (t == "") return true;
        return false;
    }
}  // namespace matching_brackets
