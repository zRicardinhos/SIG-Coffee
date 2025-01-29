#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "../utils/validacoes.h"
#include "../utils/interface.h"
#include "clientes.h"

//Tela clientes
char tela_clientes(void){
    char op;
    printf("╔═══════════════════════════════════════════╗\n");
    printf("║        Você está no Módulo Clientes 👥    ║\n");
    printf("╠═══════════════════════════════════════════╣\n");
    printf("║      [1] - Cadastrar Clientes             ║\n");
    printf("║      [2] - Consultar Cliente              ║\n");
    printf("║      [3] - Atualizar Cliente              ║\n");
    printf("║      [4] - Desativar Cliente              ║\n");
    printf("║      [5] - Relatório de Clientes          ║\n");
    printf("║      [0] - Voltar                         ║\n");
    printf("╚═══════════════════════════════════════════╝\n");
    printf("     🌟 Por favor, selecione uma opção 🌟:   \n");
    
    scanf("%c",&op);
    getchar();
    system("clear");
    return op;
}

//funcoes do modulo clientes
void modulo_clientes(void){
    char opcao;
    do {
        opcao = tela_clientes();
        switch(opcao){
            case '1':
            cadastrar_cliente();
                break;
            case '2':
            consultar_cliente();
                break;
            case '3':
            atualizar_cliente();
                break;
            case '4':
            desativar_cliente();
                break;
            case '5':
            relatorio_clientes();
        }
    }
    while(opcao != '0');
}

// Função para salvar cliente no arquivo
void salvar_cliente(Cliente *c) {
    FILE *fp = fopen("data/clientes.dat", "ab");
    if (fp == NULL) {
        printf("Erro ao abrir arquivo de clientes!\n");
        return;
    }
    fwrite(c, sizeof(Cliente), 1, fp);
    fclose(fp);
}

// Função para buscar cliente por CPF
Cliente* buscar_cliente(const char *cpf) {
    FILE *fp = fopen("data/clientes.dat", "rb");
    if (fp == NULL) return NULL;

    static Cliente c;
    while (fread(&c, sizeof(Cliente), 1, fp)) {
        if (strcmp(c.cpf, cpf) == 0 && c.ativo) {
            fclose(fp);
            return &c;
        }
    }
    fclose(fp);
    return NULL;
}

// Função para cadastrar cliente
void cadastrar_cliente(void) {
    Cliente c;
    limpar_tela();
    printf("╔═══════════════════════════════════════════╗\n");
    printf("║              Cadastro de Cliente          ║\n");
    printf("╚═══════════════════════════════════════════╝\n");

    // Validação de CPF
    do {
        printf(" CPF (somente números): ");
        fgets(c.cpf, 12, stdin);
        remover_nova_linha(c.email);
        if (buscar_cliente(c.cpf) != NULL) {
            printf("❌ CPF já cadastrado!\n");
            c.cpf[0] = '\0'; // Força nova tentativa
        }
    } while (!validar_cpf(c.cpf));
    
    limpar_buffer();

    // Validação de e-mail
    do {
        printf(" E-mail: ");
        fgets(c.email, 55, stdin);
        remover_nova_linha(c.email);
    } while (!validar_email(c.email));

    // Validação de telefone
    do {
        printf(" Celular (somente números): ");
        fgets(c.celular, 15, stdin);
        remover_nova_linha(c.celular);
    } while (!validar_telefone(c.celular));

    // Coleta de nome e data de nascimento
    printf(" Nome completo: ");
    fgets(c.nome, 55, stdin);
    remover_nova_linha(c.nome);

    printf(" Data de nascimento (DD/MM/AAAA): ");
    fgets(c.data_nasc, 11, stdin);
    remover_nova_linha(c.data_nasc);

    c.ativo = 1; // Cliente ativo por padrão
    salvar_cliente(&c);
    printf("✅ Cliente cadastrado com sucesso!\n");
    pausar();
}

// Função para consultar cliente
void consultar_cliente(void) {
    char cpf[12];
    limpar_tela();
    printf("╔═══════════════════════════════════════════╗\n");
    printf("║            Consultar Cliente              ║\n");
    printf("╚═══════════════════════════════════════════╝\n");

    printf(" CPF do cliente: ");
    fgets(cpf, 12, stdin);
    remover_nova_linha(cpf);

    Cliente *c = buscar_cliente(cpf);
    if (c == NULL) {
        printf("❌ Cliente não encontrado!\n");
    } else {
        printf("\nDados do Cliente:\n");
        printf(" Nome: %s\n", c->nome);
        printf(" CPF: %s\n", c->cpf);
        printf(" Celular: %s\n", c->celular);
        printf(" E-mail: %s\n", c->email);
        printf(" Data de Nascimento: %s\n", c->data_nasc);
        pausar();
        limpar_tela();
    }
}


// Função para atualizar cliente
void atualizar_cliente(void) {
    char cpf[12];
    limpar_tela();
    printf("\n╔═══════════════════════════════════════════╗\n");
    printf("║              Atualizar Cliente            ║\n");
    printf("╚═══════════════════════════════════════════╝\n\n");

    printf(" CPF do cliente: ");
    fgets(cpf, 12, stdin);
    remover_nova_linha(cpf);

    FILE *fp = fopen("data/clientes.dat", "r+b");
    if (fp == NULL) {
        printf("❌ Erro ao abrir arquivo de clientes!\n");
        pausar();
        return;
    }

    Cliente c;
    int encontrado = 0;
    limpar_buffer();
    while (fread(&c, sizeof(Cliente), 1, fp)) {
        if (strcmp(c.cpf, cpf) == 0 && c.ativo) {
            encontrado = 1;
            printf("\nDados atuais:\n");
            printf(" Nome: %s\n", c.nome);
            printf(" Celular: %s\n", c.celular);
            printf(" E-mail: %s\n", c.email);
            printf(" Data de Nascimento: %s\n", c.data_nasc);

            printf("\nNovos dados (deixe em branco para manter o atual):\n");
            
            char novo_nome[55];
            printf(" Novo nome: ");
            fgets(novo_nome, 55, stdin);
            remover_nova_linha(novo_nome);
            if (strlen(novo_nome) > 0) strcpy(c.nome, novo_nome);

            char novo_celular[15];
            printf(" Novo celular: ");
            fgets(novo_celular, 15, stdin);
            remover_nova_linha(novo_celular);
            if (strlen(novo_celular) > 0) strcpy(c.celular, novo_celular);

            char novo_email[55];
            do{
                printf(" Novo e-mail: ");
                fgets(novo_email, 55, stdin);
                remover_nova_linha(novo_email);
                if (strlen(novo_email) > 0) strcpy(c.email, novo_email);
            } while (!validar_email(novo_email) && strlen(novo_email)> 0);
            if (strlen(novo_email) > 0) strcpy(c.email, novo_email);

            char nova_data_nasc[11];
            printf(" Nova data de nascimento: ");
            fgets(nova_data_nasc, 11, stdin);
            remover_nova_linha(nova_data_nasc);
            if (strlen(nova_data_nasc) > 0) strcpy(c.data_nasc, nova_data_nasc);

            // Volta para a posição correta no arquivo e reescreve o registro
            fseek(fp, -sizeof(Cliente), SEEK_CUR);
            fwrite(&c, sizeof(Cliente), 1, fp);
            printf("✅ Cliente atualizado com sucesso!\n");
            break;
        }
    }
    
    if (!encontrado) {
        printf("❌ Cliente não encontrado!\n");
    }

    fclose(fp);
    pausar();
    limpar_tela();
}

// Função para desativar cliente
void desativar_cliente(void) {
    char cpf[12];
    limpar_tela();
    printf("╔═══════════════════════════════════════════╗\n");
    printf("║              Desativar Cliente            ║\n");
    printf("╚═══════════════════════════════════════════╝\n");

    printf(" CPF do cliente: ");
    fgets(cpf, 12, stdin);
    remover_nova_linha(cpf);

    Cliente *c = buscar_cliente(cpf);
    if (c == NULL) {
        printf("❌ Cliente não encontrado!\n");
        pausar();
        limpar_tela();
        return;
    }

    c->ativo = 0;
    salvar_cliente(c);
    printf("✅ Cliente desativado com sucesso!\n");
    pausar();
}
// Função para gerar relatório de clientes
void relatorio_clientes(void) {
    FILE *fp = fopen("data/clientes.dat", "rb");
    if (fp == NULL) {
        // Verifica se o erro foi devido à ausência do arquivo
        if (errno == ENOENT) {
            printf("ℹ️  Nenhum cliente cadastrado!\n");
        } else {
            printf("❌ Erro ao abrir arquivo de clientes: %s\n", strerror(errno));
        }
        pausar();
        return;
    }

    // Lê todos os clientes ativos para memória
    Cliente *clientes = NULL;
    Cliente c;
    int count = 0;
    size_t capacidade = 10;

    clientes = malloc(sizeof(Cliente) * capacidade);
    if (clientes == NULL) {
        printf("❌ Erro de alocação de memória!\n");
        fclose(fp);
        pausar();
        return;
    }

    while (fread(&c, sizeof(Cliente), 1, fp)) {
        if (c.ativo) {
            // Redimensiona array se necessário
            if (count >= capacidade) {
                capacidade *= 2;
                Cliente *temp = realloc(clientes, sizeof(Cliente) * capacidade);
                if (temp == NULL) {
                    printf("❌ Erro ao realocar memória!\n");
                    free(clientes);
                    fclose(fp);
                    pausar();
                    return;
                }
                clientes = temp;
            }
            clientes[count++] = c;
        }
    }
    fclose(fp);

    // Ordena clientes por nome
    qsort(clientes, count, sizeof(Cliente), comparar_clientes);

    limpar_tela();
    printf("╔═════════════════════════════════════════════════════════════╗\n");
    printf("║                RELATÓRIO DE CLIENTES ATIVOS                 ║\n");
    printf("╠════════════════════╦═══════════════════╦════════════════════╣\n");
    printf("║ Nome               ║ CPF               ║ Celular            ║\n");
    printf("╠════════════════════╬═══════════════════╬════════════════════╣\n");

    if (count == 0) {
        printf("║           Nenhum cliente encontrado           ║\n");
        printf("║                                               ║\n");
    } else {
        char cpf_formatado[15];
        char cel_formatado[15];
        
        for (int i = 0; i < count; i++) {
            formatar_cpf(clientes[i].cpf, cpf_formatado, sizeof(cpf_formatado));
            formatar_celular(clientes[i].celular, cel_formatado, sizeof(cel_formatado));
            
            printf("║ %-18.18s ║ %-15.15s   ║ %-18.18s ║\n",
                   clientes[i].nome,
                   cpf_formatado,
                   cel_formatado);
            printf("╠════════════════════╬═══════════════════╬════════════════════╣\n");
        }
    }

    printf("║ Total de clientes ativos: %-31d   ║\n", count);
    printf("╚═════════════════════════════════════════════════════════════╝\n");
    
    free(clientes);
    pausar();
}

void formatar_cpf(const char *cpf, char *formatado, size_t tamanho) {
    if (strlen(cpf) != 11) {
        snprintf(formatado, tamanho, "%s", cpf);
        return;
    }
    snprintf(formatado, tamanho, "%.3s.%.3s.%.3s-%s", cpf, cpf+3, cpf+6, cpf+9);
}

void formatar_celular(const char *celular, char *formatado, size_t tamanho) {
    if (strlen(celular) != 11) {
        snprintf(formatado, tamanho, "%s", celular);
        return;
    }
    snprintf(formatado, tamanho, "(%s)%s-%s", 
        celular, celular+2, celular+7);
}

int comparar_clientes(const void *a, const void *b) {
    const Cliente *cliA = (const Cliente *)a;
    const Cliente *cliB = (const Cliente *)b;
    return strcmp(cliA->nome, cliB->nome);
}
