#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char * palabra;
    int num_ocurrencias;
    int * num_lineas;
} palabraInfo_t;

typedef struct {
    palabraInfo_t * info;
    int num;
} listaPalabras_t;

typedef struct {
    int num;
    char ** lineas;
} lineas_t;

char * leelineaDinamicaFile(FILE * fichero);
void examinaLinea(char * lineaAux, int numLinea, listaPalabras_t * listaPalabras);
void escribirResultado(listaPalabras_t lista, char *nombre);
int contarLineas(FILE * fichero);

int main(int argc, char *argv[]) {
    FILE * fO = fopen(argv[1], "r");
    int busquedas = argc - 2;
    lineas_t lineas;
    listaPalabras_t listaPalabras;
    listaPalabras.num = busquedas;
    lineas.num = 0;
    lineas.num = contarLineas(fO);
    lineas.lineas = (char **)malloc(sizeof(char *) * lineas.num);
    listaPalabras.info = malloc(sizeof(palabraInfo_t) * listaPalabras.num);
    for (int i = 0; i < listaPalabras.num; i++){
        listaPalabras.info[i].num_lineas = malloc(sizeof(int));
        listaPalabras.info[i].num_lineas[0] = 0;
        listaPalabras.info[i].num_ocurrencias = 0;
    }
    rewind(fO);
    for (int i = 0; i < lineas.num; i++) {
        lineas.lineas[i] = leelineaDinamicaFile(fO);
    }
    for (int i = 0; i < listaPalabras.num; i++) {
        int longitud = strlen(argv[i + 2]);
        listaPalabras.info[i].palabra = malloc(sizeof(char) * (longitud + 1));
        strcpy(listaPalabras.info[i].palabra, argv[i + 2]);
    }
    for (int i = 0; i < lineas.num; i++) {
        examinaLinea(lineas.lineas[i], i, &listaPalabras);
    }
    escribirResultado(listaPalabras, argv[1]);
    for (int i = 0; i < lineas.num; i++) {
        free(lineas.lineas[i]);
    }
    free(lineas.lineas);

    for (int i = 0; i < listaPalabras.num; i++) {
        free(listaPalabras.info[i].palabra);
        free(listaPalabras.info[i].num_lineas);
    }
    free(listaPalabras.info);

    fclose(fO);

    return 0;
}

int contarLineas(FILE * fichero) {
    char caracter;
    int count = 0;
    while ((caracter = fgetc(fichero)) != EOF) {
        if (caracter == '\n') {
            count++;
        }
    }
    return count;
}

char *leelineaDinamicaFile(FILE * fichero) {
    char *palabra = NULL;
    char caracter;
    int count = 0;

    while ((caracter = fgetc(fichero)) != EOF && caracter != '\n') {
        palabra = realloc(palabra, sizeof(char) * (count + 1));
        palabra[count++] = caracter;
    }
    if (count > 0) {
        palabra = realloc(palabra, sizeof(char) * (count + 1));
        palabra[count] = '\0';
    }
    return palabra;
}

void examinaLinea(char * lineaAux, int numLinea, listaPalabras_t * listaPalabras) {
    char * aux = NULL;
    int k = 0;
    int a = 0;
    for (int i = 0; i < listaPalabras->num; i++) {
        for (int j = 0; lineaAux[j] != '\0'; j++) {
            if (lineaAux[j] != ' ') {
                aux = realloc(aux, sizeof(char) * (k + 1));
                aux[k++] = lineaAux[j];
            } else {
                aux = realloc(aux, sizeof(char) * (k + 1));
                aux[k] = '\0';
                k = 0;
                if (strcmp(aux, listaPalabras->info[i].palabra) == 0) {
                    listaPalabras->info[i].num_ocurrencias++;
                    int a = listaPalabras->info[i].num_ocurrencias;
                    listaPalabras->info[i].num_lineas = (int *)realloc(listaPalabras->info[i].num_lineas, sizeof(int) * a);
                    listaPalabras->info[i].num_lineas[a - 1] = numLinea + 1;
                }
                free(aux);
                aux = NULL;
            }
        }
    }
}

void escribirResultado(listaPalabras_t lista, char *nombre) {
    nombre = strtok(nombre, ".");
    char nombreDestino[strlen(nombre) + 5];
    strcpy(nombreDestino, nombre);
    strcat(nombreDestino, ".out.txt");
    FILE *f1 = fopen(nombreDestino, "w");
    for (int i = 0; i < lista.num; i++) {
        if (lista.info[i].num_ocurrencias > 0){
            fprintf(f1, "%s. Numero de ocurrencias: %d. Numero de lineas : ", lista.info[i].palabra, lista.info[i].num_ocurrencias);
            for (int j = 0; j < lista.info[i].num_ocurrencias; j++) {
                fprintf(f1, "%d\t", lista.info[i].num_lineas[j]);
            }
            fprintf(f1, "\n");
        }
    }
    fclose(f1);
}
