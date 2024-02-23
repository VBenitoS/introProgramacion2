#include <stdio.h>
#include <stdlib.h>
#include <string.h>

union bswap32 {
  int data;
  char bytes[4];
};
typedef struct {
  int data;
  char bytes[4];
}bswap;

int main(int argc, char *argv[]) {
  union bswap32 datos;
  bswap datosStruct;
  datosStruct.data = 1;
  datos.data = 1;
  if(datos.bytes[0] == 1) {
    printf("LittleEndian\n");
  } else {
    printf("BigEndian\n");
  }
  if(datosStruct.bytes[0] == 1) {
    printf("LittleEndian\n");
  } else {
    printf("BigEndian\n");
  }
  return 0;
}
