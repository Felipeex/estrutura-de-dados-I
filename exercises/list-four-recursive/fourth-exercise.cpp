#include <stdio.h>

void printarVetorInvertido(int vetor[], int TL);

int main() {
  int vetor[3] = { 456, 123, 543 };

  printarVetorInvertido(vetor, 2);
}

void printarVetorInvertido(int vetor[], int TL) {
  if (TL >= 0) {
    printf("%d ", vetor[TL]);
    printarVetorInvertido(vetor, TL - 1);
  }
}