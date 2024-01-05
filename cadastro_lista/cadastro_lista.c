#include "cadastro_lista.h"
#include "gtk-3.0/gtk/gtk.h"

int qtd_lista = 0;

void cadastrar_nome_lista(char const *nome) {
    char nome_da_questao[100] = "";
    char caminho[500] = "../main/banco_listas/";
    char pasta[500] = "lista";
    char nome_arq[500] =  "/nome_lista";
    FILE *file = fopen("../qtd.txt", "r");  
    char numero[200] = "";
    fscanf(file, "%[^\n]", numero);
    strcat(pasta, numero);
    strcat(caminho, pasta);
    strcat(nome_arq, numero);
    strcat(nome_arq, ".txt");
    strcat(caminho, nome_arq);
    fclose(file);
    
    g_print("%s", caminho);

    strcpy(nome_da_questao, nome);
    FILE *arq = fopen(caminho, "a");
    fputs(nome_da_questao, arq);
    fputc('\n', arq);
    fclose(arq);
};

void criar_pasta_lista () {
    char caminho[2000] = "mkdir banco_listas/lista";
    FILE *file = fopen("../qtd.txt", "r");  
    char numero[200] = "";  
    fscanf(file, "%[^\n]", numero);

    strcat(caminho, numero);
    system(caminho);

    fclose(file);
}

void atualizar_qtd_lista () {
    //abrindo e lendo a quantidade de listas no sistema
    FILE *file = NULL;
    file = fopen("../qtd.txt", "r");
    char quantidade[200] = "";
    int intquantidade = 0;
    fscanf(file ,"%[^\n]", quantidade);
    intquantidade = atoi(quantidade);
    intquantidade++;
    fclose(file);


    //atualizando a quantidade de listas no sistema
    file = NULL;
    file = fopen("../qtd.txt", "w");
    fprintf(file, "%d\n", intquantidade);
    fclose(file);
}

void casdastrar_lista(const char *nome) {
    g_print("%s", nome);
    atualizar_qtd_lista();
    criar_pasta_lista();
    cadastrar_nome_lista(nome);
};
