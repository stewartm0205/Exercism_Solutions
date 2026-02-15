#include "bob.h"
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>

char *hey_bob(char *greeting){
 
    char* ans = (char*)malloc(300*sizeof(char));
    char * pg = (char*)malloc((strlen(greeting)+1)*sizeof(char));
    strcpy(pg,greeting);
    size_t gl=strlen(pg);

    if (all_blanks(pg)) {
        ans="Fine. Be that way!";
        return ans;
    }
    for (size_t gi=gl-1; pg[gi]==' '; gi--) {
        pg[gi]='\0';
    }
    gl=strlen(pg);

    if (!strcmp(uc_str(pg),pg)&&!no_letters(pg)) {
        if (greeting[gl-1] == '?') {
            ans="Calm down, I know what I'm doing!";
            return ans;
        } 
        ans="Whoa, chill out!";
        return ans;
    }
    if (pg[gl-1] == '?') {
        ans="Sure.";
        return ans;
    }
    ans="Whatever.";
    return ans;
}
    
char *uc_str(char* str) {
    char* uc = (char*)malloc(strlen(str));
    for (size_t i=0;i<strlen(str);i++) uc[i]=toupper(str[i]);
    return uc;
}

bool no_letters(char* str) {
    for (size_t i=0;i<strlen(str);i++) {
        if (isalpha(str[i])) return false;
    }    
    return true;
}

bool all_blanks(char* str) {
    for (size_t i=0;i<strlen(str);i++) {
        if (str[i]!=' '&&str[i]!='\t'&&str[i]!='\r'&&str[i]!='\n') return false;
    }    
    return true;
}
