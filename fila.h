#include <stdio.h>

#define quantidadeMaximaFila 10 // MAXFILA

struct FilaCircular {
  int inicio;
  int fim;

  int fila[quantidadeMaximaFila];
  int quantidade;
};

void inicializar(FilaCircular &f);
void inserir(FilaCircular &f, int elemento);
int retirar(FilaCircular &f);

int estaCheia(FilaCircular f);
int estaVazia(FilaCircular f);

int elementoFim(FilaCircular f);
int elementoInicio(FilaCircular f);

void exibir(FilaCircular f);

void inicializar(FilaCircular &f) {
  f.fim = -1;
  f.inicio = 0;
  f.quantidade = 0;
}

void inserir(FilaCircular &f, int elemento) {
  if (f.fim == (quantidadeMaximaFila - 1)) {
    f.fim = 0;
    f.fila[f.fim] = elemento;
  } else {
    f.fila[++f.fim] = elemento;
  }

  f.quantidade++;
}

int retirar(FilaCircular &f) {
  int elementoRetirado = f.fila[f.inicio];

  if (f.inicio == (quantidadeMaximaFila - 1)) {
    f.inicio = 0;
  } else {
    f.inicio++;
  }

  f.quantidade--;

  return elementoRetirado;
}

int estaCheia(FilaCircular f) {
  return f.quantidade == quantidadeMaximaFila;
}

int estaVazia(FilaCircular f) {
  return f.quantidade == 0;
}

int elementoFim(FilaCircular f) {
  return f.fila[f.fim];
}

int elementoInicio(FilaCircular f) {
  return f.fila[f.inicio];
}

void exibir(FilaCircular f) {
  while(!estaVazia(f))
    printf("%d\n", retirar(f));
}