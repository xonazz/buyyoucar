#ifndef VALID_VECHI_H
#define VALID_VECHI_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Definição da estrutura Veículo
typedef struct {
    char placa[9];  // Placa do veículo (8 caracteres + '\0')
    char marca[100]; // Marca do veículo
    char modelo[100]; // Modelo do veículo
    int ano; // Ano de fabricação
} Veiculo;

// Funções de validação
int valida_placa(char placa[]);
int valida_ano(int ano);
int valida_marca(char marca[]);
int valida_modelo(char modelo[]);

// Função para criar e validar um veículo
Veiculo* cria_veiculo(char placa[], char marca[], char modelo[], int ano);

// Função para exibir as informações do veículo
void exibe_veiculo(Veiculo* veiculo);

// Função para salvar os dados de um veículo em um arquivo
void salvar_veiculo_em_arquivo(Veiculo* veiculo); 

void buscar_veiculo_por_placa(const char *placa_buscar); 

void modificar_veiculo_por_placa(const char *placa_buscar); 

void remover_veiculo_por_placa(const char *placa_buscar);

#endif // VALID_VECHI_H
