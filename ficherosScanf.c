#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  FILE *f;
  char cadena[20];
  int num;
  f = fopen(argv[1], "r");
  fscanf(f, "%s %d", cadena, &num);
  printf("%s %d\n", cadena, num);
  fclose(f);
  return 0;
}
