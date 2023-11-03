#include "fila_rest.h"
#include <stdio.h>

int main(void) {
  Fila filaPedido;
  Fila filaPagamento;
  Fila filaEncomenda;
  criarFila(&filaPedido);
  criarFila(&filaPagamento);
  criarFila(&filaEncomenda);

  char opcao;

  do {
    printf("\n------------------------------------------------------\n");
    printf("\n--- Menu principal ---\n");
    printf("\na) Inserir na fila de pedido\n");
    printf("b) Remover da fila de pedido\n");
    printf("c) Remover da fila de pagamento\n");
    printf("d) Remover da fila de encomenda e liberá-lo.\n");
    printf("e) Exibir as filas\n");
    printf("f) Sair do programa\n");
    printf("\nDigite uma opção: ");
    scanf(" %c", &opcao);

    switch (opcao) {
    case 'a':
      printf("Você escolheu inserir na fila de pedido.\n");
      char cliente[MAX];
      printf("\nDigite o nome do cliente: ");
      scanf(" %s", cliente);

      if (inserirNaFila(&filaPedido, cliente)) {
        printf("O cliente foi inserido na fila com sucesso!\n");
      } else {
        printf("A fila está cheia. Por favor, aguarde.\n");
      }
      break;

    case 'b':
      printf("Você escolheu remover o cliente da fila de pedido.\n");

      if (removerDaFilaPedido(&filaPedido, &filaPagamento)) {
        printf("\nCliente inserido com sucesso na fila de pagamento!");
      }
      break;

    case 'c':
      printf("Você escolheu remover o cliente da fila de pagamento.\n");

      if (removerDaFilaPagamento(&filaPagamento, &filaEncomenda)) {
        printf("\nCliente inserido com sucesso na fila de encomenda!");
      }
      break;

    case 'd':
      printf("Você escolheu remover o cliente da fila de encomenda e "
             "liberá-lo.\n");

      if (removerDaFilaEncomenda(&filaEncomenda, cliente)) {
        printf("\nCliente liberado!");
      }
      break;

    case 'e':
      printf("Você escolheu exibir as filas.\n");

      printf("\nFila de Pedido: \n");
      exibirFila(&filaPedido);

      printf("\n");
      printf("Fila de Pagamento: \n");
      exibirFila(&filaPagamento);

      printf("\n");
      printf("Fila de Encomenda: \n");
      exibirFila(&filaEncomenda);

      break;

    case 'f':
      break;

    default:
      printf("Opção inválida.\n");
    }
  } while (opcao != 'f');

  return 0;
}
