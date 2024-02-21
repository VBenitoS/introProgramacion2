#include <stdlib.h>
#include <stdio.h>
#define TAM 8
void comprobarDni(long int cadena);

int main(int argc, char *argv[]) {
  long int dni = strtol(argv[1],NULL,10);
  comprobarDni(dni);
  return 0;
}

void comprobarDni(long int cadena) {
  int suma=0, cont=0, resto=0, encontrado=0;
  char letra;
  char arrayLetras[] = "TRWAGMYFPDXBNJZSQVHLCKE";
  resto = cadena % 23;
  printf("%ld%c\n", cadena, arrayLetras[resto]);
}
