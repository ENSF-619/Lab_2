// lab2exe_C.c
// ENSF 619 Fall 2020 Lab 2 Exercise C

#include <stdio.h>

int what(const int *a, int n);

// This function was not written for easy readability!
// It's a drill exercise about pointer arithmetic!
int what(const int *a, int n)
{
  const int *max = a, *min = a + n - 1, *guard = a + n;
  const int *p, *q;
  for (p = a + 1; p != guard; p++) {
    if (*p > *max)
      max = p;
    
  }
 
  for (q = a + n - 1; q != a; q--) {
    if (q[-1] < *min)
      min = q - 1;
  }
  printf("\n test %d\n",*(min-2));

  // point one (after the 2nd loop has finished)

  return min - max;
}

int main(void)
{
  int w;
  int x[] = {99, 0, 0, -99, 0, 0};
  int y[] = {1, 0, 100, 2, 0, 3};
  w = what(x, sizeof(x) / sizeof(int));
  printf("1st result: %d.\n", w);
  w = what(y, sizeof(y) / sizeof(int));
  printf("2nd result: %d.\n", w);
  return 0;
}
