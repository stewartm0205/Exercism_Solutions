#include "pangram.h"
#include "stdio.h"
#include "ctype.h"

bool is_pangram(const char *sentence)
{
  int ac[26] = {0};  
  if (!sentence) {return false;}
  if (sentence[0]=='\0') {return false;}
  for (int i = 0; sentence[i]!='\0'; i++){
    if (tolower(sentence[i]) >= 'a' && 
        tolower(sentence[i]) <= 'z')  {
      ac[tolower(sentence[i])-'a']=1;
    }
  }
  for (int i = 0; i<=25; i++){
    if (ac[i]==0) {
      return false; 
    }
  }
	return true;
}
