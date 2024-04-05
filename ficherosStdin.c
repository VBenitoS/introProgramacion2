#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  FILE *f;
  int numero;
  f = fopen("stdin.txt", "a");
  fscanf(stdin, "%d", &numero);
  fprintf(stdout, "Salida normal\n"); //Si ponemos > va a guardar esto en el fichero e imprimir lo siguiente por pantalla
  fprintf(stderr, "Salida error\n"); //Salida de error si ponemos 2> imprime esto por fichero
  fclose(f);
  return 0;
}
