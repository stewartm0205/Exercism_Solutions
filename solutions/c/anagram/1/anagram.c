#include "anagram.h"
#include <string.h>
#include <ctype.h>

void find_anagrams(const char *subject, struct candidates *candidates){

    for (size_t ci=0; ci < candidates->count; ci++){
        candidates->candidate[ci].is_anagram=UNCHECKED;
        if (is_anagram(subject, candidates->candidate[ci].word)){
            candidates->candidate[ci].is_anagram=IS_ANAGRAM;
        } else {
            candidates->candidate[ci].is_anagram=NOT_ANAGRAM;
        }
    }
}

bool is_anagram(const char *subject, const char *word){
    if (strlen(word)!=strlen(subject)) return false;
    char cword[30];
    strcpy(cword,word);
    size_t wi;
    for (wi = 0; subject[wi]!='\0';wi++) {
        if (tolower(word[wi])!=tolower(subject[wi])) break;
    }
    if (wi==strlen(word)) return false;
    for (int ci = 0; subject[ci]!='\0';ci++) {
        char* lcp = strchr(cword,tolower(subject[ci]));
        char* ucp = strchr(cword,toupper(subject[ci]));
        if (lcp==NULL && ucp==NULL) return false; 
        if (lcp!=NULL) *lcp=' ';
        if (ucp!=NULL) *ucp=' ';
    }
    return true;
}
