#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  FILE *f;
  char cadena[50];
  f = fopen(argv[1], "r");
  while(fgets(cadena, 50, f)!=NULL) {
    printf("%s", cadena);
  }
  fclose(f);
  return 0;
}
