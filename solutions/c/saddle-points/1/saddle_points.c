#include "saddle_points.h"
#include <stdio.h>

saddle_points_t* saddle_points(uint8_t rows, uint8_t columns, uint8_t matrix[rows][columns]){
  
    saddle_points_t* sps = malloc(sizeof(saddle_points_t));
    if (matrix==NULL){
        sps->count=0;
        return sps;
    }    
    sps->points = malloc(0);
    size_t spi=-1;
    uint8_t rowmax;
    uint8_t maxcol;
    uint8_t maxrow;
    for (uint8_t r=0; r<rows; r++){
        rowmax=0;
        for (uint8_t c=0; c<columns; c++) {
            //find max value in row
            if (matrix[r][c]>rowmax) {
                rowmax=matrix[r][c];
                maxcol=c;
            }
        }
        //check if max val in row is min val in col
        uint8_t dr;
        for (dr=0; dr<rows; dr++) {
            if (dr!=r && matrix[dr][maxcol]<rowmax) break;
        }
        if (dr==rows) {
            maxrow=r;
            break; 
        }  else {
            rowmax=0;
        }  
    }
    
    if (rowmax>0) {                
        spi++;
        sps->points = realloc(sps->points,(spi+1)*sizeof(saddle_point_t));
        sps->count++;
        sps->points[spi].row=maxrow+1;
        sps->points[spi].column=maxcol+1;

        for (uint8_t i=maxcol+1;i<columns;i++) {
            if (matrix[maxrow][i]==rowmax) {                
                spi++;
                sps->points = realloc(sps->points,(spi+1)*sizeof(saddle_point_t));
                sps->count++;
                sps->points[spi].row=maxrow+1;
                sps->points[spi].column=i+1;
            }
        }
        if (spi<1) {
            for (uint8_t i=maxrow+1;i<rows;i++) {
                if (matrix[i][maxcol]==rowmax) {                
                    spi++;
                    sps->points = realloc(sps->points,(spi+1)*sizeof(saddle_point_t));
                    sps->count++;
                    sps->points[spi].row=i+1;
                    sps->points[spi].column=maxcol+1;
                }
            }           
        } 
    }
    return sps;

}

void free_saddle_points(saddle_points_t* sp){
    free(sp);
}
