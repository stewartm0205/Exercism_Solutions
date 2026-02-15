#include "isogram.h"
#include "ctype.h"
#include "stdio.h"

bool is_isogram(const char phrase[])
{
	int lc[26] = {0};
	for (int i = 0; phrase[i]!='\0'; i++) 
	{
		//printf("%d, %c", i, phrase[i]);
		if (isalpha(phrase[i]))
		{
			lc[(int)(tolower(phrase[i]))-(int)('a')]++;
			//printf("%d",lc[(int)(tolower(phrase[i]))-(int)('a')]);
			if (lc[(int)(tolower(phrase[i]))-(int)('a')]>1) return false;
		}

	}
	return true;
}
