#include "matching_brackets.h"
#include <stdio.h>

bool is_paired(const char *input) {
    char br[200];
    int bi=-1;
    for (int i=0; input[i]!='\0'; i++) {
        if (input[i] == '['||input[i] == ']'||input[i] == '{'||input[i] == '}'||input[i] == '('||input[i] == ')') br[++bi]=input[i];
        if (bi>0 && ((br[bi-1]=='['&&br[bi]==']')||(br[bi-1]=='{'&&br[bi]=='}')||(br[bi-1]=='('&&br[bi]==')'))) bi-=2;
    }
    if (bi>=0) return false;
    return true;
}
