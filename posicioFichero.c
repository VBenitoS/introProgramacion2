#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    FILE *f = fopen(argv[1], "r");
    FILE *f2;
    fseek(f, 0, SEEK_END);
    long tam = ftell(f);
    char *contenidoFichero;
    printf("El tamaño del archivo %s es: %ld bytes\n", argv[1], tam);
    rewind(f);
    contenidoFichero = (char *) malloc(tam + 1);
    fread(contenidoFichero, 1, tam, f);
    contenidoFichero[tam] = '\0';
    f2 = fopen(argv[2], "wb");
    fprintf(f2, "%s", contenidoFichero);
    fclose(f);
    fclose(f2);
    return 0;
}
