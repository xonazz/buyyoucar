#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include "veiculo.h"
#include "entradas.h"


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

    char situacao[20];

     Veiculo *veiculo = (Veiculo*) malloc(sizeof(Veiculo));      // Aloca dinamicamente memória para a estrutura Cliente
    if (veiculo == NULL) {
        perror("Erro ao alocar memória em veículo");
        exit(1);
    }

    FILE* fp;  // Ponteiro para o arquivo
    

    
    system("clear||cls");
    printf("\n");
    printf("┌─────────────────────────────────────────────────────────────────────────────┐\n");
    printf("|                                 BuyYourCar                                  |\n");
    printf("└─────────────────────────────────────────────────────────────────────────────┘\n");
    printf("┌─────────────────────────────────────────────────────────────────────────────┐\n");
    printf("|                              Cadastrar Veículo                              |\n");
    printf("|                                                                             |\n");
    printf("| Insira os dados                                                             |\n");
    printf("|                                                                             |\n");
    printf("└─────────────────────────────────────────────────────────────────────────────┘\n");

    

     // Lê o CPF e verifica se já está cadastrado
    do {
         lePlaca(veiculo);// Lê e valida o CPF do cliente
        if (verificaPlacaCadastrada(veiculo->placa)) {
            printf("\nErro: Placa cadastra %s já cadastrada!\n", veiculo->placa);
            printf("Tente novamente.\n");
        } else {
            break; // CPF não está duplicado, sai do loop
        }
    } while (1); // Continua até o CPF ser válido e único
    leMarca(veiculo);
    leModelo(veiculo);
    leAno(veiculo);


        veiculo->sit = 'd';                  // Coloca o status do cliente como 'ativo'
        strcpy(situacao, "Disponível"); 

      // Exibe as informações para o usuário
    getchar();
    printf("+---------------------------------------------------------------------------+\n");
    printf("|                                                                           |\n");
    printf("| Veiculo cadastrado com sucesso\n");
    printf("|\n");
    printf("| Placa: %s\n", veiculo->placa);
    printf("| Marca: %s\n", veiculo->marca);
    printf("| Modelo: %s\n", veiculo->modelo);
    printf("| ano de fabricação: %s\n", veiculo->anodf);
    printf("| Situação do veículo %s\n", situacao);
    printf("|                                                                           |\n");
    printf("+---------------------------------------------------------------------------+\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
    

 fp = fopen ("veiculos.dat", "ab");
    if(fp == NULL) {
        perror("Erro ao abrir o arquivo veiculos.dat");
        exit(1);  // Mantém a saída do programa caso haja um erro ao abrir o arquivo
    }
    fwrite(veiculo, sizeof(Veiculo), 1, fp);

    fclose (fp);  //Fecha o arquivo
    free (veiculo);                        // libera memória da estrutura Cliente

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
    printf("| Informe a Placa:                                                            |\n");
    printf("|                                                                             |\n");
    printf("└─────────────────────────────────────────────────────────────────────────────┘\n");
   
   char placa_busca[13];
                                                   
    // Lê a placa
    lePlacaBusca(placa_busca);     // nova função parecida com o leCpfCliente mas para cpf_busca
    
    busca_placa(placa_busca);     // Busca o cliente pelo CPF informado e exibe-o 
}

// Função responsável por buscar e exibir os dados de um cliente com base no CPF informado
void busca_placa(const char *cpf_busca) {
    char situacao[20];    // Declaração de variável para armazenar a situação do cliente
    
    FILE *fp;
    Veiculo *veiculo;
    veiculo = (Veiculo*) malloc(sizeof(Veiculo));
    if (veiculo == NULL) {
        perror("Erro ao alocar memória em veiculo");
        exit(1);
    }

  
    fp = fopen("veiculos.dat", "rb");
    if (fp == NULL) {
        perror("Erro ao abrir o arquivo!\n");
        exit(1);
    }

    int encontrado = 0;
        // Ler os dados do arquivo cliente por cliente
    while (fread(veiculo, sizeof(Veiculo), 1, fp)) {
  

        // Verifica se o CPF corresponde ao que foi procurado
       if (strcmp(veiculo->placa, cpf_busca) == 0) {
            printf(" ____________________________________________________________________ \n");
            printf("| Veiculo encontrado                                                 |\n");
            printf("| Placa: %s                                           |\n",veiculo->placa );
            printf("| Modelo: %s                                            |\n",veiculo->modelo );
            printf("| Marca: %s                                          |\n",veiculo->marca);
            printf("| Ano de fabricação: %s                                      |\n",veiculo->anodf );


            // Verifica o status do cliente (ativo ou inativo)
            if (veiculo->sit == 'd') {
                strcpy(situacao, "Disponível");
            } else if (veiculo->sit == 'i') {
                strcpy(situacao, "Indisponível");
            } else {
                strcpy(situacao, "Não informado");
            }
        
            printf("| Situação do veículo: %s\n", situacao);
            printf("+---------------------------------------------------------------------------+\n");
            printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
            getchar();
            encontrado = 1;
            break; // Encerra o loop quando encontrar o cliente
        }
    }
    if (!encontrado) {
        printf("veículo não encontrado\n");
    }
    fclose(fp);  // Fecha o arquivo após o uso
    free (veiculo);                        // libera memória da estrutura Cliente
}


void atualiza_veiculo(void) { 

    char opcao[3];
    char placa_busca[13];
    int encontrado = 0;

    FILE *fp;
    Veiculo *veiculo;
    veiculo = (Veiculo*) malloc(sizeof(Veiculo));
    if (veiculo == NULL) {
        perror("Erro ao alocar memória em veiculo");
        exit(1);
    }

    
    system("clear||cls");
    printf("\n");
    printf("┌─────────────────────────────────────────────────────────────────────────────┐\n");
    printf("|                                 BuyYourCar                                  |\n");
    printf("└─────────────────────────────────────────────────────────────────────────────┘\n");
    printf("┌─────────────────────────────────────────────────────────────────────────────┐\n");
    printf("|                          Atualizar Dados do Veículo                         |\n");
    printf("|                                                                             |\n");
    printf("| Informe a Placa:                                                            |\n");
    printf("|                                                                             |\n");
    printf("└─────────────────────────────────────────────────────────────────────────────┘\n");
    
    // Abre o arquivo de clientes
    fp = fopen("veiculos.dat", "r+b");  // Abre o arquivo para leitura e escrita
    if (fp == NULL) {
        perror("Erro ao abrir o arquivo");
        exit(1);
    }
    while (fread(veiculo, sizeof(Veiculo), 1, fp)) {
        if (strcmp(veiculo->placa, placa_busca) == 0 && veiculo->sit == 'd') {
            encontrado = 1;  
     } do {
                printf("\nCliente encontrado:\n");
                printf("1. Placa: %s\n", veiculo->placa);
                printf("2. Marca: %s\n", veiculo->marca);
                printf("3. Modelo: %s\n", veiculo->modelo);
                printf("4. Ano de fabricação: %s\n", veiculo->anodf);
                printf("0. Sair da atualização\n");
                printf("\n");
                printf("Escolha o campo que deseja atualizar: ");
                
                // Lê a opção utilizando fgets
                fgets(opcao, sizeof(opcao), stdin); // Lê a opção como string
                opcao[strcspn(opcao, "\n")] = '\0'; // Remove o '\n' do final

                switch (opcao[0]) {  // Usa a primeira letra da opção
                    case '1':
                        lePlaca(veiculo);
                        break;
                    case '2':
                        leMarca(veiculo);
                        break;
                    case '3':
                        leModelo(veiculo);
                        break;
                    case '4':
                        leAno(veiculo);
                        break;
                    case '0':
                        printf("Finalizando a atualização...\n");
                        break;
                    default:
                        printf("Opção inválida.\n");
                }

                // Atualiza o cliente no arquivo após cada alteração
                if (opcao[0] >= '1' && opcao[0] <= '5') {
                    fseek(fp, -sizeof(Veiculo), SEEK_CUR);     // Volta para o início do registro
                    fwrite(veiculo, sizeof(Veiculo), 1, fp);
                    printf("Dados atualizados com sucesso!\n");
                }
            } while (opcao[0] != '0');

            break; // Sai do loop após encontrar e atualizar o cliente
        }

    if (!encontrado) {
        printf("Veiculo com placa %s não encontrado ou indisponível.\n", placa_busca);}

        fclose(fp);
    free (veiculo);                        // libera memória da estrutura Cliente
    printf("|                                                                           |\n");
    printf("+---------------------------------------------------------------------------+\n");

    }
  

void exclui_veiculo(void) {
    char situacao[20];
    char placa_busca[13];
    int encontrado = 0;

    FILE *fp;
    Veiculo *veiculo;
    veiculo = (Veiculo*) malloc(sizeof(Veiculo));
    if (veiculo == NULL) {
        perror("Erro ao alocar memória em veiculo");
        exit(1);
    }
    
    system("clear||cls");
    printf("\n");
    printf("┌─────────────────────────────────────────────────────────────────────────────┐\n");
    printf("|                                 BuyYourCar                                  |\n");
    printf("└─────────────────────────────────────────────────────────────────────────────┘\n");
    printf("┌─────────────────────────────────────────────────────────────────────────────┐\n");
    printf("|                          Excluir Veículo do Sistema                         |\n");
    printf("|                                                                             |\n");
    printf("| Insira os dados                                                             |\n");
    printf("|                                                                             |\n");
    printf("└─────────────────────────────────────────────────────────────────────────────┘\n");
    
    // Lê o CPF
    lePlacaBusca(placa_busca);

    // Abre o arquivo original para leitura
    fp = fopen("veiculos.dat", "r+b");
    if (fp == NULL) {
        perror("Erro ao abrir o arquivo original!\n");
        exit(1);
    }

    // Lê os registros do arquivo original e encontra o cliente
    while (fread(veiculo, sizeof(Veiculo), 1, fp)) {
        // Se o CPF corresponder, exibe os dados do cliente
        if (strcmp(veiculo->placa, placa_busca) == 0 && veiculo->sit == 'd') {
            
            // Exibe a situação do cliente
            if (veiculo->sit == 'd') {
                strcpy(situacao, "Disponível");
            } else if (veiculo->sit == 'i') {
                strcpy(situacao, "Indisponível");
            } else {
                strcpy(situacao, "Não informado");
            }
            
            printf("+---------------------------------------------------------------------------+\n");
            printf("| Veiculo encontrado\n");
            printf("| Placa: %s\n", veiculo->placa);
            printf("| Marca: %s\n", veiculo->marca);
            printf("| Modelo: %s\n", veiculo->modelo);
            printf("| Ano de fabricação: %s\n", veiculo->anodf);
            printf("| Situação do veículo: %s\n", situacao);  // Exibe a situação do veiculo
            printf("+---------------------------------------------------------------------------+\n");

            // Pergunta para o usuário se deseja excluir
            char confirmacao[3];  // Usar um array de 2 caracteres
            printf("Tem certeza que deseja excluir este cliente? (S/N): ");
            fgets(confirmacao, sizeof(confirmacao), stdin);
            // Remove o '\n' que pode ser deixado no buffer por causa do fgets
            confirmacao[strcspn(confirmacao, "\n")] = 0;

            // Trata a confirmação (sem considerar maiúsculas/minúsculas)
            if (confirmacao[0] == 'S' || confirmacao[0] == 's' || confirmacao[0] == 'Y' || confirmacao[0] == 'y') {
                
                // Marca o cliente como inativo
                veiculo->sit = 'i';
                fseek(fp, -sizeof(Veiculo), SEEK_CUR); // Volta ao início do registro atual
                fwrite(veiculo, sizeof(Veiculo), 1, fp); // Atualiza o registro no arquivo

                printf("\nVeiculo com placa %s foi marcado como indisponível.\n", placa_busca);
                printf("Pressione Enter para continuar...\n");
                getchar(); // Aguarda o usuário pressionar Enter antes de continuar
            } else {
                printf("\nExclusão cancelada.\n");
                printf("Pressione Enter para voltar ao menu...\n");
                getchar(); // Aguarda o usuário pressionar Enter antes de voltar
            }
            encontrado = 1;
            break; // Sai do loop após encontrar o cliente
        }
    }

    // Se o cliente não for encontrado
    if (!encontrado) {
        printf("Veiculo com placa %s não encontrado ou indisponível.\n", placa_busca);
        printf("Pressione Enter para continuar...\n");
        getchar(); // Aguarda o usuário pressionar Enter antes de continuar
    }

    fclose(fp); // Fecha o arquivo após o uso
    free(veiculo); // Libera a memória alocada
}

void lePlacaBusca (char *placa_busca) {
    printf("|-> Placa (apenas caracteres):  ");     // Criar uma nova função parecida com o leCpfCliente mas para cpf_busca
    do {
        fgets(placa_busca, 13, stdin);
        placa_busca[strcspn(placa_busca, "\n")] = '\0';  // Remove o '\n' do final

        if (verificarPlacaValida(placa_busca)) {
            printf("Placa válida\n");
            break;
        } else {
            printf("Placa inválida, tente novamente apertando a tecla ENTER\n");
            getchar();  // Aguarda a tecla ENTER para evitar erro de input
        }
    } while (!verificarPlacaValida(placa_busca));  // Continua até o CPF ser válido
}

int verificaPlacaCadastrada(const char *placa) {
    FILE *fp;
    Veiculo veiculo;

    // Abre o arquivo de clientes para leitura
    fp = fopen("veiculos.dat", "rb");
    if (fp == NULL) {
        perror("Erro ao abrir o arquivo de veiculos");
        return 0;  // Retorna 0 para indicar erro na abertura do arquivo
    }

    // Lê os clientes do arquivo
    while (fread(&veiculo, sizeof(Veiculo), 1, fp)) {
        if (strcmp(veiculo.placa, placa) == 0) {
            fclose(fp);
            return 1;  // Retorna 1 se o CPF já estiver cadastrado
        }
    }

    fclose(fp);
    return 0;  // Retorna 0 se o CPF não estiver cadastrado
}

