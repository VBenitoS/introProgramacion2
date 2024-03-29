#include <stdio.h>
#include <stdlib.h>

typedef enum
{
  SALIR,
  NUEVO,
  LISTAR,
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
void listarLibro(t_libro *libro);
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
  int tam_buffer = TAM_BLOQUE;

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
  ptrBiblio->libros = realloc(ptrBiblio->libros, sizeof(t_libro) * ptrBiblio->numLibros);
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
  int error = 0;
  char *ptr = NULL;
  char *ptrAux = NULL;

  ptr = (char *)malloc(sizeof(char)); //NO HACE FALTA PORQUE EN LA PRIMERA INTERACCION DEL REALLOC EL PTR FUNCIONA COMO NULL Y ESTE ACTUA COMO MALLOC
  while ((aux = getchar()) != '\n')
  {
    ptr[tam_cadena++] = aux;
    ptr = realloc(ptr, tam_cadena);

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
  printf("Para pedir un prestamo pulse %d \n", PRESTAMO);
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
    listarLibro(&(biblio->libros[i]));
  }
}

void listarLibro(t_libro *libro)
{
  printf("------------------------------\n");
  printf("Titulo: %s\n", libro->titulo);
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

void prestamo(t_biblio *biblio)
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
    listarLibro(&(biblio->libros[contador - 1]));
  }
}
