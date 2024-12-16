#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "valid_func.h"

// Função para alocar memória para os campos dinâmicos
void alocar_dados(struct Funcionario *func) {
    func->cpf = (char *)malloc(12 * sizeof(char));           // CPF tem 11 dígitos + 1 para '\0'
    func->nome = (char *)malloc(100 * sizeof(char));         // Aloca memória para o nome
    func->email = (char *)malloc(100 * sizeof(char));        // Aloca memória para o e-mail
    func->data_nascimento = (char *)malloc(11 * sizeof(char));  // Data de nascimento no formato dd/mm/aaaa
    func->celular = (char *)malloc(12 * sizeof(char));       // Aloca memória para o celular (11 dígitos + '\0')

    if (func->cpf == NULL || func->nome == NULL || func->email == NULL || func->data_nascimento == NULL || func->celular == NULL) {
        printf("Erro na alocação de memória!\n");
        exit(1);  // Finaliza o programa com erro
    }
}

// Função para liberar a memória alocada
void liberar_dados(struct Funcionario *func) {
    free(func->cpf);
    free(func->nome);
    free(func->email);
    free(func->data_nascimento);
    free(func->celular);
}

// Função para ler os dados do usuário
void ler_dados(struct Funcionario *func) {
    printf("Digite o CPF (11 digitos): ");
    fgets(func->cpf, 12, stdin);
    func->cpf[strcspn(func->cpf, "\n")] = '\0';  // Remove o caractere de nova linha

    printf("Digite o nome: ");
    fgets(func->nome, 100, stdin);
    func->nome[strcspn(func->nome, "\n")] = '\0';  // Remove o caractere de nova linha

    printf("Digite o e-mail: ");
    fgets(func->email, 100, stdin);
    func->email[strcspn(func->email, "\n")] = '\0';  // Remove o caractere de nova linha

    printf("Digite a data de nascimento (dd/mm/aaaa): ");
    fgets(func->data_nascimento, 11, stdin);
    func->data_nascimento[strcspn(func->data_nascimento, "\n")] = '\0';  // Remove o caractere de nova linha

    // Limpar o buffer de entrada antes de ler o celular
    getchar();  // Limpa o buffer, removendo o '\n' residual que pode ter sido deixado por fgets()

    printf("Digite o número de celular (11 dígitos): ");
    fgets(func->celular, 12, stdin);
    func->celular[strcspn(func->celular, "\n")] = '\0';  // Remove o caractere de nova linha
}

// Função para exibir os dados lidos
void exibir_dados(struct Funcionario *func) {
    printf("\nDados do Funcionario:\n");
    printf("CPF: %s\n", func->cpf);
    printf("Nome: %s\n", func->nome);
    printf("Email: %s\n", func->email);
    printf("Data de Nascimento: %s\n", func->data_nascimento);
    printf("Celular: %s\n", func->celular);
}

// Função para salvar os dados em um arquivo binário
void salvar_dados_binario(struct Funcionario *func, const char *nome_arquivo) {
    FILE *arquivo = fopen(nome_arquivo, "wb");  // Abre o arquivo para escrita binária
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para escrita!\n");
        exit(1);
    }

    // Grava os dados no arquivo
    fwrite(func->cpf, sizeof(char), 12, arquivo);
    fwrite(func->nome, sizeof(char), 100, arquivo);
    fwrite(func->email, sizeof(char), 100, arquivo);
    fwrite(func->data_nascimento, sizeof(char), 11, arquivo);
    fwrite(func->celular, sizeof(char), 12, arquivo);

    fclose(arquivo);
}

// Função para carregar os dados de um arquivo binário
void carregar_dados_binario(struct Funcionario *func, const char *nome_arquivo) {
    FILE *arquivo = fopen(nome_arquivo, "rb");  // Abre o arquivo para leitura binária
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para leitura!\n");
        exit(1);
    }

    // Lê os dados do arquivo
    fread(func->cpf, sizeof(char), 12, arquivo);
    fread(func->nome, sizeof(char), 100, arquivo);
    fread(func->email, sizeof(char), 100, arquivo);
    fread(func->data_nascimento, sizeof(char), 11, arquivo);
    fread(func->celular, sizeof(char), 12, arquivo);

    fclose(arquivo);
}

// Função para buscar dados pelo CPF no arquivo binário
void buscar_dados_por_cpf(const char *nome_arquivo, const char *cpf_buscar) {
    FILE *arquivo = fopen(nome_arquivo, "rb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para leitura!\n");
        exit(1);
    }

    struct Funcionario func;
    int encontrado = 0;

    // Percorrer o arquivo até encontrar o CPF desejado
    while (fread(func.cpf, sizeof(char), 12, arquivo) == 12) {
        // Lê os dados restantes após o CPF
        fread(func.nome, sizeof(char), 100, arquivo);
        fread(func.email, sizeof(char), 100, arquivo);
        fread(func.data_nascimento, sizeof(char), 11, arquivo);
        fread(func.celular, sizeof(char), 12, arquivo);

        // Verificar se o CPF lido é igual ao CPF buscado
        if (strcmp(func.cpf, cpf_buscar) == 0) {
            encontrado = 1;
            break;  // Encerra o loop após encontrar o CPF
        }
    }

    if (encontrado) {
        // Exibe os dados do funcionário se o CPF for encontrado
        printf("\nDados do Funcionário encontrado:\n");
        printf("CPF: %s\n", func.cpf);
        printf("Nome: %s\n", func.nome);
        printf("Email: %s\n", func.email);
        printf("Data de Nascimento: %s\n", func.data_nascimento);
        printf("Celular: %s\n", func.celular);
    } else {
        printf("CPF não encontrado no arquivo.\n");
    }

    fclose(arquivo); 
} 

// Função para alocar memória para os campos dinâmicos
void alocar_funcionario(struct Funcionario *func) {
    func->cpf = (char *)malloc(12 * sizeof(char));           // CPF tem 11 dígitos + 1 para '\0'
    func->nome = (char *)malloc(100 * sizeof(char));         // Aloca memória para o nome
    func->email = (char *)malloc(100 * sizeof(char));        // Aloca memória para o e-mail
    func->data_nascimento = (char *)malloc(11 * sizeof(char));  // Data de nascimento no formato dd/mm/aaaa
    func->celular = (char *)malloc(12 * sizeof(char));       // Aloca memória para o celular (11 dígitos + '\0')

    if (func->cpf == NULL || func->nome == NULL || func->email == NULL || func->data_nascimento == NULL || func->celular == NULL) {
        printf("Erro na alocação de memória!\n");
        exit(1);  // Finaliza o programa com erro
    }
}

// Função para liberar a memória alocada
void liberar_funcionario(struct Funcionario *func) {
    free(func->cpf);
    free(func->nome);
    free(func->email);
    free(func->data_nascimento);
    free(func->celular);
}

// Função para ler os dados do usuário
void ler_funcionario(struct Funcionario *func) {
    printf("Digite o CPF (11 digitos): ");
    fgets(func->cpf, 12, stdin);
    func->cpf[strcspn(func->cpf, "\n")] = '\0';  // Remove o caractere de nova linha

    printf("Digite o nome: ");
    fgets(func->nome, 100, stdin);
    func->nome[strcspn(func->nome, "\n")] = '\0';  // Remove o caractere de nova linha

    printf("Digite o e-mail: ");
    fgets(func->email, 100, stdin);
    func->email[strcspn(func->email, "\n")] = '\0';  // Remove o caractere de nova linha

    printf("Digite a data de nascimento (dd/mm/aaaa): ");
    fgets(func->data_nascimento, 11, stdin);
    func->data_nascimento[strcspn(func->data_nascimento, "\n")] = '\0';  // Remove o caractere de nova linha

    printf("Digite o número de celular (11 dígitos): ");
    fgets(func->celular, 12, stdin);
    func->celular[strcspn(func->celular, "\n")] = '\0';  // Remove o caractere de nova linha
}

// Função para exibir os dados lidos
void exibir_funcionario(struct Funcionario *func) {
    printf("\nDados do Funcionário:\n");
    printf("CPF: %s\n", func->cpf);
    printf("Nome: %s\n", func->nome);
    printf("Email: %s\n", func->email);
    printf("Data de Nascimento: %s\n", func->data_nascimento);
    printf("Celular: %s\n", func->celular);
}

// Função para salvar os dados em um arquivo binário
void salvar_funcionario_binario(struct Funcionario *func, const char *nome_arquivo) {
    FILE *arquivo = fopen(nome_arquivo, "wb");  // Abre o arquivo para escrita binária
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para escrita!\n");
        exit(1);
    }

    // Grava os dados no arquivo
    fwrite(func->cpf, sizeof(char), 12, arquivo);
    fwrite(func->nome, sizeof(char), 100, arquivo);
    fwrite(func->email, sizeof(char), 100, arquivo);
    fwrite(func->data_nascimento, sizeof(char), 11, arquivo);
    fwrite(func->celular, sizeof(char), 12, arquivo);

    fclose(arquivo);
}

// Função para carregar os dados de um arquivo binário
void carregar_funcionario_binario(struct Funcionario *func, const char *nome_arquivo) {
    FILE *arquivo = fopen(nome_arquivo, "rb");  // Abre o arquivo para leitura binária
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para leitura!\n");
        exit(1);
    }

    // Lê os dados do arquivo
    fread(func->cpf, sizeof(char), 12, arquivo);
    fread(func->nome, sizeof(char), 100, arquivo);
    fread(func->email, sizeof(char), 100, arquivo);
    fread(func->data_nascimento, sizeof(char), 11, arquivo);
    fread(func->celular, sizeof(char), 12, arquivo);

    fclose(arquivo);
}

// Função para buscar dados pelo CPF no arquivo binário
void buscar_funcionario_por_cpf(const char *nome_arquivo, const char *cpf_buscar) {
    FILE *arquivo = fopen(nome_arquivo, "rb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para leitura!\n");
        exit(1);
    }

    struct Funcionario func;
    int encontrado = 0;

    // Percorrer o arquivo até encontrar o CPF desejado
    while (fread(func.cpf, sizeof(char), 12, arquivo) == 12) {
        // Lê os dados restantes após o CPF
        fread(func.nome, sizeof(char), 100, arquivo);
        fread(func.email, sizeof(char), 100, arquivo);
        fread(func.data_nascimento, sizeof(char), 11, arquivo);
        fread(func.celular, sizeof(char), 12, arquivo);

        // Verificar se o CPF lido é igual ao CPF buscado
        if (strcmp(func.cpf, cpf_buscar) == 0) {
            encontrado = 1;
            break;  // Encerra o loop após encontrar o CPF
        }
    }

    if (encontrado) {
        // Exibe os dados do funcionário se o CPF for encontrado
        printf("\nDados do Funcionário encontrado:\n");
        printf("CPF: %s\n", func.cpf);
        printf("Nome: %s\n", func.nome);
        printf("Email: %s\n", func.email);
        printf("Data de Nascimento: %s\n", func.data_nascimento);
        printf("Celular: %s\n", func.celular);
    } else {
        printf("CPF não encontrado no arquivo.\n");
    }

    fclose(arquivo); 
}

// Função para alterar os dados de um funcionário a partir do CPF
void alterar_funcionario_por_cpf(const char *nome_arquivo, const char *cpf_buscar) {
    FILE *arquivo = fopen(nome_arquivo, "r+b");  // Abre o arquivo para leitura e escrita binária
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para leitura!\n");
        exit(1);
    }

    struct Funcionario func;
    int encontrado = 0;

    // Percorrer o arquivo até encontrar o CPF desejado
    while (fread(func.cpf, sizeof(char), 12, arquivo) == 12) {
        // Lê os dados restantes após o CPF
        fread(func.nome, sizeof(char), 100, arquivo);
        fread(func.email, sizeof(char), 100, arquivo);
        fread(func.data_nascimento, sizeof(char), 11, arquivo);
        fread(func.celular, sizeof(char), 12, arquivo);

        // Verificar se o CPF lido é igual ao CPF buscado
        if (strcmp(func.cpf, cpf_buscar) == 0) {
            encontrado = 1;
            break;  // Encerra o loop após encontrar o CPF
        }
    }

    if (encontrado) {
        // Exibir os dados atuais do funcionário
        exibir_funcionario(&func);
        
        // Pedir ao usuário para digitar novos dados
        printf("\nDigite os novos dados:\n");
        ler_funcionario(&func);

        // Voltar ao início do arquivo e sobrescrever os dados
        fseek(arquivo, -((long)sizeof(struct Funcionario)), SEEK_CUR);
        
        fwrite(func.cpf, sizeof(char), 12, arquivo);
        fwrite(func.nome, sizeof(char), 100, arquivo);
        fwrite(func.email, sizeof(char), 100, arquivo);
        fwrite(func.data_nascimento, sizeof(char), 11, arquivo);
        fwrite(func.celular, sizeof(char), 12, arquivo);

        printf("\nDados alterados com sucesso!\n");
    } else {
        printf("CPF não encontrado no arquivo.\n");
    }

    fclose(arquivo);
} 

void excluir_funcionario_por_cpf(const char *nome_arquivo, const char *cpf_excluir) {
    FILE *arquivo_original = fopen(nome_arquivo, "rb");
    if (arquivo_original == NULL) {
        printf("Erro ao abrir o arquivo para leitura!\n");
        exit(1);
    }

    FILE *arquivo_temp = fopen("temp.bin", "wb");
    if (arquivo_temp == NULL) {
        printf("Erro ao criar arquivo temporário!\n");
        fclose(arquivo_original);
        exit(1);
    }

    struct Funcionario func;
    int encontrado = 0;

    // Percorrer o arquivo e copiar todos os dados para o arquivo temporário, exceto os do CPF a ser excluído
    while (fread(func.cpf, sizeof(char), 12, arquivo_original) == 12) {
        // Lê os dados restantes após o CPF
        fread(func.nome, sizeof(char), 100, arquivo_original);
        fread(func.email, sizeof(char), 100, arquivo_original);
        fread(func.data_nascimento, sizeof(char), 11, arquivo_original);
        fread(func.celular, sizeof(char), 12, arquivo_original);

        // Verifica se o CPF lido é igual ao CPF a ser excluído
        if (strcmp(func.cpf, cpf_excluir) != 0) {
            // Se não for o CPF a ser excluído, grava os dados no arquivo temporário
            fwrite(func.cpf, sizeof(char), 12, arquivo_temp);
            fwrite(func.nome, sizeof(char), 100, arquivo_temp);
            fwrite(func.email, sizeof(char), 100, arquivo_temp);
            fwrite(func.data_nascimento, sizeof(char), 11, arquivo_temp);
            fwrite(func.celular, sizeof(char), 12, arquivo_temp);
        } else {
            encontrado = 1;  // Marca que o CPF foi encontrado e excluído
        }
    }

    // Fecha ambos os arquivos
    fclose(arquivo_original);
    fclose(arquivo_temp);

    if (encontrado) {
        // Substitui o arquivo original pelo arquivo temporário
        if (remove(nome_arquivo) != 0) {
            printf("Erro ao remover o arquivo original!\n");
            exit(1);
        }

        if (rename("temp.bin", nome_arquivo) != 0) {
            printf("Erro ao renomear o arquivo temporário!\n");
            exit(1);
        }

        printf("Funcionário com CPF %s excluído com sucesso.\n", cpf_excluir);
    } else {
        printf("CPF %s não encontrado no arquivo.\n", cpf_excluir);
    }
}