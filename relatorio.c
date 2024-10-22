#include <stdio.h> 
#include <stdlib.h>
#include "relatorio.h"

void tela_relatorio(void) {
    char op;
    do {
        system("clear||cls");
        printf("\n");
        printf("┌─────────────────────────────────────────────────────────────────────────────┐\n");
        printf("|                                 BuyYourCar                                  |\n");
        printf("└─────────────────────────────────────────────────────────────────────────────┘\n");
        printf("┌─────────────────────────────────────────────────────────────────────────────┐\n");
        printf("|                                Menu Relatório                               |\n");
        printf("|                                                                             |\n");
        printf("| 1. Relatório dos Clientes                                                   |\n");
        printf("| 2. Relatório dos Veículos                                                   |\n");
        printf("| 3. Relatório dos Funcionários                                               |\n");
        printf("| 4. Relatório das Vendas                                                     |\n");
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
                relatorio_cliente();
            	  break;
            case '2':
                relatorio_veiculo();
            	  break;
            case '3':
                relatorio_funcionario();
            	  break;
            case '4':
                relatorio_venda();
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

void relatorio_cliente(void) {	
    system("clear||cls");	
    printf("\n");
    printf("┌─────────────────────────────────────────────────────────────────────────────┐\n");
    printf("|                                 BuyYourCar                                  |\n");
    printf("└─────────────────────────────────────────────────────────────────────────────┘\n");
    printf("┌─────────────────────────────────────────────────────────────────────────────┐\n");
    printf("|                           Relatório dos Clientes                            |\n");
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

void relatorio_veiculo(void) {	
    system("clear||cls");	
    printf("\n");
    printf("┌─────────────────────────────────────────────────────────────────────────────┐\n");
    printf("|                                 BuyYourCar                                  |\n");
    printf("└─────────────────────────────────────────────────────────────────────────────┘\n");
    printf("┌─────────────────────────────────────────────────────────────────────────────┐\n");
    printf("|                          Relatório dos Veículos                             |\n");
    printf("|                                                                             |\n");
    printf("| Placa:                                                                      |\n");
    printf("| Marca:                                                                      |\n");
    printf("| Modelo:                                                                     |\n");
    printf("| Ano de fabricação:                                                          |\n");
    printf("|                                                                             |\n");
    printf("└─────────────────────────────────────────────────────────────────────────────┘\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
    printf("\n");
}

void relatorio_funcionario(void) {
    system("clear||cls");		
    printf("\n");
    printf("┌─────────────────────────────────────────────────────────────────────────────┐\n");
    printf("|                                 BuyYourCar                                  |\n");
    printf("└─────────────────────────────────────────────────────────────────────────────┘\n");
    printf("┌─────────────────────────────────────────────────────────────────────────────┐\n");
    printf("|                           Relatório dos Funcionários                        |\n");
    printf("|                                                                             |\n");
    printf("| CPF (Apenas número) :                                                       |\n");
    printf("| Nome Completo:                                                              |\n");
    printf("| E-mail:                                                                     |\n");
    printf("| Data de nascimento(dd/mm/aaaa)                                              |\n");
    printf("| Celular (Apenas números) :                                                  |\n");
    printf("|                                                                             |\n");
    printf("└─────────────────────────────────────────────────────────────────────────────┘\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
    printf("\n");
}

void relatorio_venda(void) {
    system("clear||cls");		
    printf("\n");
    printf("┌─────────────────────────────────────────────────────────────────────────────┐\n");
    printf("|                                 BuyYourCar                                  |\n");
    printf("└─────────────────────────────────────────────────────────────────────────────┘\n");
    printf("┌─────────────────────────────────────────────────────────────────────────────┐\n");
    printf("|                             Relatório das Vendas                            |\n");
    printf("|                                                                             |\n");
    printf("| N° de protocolo:                                                            |\n");
    printf("| Data e hora:                                                                |\n");
    printf("| CPF do Comprador:                                                           |\n");
    printf("| CPF do Vendedor:                                                            |\n");
    printf("| Valor:                                                                      |\n");
    printf("|                                                                             |\n");
    printf("└─────────────────────────────────────────────────────────────────────────────┘\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
    printf("\n");
}
