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
    printf("| Nome Completo:                                                              |\n");
    printf("| CPF (Apenas Números):                                                       |\n");
    printf("| Número de Telefone (Apenas Números):                                        |\n");
    printf("| Número da CNH (Apenas Números):                                             |\n");
    printf("| E-mail:                                                                     |\n");
    printf("| Endereço: (Cidade, Bairro, Rua e Número)                                    |\n");
    printf("|                                                                             |\n");
    printf("└─────────────────────────────────────────────────────────────────────────────┘\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
    printf("\n");
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
    printf("| CPF (Apenas Números):                                                       |\n");
    printf("|                                                                             |\n");
    printf("└─────────────────────────────────────────────────────────────────────────────┘\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
    printf("\n");
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
    printf("| CPF (Apenas Números):                                                       |\n");
    printf("|                                                                             |\n");
    printf("└─────────────────────────────────────────────────────────────────────────────┘\n");
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
    printf("| CPF (Apenas Números):                                                       |\n");
    printf("|                                                                             |\n");
    printf("└─────────────────────────────────────────────────────────────────────────────┘\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
    printf("\n");
}
