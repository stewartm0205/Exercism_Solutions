#include "grains.h"
#include "ctype.h"
#include "stdio.h"

uint64_t square(uint8_t n)
{
	if (n==0 || n > 64) return (0);
	uint64_t g = 1;
	for (uint8_t i=2; i<=n; i++){
 		g *= 2;         
	}
	return g;
}

uint64_t total()
{
	uint64_t t = 0;
	for (uint8_t i=1; i<=64; i++){
 		t += square(i);         
	}
	return t;
}
