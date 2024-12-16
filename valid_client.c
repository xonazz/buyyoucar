#include "valid_client.h"

// Função para validar o nome
int validar_nome(const char *nome) {
    if (nome == NULL || strlen(nome) == 0) {
        printf("Nome inválido! O nome não pode ser vazio.\n");
        return 0;
    }
    return 1;
}

// Função para validar o CPF (simples validação de formato, sem cálculo de dígitos)
int validar_cpf(const char *cpf) {
    if (strlen(cpf) != 11) {
        printf("CPF inválido! O CPF deve ter 11 caracteres.\n");
        return 0;
    }
    for (int i = 0; i < 11; i++) {
        if (!isdigit(cpf[i])) {
            printf("CPF inválido! O CPF deve conter apenas números.\n");
            return 0;
        }
    }
    return 1;
}

// Função para validar o telefone (11 dígitos numéricos)
int validar_telefone(const char *telefone) {
    if (strlen(telefone) != 11) {
        printf("Telefone inválido! O telefone deve ter 11 dígitos numéricos.\n");
        return 0;
    }

    for (int i = 0; i < 11; i++) {
        if (!isdigit(telefone[i])) {
            printf("Telefone inválido! O telefone deve conter apenas números.\n");
            return 0;
        }
    }

    return 1;
}

// Função para validar CNH (exemplo simples)
int validar_cnh(const char *cnh) {
    if (strlen(cnh) != 11) {
        printf("CNH inválida! A CNH deve ter 11 caracteres.\n");
        return 0;
    }
    for (int i = 0; i < 11; i++) {
        if (!isdigit(cnh[i])) {
            printf("CNH inválida! A CNH deve conter apenas números.\n");
            return 0;
        }
    }
    return 1;
}

// Função para validar e-mail (simplificação da validação)
int validar_email(const char *email) {
    // Verificar se contém "@" e "."
    if (strchr(email, '@') == NULL || strchr(email, '.') == NULL) {
        printf("E-mail inválido! O e-mail deve conter '@' e '.'.\n");
        return 0;
    }
    return 1;
}

// Função para validar o endereço (não possui validação rigorosa)
int validar_endereco(const char *endereco) {
    if (strlen(endereco) == 0) {
        printf("Endereço inválido! O endereço não pode ser vazio.\n");
        return 0;
    }
    return 1;
}

// Função para limpar o buffer de entrada (para evitar problemas com fgets)
void limpar_buffer() {
    char c;
    while ((c = getchar()) != '\n' && c != EOF);  // Limpa até o fim da linha ou do arquivo
}

// Função para criar uma nova Pessoa com validação
Pessoa* criar_pessoa() {
    Pessoa* nova_pessoa = (Pessoa*)malloc(sizeof(Pessoa)); // Aloca memória dinamicamente para a estrutura

    if (nova_pessoa == NULL) {
        printf("Erro ao alocar memória.\n");
        return NULL;
    }

    // Recebe o nome
    printf("Digite o nome: ");
    fgets(nova_pessoa->nome, MAX_LEN, stdin);
    nova_pessoa->nome[strcspn(nova_pessoa->nome, "\n")] = '\0'; // Remove o \n do final

    if (!validar_nome(nova_pessoa->nome)) {
        free(nova_pessoa); // Libera memória em caso de erro
        return NULL;
    }

    // Limpa o buffer antes de ler o CPF
    limpar_buffer();

    // Recebe o CPF
    printf("Digite o CPF (somente números, sem pontuação): Exemplo: 12345678901: ");
    fgets(nova_pessoa->cpf, 12, stdin);
    nova_pessoa->cpf[strcspn(nova_pessoa->cpf, "\n")] = '\0'; // Remove o \n do final

    if (!validar_cpf(nova_pessoa->cpf)) {
        free(nova_pessoa); // Libera memória em caso de erro
        return NULL;
    }

    // Limpa o buffer antes de ler o telefone
    limpar_buffer();

    // Recebe o telefone
    printf("Digite o telefone (somente números, 11 dígitos): Exemplo: 11987654321: ");
    fgets(nova_pessoa->telefone, 12, stdin);
    nova_pessoa->telefone[strcspn(nova_pessoa->telefone, "\n")] = '\0'; // Remove o \n do final

    if (!validar_telefone(nova_pessoa->telefone)) {
        free(nova_pessoa); // Libera memória em caso de erro
        return NULL;
    }

    // Limpa o buffer antes de ler a CNH
    limpar_buffer();

    // Recebe a CNH
    printf("Digite o número da CNH (somente números, 11 dígitos): Exemplo: 12345678901: ");
    fgets(nova_pessoa->cnh, 12, stdin);
    nova_pessoa->cnh[strcspn(nova_pessoa->cnh, "\n")] = '\0'; // Remove o \n do final

    if (!validar_cnh(nova_pessoa->cnh)) {
        free(nova_pessoa); // Libera memória em caso de erro
        return NULL;
    }

    // Limpa o buffer antes de ler o e-mail
    limpar_buffer();

    // Recebe o e-mail
    printf("Digite o e-mail: Exemplo: nome@dominio.com: ");
    fgets(nova_pessoa->email, MAX_LEN, stdin);
    nova_pessoa->email[strcspn(nova_pessoa->email, "\n")] = '\0'; // Remove o \n do final

    if (!validar_email(nova_pessoa->email)) {
        free(nova_pessoa); // Libera memória em caso de erro
        return NULL;
    }

    // Limpa o buffer antes de ler o endereço
    limpar_buffer();

    // Recebe o endereço
    printf("Digite o endereço: Exemplo: Rua A, 123, Bairro XYZ: ");
    fgets(nova_pessoa->endereco, MAX_LEN, stdin);
    nova_pessoa->endereco[strcspn(nova_pessoa->endereco, "\n")] = '\0'; // Remove o \n do final

    if (!validar_endereco(nova_pessoa->endereco)) {
        free(nova_pessoa); // Libera memória em caso de erro
        return NULL;
    }

    return nova_pessoa;
}

// Função para salvar os dados da pessoa em um arquivo
void salvar_pessoa_em_arquivo(Pessoa* pessoa) {
    FILE* arquivo = fopen("pessoa_data.txt", "a"); // Abre o arquivo para adicionar os dados

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para salvar os dados.\n");
        return;
    }

    // Salva os dados no arquivo
    fprintf(arquivo, "Nome: %s\n", pessoa->nome);
    fprintf(arquivo, "CPF: %s\n", pessoa->cpf);
    fprintf(arquivo, "Telefone: %s\n", pessoa->telefone);
    fprintf(arquivo, "CNH: %s\n", pessoa->cnh);
    fprintf(arquivo, "E-mail: %s\n", pessoa->email);
    fprintf(arquivo, "Endereço: %s\n", pessoa->endereco);
    fprintf(arquivo, "--------------------------\n");

    fclose(arquivo); // Fecha o arquivo
    printf("Dados salvos com sucesso em 'pessoa_data.txt'.\n");
}

// Função para imprimir os dados de uma pessoa
void imprimir_pessoa(Pessoa* pessoa) {
    if (pessoa != NULL) {
        printf("\nPessoa cadastrada:\n");
        printf("Nome: %s\n", pessoa->nome);
        printf("CPF: %s\n", pessoa->cpf);
        printf("Telefone: %s\n", pessoa->telefone);
        printf("CNH: %s\n", pessoa->cnh);
        printf("E-mail: %s\n", pessoa->email);
        printf("Endereço: %s\n", pessoa->endereco);
    }
}


// Função para verificar se o CPF existe no arquivo e imprimir as informações associadas
int verificar_cpf_no_arquivo(const char *cpf) {
    FILE *arquivo = fopen("pessoa_data.txt", "r"); // Abre o arquivo para leitura

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para leitura.\n");
        return 0;
    }

    char linha[MAX_LEN];
    int cpf_encontrado = 0;
    char nome[MAX_LEN], telefone[MAX_LEN], cnh[MAX_LEN], email[MAX_LEN], endereco[MAX_LEN];

    // Inicializa as variáveis com valores vazios
    nome[0] = telefone[0] = cnh[0] = email[0] = endereco[0] = '\0';

    // Ler o arquivo linha por linha
    while (fgets(linha, MAX_LEN, arquivo)) {
        // Procurar pela linha que começa com "CPF: "
        if (strncmp(linha, "CPF: ", 5) == 0) {
            // Comparar o CPF extraído da linha com o CPF passado
            if (strcmp(linha + 5, cpf) == 0) {
                cpf_encontrado = 1;

                // Imprimir as informações associadas ao CPF
                printf("\nInformações associadas ao CPF %s:\n", cpf);

                // Imprimir nome
                if (fgets(linha, MAX_LEN, arquivo) && strncmp(linha, "Nome: ", 6) == 0) {
                    printf("Nome: %s", linha + 6);
                }

                // Imprimir telefone
                if (fgets(linha, MAX_LEN, arquivo) && strncmp(linha, "Telefone: ", 10) == 0) {
                    printf("Telefone: %s", linha + 10);
                }

                // Imprimir CNH
                if (fgets(linha, MAX_LEN, arquivo) && strncmp(linha, "CNH: ", 5) == 0) {
                    printf("CNH: %s", linha + 5);
                }

                // Imprimir email
                if (fgets(linha, MAX_LEN, arquivo) && strncmp(linha, "E-mail: ", 8) == 0) {
                    printf("E-mail: %s", linha + 8);
                }

                // Imprimir endereço
                if (fgets(linha, MAX_LEN, arquivo) && strncmp(linha, "Endereço: ", 10) == 0) {
                    printf("Endereço: %s", linha + 10);
                }

                break; // Encontrou o CPF, então sai do loop
            }
        }
    }

    fclose(arquivo); // Fecha o arquivo

    if (!cpf_encontrado) {
        printf("CPF não encontrado.\n");
    }

    return cpf_encontrado; // Retorna 1 se o CPF foi encontrado, 0 caso contrário
} 

// Função para buscar o CPF no arquivo e permitir a alteração dos dados
int buscar_e_alterar_cpf_no_arquivo(const char *cpf) {
    FILE *arquivo = fopen("pessoa_data.txt", "r+"); // Abre o arquivo para leitura e escrita

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para leitura e escrita.\n");
        return 0;
    }

    char linha[MAX_LEN];
    char nome[MAX_LEN], telefone[MAX_LEN], cnh[MAX_LEN], email[MAX_LEN], endereco[MAX_LEN];
    int cpf_encontrado = 0;
    long posicao_inicial = 0;

    // Percorre o arquivo para encontrar o CPF e salvar a posição onde ele ocorre
    while (fgets(linha, MAX_LEN, arquivo)) {
        posicao_inicial = ftell(arquivo); // Salva a posição atual no arquivo

        // Verifica se a linha contém o CPF
        if (strncmp(linha, "CPF: ", 5) == 0 && strcmp(linha + 5, cpf) == 0) {
            cpf_encontrado = 1;
            break; // Encerra o loop se encontrar o CPF
        }
    }

    if (!cpf_encontrado) {
        printf("CPF não encontrado.\n");
        fclose(arquivo);
        return 0; // Se o CPF não foi encontrado, retorna 0
    }

    // Solicita as novas informações do cliente
    printf("\nDigite as novas informações para o CPF %s:\n", cpf);

    // Solicita o novo nome
    printf("Digite o novo nome: ");
    fgets(nome, MAX_LEN, stdin);
    nome[strcspn(nome, "\n")] = '\0'; // Remove o '\n' do final

    // Solicita o novo telefone
    printf("Digite o novo telefone: ");
    fgets(telefone, MAX_LEN, stdin);
    telefone[strcspn(telefone, "\n")] = '\0';

    // Solicita a nova CNH
    printf("Digite a nova CNH: ");
    fgets(cnh, MAX_LEN, stdin);
    cnh[strcspn(cnh, "\n")] = '\0';

    // Solicita o novo e-mail
    printf("Digite o novo e-mail: ");
    fgets(email, MAX_LEN, stdin);
    email[strcspn(email, "\n")] = '\0';

    // Solicita o novo endereço
    printf("Digite o novo endereço: ");
    fgets(endereco, MAX_LEN, stdin);
    endereco[strcspn(endereco, "\n")] = '\0';

    // Volta para o início do arquivo
    fseek(arquivo, posicao_inicial - strlen(linha), SEEK_SET);

    // Regrava as novas informações no arquivo
    fprintf(arquivo, "Nome: %s\n", nome);
    fprintf(arquivo, "CPF: %s\n", cpf);
    fprintf(arquivo, "Telefone: %s\n", telefone);
    fprintf(arquivo, "CNH: %s\n", cnh);
    fprintf(arquivo, "E-mail: %s\n", email);
    fprintf(arquivo, "Endereço: %s\n", endereco);
    fprintf(arquivo, "--------------------------\n");

    fclose(arquivo); // Fecha o arquivo

    printf("\nDados alterados com sucesso!\n");
    return 1; // Retorna 1 se a alteração for bem-sucedida
} 

// Função para buscar o CPF no arquivo e deletar os dados associados a ele
int deletar_cpf_no_arquivo(const char *cpf) {
    FILE *arquivo = fopen("pessoa_data.txt", "r");  // Abre o arquivo para leitura
    FILE *temp_arquivo = fopen("temp_pessoa_data.txt", "w");  // Cria um arquivo temporário para gravar os dados restantes

    if (arquivo == NULL || temp_arquivo == NULL) {
        printf("Erro ao abrir os arquivos.\n");
        return 0;  // Se algum arquivo não foi aberto corretamente, retorna 0
    }

    char linha[MAX_LEN];
    int cpf_encontrado = 0;

    // Percorre o arquivo original linha por linha
    while (fgets(linha, MAX_LEN, arquivo)) {
        // Verifica se a linha contém o CPF
        if (strncmp(linha, "CPF: ", 5) == 0 && strcmp(linha + 5, cpf) == 0) {
            cpf_encontrado = 1;
            // Ignora as linhas associadas ao CPF a ser deletado
            while (fgets(linha, MAX_LEN, arquivo) && strcmp(linha, "--------------------------\n") != 0) {
                // Apenas avança até o final da entrada associada ao CPF
            }
        } else {
            // Se o CPF não foi encontrado, copia a linha para o arquivo temporário
            fputs(linha, temp_arquivo);
        }
    }

    fclose(arquivo);  // Fecha o arquivo original
    fclose(temp_arquivo);  // Fecha o arquivo temporário

    if (!cpf_encontrado) {
        printf("CPF não encontrado.\n");
        remove("temp_pessoa_data.txt");  // Remove o arquivo temporário se não foi encontrado o CPF
        return 0;  // Retorna 0 se o CPF não for encontrado
    }

    // Substitui o arquivo original pelo arquivo temporário
    if (remove("pessoa_data.txt") == 0) {
        if (rename("temp_pessoa_data.txt", "pessoa_data.txt") == 0) {
            printf("Dados associados ao CPF %s foram deletados com sucesso.\n", cpf);
            return 1;  // Retorna 1 se a operação for bem-sucedida
        } else {
            printf("Erro ao renomear o arquivo temporário.\n");
        }
    } else {
        printf("Erro ao remover o arquivo original.\n");
    }

    return 0;  // Retorna 0 em caso de erro
}