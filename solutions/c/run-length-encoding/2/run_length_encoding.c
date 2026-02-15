#include "run_length_encoding.h"
#include <string.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

char *encode(const char *text){
    size_t tl=strlen(text);
    char* ec=malloc(tl*sizeof(char));
    char ccstr[10];
    char cch;
    size_t eci = 0;
    size_t chcount = 0;
    for(size_t ti=0; ti<tl; ti++) {
        if (ti==0) {
            cch=text[0];
            chcount = 1;
        } else if (text[ti]!=cch){
            if (chcount >1) {
                sprintf(ccstr,"%ld",chcount);
                for (size_t i=0; i<strlen(ccstr);i++) {
                    ec[eci++]=ccstr[i];
                }               
            }
            ec[eci++]=cch;
            cch=text[ti];
            chcount = 1;
        } else {
            chcount++;
        }   
    }
    if (chcount >1) {
        sprintf(ccstr,"%ld",chcount);
        for (size_t i=0; i<strlen(ccstr);i++) {
            ec[eci++]=ccstr[i];
        }               
    }
    ec[eci++]=cch;
    ec[eci]='\0';
    return ec;
}
char *decode(const char *data){
    size_t dl=strlen(data);
    char* dc=malloc(dl*6*sizeof(char));
    size_t dci = 0;
    size_t nl = 0;
    int nc;
    char num[10];
    for (size_t di=0; di<dl; di++) {
        if (isdigit(data[di])) {
            num[nl++]=data[di];
        } else {
            if (nl>0) {
                num[nl] = '\0';
                sscanf(num, "%d", &nc);
                for (int i=0; i<nc-1; i++) {
                    dc[dci++]=data[di];
                }    
                nl=0;
            }
            dc[dci++]=data[di];
        }
    }
    printf("dc=<%s>\n");
    return dc;

}