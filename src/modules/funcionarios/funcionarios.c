#include <stdio.h>
#include <stdlib.h>
#include "funcionarios.h"

//NAVEG
void modulo_funcionarios(void){
    char opcao;
    do {
        opcao = tela_funcionarios();
        switch(opcao){
            case '1':
            cadastrar_funcionario();
                break;
            case '2':
            consultar_funcionario();
                break;
            case '3':
            atualizar_funcionario();
                break;
            case '4':
            desativar_funcionario();
                break;
        }
    }
    while(opcao != '0');
}
//Tela princial
char tela_funcionarios(void){
    char op;
    printf("╔═══════════════════════════════════════════╗\n");
    printf("║       Você está no Módulo Funcionários 👔 ║\n");
    printf("╠═══════════════════════════════════════════╣\n");
    printf("║      [1] - Cadastrar Funcionário          ║\n");
    printf("║      [2] - Consultar Funcionários         ║\n");
    printf("║      [3] - Atualizar Funcionário          ║\n");
    printf("║      [4] - Remover Funcionário            ║\n");
    printf("║      [5] - Relatório de Funcionários      ║\n");
    printf("║      [0] - Voltar                         ║\n");
    printf("╚═══════════════════════════════════════════╝\n");
    printf("     🌟 Por favor, selecione uma opção 🌟:   \n");

    scanf("%c",&op);
    getchar();
    system("clear");
    return op;
}

//SUB TELAS Funcionarios
void cadastrar_funcionario(void){
    printf("╔═══════════════════════════════════════════╗\n");
    printf("║            Cadastro de Funcionario        ║\n");
    printf("╚═══════════════════════════════════════════╝\n");
    printf("      Nome completo: \n");
    printf("      Celular(Apenas numeros): \n");
    printf("      E-mail: \n");
    printf("      CPF: \n");
    printf("      Data de nascimento: \n");
    printf("Pressione Qualquer tecla para Continuar!!!\n");
    getchar();
    system("clear");
}
void consultar_funcionario(void){
    printf("╔═══════════════════════════════════════════╗\n");
    printf("║            Consulta de Funcionario        ║\n");
    printf("╚═══════════════════════════════════════════╝\n");
    printf("      CPF: \n");
    printf("Pressione Qualquer tecla para Continuar!!!\n");
    getchar();
    system("clear");
}
void atualizar_funcionario(void){
    printf("╔═══════════════════════════════════════════╗\n");
    printf("║            Atualizar funcionario          ║\n");
    printf("╚═══════════════════════════════════════════╝\n");
    printf("      CPF: \n");
    printf("      Novas Infos: \n");
    printf("Pressione Qualquer tecla para Continuar!!!\n");
    getchar();
    system("clear");
}
void desativar_funcionario(void){
    printf("╔═══════════════════════════════════════════╗\n");
    printf("║            Desativar Funcionario          ║\n");
    printf("╚═══════════════════════════════════════════╝\n");
    printf("      CPF: \n");
    printf("Pressione Qualquer tecla para Continuar!!!\n");
    getchar();
    system("clear");
}