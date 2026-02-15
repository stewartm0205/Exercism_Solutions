#include "word_count.h"


int count_words(const char *sentence, word_count_word_t * words){

    int si = 0;
    char w[MAX_WORD_LENGTH + 1];
    char lcw[MAX_WORD_LENGTH + 1];
    while(get_next_word(&si,sentence,w)){
        to_lowercase(w,lcw);
        save_word(lcw,words);
    }
    // count up the words
    int wi;
    for (wi=0;words[wi].count>0;wi++){}
    return wi;
}

bool get_next_word(int * si, const char *sentence, char *w) {
    int i = 0;
    while((isspace(sentence[*si])||ispunct(sentence[*si]))&&*si<(int)strlen(sentence)) *si=*si+1;
    while((isalnum(sentence[*si])||sentence[*si]=='\'')&&*si<(int)strlen(sentence)){
        w[i]=sentence[*si];
        i++;
        *si=*si+1;
    }
    if (i>1 && w[i-1]=='\'')i--;
    w[i]='\0';
    if (strlen(w)>0) return true;
    return false;
}

void to_lowercase(char *w, char *lcw) {
    int i;
    for (i=0;w[i]!='\0';i++) {
        lcw[i]=tolower(w[i]);
    }
    lcw[i]='\0';
}

void save_word(char* word, word_count_word_t* words) {
    int i = 0;
    while (words[i].count>0 &&
           strcmp(word,words[i].text)) {
        i++;       
    }
    if (words[i].count>0) {
        words[i].count++;
    } else {
        strcpy(words[i].text,word);
        words[i].count = 1;
    }

}