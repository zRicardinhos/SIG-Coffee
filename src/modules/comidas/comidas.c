#include "comidas.h"
#include "../utils/validacoes.h"
#include "../utils/interface.h"
#include <strings.h>
#include <ctype.h>

// Implementação das funções para Cafés

void salvar_cafe(Cafe *c) {
    FILE *fp = fopen("data/cafes.dat", "ab");
    if (fp == NULL) {
        printf("❌ Erro ao salvar café!\n");
        return;
    }
    fwrite(c, sizeof(Cafe), 1, fp);
    fclose(fp);
}

Cafe* buscar_cafe(const char *nome) {
    static Cafe c;
    FILE *fp = fopen("data/cafes.dat", "rb");
    if (fp == NULL) return NULL;

    while (fread(&c, sizeof(Cafe), 1, fp)) {
        if (strcasecmp(c.nome, nome) == 0 && c.ativo) {
            fclose(fp);
            return &c;
        }
    }
    fclose(fp);
    return NULL;
}

void listar_cafes(void) {
    FILE *fp = fopen("data/cafes.dat", "rb");
    if (fp == NULL) {
        printf("ℹ️  Nenhum café cadastrado!\n");
        return;
    }

    Cafe c;
    printf("\n╔══════════════════════════════════════════════════════════╗\n");
    printf("║ %-20s %-12s %-10s %-8s ║\n", "Nome", "Torra", "Origem", "Preço");
    printf("╠══════════════════════════════════════════════════════════╣\n");
    
    while (fread(&c, sizeof(Cafe), 1, fp)) {
        if (c.ativo) {
            printf("║ %-20s %-12s %-10s R$%-6.2f ║\n", 
                   c.nome, c.tipo_torra, c.origem, c.preco);
        }
    }
    printf("╚══════════════════════════════════════════════════════════╝\n");
    fclose(fp);
}

void cadastrar_cafe(void) {
    Cafe novo;
    memset(&novo, 0, sizeof(Cafe));
    
    limpar_tela();
    printf("╔═══════════════════════════════════════════╗\n");
    printf("║             CADASTRO DE CAFÉ              ║\n");
    printf("╠═══════════════════════════════════════════╣\n");

    do {
        printf(" Nome do café: ");
        fgets(novo.nome, MAX_NOME, stdin);
        remover_nova_linha(novo.nome);
    } while (buscar_cafe(novo.nome) != NULL);

    do {
        printf(" Tipo de torra (Claro/Médio/Escuro): ");
        fgets(novo.tipo_torra, MAX_TIPO, stdin);
        remover_nova_linha(novo.tipo_torra);
    } while (!validar_opcoes(novo.tipo_torra, "Claro,Médio,Escuro"));

    printf(" Origem: ");
    fgets(novo.origem, MAX_TIPO, stdin);
    remover_nova_linha(novo.origem);

    printf(" Preço: R$");
    scanf("%f", &novo.preco);
    limpar_buffer();

    novo.ativo = 1;
    salvar_cafe(&novo);
    
    printf("\n✅ Café cadastrado com sucesso!\n");
    pausar();
}

void atualizar_cafe(void) {
    limpar_tela();
    char nome[MAX_NOME];
    printf("╔═══════════════════════════════════════════╗\n");
    printf("║             ATUALIZAR CAFÉ                ║\n");
    printf("╠═══════════════════════════════════════════╣\n");
    
    printf(" Nome do café: ");
    fgets(nome, MAX_NOME, stdin);
    remover_nova_linha(nome);

    Cafe *c = buscar_cafe(nome);
    if (c == NULL) {
        printf("❌ Café não encontrado!\n");
        pausar();
        return;
    }

    printf(" Novo preço (atual: R$%.2f): ", c->preco);
    scanf("%f", &c->preco);
    limpar_buffer();

    FILE *fp = fopen("data/cafes.dat", "r+b");
    if (fp) {
        fseek(fp, -sizeof(Cafe), SEEK_CUR);
        fwrite(c, sizeof(Cafe), 1, fp);
        fclose(fp);
        printf("✅ Café atualizado!\n");
    }
    pausar();
}

void remover_cafe(void) {
    limpar_tela();
    char nome[MAX_NOME];
    printf("╔═══════════════════════════════════════════╗\n");
    printf("║              REMOVER CAFÉ                 ║\n");
    printf("╠═══════════════════════════════════════════╣\n");
    
    printf(" Nome do café: ");
    fgets(nome, MAX_NOME, stdin);
    remover_nova_linha(nome);

    FILE *fp = fopen("data/cafes.dat", "r+b");
    if (!fp) {
        printf("❌ Erro ao abrir arquivo!\n");
        pausar();
        return;
    }

    Cafe c;
    int encontrado = 0;
    while (fread(&c, sizeof(Cafe), 1, fp)) {
        if (strcasecmp(c.nome, nome) == 0 && c.ativo) {
            c.ativo = 0;
            fseek(fp, -sizeof(Cafe), SEEK_CUR);
            fwrite(&c, sizeof(Cafe), 1, fp);
            encontrado = 1;
            break;
        }
    }
    fclose(fp);

    printf(encontrado ? "✅ Café removido!\n" : "❌ Café não encontrado!\n");
    pausar();
}

// Implementação das funções para Lanches

void salvar_lanche(Lanche *l) {
    FILE *fp = fopen("data/lanches.dat", "ab");
    if (fp == NULL) {
        printf("❌ Erro ao salvar lanche!\n");
        return;
    }
    fwrite(l, sizeof(Lanche), 1, fp);
    fclose(fp);
}

Lanche* buscar_lanche(const char *nome) {
    static Lanche l;
    FILE *fp = fopen("data/lanches.dat", "rb");
    if (fp == NULL) return NULL;

    while (fread(&l, sizeof(Lanche), 1, fp)) {
        if (strcasecmp(l.nome, nome) == 0 && l.ativo) {
            fclose(fp);
            return &l;
        }
    }
    fclose(fp);
    return NULL;
}

void listar_lanches(void) {
    FILE *fp = fopen("data/lanches.dat", "rb");
    if (fp == NULL) {
        printf("ℹ️  Nenhum lanche cadastrado!\n");
        return;
    }

    Lanche l;
    printf("\n╔═══════════════════════════════════════════════════════════════╗\n");
    printf("║ %-20s %-15s %-10s %-15s ║\n", "Nome", "Categoria", "Preço", "Ingredientes");
    printf("╠═══════════════════════════════════════════════════════════════╣\n");
    
    while (fread(&l, sizeof(Lanche), 1, fp)) {
        if (l.ativo) {
            printf("║ %-20s %-15s R$%-8.2f %-15s ║\n",
                   l.nome, 
                   l.categoria,
                   l.preco,
                   l.ingredientes);
        }
    }
    printf("╚═══════════════════════════════════════════════════════════════╝\n");
    fclose(fp);
}

void cadastrar_lanche(void) {
    Lanche novo;
    memset(&novo, 0, sizeof(Lanche));
    
    limpar_tela();
    printf("╔═══════════════════════════════════════════╗\n");
    printf("║           CADASTRO DE LANCHES             ║\n");
    printf("╠═══════════════════════════════════════════╣\n");

    do {
        printf(" Nome do lanche: ");
        fgets(novo.nome, MAX_NOME, stdin);
        remover_nova_linha(novo.nome);
    } while (buscar_lanche(novo.nome) != NULL);

    do {
        printf(" Categoria (Sanduíche/Salgado/Doce): ");
        fgets(novo.categoria, MAX_TIPO, stdin);
        remover_nova_linha(novo.categoria);
    } while (!validar_opcoes(novo.categoria, "Sanduíche,Salgado,Doce"));

    printf(" Ingredientes principais: ");
    fgets(novo.ingredientes, MAX_DETALHE, stdin);
    remover_nova_linha(novo.ingredientes);

    printf(" Preço: R$");
    scanf("%f", &novo.preco);
    limpar_buffer();

    novo.ativo = 1;
    salvar_lanche(&novo);
    
    printf("\n✅ Lanche cadastrado com sucesso!\n");
    pausar();
}

void atualizar_lanche(void) {
    limpar_tela();
    char nome[MAX_NOME];
    printf("╔═══════════════════════════════════════════╗\n");
    printf("║           ATUALIZAR LANCHE                ║\n");
    printf("╠═══════════════════════════════════════════╣\n");
    
    printf(" Nome do lanche: ");
    fgets(nome, MAX_NOME, stdin);
    remover_nova_linha(nome);

    Lanche *l = buscar_lanche(nome);
    if (l == NULL) {
        printf("❌ Lanche não encontrado!\n");
        pausar();
        return;
    }

    printf(" Novo preço (atual: R$%.2f): ", l->preco);
    scanf("%f", &l->preco);
    limpar_buffer();

    printf(" Novos ingredientes: ");
    fgets(l->ingredientes, MAX_DETALHE, stdin);
    remover_nova_linha(l->ingredientes);

    FILE *fp = fopen("data/lanches.dat", "r+b");
    if (fp) {
        fseek(fp, -sizeof(Lanche), SEEK_CUR);
        fwrite(l, sizeof(Lanche), 1, fp);
        fclose(fp);
        printf("✅ Lanche atualizado!\n");
    }
    pausar();
}

void remover_lanche(void) {
    limpar_tela();
    char nome[MAX_NOME];
    printf("╔═══════════════════════════════════════════╗\n");
    printf("║             REMOVER LANCHE                ║\n");
    printf("╠═══════════════════════════════════════════╣\n");
    
    printf(" Nome do lanche: ");
    fgets(nome, MAX_NOME, stdin);
    remover_nova_linha(nome);

    FILE *fp = fopen("data/lanches.dat", "r+b");
    if (!fp) {
        printf("❌ Erro ao abrir arquivo!\n");
        pausar();
        return;
    }

    Lanche l;
    int encontrado = 0;
    while (fread(&l, sizeof(Lanche), 1, fp)) {
        if (strcasecmp(l.nome, nome) == 0 && l.ativo) {
            l.ativo = 0;
            fseek(fp, -sizeof(Lanche), SEEK_CUR);
            fwrite(&l, sizeof(Lanche), 1, fp);
            encontrado = 1;
            break;
        }
    }
    fclose(fp);

    printf(encontrado ? "✅ Lanche removido!\n" : "❌ Lanche não encontrado!\n");
    pausar();
}

// Funções do módulo principal

void modulo_comidas(void) {
    char opcao;
    do {
        opcao = tela_comidas();
        switch(opcao) {
            case '1': cadastrar_cafe(); break;
            case '2': consultar_cafe(); break;
            case '3': atualizar_cafe(); break;
            case '4': remover_cafe(); break;
            case '5': submodulo_lanches(); break;
        }
    } while(opcao != '0');
}

char tela_comidas(void) {
    char op;
    limpar_tela();
    printf("╔═══════════════════════════════════════════╗\n");
    printf("║        ☕ MÓDULO CAFÉS/LANCHES ☕         ║\n");
    printf("╠═══════════════════════════════════════════╣\n");
    printf("║ [1] Cadastrar Café                        ║\n");
    printf("║ [2] Consultar Cafés                       ║\n");
    printf("║ [3] Atualizar Café                        ║\n");
    printf("║ [4] Remover Café                          ║\n");
    printf("║ [5] Gerenciar Lanches                     ║\n");
    printf("║ [0] Voltar                                ║\n");
    printf("╚═══════════════════════════════════════════╝\n");
    printf("     🌟 Selecione uma opção: ");
    
    scanf("%c", &op);
    limpar_buffer();
    system("clear");
    return op;
}

void submodulo_lanches(void) {
    char opcao;
    do {
        limpar_tela();
        printf("╔═══════════════════════════════════════════╗\n");
        printf("║             GESTÃO DE LANCHES             ║\n");
        printf("╠═══════════════════════════════════════════╣\n");
        printf("║ [1] Cadastrar Lanche                      ║\n");
        printf("║ [2] Consultar Lanches                     ║\n");
        printf("║ [3] Atualizar Lanche                      ║\n");
        printf("║ [4] Remover Lanche                        ║\n");
        printf("║ [0] Voltar                                ║\n");
        printf("╚═══════════════════════════════════════════╝\n");
        printf("     🌟 Selecione uma opção: ");
        
        scanf("%c", &opcao);
        limpar_buffer();
        
        switch(opcao) {
            case '1': cadastrar_lanche(); break;
            case '2': listar_lanches(); pausar(); break;
            case '3': atualizar_lanche(); break;
            case '4': remover_lanche(); break;
        }
    } while(opcao != '0');
}

// Função de consulta genérica mantida para compatibilidade
void consultar_cafe(void) {
    limpar_tela();
    listar_cafes();
    pausar();
}