#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    FILE *fichero;

    fichero = fopen(argv[1], "a");

    fputs("Hooola lokete\n", fichero);

    fclose(fichero);

    return 0;
}
