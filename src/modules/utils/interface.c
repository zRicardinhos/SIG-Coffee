#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void limpar_tela(void) {
    system("clear || cls");
}

void pausar(void) {
    printf("\n🌟 Pressione ENTER para continuar...");
    getchar();
    getchar();
}

void remover_nova_linha(char *str) {
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}

void limpar_buffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}