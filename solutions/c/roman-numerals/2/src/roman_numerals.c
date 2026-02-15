#include "roman_numerals.h"
#include "ctype.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

char *to_roman_numeral(int arabic){ 
  typedef struct roman_numeral_info {
    int limit;
    int ltype;
    char *roman_digit;
  } roman_numeral_info; 
  roman_numeral_info roman_numerals[]={{1000, 1, "M"},
                                       {900, 2, "CM"},
                                       {500, 2, "D"},
                                       {400, 2, "CD"},
                                       {100, 1, "C"},
                                       {90, 2, "XC"},
                                       {50, 2, "L"},
                                       {40, 2, "XL"},
                                       {10, 1, "X"},
                                       {9, 2, "IX"},
                                       {5, 2, "V"},
                                       {4, 2, "IV"},
                                       {1, 1, "I"}
                                      };
  char *roman_numeral = malloc( sizeof(char) * (MAX_ROMAN_NUMBER_SIZE + 1));
  strcpy(roman_numeral, "");
  int anum = arabic;
  for (int di = 0; anum != 0 && di < NUMBER_OF_DIGITS; di++) {
    if (anum >= roman_numerals[di].limit) {
      if (roman_numerals[di].ltype == 1) {
        for (int ri = 0; ri < (anum / roman_numerals[di].limit); ri ++){
          strcat(roman_numeral, roman_numerals[di].roman_digit);
        }
        anum = anum % roman_numerals[di].limit; 
      } else {
        strcat(roman_numeral, roman_numerals[di].roman_digit);
        anum = anum - roman_numerals[di].limit;
      }
    }
  }
	return roman_numeral;
}
