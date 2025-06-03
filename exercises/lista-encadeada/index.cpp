#include <stdio.h>

#include "lista-encadeada.h"

int main() {
  Elemento * lista = NULL;

  lista = adicionar(lista, 50);
  lista = adicionar(lista, 25);
  lista = adicionar(lista, 10);

  exibir(lista);
}