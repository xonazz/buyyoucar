#include <stdio.h>
#include <stdlib.h>           
#include <string.h>           
#include "cliente.h"
#include "funcionario.h" 
#include "validacao.h"  
#include "funcionario.h"
#include "veiculo.h"
#include "venda.h" 
#include <stdbool.h>

void leApenasNome(Cliente *cliente) {
    fgets(cliente->nome, sizeof(cliente->nome), stdin);              
    cliente->nome[strcspn(cliente->nome, "\n")] = '\0';
} 

// Função para ler e validar o nome do cliente
void leNomeCliente(Cliente *cliente) {
    printf("|-> Nome do cliente: ");
    do {
       leApenasNome(cliente);
        if (ver_nome(cliente->nome)) {
            printf("Nome válido\n");
            break;
        } else {
            printf("Nome inválido, tente novamente apertando a tecla ENTER");
            getchar();
            printf("|-> Nome do cliente: ");
        }
    } while (!ver_nome(cliente->nome));
}

void leApenasCpf(Cliente *cliente) {
    fgets(cliente->cpf, sizeof(cliente->cpf), stdin);
    cliente->cpf[strcspn(cliente->cpf, "\n")] = '\0';
}


void leCpfCliente(Cliente *cliente){
 printf("|-> CPF (somente números): ");
    do {
        leApenasCpf(cliente);
        if (verificar_cpf(cliente->cpf)) {
            printf("CPF válido\n");
            break;
        } else {
            printf("CPF inválido, tente novamente apertando a tecla ENTER");
            getchar();
            printf("|-> CPF (somente números): ");
        }
    } while (!verificar_cpf(cliente->cpf)); // Continua até o CPF ser válido
}

void leApenasEmail(Cliente *cliente) {
    fgets(cliente->email, sizeof(cliente->email), stdin);
    cliente->email[strcspn(cliente->email, "\n")] = '\0';
}

// Função para ler e validar o Email do cliente
void leEmailCliente(Cliente *cliente) {
    printf("|-> Email: ");
    do {
        leApenasEmail(cliente);    // Lê o email dinamicamente através do ponteiro
        if (validarEmail(cliente->email)) {
            printf("Email válido\n");
            break;
        } else {
            printf("Email inválido, tente novamente apertando a tecla ENTER");
            getchar();
            printf("|-> Email: ");
        }
    } while(!validarEmail(cliente->email));
} 

// Função para capturar apenas a data do cliente
void leApenaCnh(Cliente *cliente) {
    fgets(cliente->cnh, sizeof(cliente->cnh), stdin);
    cliente->cnh[strcspn(cliente->cnh, "\n")] = '\0';
}

// Função para ler e validar a cnh do cliente
void leCnhCliente(Cliente *cliente) {
    printf("|-> N° da CNH (APENAS NÚMEROS): ");
        do {
         leApenaCnh(cliente);   // Lê a data dinamicamente através do ponteiro
        if (validarCNH(cliente->cnh)) {
            printf("N° da CNH inválido\n");
            break;
        } else {
            printf("N° da CNH inválido, tente novamente apertando a tecla ENTER");
            getchar();
            printf("|-> N° da CNH (APENAS NÚMEROS):  ");
        }
    } while(!validarCNH(cliente->cnh));
} 

void leApenasFone(Cliente *cliente) {
    fgets(cliente->fone, sizeof(cliente->fone), stdin);
    cliente->fone[strcspn(cliente->fone, "\n")] = '\0';
}

// Função para ler e validar o  número de telefone do cliente
void leFoneCliente(Cliente *cliente) {
  printf("|-> N° de Celular (somente números): ");
     do {
        leApenasFone(cliente);    // Lê o número de telefone dinamicamente através do ponteiro
        if (validarCelular(cliente->fone)) {
            printf(" N° de Celular válido\n");
            break;
        } else {
            printf("N° de Celular inválido, tente novamente apertando a tecla ENTER");
            getchar();
            printf("|-> N° de Celular (somente números): ");
        }
    } while(!validarCelular(cliente->fone));
} 

// ------------------------------------------------------------- // 
// Entradas para funcionario 

///--------------------------------------------------------///
///                        NOME F                          ///
//---------------------------------------------------------///
// Função para capturar apenas o nome do funcionário

void leApenasNomeF(Funcionario *funcionario) {
    fgets(funcionario->nome, sizeof(funcionario->nome), stdin);              
    funcionario->nome[strcspn(funcionario->nome, "\n")] = '\0';
}

// Função para ler e validar o nome do funcionário
void leNomeFuncionario(Funcionario *funcionario) {
    printf("|-> Nome do funcionário: ");
    do {
        leApenasNomeF(funcionario);
        if (ver_nome(funcionario->nome)) {
            printf("Nome válido\n");
            break;
        } else {
            printf("Nome inválido, tente novamente apertando a tecla ENTER");
            getchar();
            printf("|-> Nome do funcionário: ");
        }
    } while (!ver_nome(funcionario->nome));
}

///--------------------------------------------------------///
///                         CPF F                          ///
//---------------------------------------------------------///
// Função para capturar apenas o CPF do funcionário
void leApenasCpfF(Funcionario *funcionario) {
    fgets(funcionario->cpf, sizeof(funcionario->cpf), stdin);
    funcionario->cpf[strcspn(funcionario->cpf, "\n")] = '\0';
}

// Função para ler e validar o CPF do funcionário
void leCpfFuncionario(Funcionario *funcionario) {
    printf("|-> CPF (somente números): ");
    do {
        leApenasCpfF(funcionario);
        if (verificar_cpf(funcionario->cpf)) {
            printf("CPF válido\n");
            break;
        } else {
            printf("CPF inválido, tente novamente apertando a tecla ENTER \n");
            getchar();
            printf("|-> CPF (somente números): ");
        }
    } while (!verificar_cpf(funcionario->cpf)); // Continua até o CPF ser válido
}


///--------------------------------------------------------///
///                        EMAIL F                         ///
//---------------------------------------------------------///
// Função para capturar apenas o email do funcionário
void leApenasEmailF(Funcionario *funcionario) {
    fgets(funcionario->email, sizeof(funcionario->email), stdin);
    funcionario->email[strcspn(funcionario->email, "\n")] = '\0';
}

// Função para ler e validar o Email do funcionário
void leEmailFuncionario(Funcionario *funcionario) {
    printf("|-> Email: ");
    do {
        leApenasEmailF(funcionario);    // Lê o email dinamicamente através do ponteiro
        if (validarEmail(funcionario->email)) {
            printf("Email válido\n");
            break;
        } else {
            printf("Email inválido, tente novamente apertando a tecla ENTER");
            getchar();
            printf("|-> Email: ");
        }
    } while(!validarEmail(funcionario->email));
}


///--------------------------------------------------------///
///                        DATA F                          ///
//---------------------------------------------------------///
// Função para capturar apenas a data do funcionário
void leApenaCnhF(Funcionario *funcionario) {
    fgets(funcionario->cnh, sizeof(funcionario->cnh), stdin);
    funcionario->cnh[strcspn(funcionario->cnh, "\n")] = '\0';
}

// Função para ler e validar a data do funcionário
void leCnhFuncionario(Funcionario *funcionario) {
    printf("|-> N° da CNH: ");
        do {
        leApenaCnhF(funcionario);   // Lê a data dinamicamente através do ponteiro
        if (validarCNH(funcionario->cnh)) {
            printf("N° da CNH inválido\n");
            break;
        } else {
            printf("N° da CNH inválido, tente novamente apertando a tecla ENTER");
            getchar();
            printf("|-> N° da CNH: ");
        }
    } while(!validarCNH(funcionario->cnh));
}


///--------------------------------------------------------///
///                        FONE F                          ///
//---------------------------------------------------------///
// Função para capturar apenas o número de telefone do funcionário
void leApenasFoneF(Funcionario *funcionario) {
    fgets(funcionario->fone, sizeof(funcionario->fone), stdin);
    funcionario->fone[strcspn(funcionario->fone, "\n")] = '\0';
}

// Função para ler e validar o  número de telefone do funcionário
void leFoneFuncionario(Funcionario *funcionario) {
  printf("|-> celular (somente números): ");
     do {
        leApenasFoneF(funcionario);    // Lê o número de telefone dinamicamente através do ponteiro
        if (validarCelular(funcionario->fone)) {
            printf("Número de celular válido\n");
            break;
        } else {
            printf("Número de celular inválido, tente novamente apertando a tecla ENTER");
            getchar();
            printf("|-> celular (somente números): ");
        }
    } while(!validarCelular(funcionario->fone));
}

///----------------------- ENTRADAS VEICULO ---------------------------/// 

void leApenasplaca(Veiculo *veiculo) {
    fgets(veiculo->placa, sizeof(veiculo->placa), stdin);              
    veiculo->placa[strcspn(veiculo->placa, "\n")] = '\0';
} 

// Função para ler e validar o nome do cliente
void lePlaca(Veiculo *veiculo) {
    printf("|-> Placa (apenas caracteres): ");
    do {
       leApenasplaca(veiculo);
        if (verificarPlacaValida(veiculo->placa)) {
            printf("placa válida\n");
            break;
        } else {
            printf("placa inválida, tente novamente apertando a tecla ENTER");
            getchar();
            printf("|-> Placa (apenas caracteres): ");
        }
    } while (!verificarPlacaValida(veiculo->placa));
}

void leApenasmarca(Veiculo *veiculo) {
    fgets(veiculo->marca, sizeof(veiculo->marca), stdin);              
    veiculo->marca[strcspn(veiculo->marca, "\n")] = '\0';
} 

void leMarca(Veiculo *veiculo) {
    printf("|-> Marca do veículo: ");
    do {
       leApenasmarca(veiculo);
        if (verificarNomeValido(veiculo->marca)) {
            printf("Marca válida\n");
            break;
        } else {
            printf("Marca inválida, tente novamente apertando a tecla ENTER");
            getchar();
            printf("|-> Marca do veículo: ");
        }
    } while (!verificarNomeValido(veiculo->marca));
}

void leApenasmodelo(Veiculo *veiculo) {
    fgets(veiculo->modelo, sizeof(veiculo->modelo), stdin);              
    veiculo->modelo[strcspn(veiculo->modelo, "\n")] = '\0';
} 

void leModelo(Veiculo *veiculo) {
    printf("|-> Modelo do veículo: ");
    do {
       leApenasmodelo(veiculo);
        if (verificarNomeValido(veiculo->modelo)) {
            printf("Modelo válido\n");
            break;
        } else {
            printf("Modelo inválido, tente novamente apertando a tecla ENTER");
            getchar();
            printf("|-> Modelo do veículo: ");
        }
    } while (!verificarNomeValido(veiculo->modelo));
} 

void leApenasAno(Veiculo *veiculo) {
    fgets(veiculo->anodf, sizeof(veiculo->anodf), stdin);              
    veiculo->anodf[strcspn(veiculo->anodf, "\n")] = '\0';
} 

void leAno(Veiculo *veiculo) {
    printf("|-> Ano de fabricação do veículo: ");
    do {
       leApenasAno(veiculo);
        if (verificarAnoValido(veiculo->anodf)) {
            printf("Ano válido\n");
            break;
        } else {
            printf("Ano inválido, tente novamente apertando a tecla ENTER");
            getchar();
            printf("|-> Ano de fabricação do veículo: ");
        }
    } while (!verificarAnoValido(veiculo->anodf));
} 

void leApenasCpfVenda(Venda *venda) {
    fgets(venda->cpfc, sizeof(venda->cpfc), stdin);              
    venda->cpfc[strcspn(venda->cpfc, "\n")] = '\0';
} 

void leCpfVenda(Venda *venda){
 printf("|-> CPF (somente números): ");
    do {
        leApenasCpfVenda(venda);
        if (verificar_cpf(venda->cpfc)) {
            printf("CPF válido\n");
            break;
        } else {
            printf("CPF inválido, tente novamente apertando a tecla ENTER");
            getchar();
            printf("|-> CPF (somente números): ");
        }
    } while (!verificar_cpf(venda->cpfc)); // Continua até o CPF ser válido
} 

void leApenasCpffVenda(Venda *venda) {
    fgets(venda->cpff, sizeof(venda->cpff), stdin);              
    venda->cpff[strcspn(venda->cpff, "\n")] = '\0';
} 

void leCpffVenda(Venda *venda){
 printf("|-> CPF (somente números): ");
    do {
        leApenasCpffVenda(venda);
        if (verificar_cpf(venda->cpff)) {
            printf("CPF válido\n");
            break;
        } else {
            printf("CPF inválido, tente novamente apertando a tecla ENTER \n");
            getchar();
            printf("|-> CPF (somente números): ");
        }
    } while (!verificar_cpf(venda->cpff)); // Continua até o CPF ser válido
} 


void leApenasPlacaVenda(Venda *venda) {
    fgets(venda->placa, sizeof(venda->placa), stdin);              
    venda->placa[strcspn(venda->placa, "\n")] = '\0';
} 

void lePlacaVenda(Venda *venda){
 printf("|-> Placa (apenas caracteres): ");
    do {
         leApenasPlacaVenda(venda);
        if (verificar_cpf(venda->cpfc)) {
            printf("CPF válido\n");
            break;
        } else {
            printf("CPF inválido, tente novamente apertando a tecla ENTER");
            getchar();
            printf("|-> CPF (somente números): ");
        }
    } while (!verificar_cpf(venda->cpfc)); // Continua até o CPF ser válido
} 

void leApenasData(Venda *venda) {
    fgets(venda->data, sizeof(venda->data), stdin);              
    venda->data[strcspn(venda->data, "\n")] = '\0';
}  


void leApenasValor(Venda *venda) {
    while (1) {  // Loop para garantir que o valor será positivo
        // Tenta ler um valor float da entrada padrão
        printf("Digite o valor da venda: ");
        
        if (scanf("%f", &venda->valor) != 1) {
            // Se falhar na leitura, define o valor como 0.0 ou pode tratar de outra forma
            venda->valor = 0.0f;
            // Para depuração, podemos exibir uma mensagem de erro
            fprintf(stderr, "Erro ao ler o valor float. Tente novamente.\n");
            // Limpa o buffer de entrada em caso de erro de leitura
            while(getchar() != '\n');
        } else if (venda->valor <= 0) {
            // Se o valor for negativo ou zero, exibe uma mensagem de erro e repete a leitura
            fprintf(stderr, "O valor deve ser positivo. Tente novamente.\n");
            venda->valor = 0.0f;  // Define o valor como 0 para repetir a entrada
        } else {
            // Se o valor for válido (positivo), sai do loop
            break;
        }
    }
}
void leApenasParcela(Venda *venda) {
    fgets(venda->parce, sizeof(venda->parce), stdin);              
    venda->parce[strcspn(venda->parce, "\n")] = '\0';
}  

void leParcelaVenda(Venda *venda){
 printf("|-> N° de parcelas (apenas número): \n");
    do {
        leApenasParcela(venda);
        if (validarParcelas(venda->parce)) {
            printf("Parcelamento válido\n");
            break;
        } else {
            printf("parcelamento inválido, tente novamente apertando a tecla ENTER \n");
            getchar();
            printf("|-> N° de parcelas (apenas número): \n");
        }
    } while (!validarParcelas(venda->parce)); // continua até o número de parcelas ser válido
}  

void leDataVenda(Venda *venda) {

    // Solicita a entrada do usuário
    printf("Digite a data no formato YYYY-MM-DD: ");
    fgets(venda->data, sizeof(venda->data), stdin);

    // Remove a nova linha (\n) caso o usuário pressione Enter após digitar
    venda->data[strcspn(venda->data, "\n")] = '\0';

    // Verifica se a data é válida
    if (isValidDate(venda->data)) {
        printf("Data válida: %s\n", venda->data);
    } else {
        printf("Data inválida: %s\n", venda->data);
    }

}
