#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef long long int int64;
typedef int int32;
typedef short int16;
typedef char byte;

typedef struct{
  int64 numeroHojas;
  int32 numeroRamas;
  int16 numeroDulces;
  byte numeroArbol[10];
}arbol_t;

arbol_t crearArbol(arbol_t arbol);
void mostrarArbol(arbol_t arbol);

int main(int argc, char *argv[]) {
  arbol_t arbol;
  crearArbol(arbol);
  mostrarArbol(arbol);
  return 0;
}

arbol_t crearArbol(arbol_t arbol) {
  printf("- Introduce los valores del arbol\n");
  printf("\tNumero de hojas: ");
  scanf("%lld", &arbol.numeroHojas);
  printf("\tNumero de ramas: ");
  scanf("%d", &arbol.numeroRamas);
  printf("\tNumero de dulces: ");
  scanf("%hd", &arbol.numeroDulces);
  printf("\tCodigo del arbol: ");
  scanf("%s", &arbol.numeroArbol);
  return arbol;
}

void mostrarArbol(arbol_t arbol) {
  printf("El arbol es: \n");
  printf("\tHojas: %lld\n", arbol.numeroHojas);
  printf("\tRamas: %d\n", arbol.numeroRamas);
  printf("\tDulces: %hd\n", arbol.numeroDulces);
  printf("\tCodigo: %s\n", arbol.numeroArbol);
}
