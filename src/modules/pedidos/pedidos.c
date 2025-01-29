#include "pedidos.h"
#include "../clientes/clientes.h"
#include "../comidas/comidas.h"
#include <ctype.h>
#include <string.h>
#include <stdio.h>

// ==========================================================
// Funções auxiliares
// ==========================================================

static int gerar_novo_id() {
    FILE *fp = fopen("data/pedidos.dat", "rb");
    int id = 0;
    Pedido p;
    
    if(fp) {
        while(fread(&p, sizeof(Pedido), 1, fp)) {
            if(p.id > id) id = p.id;
        }
        fclose(fp);
    }
    return id + 1;
}

void salvar_pedido(Pedido *p) {
    FILE *fp = fopen("data/pedidos.dat", "ab");
    if(fp) {
        fwrite(p, sizeof(Pedido), 1, fp);
        fclose(fp);
    }
}

Pedido* buscar_pedido_por_id(int id) {
    static Pedido p;
    FILE *fp = fopen("data/pedidos.dat", "rb");
    
    if(fp) {
        while(fread(&p, sizeof(Pedido), 1, fp)) {
            if(p.id == id && p.ativo) {
                fclose(fp);
                return &p;
            }
        }
        fclose(fp);
    }
    return NULL;
}

void salvar_item_pedido(ItemPedido *ip) {
    FILE *fp = fopen("data/itens_pedido.dat", "ab");
    if(fp) {
        fwrite(ip, sizeof(ItemPedido), 1, fp);
        fclose(fp);
    }
}

void carregar_itens_pedido(int id_pedido) {
    FILE *fp = fopen("data/itens_pedido.dat", "rb");
    ItemPedido ip;
    
    if(fp) {
        printf("\n════════ Itens do Pedido ════════\n");
        while(fread(&ip, sizeof(ItemPedido), 1, fp)) {
            if(ip.id_pedido == id_pedido) {
                printf("▸ %-25s x%-3d R$%-7.2f\n", 
                      ip.nome_item, 
                      ip.quantidade, 
                      ip.quantidade * ip.preco_unitario);
            }
        }
        printf("══════════════════════════════════\n");
        fclose(fp);
    }
}

// ==========================================================
// Funções principais
// ==========================================================

void pedidos(void) {
    char opcao;
    do {
        opcao = tela_pedidos();
        switch(opcao) {
            case '1': ver_pedidos(); break;
            case '2': add_pedido(); break;
            case '3': remover_pedido(); break;
            case '4': atualizar_pedido(); break;
            case '5': historico_pedidos(); break;
        }
    } while(opcao != '0');
}

char tela_pedidos(void) {
    char op;
    limpar_tela();
    printf("╔═══════════════════════════════════════════╗\n");
    printf("║           GESTÃO DE PEDIDOS 🛒            ║\n");
    printf("╠═══════════════════════════════════════════╣\n");
    printf("║ 1. Ver pedidos ativos                     ║\n");
    printf("║ 2. Novo pedido                            ║\n");
    printf("║ 3. Cancelar pedido                        ║\n");
    printf("║ 4. Atualizar status                       ║\n");
    printf("║ 5. Histórico completo                     ║\n");
    printf("║ 0. Voltar                                 ║\n");
    printf("╚═══════════════════════════════════════════╝\n");
    printf("     🌟 Selecione uma opção: ");
    
    scanf("%c", &op);
    limpar_buffer();
    return op;
}

void add_pedido(void) {
    Pedido novo;
    ItemPedido item;
    char continuar;
    int item_count = 0;
    
    limpar_tela();
    printf("╔═══════════════════════════════════════════╗\n");
    printf("║          NOVO PEDIDO - CADASTRO           ║\n");
    printf("╠═══════════════════════════════════════════╣\n");

    // Gerar novo ID
    novo.id = gerar_novo_id();
    
    // Validar cliente
    do {
        printf(" CPF do cliente (somente números): ");
        fgets(novo.cpf_cliente, 12, stdin);
        remover_nova_linha(novo.cpf_cliente);
        limpar_buffer();
    } while(!validar_cpf(novo.cpf_cliente) || buscar_cliente(novo.cpf_cliente) == NULL);

    // Data atual
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
        snprintf(novo.data, 11, "%02u/%02u/%04u", 
        (unsigned int)tm.tm_mday, 
        (unsigned int)(tm.tm_mon + 1), 
        (unsigned int)(tm.tm_year + 1900));

    // Cadastro de itens
    novo.total = 0;
    do {
        printf("\n» Item %d «\n", item_count + 1);
        printf(" Nome do item: ");
        fgets(item.nome_item, 30, stdin);
        remover_nova_linha(item.nome_item);
        
        printf(" Quantidade: ");
        scanf("%d", &item.quantidade);
        limpar_buffer();
        
        printf(" Preço unitário: R$");
        scanf("%f", &item.preco_unitario);
        limpar_buffer();

        item.id_pedido = novo.id;
        novo.total += item.quantidade * item.preco_unitario;
        salvar_item_pedido(&item);
        item_count++;

        printf("\n Adicionar outro item? (s/n): ");
        scanf("%c", &continuar);
        limpar_buffer();
    } while(toupper(continuar) == 'S' && item_count < MAX_ITENS_PEDIDO);

    // Status inicial
    strcpy(novo.status, "ABERTO");
    novo.ativo = 1;
    salvar_pedido(&novo);
    
    printf("\n✅ Pedido #%d cadastrado!\nTotal: R$%.2f\n", novo.id, novo.total);
    pausar();
}

void ver_pedidos(void) {
    limpar_tela();
    printf("╔═══════════════════════════════════════════╗\n");
    printf("║          PEDIDOS ATIVOS - VISUALIZAÇÃO    ║\n");
    printf("╠═══════════════════════════════════════════╣\n");
    
    FILE *fp = fopen("data/pedidos.dat", "rb");
    if(fp) {
        Pedido p;
        printf("%-6s %-14s %-10s %-12s %-10s\n", 
              "ID", "Cliente", "Data", "Status", "Total");
        printf("═════════════════════════════════════════════════\n");
        
        while(fread(&p, sizeof(Pedido), 1, fp)) {
            if(p.ativo) {
                printf("%-6d %-14s %-10s %-12s R$%-8.2f\n", 
                      p.id, p.cpf_cliente, p.data, p.status, p.total);
                carregar_itens_pedido(p.id);
            }
        }
        fclose(fp);
    } else {
        printf(" ℹ️  Nenhum pedido ativo encontrado!\n");
    }
    pausar();
}

void remover_pedido(void) {
    limpar_tela();
    int id;
    printf("╔═══════════════════════════════════════════╗\n");
    printf("║          CANCELAMENTO DE PEDIDO           ║\n");
    printf("╠═══════════════════════════════════════════╣\n");
    
    printf(" ID do pedido: ");
    scanf("%d", &id);
    limpar_buffer();

    FILE *fp = fopen("data/pedidos.dat", "r+b");
    if(fp) {
        Pedido p;
        int encontrado = 0;
        
        while(fread(&p, sizeof(Pedido), 1, fp)) {
            if(p.id == id && p.ativo) {
                // Atualiza o status para CANCELADO
                strncpy(p.status, "CANCELADO", TAM_STATUS-1);
                p.status[TAM_STATUS-1] = '\0'; // Garante terminação nula
                p.ativo = 0; // Marca como inativo
                
                fseek(fp, -sizeof(Pedido), SEEK_CUR);
                fwrite(&p, sizeof(Pedido), 1, fp);
                encontrado = 1;
                break;
            }
        }
        fclose(fp);
        
        if(encontrado) {
            printf("\n✅ Pedido #%d cancelado com sucesso!\n", id);
        } else {
            printf("\n❌ Pedido não encontrado ou já cancelado!\n");
        }
    } else {
        printf("\n❌ Erro ao acessar os pedidos!\n");
    }
    pausar();
}
void atualizar_pedido(void) {
    limpar_tela();
    int id;
    printf("╔═══════════════════════════════════════════╗\n");
    printf("║          ATUALIZAÇÃO DE STATUS            ║\n");
    printf("╠═══════════════════════════════════════════╣\n");
    
    printf(" ID do pedido: ");
    scanf("%d", &id);
    limpar_buffer();

    Pedido *p = buscar_pedido_por_id(id);
    if(p) {
        printf("\nStatus atual: %s\n", p->status);
        printf("Novo status (ABERTO/FINALIZADO/CANCELADO): ");
        fgets(p->status, TAM_STATUS, stdin);
        remover_nova_linha(p->status);

        FILE *fp = fopen("data/pedidos.dat", "r+b");
        if(fp) {
            fseek(fp, -sizeof(Pedido), SEEK_CUR);
            fwrite(p, sizeof(Pedido), 1, fp);
            fclose(fp);
            printf("\n✅ Status atualizado com sucesso!\n");
        }
    } else {
        printf("\n❌ Pedido não encontrado!\n");
    }
    pausar();
}

void historico_pedidos(void) {
    limpar_tela();
    printf("╔═══════════════════════════════════════════╗\n");
    printf("║          HISTÓRICO COMPLETO 📜            ║\n");
    printf("╠═══════════════════════════════════════════╣\n");
    
    FILE *fp = fopen("data/pedidos.dat", "rb");
    if(fp) {
        Pedido p;
        printf("%-6s %-14s %-10s %-12s %-10s\n", 
              "ID", "Cliente", "Data", "Status", "Total");
        printf("═════════════════════════════════════════════════\n");
        
        while(fread(&p, sizeof(Pedido), 1, fp)) {
            printf("%-6d %-14s %-10s %-12s R$%-8.2f\n", 
                  p.id, p.cpf_cliente, p.data, p.status, p.total);
            carregar_itens_pedido(p.id);
        }
        fclose(fp);
    } else {
        printf("ℹ️  Nenhum pedido registrado!\n");
    }
    pausar();
}