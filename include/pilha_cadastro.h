#ifndef _pilha_cadastro
#define _pilha_cadastro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct desqnode{
    char comando[400];
    struct desqnode *proximo;
    struct desqnode *anterior;
} desq_node;

typedef struct {
  desq_node *comeco;
  desq_node *fim;
  int tamanho;

} pilha_desq;

pilha_desq *criar_pilha();
desq_node *criar_desq_node (char caminho[370]);
bool destruir_pilha_cad(pilha_desq *ref);
bool push(pilha_desq *ref, char caminho[370]);
bool pop (pilha_desq *ref);
void exibir_lista(pilha_desq *ref);   
int get_size(pilha_desq *ref);

#endif
