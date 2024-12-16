#include <stdio.h> 
#include <stdlib.h> 
#include "funcionario.h"  

void tela_funcionario(void) { 
    char op;
    do {
        system("clear||cls");
        printf("\n");
        printf("┌─────────────────────────────────────────────────────────────────────────────┐\n");
        printf("|                                 BuyYourCar                                  |\n");
        printf("└─────────────────────────────────────────────────────────────────────────────┘\n");
        printf("┌─────────────────────────────────────────────────────────────────────────────┐\n");
        printf("|                             Módulo Funcionário                              |\n");
        printf("|                                                                             |\n");
        printf("| 1. Cadastrar Novo Funcionário                                               |\n");
        printf("| 2. Pesquisar os Dados do Funcionário                                        |\n");
        printf("| 3. Atualizar o Cadastro do Funcionário                                      |\n");
        printf("| 4. Excluir Funcionário do Sistema                                           |\n");
        printf("| 0. Sair                                                                     |\n");
        printf("|                                                                             |\n");
        printf("└─────────────────────────────────────────────────────────────────────────────┘\n"); 
        printf("──────────────────────────────────────────────────────────────────────────────\n");
        printf("\n");
        printf("            Escolha a opção desejada: ");
        scanf("%c", &op);
        getchar();
        printf("\n");
        printf("──────────────────────────────────────────────────────────────────────────────\n");
        switch (op) {
        case '1':
            cadastra_funcionario();
            break;
        case '2':
            pesquisa_funcionario();
            break;
        case '3':
            atualiza_funcionario();
            break;
        case '4':
            exclui_funcionario();
            break;
        case '0':
            printf("Voltando para o menu principal\n");
                printf("\n");
            printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
                getchar();
            break;
        default:
            printf("Opção inválida, digite um número entre as opções disponíveis\n");
            printf("\n");
            printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
                getchar(); 
            break;
        }
    } while (op != '0');
}

void cadastra_funcionario(void) {

    system("clear||cls");
    printf("\n");
    printf("┌─────────────────────────────────────────────────────────────────────────────┐\n");
    printf("|                                 BuyYourCar                                  |\n");
    printf("└─────────────────────────────────────────────────────────────────────────────┘\n");
    printf("┌─────────────────────────────────────────────────────────────────────────────┐\n");
    printf("|                             Cadastrar Funcionário                           |\n");
    printf("|                                                                             |\n");
    printf("| Insira os dados do funcionário:                                             |\n");
    printf("|                                                                             |\n");
    printf("|_____________________________________________________________________________|\n");

    struct Funcionario func;

    // Aloca memória para os campos da struct
    alocar_dados(&func);

    // Ler os dados do usuário
    ler_dados(&func);

    // Exibir os dados lidos
    exibir_dados(&func);

    // Salvar os dados em um arquivo binário
    salvar_dados_binario(&func, "valid_func.dat");

    // Liberar a memória alocada
    liberar_dados(&func);

    // Para carregar os dados de volta de um arquivo binário
    struct Funcionario func_carregado;
    alocar_dados(&func_carregado);  // Aloca memória para os dados do funcionário carregado

    carregar_dados_binario(&func_carregado, "valid_func.dat");

    // Exibir os dados carregados
    printf("\nDados carregados do arquivo:\n");
    exibir_dados(&func_carregado);

    // Liberar memória após carregar os dados
    liberar_dados(&func_carregado);

    return 0;
    printf("\n"); 
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar(); 

}  

void pesquisa_funcionario(void) {
    
    system("clear||cls");
    printf("\n");
    printf("┌─────────────────────────────────────────────────────────────────────────────┐\n");
    printf("|                                 BuyYourCar                                  |\n");
    printf("└─────────────────────────────────────────────────────────────────────────────┘\n");
    printf("┌─────────────────────────────────────────────────────────────────────────────┐\n");
    printf("|                         Pesquisar Dados do Funcionário                      |\n");
    printf("|                                                                             |\n");
    printf("| Insira os dados:                                                            |\n");
    printf("|                                                                             |\n");
    printf("└─────────────────────────────────────────────────────────────────────────────┘\n");
    const char *nome_arquivo = "funcionario.dat";
    char cpf_buscar[12];

    // Solicita o CPF a ser buscado
    printf("Digite o CPF a ser buscado (11 dígitos): ");
    fgets(cpf_buscar, 12, stdin);
    cpf_buscar[strcspn(cpf_buscar, "\n")] = '\0';  // Remove o caractere de nova linha

    // Chama a função para buscar o funcionário pelo CPF
    buscar_dados_por_cpf(nome_arquivo, cpf_buscar);

    return 0;
    printf("\n"); 
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n"); 
    getchar(); 
}  


void atualiza_funcionario(void) {
    
    system("clear||cls");
    printf("\n");
    printf("┌─────────────────────────────────────────────────────────────────────────────┐\n");
    printf("|                                 BuyYourCar                                  |\n");
    printf("└─────────────────────────────────────────────────────────────────────────────┘\n");
    printf("┌─────────────────────────────────────────────────────────────────────────────┐\n");
    printf("|                       Atualizar Cadastro do Funcionário                     |\n");
    printf("|                                                                             |\n");
    printf("| Insira os dados:                                                            |\n");
    printf("|                                                                             |\n");
    printf("└─────────────────────────────────────────────────────────────────────────────┘\n");
    struct Funcionario funcionario;

    // Alocar memória para os dados do funcionário
    alocar_funcionario(&funcionario);

    // Ler os dados do funcionário
    ler_funcionario(&funcionario);

    // Exibir os dados lidos
    exibir_funcionario(&funcionario);

    // Salvar os dados em um arquivo binário
    salvar_funcionario_binario(&funcionario, "funcionarios.bin");

    // Alterar dados de um funcionário existente (supondo que o CPF seja "12345678901")
    alterar_funcionario_por_cpf("funcionarios.bin", "12345678901");

    // Liberar a memória alocada
    liberar_funcionario(&funcionario);

    return 0;
    printf("\n"); 
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n"); 
    getchar(); 
}  


void exclui_funcionario(void) {
    
    system("clear||cls");
    printf("\n");
    printf("┌─────────────────────────────────────────────────────────────────────────────┐\n");
    printf("|                                 BuyYourCar                                  |\n");
    printf("└─────────────────────────────────────────────────────────────────────────────┘\n");
    printf("┌─────────────────────────────────────────────────────────────────────────────┐\n");
    printf("|                       Excluir Funcionário do Sistema                        |\n");
    printf("|                                                                             |\n");
    printf("| Informe o CPF(Apenas Números):                                              |\n");
    printf("|                                                                             |\n");
    printf("└─────────────────────────────────────────────────────────────────────────────┘\n");
    printf("\n"); 
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n"); 
    getchar(); 
}   
