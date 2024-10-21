///////////////////////////////////////////////////////////////////////////////
///               Universidade Federal do Rio Grande do Norte               ///
///                    Disciplina DCT1106 -- Programação                    ///
///          Projeto de Sistema para uma Concessionária de Veículos         ///
///         Developed by @IvysonWNM and @xonazz -- since sept, 2024         ///
///////////////////////////////////////////////////////////////////////////////

#include <stdio.h> 
#include <stdlib.h>
#include "cliente.h"
#include "veiculo.h" 
#include "funcionario.h" 
#include "venda.h"

// Projeto V4.44

// ################################
// Assinatura das Funções
int tela_principal(void);
void tela_sobre(void);
void tela_equipe(void);

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
