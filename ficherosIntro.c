#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  FILE *f, *f1, *f2, *f3, *f4, *f5; //r es una especie de permiso
  f = fopen("ejemplo.txt","r"); //FILE *fopen (char *nombre_archivo, char *modo);
  if(f==NULL) {
    printf("ERROR CHIN CHON\n");
  } else {
    printf("EL archivo existe\n");
  }
  f1 = fopen("ejemploW.txt","w");
  f2 = fopen("ejemploA.txt","a"); //añadir al final
  f3 = fopen("ejemploR2.txt","r+");
  f4 = fopen("ejemploW2.txt","w+");
  f5 = fopen("ejemploA2.txt","a+");
  if(f1==NULL) {
    printf("ERROR CHIN CHON W\n");
  } else {
    printf("EL archivo existe W\n");
  }
  if(f2==NULL) {
    printf("ERROR CHIN CHON A\n");
  } else {
    printf("EL archivo existe A\n");
  }
  if(f3==NULL) {
    printf("ERROR CHIN CHON R+ \n"); //leer y escribir pero desde donde esta el fichero
  } else {
    printf("EL archivo existe R+\n");
  }
  if(f4==NULL) {
    printf("ERROR CHIN CHON W+\n"); //Crea archivo para escribir/leer
  } else {
    printf("EL archivo existe W+\n");
  }
  if(f5==NULL) {
    printf("ERROR CHIN CHON A+\n");
  } else {
    printf("EL archivo existe A+\n");
  }
  return 0;
}
