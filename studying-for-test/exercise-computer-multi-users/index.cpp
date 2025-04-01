#include <stdio.h>
#include <windows.h>
#include "headers/fila-circular-com-prioridade.h"
// #include "headers/fila-com-prioridade.h"


Transacao lerTransacao(FILE * arquivoTransacoes);
void tempoDeEsperaTransacoes(Transacao transacoes[quantidadeDeTransacoesMaxima]);
void verificandoPrioridade(Transacao transacoes[quantidadeDeTransacoesMaxima], Transacao transacaoInicio);
void gerandoTempoMedioDeEsperaTransacoes(Transacao transacoesFinalizadas[quantidadeDeTransacoesMaxima], int quantidadeDeTransacoesFinalizadas);

int main() {
  // unidade de tempo = segundo
  // ler uma nova transação a cade 3 unidade de tempo.

  // tempo de espera = intervalo de tempo entre a leitura da nova transação, e a hora que ela foi inicializada.
  
  // apenas uma transação pode ser exercutada por vez.

  /* caso tenha uma transação sendo executada, e uma transação de prioridade maior for lida, 
  a transação que está sendo executada vai parar e voltar para fila. 
  Sendo assim, a transação com prioridade maior assumira a execução */

  FILE * arquivoTransacoes = fopen("./assets/transacoes.txt", "r");

  filaComPrioridade fila;
  int totalUnidadeDeTempo = 0;

  Transacao transacoesFinalizadas[quantidadeDeTransacoesMaxima];
  int quantidadeDeTransacoesFinalizadas = 0;

  inicializarFila(fila);
  do {
    if (arquivoTransacoes != NULL) {
      printf("\ntotalUnidadeDeTempo = %d\n", totalUnidadeDeTempo);

      if (!feof(arquivoTransacoes) && !(totalUnidadeDeTempo % 3)) {
        Transacao transacao = lerTransacao(arquivoTransacoes);
        inserirFila(fila, transacao);
      }

      Transacao transacaoInicio = filaElementoInicio(fila);
      printf("transacaoInicio = %d\n", transacaoInicio.IdUsuario);

      if (!transacaoInicio.estaProcessando) {
        transacaoInicio.estaProcessando = 1; // true
      } else {
        transacaoInicio.duracao--;
      }

      fila.transacoes[0] = transacaoInicio;

      if (transacaoInicio.duracao <= 0) {
        transacoesFinalizadas[quantidadeDeTransacoesFinalizadas] = retirarFila(fila);
        quantidadeDeTransacoesFinalizadas++;
      }

      verificandoPrioridade(fila.transacoes, transacaoInicio);
      tempoDeEsperaTransacoes(fila.transacoes);
      totalUnidadeDeTempo++;

      exibirFila(fila);
    }
    
    Sleep(1000);
  } while(!filaEstaVazia(fila) || (!feof(arquivoTransacoes) && arquivoTransacoes != NULL));
  gerandoTempoMedioDeEsperaTransacoes(transacoesFinalizadas, quantidadeDeTransacoesFinalizadas);
}

Transacao lerTransacao(FILE * arquivoTransacoes) {
  Transacao transacao;
  fscanf(arquivoTransacoes, "%d,%[^,],%d,%d", &transacao.IdUsuario, &transacao.nomeTransacao, &transacao.prioridade, &transacao.duracao);

  transacao.estaProcessando = 0; // false
  transacao.tempoEspera = 0;

  return transacao;
}

void tempoDeEsperaTransacoes(Transacao transacoes[quantidadeDeTransacoesMaxima]) {
  for(int i = 0; i < quantidadeDeTransacoesMaxima; i++) {
    Transacao transacao = transacoes[i];

    if (!transacao.estaProcessando) {
      transacoes[i].tempoEspera++;
    }
  }
}

void verificandoPrioridade(Transacao transacoes[quantidadeDeTransacoesMaxima], Transacao transacaoInicio) {
  for(int i = 1; i < quantidadeDeTransacoesMaxima; i++) {
    Transacao transacao = transacoes[i];

    char transacaoEstaNoInicio = (transacao.IdUsuario == transacaoInicio.IdUsuario && transacao.nomeTransacao == transacaoInicio.nomeTransacao); // bool

    if (transacao.estaProcessando && !transacaoEstaNoInicio) {
      transacoes[i].estaProcessando = 0; // false
    }
  }
}

void gerandoTempoMedioDeEsperaTransacoes(Transacao transacoesFinalizadas[quantidadeDeTransacoesMaxima], int quantidadeDeTransacoesFinalizadas) {
  int totalTempoMedioDeEspera = 0;

  for(int i = 0; i < quantidadeDeTransacoesMaxima; i++) {
    Transacao transacao = transacoesFinalizadas[i];
    totalTempoMedioDeEspera += transacao.tempoEspera;
  }

  printf("\nTempo medio de espera: %.2f", (float) totalTempoMedioDeEspera / quantidadeDeTransacoesFinalizadas);
}