#include <stdio.h>
#include <stdlib.h>

typedef enum {
  salir, nuevo, lista, prestamo
}opcion_e;

typedef struct {
  int numPag;
  char *autor;
  char *titulo;
}libro_t;

typedef struct {
  int numLibros;
  libro_t libros;
}biblioteca_t;

libro_t introducirLibro();
char *leeLineaDinamica();
opcion_e menu();
void guardarLibro(biblioteca_t *biblioteca);

int main(int argc, char *argv[]) {
  int opcion=0;
  opcion = menu();
  biblioteca_t biblioteca = malloc(sizeof(libro_t));
  biblioteca.numLibros = 0;
  switch(opcion) {
    case salir:
      printf("Adios!\n");
      break;
    case nuevo:
      libro = introducirLibro();
      printf("%s\n", libro.titulo);
      printf("%s\n", libro.autor);
      printf("%d\n", libro.numPag);
      break;
    case lista:
      break;
    case prestamo:
      break;
    default:
      printf("Eleccion invalida!\n");
  }
  return 0;
}

opcion_e menu() {
  int opcion=0;
  printf("Para un nuevo ejemplar pulse 1\n");
  printf("Para listar ejemplares pulse 2\n");
  printf("Para pedir un prestamo de ejemplares pulse 3\n");
  printf("Para salir pulse 0\n");
  printf("-> ");
  scanf("%d", &opcion);
  while(getchar()!='\n');
  return opcion;
}

libro_t introducirLibro() {
  int num=0;
  libro_t libro;
  printf("Introduzca el titulo: ");
  libro.titulo = leeLineaDinamica();
  printf("Introduzca el autor: ");
  libro.autor = leeLineaDinamica();
  printf("Introduzca el numero de paginas: ");
  scanf("%d", &libro.numPag);
  while(getchar()!='\n');
  return libro;
}

char *leeLineaDinamica() {
  char caracter = ' ';
  int count=0, bloques = 1, limiteBuffer=10;
  char *palabra;
  palabra = malloc(sizeof(char));

  while((caracter = getchar() != '\n')) {
    palabra[count] = caracter;
    count++;
    palabra = realloc(palabra, bloques*sizeof(char)*10);
  }
  palabra[count] = '\0';
  return palabra;
}

void guardarLibro(biblioteca_t *biblioteca) {
  biblioteca
}
