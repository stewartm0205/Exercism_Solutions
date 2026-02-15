#include "scrabble_score.h"

namespace scrabble_score {
    int score(const char* word) {
        int s=0;
        for (size_t i=0; i<strlen(word); i++) {
            char ch = toupper(word[i]);
            if (strchr("A, E, I, O, U, L, N, R, S, T",ch)) s+=1;
            if (strchr("D, G",ch)) s+=2;
            if (strchr("B, C, M, P",ch)) s+=3;
            if (strchr("F, H, V, W, Y",ch)) s+=4;
            if (ch=='K') s+=5;
            if (strchr("J, X",ch)) s+=8;
            if (strchr("Q, Z",ch)) s+=10;
        }
        return s;
    }
}  // namespace scrabble_score
