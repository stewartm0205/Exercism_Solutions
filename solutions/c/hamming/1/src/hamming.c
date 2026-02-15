#include "hamming.h"
#include "string.h"
#include "ctype.h"
#include "stdio.h"

int compute(char *strand1, char *strand2)
{
	if (!strand1 || !strand2) return -1;
	if (strlen(strand1) != strlen(strand2)) return -1;
	int dist = 0;
	int l=strlen(strand1);
	for (int i=0; i<l; i++){
          	if (strand1[i] != strand2[i]) dist += 1;
	}
	return dist;
}
