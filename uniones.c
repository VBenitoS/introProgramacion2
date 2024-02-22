#include <stdio.h>
#include <stdlib.h>
#include <string.h>

union datos_u {
  int edad;
  float peso;
  char nombre[10];
};
struct datos_t {
  int edad;
  float peso;
  char nombre[10];
};

int main(int argc, char *argv[]) {
  struct datos_t dato1;
  union datos_u dato2;
  dato1.edad = 21;
  dato1.peso = 67;
  strcpy(dato1.nombre, "Carlos");
  dato2.edad = 27;
  dato2.peso = 73;
  strcpy(dato2.nombre, "Julian");
  printf("Dato 1: \n");
  printf("\tEdad: %d\n\tPeso: %.2f\n\tNombre: %s\n", dato1.edad, dato1.peso, dato1.nombre);
  printf("Dato 2: \n");
  printf("\tEdad: %d\n\tPeso: %.2f\n\tNombre: %s\n", dato2.edad, dato2.peso, dato2.nombre);
  return 0;
}
