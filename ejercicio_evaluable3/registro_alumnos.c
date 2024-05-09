#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *leelineaDinamicaFichero(FILE *f);

int main(int argc, char *argv[]){
  FILE *f = fopen(argv[1], "r");
  FILE *f2 = fopen(argv[2], "w");
  char *linea;
  printf("El fichero tiene %d lineas\n", cont);
  return 0;
}

char *leelineaDinamicaFichero(FILE *f) {
  int tam_cadena = 0;
  char aux = '\0';
  char *ptr = NULL;
  ptr = (char*)malloc(sizeof(char));
  while ((aux = fgetc(f)) != '\n')
  {
    ptr = (char*)realloc(ptr, tam_cadena + 1);
    ptr[tam_cadena++] = aux;
    *num++;
  }
  ptr[tam_cadena] = '\n';
  return ptr;
}
