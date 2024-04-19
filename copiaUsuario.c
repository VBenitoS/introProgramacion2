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
  FILE *f;
  f = fopen("usuarios.txt", "r");
  if(f == NULL) {
        printf("No se pudo abrir el archivo.\n");
        return 1; // Terminar el programa con un código de error
  } else {
    usuario_t user;
    usuario_t copia;
    user.nombre =leelineaDinamicaFichero(f);
    user.ape1 =leelineaDinamicaFichero(f);
    user.ape2 =leelineaDinamicaFichero(f);

    copia = user;

    printf("El nombre es: %s\n", copia.nombre);
    printf("El nombre es: %s\n", copia.ape1);
    printf("El nombre es: %s\n", copia.ape2);

    free(user.nombre);
    free(user.ape1);
    free(user.ape2);
  }
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
