#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  FILE *f;
  char cadena[50];
  f = fopen(argv[1], "w");
  for(int i=2; i< argc; i++) {
    fprintf(f,"ola %s\n", argv[i]);
  }
  fclose(f);
  return 0;
}
