#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *leelineaDinamicaFichero(FILE *f);
void contarLetras(char *linea, int *vocales, int *digitos, int *consonantes);

int main(int argc, char *argv[]) {
  FILE *f;
  f= fopen(argv[1], "r");
  char *linea;
  do {
    linea = leelineaDinamicaFichero(f);
    printf("Línea leída: \"%s\"\n", linea); // Imprime la línea leída para diagnóstico
    free(linea);
  } while(linea != NULL);
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
  ptr[tam_cadena] = '\0';
  return ptr;
}
