#include <stdio.h> 
#include <stdlib.h>
#include "veiculo.h"

void tela_veiculo(void) {
    char op;  
    do { 
        system("clear||cls");
        printf("\n");
        printf("┌─────────────────────────────────────────────────────────────────────────────┐\n");
        printf("|                                 BuyYourCar                                  |\n");
        printf("└─────────────────────────────────────────────────────────────────────────────┘\n");
        printf("┌─────────────────────────────────────────────────────────────────────────────┐\n");
        printf("|                                Módulo Veículo                               |\n");
        printf("|                                                                             |\n");
        printf("| 1. Cadastrar Veículo                                                        |\n");
        printf("| 2. Pesquisar Dados do Veículo                                               |\n");
        printf("| 3. Atualizar Dados do Veículo                                               |\n");
        printf("| 4. Excluir Veículo do Sistema                                               |\n");
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
            cadastra_veiculo();
            break;
        case '2':
            pesquisa_veiculo();
            break;
        case '3':
            atualiza_veiculo();
            break;
        case '4':
            exclui_veiculo();
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

void cadastra_veiculo(void) {
    
    system("clear||cls");
    printf("\n");
    printf("┌─────────────────────────────────────────────────────────────────────────────┐\n");
    printf("|                                 BuyYourCar                                  |\n");
    printf("└─────────────────────────────────────────────────────────────────────────────┘\n");
    printf("┌─────────────────────────────────────────────────────────────────────────────┐\n");
    printf("|                              Cadastrar Veículo                              |\n");
    printf("| Informe os dados:                                                           |\n");
    printf("|                                                                             |\n"); 
    printf("|_____________________________________________________________________________|\n");
    
    // Exemplo de como utilizar
    Veiculo* veiculo = cria_veiculo("ABCD-123", "Fiat", "Palio", 2020);

    if (veiculo != NULL) {
        exibe_veiculo(veiculo);  // Exibe os dados do veículo
        salvar_veiculo_em_arquivo(veiculo);  // Salva os dados no arquivo
    }

    // Libera a memória alocada
    free(veiculo);
    
    return 0;

    printf("\n"); 
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n"); 
    getchar(); 
}  

void pesquisa_veiculo(void) {
    
    system("clear||cls");
    printf("\n");
    printf("┌─────────────────────────────────────────────────────────────────────────────┐\n");
    printf("|                                 BuyYourCar                                  |\n");
    printf("└─────────────────────────────────────────────────────────────────────────────┘\n");
    printf("┌─────────────────────────────────────────────────────────────────────────────┐\n");
    printf("|                           Pesquisar Dados do Veículo                        |\n");
    printf("|                                                                             |\n");
    printf("| Informe os dados:                                                           |\n");
    printf("|                                                                             |\n");
    printf("└─────────────────────────────────────────────────────────────────────────────┘\n"); 
    char placa_buscar[9];

    printf("Digite a placa do veículo para buscar: ");
    fgets(placa_buscar, sizeof(placa_buscar), stdin);
    placa_buscar[strcspn(placa_buscar, "\n")] = '\0';  // Remove o caractere '\n'

    // Chama a função de busca
    buscar_veiculo_por_placa(placa_buscar);

    return 0;
    printf("\n"); 
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n"); 
    getchar(); 
} 


void atualiza_veiculo(void) {
    
    system("clear||cls");
    printf("\n");
    printf("┌─────────────────────────────────────────────────────────────────────────────┐\n");
    printf("|                                 BuyYourCar                                  |\n");
    printf("└─────────────────────────────────────────────────────────────────────────────┘\n");
    printf("┌─────────────────────────────────────────────────────────────────────────────┐\n");
    printf("|                          Atualizar Dados do Veículo                         |\n");
    printf("|                                                                             |\n");
    printf("| Informe os dados:                                                           |\n");
    printf("|                                                                             |\n");
    printf("└─────────────────────────────────────────────────────────────────────────────┘\n");
    char placa_buscar[9];

    printf("Digite a placa do veículo para modificar: ");
    fgets(placa_buscar, sizeof(placa_buscar), stdin);
    placa_buscar[strcspn(placa_buscar, "\n")] = '\0';  // Remove o caractere '\n'

    // Chama a função para modificar o veículo
    modificar_veiculo_por_placa(placa_buscar);

    return 0;
    printf("\n"); 
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n"); 
    getchar(); 
}  

void exclui_veiculo(void) {
    
    system("clear||cls");
    printf("\n");
    printf("┌─────────────────────────────────────────────────────────────────────────────┐\n");
    printf("|                                 BuyYourCar                                  |\n");
    printf("└─────────────────────────────────────────────────────────────────────────────┘\n");
    printf("┌─────────────────────────────────────────────────────────────────────────────┐\n");
    printf("|                          Excluir Veículo do Sistema                         |\n");
    printf("|                                                                             |\n");
    printf("| Informe a Placa:                                                            |\n");
    printf("|                                                                             |\n");
    printf("└─────────────────────────────────────────────────────────────────────────────┘\n");
    printf("\n"); 
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n"); 
    getchar(); 
} 
