#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool isNotValid(char *l, char *r) { return strlen(l) == strlen(r); }

bool isE(char *p) { return *p == 'e'; };

bool isInt(char *x) {
  int i, r, n;
  r = sscanf(x, "%d%n", &i, &n);
  if (r == 1 && n == strlen(x)) {
    return true;
  }
  return false;
}

bool isFloat(char *x) { return atof(x) != 0.0; }

bool isNumber(char *s) {
  char *p;
  int numl = strtol(s, &p, 10);

  char *x;
  int numr = strtol(p, &x, 10);

  if (isInt(s) || isFloat(x)) {
    return true;
  }

  if (isNotValid(s, p)) {
    return false;
  }

  if (isE(p)) {
    if (isNotValid(p, x)) {
      if (isInt(++x)) {
        return true;
      }
      return false;
    }
  }
  return false;
}

int main(int argc, char **argv) {
  char *s = "95a54e53";
  bool foo = isNumber(s);
  printf("Input is %d\n", foo);
}