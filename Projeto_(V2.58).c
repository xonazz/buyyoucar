///////////////////////////////////////////////////////////////////////////////
///             Universidade Federal do Rio Grande do Norte                 ///
///                  Disciplina DCT1106 -- Programação                      ///
///                  Projeto de uma Concessionária de Veículos              ///
///////////////////////////////////////////////////////////////////////////////


#include <stdio.h> 
#include <stdlib.h>

// Projeto V2.58

// ################################
// Assinatura das Funções
void tela_principal(void);
void tela_cliente(void);
void cadastra_cliente(void);
void pesquisa_cliente(void);
void atualiza_cliente(void);
void exclui_cliente(void);

void tela_veiculo(void);
void cadastra_veiculo(void);
void pesquisa_veiculo(void);
void atualiza_veiculo(void);
void exclui_veiculo(void);

void tela_funcionario(void);
void cadastra_funcionario(void);
void pesquisa_funcionario(void);
void atualiza_funcionario(void);
void exclui_funcionario(void);

void tela_sobre(void);
void tela_equipe(void);

// ################################
// Programa Principal
int main(void) {
    tela_principal();
    tela_cliente();
    cadastra_cliente();
    pesquisa_cliente();
    atualiza_cliente();
    exclui_cliente();

    tela_veiculo();
    cadastra_veiculo();
    pesquisa_veiculo();
    atualiza_veiculo();
    exclui_veiculo();
    
    tela_funcionario();
    cadastra_funcionario();
    pesquisa_funcionario();
    atualiza_funcionario();
    exclui_funcionario();
    
    tela_sobre();
    tela_equipe();
    return 0;
}


// ################################
// Funções

void tela_principal(void) {
    system("clear||cls");
    printf("\n");
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
    printf("| 5. Módulo Relatórios                                                        |\n");
    printf("| 0. Sair                                                                     |\n");
    printf("└─────────────────────────────────────────────────────────────────────────────┘\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
    printf("\n");
}

void tela_cliente(void) {
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
    printf("└─────────────────────────────────────────────────────────────────────────────┘\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
    printf("\n");
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

void tela_veiculo(void) {   
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
    printf("\n"); 
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n"); 
    getchar(); 
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
    printf("|                                                                             |\n");
    printf("|                                                                             |\n");
    printf("| Informe a Placa:                                                            |\n");
    printf("|                                                                             |\n");
    printf("|                                                                             |\n");
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
    printf("|                                                                             |\n");
    printf("|                                                                             |\n");
    printf("| Informe a Placa:                                                            |\n");
    printf("|                                                                             |\n");
    printf("|                                                                             |\n");
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
    printf("|                                                                             |\n");
    printf("|                                                                             |\n");
    printf("| Informe a Placa:                                                            |\n");
    printf("|                                                                             |\n");
    printf("|                                                                             |\n");
    printf("|                                                                             |\n");
    printf("└─────────────────────────────────────────────────────────────────────────────┘\n");
    printf("\n"); 
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n"); 
    getchar(); 
} 

void tela_funcionario(void) { 
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
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n"); 
    getchar();
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
    printf("|                                                                             |\n");
    printf("|                                                                             |\n");
    printf("| Informe o CPF(Apenas Números):                                              |\n");
    printf("|                                                                             |\n");
    printf("|                                                                             |\n");
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
    printf("|                                                                             |\n");
    printf("|                                                                             |\n");
    printf("| Informe o CPF(Apenas Números):                                              |\n");
    printf("|                                                                             |\n");
    printf("|                                                                             |\n");
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
    printf("|                                                                             |\n");
    printf("|                                                                             |\n");
    printf("| Informe o CPF(Apenas Números):                                              |\n");
    printf("|                                                                             |\n");
    printf("|                                                                             |\n");
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
    printf("└─────────────────────────────────────────────────────────────────────────────┘\n");
    printf("\n"); 
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n"); 
    getchar();
} 

void tela_equipe(void) {
    system("clear||cls");
    printf("\n");
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
