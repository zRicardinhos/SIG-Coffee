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
            case '5':
            submodulo_vendas();
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
    printf("      1 - Registrar Despesa           \n");
    printf("      2 - Consultar Finanças          \n");
    printf("      3 - Registrar Ganho           \n");
    printf("      4 - Relatório Financeiro        \n");
    printf("      5 - Submódulo Vendas            \n");
    printf("      0 - Voltar                      \n");
    printf("============================================\n");
    printf("DIGITE A OPÇAO DESEJADA !!!\n");
    scanf("%c",&op);
    getchar();
    system("clear");
    return op;
}

// SUBMODULOS FINANCEIRO
void registrar_despesa(void){
    printf("===========================================\n");
    printf("              Registrar Despesa             \n");
    printf("==========================================\n");
    printf("\n      Descrição da despesa: ");
    printf("\n      Valor: ");
    printf("Pressione Qualquer tecla para Continuar!!!\n");
    getchar();
    system("clear");
}
void registrar_ganho(void){
    printf("===========================================\n");
    printf("              Registrar Ganho               \n");
    printf("==========================================\n");
    printf("\n      Descrição do ganho: ");
    printf("\n      Valor: ");
    printf("Pressione Qualquer tecla para Continuar!!!\n");
    getchar();
    system("clear");
}
void consultar_financas(void){
    printf("===========================================\n");
    printf("              Consultar Finanças               \n");
    printf("==========================================\n");
    printf("\n      Relatório de transações: ");
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
void submodulo_vendas(void){
    printf("===========================================\n");
    printf("              Submódulo Vendas               \n");
    printf("==========================================\n");
    printf("\n      1 - Registrar Venda: ");
    printf("\n      2 - Relatório de Vendas: ");
    printf("Pressione Qualquer tecla para Continuar!!!\n");
    getchar();
    system("clear");
}
