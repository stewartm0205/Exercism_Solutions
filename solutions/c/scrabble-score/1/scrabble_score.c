#include "scrabble_score.h"
#include <string.h>
#include <ctype.h>

unsigned int score(const char *word) {
    size_t wl = strlen(word);
    unsigned int s=0;
    for (size_t wi=0; wi<wl; wi++) {
        switch(tolower(word[wi])) {
            case 'd': case 'g': s+=2; break;
            case 'b': case 'c': case 'm': case 'p': s+=3; break;
            case 'f': case 'h': case 'v': case 'w': case 'y': s+=4; break;
            case 'k': s+=5; break;
            case 'j':case 'x': s+=8; break;
            case 'q':case 'z': s+=10; break;
            default :s++;
        }
    }
    return s;
}
