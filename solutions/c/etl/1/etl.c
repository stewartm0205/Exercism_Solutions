#include "etl.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>

int convert(const legacy_map *input, const size_t input_len, new_map **output){

    int counts[26] = {0};
    int values[26] = {0};
    //if (output==NULL) printf("NULL\n");
    for (size_t il=0; il<input_len; il++){
        for (size_t i=0; i<strlen(input[il].keys); i++) {
            counts[tolower(input[il].keys[i])-'a']=1;
            values[tolower(input[il].keys[i])-'a']=input[il].value;
        }

    }
    for (size_t j=0;j<26;j++){
        printf("j=%lu,c=%d,val=%d|",j,counts[j],values[j]);
    }
    printf("\n");
    *output = malloc(26*8);
    //if (output2==NULL) return 0;
    for (size_t j=0;j<26;j++){
        output[j]=malloc(sizeof(new_map));
    }
    int al=0;
    for (size_t j=0;j<26;j++){
        if (counts[j]>0){
            printf("al=%d\n",al);
            printf("after malloc\n");
            output[al]->value=values[j];
            output[al]->key=(char)'a'+j;
            al++;
        }
    }
    printf("{");
    for (int j=0;j<al;j++){
        printf("{'%c',%d},",output[j]->key,output[j]->value);
    }
    printf("}\n");
    printf("al=%d\n",al);
    //output=output2;
    return al; */
}