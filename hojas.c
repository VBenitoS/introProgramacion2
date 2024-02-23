#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
  amarillo,verde,marron
}color_e;

typedef struct {
  int tamano;
  float grosor;
  color_e color;
}hoja;

int main(int argc, char *argv[]) {
  hoja hoja_nueva;
  hoja_nueva.tamano = 23;
  hoja_nueva.grosor = 2.3;
  hoja_nueva.color = amarillo;
  printf("- Hoja: \n");
  printf("\tTamaño: %d\n", hoja_nueva.tamano);
  printf("\tGrosor: %.2f\n", hoja_nueva.grosor);
  switch(hoja_nueva.color)  {
    case amarillo:
    printf("\tColor: amarillo\n");
    break;
    case marron:
    printf("\tColor: marron\n");
    break;
    case verde:
    printf("\tColor: verde\n");
    break;
  }
  return 0;
}
