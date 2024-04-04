
char *leeCadenaDinamica {
  int tam=0;
  char aux ='\0';
  char *ptr = NULL;

  ptr = (char*)malloc(sizeof(char));
  while((aux = getchar())!='\n') {
    ptr[tam++] = aux;
    ptr=realloc(ptr, (tam + 1)*sizeof(char));
  }
  ptr[tam] = '\0'
  return ptr;
}
