#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char *argv[]) {
  int *ptr_int = (int*)malloc(10*sizeof(int));
  for(int i=0; i<11; i++) {
    ptr_int[i] = i;
  }
  for(int i=0; i <11; i++) {
    printf("%d\t", ptr_int[i]);
  }
  printf("\n");
  return 0;
}
