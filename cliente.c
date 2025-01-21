#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include "cliente.h"
#include "validacao.h"
#include "entradas.h"


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

    char situacao[20];
    
    Cliente *cliente = (Cliente*) malloc(sizeof(Cliente));      // Aloca dinamicamente memória para a estrutura Cliente
    if (cliente == NULL) {
        perror("Erro ao alocar memória em cliente");
        exit(1);
    }

    FILE* fp;  // Ponteiro para o arquivo
    

    system("clear||cls");	
    printf("\n");
    printf("┌─────────────────────────────────────────────────────────────────────────────┐\n");
    printf("|                                 BuyYourCar                                  |\n");
    printf("└─────────────────────────────────────────────────────────────────────────────┘\n");
    printf("┌─────────────────────────────────────────────────────────────────────────────┐\n");
    printf("|                                Cadastrar Cliente                            |\n");
    printf("|                                                                             |\n");
    printf("| Insira os dados                                                             |\n");
    printf("|_____________________________________________________________________________|\n"); 

    leNomeCliente(cliente);      

     // Lê o CPF e verifica se já está cadastrado
    do {
        leCpfCliente(cliente); // Lê e valida o CPF do cliente
        if (verificaCpfCadastrado(cliente->cpf)) {
            printf("\nErro: CPF %s já cadastrado!\n", cliente->cpf);
            printf("Tente novamente.\n");
        } else {
            break; // CPF não está duplicado, sai do loop
        }
    } while (1); // Continua até o CPF ser válido e único
    
     leEmailCliente(cliente); 

     leCnhCliente(cliente);
    
     leFoneCliente(cliente);

        cliente->status = 'a';                  // Coloca o status do cliente como 'ativo'
        strcpy(situacao, "Ativo"); 

      // Exibe as informações para o usuário
    printf("+---------------------------------------------------------------------------+\n");
    printf("|                                                                           |\n");
    printf("| Cliente cadastrado com sucesso\n");
    printf("|\n");
    printf("| Nome: %s\n", cliente->nome);
    printf("| CPF: %s\n", cliente->cpf);
    printf("| Email: %s\n", cliente->email);
    printf("| Carteita de motorista: %s\n", cliente->cnh);
    printf("| Número de telefone: %s\n", cliente->fone);
    printf("| Situação do cliente: %s\n", situacao);
    printf("|                                                                           |\n");
    printf("+---------------------------------------------------------------------------+\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
    

 fp = fopen ("clientes.dat", "ab");
    if(fp == NULL) {
        perror("Erro ao abrir o arquivo clientes.dat");
        exit(1);  // Mantém a saída do programa caso haja um erro ao abrir o arquivo
    }
    fwrite(cliente, sizeof(Cliente), 1, fp);

    fclose (fp);  //Fecha o arquivo
    free (cliente);                        // libera memória da estrutura Cliente

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
    printf("| Insira os dados                                                             |\n");
    printf("|                                                                             |\n");
    printf("└─────────────────────────────────────────────────────────────────────────────┘\n");
    char cpf_busca[13];
                                                   
    // Lê o CPF
    leCpfBusca(cpf_busca);     // nova função parecida com o leCpfCliente mas para cpf_busca
    
    busca_cliente(cpf_busca);     // Busca o cliente pelo CPF informado e exibe-o 
}

// Função responsável por buscar e exibir os dados de um cliente com base no CPF informado
void busca_cliente (const char *cpf_busca) {
    char situacao[20];    // Declaração de variável para armazenar a situação do cliente
    
    FILE *fp;
    Cliente *cliente;
    cliente = (Cliente*) malloc(sizeof(Cliente));
    if (cliente == NULL) {
        perror("Erro ao alocar memória em cliente");
        exit(1);
    }

  
    fp = fopen("clientes.dat", "rb");
    if (fp == NULL) {
        perror("Erro ao abrir o arquivo!\n");
        exit(1);
    }

    int encontrado = 0;
        // Ler os dados do arquivo cliente por cliente
    while (fread(cliente, sizeof(Cliente), 1, fp)) {
  

        // Verifica se o CPF corresponde ao que foi procurado
       if (strcmp(cliente->cpf, cpf_busca) == 0) {
            printf(" ____________________________________________________________________ \n");
            printf("| Cliente encontrado                                                 |\n");
            printf("| Nome: %s                                           |\n",cliente->nome );
            printf("| CPF: %s                                            |\n",cliente->cpf  );
            printf("| Email: %s                                          |\n",cliente->email);
            printf("| N° da CNH: %s                                      |\n",cliente->cnh  );
            printf("| Telefone: %s                                       |\n",cliente->fone );
            printf("|____________________________________________________________________|\n");

            // Verifica o status do cliente (ativo ou inativo)
            if (cliente->status == 'a') {
                strcpy(situacao, "Ativo");
            } else if (cliente->status == 'i') {
                strcpy(situacao, "Inativo");
            } else {
                strcpy(situacao, "Não informado");
            }
        
            printf("| Situação do cliente: %s\n", situacao);
            printf("+---------------------------------------------------------------------------+\n");
            printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
            getchar();
            encontrado = 1;
            break; // Encerra o loop quando encontrar o cliente
        }
    }
    if (!encontrado) {
        printf("Cliente não encontrado\n");
    }
    fclose(fp);  // Fecha o arquivo após o uso
    free (cliente);                        // libera memória da estrutura Cliente
}



void atualiza_cliente(void) {

    char opcao[3];
    char cpf_busca[13];
    int encontrado = 0;

    FILE *fp;
    Cliente *cliente;
    cliente = (Cliente*) malloc(sizeof(Cliente));
    if (cliente == NULL) {
        perror("Erro ao alocar memória em cliente");
        exit(1);
    }

    system("clear||cls");		
    printf("\n");
    printf("┌─────────────────────────────────────────────────────────────────────────────┐\n");
    printf("|                                 BuyYourCar                                  |\n");
    printf("└─────────────────────────────────────────────────────────────────────────────┘\n");
    printf("┌─────────────────────────────────────────────────────────────────────────────┐\n");
    printf("|                         Atualizar o Cadastro do Cliente                     |\n");
    printf("|                                                                             |\n");
    printf("| Insira os dados                                                             |\n");
    printf("|                                                                             |\n");
    printf("└─────────────────────────────────────────────────────────────────────────────┘\n");

    // Abre o arquivo de clientes
    fp = fopen("clientes.dat", "r+b");  // Abre o arquivo para leitura e escrita
    if (fp == NULL) {
        perror("Erro ao abrir o arquivo");
        exit(1);
    }
    while (fread(cliente, sizeof(Cliente), 1, fp)) {
        if (strcmp(cliente->cpf, cpf_busca) == 0 && cliente->status == 'a') {
            encontrado = 1;  
     } do {
                printf("\nCliente encontrado:\n");
                printf("1. Nome: %s\n", cliente->nome);
                printf("2. CPF: %s\n", cliente->cpf);
                printf("3. Email: %s\n", cliente->email);
                printf("4. Data: %s\n", cliente->cnh);
                printf("5. Telefone: %s\n", cliente->fone);
                printf("0. Sair da atualização\n");
                printf("\n");
                printf("Escolha o campo que deseja atualizar: ");
                
                // Lê a opção utilizando fgets
                fgets(opcao, sizeof(opcao), stdin); // Lê a opção como string
                opcao[strcspn(opcao, "\n")] = '\0'; // Remove o '\n' do final

                switch (opcao[0]) {  // Usa a primeira letra da opção
                    case '1':
                        leNomeCliente(cliente);
                        break;
                    case '2':
                        leCpfCliente(cliente);
                        break;
                    case '3':
                        leEmailCliente(cliente);
                        break;
                    case '4':
                        leCnhCliente(cliente);
                        break;
                    case '5':
                        leFoneCliente(cliente);
                        break;
                    case '0':
                        printf("Finalizando a atualização...\n");
                        break;
                    default:
                        printf("Opção inválida.\n");
                }

                // Atualiza o cliente no arquivo após cada alteração
                if (opcao[0] >= '1' && opcao[0] <= '5') {
                    fseek(fp, -sizeof(Cliente), SEEK_CUR);     // Volta para o início do registro
                    fwrite(cliente, sizeof(Cliente), 1, fp);
                    printf("Dados atualizados com sucesso!\n");
                }
            } while (opcao[0] != '0');

            break; // Sai do loop após encontrar e atualizar o cliente
        }

    if (!encontrado) {
        printf("Cliente com CPF %s não encontrado ou inativo.\n", cpf_busca);}

        fclose(fp);
    free (cliente);                        // libera memória da estrutura Cliente
    printf("|                                                                           |\n");
    printf("+---------------------------------------------------------------------------+\n");

    }


void exclui_cliente(void) {

    char situacao[20];   // Declaração de variável para armazenar a situação do cliente
    char cpf_busca[13];
    FILE *fp;
    int encontrado = 0;
    
    Cliente *cliente;
    cliente = (Cliente*) malloc(sizeof(Cliente));
    if (cliente == NULL) {
        perror("Erro ao alocar memória em cliente");
        exit(1);
    }
    

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
   
    // Lê o CPF
    leCpfBusca(cpf_busca);

    // Abre o arquivo original para leitura
    fp = fopen("clientes.dat", "r+b");
    if (fp == NULL) {
        perror("Erro ao abrir o arquivo original!\n");
        exit(1);
    }

    // Lê os registros do arquivo original e encontra o cliente
    while (fread(cliente, sizeof(Cliente), 1, fp)) {
        // Se o CPF corresponder, exibe os dados do cliente
        if (strcmp(cliente->cpf, cpf_busca) == 0 && cliente->status == 'a') {
            
            // Exibe a situação do cliente
            if (cliente->status == 'a') {
                strcpy(situacao, "Ativo");
            } else if (cliente->status == 'i') {
                strcpy(situacao, "Inativo");
            } else {
                strcpy(situacao, "Não informado");
            }
            
            printf("+---------------------------------------------------------------------------+\n");
            printf("| Cliente encontrado\n");
            printf("| Nome: %s\n", cliente->nome);
            printf("| CPF: %s\n", cliente->cpf);
            printf("| Email: %s\n", cliente->email);
            printf("| Data de nascimento: %s\n", cliente->cnh);
            printf("| Telefone: %s\n", cliente->fone);
            printf("| Situação do cliente: %s\n", situacao);  // Exibe a situação do cliente
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
                cliente->status = 'i';
                fseek(fp, -sizeof(Cliente), SEEK_CUR); // Volta ao início do registro atual
                fwrite(cliente, sizeof(Cliente), 1, fp); // Atualiza o registro no arquivo

                printf("\nCliente com CPF %s foi marcado como inativo.\n", cpf_busca);
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
        printf("Cliente com CPF %s não encontrado ou já está inativo.\n", cpf_busca);
        printf("Pressione Enter para continuar...\n");
        getchar(); // Aguarda o usuário pressionar Enter antes de continuar
    }

    fclose(fp); // Fecha o arquivo após o uso
    free(cliente); // Libera a memória alocada
}


void leCpfBusca (char *cpf_busca) {
    printf("|-> CPF (somente números): ");     // Criar uma nova função parecida com o leCpfCliente mas para cpf_busca
    do {
        fgets(cpf_busca, 13, stdin);
        cpf_busca[strcspn(cpf_busca, "\n")] = '\0';  // Remove o '\n' do final

        if (verificar_cpf(cpf_busca)) {
            printf("CPF válido\n");
            break;
        } else {
            printf("CPF inválido, tente novamente apertando a tecla ENTER\n");
            getchar();  // Aguarda a tecla ENTER para evitar erro de input
        }
    } while (!verificar_cpf(cpf_busca));  // Continua até o CPF ser válido
}

int verificaCpfCadastrado(const char *cpf) {
    FILE *fp;
    Cliente cliente;

    // Abre o arquivo de clientes para leitura
    fp = fopen("clientes.dat", "rb");
    if (fp == NULL) {
        perror("Erro ao abrir o arquivo de clientes");
        return 0;  // Retorna 0 para indicar erro na abertura do arquivo
    }

    // Lê os clientes do arquivo
    while (fread(&cliente, sizeof(Cliente), 1, fp)) {
        if (strcmp(cliente.cpf, cpf) == 0) {
            fclose(fp);
            return 1;  // Retorna 1 se o CPF já estiver cadastrado
        }
    }

    fclose(fp);
    return 0;  // Retorna 0 se o CPF não estiver cadastrado
}

