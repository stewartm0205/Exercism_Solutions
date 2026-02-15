#include "grains.h"
#include "ctype.h"
#include "stdio.h"

unsigned long long square(unsigned int n)
{
	if (n==0 || n > 64) return (0);
	unsigned long long g = 1;
	for (unsigned int i=2; i<=n; i++){
 		g *= 2;         
	}
	return g;
}

unsigned long long total()
{
	unsigned long long t = 0;
	for (unsigned int i=1; i<=64; i++){
 		t += square(i);         
	}
	return t;
}
