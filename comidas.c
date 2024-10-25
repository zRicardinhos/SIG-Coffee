#include <stdio.h>
#include <stdlib.h>
#include "comidas.h"

void modulo_comidas(void){
    char opcao;
    do {
        opcao = tela_comidas();
        switch(opcao){
            case '1':
            cadastrar_cafe();
                break;
            case '2':
            consultar_cafe();
                break;
            case '3':
            atualizar_cafe();
                break;
            case '4':
            remover_cafe();
                break;
            case '5':
            submodulo_lanches();
                break;
        }
    }
    while(opcao != '0');
}

//Tela principal
char tela_comidas(void){
    char op;
    printf("============================================\n");
    printf("       Você está no Módulo Cafés/Lanches    \n");
    printf("============================================\n");
    printf("      1 - Cadastrar Tipo de Café   \n");
    printf("      2 - Consultar Cafés          \n");
    printf("      3 - Atualizar Café           \n");
    printf("      4 - Remover Café             \n");
    printf("      5 - Submódulo Lanches        \n");
    printf("      0 - Voltar                   \n");
    printf("============================================\n");
    printf("DIGITE A OPÇAO DESEJADA !!!\n");
    scanf("%c",&op);
    getchar();
    system("clear");
    return op;
}

//SUB TELAS CAFES/LANCHES
void cadastrar_cafe(void){
    printf("===========================================\n");
    printf("              Cadastro de Café               \n");
    printf("==========================================\n");
    printf("\n      Nome do Café: ");
    printf("\n      Tipo de Torra (Claro, Médio, Escuro): ");
    printf("\n      Origem do Café: ");
    printf("\n      Moagem (Grossa, Média, Fina): ");
    printf("Pressione Qualquer tecla para Continuar!!!\n");
    getchar();
    system("clear");
}
void consultar_cafe(void){
    printf("===========================================\n");
    printf("              Consulta de Cafés               \n");
    printf("==========================================\n");
    printf("\n      Nome ou ID do Café: ");
    printf("Pressione Qualquer tecla para Continuar!!!\n");
    getchar();
    system("clear");
}
void atualizar_cafe(void){
    printf("===========================================\n");
    printf("              Atualizar Café             \n");
    printf("==========================================\n");
    printf("\n      Nome ou ID do Café: ");
    printf("\n      Novas Informações: ");
    printf("Pressione Qualquer tecla para Continuar!!!\n");
    getchar();
    system("clear");
}
void remover_cafe(void){
    printf("===========================================\n");
    printf("              Remover Café               \n");
    printf("==========================================\n");
    printf("\n      Nome ou ID do Café: ");
    printf("Pressione Qualquer tecla para Continuar!!!\n");
    getchar();
    system("clear");
}
void submodulo_lanches(void){
    printf("===========================================\n");
    printf("              Submódulo Lanches               \n");
    printf("==========================================\n");
    printf("\n      1 - Cadastrar Lanche: ");
    printf("\n      2 - Atualizar Lanche: ");
    printf("\n      3 - Remover Lanche: ");
    printf("\n      4 - Consultar Lanche: ");
    printf("Pressione Qualquer tecla para Continuar!!!\n");
    getchar();
    system("clear");
}