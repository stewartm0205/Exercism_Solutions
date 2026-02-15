#include "armstrong_numbers.h"
#include <stdio.h>
#include <math.h>
bool is_armstrong_number(int candidate){
	int nd = ceil(log10(candidate));
	int s = 0;
	int ds = candidate;
	for(int i=1;i<=nd;i++){
		int d=ds%10;
		ds=ds/10;
		s+=pow(d,nd);
	}
	if (s==candidate) return true;
	return false;
}
