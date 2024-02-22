#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INT 1
#define FLOAT 2
#define CHAR 3
struct lectura_datos_t {
  int tipo;
  int i;
  float f;
  char str[4];
};
int main(int argc, char *argv[]) {
  int verif=0;
  struct lectura_datos_t usuario;
  printf("Introduzca un 1 si quiere un INT, 2 un FLOAT, 3 un CHAR\n");
  printf("valor: ");
  scanf("%d", &usuario.tipo);
  switch(usuario.tipo) {
    case INT:
      printf("Introduzca ahora el dato que desea ver: ");
      verif = scanf("%d", &usuario.i);
      if(verif==1) {
        printf("Tu dato es: %d\n", usuario.i);
      } else {
        printf("Ese tipo de dato no es correcto\n");
      }
      break;
    case FLOAT:
     printf("Introduzca ahora el dato que desea ver: ");
      verif = scanf("%f", &usuario.f);
      if(verif==1) {
        printf("Tu dato es: %.2f\n", usuario.f);
      } else {
        printf("Ese tipo de dato no es correcto\n");
      }
    break;
    case CHAR:
     printf("Introduzca ahora el dato que desea ver: ");
      verif = scanf("%s", &usuario.str);
      if(verif==1) {
        printf("Tu dato es: %s\n", usuario.str);
      } else {
        printf("Ese tipo de dato no es correcto\n");
      }
      break;
    default:
      printf("Elección inválida\n");
  }
  return 0;
}
