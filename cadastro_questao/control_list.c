#include "control_list.h"

chead *criar_c_lista() {
    chead *lista = NULL;

    do {
        lista = (chead*) malloc(sizeof(chead)*1);
    } while (lista == NULL);

    lista -> begin = NULL;
    lista -> end = NULL;
    lista -> tamanho = 0;

    return lista;
};

cnode *criar_c_no(int numero) {
    cnode *no = NULL;
    do {
        no = (cnode*) malloc(sizeof(cnode)*1);
    } while (no == NULL);
    no -> numero_questao = numero;
    no -> next = NULL;
    no -> prev = NULL;
    
    return no;
}; 

bool adicionar_c_fim(chead *lista, int numero) {
    if (lista != NULL){
        cnode *no = criar_c_no(numero);
        cnode *aux = NULL;

        if (lista -> tamanho == 0) {
            lista -> begin = no;
            lista -> end = no;    
        } else {
            aux = lista -> end;
            lista -> end = no;
            lista -> end -> prev = aux;
            aux -> next = lista -> end;
        }
        
        lista -> tamanho++;

        return true;
    } else {
        return false;
    }
};

bool destruir_c_lista(chead * lista) {
    if (lista != NULL) {
        cnode *aux = NULL;
        cnode *Pnode = lista -> begin;
        for (int i = 0; i < lista -> tamanho; i++) {
            aux = Pnode;
            Pnode = Pnode -> next;
            free(aux);
        }
        free(lista);
        return true;
    } else {
        return false;
    }
};
