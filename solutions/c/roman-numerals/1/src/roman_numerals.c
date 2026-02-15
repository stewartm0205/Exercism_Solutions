#include "roman_numerals.h"
#include "ctype.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

char *to_roman_numeral(int arabic){ 
  int limit[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1}; 
  int ltype[]  = {1,    2,   2,   2,   1,   2,  2,  2,  1,  2, 2, 2, 1};
  char *roman_digits[]  = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", 
                           "X", "IX", "V", "IV", "I"};
  char *roman_numeral = malloc( sizeof(char) * 51);
  strcpy(roman_numeral, "");
  int anum = arabic;
  for (int di = 0; anum != 0 && di < 13; di++) {
    if (anum >= limit[di]) {
      if (ltype[di] == 1) {
        for (int ri = 0; ri < (anum / limit[di]); ri ++){
          strcat(roman_numeral, roman_digits[di]);
        }
        anum = anum % limit[di]; 
      } else {
        strcat(roman_numeral, roman_digits[di]);
        anum = anum - limit[di];
      }
    }
  }
	return roman_numeral;
}
