#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int numero;
  nodo_t *siguiente;
} nodo_t;

typedef enum {
  SALIR,
  NUEVO,
  LISTAR,
  SACAR,
  CONTAR
} menu_e;

int menu();
void listarNodo(nodo_t *pila);
void nuevoNodo(nodo_t ** pila);

int main(int argc, char *argv[]) {
  nodo_t *pila = NULL;
  int opcion = 0;
  do {

  }
  return 0;
}

void nuevoNodo(nodo_t ** pila) { //es doble * porque como la pila ya es un puntero quiero cambiar la direccion del puntero pila
  nodo_t *nodo;
  nodo = (nodo_t *)malloc(sizeof(nodo_t));
  nodo->numero = 3;
  nodo->siguiente = *pila;
  *pila = nodo;
}

void listarNodo(nodo_t *pila) {

}
