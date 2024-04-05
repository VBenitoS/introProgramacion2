#include <stdio.h>
#include <stdlib.h>

char *leelineaDinamicaFichero(FILE *f);

typedef struct {
  int numLineas;
  char **lineas;
}lineas_t;

int main(int argc, char *argv[]) {
  FILE *f;
  f= fopen("ejemplo.txt", "r");
  lineas_t linea;

  fclose(f);
  return 0;
}

char *leelineaDinamicaFichero(FILE *f) {
  int tam_cadena = 0;
  char aux = '\0';
  char *ptr = NULL;


  ptr = (char*)malloc(sizeof(char));
  while ((aux = fgetc(f)) != '\n')
  {
    ptr[tam_cadena++] = aux;
    ptr = realloc(ptr, tam_cadena + 1);

  }
  ptr[tam_cadena] = '\n';
  return ptr;
}
