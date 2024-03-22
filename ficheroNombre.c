#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  FILE *f;
  f = fopen("ejemplo.txt", "w");
  fputs("Victor Benito Salvador", f);
  fclose(f);
  return 0;
}
