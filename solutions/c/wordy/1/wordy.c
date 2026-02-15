#include "wordy.h"

bool answer(const char *question, int *result){
    int tot;
    int num;
    int qi = 0;
    bool ans=true;
 
    if (!parse_question_parta(&qi, question, &num)) return false;
    tot = num;
    char op;
    while ((ans=parse_question_rest(&qi, question, &op, &num)) && 
           qi <(int)strlen(question)) {
        switch (op) {
            case '+':tot+=num;break;
            case '-':tot-=num;break;
            case '*':tot*=num;break;
            case '/':tot/=num;break;
        }
    }
    *result=tot;
    return ans;
}
bool parse_question_parta(int * qi, const char *question, int * num) {
    if (strlen(question) < 10) {
        return false;
    }
    char pref [10];
    strncpy(pref,question,8);
    if (strcmp(pref, "What is ")) {
        return false;
    }
    * qi = 8;
    char * numstr = malloc(20*sizeof(char));
    get_word(qi, question, numstr);
    sscanf(numstr,"%d",num);
    return true;    
}    

bool parse_question_rest(int * qi, const char *question, char* op, int * num) {
    if (question[*qi] == '?') {
        *qi+=1;
        return true;
    }
    char fullop[10] = "";
    char by[10] = "";
    *op=' ';
    get_word(qi, question, fullop);
    if (!strcmp(fullop,"plus")) *op='+';
    if (!strcmp(fullop,"minus")) *op='-';
    if (!strcmp(fullop,"multiplied")) {
        get_word(qi, question, by);
        if (strcmp(by,"by")) return false;
        *op='*';
    }
    if (!strcmp(fullop,"divided")) {
        get_word(qi, question, by);
        if (strcmp(by,"by")) return false;
        *op='/';
    }
 
    if (strlen(fullop)>0 && *op==' ') return false;
    char numstr[10]="";
    get_word(qi,question,numstr);
    sscanf(numstr,"%d",num);
    if (numstr[0]=='?')return false; else return true;   
}

void get_word(int * qi, const char* question, char* word) {
    int wi=0;
    if (question[*qi] == ' ') *qi+=1;
    if (question[*qi]=='?') {
        word[0]='?';
        word[1]='\0';
        return;
    }
    while(question[*qi]!=' ' && question[*qi]!='?' && *qi<(int)strlen(question)) {
        word[wi++]=question[*qi];
        *qi+=1;
    }
    return;

}
