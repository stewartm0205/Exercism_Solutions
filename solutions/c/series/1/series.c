#include "series.h"
#include "string.h"
#include <stdlib.h>

slices_t slices(char *input_text, unsigned int substring_length){
    slices_t ss;

    ss.substring = malloc(MAX_SERIES_RESULTS*sizeof(char **));

    if (substring_length > strlen(input_text) || substring_length==0) {
        ss.substring_count=0;
        ss.substring[0]="";
        return ss;
    }

    int ssi=0;
    for (size_t i=0; i<=strlen(input_text)-substring_length;i++){
        char* sstr=malloc((substring_length+1)*sizeof(char));
        size_t j;
        for(j=0;j<substring_length;j++){
            sstr[j]=input_text[i+j];
        }
        sstr[j]='\0';
        ss.substring[ssi]=sstr;
        ssi++;
    }
    ss.substring_count=ssi;
    return ss;
}
