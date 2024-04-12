#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int num1, num2, num3;
  char c;
  printf("Escribe 3 nuemros\n");
  scanf("%d", &num1);
  scanf("%d", &num2);
  scanf("%d", &num3);
  printf("%d%d%d", num1, num2, num3);
  while(getchar()!='\n');
  scanf("%c", &c);
  return 0;
}
