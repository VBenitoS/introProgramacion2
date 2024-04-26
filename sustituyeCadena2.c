#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Sustituyendo una palabra de la cadena por otra, sin importar el tamaño de esta
int main(int argc, char *argv[]) {
  char *cadena = argv[1];
  char *palabra1 = strstr(cadena, argv[2]);
  char *palabra2 = argv[3];
  char *resultado;
  long diferencia;
  diferencia = strlen(cadena) - strlen(palabra1) + strlen(palabra2);
  resultado = (char *) malloc(sizeof(char) * (diferencia + 1));
  strncpy(resultado, cadena, palabra1 - cadena); //Copia la cadena hasta la palabra elegida
  resultado[palabra1 - cadena] = '\0';
  strcat(resultado, palabra2); //Concatena con la palabra a sustituir al final
  strcat(resultado, palabra1 + strlen(argv[2])); //añadimos el resto de la frase moviendo el puntero a despues de la palabra elegida
  printf("%s\n", resultado);
  return 0;
}
