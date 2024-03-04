#include <stdio.h>
#include <stdlib.h>
#define TAM 100
enum materiales {
  plastico, madera, cristal, metal
};

typedef struct {
  int num;
  int alto;
  int ancho;
  int fondo;
  int material;
  float precio;
}mesa_t;

void introducir_mesa(mesa_t mesas[], int *numMesas);
void mostrar_mesas(mesa_t mesas[], int *numMesas);
void calcular_precio(mesa_t mesas[], int *numMesas);

int main(int argc, char *argv[]) {
  mesa_t mesas[TAM];
  int num=0, opcion;
  int *numMesas = &num;
  do {
    printf("----------------------------------------\n");
    printf("1 - Introducir caracteristicas de una nueva mesa.\n");
    printf("2 - Mostrar las mesas disponibles.\n");
    printf("3 - Calcular precio pedido.\n");
    printf("4 - Salir.\n");
    printf("----------------------------------------\n");
    printf("->  ");
    scanf("%d", &opcion);
    while(getchar() != '\n');
    switch(opcion) {
      case 1:
        introducir_mesa(mesas, numMesas);
      break;
      case 2:
        mostrar_mesas(mesas, numMesas);
      break;
      case 3:
        calcular_precio(mesas, numMesas);
      break;
      case 4:
        printf("Este programa ha terminado...\n");
      break;
      default:
        printf("Opción no válida. Por favor, seleccione nuevamente.\n");
    }
  } while(opcion != 4);
  return 0;
}

void introducir_mesa(mesa_t mesas[], int *numMesas){
  mesa_t nueva_mesa;
  printf("Introduzca alto: ");
  scanf("%d", &nueva_mesa.alto);
  printf("\nIntroduzca ancho: ");
  scanf("%d", &nueva_mesa.ancho);
  printf("\nIntroduzca fondo: ");
  scanf("%d", &nueva_mesa.fondo);
  printf("\nIntroduzca material: ");
  printf("\n 0 - plastico");
  printf("\n 1 - cristal");
  printf("\n 2 - madera");
  printf("\n 3 - metal\n");
  scanf("%d", &nueva_mesa.material);
  printf("\nIntroduzca precio: ");
  scanf("%f", &nueva_mesa.precio);
  nueva_mesa.num = *numMesas;
  mesas[*numMesas] = nueva_mesa;
  *numMesas += 1;
}
void mostrar_mesas(mesa_t mesas[], int *numMesas){
  for(int i=0; i < *numMesas; i++) {
    printf("----------------------------------------\n");
    printf("Mesa: %d\n", mesas[i].num);
    printf("Alto: %d\n", mesas[i].alto);
    printf("Ancho: %d\n", mesas[i].ancho);
    printf("Fondo: %d\n", mesas[i].fondo);
    printf("Material: ");
    if(mesas[i].material == plastico) {
      printf("plastico\n");
    } else if(mesas[i].material == cristal) {
      printf("cristal\n");
    } else if(mesas[i].material == madera) {
      printf("madera\n");
    } else if(mesas[i].material == metal) {
      printf("metal\n");
    } else {
      printf("?\n");
    }
    printf("Precio: %.2f\n", mesas[i].precio);
    printf("----------------------------------------\n");
  }
}
void calcular_precio(mesa_t mesas[], int *numMesas){
  char caracter;
  int id_mesas[5];
  int i=0;
  float precio_total=0;
  printf("Hay %d mesas\n", *numMesas);
  printf("Introduzca la lista de indices de mesas separadas por una coma sin espacios.");
  printf("\nMaximo de 5 mesas: ");
  do {
    caracter = getchar();
    if(caracter != ',') {
      id_mesas[i] = caracter - '0';
      i++;
    }
  } while(caracter != '\n');
  for(int j=0; j<i; j++) {
    precio_total += mesas[id_mesas[j]].precio;
  }
  printf("El precio final calculado es: %.2f\n", precio_total);
}
