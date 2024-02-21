#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Alumno {
  char nombre[50];
  char apellido[50];
  int edad;
  float altura;
};

int main(int argc, char *argv[]) {
  struct Alumno santiago;
  struct Alumno alumnos[3];
  strcpy(santiago.nombre, "Santiago");;
  strcpy(santiago.apellido, "Carlos");
  santiago.edad = 24;
  santiago.altura = 1.77;
  printf("Informacion: \n");
  printf("\tNombre: %s\n", santiago.nombre);
  printf("\tApellido: %s\n", santiago.apellido);
  printf("\tEdad: %d\n", santiago.edad);
  printf("\tAltura: %.2f\n", santiago.altura);
  return 0;
}
