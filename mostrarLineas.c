#include <stdio.h>
#include <stdlib.h>

char *leelineaDinamicaFichero(FILE *f);

typedef struct {
  int numLineas;
  char **lineas;
}lineas_t;

int main(int argc, char *argv[]) {
  FILE *f;
  f= fopen(argv[2], "r");
  lineas_t linea;
  linea.numLineas = atoi(argv[1]);
  linea.lineas = (char**)malloc(linea.numLineas*sizeof(char*));
  for(int i=0; i< linea.numLineas; i++) {
    linea.lineas[i] = leelineaDinamicaFichero(f);
  }
  for(int i=0; i< linea.numLineas; i++) {
    printf("%s", linea.lineas[i]);
  }
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
