#include <stdio.h> 

// Projeto V1.08

// ################################
// Assinatura das Funções
void tela_principal(void);
void tela_sobre(void);
void tela_equipe(void);

// ################################
// Programa principal
int main(void) {
    tela_principal();
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
