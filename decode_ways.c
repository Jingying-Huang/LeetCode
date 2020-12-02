#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Given a non-empty string containing only digits, determine the total number of
ways to decode it.
E.g.
  Input: s = "12"
  Output: 2
  Explanation: It could be decoded as "AB" (1 2) or "L" (12).

  Input: s = "226"
  Output: 3
  Explanation: It could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2
  6).

  Mathematically speaking, the number of possible decodings is 2^(n-1)
  As 12345 would be 0000, 12-345 would be 0100
*/

void get2dArr(int* arr, int num_subsets, int*** comb, int* track, size_t size) {
  if (*track < num_subsets) {
    for (size_t i = 0; i < size; i++) {
      (*comb)[*track][i] = arr[i];
    }
  }
  ++*track;
}

void binaryGen(size_t size, int* bin, size_t i, int*** comb, int* track,
               int num_subsets) {
  if (i == size) {
    get2dArr(bin, num_subsets, comb, track, size);
    return;
  }
  bin[i] = 0;
  binaryGen(size, bin, i + 1, comb, track, num_subsets);

  bin[i] = 1;
  binaryGen(size, bin, i + 1, comb, track, num_subsets);
}

void init() {}

int* convert2Int(char* s, size_t size) {
  size_t i = 0;
  int* arr = malloc(size * sizeof(int));
  for (; i < size; ++i) {
    arr[i] = s[i] - '0';
  }
  return arr;
}

void numDecodings(char* s) {
  // Initialization
  int track = 0;
  size_t size = strlen(s);
  int* arr = convert2Int(s, size);
  int* bin = malloc((size - 1) * sizeof(int));
  unsigned int num_subsets = pow(2, size - 1);
  int** comb = malloc(num_subsets * sizeof(bin));

  for (size_t i = 0; i < num_subsets; i++) {
    comb[i] = malloc((size - 1) * sizeof(int));
  }

  binaryGen(size - 1, bin, 0, &comb, &track, num_subsets);

  for (size_t i = 0; i < num_subsets; i++) {
    for (size_t j = 0; j < size - 1; j++) {
      printf("%d ", comb[i][j]);
    }
    printf("\n");
  }

  if (arr && comb) {
    free(arr);
    for (size_t i = 0; i < num_subsets; i++) {
      free(comb[i]);
    }
    free(comb);
  }
}

int main() {
  numDecodings("226");
  return 0;
}