#ifndef ATBASH_CIPHER_H
#define ATBASH_CIPHER_H

#include <stdint.h>

char *atbash_encode(const char *input);
char *atbash_decode(const char *input);
char * reverse(char *str);
int charindex(char let, char *str);

#endif
