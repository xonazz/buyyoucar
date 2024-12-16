#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "valid_vechi.h"

// Função para validar a placa (ex: ABCD-123)
int valida_placa(char placa[]) {
    if (strlen(placa) != 8) {
        return 0; // Placa inválida
    }

    for (int i = 0; i < 4; i++) {
        if (!isalpha(placa[i])) {
            return 0; // As primeiras 4 posições devem ser letras
        }
    }

    if (placa[4] != '-') {
        return 0; // O quinto caractere deve ser o hífen
    }

    for (int i = 5; i < 8; i++) {
        if (!isdigit(placa[i])) {
            return 0; // As últimas 3 posições devem ser números
        }
    }

    return 1; // Placa válida
}

// Função para validar o ano de fabricação
int valida_ano(int ano) {
    int ano_atual = 2024;
    return ano >= 1900 && ano <= ano_atual;
}

// Função para validar a marca
int valida_marca(char marca[]) {
    return strlen(marca) > 0;
}

// Função para validar o modelo
int valida_modelo(char modelo[]) {
    return strlen(modelo) > 0;
}

// Função para criar e validar as informações do veículo
Veiculo* cria_veiculo(char placa[], char marca[], char modelo[], int ano) {
    if (!valida_placa(placa)) {
        printf("Placa inválida! A placa deve ter o formato ABCD-123.\n");
        return NULL;
    }

    if (!valida_marca(marca)) {
        printf("Marca inválida! A marca não pode estar vazia.\n");
        return NULL;
    }

    if (!valida_modelo(modelo)) {
        printf("Modelo inválido! O modelo não pode estar vazio.\n");
        return NULL;
    }

    if (!valida_ano(ano)) {
        printf("Ano inválido! O ano deve estar entre 1900 e o ano atual.\n");
        return NULL;
    }

    Veiculo* novo_veiculo = (Veiculo*)malloc(sizeof(Veiculo));
    
    if (novo_veiculo == NULL) {
        printf("Erro ao alocar memória.\n");
        return NULL;
    }

    strcpy(novo_veiculo->placa, placa);
    strcpy(novo_veiculo->marca, marca);
    strcpy(novo_veiculo->modelo, modelo);
    novo_veiculo->ano = ano;

    return novo_veiculo;
}

// Função para exibir as informações do veículo
void exibe_veiculo(Veiculo* veiculo) {
    if (veiculo != NULL) {
        printf("\nVeículo Cadastrado:\n");
        printf("Placa: %s\n", veiculo->placa);
        printf("Marca: %s\n", veiculo->marca);
        printf("Modelo: %s\n", veiculo->modelo);
        printf("Ano de Fabricação: %d\n", veiculo->ano);
    }
}

// Função para salvar os dados do veículo em um arquivo
void salvar_veiculo_em_arquivo(Veiculo* veiculo) {
    FILE *arquivo = fopen("veiculos.txt", "a"); // Abre o arquivo para adicionar dados ao final

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    // Salva as informações do veículo no arquivo
    fprintf(arquivo, "Placa: %s\n", veiculo->placa);
    fprintf(arquivo, "Marca: %s\n", veiculo->marca);
    fprintf(arquivo, "Modelo: %s\n", veiculo->modelo);
    fprintf(arquivo, "Ano de Fabricação: %d\n", veiculo->ano);
    fprintf(arquivo, "------------------------------\n");

    fclose(arquivo); // Fecha o arquivo
    printf("Veículo salvo com sucesso no arquivo 'veiculos.txt'.\n");
} 

// Função para buscar um veículo por placa no arquivo
void buscar_veiculo_por_placa(const char *placa_buscar) {
    FILE *arquivo = fopen("veiculos.txt", "r"); // Abre o arquivo para leitura

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    char linha[256];
    int encontrado = 0;

    // Variáveis para armazenar os dados do veículo
    char placa[9], marca[100], modelo[100];
    int ano;

    // Percorre o arquivo linha por linha
    while (fgets(linha, sizeof(linha), arquivo)) {
        // Lê as informações do veículo do arquivo
        if (sscanf(linha, "Placa: %8s", placa) == 1) {
            if (strcmp(placa, placa_buscar) == 0) {
                // Encontrou a placa, agora lemos os dados seguintes
                fgets(linha, sizeof(linha), arquivo); // Lê a linha da marca
                sscanf(linha, "Marca: %[^\n]", marca);
                
                fgets(linha, sizeof(linha), arquivo); // Lê a linha do modelo
                sscanf(linha, "Modelo: %[^\n]", modelo);
                
                fgets(linha, sizeof(linha), arquivo); // Lê a linha do ano
                sscanf(linha, "Ano de Fabricação: %d", &ano);

                // Exibe os dados do veículo encontrado
                printf("\nVeículo Encontrado:\n");
                printf("Placa: %s\n", placa);
                printf("Marca: %s\n", marca);
                printf("Modelo: %s\n", modelo);
                printf("Ano de Fabricação: %d\n", ano);

                encontrado = 1;
                break; // Sai do loop após encontrar o veículo
            }
        }
    }

    if (!encontrado) {
        printf("Veículo com a placa %s não encontrado no arquivo.\n", placa_buscar);
    }

    fclose(arquivo); // Fecha o arquivo
} 

void modificar_veiculo_por_placa(const char *placa_buscar) {
    FILE *arquivo = fopen("veiculos.txt", "r+"); // Abre o arquivo para leitura e escrita

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    char linha[256];
    int encontrado = 0;
    long posicao_inicial = 0;

    // Variáveis para armazenar os dados do veículo
    char placa[9], marca[100], modelo[100];
    int ano;

    // Percorrer o arquivo linha por linha para encontrar o veículo
    while (fgets(linha, sizeof(linha), arquivo)) {
        // Lê as informações do veículo do arquivo
        posicao_inicial = ftell(arquivo); // Posição inicial para modificar o conteúdo

        if (sscanf(linha, "Placa: %8s", placa) == 1) {
            if (strcmp(placa, placa_buscar) == 0) {
                // Encontrou o veículo, agora vamos alterar as informações
                encontrado = 1;

                // Solicitar novas informações para o usuário
                printf("\nVeículo encontrado. Informações atuais:\n");
                printf("Placa: %s\n", placa);
                printf("Marca: %s\n", marca);
                printf("Modelo: %s\n", modelo);
                printf("Ano de Fabricação: %d\n", ano);

                // Solicitar nova placa
                printf("Digite a nova placa (formato ABCD-123): ");
                char nova_placa[9];
                fgets(nova_placa, sizeof(nova_placa), stdin);
                nova_placa[strcspn(nova_placa, "\n")] = '\0'; // Remove o '\n'

                // Validar a nova placa
                if (!valida_placa(nova_placa)) {
                    printf("Placa inválida!\n");
                    fclose(arquivo);
                    return;
                }

                // Solicitar nova marca, modelo e ano
                printf("Digite a nova marca: ");
                fgets(marca, sizeof(marca), stdin);
                marca[strcspn(marca, "\n")] = '\0'; // Remove o '\n'

                printf("Digite o novo modelo: ");
                fgets(modelo, sizeof(modelo), stdin);
                modelo[strcspn(modelo, "\n")] = '\0'; // Remove o '\n'

                printf("Digite o novo ano de fabricação: ");
                scanf("%d", &ano);
                getchar(); // Limpar o buffer de entrada

                // Reposicionar o arquivo na posição original
                fseek(arquivo, posicao_inicial - strlen(linha), SEEK_SET);

                // Atualizar as informações no arquivo
                fprintf(arquivo, "Placa: %s\n", nova_placa);
                fprintf(arquivo, "Marca: %s\n", marca);
                fprintf(arquivo, "Modelo: %s\n", modelo);
                fprintf(arquivo, "Ano de Fabricação: %d\n", ano);
                fprintf(arquivo, "------------------------------\n");

                printf("Veículo atualizado com sucesso.\n");
                break; // Sai do loop após encontrar e modificar o veículo
            }
        }
    }

    if (!encontrado) {
        printf("Veículo com a placa %s não encontrado no arquivo.\n", placa_buscar);
    }

    fclose(arquivo); // Fecha o arquivo
} 

// Função para remover um veículo do arquivo pelo número da placa
void remover_veiculo_por_placa(const char *placa_buscar) {
    FILE *arquivo = fopen("veiculos.txt", "r");  // Abre o arquivo original para leitura
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para leitura!\n");
        return;
    }

    FILE *arquivo_temp = fopen("temp_veiculos.txt", "w");  // Cria um arquivo temporário para escrever os dados
    if (arquivo_temp == NULL) {
        printf("Erro ao abrir o arquivo temporário!\n");
        fclose(arquivo);
        return;
    }

    char linha[256];
    int encontrado = 0;

    // Percorrer o arquivo original linha por linha
    while (fgets(linha, sizeof(linha), arquivo)) {
        char placa[9];

        // Verifica se a linha contém a informação da placa
        if (sscanf(linha, "Placa: %8s", placa) == 1) {
            if (strcmp(placa, placa_buscar) == 0) {
                encontrado = 1;
                // Pula a remoção deste veículo, não escreve no arquivo temporário
                continue; // Ignora as linhas associadas a esse veículo
            }
        }

        // Escreve as linhas no arquivo temporário
        fputs(linha, arquivo_temp);
    }

    if (encontrado) {
        printf("Veículo com a placa %s foi removido com sucesso.\n", placa_buscar);
    } else {
        printf("Veículo com a placa %s não encontrado.\n", placa_buscar);
    }

    // Fechar os arquivos
    fclose(arquivo);
    fclose(arquivo_temp);

    // Substituir o arquivo original pelo arquivo temporário
    remove("veiculos.txt");  // Remove o arquivo original
    rename("temp_veiculos.txt", "veiculos.txt");  // Renomeia o arquivo temporário para o nome do arquivo original
}
