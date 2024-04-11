#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  FILE *f;
  f= fopen(argv[1], "r+"); //nombre del archivo
  if(f == NULL || argc !=4) {
    fprintf(stderr, "parametros incorrectos\n");
    return 1;
  }
  char aux;
  char orig = argv[2][0]; // caracter a cambiar
  char change = argv[3][0]; // caracter cambiado

  while (!feof(f)) { //end of file
    aux = fgetc(f);
    if(aux == orig) {
      fseek(f, -1, SEEK_CUR); //cambia el caracter por otro, si quiero añadir luego sera un 0
      fputc(change, f);
    }
  }
  return 0;
}
