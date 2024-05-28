#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
  lanzallamas,cuchilla,catapulta,martillo
}habilidad_e;

typedef struct {
  char* nombre;
  int nivel;
  int potencia;
  int velocidad;
  int resistencia;
  char* habilidad;
}robot_t;

typedef struct {
  robot_t *robots;
  int num;
} lista_robots_t;
char *leelineaDinamicaFichero(FILE *f);
void mostrar_robots(lista_robots_t lista);

int main(int argc, char *argv[]){
  FILE *f1 = fopen("ano.txt", "r");
  FILE *f2 = fopen("robotsEND.txt", "w+");
  char *linea;
  int comp;
  robot_t robot;
  lista_robots_t lista;
  lista.robots = (robot_t*)malloc(sizeof(robot_t));
  lista.num = 0;
  while ((linea = leelineaDinamicaFichero(f1)) != NULL) {
    robot.nombre = strtok(linea, ":");
    robot.nivel = atoi(strtok(NULL, ":"));
    robot.potencia = atoi(strtok(NULL, ":"));
    robot.velocidad = atoi(strtok(NULL, ":"));
    robot.resistencia = atoi(strtok(NULL, ":"));
    robot.habilidad = strtok(NULL, ":");
    fprintf(f2, "%s:%d:%d:%d:%d:%s\n", robot.nombre, robot.nivel, robot.potencia, robot.velocidad, robot.resistencia, robot.habilidad);
    lista.robots = (robot_t*)realloc(lista.robots, sizeof(robot_t) * (lista.num+1));
    lista.robots[lista.num] = robot;
    lista.num++;
    free(linea);
  }
  mostrar_robots(lista);
  fclose(f1);
  fclose(f2);
  return 0;
}


char *leelineaDinamicaFichero(FILE *f) {
  int tam_cadena = 0;
  char aux = '\0';
  char *ptr = NULL;
  while ((aux = fgetc(f)) != '\n' && aux != EOF)
  {
    ptr = (char*)realloc(ptr, sizeof(char) * (tam_cadena +1));
    ptr[tam_cadena++] = aux;
  }
  if (ptr != NULL) {
    ptr[tam_cadena] = '\0';
  }
  return ptr;
}

void mostrar_robots(lista_robots_t lista) {
  for(int i=0; i< lista.num; i++) {
    printf("%d - ", i);
    printf("Nombre: %s |", lista.robots[i].nombre);
    printf("Nivel: %d |", lista.robots[i].nivel);
    printf("Potencia: %d |", lista.robots[i].potencia);
    printf("Velocidad: %d |", lista.robots[i].velocidad);
    printf("Resistencia: %d |", lista.robots[i].resistencia);
    printf("Habilidad: %s\n", lista.robots[i].habilidad);
  }
}
