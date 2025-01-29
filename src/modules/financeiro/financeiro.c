#include "financeiro.h"
#include <math.h>

// Função para salvar transações no arquivo
void salvar_transacao(const Transacao *t) {
    FILE *fp = fopen("data/transacoes.dat", "ab");
    if (fp == NULL) {
        printf("❌ Erro ao abrir arquivo de transações!\n");
        return;
    }
    fwrite(t, sizeof(Transacao), 1, fp);
    fclose(fp);
}

// Função para obter data atual formatada
void obter_data_atual(char *buffer) {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(buffer, "%02d/%02d/%04d", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
}

// Função para registrar despesas
void registrar_despesa(void) {
    Transacao nova;
    memset(&nova, 0, sizeof(Transacao));
    
    limpar_tela();
    printf("╔═══════════════════════════════════════════╗\n");
    printf("║          REGISTRAR NOVA DESPESA           ║\n");
    printf("╠═══════════════════════════════════════════╣\n");

    printf(" Descrição: ");
    fgets(nova.descricao, MAX_DESCRICAO, stdin);
    remover_nova_linha(nova.descricao);

    do {
        printf(" Valor: R$");
        if (scanf("%lf", &nova.valor) != 1) {
            limpar_buffer();
            printf("⚠️  Valor inválido! ");
            nova.valor = -1;
        }
    } while (nova.valor <= 0);
    limpar_buffer();

    obter_data_atual(nova.data);
    strcpy(nova.tipo, "DESPESA");
    nova.valor = fabs(nova.valor) * -1; // Garante valor negativo

    salvar_transacao(&nova);
    printf("\n✅ Despesa registrada com sucesso!\n");
    pausar();
}

// Função para registrar ganhos
void registrar_ganho(void) {
    Transacao nova;
    memset(&nova, 0, sizeof(Transacao));
    
    limpar_tela();
    printf("╔═══════════════════════════════════════════╗\n");
    printf("║           REGISTRAR NOVO GANHO            ║\n");
    printf("╠═══════════════════════════════════════════╣\n");

    printf(" Descrição: ");
    fgets(nova.descricao, MAX_DESCRICAO, stdin);
    remover_nova_linha(nova.descricao);

    do {
        printf(" Valor: R$");
        if (scanf("%lf", &nova.valor) != 1) {
            limpar_buffer();
            printf("⚠️  Valor inválido! ");
            nova.valor = -1;
        }
    } while (nova.valor <= 0);
    limpar_buffer();

    obter_data_atual(nova.data);
    strcpy(nova.tipo, "GANHO");

    salvar_transacao(&nova);
    printf("\n✅ Ganho registrado com sucesso!\n");
    pausar();
}

// Função para calcular saldo total
double calcular_saldo(void) {
    FILE *fp = fopen("data/transacoes.dat", "rb");
    if (fp == NULL) return 0.0;

    Transacao t;
    double saldo = 0.0;
    
    while (fread(&t, sizeof(Transacao), 1, fp)) {
        saldo += t.valor;
    }
    fclose(fp);
    return saldo;
}

// Função para exibir saldo atual
void saldo_atual(void) {
    limpar_tela();
    double saldo = calcular_saldo();
    
    printf("╔═══════════════════════════════════════════╗\n");
    printf("║             SALDO ATUAL                   ║\n");
    printf("╠═══════════════════════════════════════════╣\n");
    printf("   Saldo atual: R$ %.2f\n", saldo);
    printf("╚═══════════════════════════════════════════╝\n");
    pausar();
}

// Função para listar todas transações
void listar_transacoes(void) {
    FILE *fp = fopen("data/transacoes.dat", "rb");
    if (fp == NULL) {
        printf("ℹ️  Nenhuma transação registrada!\n");
        return;
    }

    Transacao t;
    printf("\n╔══════════════════════════════════════════════════════════════════╗\n");
    printf("║ %-12s %-20s %-12s %-10s          ║\n", "Data", "Descrição", "Tipo", "Valor");
    printf("╠══════════════════════════════════════════════════════════════════╣\n");
    
    while (fread(&t, sizeof(Transacao), 1, fp)) {
        printf("║ %-12s %-20s %-12s R$ %8.2f       ║\n",
               t.data,
               t.descricao,
               t.tipo,
               t.valor);
    }
    printf("╚══════════════════════════════════════════════════════════════════╝\n");
    fclose(fp);
}

// Relatório financeiro completo
void relatorio_financeiro(void) {
    limpar_tela();
    printf("╔═══════════════════════════════════════════╗\n");
    printf("║          RELATÓRIO FINANCEIRO             ║\n");
    printf("╠═══════════════════════════════════════════╣\n");
    
    listar_transacoes();
    printf("\n Saldo Total: R$ %.2f\n", calcular_saldo());
    pausar();
}

// Tela principal do módulo
void modulo_financeiro(void) {
    char opcao;
    do {
        opcao = tela_financeiro();
        switch(opcao) {
            case '1': registrar_despesa(); break;
            case '2': saldo_atual(); break;
            case '3': registrar_ganho(); break;
            case '4': relatorio_financeiro(); break;
        }
    } while(opcao != '0');
}

char tela_financeiro(void) {
    char op;
    limpar_tela();
    printf("╔═══════════════════════════════════════════╗\n");
    printf("║          MÓDULO FINANCEIRO 💰             ║\n");
    printf("╠═══════════════════════════════════════════╣\n");
    printf("║ [1] Registrar Nova Despesa                ║\n");
    printf("║ [2] Visualizar Saldo Atual                ║\n");
    printf("║ [3] Registrar Novo Ganho                  ║\n");
    printf("║ [4] Gerar Relatório Completo              ║\n");
    printf("║ [0] Voltar ao Menu Principal              ║\n");
    printf("╚═══════════════════════════════════════════╝\n");
    printf("     🌟 Selecione uma opção: ");
    
    scanf("%c", &op);
    limpar_buffer();
    system("clear");
    return op;
}