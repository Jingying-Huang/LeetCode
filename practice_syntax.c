#include <stdio.h>

enum directions { NORTH, SOUTH, EAST, WEST };

typedef char *string;

void fun(int a) { printf("Values of a is %d\n", a); }

void add(int a, int b) { printf("Addition is %d\n", a + b); }

void subtract(int a, int b) { printf("Subtraction is %d\n", a - b); }

void multiply(int a, int b) { printf("Multiplication is %d\n", a * b); }

int main() {

  string list[] = {"first", "second", "third", NULL};
  for (string *p = list; *p != NULL; p++) {
    printf("%s\n", *p);
  }

  void (*fun_ptr)(int) = &fun;
  (*fun_ptr)(10);

  void (*fun_ptr_arr[])(int, int) = {add, subtract, multiply};

  unsigned int ch, a = 15, b = 10;

  printf("Enter Choice: 0 for add, 1 for subtract and 2 for multiply\n");
  scanf("%d", &ch);
  if (ch > 2)
    return 0;
  (*fun_ptr_arr[ch])(a, b);
}