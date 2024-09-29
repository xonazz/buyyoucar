#include <stdio.h> 

// Projeto V1.08

// ################################
// Assinatura das Funções
void tela_principal(void);
void tela_cliente(void);
void cadastra_cliente(void);
void pesquisa_cliente(void);
void altera_cliente(void);
void exclui_cliente(void);

void tela_sobre(void);
void tela_equipe(void);

// ################################
// Programa Principal
int main(void) {
    tela_principal();
    tela_cliente();
    cadastra_cliente();
    pesquisa_cliente();
    altera_cliente();
    exclui_cliente();

    tela_sobre();
    tela_equipe();
    return 0;
}


// ################################
// Funções

void tela_principal(void) {
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
    printf("\n");
}

void tela_cliente(void) {
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
    printf("\n");
}

void cadastra_cliente(void) {		
    printf("\n");
    printf("┌─────────────────────────────────────────────────────────────────────────────┐\n");
    printf("|                                 BuyYourCar                                  |\n");
    printf("└─────────────────────────────────────────────────────────────────────────────┘\n");
    printf("┌─────────────────────────────────────────────────────────────────────────────┐\n");
    printf("|                                Menu Cliente                                 |\n");
    printf("|                                                                             |\n");
    printf("| Nome Completo:                                                              |\n");
    printf("| CPF (Apenas Números):                                                       |\n");
    printf("| Número de Telefone (Apenas Números):                                        |\n");
    printf("| Data de nascimento(dd/mm/aaaa):                                             |\n");
    printf("| Número da CNH (Apenas Números):                                             |\n");
    printf("| E-mail:                                                                     |\n");
    printf("| Endereço: (Cidade, Bairro, Rua e Número)                                    |\n");
    printf("└─────────────────────────────────────────────────────────────────────────────┘\n");
    printf("\n");
}

void pesquisa_cliente(void) {		
    printf("\n");
    printf("┌─────────────────────────────────────────────────────────────────────────────┐\n");
    printf("|                                 BuyYourCar                                  |\n");
    printf("└─────────────────────────────────────────────────────────────────────────────┘\n");
    printf("┌─────────────────────────────────────────────────────────────────────────────┐\n");
    printf("|                                Menu Cliente                                 |\n");
    printf("|                                                                             |\n");
    printf("| CPF (Apenas Números):                                                       |\n");
    printf("|                                                                             |\n");
    printf("└─────────────────────────────────────────────────────────────────────────────┘\n");
    printf("\n");
}

void altera_cliente(void) {		
    printf("\n");
    printf("┌─────────────────────────────────────────────────────────────────────────────┐\n");
    printf("|                                 BuyYourCar                                  |\n");
    printf("└─────────────────────────────────────────────────────────────────────────────┘\n");
    printf("┌─────────────────────────────────────────────────────────────────────────────┐\n");
    printf("|                                Menu Cliente                                 |\n");
    printf("|                                                                             |\n");
    printf("| CPF (Apenas Números):                                                       |\n");
    printf("|                                                                             |\n");
    printf("└─────────────────────────────────────────────────────────────────────────────┘\n");
    printf("\n");
}

void exclui_cliente(void) {		
    printf("\n");
    printf("┌─────────────────────────────────────────────────────────────────────────────┐\n");
    printf("|                                 BuyYourCar                                  |\n");
    printf("└─────────────────────────────────────────────────────────────────────────────┘\n");
    printf("┌─────────────────────────────────────────────────────────────────────────────┐\n");
    printf("|                                Menu Cliente                                 |\n");
    printf("|                                                                             |\n");
    printf("| CPF (Apenas Números):                                                       |\n");
    printf("|                                                                             |\n");
    printf("└─────────────────────────────────────────────────────────────────────────────┘\n");
    printf("\n");
}

void tela_sobre(void) {
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
}

void tela_equipe(void) {
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
    printf("\n");
}
