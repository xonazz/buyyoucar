#include <stdio.h> 
#include <stdlib.h>
#include "cliente.h"

void tela_cliente(void) {
    char op;
    do {
        system("clear||cls");
        printf("\n");
        printf("┌─────────────────────────────────────────────────────────────────────────────┐\n");
        printf("|                                 BuyYourCar                                  |\n");
        printf("└─────────────────────────────────────────────────────────────────────────────┘\n");
        printf("┌─────────────────────────────────────────────────────────────────────────────┐\n");
        printf("|                                Menu Cliente                                 |\n");
        printf("|                                                                             |\n");
        printf("| 1. Cadastrar um Novo Cliente                                                |\n");
        printf("| 2. Procurar um Cliente                                                      |\n");
        printf("| 3. Alterar Dados do Cliente                                                 |\n");
        printf("| 4. Excluir Cliente                                                          |\n");
        printf("| 0. Voltar ao Menu                                                           |\n");
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
                cadastra_cliente();
            break;
            case '2':
                pesquisa_cliente();
            break;
            case '3':
                atualiza_cliente();
            break;
            case '4':
                exclui_cliente();
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

void cadastra_cliente(void) {	

    system("clear||cls");	
    printf("\n");
    printf("┌─────────────────────────────────────────────────────────────────────────────┐\n");
    printf("|                                 BuyYourCar                                  |\n");
    printf("└─────────────────────────────────────────────────────────────────────────────┘\n");
    printf("┌─────────────────────────────────────────────────────────────────────────────┐\n");
    printf("|                                Cadastrar Cliente                            |\n");
    printf("|                                                                             |\n");
    printf("| Insira os dados:                                                            |\n");
    printf("|                                                                             |\n");
    printf("|_____________________________________________________________________________|\n");

    // Criar e obter dados da pessoa
    Pessoa* pessoa = criar_pessoa();

    if (pessoa != NULL) {
        // Imprimir os dados coletados
        imprimir_pessoa(pessoa);

        // Salvar os dados no arquivo
        salvar_pessoa_em_arquivo(pessoa);

        // Liberar memória alocada
        free(pessoa);
    }

}

void pesquisa_cliente(void) {	

    system("clear||cls");	
    printf("\n");
    printf("┌─────────────────────────────────────────────────────────────────────────────┐\n");
    printf("|                                 BuyYourCar                                  |\n");
    printf("└─────────────────────────────────────────────────────────────────────────────┘\n");
    printf("┌─────────────────────────────────────────────────────────────────────────────┐\n");
    printf("|                                Pesquisar Cliente                            |\n");
    printf("|                                                                             |\n");
    printf("| Insira os dados:                                                            |\n");
    printf("|                                                                             |\n");
    printf("└─────────────────────────────────────────────────────────────────────────────┘\n");

    char cpf[100];

    printf("Digite o CPF a ser verificado: ");
    fgets(cpf, sizeof(cpf), stdin);
    cpf[strcspn(cpf, "\n")] = '\0';  // Remove o '\n' no final da string

    verificar_cpf_no_arquivo(cpf);  // Chama a função para verificar o CPF e imprimir as informações

    return 0;
}


void atualiza_cliente(void) {

    system("clear||cls");		
    printf("\n");
    printf("┌─────────────────────────────────────────────────────────────────────────────┐\n");
    printf("|                                 BuyYourCar                                  |\n");
    printf("└─────────────────────────────────────────────────────────────────────────────┘\n");
    printf("┌─────────────────────────────────────────────────────────────────────────────┐\n");
    printf("|                         Atualizar o Cadastro do Cliente                     |\n");
    printf("|                                                                             |\n");
    printf("| Insira os dados:                                                            |\n");
    printf("|                                                                             |\n");
    printf("└─────────────────────────────────────────────────────────────────────────────┘\n");
    char cpf[100];

    printf("Digite o CPF do cliente que deseja alterar: ");
    fgets(cpf, sizeof(cpf), stdin);
    cpf[strcspn(cpf, "\n")] = '\0';  // Remove o '\n' no final da string

    // Chama a função para buscar e alterar os dados do cliente
    if (buscar_e_alterar_cpf_no_arquivo(cpf)) {
        printf("Dados alterados com sucesso.\n");
    } else {
        printf("Não foi possível alterar os dados.\n");
    }

    return 0;
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
    printf("\n");
}


void exclui_cliente(void) {

    system("clear||cls");		
    printf("\n");
    printf("┌─────────────────────────────────────────────────────────────────────────────┐\n");
    printf("|                                 BuyYourCar                                  |\n");
    printf("└─────────────────────────────────────────────────────────────────────────────┘\n");
    printf("┌─────────────────────────────────────────────────────────────────────────────┐\n");
    printf("|                         Excluir Cliente do Sistema                          |\n");
    printf("|                                                                             |\n");
    printf("| Insira os dados:                                                            |\n");
    printf("|                                                                             |\n");
    printf("└─────────────────────────────────────────────────────────────────────────────┘\n");
    char cpf[100];

    printf("Digite o CPF do cliente que deseja deletar: ");
    fgets(cpf, sizeof(cpf), stdin);
    cpf[strcspn(cpf, "\n")] = '\0';  // Remove o '\n' no final da string

    // Chama a função para deletar os dados associados ao CPF
    if (deletar_cpf_no_arquivo(cpf)) {
        printf("Dados deletados com sucesso.\n");
    } else {
        printf("Não foi possível deletar os dados.\n");
    }

    return 0;
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
    printf("\n");
}
