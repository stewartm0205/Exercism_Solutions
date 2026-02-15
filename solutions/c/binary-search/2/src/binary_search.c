#include "binary_search.h"
#include "ctype.h"
#include "stdio.h"
#include "math.h"

int * binary_search (int n, int arr[], size_t length) {
  int i = (length - 1) / 2;
  int b = 0;
  int t = length - 1;
  if (arr == 0) return NULL;
  if ((n < arr[0]) | (n > arr[t])) return NULL;
  while (1 == 1) {
    if (arr[i] == n){
      return &arr[i];
    } else if (i < (int) length && n > arr[i] && n < arr[i+1]){
      break;
    } else if (n > arr[i]){
      b = i++;
      i = i + (t - i)/2;
    } else if (i > 0 && n > arr[i-1]){
      break;
    } else {
      t = i--;
      i =  i - (i - b)/2;
    }
	}
  return NULL;
}

