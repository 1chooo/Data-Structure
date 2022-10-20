#include "stdio.h"
#include "stdlib.h"

int main(void) {
  int list[5], *plist[5];

  for (int i = 0; i < 5; i++) {
    printf("%d\n", plist[i]);
  }

  return 0;
}