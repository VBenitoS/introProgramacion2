#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *leeFichero(FILE *f);

int main(int argc, char *argv[]){
	FILE* f0 = fopen(argv[1],"r");
	FILE* f1 = fopen(argv[2],"w+");
	int num_caracteres = atoi(argv[3]);
	char* cadena = NULL;
	char caracter = 1;
  int espacio=0;
	cadena = leeFichero(f0);
	for(int i = 0; (caracter = cadena[i]) != '\0'; i++){
		if(((i % num_caracteres) == 0 && i != 0)){
			fputs("-\n", f1);
		}
		if(caracter != '\n'){
			fputc(caracter, f1);
		}

	}
	free(cadena);
	fclose(f0);
	fclose(f1);
	return 0;
}

char *leeFichero(FILE *f){
	int i = 0;
	char *ptr = NULL;
	char caracter;
	ptr = malloc(sizeof(char));
	while((caracter = fgetc(f)) != EOF){
		ptr[i++] = caracter;
		ptr = realloc(ptr, sizeof(char) * (i+1));
	}
	ptr[i] = '\0';
	return ptr;

}
