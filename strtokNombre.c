#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char *nombre;
  char *ape1;
  char *ape2;
}usuario_t;

char *leelineaDinamicaFichero(FILE *f);

int main(int argc, char *argv[]) {
  FILE *f = fopen("usuarios.txt", "r");
  FILE *f1 = fopen("usuarios2.txt", "a");

  char *total;
  usuario_t usuario;
  total = leelineaDinamicaFichero(f);
  usuario.nombre = strtok(total, " ");
  usuario.ape1 = strtok(NULL, " ");
  usuario.ape2 = strtok(NULL, " ");
  fprintf(f1, "%s ", usuario.nombre);
  fprintf(f1, "%s ", usuario.ape1);
  fprintf(f1, "%s", usuario.ape2);
  fclose(f);
  fclose(f1);
  free(total);
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
