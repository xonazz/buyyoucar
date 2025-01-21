#include <stdio.h> 
#include <stdlib.h> 
#include "venda.h" 
#include "entradas.h" 
#include "cliente.h" 
#include <string.h> 
#include "funcionario.h"
//esse módulo ainda não está pronto

void tela_venda(void) { 
    char op;
    do {
        system("clear||cls");
        printf("\n");
        printf("┌─────────────────────────────────────────────────────────────────────────────┐\n");
        printf("|                                 BuyYourCar                                  |\n");
        printf("└─────────────────────────────────────────────────────────────────────────────┘\n");
        printf("┌─────────────────────────────────────────────────────────────────────────────┐\n");
        printf("|                                Módulo Venda                                 |\n");
        printf("|                                                                             |\n");
        printf("| 1. Cadastrar Venda                                                          |\n");
        printf("| 2. Pesquisar Venda                                                          |\n");
        printf("| 3. Atualizar Venda                                                          |\n");
        printf("| 4. Excluir Venda                                                            |\n");
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
            cadastra_venda();
            break;
        case '2':
            pesquisa_venda();
            break;
        case '3':
            atualiza_venda();
            break;
        case '4':
            exclui_venda();
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

void cadastra_venda(void) { 

    char situacao[20];

    Funcionario *funcionario = (Funcionario*) malloc(sizeof(Funcionario));      // Aloca dinamicamente memória para a estrutura Cliente
    if (funcionario == NULL) {
        perror("Erro ao alocar memória em funcionário");
        exit(1);
    }

     Veiculo *veiculo = (Veiculo*) malloc(sizeof(Veiculo));      // Aloca dinamicamente memória para a estrutura Cliente
    if (veiculo == NULL) {
        perror("Erro ao alocar memória em veículo");
        exit(1);
    }
    
    Cliente *cliente = (Cliente*) malloc(sizeof(Cliente));      // Aloca dinamicamente memória para a estrutura Cliente
    if (cliente == NULL) {
        perror("Erro ao alocar memória em cliente");
        exit(1);
    }


    Venda *venda = (Venda*) malloc(sizeof(Venda));      // Aloca dinamicamente memória para a estrutura Cliente
    if (venda == NULL) {
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
    printf("|                             Cadastrar Venda                                 |\n");
    printf("|                                                                             |\n");
    printf("| Insira os dados                                                             |\n");
    printf("|                                                                             |\n");
    printf("└─────────────────────────────────────────────────────────────────────────────┘\n");
   
    do {
        leCpfVenda(venda); // Lê e valida o CPF do cliente
        if (verificaCpfCadastrado(cliente->cpf)) {
            printf("\nCPF indisponível %s   \n",cliente->cpf);
            printf("Tente novamente.\n");
        } else {
            strcpy(cliente->cpf,venda->cpfc);
            printf("CPF disponível %s", venda->cpfc);
            break; 
        }
    } while (0); // Continua até o CPF ser válido e único
    getchar(); 

    do {
        lePlacaVenda(venda); // Lê e valida o CPF do cliente
        if (verificaPlacaCadastrada(veiculo->placa)) {
            printf("\nPlaca indisponível %s   \n",veiculo->placa);
            printf("Tente novamente.\n");
        } else {
            strcpy(veiculo->placa,venda->placa);
            printf("Placa disponível %s", venda->placa);
            break; 
        }
    } while (0); // Continua até o CPF ser válido e único
    getchar(); 

    do {
        leCpffVenda(venda); // Lê e valida o CPF do cliente
        if (verificaCpfCadastradoF(funcionario->cpf)) {
            printf("\nCPF indisponível %s   \n",funcionario->cpf);
            printf("Tente novamente.\n");
        } else {
            strcpy(funcionario->cpf,venda->cpff);
            printf("CPF disponível %s", venda->cpff);
            break; 
        }
    } while (0); // Continua até o CPF ser válido e único
    getchar(); 


      leApenasValor(venda); 
      printf("Valor da venda: %.2f\n", venda->valor);
      getchar();
      leParcelaVenda(venda);
      getchar();
      leDataVenda(venda);
      getchar();
    
    veiculo->sit = 'i';                  
    strcpy(situacao, "Indisponível"); 

    getchar();

    printf("+---------------------------------------------------------------------------+\n");
    printf("|                                                                           |\n");
    printf("| Venda cadastrada com sucesso\n");
    printf("|\n");
    printf("| CPF do comprador:   %s\n",   venda->cpfc);
    printf("| CPF do vendedor:    %s\n",   venda->cpff);
    printf("| Placa do veículo:   %s\n",   venda->placa);
    printf("| Valor da compra:    %.2f\n", venda->valor);
    printf("| N° de parcelas:     %s\n",   venda->parce);
    printf("| Data da aquisição:  %s\n",   venda->data);
    printf("|                                                                           |\n");
    printf("+---------------------------------------------------------------------------+\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar(); 

    fp = fopen ("venda.dat", "ab");
    if(fp == NULL) {
        perror("Erro ao abrir o arquivo vendas.dat");
        exit(1);  // Mantém a saída do programa caso haja um erro ao abrir o arquivo
    }
    fwrite(venda, sizeof(Venda), 1, fp);

    fclose (fp);  //Fecha o arquivo
    free(venda);  
    free(veiculo); 
    free(cliente);                    

}  

void pesquisa_venda(void) {
    
    system("clear||cls");
    printf("\n");
    printf("┌─────────────────────────────────────────────────────────────────────────────┐\n");
    printf("|                                 BuyYourCar                                  |\n");
    printf("└─────────────────────────────────────────────────────────────────────────────┘\n");
    printf("┌─────────────────────────────────────────────────────────────────────────────┐\n");
    printf("|                              Pesquisar Venda                                |\n");
    printf("|                                                                             |\n");
    printf("| Informe o N° de protocolo:                                                  |\n");
    printf("|                                                                             |\n");
    printf("└─────────────────────────────────────────────────────────────────────────────┘\n");
    
     char cpf_busca[13];   

    // Lê o CPF
    leCpfBusca(cpf_busca);     // nova função parecida com o leCpfCliente mas para cpf_busca
    
    busca_venda(cpf_busca);     // Bu
} 

// Função responsável por buscar e exibir os dados de um cliente com base no CPF informado
void busca_venda (const char *cpf_busca) {
    char situacao[20];    // Declaração de variável para armazenar a situação do cliente
    
    FILE *fp;
    Venda *venda;
    venda = (Venda*) malloc(sizeof(Venda));
    if (venda == NULL) {
        perror("Erro ao alocar memória em venda");
        exit(1);
    }

  
    fp = fopen("vendas.dat", "rb");
    if (fp == NULL) {
        perror("Erro ao abrir o arquivo!\n");
        exit(1);
    }

    int encontrado = 0;
        // Ler os dados do arquivo cliente por cliente
    while (fread(venda, sizeof(venda), 1, fp)) {
  

        // Verifica se o CPF corresponde ao que foi procurado
       if (strcmp(venda->cpfc, cpf_busca) == 0) {
           printf("+---------------------------------------------------------------------------+\n");
    printf("|                                                                           |\n");
    printf("| Venda encontrada com sucesso\n");
    printf("|\n");
    printf("| CPF do comprador:   %s\n",   venda->cpfc);
    printf("| CPF do vendedor:    %s\n",   venda->cpff);
    printf("| Placa do veículo:   %s\n",   venda->placa);
    printf("| Valor da compra:    %.2f\n", venda->valor);
    printf("| N° de parcelas:     %s\n",   venda->parce);
    printf("| Data da aquisição:  %s\n",   venda->data);
    printf("|                                                                           |\n");
    printf("+---------------------------------------------------------------------------+\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar(); 
          
    if (!encontrado) {
        printf("Venda não encontrada\n");
    }
    fclose(fp);  // Fecha o arquivo após o uso
    free (venda);                        // libera memória da estrutura Cliente

       }}}

void atualiza_venda(void) { 

    char opcao[3];
    char cpf_busca[13];
    int encontrado = 0;

    FILE *fp;
    Venda *venda;
    venda = (Venda*) malloc(sizeof(Venda));
    if (venda == NULL) {
        perror("Erro ao alocar memória em venda");
        exit(1);
    }
    
    system("clear||cls");
    printf("\n");
    printf("┌─────────────────────────────────────────────────────────────────────────────┐\n");
    printf("|                                 BuyYourCar                                  |\n");
    printf("└─────────────────────────────────────────────────────────────────────────────┘\n");
    printf("┌─────────────────────────────────────────────────────────────────────────────┐\n");
    printf("|                              Atualizar Venda                                |\n");
    printf("|                                                                             |\n");
    printf("| Informe o N° de protocolo:                                                  |\n");
    printf("|                                                                             |\n");
    printf("└─────────────────────────────────────────────────────────────────────────────┘\n");
    
    // Abre o arquivo de clientes
    fp = fopen("venda.dat", "r+b");  // Abre o arquivo para leitura e escrita
    if (fp == NULL) {
        perror("Erro ao abrir o arquivo");
        exit(1);
    }
    while (fread(venda, sizeof(Venda), 1, fp)) {
        if (strcmp(venda->cpfc, cpf_busca) == 0) {
            encontrado = 1;  
     } do {
                printf("\nCliente encontrado:\n");
                printf("1. CPF do comprador: %s\n", venda->cpfc);
                printf("2. CPF do vendedor: %s\n",  venda->cpff);
                printf("3. Placa do veículo: %s\n", venda->placa);
                printf("4. Valor da compra: %.2f\n", venda->valor);
                printf("5. N° de parcelas: %s\n", venda->parce);
                printf("6. Data da aquisição: %s\n", venda->data);
                printf("0. Sair da atualização\n");
                printf("\n");
                printf("Escolha o campo que deseja atualizar: ");
                
                // Lê a opção utilizando fgets
                fgets(opcao, sizeof(opcao), stdin); // Lê a opção como string
                opcao[strcspn(opcao, "\n")] = '\0'; // Remove o '\n' do final

                switch (opcao[0]) {  // Usa a primeira letra da opção
                    case '1':
                        leCpfVenda(venda);
                        break;
                    case '2':
                        leCpffVenda(venda);
                        break;
                    case '3':
                        leParcelaVenda(venda);
                        break;
                    case '4':
                       leApenasValor(venda);
                        break;
                    case '5':
                        leParcelaVenda(venda);
                        break;
                    case '6':
                        leDataVenda(venda);
                        break;
                    case '0':
                        printf("Finalizando a atualização...\n");
                        break;
                    default:
                        printf("Opção inválida.\n");
                }

                // Atualiza o cliente no arquivo após cada alteração
                if (opcao[0] >= '1' && opcao[0] <= '5') {
                    fseek(fp, -sizeof(Venda), SEEK_CUR);     // Volta para o início do registro
                    fwrite(venda, sizeof(Venda), 1, fp);
                    printf("Dados atualizados com sucesso!\n");
                }
            } while (opcao[0] != '0');

            break; // Sai do loop após encontrar e atualizar o cliente
        }

    if (!encontrado) {
        printf("Cliente com CPF %s não encontrado ou inativo.\n", cpf_busca);}

        fclose(fp);
    free (venda);                        // libera memória da estrutura Cliente
    printf("|                                                                           |\n");
    printf("+---------------------------------------------------------------------------+\n");

}

void exclui_venda(void) {
    
    system("clear||cls");
    printf("\n");
    printf("┌─────────────────────────────────────────────────────────────────────────────┐\n");
    printf("|                                 BuyYourCar                                  |\n");
    printf("└─────────────────────────────────────────────────────────────────────────────┘\n");
    printf("┌─────────────────────────────────────────────────────────────────────────────┐\n");
    printf("|                               Excluir Venda                                 |\n");
    printf("|                                                                             |\n");
    printf("| Informe o N° de protocolo:                                                  |\n");
    printf("|                                                                             |\n");
    printf("└─────────────────────────────────────────────────────────────────────────────┘\n");
    printf("\n"); 
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n"); 
    getchar(); 

    
}  

void leCpfVBusca (char *cpf_busca) {
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


char buscarCpfCliente(char* cpf) {
	FILE* fp;
	Cliente* cliente;

	cliente = (Cliente*) malloc(sizeof(Cliente));
	fp = fopen("clientes.dat", "rb");
	if (fp == NULL) {
		printf("Erro!");
	}
	while(fread(cliente, sizeof(Cliente), 1, fp)) {
		if ((strcmp(cliente->cpf, cpf) == 0) && (strcmp(cliente->status, "Ativo") == 0)) {
			fclose(fp);
			return cliente;
		}
	}
	fclose(fp);
	return NULL;
} 

