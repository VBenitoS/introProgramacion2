#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  char cadena[] = "Me voy de fiesta";
  char *ptr=NULL;
  ptr = (char*)malloc(sizeof(cadena));
  memcpy(ptr, cadena, 2);
  fprintf(stdout, "%s\n", ptr);
  free(ptr);
  return 0;
}
