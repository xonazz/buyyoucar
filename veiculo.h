#ifndef VEICULO_H
#define VEICULO_H

typedef struct{

    char sit;
    char placa[8];
    char marca[52];
    char modelo[52];
    char anodf[5];

}Veiculo;

void tela_veiculo(void);
void cadastra_veiculo(void);
void pesquisa_veiculo(void);
void atualiza_veiculo(void);
void exclui_veiculo(void);

void lePlacaBusca(char *placa_busca);
void busca_placa(const char *placa_busca); 
int verificaPlacaCadastrada(const char *placa);

#endif
