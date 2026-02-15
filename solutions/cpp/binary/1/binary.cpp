#include "binary.h"

namespace binary {
int convert(const char* bnum) {
    int dnum=0;
    int bmul=1;
    for (int i=(int)strlen(bnum)-1; i>=0;i--){
        if (bnum[i]!='0'&& bnum[i]!='1') return 0;
        if (bnum[i]=='1') dnum+=bmul;
        bmul*=2;
    }
    return dnum;
}
}  // namespace binary
