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

void init(int** bin, int*** comb, unsigned int num_subsets, size_t size) {
  *bin = malloc((size - 1) * sizeof(int));
  *comb = malloc(num_subsets * sizeof(*bin));
  for (size_t i = 0; i < num_subsets; i++) {
    (*comb)[i] = malloc((size - 1) * sizeof(int));
  }
}

void releaseMem(int** arr, int** bin, int*** comb, unsigned int num_subsets) {
  if (*arr && *bin && *comb) {
    free(*arr);
    free(*bin);
    for (size_t i = 0; i < num_subsets; i++) {
      free((*comb)[i]);
    }
    free(*comb);
  }
}

char* append(char* str1, char* str2) {
  char* result = NULL;
  asprintf(&result, "%s%s", str1, str2);
  return result;
}

char** splitNum(int** comb, char* s, unsigned int num_subsets, size_t size) {
  char** result = malloc(num_subsets * sizeof(char*));
  for (size_t i = 0; i < num_subsets; i++) {
    result[i] = malloc(15 * sizeof(char));
  }

  for (size_t i = 0; i < num_subsets; i++) {
    char* joined = "";
    char* dash = "-";
    char first = s[0];
    joined = append(joined, s);

    for (size_t j = 0; j < size - 1; j++) {
      if (comb[i][j] == 1) {
        joined = append(joined, dash);
      } else {
        if (j + 1 < size - 1) {
          char symbol = s[j + 1];
          joined = append(joined, &symbol);
        }
      }
    }
    strcpy(result[i], joined);
    printf("%s\n", joined);
  }
  return result;
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
  int* bin;
  int** comb;
  int track = 0;
  size_t size = strlen(s);
  unsigned int num_subsets = pow(2, size - 1);
  init(&bin, &comb, num_subsets, size);
  int* arr = convert2Int(s, size);
  binaryGen(size - 1, bin, 0, &comb, &track, num_subsets);
  char** result = splitNum(comb, s, num_subsets, size);

  // for (size_t i = 0; i < num_subsets; i++) {
  //   printf("%c ", result[i]);
  // }

  releaseMem(&arr, &bin, &comb, num_subsets);
}

int main() {
  numDecodings("226");
  return 0;
}