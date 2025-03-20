#define MAXFILA 10

struct Veiculo {
  char placa[20];
  char cor[15];
  char fabricante[30];
  char prioridade;
};

struct FilaCircular {
  int inicio;
  int fim;
  int quantidade;

  Veiculo fila[MAXFILA];
};

void inicializar(FilaCircular &filaCircular) {
  filaCircular.inicio = 0;
  filaCircular.fim = -1;
  filaCircular.quantidade = 0;
}

Veiculo inserir(FilaCircular &filaCircular, Veiculo veiculo) {
  if (filaCircular.fim + 1 == MAXFILA) {
    filaCircular.fim = -1;
  }

  filaCircular.fila[++filaCircular.fim] = veiculo;
  filaCircular.quantidade++;
}

Veiculo retirar(FilaCircular &filaCircular) {
  Veiculo veiculo = filaCircular.fila[filaCircular.inicio];

  if (filaCircular.inicio + 1 == MAXFILA) {
    filaCircular.inicio = -1;
  }

  filaCircular.inicio++;
  filaCircular.quantidade--;

  return veiculo;
}

Veiculo elementoInicio(FilaCircular &filaCircular) {
  return filaCircular.fila[filaCircular.inicio];
}

Veiculo elementoFim(FilaCircular &filaCircular) {
  return filaCircular.fila[filaCircular.fim];
}

int estaVazia(FilaCircular &filaCircular) {
  return filaCircular.quantidade == 0;
}

int estaCheia(FilaCircular &filaCircular) {
  return filaCircular.quantidade == MAXFILA;
}