#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool isNotValid(char *l, char *r) { return strlen(l) == strlen(r); }

bool isE(char *p) { return *p == 'e'; };

bool isInt(char *x) { return atoi(x) != 0; }

bool isNumber(char *s) {
  char *p;
  int numl = strtol(s, &p, 10);

  char *x;
  ++p;
  int numr = strtol(p, &x, 10);

  if (isNotValid(s, p)) {
    return false;
  } else if (isE(p)) {
    if (isNotValid(p, x)) {
      return false;
    }
    ++p;

    if (numr == 0 && isNotValid(p, x)) {
      return false;
    } else if (isInt(p)) {
      return false;
    }
    return true;
  }
  return true;
}

int main(int argc, char **argv) {
  char *s = "-1e123a";
  bool foo = isNumber(s);

  printf("Input is %d\n", foo);
}