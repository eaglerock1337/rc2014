#include <stdio.h>

void main(void) {
  for(int i = 1; i <= 100; i++) {
    if (i % 5 != 0 && i % 3 != 0) {
      printf("%d", i);
    } else {
      if (i % 3 == 0) { printf("Fizz"); }
      if (i % 5 == 0) { printf("Buzz"); }
    }
    printf("\n");
  }
}