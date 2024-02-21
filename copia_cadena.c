#include <stdio.h>
#include <stdlib.h>
void copiarArray(char copia[], char array[]);
int main() {
  char derecho[] = "Holacomoestoy";
  char reves[30]={'\0'};

  copiarArray(reves, derecho);
  printf("La derecho: %s\n", derecho);
  printf("La copia: %s\n", reves);
  return 0;
}

void copiarArray(char copia[], char array[]) {
  char *copia1, *copia2;
  copia1 = array;
  copia2 = copia;
  int i=0;
  int j=0;
  while(*copia1++); //si es true se ejecuta si es false no, cuando el puntero apunte a algo
  copia1 -= 2;
  while(copia1 != array) {
    *copia2++ = *copia1--;
  }
  *copia2++ = *copia1;
  *copia2 = '\0';
}
