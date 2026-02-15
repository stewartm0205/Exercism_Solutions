#include "acronym.h"
#include "ctype.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

char *abbreviate(const char *phrase)
{ 
  char* abbrev = malloc( sizeof(char) * 10);
  if (phrase == NULL || phrase[0] == '\0') {
    return NULL;
  }
  int j = -1;
  int fl = 1;
  for (int i = 0; phrase[i]!='\0'; i++){
    if (tolower(phrase[i]) >= 'a' && tolower(phrase[i]) <= 'z') {
      if (fl) {
        j++;
        abbrev[j] = toupper(phrase[i]);
        fl = 0;
      } 
    } else {
      if (phrase[i] != '\''){
        fl = 1;
      }
    }
  }

  abbrev[j+1]='\0';
	return abbrev;
}
