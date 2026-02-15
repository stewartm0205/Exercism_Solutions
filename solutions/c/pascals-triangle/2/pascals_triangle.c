#include "pascals_triangle.h"
#include <stdio.h>


uint8_t **create_triangle(size_t rows) {

    uint8_t **pt = malloc(rows*sizeof(uint8_t*));
    for (size_t i=0;i<rows;i++) {
        pt[i] = malloc(rows*sizeof(uint8_t));
    }
    if (rows==0) {
        pt[0] = malloc(sizeof(uint8_t));
        pt[0][0]=0;
        return pt;
    }
 
    for (size_t ri=0; ri<rows; ri++){
        for (size_t ci=0; ci<rows;ci++){
            pt[ri][ci]=0;
        }
    }

    for (size_t ri=0; ri<rows; ri++){

        if (ri==0) pt[ri][0]=1;

        if (ri>0) {
            for (size_t ci=0; ci <= ri; ci++){
                if (ci==0) pt[ri][ci]=pt[ri-1][ci];
                else pt[ri][ci]=pt[ri-1][ci-1]+pt[ri-1][ci];
            }
        }

    }

    return pt;
}
void free_triangle(uint8_t **triangle, size_t rows){
    for (size_t i=0;i<rows;i++){
        free(triangle[i]);
    }
    free(triangle);
}
