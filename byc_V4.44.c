///////////////////////////////////////////////////////////////////////////////
///               Universidade Federal do Rio Grande do Norte               ///
///                    Disciplina DCT1106 -- Programação                    ///
///          Projeto de Sistema para uma Concessionária de Veículos         ///
///         Developed by @IvysonWNM and @xonazz -- since sept, 2024         ///
///////////////////////////////////////////////////////////////////////////////

#include <stdio.h> 
#include <stdlib.h>
#include "cliente.h"

// Projeto V4.44

// ################################
// Assinatura das Funções ( telas principais)
int tela_principal(void);

void tela_veiculo(void);
void tela_funcionario(void);
void tela_venda(void);
void tela_sobre(void);
void tela_equipe(void);


// Assinatura das Funções (telas secundárias)

void cadastra_veiculo(void);
void pesquisa_veiculo(void);
void atualiza_veiculo(void);
void exclui_veiculo(void);


void cadastra_funcionario(void);
void pesquisa_funcionario(void);
void atualiza_funcionario(void);
void exclui_funcionario(void);


void cadastra_venda(void);
void pesquisa_venda(void);
void atualiza_venda(void);
void exclui_venda(void);


// ################################
// Programa Principal
int main(void) {
    int op;
    do {
        op = tela_principal();
        switch (op) {
           case 1: 
               tela_cliente();
               break;
           case 2: 
               tela_veiculo();
		break;
           case 3: 
               tela_funcionario();
               break;
           case 4: 
               tela_venda();
               break;
           case 5: 
               tela_sobre();
               break;
           case 6: 
               tela_equipe();
               break;
        }
    } while (op != 0);
    printf("The End\n"); 
    return 0;
}

// ################################
// Funções

int tela_principal(void) {
    int op;
    system("clear||cls");
    printf("\n");
    printf("┌─────────────────────────────────────────────────────────────────────────────┐\n");
    printf("|                 Universidade Federal do Rio Grande do Norte                 |\n");
    printf("|                      Disciplina DCT1106 -- Programação                      |\n");
    printf("|            Projeto de Sistema para uma Concessionária de Veículos           |\n");
    printf("|           Developed by @IvysonWNM and @xonazz -- since sept, 2024           |\n");
    printf("└─────────────────────────────────────────────────────────────────────────────┘\n");
    printf("┌─────────────────────────────────────────────────────────────────────────────┐\n");
    printf("|                                 BuyYourCar                                  |\n");
    printf("└─────────────────────────────────────────────────────────────────────────────┘\n");
    printf("┌─────────────────────────────────────────────────────────────────────────────┐\n");
    printf("|                    Sistema de Gestão Para Concessionária                    |\n");
    printf("|                                                                             |\n");
    printf("| 1. Módulo Cliente                                                           |\n");
    printf("| 2. Módulo Veículos                                                          |\n");
    printf("| 3. Módulo Funcionário                                                       |\n");
    printf("| 4. Módulo Venda                                                             |\n");
    printf("| 5. Módulo Sobre                                                             |\n");
    printf("| 6. Módulo Equipe                                                            |\n");
    printf("| 0. Sair                                                                     |\n");
    printf("|                                                                             |\n");
    printf("└─────────────────────────────────────────────────────────────────────────────┘\n");
    printf("──────────────────────────────────────────────────────────────────────────────\n");
    printf("\n");
    printf("            Escolha a opção desejada: ");
    scanf("%d", &op);
    getchar();
    printf("\n");
    printf("──────────────────────────────────────────────────────────────────────────────\n");
    return op;
}

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
    printf("|                                                                             |\n");
    printf("| Informe a Placa:                                                            |\n");
    printf("| Marca:                                                                      |\n");
    printf("| Modelo:                                                                     |\n");
    printf("| Ano de fabricação:                                                          |\n");
    printf("|                                                                             |\n");
    printf("└─────────────────────────────────────────────────────────────────────────────┘\n");
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
    printf("| Informe a Placa:                                                            |\n");
    printf("|                                                                             |\n");
    printf("└─────────────────────────────────────────────────────────────────────────────┘\n");
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
    printf("| Informe a Placa:                                                            |\n");
    printf("|                                                                             |\n");
    printf("└─────────────────────────────────────────────────────────────────────────────┘\n");
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
    printf("| CPF (Apenas número) :                                                       |\n");
    printf("| Nome Completo:                                                              |\n");
    printf("| E-mail:                                                                     |\n");
    printf("| Data de nascimento(dd/mm/aaaa)                                              |\n");
    printf("| Celular (Apenas números) :                                                  |\n");
    printf("|                                                                             |\n");
    printf("└─────────────────────────────────────────────────────────────────────────────┘\n");
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
    printf("| Informe o CPF(Apenas Números):                                              |\n");
    printf("|                                                                             |\n");
    printf("└─────────────────────────────────────────────────────────────────────────────┘\n");
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
    printf("| Informe o CPF(Apenas Números):                                              |\n");
    printf("|                                                                             |\n");
    printf("└─────────────────────────────────────────────────────────────────────────────┘\n");
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
    
    system("clear||cls");
    printf("\n");
    printf("┌─────────────────────────────────────────────────────────────────────────────┐\n");
    printf("|                                 BuyYourCar                                  |\n");
    printf("└─────────────────────────────────────────────────────────────────────────────┘\n");
    printf("┌─────────────────────────────────────────────────────────────────────────────┐\n");
    printf("|                             Cadastrar Venda                                 |\n");
    printf("|                                                                             |\n");
    printf("| N° de protocolo:                                                            |\n");
    printf("| Data e hora:                                                                |\n");
    printf("| CPF do Comprador:                                                           |\n");
    printf("| CPF do Vendedor:                                                            |\n");
    printf("| Valor:                                                                      |\n");
    printf("|                                                                             |\n");
    printf("└─────────────────────────────────────────────────────────────────────────────┘\n");
    printf("\n"); 
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar(); 
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
    printf("\n"); 
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n"); 
    getchar(); 
} 

void atualiza_venda(void) {
    
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
    printf("\n"); 
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n"); 
    getchar(); 
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

void tela_sobre(void) { 
    system("clear||cls");
    printf("\n");
    printf("┌─────────────────────────────────────────────────────────────────────────────┐\n");
    printf("|                 Universidade Federal do Rio Grande do Norte                 |\n");
    printf("|                      Disciplina DCT1106 -- Programação                      |\n");
    printf("|            Projeto de Sistema para uma Concessionária de Veículos           |\n");
    printf("|           Developed by @IvysonWNM and @xonazz -- since sept, 2024           |\n");
    printf("└─────────────────────────────────────────────────────────────────────────────┘\n");
    printf("┌─────────────────────────────────────────────────────────────────────────────┐\n");
    printf("|                                 BuyYourCar                                  |\n");
    printf("└─────────────────────────────────────────────────────────────────────────────┘\n");
    printf("┌─────────────────────────────────────────────────────────────────────────────┐\n");
    printf("|                    Sistema de Gestão Para Concessionária                    |\n");
    printf("|                                                                             |\n");
    printf("| Programa universitário da disciplina de PROGRAMAÇÃO (DCT1106) da UFRN.      |\n");
    printf("| Escrito na linguagem de programação C, fornecendo uma plataforma de gestão  |\n");
    printf("| para uma concessionária de veículos, com interfaces intuitivas divididas em |\n");
    printf("| módulos como os de clientes, veículos e funcionários. O objetivo principal  |\n");
    printf("| é ajudar pequenas e médias empresas a melhorar a eficiência e modernizar    |\n");
    printf("| seus processos de gestão, seja implementando, atualizando ou otimizando     |\n");
    printf("| suas operações.                                                             |\n");
    printf("|                                                                             |\n");
    printf("└─────────────────────────────────────────────────────────────────────────────┘\n");
    printf("\n"); 
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n"); 
    getchar();
} 

void tela_equipe(void) {
    system("clear||cls");
    printf("\n");
    printf("┌─────────────────────────────────────────────────────────────────────────────┐\n");
    printf("|                 Universidade Federal do Rio Grande do Norte                 |\n");
    printf("|                      Disciplina DCT1106 -- Programação                      |\n");
    printf("|            Projeto de Sistema para uma Concessionária de Veículos           |\n");
    printf("|           Developed by @IvysonWNM and @xonazz -- since sept, 2024           |\n");
    printf("└─────────────────────────────────────────────────────────────────────────────┘\n");
    printf("┌─────────────────────────────────────────────────────────────────────────────┐\n");
    printf("|                                 BuyYourCar                                  |\n");
    printf("└─────────────────────────────────────────────────────────────────────────────┘\n");
    printf("┌─────────────────────────────────────────────────────────────────────────────┐\n");
    printf("|                    Sistema de Gestão Para Concessionária                    |\n");
    printf("|                                                                             |\n");
    printf("|                          Projeto desenvolvido por:                          |\n");
    printf("|                                                                             |\n");
    printf("| Ivyson Wanderson                               Jonas                        |\n");
    printf("| E-mail: ivysonnunes@hotmail.com                E-mail: robsonjjcs@gmail.com |\n");
    printf("| GitHub: @IvysonWNM                             GitHub: @xonazz              |\n");
    printf("|                                                                             |\n");                                                        
    printf("| PROJETO BuyYourCar: https://github.com/xonazz/buyyoucar.git                 |\n");
    printf("└─────────────────────────────────────────────────────────────────────────────┘\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
    printf("\n");
}
