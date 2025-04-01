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
}