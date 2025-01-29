#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../utils/interface.h"
#include "../utils/validacoes.h"

// Definições independentes
#define MAX_ITENS_PEDIDO 20
#define MAX_OBSERVACAO 100
#define TAM_STATUS 15

typedef struct {
    int id;
    char cpf_cliente[12];
    char data[11];
    float total;
    char status[TAM_STATUS];
    int ativo;
} Pedido;

typedef struct {
    int id_pedido;
    char nome_item[30];
    int quantidade;
    float preco_unitario;
} ItemPedido;

// Protótipos específicos para pedidos
void modulo_pedidos(void);
char tela_pedidos(void);
void pedidos(void);
void add_pedido(void);
void remover_pedido(void);
void atualizar_pedido(void);
void historico_pedidos(void);
void ver_pedidos(void);

// Funções auxiliares internas
void salvar_pedido(Pedido *p);
Pedido* buscar_pedido_por_id(int id);
void listar_pedidos_ativos(void);
void carregar_itens_pedido(int id_pedido);

