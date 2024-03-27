#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
    WAV,
    OGG,
    MP3
} formato_t;

typedef struct {
    char nombre[50];
    char fecha[11];
    formato_t formato;
    char estacion_asignada[50];
} archivo_t;

typedef struct {
    char nombre[50];
    char coordenadas[50];
    archivo_t **grabaciones;
    int num_grabaciones;
} estacion_t;

int main(int argc, char *argv[]) {
  int opcion;
  do {
    printf("\nMenú:\n");
    printf("1- Introducir datos de un archivo de grabación\n");
    printf("2- Introducir datos de una estación de grabación\n");
    printf("3- Asignar grabaciones a estaciones de grabación\n");
    printf("4- Mostrar datos de estaciones\n");
    printf("5- Salir\n");
    printf("Seleccione una opción: ");
    scanf("%d", &opcion);
    while(getchar()!='\n');
  }while(opcion!=0);
  return 0;
}
