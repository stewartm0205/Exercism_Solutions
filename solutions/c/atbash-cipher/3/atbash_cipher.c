#include "atbash_cipher.h"
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>

char *atbash_encode(const char *input){
    printf("encode input=%s\n",input);
    int il = strlen(input);
    char * alphabet="abcdefghijklmnopqrstuvwxyz";
    char * revalpha = reverse(alphabet);
   
    char * encode = malloc((il+1l/5)*sizeof(char));
    int five=0;
    int ei=0;
    for (int i=0;i<il;i++){
       
        if (isalpha(input[i])) {
            if (five>=5) {
                encode[ei++]=' ';
                five=0;
            }
            five++;
            encode[ei++]=revalpha[charindex(tolower(input[i]),alphabet)];
            
        } else if (isdigit(input[i])) {
            if (five>=5) {
                encode[ei++]=' ';
                five=0;
            }
            five++;
            encode[ei++]=input[i];         
        }
    }
    encode[ei]='\0';
    
    return encode;
}
char *atbash_decode(const char *input){
    printf("decode input=%s\n",input);
    int il = strlen(input);
    char * alphabet="abcdefghijklmnopqrstuvwxyz";
    char * revalpha = reverse(alphabet);
    char * decode = malloc((il+1l/5+8)*sizeof(char));
    int di=0;
    for (int i=0; i<il; i++){
        if (input[i] != ' '){
            if (isalpha(input[i])) decode[di++]=alphabet[charindex(input[i],revalpha)];
            else decode[di++]=input[i];
        }
    }
    decode[di]='\0';
    return decode;
}

char * reverse(char *str) {
    int sl = strlen(str);
    char * revstr = malloc((sl+8)*sizeof(char));
    int ri=0;
    for (int si=sl-1;si>=0;si--){
        revstr[ri++]=str[si];
    }
    revstr[ri]='\0';
    return revstr;
}

int charindex(char let, char *str) {
    for (int i=0; i <= (int)strlen(str); i++){
        if (let==str[i]) return i;
    }
    return -1;
}