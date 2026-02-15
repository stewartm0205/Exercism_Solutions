#include "minesweeper.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char **annotate(const char **minefield, const size_t rows) {
    if (rows==0) return NULL;

    char **am=malloc(rows * sizeof(char *));
    size_t columns = strlen(minefield[0]);
    if (strlen(minefield[0])==0) {
        am[0]="";
        return am;
    };
    size_t* counts[rows];
    for(size_t r=0; r<rows; r++) {
        counts[r]=(size_t*)malloc(columns*sizeof(size_t));
        for(size_t c=0; c<columns; c++) {
            counts[r][c]=0;
        }
    }
    for(size_t r=0; r<rows; r++) {
        for(size_t c=0; c<columns; c++) {
            for (int dr=-1;dr<=1;dr++){
                for (int dc=-1;dc<=1;dc++) {
                    if (r+dr<rows && c+dc<columns && !(dr==0 && dc==0)) {
                        if (minefield[(r+dr)][c+dc]=='*') {
                            counts[r][c]++;
                        }
                    }
                }
            }
        }
    }
    for(size_t r=0; r<rows; r++) {
        char row[10]; 
        size_t c=0;
        for(c=0; c<columns; c++) {
            if (minefield[r][c]!='*' && counts[r][c]>0) {
                char num[2];
                sprintf(num,"%lu",counts[r][c]);
                row[c]=num[0];
            } else {
                row[c]=minefield[r][c];
            }
        }
        row[c]='\0';
        am[r]=malloc(rows * sizeof(char));
        strcpy(am[r],row);
    }
    for(size_t r=0; r<rows; r++) {
        free(counts[r]);
    }
    return am;
}
void free_annotation(char **annotation) {
    free(annotation);
}