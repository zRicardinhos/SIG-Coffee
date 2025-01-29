#include "funcionarios.h"
#include <strings.h>

void modulo_funcionarios(void) {
    char opcao;
    do {
        opcao = tela_funcionarios();
        switch(opcao) {
            case '1': cadastrar_funcionario(); break;
            case '2': consultar_funcionario(); break;
            case '3': atualizar_funcionario(); break;
            case '4': desativar_funcionario(); break;
            case '5': relatorio_funcionarios(); break;
        }
    } while(opcao != '0');
}

char tela_funcionarios(void) {
    char op;
    limpar_tela();
    printf("╔═══════════════════════════════════════════╗\n");
    printf("║          MÓDULO FUNCIONÁRIOS 👔           ║\n");
    printf("╠═══════════════════════════════════════════╣\n");
    printf("║ [1] Cadastrar Funcionário                 ║\n");
    printf("║ [2] Consultar Funcionário                 ║\n");
    printf("║ [3] Atualizar Funcionário                 ║\n");
    printf("║ [4] Desativar Funcionário                 ║\n");
    printf("║ [5] Relatório de Funcionários             ║\n");
    printf("║ [0] Voltar                                ║\n");
    printf("╚═══════════════════════════════════════════╝\n");
    printf("     🌟 Selecione uma opção: ");
    
    scanf("%c", &op);
    limpar_buffer();
    system("clear");
    return op;
}

void salvar_funcionario(Funcionario *f) {
    FILE *fp = fopen("data/funcionarios.dat", "ab");
    if (fp == NULL) {
        printf("❌ Erro ao abrir arquivo de funcionários!\n");
        return;
    }
    fwrite(f, sizeof(Funcionario), 1, fp);
    fclose(fp);
}

Funcionario* buscar_funcionario(const char *cpf) {
    static Funcionario f;
    FILE *fp = fopen("data/funcionarios.dat", "rb");
    if (fp == NULL) return NULL;

    while (fread(&f, sizeof(Funcionario), 1, fp)) {
        if (strcmp(f.cpf, cpf) == 0 && f.ativo) {
            fclose(fp);
            return &f;
        }
    }
    fclose(fp);
    return NULL;
}

void cadastrar_funcionario(void) {
    Funcionario novo;
    memset(&novo, 0, sizeof(Funcionario));
    
    limpar_tela();
    printf("╔═══════════════════════════════════════════╗\n");
    printf("║         CADASTRO DE FUNCIONÁRIO           ║\n");
    printf("╠═══════════════════════════════════════════╣\n");

    // Validação de CPF
    do {
        printf(" CPF (somente números): ");
        fgets(novo.cpf, MAX_CPF, stdin);
        remover_nova_linha(novo.cpf);
        if (buscar_funcionario(novo.cpf) != NULL) {
            printf("⚠️  CPF já cadastrado!\n");
        }
    } while (!validar_cpf(novo.cpf) || buscar_funcionario(novo.cpf) != NULL);
    limpar_buffer();
    // Dados pessoais
    printf(" Nome completo: ");
    fgets(novo.nome, MAX_NOME2, stdin);
    remover_nova_linha(novo.nome);

    // Validação de e-mail
    do {
        printf(" E-mail: ");
        fgets(novo.email, MAX_EMAIL, stdin);
        remover_nova_linha(novo.email);
    } while (!validar_email(novo.email));

    // Validação de celular
    do {
        printf(" Celular (com DDD): ");
        fgets(novo.celular, MAX_CEL, stdin);
        remover_nova_linha(novo.celular);
    } while (!validar_telefone(novo.celular));

    printf(" Cargo: ");
    fgets(novo.cargo, MAX_CARGO, stdin);
    remover_nova_linha(novo.cargo);

    novo.ativo = 1;
    salvar_funcionario(&novo);
    printf("\n✅ Funcionário cadastrado com sucesso!\n");
    pausar();
}

void consultar_funcionario(void) {
    limpar_tela();
    char cpf[MAX_CPF];
    printf("╔═══════════════════════════════════════════╗\n");
    printf("║         CONSULTA DE FUNCIONÁRIO           ║\n");
    printf("╠═══════════════════════════════════════════╣\n");
    
    printf(" CPF do funcionário: ");
    fgets(cpf, MAX_CPF, stdin);
    remover_nova_linha(cpf);

    Funcionario *f = buscar_funcionario(cpf);
    if (f == NULL) {
        printf("❌ Funcionário não encontrado!\n");
    } else {
        printf("\n╔═══════════════════════════════════════════╗\n");
        printf("║               DETALHES                    ║\n");
        printf("╠═══════════════════════════════════════════╣\n");
        printf(" Nome: %s\n", f->nome);
        printf(" CPF: %s\n", f->cpf);
        printf(" E-mail: %s\n", f->email);
        printf(" Celular: %s\n", f->celular);
        printf(" Cargo: %s\n", f->cargo);
        printf("╚═══════════════════════════════════════════╝\n");
    }
    pausar();
}

void atualizar_funcionario(void) {
    limpar_tela();
    char cpf[MAX_CPF];
    printf("╔═══════════════════════════════════════════╗\n");
    printf("║         ATUALIZAR FUNCIONÁRIO             ║\n");
    printf("╠═══════════════════════════════════════════╣\n");
    
    printf(" CPF do funcionário: ");
    fgets(cpf, MAX_CPF, stdin);
    remover_nova_linha(cpf);

    FILE *fp = fopen("data/funcionarios.dat", "r+b");
    if (fp == NULL) {
        printf("❌ Erro ao abrir arquivo!\n");
        pausar();
        return;
    }

    Funcionario f;
    int encontrado = 0;
    while (fread(&f, sizeof(Funcionario), 1, fp)) {
        if (strcmp(f.cpf, cpf) == 0 && f.ativo) {
            printf("\nNovo e-mail (atual: %s): ", f.email);
            fgets(f.email, MAX_EMAIL, stdin);
            remover_nova_linha(f.email);

            printf(" Novo celular (atual: %s): ", f.celular);
            fgets(f.celular, MAX_CEL, stdin);
            remover_nova_linha(f.celular);

            printf(" Novo cargo (atual: %s): ", f.cargo);
            fgets(f.cargo, MAX_CARGO, stdin);
            remover_nova_linha(f.cargo);

            fseek(fp, -sizeof(Funcionario), SEEK_CUR);
            fwrite(&f, sizeof(Funcionario), 1, fp);
            encontrado = 1;
            break;
        }
    }
    fclose(fp);

    printf(encontrado ? "✅ Funcionário atualizado!\n" : "❌ Funcionário não encontrado!\n");
    pausar();
}

void desativar_funcionario(void) {
    limpar_tela();
    char cpf[MAX_CPF];
    printf("╔═══════════════════════════════════════════╗\n");
    printf("║         DESATIVAR FUNCIONÁRIO             ║\n");
    printf("╠═══════════════════════════════════════════╣\n");
    
    printf(" CPF do funcionário: ");
    fgets(cpf, MAX_CPF, stdin);
    remover_nova_linha(cpf);

    FILE *fp = fopen("data/funcionarios.dat", "r+b");
    if (fp == NULL) {
        printf("❌ Erro ao abrir arquivo!\n");
        pausar();
        return;
    }

    Funcionario f;
    int encontrado = 0;
    while (fread(&f, sizeof(Funcionario), 1, fp)) {
        if (strcmp(f.cpf, cpf) == 0 && f.ativo) {
            f.ativo = 0;
            fseek(fp, -sizeof(Funcionario), SEEK_CUR);
            fwrite(&f, sizeof(Funcionario), 1, fp);
            encontrado = 1;
            break;
        }
    }
    fclose(fp);

    printf(encontrado ? "✅ Funcionário desativado!\n" : "❌ Funcionário não encontrado!\n");
    pausar();
}

void listar_funcionarios_ativos(void) {
    FILE *fp = fopen("data/funcionarios.dat", "rb");
    if (fp == NULL) {
        printf("ℹ️  Nenhum funcionário cadastrado!\n");
        return;
    }

    Funcionario f;
    printf("\n╔══════════════════════════════════════════════════════════════════╗\n");
    printf("║ %-20s %-15s %-16s %-10s ║\n", "Nome", "CPF", "Cargo", "Contato");
    printf("╠══════════════════════════════════════════════════════════════════╣\n");
    
    while (fread(&f, sizeof(Funcionario), 1, fp)) {
        if (f.ativo) {
            printf("║ %-18.18s %-17.17s %-15s %-11.11s ║\n",
                   f.nome,
                   f.cpf,
                   f.cargo,
                   f.celular);
        }
    }
    printf("╚══════════════════════════════════════════════════════════════════╝\n");
    fclose(fp);
}

void relatorio_funcionarios(void) {
    limpar_tela();
    printf("╔═══════════════════════════════════════════╗\n");
    printf("║       RELATÓRIO DE FUNCIONÁRIOS           ║\n");
    printf("╠═══════════════════════════════════════════╣\n");
    listar_funcionarios_ativos();
    pausar();
}