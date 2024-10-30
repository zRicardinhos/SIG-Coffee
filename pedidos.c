#include <stdio.h>
#include <stdlib.h>
#include "pedidos.h"

//funcoes do modulo pedidos
void pedidos(void){
    char opcao;
    do {
        opcao = tela_pedidos();
        switch(opcao){
            case '1':
            ver_pedidos();
                break;
            case '2':
            add_pedido();
                break;
            case '3':
            remover_pedido();
                break;
            case '4':
            atualizar_pedido();
                break;
            case '5':
            historico_pedidos();
                break;
        }
    }
    while(opcao != '0');
}
//Tela Pedidos
char tela_pedidos(void){
    char op;
    printf("╔═══════════════════════════════════════════╗\n");
    printf("║        Você está no Módulo Pedidos        ║\n");
    printf("╠═══════════════════════════════════════════╣\n");
    printf("║      [1] - Vizualizar Pedidos             ║\n");
    printf("║      [2] - Adicionar Pedido               ║\n");
    printf("║      [3] - Remover Pedido                 ║\n");
    printf("║      [4] - Atualizar pedido               ║\n");
    printf("║      [5] - Historico de Pedidos           ║\n");
    printf("║      [0] - Voltar                         ║\n");
    printf("╚═══════════════════════════════════════════╝\n");
    printf("     🌟 Por favor, selecione uma opção 🌟:   \n");
    
    scanf("%c",&op);
    getchar();
    system("clear");
    return op;
}
//SUB-telas pedidos
void ver_pedidos(void){
    printf("╔═══════════════════════════════════════════╗\n");
    printf("║            Vizualizar Pedidos             ║\n");
    printf("╚═══════════════════════════════════════════╝\n");
    printf("[1] - Vizualizar Todos os Pedidos Ativos \n");
    printf("[2] - Vizualizar Pedido ativo especifico \n");
    printf("Pressione [1] ou [2] para Continuar!!!\n");
    getchar();
    system("clear");
}
void add_pedido(void){
    printf("╔═══════════════════════════════════════════╗\n");
    printf("║              Adicionar Pedido             ║\n");
    printf("╚═══════════════════════════════════════════╝\n");
    printf("Pedido [ID]: \n");
    printf("Pressione Qualquer tecla para Continuar!!!\n");
    getchar();
    system("clear");
}
void remover_pedido(void){
    printf("╔═══════════════════════════════════════════╗\n");
    printf("║              Remover Pedido               ║\n");
    printf("╚═══════════════════════════════════════════╝\n");
    printf("Pedido [ID]: \n");
    printf("Pressione Qualquer tecla para Continuar!!!\n");
    getchar();
    system("clear");
}
void atualizar_pedido(void){
    printf("╔═══════════════════════════════════════════╗\n");
    printf("║              Atualizar Pedido             ║\n");
    printf("╚═══════════════════════════════════════════╝\n");
    printf("Pedido [ID]: \n");
    printf("Pressione Qualquer tecla para Continuar!!!\n");
    getchar();
    system("clear");
}
void historico_pedidos(void){
    printf("╔═══════════════════════════════════════════╗\n");
    printf("║              Historico Pedidos            ║\n");
    printf("╚═══════════════════════════════════════════╝\n");
    printf("      [1] - Vizualizar Todos os Pedidos \n");
    printf("      [2] - Vizualizar Pedido especifico \n");
    printf("Pressione [1] ou [2] para Continuar!!!\n");
    getchar();
    system("clear");
}