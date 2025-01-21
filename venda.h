#ifndef VENDA_H
#define VENDA_H 


typedef struct{

char cpfc[13];
char cpff[13];
char placa[8];
char data[15];
float valor;
char parce[3]; 
char sit;

}Venda;


void tela_venda(void);
void cadastra_venda(void);
void pesquisa_venda(void); 
void atualiza_venda(void); 
void exclui_venda(void);  

int verificaPlacaCadastrada(const char *placa); 
void leCpfVBusca (char *cpf_busca); 
char buscarProfessor(char*);



#endif
