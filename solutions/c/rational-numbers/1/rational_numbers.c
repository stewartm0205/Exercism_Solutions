#include "rational_numbers.h"
#include <stdio.h>

rational_t add(rational_t r1, rational_t r2){
    rational_t ret;
    ret.numerator = r1.numerator * r2.denominator + r2.numerator * r1.denominator;
    ret.denominator = r1.denominator * r2.denominator;
    if (ret.numerator==0) ret.denominator = 1;
    return ret;
}
rational_t subtract(rational_t r1, rational_t r2){
    rational_t ret;
    ret.numerator = r1.numerator * r2.denominator - r2.numerator * r1.denominator;;
    ret.denominator = r1.denominator * r2.denominator;
    if (ret.numerator==0) ret.denominator = 1;
    return ret;
}
rational_t multiply(rational_t r1, rational_t r2){
    rational_t ret;
 
    if (abs(r1.numerator)==abs(r2.denominator)) {
        r1.numerator=r1.numerator/abs(r1.numerator);
        r2.denominator=r2.denominator/abs(r2.denominator);
    }
    if (abs(r2.numerator)==abs(r1.denominator)) {
        r2.numerator=r2.numerator/abs(r2.numerator);
        r1.denominator=r1.denominator/abs(r1.denominator);
    } 

    ret.numerator = r1.numerator * r2.numerator;
    ret.denominator = r1.denominator * r2.denominator;
    if (ret.numerator==0) ret.denominator = 1;
    return ret;
}
rational_t divide(rational_t r1, rational_t r2){
    rational_t ret;
    rational_t rep2;
    rep2.denominator = r2.numerator;
    rep2.numerator = r2.denominator;
    ret = multiply(r1,rep2);
    if (ret.denominator<0 && ret.numerator>0) {
        ret.denominator=-ret.denominator;
        ret.numerator=-ret.numerator;
    }
    if (ret.denominator<0 && ret.numerator<0) {
        ret.denominator=-ret.denominator;
        ret.numerator=-ret.numerator;
    }
    return ret;
}
rational_t absolute(rational_t r1){
    rational_t ret;
        ret.numerator = abs(r1.numerator);
        ret.denominator = abs(r1.denominator);
    return ret;
}
rational_t exp_rational(rational_t r1, int16_t n){
    rational_t ret;
        ret.numerator = pow(r1.numerator, n);
        ret.denominator = pow(r1.denominator, n);
    return ret;
}
float exp_real(int16_t n, rational_t r1){
    float ret;
    float e;
    e = r1.numerator;
    e = e/r1.denominator;
    ret = pow(n,e);  
    return ret;
}
rational_t reduce(rational_t r1){
    rational_t ret;
        int16_t g=gcd (abs(r1.numerator),abs(r1.denominator));
        ret.numerator = r1.numerator/g;
        ret.denominator = r1.denominator/g;
        if (ret.denominator < 0) {
            ret.denominator = -ret.denominator;
            ret.numerator = -ret.numerator;
        }
    return ret;
}
int16_t gcd(int16_t a, int16_t b) {
    if (a == 0) return b;
    if (b==0) return b;
    if (a==b) return a;
    if (a > b) return gcd(a-b, b);
    return gcd(a,b-a);
}
