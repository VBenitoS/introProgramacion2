#include <stdlib.h>
#include <stdio.h>
#define TAM 3

int main(int argc, char *argv[]) {
  float matriz[TAM][TAM];
  float valor;
  int cont=1; //empezamos en 1 porque 0 es el nombre del fichero
  // matriz = argv;
  for(int i=0; i< TAM; i++) {
     for(int j=0; j< TAM; j++) {
      valor = strtof(argv[cont], NULL);
      printf("%.2f ", valor);
      cont++;
     }
     printf("\n");
  }
  return 0;
}
