#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct usuario_t {
  char nombre[10];
  char apellido[10];
  char DNI[9];
  int edad;
  float peso;
  char telefono[9];

};
void ImprimeUsuario( struct usuario_t usuario);
void buscarJovenes( struct usuario_t usuarios[], struct usuario_t jovenes[]);

int main(int argc, char *argv[]) {
  struct usuario_t usuarios[5];
  struct usuario_t jovenes[3];
  for(int i=0; i < 5; i++) {
    printf("Nombre: ");
    scanf("%s", usuarios[i].nombre);
    while(getchar() != '\n');
    printf("Apellido: ");
    scanf("%s", usuarios[i].apellido);
    while(getchar() != '\n');
    printf("DNI: ");
    scanf("%s", usuarios[i].DNI);
    while(getchar() != '\n');
    printf("Edad: ");
    scanf("%d", &usuarios[i].edad);
    while(getchar() != '\n');
    printf("Peso: ");
    scanf("%f", &usuarios[i].peso);
    while(getchar() != '\n');
    printf("Telefono: ");
    scanf("%s", usuarios[i].telefono);
    while(getchar() != '\n');
  }
  buscarJovenes(usuarios, jovenes);
  printf("\nMenores de 18: \n");
  for(int i=0; i<3; i++) {
    ImprimeUsuario(jovenes[i]);
  }
  return 0;
}
void ImprimeUsuario( struct usuario_t usuario) {
  printf("------------------------\n");
  printf("Nombre: %s\n", usuario.nombre);
  printf("Edad: %d\n", usuario.edad);
  printf("------------------------\n");
}

void buscarJovenes( struct usuario_t usuarios[], struct usuario_t jovenes[]) {
  int edad=0;
  struct usuario_t usu;
  for (int i = 0; i < 5 - 1; i++) {
    for (int j = 0; j < 5 - i - 1; j++) {
      if (usuarios[j].edad > usuarios[j + 1].edad) {
          usu = usuarios[j];
          usuarios[j] = usuarios[j + 1];
          usuarios[j + 1] = usu;
      }
    }
  }
  for(int i=0; i<3; i++) {
    jovenes[i] = usuarios[i];
  }
}
