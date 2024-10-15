#include <stdio.h>
#include <stdlib.h>

/// Assinatura das funções
void tela_inicial(void);
void tela_clientes(void);
void tela_comidas(void);
void tela_funcionarios(void);
void tela_financeiro(void);
void info(void);
void cadastrar_cliente(void);
void consultar_cliente(void);
void atualizar_cliente(void);
void desativar_cliente(void);
void cadastrar_funcionario(void);
void consultar_funcionario(void);
void atualizar_funcionario(void);
void desativar_funcionario(void);
void cadastrar_cafe(void);
void consultar_cafe(void);
void atualizar_cafe(void);
void remover_cafe(void);
void submodulo_lanches(void);
void registrar_despesa(void);
void registrar_ganho(void);
void consultar_financas(void);
void relatorio_financeiro(void);
void submodulo_vendas(void);

/// Função Principal
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

/// Funções
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
    printf("      3 - Registrar Ganho           \n");
    printf("      4 - Relatório Financeiro        \n");
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

// SUB TELAS Clientes
void cadastrar_cliente(void){
    printf("===========================================\n");
    printf("              Cadastro de Cliente               \n");
    printf("==========================================\n");
    printf("\n      Nome completo: ");
    printf("\n      Celular(Apenas numeros): ");
    printf("\n      E-mail: ");
    printf("\n      CPF: ");
    printf("\n      Data de nascimento: ");
    printf("Pressione Qualquer tecla para Continuar!!!\n");
    getchar();
    system("clear");
}
void consultar_cliente(void){
    printf("===========================================\n");
    printf("              Consulta de Cliente               \n");
    printf("==========================================\n");
    printf("\n      CPF: ");
    printf("Pressione Qualquer tecla para Continuar!!!\n");
    getchar();
    system("clear");
}
void atualizar_cliente(void){
    printf("===========================================\n");
    printf("              Atualizar Cliente               \n");
    printf("==========================================\n");
    printf("\n      CPF: ");
    printf("\n      Novas Infos: ");
    printf("Pressione Qualquer tecla para Continuar!!!\n");
    getchar();
    system("clear");
}
void desativar_cliente(void){
    printf("===========================================\n");
    printf("              Desativar Cliente               \n");
    printf("==========================================\n");
    printf("\n      CPF: ");
    printf("\n      Cliente desativado(a) com sucesso!  ");
    printf("Pressione Qualquer tecla para Continuar!!!\n");
    getchar();
    system("clear");
}
//SUB TELAS Funcionarios
void cadastrar_funcionario(void){
    printf("===========================================\n");
    printf("              Cadastro de Funcionario               \n");
    printf("==========================================\n");
    printf("\n      Nome completo: ");
    printf("\n      Celular(Apenas numeros): ");
    printf("\n      E-mail: ");
    printf("\n      CPF: ");
    printf("\n      Data de nascimento: ");
    printf("Pressione Qualquer tecla para Continuar!!!\n");
    getchar();
    system("clear");
}
void consultar_funcionario(void){
    printf("===========================================\n");
    printf("              Consulta de Funcionario            \n");
    printf("==========================================\n");
    printf("\n      CPF: ");
    printf("Pressione Qualquer tecla para Continuar!!!\n");
    getchar();
    system("clear");
}
void atualizar_funcionario(void){
    printf("===========================================\n");
    printf("              Atualizar Funcionario             \n");
    printf("==========================================\n");
    printf("\n      CPF: ");
    printf("\n      Novas Infos: ");
    printf("Pressione Qualquer tecla para Continuar!!!\n");
    getchar();
    system("clear");
}
void desativar_funcionario(void){
    printf("===========================================\n");
    printf("              Desativar Funcionario             \n");
    printf("==========================================\n");
    printf("\n      CPF: ");
    printf("Pressione Qualquer tecla para Continuar!!!\n");
    getchar();
    system("clear");
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
