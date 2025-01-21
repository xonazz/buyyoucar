#include <stdio.h>
#include <ctype.h>  // Para isalpha
#include <string.h>  // Para manipulação de strings
#include <stdlib.h>
#include <time.h>
#include "cliente.h"



// Função para verificar se o nome é válido
int ver_nome(const char *nome) {
    // Se o nome for NULL ou vazio, retorna falso
    if (nome == NULL || nome[0] == '\0') {
        return 0;
    }

    int espacos = 0;  // Contador de espaços encontrados
    int letras = 0;   // Contador de letras válidas

    // Verificar os caracteres do nome
    for (int i = 0; nome[i] != '\0'; i++) {
        // Se o caractere for um espaço, ele é permitido
        if (nome[i] == ' ') {
            // Contabiliza o número de espaços (entre nome e sobrenome)
            espacos++;
            // Verifica se há espaços consecutivos ou se o nome começa com espaço
            if (i == 0 || nome[i-1] == ' ') {
                return 0;  // Nome inválido se começa ou tem espaços consecutivos
            }
        }
        // Verificar se é uma letra válida
        else if (isalpha(nome[i])) {
            letras++;
        }
        else {
            // Se encontrar qualquer caractere que não seja letra ou espaço, retorna inválido
            return 0;
        }
    }

    // Verificar se o nome contém pelo menos um espaço (nome e sobrenome) e que há pelo menos 2 letras
    if (espacos >= 1 && letras >= 2) {
        return 1;  // Nome válido
    }

    return 0;  // Nome inválido
} 

// Função para calcular o primeiro dígito verificador do CPF
int calcular_digito1(int cpf[]) {
    int soma = 0;
    for (int i = 0; i < 9; i++) {
        soma += cpf[i] * (10 - i);  // Multiplica os 9 primeiros números por 10, 9, ..., 2
    }
    int resto = soma % 11;
    if (resto < 2) {
        return 0;
    } else {
        return 11 - resto;
    }
}

// Função para calcular o segundo dígito verificador do CPF
int calcular_digito2(int cpf[]) {
    int soma = 0;
    for (int i = 0; i < 10; i++) {
        soma += cpf[i] * (11 - i);  // Multiplica os 10 primeiros números por 11, 10, ..., 2
    }
    int resto = soma % 11;
    if (resto < 2) {
        return 0;
    } else {
        return 11 - resto;
    }
}

// Função para verificar se o CPF é válido
int verificar_cpf(const char *cpf_str) {
    // Verifica se o CPF tem 11 caracteres e são todos dígitos
    if (strlen(cpf_str) != 11) {
        return 0;  // CPF deve ter 11 caracteres
    }
    for (int i = 0; i < 11; i++) {
        if (!isdigit(cpf_str[i])) {
            return 0;  // Se algum caractere não for número, CPF é inválido
        }
    }

    // Converte a string de CPF em um array de inteiros
    int cpf[11];
    for (int i = 0; i < 11; i++) {
        cpf[i] = cpf_str[i] - '0';  // Converte o caractere para o número inteiro correspondente
    }

    // Calcula os dígitos verificadores e os compara com os últimos dois dígitos do CPF
    int digito1 = calcular_digito1(cpf);
    int digito2 = calcular_digito2(cpf);

    if (cpf[9] == digito1 && cpf[10] == digito2) {
        return 1;  // CPF válido
    }

    return 0;  // CPF inválido
}


int validarEmail(const char *email) {
    int i = 0;
    int possuiArroba = 0;
    int possuiPonto = 0;
    int temCharAntesDoArroba = 0;
    int temCharDepoisDoArroba = 0;

    // Verifica se o e-mail é vazio
    if (email == NULL || strlen(email) == 0) {
        return 0; // Não válido
    }

    // Verifica os caracteres do e-mail
    while (email[i] != '\0') {
        if (email[i] == '@') {
            if (possuiArroba) {
                return 0; // Vários caracteres '@' não são permitidos
            }
            possuiArroba = 1;
        } else if (email[i] == '.') {
            if (possuiArroba) {
                possuiPonto = 1;
            }
        } else if (isalpha(email[i]) || isdigit(email[i]) || email[i] == '-' || email[i] == '_') {
            if (!possuiArroba) {
                temCharAntesDoArroba = 1;
            } else {
                temCharDepoisDoArroba = 1;
            }
        } else {
            return 0; // Caracteres inválidos
        }
        i++;
    }

    // Verifica se tem ao menos um caractere antes e depois do '@'
    if (!temCharAntesDoArroba || !temCharDepoisDoArroba) {
        return 0; // Não válido
    }

    // Verifica a presença do ponto após o '@'
    if (possuiArroba && !possuiPonto) {
        return 0; // Não válido
    }

    return 1; // Válido
} 

// Função para calcular o dígito verificador de uma CNH (baseado no algoritmo do CPF)
int calcularDigitoVerificador(int numero[9]) {
    int peso1[9] = {9, 8, 7, 6, 5, 4, 3, 2, 1}; // pesos para o cálculo do primeiro dígito
    int peso2[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9}; // pesos para o cálculo do segundo dígito
    int soma1 = 0, soma2 = 0;
    int i;
    
    // Cálculo do primeiro dígito verificador
    for (i = 0; i < 9; i++) {
        soma1 += numero[i] * peso1[i];
    }
    int digito1 = (soma1 % 11);
    if (digito1 == 10) digito1 = 0; // Se o resto for 10, o dígito é 0

    // Cálculo do segundo dígito verificador
    for (i = 0; i < 9; i++) {
        soma2 += numero[i] * peso2[i];
    }
    int digito2 = (soma2 % 11);
    if (digito2 == 10) digito2 = 0; // Se o resto for 10, o dígito é 0

    return digito1 * 10 + digito2; // Retorna os dois dígitos juntos
}

// Função para verificar a validade da CNH
int validarCNH(const char *cnh) {
    // Verifica o tamanho da CNH (11 caracteres)
    if (strlen(cnh) != 11) {
        return 0; // CNH inválida
    }

    // Verifica se todos os caracteres são numéricos
    for (int i = 0; i < 11; i++) {
        if (!isdigit(cnh[i])) {
            return 0; // CNH inválida
        }
    }

    // Armazena os 9 primeiros dígitos
    int numero[9];
    for (int i = 0; i < 9; i++) {
        numero[i] = cnh[i] - '0'; // Converte de char para int
    }

    // Calcula o dígito verificador e compara com os dois últimos dígitos
    int digitosCalculados = calcularDigitoVerificador(numero);
    int digitosInformados = (cnh[9] - '0') * 10 + (cnh[10] - '0');

    if (digitosCalculados == digitosInformados) {
        return 1; // CNH válida
    } else {
        return 0; // CNH inválida
    }
} 


// Função para verificar se o número de celular é válido
int validarCelular(const char *celular) {
    // Verifica se o número tem 11 dígitos
    if (strlen(celular) != 11) {
        return 0; // Celular inválido
    }

    // Verifica se os dois primeiros dígitos são numéricos (DDD)
    if (!isdigit(celular[0]) || !isdigit(celular[1])) {
        return 0; // Celular inválido
    }

    // Verifica se o terceiro dígito é 9 (obrigatório para celulares)
    if (celular[2] != '9') {
        return 0; // Celular inválido
    }

    // Verifica se os outros 8 dígitos são numéricos
    for (int i = 3; i < 11; i++) {
        if (!isdigit(celular[i])) {
            return 0; // Celular inválido
        }
    }

    return 1; // Celular válido
} 

///-/---------- Validações do veículo -------------------- ////

int verificarPlacaValida(const char *placa) {
    // A placa deve ter exatamente 7 caracteres
    if (strlen(placa) != 7) {
        return 0;  // Não é válida
    }

    // Verificando o formato: 3 letras, 1 número, 1 letra, 2 números
    if (!isalpha(placa[0]) || !isalpha(placa[1]) || !isalpha(placa[2])) {
        return 0;  // As três primeiras posições devem ser letras
    }

    if (!isdigit(placa[3])) {
        return 0;  // O quarto caractere deve ser um número
    }

    if (!isalpha(placa[4])) {
        return 0;  // O quinto caractere deve ser uma letra
    }

    if (!isdigit(placa[5]) || !isdigit(placa[6])) {
        return 0;  // Os dois últimos caracteres devem ser números
    }

    return 1;  // Placa válida
}

// Função para verificar se um nome do veículo é válido 
int verificarNomeValido(const char *nome) { // não utilizei a função usada em funcionario e cliente, pois ela só aceita nome e sobrenome 
    int i = 0;
    
    // Verificar se o nome não está vazio
    if (nome[0] == '\0') {
        return 0;  // Nome vazio não é válido
    }

    // Verificar se o nome começa ou termina com espaço
    if (isspace(nome[0]) || isspace(nome[strlen(nome) - 1])) {
        return 0;  // Nome não pode começar ou terminar com espaço
    }

    // Verificar se todos os caracteres do nome são letras ou espaços
    while (nome[i] != '\0') {
        if (!(isalpha(nome[i]) || isspace(nome[i]))) {
            return 0;  // Nome contém caracteres inválidos
        }
        i++;
    }

    return 1;  // Nome válido
} 

int verificarAnoValido(const char *anodf) {
    // Converter a string para inteiro
    int ano = atoi(anodf);  // Usa a função atoi para converter de char* para int

    // Obter o ano atual
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    int anoAtual = tm.tm_year + 1900;  // tm_year retorna o ano desde 1900

    // Verificar se o ano está no intervalo plausível
    if (ano < 1886 || ano > anoAtual) {
        return 0;  // Ano inválido
    }

    return 1;  // Ano válido
}

// Função para verificar se o ano é bissexto
int isLeapYear(int year) {
    return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}

// Função para verificar se o mês é válido (1 a 12)
int isValidMonth(int month) {
    return month >= 1 && month <= 12;
}

// Função para verificar se o dia é válido para o mês e ano dados
int isValidDay(int day, int month, int year) {
    // Número de dias por mês
    int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    // Se for fevereiro e o ano for bissexto, ajustamos o número de dias
    if (month == 2 && isLeapYear(year)) {
        daysInMonth[1] = 29;
    }

    // Verifica se o dia está dentro do limite para o mês
    return day >= 1 && day <= daysInMonth[month - 1];
}

// Função que valida a data no formato YYYY-MM-DD
int isValidDate(const char* date) {
    if (date == NULL || strlen(date) != 10) {
        return 0; // Data inválida (tamanho errado ou NULL)
    }

    // Verifica se o formato está correto (YYYY-MM-DD)
    if (date[4] != '-' || date[7] != '-') {
        return 0; // Data inválida (formato errado)
    }

    int year, month, day;
    // Tenta converter os componentes da data
    if (sscanf(date, "%4d-%2d-%2d", &year, &month, &day) != 3) {
        return 0; // Data inválida (não conseguiu fazer o parse)
    }

    // Valida o ano, mês e dia
    if (year < 1 || !isValidMonth(month) || !isValidDay(day, month, year)) {
        return 0; // Data inválida
    }

    return 1; // Data válida
}

// Função para validar o número de parcelas
int validarParcelas(const char* parcelasStr) {
    // Definindo os limites mínimo e máximo para o número de parcelas
    const int PARCELAS_MIN = 1;
    const int PARCELAS_MAX = 12;

    // Verifica se a string é vazia
    if (parcelasStr == NULL || *parcelasStr == '\0') {
        return 0; // String vazia
    }

    // Verifica se todos os caracteres são dígitos
    for (int i = 0; parcelasStr[i] != '\0'; i++) {
        if (!isdigit(parcelasStr[i])) {
            return 0; // String contém caracteres não numéricos
        }
    }

    // Converte a string para inteiro
    int parcelas = atoi(parcelasStr);

    // Verifica se o número de parcelas está dentro do intervalo permitido
    if (parcelas >= PARCELAS_MIN && parcelas <= PARCELAS_MAX) {
        return 1;  // Número de parcelas válido
    } else {
        return 0;  // Número de parcelas inválido
    }
}

// Função de validação que agora recebe uma string (char *)
int validarValorPositivo(char *valorStr) {
    // Converte a string para float
    float valor = strtof(valorStr, NULL);

    // Verifica se o valor é positivo
    if (valor > 0) {
        return 1; // Valor positivo
    } else {
        return 0; // Valor não positivo (zero ou negativo)
    }
}