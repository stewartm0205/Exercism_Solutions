#include "collatz_conjecture.h"
#include <stdio.h>
int steps(int start){
    int s=0;
    int n = start;
    if (start <= 0) return -1;
    while(n>1){
        if (n%2==0) {
            n=n/2;
        }else{
            n=3*n+1;
        }   
        s++;
    }
    return s;
}

