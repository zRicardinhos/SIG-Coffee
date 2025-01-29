#ifndef COMIDAS_H
#define COMIDAS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <ctype.h>
#include "../utils/validacoes.h"
#include "../utils/interface.h"

#define MAX_NOME 30
#define MAX_TIPO 20
#define MAX_DETALHE 100

// Definições separadas para Café e Lanche
typedef struct {
    char nome[MAX_NOME + 1];
    char tipo_torra[MAX_TIPO + 1];
    char origem[MAX_TIPO + 1];
    char moagem[MAX_TIPO + 1];
    float preco;
    int ativo;
} Cafe;

typedef struct {
    char nome[MAX_NOME + 1];
    char categoria[MAX_TIPO + 1]; // Sanduíche, Salgado, Doce
    char ingredientes[MAX_DETALHE + 1];
    float preco;
    int ativo;
} Lanche;

// Tipo genérico para armazenamento
typedef union {
    Cafe cafe;
    Lanche lanche;
} ItemComida;

typedef enum { CAFE, LANCHE } TipoComida;

// Protótipos principais
void modulo_comidas(void);
char tela_comidas(void);

// Funções para Cafés
void cadastrar_cafe(void);
void consultar_cafe(void);
void atualizar_cafe(void);
void remover_cafe(void);

// Funções para Lanches
void submodulo_lanches(void);
void cadastrar_lanche(void);
void consultar_lanche(void);
void atualizar_lanche(void);
void remover_lanche(void);

// Funções auxiliares
void salvar_item(ItemComida item, TipoComida tipo);
void* buscar_item(const char *nome, TipoComida tipo);
void listar_itens(TipoComida tipo);

#endif // COMIDAS_H
