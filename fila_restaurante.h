#define MAX 10
#define MAX_TAMANHO_STRING 20

typedef struct fila {
  char cliente[MAX][MAX_TAMANHO_STRING];
  int inicio;
  int fim;
  int tamanho;
} Fila;

void criarFila(Fila *f);
int estaVazia(Fila *f);
int estaCheia(Fila *f);
int tamanhoDaFila(Fila *f);
int inserirNaFila(Fila *f, const char cliente[]);
int removerDaFilaPedido(Fila *filaPedido, Fila *filaPagamento);
int removerDaFilaPagamento(Fila *filaPagamento, Fila *filaEncomenda);
int removerDaFilaEncomenda(Fila *filaEncomenda, char clienteRemovido[MAX]);
void exibirFila(Fila *f);
