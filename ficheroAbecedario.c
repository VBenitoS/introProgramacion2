#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  FILE *f;
  char min='a', mayus='A';
  f = fopen("ejemplo.txt", "a");
  fputs("El abecedario: \n", f);
  for(int i=0; i < 26; i++) {
    fputc(min, f);
    fputc('\t', f);
    fputc(mayus, f);
    fputc('\n', f);
    min++;
    mayus++;
  }
  fclose(f);
  return 0;
}
