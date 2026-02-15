#include "pig_latin.h"

char *translate(const char *phrase){
    char* pl = (char*)malloc(255);
    pl[0]='\0';
    char* nw = malloc(255);
    char * w;
    //l = strlen(phrase);
    size_t pi=0;
    while ((w=getword(&pi, phrase))) {
        if (w[0]=='a'||w[0]=='e'||w[0]=='i'||w[0]=='o'||w[0]=='u'||
            (strlen(w)>1 && ((w[0]=='x' && w[1]=='r')||
                             (w[0]=='y' && w[1]=='t')))) {
            strcat(pl,w);
            strcat(pl,"ay");
        } else {
            char* kcluster = getkcluster(w);
            char* rw=substring(w,strlen(kcluster),strlen(w)-strlen(kcluster)+2);
            if (strlen(w)>=2 && w[0]=='q' && w[1]=='u') {
              rw=substring(w,2,strlen(w));
              strcpy(nw,rw);
              strcat(nw,"quay");
              strcat(pl,nw);
            } else if (strlen(w)>=3 && w[1]=='q' && w[2]=='u') {
              rw=substring(w,3,strlen(w));
              strcpy(nw,rw);
              rw=substring(w,0,0);
              strcat(nw,rw);
              strcat(nw,"quay");
              strcat(pl,nw);
            } else if (strlen(w)==2 && w[1]=='y') {
              strcpy(nw,"y");
              rw=substring(w,0,0);
              strcat(nw,rw);
              strcat(nw,"ay");
              strcat(pl,nw);
            } else {
              strcpy(nw,rw);
              strcat(nw,kcluster);
              strcat(nw,"ay");
              strcat(pl,nw);
            }
        }
        if (pi>=strlen(phrase)) break; 
        strcat(pl," "); 
    }
    return pl;
}
char *getword(size_t* pi, const char *phrase){
  char * w=malloc(20*sizeof(char));
  size_t wi=0;
  while(phrase[*pi]!=' ' && *pi<strlen
  (phrase)) {
    w[wi++]=phrase[*pi];
    *pi += 1;
  }
  *pi += 1;
  w[wi]='\0';
  return w;
}

char * getkcluster(char * w){
  char* kcluster = malloc(20*sizeof(char));
  size_t i;
  for (i=0; i<strlen(w) && w[i]!='a'&&w[i]!='e'&&w[i]!='i'&&
       w[i]!='o'&&w[i]!='u';i++){
    kcluster[i]=w[i];
  }
  kcluster[i]='\0';
  // check for a y 
  for (i=0; i<strlen(kcluster) && kcluster[i]!='y'; i++);
  if (i<strlen(kcluster)-1) kcluster[i]='\0';
  return kcluster;
}

char* substring(char* str, size_t startpos, size_t endpos) {
  char * rstr=malloc((strlen(str)+1)*sizeof(char));
  size_t ri=0;
  for (size_t i=startpos;i<=endpos;i++) {
    rstr[ri++]=str[i];
  }
  rstr[ri]='\0';
  return rstr;
}