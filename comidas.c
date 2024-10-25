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
    printf("╔═══════════════════════════════════════════╗\n");
    printf("║      Você está no Módulo Cafés/Lanches ☕ ║\n");
    printf("╠═══════════════════════════════════════════╣\n");
    printf("║      [1] - Cadastrar Tipo de Café         ║\n");
    printf("║      [2] - Consultar Cafés                ║\n");
    printf("║      [3] - Atualizar Café                 ║\n");
    printf("║      [4] - Remover Café                   ║\n");
    printf("║      [5] - Lanches                        ║\n");
    printf("║      [0] - Voltar                         ║\n");
    printf("╚═══════════════════════════════════════════╝\n");
    printf("     🌟 Por favor, selecione uma opção 🌟:   \n");
    
    scanf("%c",&op);
    getchar();
    system("clear");
    return op;
}

//SUB TELAS CAFES/LANCHES
void cadastrar_cafe(void){
    printf("╔═══════════════════════════════════════════╗\n");
    printf("║              Cadastro de Cafe             ║\n");
    printf("╚═══════════════════════════════════════════╝\n");
    printf("      Nome do Café: \n");
    printf("      Tipo de Torra (Claro, Médio, Escuro): \n");
    printf("      Origem do Café: \n");
    printf("      Moagem (Grossa, Média, Fina): \n");
    printf("Pressione Qualquer tecla para Continuar!!!\n");
    getchar();
    system("clear");
}
void consultar_cafe(void){
    printf("╔═══════════════════════════════════════════╗\n");
    printf("║              Consulta de Cafe             ║\n");
    printf("╚═══════════════════════════════════════════╝\n");
    printf("      Nome ou ID do Café: \n");
    printf("Pressione Qualquer tecla para Continuar!!!\n");
    getchar();
    system("clear");
}
void atualizar_cafe(void){
    printf("╔═══════════════════════════════════════════╗\n");
    printf("║              Atualizar Cafe               ║\n");
    printf("╚═══════════════════════════════════════════╝\n");
    printf("      Nome ou ID do Café: \n");
    printf("      Novas Informações: \n");
    printf("Pressione Qualquer tecla para Continuar!!!\n");
    getchar();
    system("clear");
}
void remover_cafe(void){
    printf("╔═══════════════════════════════════════════╗\n");
    printf("║                Remover Cafe               ║\n");
    printf("╚═══════════════════════════════════════════╝\n");
    printf("      Nome ou ID do Café: \n");
    printf("Pressione Qualquer tecla para Continuar!!!\n");
    getchar();
    system("clear");
}
void submodulo_lanches(void){
    printf("╔═══════════════════════════════════════════╗\n");
    printf("║                  Lanches                  ║\n");
    printf("╚═══════════════════════════════════════════╝\n");
    printf("      1 - Cadastrar Lanche: \n");
    printf("      2 - Atualizar Lanche: \n");
    printf("      3 - Remover Lanche:   \n");
    printf("      4 - Consultar Lanche: \n");
    printf("Pressione Qualquer tecla para Continuar!!!\n");
    getchar();
    system("clear");
}