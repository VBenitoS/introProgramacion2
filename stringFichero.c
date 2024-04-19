#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  char *palabra1 = argv[1];
  char *palabra2 = argv[2];
  int comp=0;
  fprintf(stdout,"La extension del fichero es %s\n",strchr(argv[1], '.'));
  // fprintf(stdout,"El nombre del fichero es %s\n", strtok(argv[1], "."));
  comp = strcmp(palabra1, palabra2);
  if(comp == 0){
      printf("Las cadenas son iguales\n");
  }else if(comp < 0){
      printf("La primera cadena es mas grande que la segunda\n");
      printf("%s - %s\n", palabra1, palabra2);
  }else if(comp > 0){
      printf("La segunda cadena es mas grande que la primera\n");
      printf("%s - %s\n", palabra2, palabra1);
  }
  return 0;
}
