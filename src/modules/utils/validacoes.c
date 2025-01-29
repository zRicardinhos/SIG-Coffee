#include <regex.h>
#include <ctype.h>
#include <string.h>
#include "validacoes.h"

int validar_cpf(const char *cpf) {
    int soma = 0, resto, i;
    int temp_cpf[11];

    for(i = 0; i < 11; i++) {
        if(!isdigit(cpf[i])) return 0;
        temp_cpf[i] = cpf[i] - '0';
    }

    // Verifica primeiro dígito
    for(i = 0; i < 9; i++) soma += temp_cpf[i] * (10 - i);
    resto = (soma * 10) % 11;
    if(resto == 10) resto = 0;
    if(resto != temp_cpf[9]) return 0;

    soma = 0;
    // Verifica segundo dígito
    for(i = 0; i < 10; i++) soma += temp_cpf[i] * (11 - i);
    resto = (soma * 10) % 11;
    if(resto == 10) resto = 0;
    return (resto == temp_cpf[10]);
}

int validar_email(const char *email) {
    regex_t regex;
    int reti = regcomp(&regex, "^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}$", REG_EXTENDED);
    reti = regexec(&regex, email, 0, NULL, 0);
    regfree(&regex);
    return (reti == 0);
}

int validar_telefone(const char *telefone) {
    regex_t regex;
    int reti = regcomp(&regex, "^([0-9]{2})?[0-9]{9}$", REG_EXTENDED);
    reti = regexec(&regex, telefone, 0, NULL, 0);
    regfree(&regex);
    return (reti == 0);
}