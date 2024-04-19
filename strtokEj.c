#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char *cadena;
  char frase[]="Me voy de fiesta";
  cadena = strtok(frase, " ");
  do {
    printf("%s", cadena);
    cadena = strtok(NULL, " ");
  }while(cadena);
  printf("\n");
  return 0;
}
