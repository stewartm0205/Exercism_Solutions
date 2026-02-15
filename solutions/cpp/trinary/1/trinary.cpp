#include "trinary.h"

namespace trinary {
int to_decimal(const char* tnum) {
    int dnum=0;
    int tmul=1;
    for (int i=(int)strlen(tnum)-1; i>=0;i--){
        if (tnum[i]!='0'&& tnum[i]!='1'&& tnum[i]!='2') return 0;
        if (tnum[i]=='1') dnum+=tmul;
        if (tnum[i]=='2') dnum+=2*tmul;
        tmul*=3;
    }
    return dnum;
}

}  // namespace trinary
