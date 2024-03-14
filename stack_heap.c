#include <stdio.h>
#include <stdlib.h>
void func(int valor) {
  unsigned int c;
  unsigned int *ptr;
  ptr = malloc(1);
  printf("Stack: %p | Heap: %p\n", &c, ptr);
  if(valor <= 0) return;
  func(valor - 1);
}
int main() {
  func(10);
  return 0;
}
