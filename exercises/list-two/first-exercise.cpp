#include <stdio.h>
#include "./utils/pilha.h"

void inserirPilha(TpPilha &pilha);
void concatenaPilha(TpPilha &primeiraPilha, TpPilha segundaPilha);

int main() {
  TpPilha primeiraPilha;
  TpPilha segundaPilha;

  inicializa(primeiraPilha);

  printf("Inserir numeros da primeira pilha: ");
  inserirPilha(primeiraPilha);

  /* insere(primeiraPilha, 34);
  insere(primeiraPilha, 87);
  insere(primeiraPilha, 32);
  insere(primeiraPilha, 45); */

  inicializa(segundaPilha);

  printf("Inserir numeros da segunda pilha: ");
  inserirPilha(primeiraPilha);

/*   insere(primeiraPilha, 28);
  insere(primeiraPilha, 74);
  insere(primeiraPilha, 56);
  insere(primeiraPilha, 41);
  insere(primeiraPilha, 23); */

  concatenaPilha(primeiraPilha, segundaPilha);

  exibe(primeiraPilha);
}

void inserirPilha(TpPilha &pilha) {
  int elemento;

  do {
    scanf("%d", &elemento);
    
    if (elemento != 0) {
      insere(pilha, elemento);
    }
  } while(!cheia(pilha.TOPO) && elemento != 0);
}

void concatenaPilha(TpPilha &primeiraPilha, TpPilha segundaPilha) {
  TpPilha pilhaAuxilar;
  inicializa(pilhaAuxilar);

  while(!vazia(segundaPilha.TOPO))
    insere(pilhaAuxilar, retira(segundaPilha));

  while(!vazia(pilhaAuxilar.TOPO))
    insere(primeiraPilha, retira(pilhaAuxilar));
}