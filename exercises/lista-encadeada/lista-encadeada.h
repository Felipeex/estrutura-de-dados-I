#include <stdio.h>

struct Elemento {
  int numero;
  Elemento * proximo;
};

Elemento * adicionar(Elemento * lista, int numero) {
  Elemento * novo = new Elemento;

  novo->numero = numero;
  novo->proximo = lista;

  lista = novo;
  return lista;
}

void exibir(Elemento * lista) {
  while(lista != NULL) {
    printf("%d\n", lista->numero);
    lista = lista->proximo;
  }
}