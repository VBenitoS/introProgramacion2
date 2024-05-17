#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *leelineaDinamicaFichero(FILE *f);

int main(int argc, char *argv[]){
  FILE *f1 = fopen("stdin.txt", "r");
  FILE *f2 = fopen("stfin.txt", "w");
  char *cadena;
  int media=0;
  int num=0;
  int i=0;
  int cont=0;
  cadena = leelineaDinamicaFichero(f1);
  i = strcspn(cadena, ":");
  fprintf(f2, "Nombre: ");
  for(int j = 0; j < i; j++) {
    fprintf(f2,"%c", cadena[j]) X
  }
  fprintf(f2, "\n");
  do {
    cadena = leelineaDinamicaFichero(f1);
    i = strcspn(NULL, ":");
    num = atoi(cadena);
    cont++;
    media += num;
  }while(cadena != NULL);
  media = media / cont;
  fprintf(f2, "Media total: %d", media);
  fclose(f1);
  fclose(f2);
  return 0;
}


char *leelineaDinamicaFichero(FILE *f) {
  int tam_cadena = 0;
  char aux = '\0';
  char *ptr = NULL;
  while ((aux = fgetc(f)) != '\n' && aux != EOF)
  {
    ptr = (char*)realloc(ptr, sizeof(char) * (tam_cadena +1))
    ptr[tam_cadena++] = aux;
  }
  if (ptr != NULL) {
    ptr[tam_cadena] = '\0';
  }
  return ptr;
}
