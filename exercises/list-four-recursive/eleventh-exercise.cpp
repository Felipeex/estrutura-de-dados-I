#include <stdio.h>

int somatorio(int i, int n);

int main() {
  int soma = somatorio(1, 8);
  printf("%d", soma);
}

int somatorio(int i, int n) {
  if (i < n) {
    return (i * i) + somatorio(i + 1, n);
  }
}