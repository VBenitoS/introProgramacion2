#include <stdlib.h>
#include <stdio.h>

void main(int argc, char *argv[]) {

  float sumatorio = 0;
  int mediaLimit = argc - 1; // -1 se debe a que hay un argumento que es la direccion en donde esta la app

  for (int i = 1; i < argc; i++) {
    long int valor = strtol(argv[i], NULL,  10); //para ver si lo puedo pasar a entero
    printf("%ld\n", valor);

    if (valor == 0) {
        if (*argv[i] != '0') mediaLimit--;
      }
      else {
            sumatorio += valor;
      }
  }
  printf("Total: %.0f\nMedia: %.2f\nMedia Limit: %d\n", sumatorio, sumatorio/ mediaLimit, mediaLimit);
}
