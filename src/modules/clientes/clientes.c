#include <stdio.h>
#include <stdlib.h>
#include "clientes.h"


//funcoes do modulo clientes
void modulo_clientes(void){
    char opcao;
    do {
        opcao = tela_clientes();
        switch(opcao){
            case '1':
            cadastrar_cliente();
                break;
            case '2':
            consultar_cliente();
                break;
            case '3':
            atualizar_cliente();
                break;
            case '4':
            desativar_cliente();
                break;
        }
    }
    while(opcao != '0');
}
//Tela clientes
char tela_clientes(void){
    char op;
    printf("╔═══════════════════════════════════════════╗\n");
    printf("║        Você está no Módulo Clientes 👥    ║\n");
    printf("╠═══════════════════════════════════════════╣\n");
    printf("║      [1] - Cadastrar Clientes             ║\n");
    printf("║      [2] - Consultar Cliente              ║\n");
    printf("║      [3] - Atualizar Cliente              ║\n");
    printf("║      [4] - Desativar Cliente              ║\n");
    printf("║      [5] - Relatório de Clientes          ║\n");
    printf("║      [0] - Voltar                         ║\n");
    printf("╚═══════════════════════════════════════════╝\n");
    printf("     🌟 Por favor, selecione uma opção 🌟:   \n");
    
    scanf("%c",&op);
    getchar();
    system("clear");
    return op;
}
//SUB-telas clientes
void cadastrar_cliente(void){
    char nome[55],email[55],cpf[12],celular[15],data_nasc[15];
    printf("╔═══════════════════════════════════════════╗\n");
    printf("║              Cadastro de Cliente          ║\n");
    printf("╚═══════════════════════════════════════════╝\n");
    printf("\n      Nome completo: ");
    fgets(nome,sizeof(nome),stdin);
    printf("\n      Celular(Apenas numeros): ");
    fgets(celular,sizeof(celular),stdin);
    printf("\n      E-mail: ");
    fgets(email,sizeof(email),stdin);
    printf("\n      CPF: ");
    fgets(cpf,sizeof(cpf),stdin);
    printf("\n      Data de nascimento: ");
    fgets(data_nasc,sizeof(data_nasc),stdin);
    printf("Pressione Qualquer tecla para Continuar!!!\n");
    getchar();
    system("clear");
}
void consultar_cliente(void){
    char cpf[12];
    printf("╔═══════════════════════════════════════════╗\n");
    printf("║              Consulta de Cliente          ║\n");
    printf("╚═══════════════════════════════════════════╝\n");
    printf("      CPF: ");
    fgets(cpf,sizeof(cpf),stdin);
    printf("\n Pressione Qualquer tecla para Continuar!!!\n");
    getchar();
    system("clear");
}
void atualizar_cliente(void){
    char cpf[12];
    printf("╔═══════════════════════════════════════════╗\n");
    printf("║              Atualizar Cliente            ║\n");
    printf("╚═══════════════════════════════════════════╝\n");
    printf("      CPF: ");
    fgets(cpf,sizeof(cpf),stdin);
    printf("\nPressione Qualquer tecla para Continuar!!!\n");
    getchar();
    system("clear");
}
void desativar_cliente(void){
    char cpf[12];
    printf("╔═══════════════════════════════════════════╗\n");
    printf("║              Desativar Cliente            ║\n");
    printf("╚═══════════════════════════════════════════╝\n");
    printf("     CPF: ");
    fgets(cpf,sizeof(cpf),stdin);
    //Exemplo
    printf("\n     Cliente desativado(a) com sucesso!  \n");
    printf("Pressione Qualquer tecla para Continuar!!!\n");
    getchar();
    system("clear");
}
