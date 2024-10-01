#include <stdio.h>
#include <stdlib.h>

/// Declarando func  
void tela_inicial(void);
void tela_clientes(void);
void tela_comidas(void);
void tela_funcionarios(void);
void tela_financeiro(void);
void info(void);

/// Func Principal
int main(void)
{
    tela_inicial();
    tela_clientes();
    tela_comidas();
    tela_funcionarios();
    tela_financeiro();
    info();

    return 0;
}

/// Funcoes
void tela_inicial(void){
    printf("===========================================\n");
    printf("                SIG-Coffee                 \n");
    printf("==========================================\n");
    printf("      1 - Módulo Clientes      \n");
    printf("      2 - Módulo Cafés/Lanches \n");
    printf("      3 - Módulo Funcionários  \n");
    printf("      4 - Módulo Financeiro    \n");
    printf("      5 - Módulo Informações   \n");
    printf("      0 - Sair                 \n");
    printf("Pressione Qualquer tecla para Continuar!!!\n");
    getchar();
    system("clear");
}
void tela_clientes(void){
    printf("============================================\n");
    printf("         Você está no Módulo Clientes       \n");
    printf("============================================\n");
    printf("      1 - Cadastrar Clientes      \n");
    printf("      2 - Consultar Cliente       \n");
    printf("      3 - Atualizar Cliente       \n");
    printf("      4 - Desativar Cliente       \n");
    printf("      5 - Relatório de Clientes   \n");
    printf("      0 - Voltar                  \n");
    printf("============================================\n");
    printf("Pressione Qualquer tecla para Continuar!!!\n");
    getchar();
    system("clear");
}
void tela_comidas(void){
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
    printf("Pressione Qualquer tecla para Continuar!!!\n");
    getchar();
    system("clear");
}
void tela_funcionarios(void){
    printf("============================================\n");
    printf("       Você está no Módulo Funcionários     \n");
    printf("============================================\n");
    printf("      1 - Cadastrar Funcionário         \n");
    printf("      2 - Consultar Funcionários         \n");
    printf("      3 - Atualizar Funcionário         \n");
    printf("      4 - Remover Funcionário           \n");
    printf("      5 - Relatório de Funcionários     \n");
    printf("      0 - Voltar                        \n");
    printf("============================================\n");
    printf("Pressione Qualquer tecla para Continuar!!!\n");
    getchar();
    system("clear");
}
void tela_financeiro(void){
    printf("============================================\n");
    printf("       Você está no Módulo Financeiro       \n");
    printf("============================================\n");
    printf("      1 - Registrar Despesa           \n");
    printf("      2 - Consultar Finanças          \n");
    printf("      1 - Registrar Ganho           \n");
    printf("      4 - Relatorio Financeiro        \n");
    printf("      5 - Submódulo Vendas            \n");
    printf("      0 - Voltar                      \n");
    printf("============================================\n");
    printf("Pressione Qualquer tecla para Continuar!!!\n");
    getchar();
    system("clear");
}
void info(void){
    printf("============================================\n");
    printf("      Você está no Módulo Informações       \n");
    printf("============================================\n");
    printf("      Projeto de Gestão de uma Cafeteria    \n");
    printf("      Equipe de desenvolvimento:            \n");
    printf("      Ricardo Addario @zRicardinhos         \n");
    printf("      Licença Pública Geral GNU             \n");
    printf("      www.gnu.org/licenses/gpl.html         \n");
    printf("Pressione Qualquer tecla para Continuar!!!\n");
    getchar();
    system("clear");
}