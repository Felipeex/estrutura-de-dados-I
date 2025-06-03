#include <stdio.h>

struct PonteiroFilaSimplesmente {
  int numeroElemento;
  PonteiroFilaSimplesmente * proximo;
} typedef No;

PonteiroFilaSimplesmente * inserirFimFilaSimplesmente(PonteiroFilaSimplesmente *fila, int numeroElemento);
PonteiroFilaSimplesmente * inserirOrdenadoFilaSimplesmente(PonteiroFilaSimplesmente *fila, int numeroElemento);

PonteiroFilaSimplesmente * removerInicioFilaSimplesmente(PonteiroFilaSimplesmente *fila);

int estaVazio(PonteiroFilaSimplesmente *fila);

void exibirIterativoFilaSimplesmente(PonteiroFilaSimplesmente *fila);
void exibirIterativoInvertidoFilaSimplesmente(PonteiroFilaSimplesmente *fila);

void exibirRecursivoFilaSimplesmente(PonteiroFilaSimplesmente *fila);
void exibirRecursivoInvertidoFilaSimplesmente(PonteiroFilaSimplesmente *fila);

PonteiroFilaSimplesmente * inserirFimFilaSimplesmente(PonteiroFilaSimplesmente * fila, int numeroElemento) {
  No * auxiliarFila;
  No * novo = new No;

  novo->numeroElemento = numeroElemento;
  novo->proximo = NULL;

  if (estaVazio(fila)) {
    fila = novo;
  } else {
    auxiliarFila = fila;

    while(auxiliarFila->proximo != NULL)
      auxiliarFila = auxiliarFila->proximo;

    auxiliarFila->proximo = novo;
  }

  return fila;
}

PonteiroFilaSimplesmente * inserirOrdenadoFilaSimplesmente(PonteiroFilaSimplesmente *fila, int numeroElemento) {
  PonteiroFilaSimplesmente * auxiliarFila, * anterior;
  PonteiroFilaSimplesmente * novo = new PonteiroFilaSimplesmente;

  novo->numeroElemento = numeroElemento;
  novo->proximo = NULL;

  if (estaVazio(fila)) {
    novo->proximo = fila;
    fila = novo;
  } else {
    if (fila->numeroElemento < numeroElemento) {
      auxiliarFila = fila;
      novo->proximo = fila;
      fila = novo;
    } else {
      auxiliarFila = fila->proximo;

      printf("oi?");

      while(auxiliarFila != NULL && auxiliarFila->numeroElemento < numeroElemento) {
        anterior = auxiliarFila;
        auxiliarFila = auxiliarFila->proximo;
      }

      if (auxiliarFila->proximo == NULL) {
        auxiliarFila->proximo = novo;
      } else {
        anterior->proximo = novo;
        novo->proximo = auxiliarFila;
      }
    }
  }
}

PonteiroFilaSimplesmente * removerInicioFilaSimplesmente(PonteiroFilaSimplesmente *fila) {
  No * novoElementoInicio = fila->proximo;
  delete fila;
  
  fila = novoElementoInicio;
  return fila;
}

int estaVazio(PonteiroFilaSimplesmente *fila) {
  return fila == NULL;
}

void exibirIterativoFilaSimplesmente(PonteiroFilaSimplesmente * fila) {
  while(fila != NULL) {
    printf("%d\n", fila->numeroElemento);
    fila = fila->proximo;
  }
}

void exibirIterativoInvertidoFilaSimplesmente(PonteiroFilaSimplesmente * fila) {
  No * filaInvertida = NULL;

  while(fila != NULL) {
    No * novo = new No;

    novo->numeroElemento = fila->numeroElemento;
    novo->proximo = filaInvertida;

    filaInvertida = novo;

    fila = fila->proximo;
  }

  while(filaInvertida != NULL) {
    No * atual = filaInvertida;
    printf("%d\n", atual->numeroElemento);
    
    filaInvertida = filaInvertida->proximo;
    delete atual;
  }
}

void exibirRecursivoFilaSimplesmente(PonteiroFilaSimplesmente *fila) {
  if (fila != NULL) {
    printf("%d\n", fila->numeroElemento);
    exibirRecursivoFilaSimplesmente(fila->proximo);
  }
}

void exibirRecursivoInvertidoFilaSimplesmente(PonteiroFilaSimplesmente *fila) {
  if (fila != NULL) {
    exibirRecursivoInvertidoFilaSimplesmente(fila->proximo);
    printf("%d\n", fila->numeroElemento);
  }
}