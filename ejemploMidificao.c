#include <stdio.h>
#include <stdlib.h>

typedef enum
{
  SALIR,
  NUEVO,
  LISTAR,
  BUSCAR,
  PRESTAMO,
  INVALIDA
} t_menu;

typedef struct
{
  char *titulo;
  char *autor;
  int numPag;
} t_libro;

typedef struct
{
  int numLibros;
  t_libro *libros;
} t_biblio;

char *leeCadenaDinamica();
t_libro crearLibro();
void newLibro(t_biblio *ptrBiblio);
void listarBiblio(t_biblio *ptrBiblio);
void listarLibro(t_libro libro);
void buscar(t_biblio *biblio);
void prestamo(t_biblio *biblio);
int esMismaCadena(char *cadena1, char *cadena2);
t_menu menu();
void liberar(t_biblio *biblio);

int main(int argc, char *argv[])
{
  t_biblio biblio;
  int opcion = INVALIDA;
  biblio.numLibros = 0;
  biblio.libros = NULL;

  do
  {
    opcion = menu();

    switch (opcion)
    {
    case NUEVO:
      newLibro(&biblio);
      break;
    case LISTAR:
      listarBiblio(&biblio);
      break;
    case BUSCAR:
      buscar(&biblio);
      break;
    case PRESTAMO:
      prestamo(&biblio);
      break;
    case SALIR:
      liberar(&biblio);
      break;
    default:
      printf("Opcion incorrecta\n");
    }
  } while (opcion != SALIR);

  return 0;
}

void newLibro(t_biblio *ptrBiblio)
{
  ptrBiblio->numLibros++;
  ptrBiblio->libros = (t_libro *)realloc(ptrBiblio->libros, sizeof(t_libro) * ptrBiblio->numLibros);
  ptrBiblio->libros[ptrBiblio->numLibros - 1] = crearLibro();
}

t_libro crearLibro()
{
  t_libro libro;
  printf("Introduce el autor: ");
  libro.autor = leeCadenaDinamica();
  printf("Introduce el titulo: ");
  libro.titulo = leeCadenaDinamica();
  printf("Itroduce el numero de paginas: ");
  scanf("%d", &(libro.numPag));
  while (getchar() != '\n')
    ;
  return libro;
}

char *leeCadenaDinamica()
{
  int tam_cadena = 0;
  char aux = '\0';
  char *ptr = NULL;


  ptr = (char*)malloc(sizeof(char));
  while ((aux = getchar()) != '\n')
  {
    ptr[tam_cadena++] = aux;
    ptr = realloc(ptr, tam_cadena + 1);

  }
  ptr[tam_cadena] = '\0';
  return ptr;
}

t_menu menu()
{
  t_menu opcion;
  printf("--------------------------------------\n");
  printf("Para introducir un libro pulse %d \n", NUEVO);
  printf("Para listar los libros pulse %d \n", LISTAR);
  printf("Para buscar un libro pulse %d \n", BUSCAR);
  printf("Para retirar un libro en prestamo pulse %d \n", PRESTAMO);
  printf("Para salir pulse %d\n", SALIR);
  printf("--------------------------------------\n");
  scanf("%d", &opcion);
  while (getchar() != '\n')
    ;
  return opcion;
}

void listarBiblio(t_biblio *biblio)
{
  for (int i = 0; i < biblio->numLibros; i++)
  {
    listarLibro((biblio->libros[i]));
  }
}

void listarLibro(t_libro libro)
{
  printf("------------------------------\n");
  printf("Titulo: %s\n", libro.titulo);
  printf("Autor: %s\n", libro.autor);
  printf("Numero de paginas: %d\n", libro.numPag);
}

void liberar(t_biblio *biblio)
{
  t_libro *ptrAux;
  for (int i = 0; i < biblio->numLibros; i++)
  {
    ptrAux = &(biblio->libros[i]);
    free(ptrAux->autor);
    free(ptrAux->titulo);
  }
  free (biblio->libros);
}

int esMismaCadena(char *cadena1, char *cadena2)
{
  while (*cadena1 && *cadena2 && *cadena1 == *cadena2)
  {
    cadena1++;
    cadena2++;
  }
  return (*cadena2 == *cadena1);
}

void buscar(t_biblio *biblio)
{
  char *titulo;
  int encontrado = 0;
  int contador = 0;

  printf("Introduce el titulo del libro:");
  titulo = leeCadenaDinamica();

  while (!encontrado && contador < biblio->numLibros)
  {
    encontrado = esMismaCadena(titulo, biblio->libros[contador].titulo);
    contador++;
  }

  free(titulo);

  if (encontrado)
  {
    printf("Encontrado en la posicion: %d", contador -1);
    listarLibro((biblio->libros[contador - 1]));
  }
}

void prestamo (t_biblio *biblio) {
  t_libro * ptrAux;
  int indice = 0;
  int i = 0;
  ptrAux = (t_libro *) malloc(sizeof(t_libro)* (biblio->numLibros -1));

  printf("Indice del libro: ");
  scanf ("%d", &indice);
  while(getchar()!='\n');
  for (i = 0; i < indice; i++) {
    ptrAux[i] = biblio->libros[i];
  }

  for (i = indice +1; i < biblio->numLibros; i++) {
    ptrAux[i -1] = biblio->libros[i];
  }

  biblio->numLibros--;
  free (biblio->libros);
  biblio->libros = ptrAux;
}
