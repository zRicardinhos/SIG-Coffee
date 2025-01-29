#ifndef CLIENTES_H
#define CLIENTES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOME2 55
#define MAX_EMAIL 55
#define MAX_CPF 12
#define MAX_CEL 15
#define MAX_DATA_NASC 11

typedef struct {
    char nome[MAX_NOME2];
    char email[MAX_EMAIL];
    char cpf[MAX_CPF];
    char celular[MAX_CEL];
    char data_nasc[MAX_DATA_NASC];
    int ativo;
} Cliente;

// Protótipos das funções públicas
void modulo_clientes(void);
char tela_clientes(void);
void cadastrar_cliente(void);
void consultar_cliente(void);
void atualizar_cliente(void);
void desativar_cliente(void);
void relatorio_clientes(void);

// Funções auxiliares
Cliente* buscar_cliente(const char *cpf);
void formatar_cpf(const char *cpf, char *formatado, size_t tamanho);
void formatar_celular(const char *celular, char *formatado, size_t tamanho);
int comparar_clientes(const void *a, const void *b);

// Utilitários
void remover_nova_linha(char *str);
void limpar_buffer(void);

#endif // CLIENTES_H