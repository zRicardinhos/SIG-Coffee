#include <stdio.h>
#include <stdlib.h>
#include "src/modules/clientes/clientes.h"
#include "src/modules/funcionarios/funcionarios.h"
#include "src/modules/comidas/comidas.h"
#include "src/modules/financeiro/financeiro.h"
#include "src/modules/pedidos/pedidos.h"
/// Assinatura das funções
char tela_inicial(void);
void info(void);

/// Função Principal
int main(void)
{
    char opcao;
    do {
        opcao = tela_inicial();
        switch(opcao){
            case '1':
            modulo_clientes();
                break;
            case '2':
            modulo_comidas();
                break;
            case '3':
            modulo_funcionarios();
                break;
            case '4':
            modulo_financeiro();
                break;
            case '5':
            pedidos();
                break;
            case '6':
            info();
                break;
        }
    }
    while(opcao != '0');
    return 0;
}

/// tela principal
char tela_inicial(void){
    char op;
    // A barra esta alinhada, esta deste jeito por causa do emoji
    printf("╔═══════════════════════════════════════════╗\n");
    printf("║              ☕ SIG-Coffee ☕             ║\n");
    printf("╠═══════════════════════════════════════════╣\n");
    printf("║        [1] - Módulo Clientes              ║\n");
    printf("║        [2] - Módulo Cafés/Lanches         ║\n");
    printf("║        [3] - Módulo Funcionários          ║\n");
    printf("║        [4] - Módulo Financeiro            ║\n");
    printf("║        [5] - Pedidos                      ║\n");
    printf("║        [6] - Módulo Informações           ║\n");
    printf("║        [0] - Sair                         ║\n");
    printf("╚═══════════════════════════════════════════╝\n");
    printf("     🌟 Por favor, selecione uma opção 🌟:  \n");
    
    scanf("%c",&op);
    getchar();
    system("clear");
    return op;
}
void info(void){
    printf("╔═══════════════════════════════════════════╗\n");
    printf("║     Você está no Módulo Informações  ℹ️    ║\n");
    printf("╠═══════════════════════════════════════════╣\n");
    printf("║     Projeto de Gestão de uma Cafeteria    ║\n");
    printf("║      Equipe de desenvolvimento:           ║\n");
    printf("║      Ricardo Addario @zRicardinhos        ║\n");
    printf("║      Licença Pública Geral GNU            ║\n");
    printf("║      www.gnu.org/licenses/gpl.html        ║\n");
    printf("╚═══════════════════════════════════════════╝\n");
    printf("🌟 Pressione Qualquer tecla para Continuar 🌟\n");
    getchar();
    system("clear");
}