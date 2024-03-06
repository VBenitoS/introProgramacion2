#include <stdio.h>
#include <stdlib.h>

typedef struct{
  char jugador1[10];
  char jugador2[10];
  int partidos_ganados;
  int sets_ganados;
  int sets_perdidos;
}pareja_t;

typedef struct{
  pareja_t *pareja1;
  pareja_t *pareja2;
  int sets_pareja1;
  int sets_pareja2;
}partido_t;

typedef struct{
  int num;
  partido_t partido1;
  partido_t partido2;
}jornada_t;

jornada_t introducirResultado();
void mostrarResultados(jornada_t jornadas[]);
void mostrarGanador(pareja_t parejas[]);

int main(int argc, char *argv[]) {
  int opcion, num_jornadas=0, cont=0, j=0;
  jornada_t jornadas[20];
  pareja_t parejas[4];
  for(int i=1; j < 4 && i < argc; i+=2, j++) {
    for(int k=0; k < 10 && argv[i-1][k] != '\0'; k++) {
      parejas[j].jugador1[k] = argv[i-1][k];
    }
    for(int k=0; k < 10 && argv[i][k] != '\0'; k++) {
      parejas[j].jugador2[k] = argv[i][k];
    }
    parejas[j].partidos_ganados = 0;
    parejas[j].sets_ganados = 0;
    parejas[j].sets_perdidos = 0;
  }
  for(int i=1; i < (argc/2) - 1; i++) {
    printf("----------------------------------------\n");
    printf("Pareja: \n");
    printf("%s--%s\n", parejas[i-1].jugador1, parejas[i-1].jugador2);
    printf("P.Ganados: %d S.ganados: %d  S.perdidos: %d", parejas[i-1].partidos_ganados, parejas[j].sets_ganados, parejas[j].sets_perdidos);
    printf("----------------------------------------\n");
  }
  do {
    printf("----------------------------------------\n");
    printf("1 - Introducir resultados.\n");
    printf("2 - Mostrar resultados.\n");
    printf("3 - Mostrar ganador.\n");
    printf("0 - Salir.\n");
    printf("----------------------------------------\n");
    printf("->  ");
    scanf("%d", &opcion);
    while(getchar() != '\n');
    switch(opcion) {
      case 1:
        jornadas[num_jornadas] = introducirResultado();
      break;
      case 2:
      break;
      case 3:
      break;
      case 0:
        printf("Este programa ha terminado...\n");
      break;
      default:
        printf("Opción no válida. Por favor, seleccione nuevamente.\n");
    }
  } while(opcion != 0);
  return 0;
}

jornada_t introducirResultado(){

}
void mostrarResultados(jornada_t jornadas[]){

}
void mostrarGanador(pareja_t parejas[]){

}
