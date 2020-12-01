#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printSubsequences(int* arr, size_t size) {
  unsigned int num_subsets = pow(2, size);
  for (size_t i = 1; i < num_subsets; i++) {
    for (size_t j = 0; j < size; j++) {
      if (i & (1 << j)) {
        printf("%d", arr[j]);
      }
    }
    printf("\n");
  }
}

int* convert2Int(char* s, size_t size) {
  size_t i = 0;
  int* arr = malloc(size * sizeof(int));
  for (; i < size; ++i) {
    arr[i] = s[i] - '0';
  }
  return arr;
}

void numDecodings(char* s) {
  size_t size = strlen(s);
  int* arr = convert2Int(s, size);
  printSubsequences(arr, size);
  free(arr);
}

int main() {
  numDecodings("123");
  return 0;
}