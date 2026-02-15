#ifndef PIG_LATIN_H
#define PIG_LATIN_H

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>

char *translate(const char *phrase);
char *getword(size_t* pi, const char *phrase);
char * getkcluster(char * w);
char* substring(char* str, size_t startpos, size_t endpos);

#endif
