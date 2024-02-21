#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Persona {
  char nombre[50];
  int edad;
  float altura;
};

int main(int argc, char *argv[]) {
  struct Persona persona1;
  strcpy(persona1.nombre, "Carlos");
  persona1.edad = 24;
  persona1.altura = 1.77;

  printf("Informacion: \n");
  printf("\tNombre: %s\n\tEdad: %d\n\tAltura: %0.2f\n", persona1.nombre,persona1.edad,persona1.altura);
}
