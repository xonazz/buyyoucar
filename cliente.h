#ifndef CLIENTE_H 
#define CLIENTE_H 

#include <stdio.h>

// Struct p/ dados do cliente 
typedef struct {
    char status;          // Status do cliente (ativo, inativo, etc)
    char nome[52];        // Nome como array estático
    char cpf[13];         // CPF com tamanho fixo
    char email[258];      // E-mail como array estático
    char cnh[12];        // n° da carteira de motorista estático
    char fone[15];        // Telefone como array estático
} Cliente;



void tela_cliente(void);
void cadastra_cliente(void);
void pesquisa_cliente(void);
void atualiza_cliente(void);
void exclui_cliente(void);

void grava_cliente(FILE *fp, Cliente *cliente);
void busca_cliente(const char *cpf_busca);

int verificaCpfCadastrado(const char *cpf);

#endif 
