#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define INCOGNITA '?'
#define AGUA 'O'

typedef struct {
  int fila;
  int columna;
  int acierto;
}intento_t;

typedef struct {
  int fila;
  int columna;
}coordenadas_t;

typedef struct {
  intento_t *intentos;
  int num;
}listaIntentos_t;
char **crearMatriz(int numFilasColumnas);
void rellenaMatriz(char** matriz, int tam, char valor);
void presentarMatriz(char **matriz, int tam, int fin, coordenadas_t bomba);
intento_t pedirIntento();
coordenadas_t generarBomba(int numFilasColumnas);
int presentarMenu();
void testeaIntento(char** matriz, intento_t* nuevoIntento, coordenadas_t coordenadasBomba);
void insertaIntentoEnLista(listaIntentos_t* intentos, intento_t nuevoIntento);
void visualizarIntentos(listaIntentos_t* intentos, coordenadas_t coordenadasBomba);

int main(int argc, char *argv[]) {
  int tamFilasColumnas = atoi(argv[1]);
  char **matriz = crearMatriz(tamFilasColumnas);
  intento_t intento;
  listaIntentos_t totalIntentos;
  totalIntentos.num = 0;
  coordenadas_t bomba = generarBomba(tamFilasColumnas);
  int opcion = 0;
  printf("Coordenadas de la bomba: fila: %d columna: %d\n", bomba.fila, bomba.columna);
  rellenaMatriz(matriz, tamFilasColumnas, INCOGNITA);
  totalIntentos.intentos = (intento_t *)malloc(sizeof(intento_t));
  do {
    opcion = presentarMenu();
    switch (opcion) {
      case 0:
      break;
      case 1:
        intento = pedirIntento();
        testeaIntento(matriz, &intento, bomba);
        if(intento.acierto == 0) {
          insertaIntentoEnLista(&totalIntentos, intento);
        }
      break;
      case 2:
        visualizarIntentos(&totalIntentos, bomba);
      break;
      case 3:
        presentarMatriz(matriz, tamFilasColumnas, 0, bomba);
      break;
      default:
        printf("ERROR\n");
    }
  }while(opcion != 0 && intento.acierto == 0);
  presentarMatriz(matriz, tamFilasColumnas, 1, bomba);
  for (int i = 0; i < tamFilasColumnas; i++) {
    free(matriz[i]);
  }
  free(matriz);
  if (totalIntentos.intentos != NULL) {
    free(totalIntentos.intentos);
  }
  return 0;
}

char **crearMatriz(int numFilasColumnas) {
  char **ptr = NULL;
  ptr = (char**)malloc(numFilasColumnas * sizeof(char*));
  for(int i=0; i< numFilasColumnas; i++) {
    ptr[i] = (char*)malloc(numFilasColumnas * sizeof(char));
  }
  return ptr;
}
void rellenaMatriz(char** matriz, int tam, char valor) {
  for(int i=0; i < tam; i++) {
    for(int j=0; j < tam; j++) {
      matriz[i][j] = valor;
    }
  }
}

void presentarMatriz(char **matriz, int tam, int fin, coordenadas_t bomba) {
  printf("\n");
  for(int i=0; i < tam; i++) {
    printf("\t");
    for(int j=0; j < tam; j++) {
      if(fin == 1 && bomba.fila == i && bomba.columna == j) {
        matriz[i][j] = 'X';
      }
      printf("%c ", matriz[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

intento_t pedirIntento() {
  intento_t intento;
  printf("Introduce fila y columna: ");
  scanf("%d %d", &intento.fila, &intento.columna);
  while(getchar()!='\n');
  intento.acierto = 0;
  return intento;
}

coordenadas_t generarBomba(int numFilasColumnas) {
  coordenadas_t bomba;
  srand(time(NULL));
  bomba.fila = rand() % numFilasColumnas;
  bomba.columna = rand() % numFilasColumnas;
  return bomba;
}

int presentarMenu() {
  int opcion=0;
  printf("***************************************\n");
  printf("Introduzca una opcion\n");
  printf("Para buscar pulse 1\n");
  printf("Para visualizar los intentos pulse 2\n");
  printf("Para ver la matriz pulse 3\n");
  printf("Para salir pulse 0\n");
  printf("***************************************\n");
  printf("-> ");
  scanf("%d", &opcion);
  while(getchar()!='\n');
  return opcion;
}

void testeaIntento(char** matriz, intento_t* nuevoIntento, coordenadas_t coordenadasBomba) {
  int fila = nuevoIntento->fila, columna = nuevoIntento->columna;
  if(nuevoIntento->fila == coordenadasBomba.fila && nuevoIntento->columna == coordenadasBomba.columna) {
    nuevoIntento->acierto = 1;
    printf("\n*******************BOMBA ENCONTRADA*******************\n");
  } else {
    matriz[fila][columna] = 'O';
  }
}

void insertaIntentoEnLista(listaIntentos_t* intentos, intento_t nuevoIntento) {
  intentos->intentos = realloc(intentos->intentos, (intentos->num + 1) * sizeof(intento_t));
  intentos->intentos[intentos->num] = nuevoIntento;
  intentos->num++;
}

void visualizarIntentos(listaIntentos_t* intentos, coordenadas_t coordenadasBomba) {
  printf("\n--------------------------------");
  for(int i=0; i< intentos->num; i++) {
    printf("\n Intento %d: \n", i);
    printf("[%d][%d]", intentos->intentos[i].fila, intentos->intentos[i].columna);
    if(intentos->intentos[i].fila == coordenadasBomba.fila) {
      printf("...en esa fila\n");
    } else if (intentos->intentos[i].columna == coordenadasBomba.columna){
      printf("...en esa columna\n");
    } else {
      printf("\n");
    }
  }
  printf("--------------------------------");
  printf("\n");
}
