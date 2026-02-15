#include "phone_number.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stddef.h>

char *phone_number_clean(const char *input){
 
    char * pin = malloc((strlen(input)+2)*sizeof(char));
    char * pnc = malloc((strlen(input)+2)*sizeof(char));

    // remove spaces and dots
    size_t pi = 0;
    for (size_t i=0; i<strlen(input);i++){
        if(input[i]!=' '&&input[i]!='.'&&input[i]!='('&&input[i]!=')'&&input[i]!='-'&&input[i]!='+') pin[pi++]=input[i];
    }
 
    pin[pi]='\0';
 
    // error checks
    if (pin[0]=='1' && strlen(pin)==9) {
        strcpy(pnc,"0000000000");
        return pnc;
    }
    if (pin[0]=='0') {
        strcpy(pnc,"0000000000");
        return pnc;
    }
    if (pin[0]!='1' && strlen(pin)==11) {
        strcpy(pnc,"0000000000");
        return pnc;
    }
    if (strlen(pin)>11) {
      
        strcpy(pnc,"0000000000");
        return pnc;
    }
    for (size_t i=0;i<strlen(input);i++) {
        if (isalpha(input[i])||input[i]=='@'||input[i]==':'||input[i]=='!') {
            strcpy(pnc,"0000000000");
            return pnc;
        }
    }
    size_t poi = 0;
    size_t pii = 0;
    //check for 1
    
    if (strlen(pin)>10 && pin[pii]=='1') pii++;
    if (pin[pii]=='0'||pin[pii]=='1') {
        strcpy(pnc,"0000000000");
        return pnc;
    }
    pnc[poi++]=pin[pii++];
    pnc[poi++]=pin[pii++];
    pnc[poi++]=pin[pii++];
    if (pin[pii]=='0'||pin[pii]=='1') {
        strcpy(pnc,"0000000000");
        return pnc;
    }   
    pnc[poi++]=pin[pii++]; 
    pnc[poi++]=pin[pii++];
    pnc[poi++]=pin[pii++];
    pnc[poi++]=pin[pii++];
    pnc[poi++]=pin[pii++];
    pnc[poi++]=pin[pii++];
    pnc[poi++]=pin[pii++];
    return pnc;
}
