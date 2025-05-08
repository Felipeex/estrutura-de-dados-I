#include <stdio.h>
#include <string.h>

struct Elemento {
  char nome[100];
  Elemento *proximo;
};

Elemento *inserir(Elemento *lista, char nome[100]);
int isVazia(Elemento *lista);
void exibir(Elemento *lista);
void exibirRecursivo(Elemento *lista);

int main(void) {
  char nome[100];
  Elemento *lista = NULL;

  do {
    printf("Forneca um nome: ");
    fgets(nome, 100, stdin);

    lista = inserir(lista, nome);
  } while(strlen(nome) > 1);

  exibir(lista);

  printf("\nExibir recursivo: ");
  exibirRecursivo(lista);
}


Elemento *inserir(Elemento *lista, char nome[100]) {
  Elemento *novoElemento = new Elemento;

  strcpy(novoElemento->nome, nome);
  novoElemento->proximo = lista;

  lista = novoElemento;
  return lista;
}

void exibir(Elemento *lista) {
  printf("\nExibir iterativo: ");
  while(lista != NULL) {
    printf("%s", lista->nome);
    lista = lista->proximo;
  }
}

void exibirRecursivo(Elemento *lista) {
  if (lista != NULL) {
    printf("%s", lista->nome);
    exibirRecursivo(lista->proximo);
  }
}

int isVazia(Elemento *lista) {
  return lista == NULL;
}