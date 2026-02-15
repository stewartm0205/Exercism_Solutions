#include "perfect_numbers.h"

kind classify_number(int num){
    if (num<=0) return ERROR;
    int as=0;
    for(int i=1;i<num;i++){
        if (num%i==0) {
            as+=i;
        }
    }
    if (as==num) {
        return PERFECT_NUMBER;
    } else if (as > num) {
        return ABUNDANT_NUMBER;
    } else {
        return DEFICIENT_NUMBER;
    }
}
