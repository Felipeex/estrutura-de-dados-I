#include <stdio.h>

#include "./TADs/fila-dinamica-simplesmente-encadeada.h"

int filaSimplesmente() {
  // fila dinamica simplesmente encadeada
  printf("Fila dinamica simplesmente encadeada: \n");

  PonteiroFilaSimplesmente * filaSimplesmente = NULL;

  filaSimplesmente = inserirFimFilaSimplesmente(filaSimplesmente, 10);
  filaSimplesmente = inserirFimFilaSimplesmente(filaSimplesmente, 5);
  filaSimplesmente = inserirFimFilaSimplesmente(filaSimplesmente, 2);
  filaSimplesmente = inserirFimFilaSimplesmente(filaSimplesmente, 20);
  filaSimplesmente = inserirFimFilaSimplesmente(filaSimplesmente, 7);

  filaSimplesmente = removerInicioFilaSimplesmente(filaSimplesmente); // remove 10

  filaSimplesmente = inserirFimFilaSimplesmente(filaSimplesmente, 99);


  printf("\nexibirIterativoFilaSimplesmente()\n");
  exibirIterativoFilaSimplesmente(filaSimplesmente);

  printf("\nexibirIterativoInvertidoFilaSimplesmente()\n");
  exibirIterativoInvertidoFilaSimplesmente(filaSimplesmente);

  printf("\nexibirRecursivoFilaSimplesmente()\n");
  exibirRecursivoFilaSimplesmente(filaSimplesmente);

  printf("\nexibirRecursivoInvertidoFilaSimplesmente()\n");
  exibirRecursivoInvertidoFilaSimplesmente(filaSimplesmente);
}

int filaSimplesmenteOrdenado() {
  // fila dinamica simplesmente encadeada (Ordenado)
  printf("\nFila dinamica simplesmente encadeada (Ordenado): \n");

  PonteiroFilaSimplesmente * filaSimplesmente = NULL;

  filaSimplesmente = inserirOrdenadoFilaSimplesmente(filaSimplesmente, 10);
  filaSimplesmente = inserirOrdenadoFilaSimplesmente(filaSimplesmente, 5);
  filaSimplesmente = inserirOrdenadoFilaSimplesmente(filaSimplesmente, 2);
  filaSimplesmente = inserirOrdenadoFilaSimplesmente(filaSimplesmente, 20);
  filaSimplesmente = inserirOrdenadoFilaSimplesmente(filaSimplesmente, 7);

  // filaSimplesmente = removerInicioFilaSimplesmente(filaSimplesmente); // remove 10

  filaSimplesmente = inserirOrdenadoFilaSimplesmente(filaSimplesmente, 99);


  printf("\nexibirIterativoFilaSimplesmente()\n");
  exibirIterativoFilaSimplesmente(filaSimplesmente);

  printf("\nexibirIterativoInvertidoFilaSimplesmente()\n");
  exibirIterativoInvertidoFilaSimplesmente(filaSimplesmente);

  printf("\nexibirRecursivoFilaSimplesmente()\n");
  exibirRecursivoFilaSimplesmente(filaSimplesmente);

  printf("\nexibirRecursivoInvertidoFilaSimplesmente()\n");
  exibirRecursivoInvertidoFilaSimplesmente(filaSimplesmente);
}

int main(void) {
  // filaSimplesmente();
  filaSimplesmenteOrdenado();
}