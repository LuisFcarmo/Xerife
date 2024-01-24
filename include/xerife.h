#ifndef XEREFI_H
#define XEREFI_H

#include "cadastro.h"
#include "deletar_lista.h"
#include "includes.h"
#include "login.h"
#include "cadastro_lista.h"
#include "mostrar_lista.h"
#include "cad_questao.h"
#include "julgar.h"
#include "mostrar_questao.h"
#include "rank.h"
#include "pilha_cadastro.h"
#include "envios.h"


void on_bt_submeter_pagina_questao_clicked ();

void on_bt_voltar_cadastro_clicked ();

void mensagem (const char *texto, const char *texto_secundario);

void on_bt_enviar_cadastro_clicked ();

void on_bt_login_tela_login_clicked ();

void on_bt_cadastre_se_login_clicked ();

void on_cadastro_questao_clicked ();

void on_bt_enviar_cadquesatao_clicked ();

void on_bt_enviar_quantidade_questao_clicked ();

void on_cad_lista_enviar_bt_clicked ();

void on_bt_avancar_exibir_listar_clicked ();

void on_bt_voltar_exibir_lista_clicked ();

void on_deslogar_clicked ();

void on_bt_ir_cadastrar_lista_clicked();

void on_bt_mostrar_listas_ativas_clicked ();

void bt_enviar_entrada_saida ();

void on_bt_lista_selecionada_entrar_clicked ();

void on_button_submeter_questao_clicked();

void on_stack_1_escolher_arquivo_file_chooser_confirm_overwrite ();

void on_stack_1_escolher_arquivo_file_chooser_file_activated();

void on_stack_1_casos_de_teste_button_back_clicked();

void on_stack_2_casos_de_teste_button_back_clicked();

void mostrar_casos_de_testes(const char*);

char* get_answer(int resultado);

void on_bt_ok_message_dialog_box_clicked(); 

void on_bt_voltar_casos_de_teste_clicked();

void on_bt_back_descricao_questao_clicked();

void on_bt_forward_descricao_questao_clicked();

void on_bt_descricao_questao_sair_clicked();

void on_bt_lista_ativa_sair_clicked();

void on_bt_voltar_cadlista_clicked();

void on_bt_deletar_lista_clicked();

void on_bt_voltar_deletar_lista_numero_clicked();
     
void on_bt_enviar_deletar_lista_numero_clicked();

void atualizar_list_store_deletar_listas();

void on_bt_mostrar_rank_clicked();

void on_bt_voltar_rank_clicked();

void on_file_chooser_arquivos_cad_geral_confirm_overwrite();

void on_file_chooser_arquivos_cad_geral_file_activated();

void on_bt_desfazer_cad_activate();

void on_bt_exercicos_listar_clicked();

void on_bt_sair_da_lista_clicked();

void on_bt_cancelar_cad_clicked();

void on_tree_view_listas_ativas_row_activated();

void on_bt_mostrar_envios_clicked();

void on_tree_view_envios_row_activated();

void on_bt_ok_codigo_prompt_clicked();
#endif