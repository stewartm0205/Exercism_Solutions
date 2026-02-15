#include "binary_search.h"
#include "ctype.h"
#include "stdio.h"
#include "math.h"

int * binary_search (int n, int arr[], size_t length) {
  int i = (length - 1) / 2;
  int b = 0;
  int t = length - 1;
  if (arr == NULL) return NULL;
  while (1 == 1) {
    if (arr[i] == n){
      return &arr[i];
    } else if (i < (int) length && n > arr[i] && n < arr[i+1]){
      return NULL;
    } else if (n > arr[i] && n <= arr[length-1]){
      b = i;
      i = i + (t - i)/2;
      if (i == b) i++;
    } else if (i > 0 && n < arr[i] && n > arr[i-1]){
      return NULL;
    } else if (n < arr[i] && n >= arr[0]) {
      t = i;
      i =  i - (i - b)/2;
      if (i == t) i--;
    } else {
      return NULL;
    }
	}
}

