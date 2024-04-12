#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  char nombre[10] = "Xela";
  char apellido[10] = "Erni";
  char full_name[25] = {'\0'};
  strcpy(full_name, nombre);
  strcat(full_name, " ");
  strcat(full_name, apellido);
  printf("%s\n", full_name);
  return 0;
}
