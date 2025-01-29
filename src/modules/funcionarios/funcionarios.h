////// Assinaturas das funções Módulo Funcionarios e typedef
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "../utils/validacoes.h"
#include "../utils/interface.h"

#define MAX_NOME2 55
#define MAX_EMAIL 55
#define MAX_CPF 12
#define MAX_CEL 15
#define MAX_CARGO 30

typedef struct {
    char nome[MAX_NOME2];
    char email[MAX_EMAIL];
    char cpf[MAX_CPF];
    char celular[MAX_CEL];
    char cargo[MAX_CARGO];
    int ativo;
} Funcionario;

// Protótipos das funções
void modulo_funcionarios(void);
char tela_funcionarios(void);
void cadastrar_funcionario(void);
void consultar_funcionario(void);
void atualizar_funcionario(void);
void desativar_funcionario(void);
void relatorio_funcionarios(void);

// Funções auxiliares
void salvar_funcionario(Funcionario *f);
Funcionario* buscar_funcionario(const char *cpf);
void listar_funcionarios_ativos(void);
