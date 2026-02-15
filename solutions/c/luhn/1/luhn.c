#include "luhn.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

bool luhn(const char *num){
    if (strlen(num)<=1) return false;
    if (!strcmp(num," 0"))  return false;
    int s=0;
    int di=0;
    for (int i=strlen(num)-1; i>=0;i--){
        if (num[i]!=' ' && (num[i]<'0' || num[i]>'9')) return false;
        if (num[i]!=' ') {
            di++;
            int d = num[i]-'0';
            if (di%2==0) {
                if (2*d>9) {
                    s+=2*d-9;
                } else {
                    s+=2*d;
                }
            } else {
                s+=d;
            }
        }
    }
    if (s%10==0) return true;
    return false;
}
