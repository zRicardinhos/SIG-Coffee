////// Assinaturas das funções Módulo Clientes e typedef

typedef struct {
    char nome[55];
    char email[55];
    char cpf[12];
    char celular[15];
    char data_nasc[11];
    int ativo;
} Cliente;

void modulo_clientes(void);
char tela_clientes(void);
void cadastrar_cliente(void);
void consultar_cliente(void);
void atualizar_cliente(void);
void desativar_cliente(void);
// Funções auxiliares     
void remover_nova_linha(char *str);      
void limpar_buffer(void);  
void relatorio_clientes(void);
void formatar_cpf(const char *cpf, char *formatado, size_t tamanho);
void formatar_celular(const char *celular, char *formatado, size_t tamanho);
int comparar_clientes(const void *a, const void *b);
Cliente* buscar_cliente(const char *cpf);