#include "crypto_square.h"
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>

char *ciphertext(const char *input){
    printf("input=%s\n",input);
    size_t il = strlen(input);
    char * pin = malloc((il+1)*sizeof(char));
    int pi=0;
    for (size_t i=0; i<il; i++){
        if (isalnum(input[i])) {
            pin[pi++]=tolower(input[i]);
        }
    }
    pin[pi]='\0';
   
    size_t pl=strlen(pin);
    size_t c=sqrt(pl);
    size_t r=0;
    if (c!=0) r=pl/c;
    if (c*r<pl) c++;
    if(c-r>1) {
        c++;
        r--;
    }
    printf("second\n");
    pi=0;
    char* ct=malloc((c*r+1)*sizeof(char)); 
    for (size_t ci=0; ci<c; ci++) {
        for (size_t ri=0; ri<r; ri++) {
            if (ri*c+ci<pl) ct[pi++]=pin[ri*c+ci];
            else ct[pi++]=' ';
        }
        if (ci<c-1) ct[pi++]=' ';
    }
    ct[pi]='\0';
    return ct;
}

