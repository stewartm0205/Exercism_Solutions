#include "isogram.h"
using namespace std;
namespace isogram {
    bool is_isogram(const char * word) {
        int cc[26] = { }; 
        for (int i=0; i<(int)strlen(word); i++){
            char ch=tolower(word[i]);
            if (ch>='a' && ch<='z'){
                if (cc[ch-'a']==1) return false;
                cc[ch-'a'] = 1;
            }
        }
        return true;
    }
}  // namespace isogram
