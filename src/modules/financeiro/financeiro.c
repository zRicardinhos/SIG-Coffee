#include <stdio.h>
#include <stdlib.h>
#include "financeiro.h"
#include "../utils/validacoes.h"

void modulo_financeiro(void){
    char opcao;
    do {
        opcao = tela_financeiro();
        switch(opcao){
            case '1':
            registrar_despesa();
                break;
            case '2':
            saldo_atual();
                break;
            case '3':
            registrar_ganho();
                break;
            case '4':
            relatorio_financeiro();
                break;
        }
    }
    while(opcao != '0');
}
//Tela principal
char tela_financeiro(void){
    char op;
    printf("╔═══════════════════════════════════════════╗\n");
    printf("║       Você está no Módulo Financeiro 💰   ║\n");
    printf("╠═══════════════════════════════════════════╣\n");
    printf("║   [1] - Registrar Nova Despesa            ║\n");
    printf("║   [2] - Visualizar Saldo Atual            ║\n");
    printf("║   [3] - Registrar Novo Ganho/Lucro        ║\n");
    printf("║   [4] - Gerar Relatório Financeiro        ║\n");
    printf("║   [0] - Voltar ao Menu Principal          ║\n");
    printf("╚═══════════════════════════════════════════╝\n");
    printf("     🌟 Por favor, selecione uma opção 🌟:   \n");

    scanf("%c",&op);
    getchar();
    system("clear");
    return op;
}

// SUBMODULOS FINANCEIRO
void registrar_despesa(void){
    printf("╔═══════════════════════════════════════════╗\n");
    printf("║           Registrar nova Despesa          ║\n");
    printf("╚═══════════════════════════════════════════╝\n");
    printf("      Descrição da despesa: \n");
    printf("      Valor: \n");
    printf("Pressione Qualquer tecla para Continuar!!!\n");
    getchar();
    system("clear");
}
void registrar_ganho(void){
    printf("╔═══════════════════════════════════════════╗\n");
    printf("║            Registrar Ganho/Lucro          ║\n");
    printf("╚═══════════════════════════════════════════╝\n");
    printf("      Descrição do ganho: \n");
    printf("      Valor: \n");
    printf("Pressione Qualquer tecla para Continuar!!!\n");
    getchar();
    system("clear");
}
void saldo_atual(void){
    printf("╔═══════════════════════════════════════════╗\n");
    printf("║            Vizualizar Saldo Atual         ║\n");
    printf("╚═══════════════════════════════════════════╝\n");
    printf("      Saldo atual: \n");
    printf("Pressione Qualquer tecla para Continuar!!!\n");
    getchar();
    system("clear");
}
void relatorio_financeiro(void){
    printf("╔═══════════════════════════════════════════╗\n");
    printf("║              Relatorio Financeiro         ║\n");
    printf("╚═══════════════════════════════════════════╝\n");
    printf("      Relatório Completo: \n");
    printf("Pressione Qualquer tecla para Continuar!!!\n");
    getchar();
    system("clear");
}