////// Assinaturas das funções Módulo Funcionarios e typedef

typedef struct {
    char nome[55];
    char email[55];
    char cpf[12];
    char celular[15];
    char cargo[30];
    int ativo;
} Funcionario;

void modulo_funcionarios(void);
char tela_funcionarios(void);
void cadastrar_funcionario(void);
void consultar_funcionario(void);
void atualizar_funcionario(void);
void desativar_funcionario(void);