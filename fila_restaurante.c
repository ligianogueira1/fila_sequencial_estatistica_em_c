#include "fila_rest.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void criarFila(Fila *f) {
  f->inicio = 0;
  f->tamanho = 0;
}

int estaVazia(Fila *f) { return f->tamanho == 0; }

int estaCheia(Fila *f) { return f->tamanho == MAX; }

int tamanhoDaFila(Fila *f) { return f->tamanho; }

int inserirNaFila(Fila *f, const char cliente[]) {
  if (estaCheia(f)) {
    return 0;
  } else {
    strcpy(f->cliente[f->tamanho], cliente);
    f->tamanho++;
    return 1;
  }
}

int removerDaFila(Fila *f, char clienteRemovido[MAX_TAMANHO_STRING]) {
  if (estaVazia(f)) {
    printf("A fila já está vazia.\n");
    return 0;
  } else {
    strcpy(clienteRemovido, f->cliente[f->inicio]);
    f->inicio = (f->inicio + 1) % MAX;
    f->tamanho--;
    return 1;
  }
}

int removerDaFilaPedido(Fila *filaPedido, Fila *filaPagamento) {
  char clienteRemovido[MAX_TAMANHO_STRING];
  if (!estaVazia(filaPedido)) {
    removerDaFila(filaPedido, clienteRemovido);
    inserirNaFila(filaPagamento, clienteRemovido);
  }
}

int removerDaFilaPagamento(Fila *filaPagamento, Fila *filaEncomenda) {
  char clienteRemovido[MAX];
  if (!estaVazia(filaPagamento)) {
    if (removerDaFila(filaPagamento, clienteRemovido)) {
      if (inserirNaFila(filaEncomenda, clienteRemovido)) {
        return 1;
      }
    }
  }
  return 0;
}

int removerDaFilaEncomenda(Fila *filaEncomenda, char clienteRemovido[MAX]) {
  if (!estaVazia(filaEncomenda)) {
    removerDaFila(filaEncomenda, clienteRemovido);
  }
}

void exibirFila(Fila *f) {
  if (estaVazia(f)) {
    printf("A fila está vazia.\n");
  } else {
    int i;
    int indice = f->inicio;
    for (i = 0; i < f->tamanho; i++) {
      printf("%s\n", f->cliente[indice]);
      indice = (indice + 1) % MAX;
    }
  }
}
