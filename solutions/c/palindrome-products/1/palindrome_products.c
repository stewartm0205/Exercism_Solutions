#include "palindrome_products.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

product_t *get_palindrome_product(int from, int to){
 
    product_t* pp = malloc(sizeof(product_t));

    
    int sp=from*to+1;
    int lp=0;
    for (int i=from;i<=to;i++) {
        for (int j=from;j<=to;j++) {
            char* numstr=malloc(10*sizeof(char));
            sprintf(numstr,"%d",i*j);
            if(!strcmp(numstr,strrev(numstr))){
                if (i*j>lp) {
                    lp=i*j;
                    pp->largest=lp;
                }                   
                if (i*j<sp) {
                    sp=i*j;    
                    pp->smallest=sp;
                } 
            }
        }
    }
    pp->factors_lg = malloc(sizeof(factor_t));
    factor_t * fac = pp->factors_lg;
    int fc=0;
    for (int i=from;i<=to;i++) {
        for (int j=from;j<=to;j++) {
            char* numstr=malloc(10*sizeof(char));
            sprintf(numstr,"%d",i*j);
            if(!strcmp(numstr,strrev(numstr))){
                if (i*j==pp->largest) {
                    if (fc==0) {
                        pp->factors_lg->factor_a=i;
                        pp->factors_lg->factor_b=j;
                        fc++;
                    } else {
                        fac->next=malloc(sizeof(factor_t));
                        fac = fac->next;
                        fac->factor_a=i;
                        fac->factor_b=j;
                    }
                }                   
            }
        }
    }
    pp->factors_sm = malloc(sizeof(factor_t));
    fac = pp->factors_sm;
    fc=0;
    for (int i=from;i<=to;i++) {
        for (int j=from;j<=to;j++) {
            char* numstr=malloc(10*sizeof(char));
            sprintf(numstr,"%d",i*j);
            if(!strcmp(numstr,strrev(numstr))){                 
                if (i*j==pp->smallest) {
                    if (fc==0) {
                        pp->factors_sm->factor_a=i;
                        pp->factors_sm->factor_b=j;
                        fc++;

                    } else {
                        fac->next=malloc(sizeof(factor_t));
                        fac = fac->next;
                        fac->factor_a=i;
                        fac->factor_b=j;
                    }
                }                   
            }
        }
    }
    if (from>to) {
        sprintf(pp->error,"invalid input: min is %d and max is %d",from,to);
        return pp;
    }
    if (pp->smallest==0) {
        sprintf(pp->error,"no palindrome with factors in the range %d to %d",from,to);
    }
    return pp;
}
void free_product(product_t *p){
    free(p->factors_sm);
    free(p->factors_lg);
    free(p);
}
char* strrev(char* str) {
    
    int l = strlen(str);
    char * revstr=malloc((l+1)*sizeof(char));
    int j=l-1;
    for(int i = 0; i<l; i++){
        revstr[i]=str[j--];
    }
    revstr[l]='\0';
    return revstr;
}

