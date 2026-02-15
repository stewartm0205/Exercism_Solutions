#include "say.h"
#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int say(int64_t input, char **ans){
    int64_t bill = input / 1000000000;
    int64_t r = input % 1000000000;
    int64_t mill = r / 1000000;
    r = r % 1000000;
    int64_t thous =  r / 1000;
    r = r % 1000;
    int64_t hun = r / 100;
    int64_t tendigit = r % 100;
    
    char * numans=malloc(120*sizeof(char));
    *ans = numans;
    char * hunans=malloc(120*sizeof(char));
    printf("input=%lu\n",input);
    if (input>999999999999 || input<0) return -1;
    if (input == 0){
         strcpy(*ans,"zero");
         return 0;
    }  
    
    if (bill>0) {
        sayhun(bill, hunans);
        strcat(numans, hunans);
        strcat(numans, " billion ");
    }
    if (mill>0) {
        sayhun(mill, hunans);
        strcat(numans, hunans);
        strcat(numans, " million ");
    }
    if (thous>0) {
        sayhun(thous, hunans);
        strcat(numans, hunans);
        strcat(numans, " thousand ");
    }
    if (hun>0) {
        sayhun(hun, hunans);
        strcat(numans, hunans);
        strcat(numans, " hundred ");
    }
    if (tendigit>0) {
        sayten(tendigit, hunans);
        strcat(numans, hunans);
        strcat(numans, " ");
    }
    if (numans[strlen(numans)-1]==' ') {
       numans[strlen(numans)-1] = '\0'; 
    }

    return 0;
}
int sayhun(int64_t input, char *hunans) {
    char * digitans=malloc(50*sizeof(char));
    char * tenans=malloc(50*sizeof(char));
    strcpy(hunans,"");
    int64_t digit=input/100;
    if (digit>0) {
        saydigit(digit, digitans);
        strcat(hunans, digitans);
        strcat(hunans, " hundred ");
    }    
    int64_t ten = input % 100;
    sayten(ten, tenans);
    strcat(hunans, tenans);
    return 0;
}

int sayten(int64_t input, char *tenans) {

    char * digitans=malloc(50*sizeof(char));
    int64_t ten = input / 10;
    int64_t digit = input % 10;
    if (ten == 0) {
        saydigit(digit, digitans);
        strcat(tenans,digitans);
        return 0;
    }
    if (ten == 1) {

        switch(digit){
             case 0: strcpy(tenans,"ten"); break;
             case 1: strcpy(tenans,"eleven"); break;
             case 2: strcpy(tenans,"twelve"); break;
             case 3: strcpy(tenans,"thirteen"); break;
             case 4: strcpy(tenans,"fourteen"); break;
             case 5: strcpy(tenans,"fifteen"); break;
             case 6: strcpy(tenans,"sixteen"); break;
             case 7: strcpy(tenans,"seventeen"); break;
             case 8: strcpy(tenans,"eighteen"); break;
             case 9: strcpy(tenans,"nineteen"); break;
        }
        return 0;
    }
    
    if (ten > 1) {
        switch(ten){
             case 2: strcpy(tenans,"twenty"); break;
             case 3: strcpy(tenans,"thirty"); break;
             case 4: strcpy(tenans,"forty"); break;
             case 5: strcpy(tenans,"fifty"); break;
             case 6: strcpy(tenans,"sixty"); break;
             case 7: strcpy(tenans,"seventy"); break;
             case 8: strcpy(tenans,"eighty"); break;
             case 9: strcpy(tenans,"ninety"); break;
        }     
        if (digit==0) return 0;   
        saydigit(digit, digitans);
        strcat(tenans,"-");
        strcat(tenans,digitans);
        return 0;
    }
    return 0;
}    

int saydigit(int64_t digit, char * digitans){

    switch (digit) {
        case 0: strcpy(digitans,""); break;
        case 1: strcpy(digitans,"one");break;
        case 2: strcpy(digitans,"two");break;
        case 3: strcpy(digitans,"three");break;
        case 4: strcpy(digitans,"four");break;
        case 5: strcpy(digitans,"five");break;
        case 6: strcpy(digitans,"six");break;
        case 7: strcpy(digitans,"seven");break;
        case 8: strcpy(digitans,"eight");break;
        case 9: strcpy(digitans,"nine");break;
    }
    return 0;
}    