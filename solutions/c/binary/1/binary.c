#include "binary.h"
#include <string.h>
#include <stdio.h>

int convert(const char *input){
    printf("input=%s\n",input);
    int d=0;
    int m=1;
    for (int i=strlen(input)-1;i>=0;i--){
        //printf("i=%d\n",i);
        if (input[i]=='1') {
            d+=m;
        } else {
            if (input[i]!='0') {
                return INVALID;
            }   
        } 
        m=m * 2;
    }
    return d;
}