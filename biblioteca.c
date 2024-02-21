#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Autor {
  char nombre[50];
  char apellido[50];
  char nacionalidad[50];
};

struct Libro {
  char titulo[20];
  char isbn[20];
  int num_pags;
  char editorial[20];
  struct Autor autor; //Autor del libro declarado dentro de este
};

struct Biblioteca {
  struct Libro libros[50];
  int nlibros;
};

void menu();
struct Libro introducirLibro();
struct Autor crearAutor();

int main(int argc, char *argv[]) {
  menu();
  return 0;
}

void menu() {
  int eleccion=0;
  struct Biblioteca biblio;
  biblio.nlibros = 0;
  while(eleccion!=4) {
    printf("BIENVENIDO A LA BIBLIOTECA!\n");
    printf("- Introduzca un 1 para introducir un libro\n");
    printf("- Introduzca un 2 para ver un listado de los libros\n");
    printf("- Introduzca un 3 para buscar libros por autor\n");
    printf("- Introduzca un 4 para SALIR\n");
    printf("-> ");
    scanf("%d", &eleccion);
    switch(eleccion) {
      case 1:
          biblio.libros[biblio.nlibros] = introducirLibro();
          biblio.nlibros++;
        break;
      case 2:

      break;
      case 3:

        break;
      case 4:
        printf("Adios caracola!\n");
        break;
      default:
        printf("Elección inválida\n");
    }
  }
}

struct Libro introducirLibro() {
  struct Libro nuevoLibro;
  printf("-------- Nuevo libro --------\n");
  printf("Titulo: ");
  scanf("%s", nuevoLibro.titulo);
  while(getchar() != '\n');
  printf("ISBN: ");
  scanf("%s", nuevoLibro.isbn);
  while(getchar() != '\n');
  printf("Numero de paginas: ");
  scanf("%d", &nuevoLibro.num_pags);
  while(getchar() != '\n');
  printf("Editorial: ");
  scanf("%s", nuevoLibro.editorial);
  while(getchar() != '\n');
  printf("\n");
  nuevoLibro.autor = crearAutor();
  return nuevoLibro;
}

struct Autor crearAutor() {
  struct Autor nuevoAutor;
  printf("-------- Autor --------\n");
  printf("Nombre: ");
  scanf("%s", nuevoAutor.nombre);
  while(getchar() != '\n');
  printf("Apellido: ");
  scanf("%s", nuevoAutor.apellido);
  while(getchar() != '\n');
  printf("Nacionalidad: ");
  scanf("%s", nuevoAutor.nacionalidad);
  while(getchar() != '\n');
  printf("\n");
  return nuevoAutor;
}
