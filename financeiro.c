#include <stdio.h>
#include <stdlib.h>
#include "financeiro.h"

void modulo_financeiro(void){
    char opcao;
    do {
        opcao = tela_financeiro();
        switch(opcao){
            case '1':
            registrar_despesa();
                break;
            case '2':
            registrar_ganho();
                break;
            case '3':
            consultar_financas();
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
    printf("============================================\n");
    printf("       Você está no Módulo Financeiro       \n");
    printf("============================================\n");
    printf("   [1] - Registrar Nova Despesa             \n");
    printf("   [2] - Visualizar Saldo Atual             \n");
    printf("   [3] - Registrar Novo Ganho/Lucro         \n");
    printf("   [4] - Gerar Relatório Financeiro         \n");
    printf("   [0] - Voltar ao Menu Principal           \n");
    printf("============================================\n");
    printf("   Por favor, selecione uma opção: \n");

    scanf("%c",&op);
    getchar();
    system("clear");
    return op;
}

// SUBMODULOS FINANCEIRO
void registrar_despesa(void){
    printf("===========================================\n");
    printf("            Registrar Nova Despesa             \n");
    printf("==========================================\n");
    printf("\n      Descrição da despesa: ");
    printf("\n      Valor: ");
    printf("Pressione Qualquer tecla para Continuar!!!\n");
    getchar();
    system("clear");
}
void registrar_ganho(void){
    printf("===========================================\n");
    printf("              Registrar novo Ganho/lucro        \n");
    printf("==========================================\n");
    printf("\n      Descrição do ganho: ");
    printf("\n      Valor: ");
    printf("Pressione Qualquer tecla para Continuar!!!\n");
    getchar();
    system("clear");
}
void saldo_atual(void){
    printf("===========================================\n");
    printf("            Visualizar Saldo Atual           \n");
    printf("==========================================\n");
    printf("\n      Saldo atual: ");
    printf("Pressione Qualquer tecla para Continuar!!!\n");
    getchar();
    system("clear");
}
void relatorio_financeiro(void){
    printf("===========================================\n");
    printf("              Relatório Financeiro               \n");
    printf("==========================================\n");
    printf("\n      Relatório Completo: ");
    printf("Pressione Qualquer tecla para Continuar!!!\n");
    getchar();
    system("clear");
}