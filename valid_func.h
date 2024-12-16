#ifndef VALID_FUNC_H
#define VALID_FUNC_H

// Definição da estrutura Funcionario
struct Funcionario {
    char *cpf;                // Apontador para armazenar CPF
    char *nome;               // Apontador para armazenar o nome
    char *email;              // Apontador para armazenar o e-mail
    char *data_nascimento;    // Apontador para armazenar a data de nascimento
    char *celular;            // Apontador para armazenar o número de celular
};

// Funções para manipular a estrutura Funcionario
void alocar_dados(struct Funcionario *func);  // Aloca memória para os dados
void liberar_dados(struct Funcionario *func); // Libera a memória alocada
void ler_dados(struct Funcionario *func);    // Lê os dados do usuário
void exibir_dados(struct Funcionario *func); // Exibe os dados lidos 
void buscar_dados_por_cpf(const char *nome_arquivo, const char *cpf_buscar);

// Funções para salvar e carregar dados de um arquivo binário
void salvar_dados_binario(struct Funcionario *func, const char *nome_arquivo);
void carregar_dados_binario(struct Funcionario *func, const char *nome_arquivo); 

// Protótipos das funções

// Função para alocar memória para os campos dinâmicos de um funcionário
void alocar_funcionario(struct Funcionario *func);

// Função para liberar a memória alocada para os dados de um funcionário
void liberar_funcionario(struct Funcionario *func);

// Função para ler os dados de um funcionário
void ler_funcionario(struct Funcionario *func);

// Função para exibir os dados de um funcionário
void exibir_funcionario(struct Funcionario *func);

// Função para salvar os dados de um funcionário em um arquivo binário
void salvar_funcionario_binario(struct Funcionario *func, const char *nome_arquivo);

// Função para carregar os dados de um funcionário de um arquivo binário
void carregar_funcionario_binario(struct Funcionario *func, const char *nome_arquivo);

// Função para buscar os dados de um funcionário pelo CPF em um arquivo binário
void buscar_funcionario_por_cpf(const char *nome_arquivo, const char *cpf_buscar);

// Função para alterar os dados de um funcionário a partir do CPF no arquivo binário
void alterar_funcionario_por_cpf(const char *nome_arquivo, const char *cpf_buscar); 

void excluir_funcionario_por_cpf(const char *nome_arquivo, const char *cpf_excluir);

#endif // VALID_FUNC_H
