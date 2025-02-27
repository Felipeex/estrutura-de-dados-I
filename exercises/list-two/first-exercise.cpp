#include <stdio.h>
#include "./utils/pilha.h"

void concatenaPilha(TpPilha &primeiraPilha, TpPilha segundaPilha);

int main() {
  TpPilha primeiraPilha;
  TpPilha segundaPilha;

  inicializa(primeiraPilha);

  insere(primeiraPilha, 34);
  insere(primeiraPilha, 87);
  insere(primeiraPilha, 32);
  insere(primeiraPilha, 45);

  inicializa(segundaPilha);

  insere(primeiraPilha, 28);
  insere(primeiraPilha, 74);
  insere(primeiraPilha, 56);
  insere(primeiraPilha, 41);
  insere(primeiraPilha, 23);

  concatenaPilha(primeiraPilha, segundaPilha);

  exibe(primeiraPilha);
}

void concatenaPilha(TpPilha &primeiraPilha, TpPilha segundaPilha) {
  TpPilha pilhaAuxilar;
  inicializa(pilhaAuxilar);

  while(!vazia(segundaPilha.TOPO))
    insere(pilhaAuxilar, retira(segundaPilha));

  while(!vazia(pilhaAuxilar.TOPO))
    insere(primeiraPilha, retira(pilhaAuxilar));
}