#include "hexadecimal.h"
using namespace std;
namespace hexadecimal {
int convert(const char* hnum) {
    const char* hdigits = "0123456789abcdef";
    int dnum=0;
    int hmul=1;
    for (int i=(int)strlen(hnum)-1; i>=0;i--){
        const char* pch = strchr(hdigits,hnum[i]);
        if (pch == nullptr) return 0;
        int n = (int)(pch-hdigits);
        dnum+=n*hmul;
        hmul*=16;
    }
    return dnum;
}

}  // namespace hexadecimal
