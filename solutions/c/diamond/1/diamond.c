#include "diamond.h"
#include <stdlib.h>
#include <stdio.h>

char **make_diamond(const char letter){
    int dz=(int)letter - (int)'A' + 1;
    char** d = (char**)malloc((2*dz-1)*sizeof(char*));
    for (int vi = 0; vi < 2*dz-1; vi++){
        d[vi]=malloc((2*dz-1)*sizeof(char));
        for (int hi = 0; hi < dz+2; hi++){
            d[vi][hi] = ' ';
        }
    }
    for (int r=0; r<2*dz-1; r++){
        int c;
        for (c=0; c<2*dz-1; c++) {
            d[r][c]=' ';
        }
        d[r][c]='\0';
    }

    for (int i=0; i<dz; i++){
        d[i][dz-1-i]='A'+i;
        d[i][dz-1+i]='A'+i;
        d[2*dz-2-i][dz-i-1]='A'+i;
        d[2*dz-2-i][dz+i-1]='A'+i;
    }
    return d;
}