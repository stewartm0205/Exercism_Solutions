#ifndef WORDY_H
#define WORDY_H

#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

bool answer(const char *question, int *result);
bool parse_question_parta(int * qi, const char *question, int * num);
bool parse_question_rest(int * qi, const char *question, char* op, int * num);
void get_word(int * qi, const char* question, char* word);

#endif
