#include <stdio.h>
#include <stdlib.h>

#define ROWS 4
#define COLS 2
#define MAX 4

typedef enum { false, true } bool;

typedef struct {
  int data[COLS];
} my_data_t;

my_data_t arr[ROWS] = {{1, 3}, {2, 6}, {15, 18}, {8, 10}};

int less(const void* a, const void* b) {
  const my_data_t* ptr_a = a;
  const my_data_t* ptr_b = b;
  return (int)(ptr_a->data[0] - ptr_b->data[0]);
}

void sort_double_array() {
  qsort(arr, sizeof(arr) / sizeof(*arr), sizeof(*arr), less);
}

void merge_array(int* l1, int* l2) {
  int l[MAX] = {l1[0], l1[1], l2[0], l2[1]};
  int min, max;
  min = max = l[0];
  for (size_t i = 0; i < MAX; ++i) {
    if (l[i] < min) {
      min = l[i];
    }
    if (l[i] > max) {
      max = l[i];
    }
  }
  l1[0] = min;
  l1[1] = max;
}

bool is_overlap(int* l1, int* l2) {
  if (l1[1] < l2[0] || l1[0] > l2[1]) return false;
  return true;
}

my_data_t* merge(my_data_t* arr, int* returnSize) {
  my_data_t* returnArr = malloc(sizeof(my_data_t) * (*returnSize));
  returnArr[0] = arr[0];
  for (size_t i = 1; i < ROWS; ++i) {
    if (is_overlap(returnArr[i - 1].data, arr[i].data)) {
      merge_array(returnArr[i - 1].data, arr[i].data);
    } else {
      returnArr[i - 1] = arr[i];
    }
  }
  return returnArr;
}

int main() {
  sort_double_array();
  printf("Before merging:\n");
  for (size_t i = 0; i < ROWS; ++i) {
    for (size_t j = 0; j < COLS; ++j) {
      printf("%d\n", arr[i].data[j]);
    }
  }

  int size = 3;
  int* returnSize = &size;
  my_data_t* returnArr = merge(arr, returnSize);
  printf("After merging:\n");
  for (size_t i = 0; i < *returnSize; ++i) {
    for (size_t j = 0; j < COLS; ++j) {
      printf("%d\n", returnArr[i].data[j]);
    }
  }
  free(returnArr);
  return 0;
}
