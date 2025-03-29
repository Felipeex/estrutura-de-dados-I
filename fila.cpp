#include <stdio.h>
#include "./fila.h"

int main() {
  FilaCircular filaCircular;

  inicializar(filaCircular);

  if (!estaCheia(filaCircular)) {    
    inserir(filaCircular, 10);
    inserir(filaCircular, 8);
  }

  if (!estaVazia(filaCircular)) {
    retirar(filaCircular);
  }

  if (!estaCheia(filaCircular)) {    
    inserir(filaCircular, 15);
    inserir(filaCircular, 2);
    inserir(filaCircular, 4);
    inserir(filaCircular, 6);
    inserir(filaCircular, 7);
    inserir(filaCircular, 22);
    inserir(filaCircular, 25);
    inserir(filaCircular, 30);
    inserir(filaCircular, 40);
    inserir(filaCircular, 45);
  }

  if (!estaVazia(filaCircular)) {
    retirar(filaCircular);
  }

  printf("Fila Circular (%d Elementos)\n", filaCircular.quantidade);
  exibir(filaCircular);
  
  printf("\nElemento Inicio = %d", elementoInicio(filaCircular));
  printf("\nElemento Fim = %d", elementoFim(filaCircular));

  printf("\nEsta Vazia? ");
  estaVazia(filaCircular) ? printf("Sim") : printf("Nao");

  printf("\nEsta Cheia? ");
  estaCheia(filaCircular) ? printf("Sim") : printf("Nao");
}