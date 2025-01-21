#ifndef ENTRADAS_H
#define ENTRADAS_H

#define TAM_CPF 12
#define TAM_CODIGO 7

#include "cliente.h"    // Para incluir a estrutura Cliente
#include "funcionario.h"
#include "validacao.h"  // Para incluir a função ver_nome
#include <stddef.h>      // Necessário para o tipo 'size_t'
#include "veiculo.h" 
#include "venda.h"


void leNomeCliente(Cliente *cliente);
// Declaração das funções relacionadas ao cliente

void leApenasCpf(Cliente *cliente);

void leCpfCliente(Cliente *cliente);
 
void leApenasEmail(Cliente *cliente);

void leEmailCliente(Cliente *cliente);

void leApenaCnh(Cliente *cliente);

void leCnhCliente(Cliente *cliente); 

void leApenasFone(Cliente *cliente); 

void leFoneCliente(Cliente *cliente);

// --------------------------------------------------// 
// Entradas para Funcionario 

void leNomeFuncionario(Funcionario *funcionario);
void leCpfFuncionario(Funcionario *funcionario);
void leEmailFuncionario(Funcionario *funcionario);
void leCnhFuncionario(Funcionario *funcionario);
void leFoneFuncionario(Funcionario *funcionario);

void menu_cliente(void);
void cadastra_cliente(void);

void pesquisa_cliente(void);
void busca_cliente (const char *cpf_busca);

void atualiza_cliente(void);
void exclui_cliente(void);

void leCpfBusca (char *cpf_busca);
int verificaCpfCadastrado(const char *cpf);


//---------------------------ENTRADAS VEICULO------------------------------------//

void leApenasplaca(Veiculo *veiculo); 
void lePlaca(Veiculo *veiculo);
void leApenasmarca(Veiculo *veiculo);
void leMarca(Veiculo *veiculo);
void leApenasmodelo(Veiculo *veiculo);
void leModelo(Veiculo *veiculo);
void leApenasAno(Veiculo *veiculo);
void leAno(Veiculo *veiculo);

//------------------------------------ENTRADAS VENDA---------------------------------// 

void leApenasCpfVenda(Venda *venda); 
void leCpfVenda(Venda *venda);
void leApenasPlacaVenda(Venda *venda);
void lePlacaVenda(Venda *venda);
void leApenasParcela(Venda *venda);
void leParcelaVenda(Venda *venda);
void leDataVenda(Venda *venda);
void leApenasValor(Venda *venda); 
void leApenasCpffVenda(Venda *venda);
void leCpffVenda(Venda *venda);

#endif 