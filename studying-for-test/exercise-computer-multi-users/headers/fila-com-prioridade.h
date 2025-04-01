#define quantidadeDeTransacoesMaxima 100

struct Transacao {
  int IdUsuario;
  char nomeTransacao[100];
  
  int prioridade;
  int duracao;

  int tempoEspera;
  char estaProcessando;
};

struct filaComPrioridade {
  Transacao transacoes[quantidadeDeTransacoesMaxima];

  int fim;
  int quantidade;
};

void inicializarFila(filaComPrioridade &fila);

void inserirFila(filaComPrioridade &fila, Transacao transacao);
Transacao retirarFila(filaComPrioridade &fila);

char filaEstaVazia(filaComPrioridade fila);
char filaEstaCheia(filaComPrioridade fila);

Transacao filaElementoInicio(filaComPrioridade fila);
Transacao filaElementoFim(filaComPrioridade fila);

void exibirFila(filaComPrioridade fila);

void inicializarFila(filaComPrioridade &fila) {
  fila.fim = -1;
  fila.quantidade = 0;
}

void inserirFila(filaComPrioridade &fila, Transacao transacao) {
  fila.transacoes[++fila.fim] = transacao;
  fila.quantidade++;

  for(int i = fila.fim - 1; i >= 0 && transacao.prioridade < fila.transacoes[i].prioridade; i--) {
    Transacao elemento = fila.transacoes[i];

    fila.transacoes[i] = transacao;
    fila.transacoes[i + 1] = elemento;
  }
}

Transacao retirarFila(filaComPrioridade &fila) {
  Transacao transacao = fila.transacoes[0];

  for(int i = 0; i < fila.fim; i++) {
    fila.transacoes[i] = fila.transacoes[i + 1];
  }

  fila.fim--;
  fila.quantidade--;
  return transacao;
}

char filaEstaVazia(filaComPrioridade fila) {
  return fila.fim < 0;
}

char filaEstaCheia(filaComPrioridade fila) {
  return fila.quantidade == quantidadeDeTransacoesMaxima;
}

Transacao filaElementoInicio(filaComPrioridade fila) {
  return fila.transacoes[0];
}

Transacao filaElementoFim(filaComPrioridade fila) {
  return fila.transacoes[fila.fim];
}

void exibirFila(filaComPrioridade fila) {
  while(!filaEstaVazia(fila)) {
    Transacao transacao = retirarFila(fila);
    printf("[%d] (%d) %s, duracao: %d, tempoEspera: %d, processando: %d\n", transacao.prioridade, transacao.IdUsuario, transacao.nomeTransacao, transacao.duracao, transacao.tempoEspera, transacao.estaProcessando);
  }
}