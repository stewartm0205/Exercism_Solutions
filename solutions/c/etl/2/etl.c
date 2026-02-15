#include "etl.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>

int convert(const legacy_map *input, const size_t input_len, new_map **output){

    int counts[26] = {0};
    int values[26] = {0};
    for (size_t il=0; il<input_len; il++){
        for (size_t i=0; i<strlen(input[il].keys); i++) {
            counts[tolower(input[il].keys[i])-'a']=1;
            values[tolower(input[il].keys[i])-'a']=input[il].value;
        }

    }
    *output = malloc(26*sizeof(new_map));
    int al=0;
    for (size_t j=0;j<26;j++){
        if (counts[j]>0){
            (*output)[al].value=values[j];
            (*output)[al].key=(char)'a'+j;
            al++;
        }
    }
    return al; 
}