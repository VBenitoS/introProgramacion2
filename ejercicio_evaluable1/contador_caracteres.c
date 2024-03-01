#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 11

void introducirNuevaFrase(char frase[], char arrayCaracteres[], int arrayContador[], int tam);
void mostrarResultado(char caracteres[], int contador[], int tam);
int main(int argc, char *argv[]) {
  int opcion;
  if( argc < TAM) { //determinamos que solo sea un maximo de 10 caracteres
    char arrayCaracteres[argc-1];
    int arrayContador[argc-1];
    char frase[40];
    int index=0;
    for(int i=1; i < argc; i++) {
      for(int j = 0; argv[i][j] != '\0'; j++) { //guardo los caracteres a contar en un array
        arrayCaracteres[index] = argv[i][j];
        arrayContador[index] = 0;
        index++;
      }
    }
    printf("\n");
    do {
      printf("----------------------------------------\n");
      printf("Para introducir una frase nueva pulse 1\n");
      printf("Para mostrar el resultado pulse 2\n");
      printf("Para salir pulse 0\n");
      printf("----------------------------------------\n");
      printf("->  ");
      scanf("%d", &opcion);
      while(getchar() != '\n');
      switch (opcion) {
                case 0:
                    printf("Este programa ha terminado...\n");
                    break;
                case 1:
                    introducirNuevaFrase(frase, arrayCaracteres, arrayContador, argc-1);
                    break;
                case 2:
                    mostrarResultado(arrayCaracteres, arrayContador, argc-1);
                    break;
                default:
                    printf("Opción no válida. Por favor, seleccione nuevamente.\n");
        }
    } while (opcion != 0);
    return 0;
  }
}

void introducirNuevaFrase(char frase[], char arrayCaracteres[], int arrayContador[], int tam) {
  int i=0;
  char caracter;
  printf("Introduzca el texto: \n");
  do {
    caracter = getchar();
    frase[i] = caracter;
    i++;
  } while(caracter != '\n' && i < 40);

  for(int k=0; k < tam; k++) {
    for(int j=0; j < i ; j++) {
      if(frase[j] == arrayCaracteres[k]) {
        arrayContador[k]++;
      }
    }
  }
}

void mostrarResultado(char caracteres[], int contador[], int tam) {
  for(int i=0; i < tam; i++) {
    printf("\t%c -> %d\n", caracteres[i], contador[i]);
  }
}
