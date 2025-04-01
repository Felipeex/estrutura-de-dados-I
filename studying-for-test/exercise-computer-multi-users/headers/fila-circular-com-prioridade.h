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

  int inicio;
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
  fila.inicio = 0;
  fila.fim = -1;
  fila.quantidade = 0;
}

void inserirFila(filaComPrioridade &fila, Transacao transacao) {
  fila.transacoes[++fila.fim] = transacao;
  fila.quantidade++;

  /* fila.inicio > fila.fim */

  if (fila.fim <= 0 && fila.quantidade > 1) { // Verifica se não está comparando o fim com lixo, e precisa dar a volta no vetor
    /* Transacao elemento = fila.transacoes[quantidadeDeTransacoesMaxima - 1];

    if (transacao.prioridade > elemento.prioridade) {
      fila.transacoes[fim] = transacao;
      fila.transacoes[fim + 1] = elemento;
    }

    fim = quantidadeDeTransacoesMaxima - 1; */
  } else { // Significa que o fim está linear ao inicio, e não precisamos da a volta no vetor
    for(int i = fila.fim - 1; i >= 0 && transacao.prioridade < fila.transacoes[i].prioridade; i--) {
      Transacao elemento = fila.transacoes[i];

      fila.transacoes[i] = transacao;
      fila.transacoes[i + 1] = elemento;
    }
  }
}

Transacao retirarFila(filaComPrioridade &fila) {
  Transacao transacao = fila.transacoes[0];

  if (fila.inicio == (quantidadeDeTransacoesMaxima - 1)) {
    fila.inicio = -1;
  }

  fila.inicio++;
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
  return fila.transacoes[fila.inicio];
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