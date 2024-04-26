#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  char cadena[] = "Mi coche es jueves.";
  char *resultado = strstr(cadena, "jueves");
  memcpy(resultado,"vierne",6);
  printf("%s\n", cadena);
  return 0;
}
