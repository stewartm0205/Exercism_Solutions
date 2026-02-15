#include "secret_handshake.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

const char **commands(size_t number) {
    char ** cmds=malloc(5*sizeof(char*));
    char ** revcmds=malloc(5*sizeof(char*));
    for (size_t i=0;i<5;i++){
        cmds[i]=malloc(15*5*sizeof(char));
        revcmds[i]=malloc(15*5*sizeof(char));
    }
    if (number==0||number==16) return (const char**) cmds[0];
    size_t nc=0;
    for (size_t i = 0;i<=5;i++){
        size_t b=number % 2;
        number=number/2;
        if (b==1) {
            switch (i) {
                case 0: strcpy(cmds[nc++],"wink");break;
                case 1: strcpy(cmds[nc++],"double blink");break;
                case 2: strcpy(cmds[nc++],"close your eyes");break;
                case 3: strcpy(cmds[nc++],"jump");break;
                case 4: {
                    size_t rci = nc-1;
                    for (size_t j=0;j<nc;j++){
                        strcpy(revcmds[rci--],cmds[j]);
                    }
                    return (const char**) revcmds;
                }
            }
        }
    }
    return (const char**) cmds;
}


