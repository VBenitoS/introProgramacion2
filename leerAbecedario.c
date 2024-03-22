#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  FILE *f;
  f = fopen("ejemplo.txt", "r");
  char letra;
  while((letra = fgetc(f)) != EOF) printf("%c", letra);
  fclose(f);
  return 0;
}
