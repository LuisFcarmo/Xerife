#include "cad_questao.h"

chead *lista = NULL;
chead *lista_questao = NULL;
cnode *aux = NULL;
cnode *aux_entrada_saida = NULL;

char lista_atual[200];

void criar_carregar_lista(const char *qtd_questao) {
    lista = criar_c_lista();
    for (int i = 1; i <= atoi(qtd_questao); i++) {
        adicionar_c_fim(lista, i);
    }
    aux = lista -> begin;
};

void criar_carregar_lista_entrada_saoida(const char *qtd_entrada_saida) {
    lista_questao = criar_c_lista();
    for (int i = 1; i <= atoi(qtd_entrada_saida); i++) {
        adicionar_c_fim(lista_questao, i);
    }
    aux_entrada_saida = lista_questao -> begin;
};

void cria_pastas_desq_questao (const char * qtd_questao) {
    int max_questao = atoi(qtd_questao);
    FILE *aqr = fopen("../qtd.txt", "r");
    fscanf(aqr, "%[^\n]", lista_atual);
    fclose(aqr);
    char caminho[100];
    char caminho_aux[100];

    strcpy(caminho, caminho_aux);

    for (int i = 1; i <= max_questao; i++) {
        sprintf(caminho, "mkdir ../main/banco_listas/lista%d/questao%d", atoi(lista_atual), i);
        system(caminho);
    }

    criar_carregar_lista(qtd_questao);
}

void cria_pastas_entrada_saida (const char *qtd_questao) {
    char caminho[200] = "";
    int max_questao = atoi(qtd_questao);

    for (int i = 1; i <= max_questao; i++) {
        sprintf(caminho, "mkdir ../main/banco_listas/lista%d/questao%d/entrada%d", atoi(lista_atual), i, i);
        system(caminho);
        sprintf(caminho, "mkdir ../main/banco_listas/lista%d/questao%d/saida%d", atoi(lista_atual), i, i);
        system(caminho);
    }
}


void cadastro_descricao_questao(const char* qtd_questao) {
    cria_pastas_desq_questao(qtd_questao);
};

void gravar_arquivo (gchar *caminho) {
    char caminho_destino[100];
    char caminho_final[300] = "cp ";
    sprintf(caminho_destino, " ../main/banco_listas/lista%d/questao%d/", atoi(lista_atual), aux -> numero_questao);
    strcat(caminho_final, (char*) caminho);
    strcat(caminho_final, caminho_destino);
    system(caminho_final);

}

void fechar_recursos() {
    destruir_c_lista(lista);
}

int proxima_questao (gchar *caminho) {
    if (aux == lista -> end) {
        fechar_recursos();
        return 1;
    } else {
        aux = aux -> next;
    }    
};

void gravar_arquivo_entrada_saida (gchar *caminho_entrada, gchar *caminho_saida) {
    char caminho_destino[100];
    char caminho_final[300] = "cp ";

    sprintf(caminho_destino, " ../main/banco_listas/lista%d/questao%d/entrada%d/", atoi(lista_atual),
        aux -> numero_questao, aux -> numero_questao 
    );
    
    strcat(caminho_final, (char*) caminho_entrada);
    strcat(caminho_final, caminho_destino);

    system(caminho_final);

    sprintf(caminho_destino, " ../main/banco_listas/lista%d/questao%d/saida%d/", atoi(lista_atual),
        aux -> numero_questao, aux -> numero_questao 
    );

    char caminho_final2[300] = "cp ";

    strcat(caminho_final2, (char*) caminho_saida);
    strcat(caminho_final2, caminho_destino);

    system(caminho_final2);

}

int proxima_questao_entrada_saida () {
    if (aux_entrada_saida == lista_questao -> end ) {
        aux_entrada_saida = lista_questao -> begin;
        if (aux == lista -> end) {
            destruir_c_lista(lista);
            destruir_c_lista(lista_questao);

            return 1;
        }
        aux = aux -> next;
    } 
    else {
        aux_entrada_saida = aux_entrada_saida -> next;
    }
}