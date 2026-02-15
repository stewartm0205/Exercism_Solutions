#include "rail_fence_cipher.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

char *encode(char *text, size_t rails){
    size_t tl=strlen(text);
    char ** rail = malloc(rails*sizeof(char *));
    for (size_t ri=0; ri<rails;ri++){
        rail[ri]=malloc((tl+1)*sizeof(char));
        size_t rli;
        for (rli=0;rli<tl;rli++){
            rail[ri][rli]=' ';
        }
        rail[ri][rli]='\0';
    }
    size_t ri=0;
    size_t rli=0;
    size_t dir=1;
    for (size_t ti=0;ti<tl;ti++){
        if(text[ti]!=' ') rail[ri][rli++]=text[ti];
        ri+=dir;
        if (ri==rails-1||ri==0) {
            dir=-1*dir;
        }
    }

    char * ec=malloc((tl+1)*sizeof(char));
    size_t eci = 0;
    for (size_t ri=0; ri<rails; ri++) {
        for (size_t rli=0; rli<tl; rli++) {
            if (rail[ri][rli]!=' ') ec[eci++] = rail[ri][rli];
        }
    }
    ec[eci]='\0';
    return ec;
}

char *decode(char *ciphertext, size_t rails){
    size_t cdl=strlen(ciphertext);
    char ** rail = malloc(rails*sizeof(char *));
    char * text=malloc((cdl+1)*sizeof(char));
    for (size_t ri=0; ri<rails;ri++){
        rail[ri]=malloc((cdl+1)*sizeof(char));
        size_t rli;
        for (rli=0;rli<cdl;rli++){
            rail[ri][rli]=' ';
        }
        rail[ri][rli]='\0';
    }

    int * r = calloc(rails,sizeof(int));
    int * nc = calloc(rails,sizeof(int));
    int * sti= calloc(rails,sizeof(int));

    nc[0] = cdl / (2 * rails - 2);
    if (cdl % (2 * rails - 2)!=0) nc[0]++;
    sti[0] = 0;

    for (int ri=1; ri < (int)(rails-1); ri++){
        nc[ri] =  cdl / (rails-1); 
        sti[ri] = sti[ri-1] + nc[ri-1];
    }

    nc[rails-1] = cdl / (2 * rails - 2);
    sti[rails-1] = nc[0]+(rails-2)*nc[1];       

    int rli=0;
    int ri=0;
    int dir = 1;
    for(rli=0;rli<(int)cdl;rli++){

        rail[ri][rli]=ciphertext[sti[ri]+r[ri]];
        r[ri]++;

        ri+=dir;
        if (ri==(int)rails) {
            dir=-1;
            ri=rails-2;
        } else if (ri==0) {
            dir=1;
            ri=0;
        }
    
    }

    for (size_t ri = 0; ri<rails; ri++) {
        rail[ri][rli]='\0';
    }
    int ti;
    rli = 0;
    ri = 0;
    dir = 1;
    for (ti=0;ti<(int)cdl;ti++){
        text[ti]=rail[ri][rli++];
        ri+=dir;
        if (ri==(int)rails-1||ri==0) {
            dir=-1*dir;
        }
    }
    text[ti]='\0';
    return text;

}
