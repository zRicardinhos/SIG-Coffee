////// Assinaturas das funções Módulo Financeiro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include "../utils/interface.h"

#define MAX_DESCRICAO 100
#define MAX_TIPO2 15
#define MAX_DATA 11

typedef struct {
    char descricao[MAX_DESCRICAO];
    double valor;
    char tipo[MAX_TIPO2]; // "DESPESA" ou "GANHO"
    char data[MAX_DATA]; // Formato DD/MM/AAAA
} Transacao;

// Protótipos das funções principais
void modulo_financeiro(void);
char tela_financeiro(void);

// Funções de operações financeiras
void registrar_despesa(void);
void registrar_ganho(void);
void saldo_atual(void);
void relatorio_financeiro(void);

// Funções auxiliares
void salvar_transacao(const Transacao *t);
double calcular_saldo(void);
void listar_transacoes(void);
void obter_data_atual(char *buffer);
