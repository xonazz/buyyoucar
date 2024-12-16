#ifndef VALID_CLIENT_H
#define VALID_CLIENT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 100

// Estrutura para armazenar as informações de uma pessoa
typedef struct {
    char nome[MAX_LEN];
    char cpf[12];       // CPF com 11 dígitos + '\0'
    char telefone[12];  // Telefone com 11 dígitos + '\0'
    char cnh[12];       // CNH com 11 dígitos + '\0'
    char email[MAX_LEN];
    char endereco[MAX_LEN];
} Pessoa;

// Funções de validação
int validar_nome(const char *nome);
int validar_cpf(const char *cpf);
int validar_telefone(const char *telefone);
int validar_cnh(const char *cnh);
int validar_email(const char *email);
int validar_endereco(const char *endereco); 
int verificar_cpf_no_arquivo(const char *cpf); 
int buscar_e_alterar_cpf_no_arquivo(const char *cpf);
int deletar_cpf_no_arquivo(const char *cpf);

// Funções auxiliares
void limpar_buffer();

// Função para criar uma nova pessoa com dados válidos
Pessoa* criar_pessoa();

// Função para imprimir os dados de uma pessoa
void imprimir_pessoa(Pessoa* pessoa);

// Função para salvar os dados de uma pessoa em um arquivo
void salvar_pessoa_em_arquivo(Pessoa* pessoa);

#endif // VALID_CLIENT_H
