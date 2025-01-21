#ifndef VER_NOME_H
#define VER_NOME_H

// Protótipo da função ver_nome
int ver_nome(const char *nome); 

// Função para verificar se o CPF é válido
int verificar_cpf(const char *cpf);

// Funções auxiliares para calcular os dígitos verificadores
int calcular_digito1(int cpf[]);
int calcular_digito2(int cpf[]); 

int validarEmail(const char *email); 

// Declaração da função que calcula o dígito verificador da CNH
int calcularDigitoVerificador(int numero[9]);

// Declaração da função que valida o número da CNH
int validarCNH(const char *cnh); 

int validarCelular(const char *celular);

//--------------------------------validação veiculo-----------------------------//

int verificarPlacaValida(const char *placa);
int verificarNomeValido(const char *nome);
int verificarAnoValido(const char *anodf);
int isLeapYear(int year);
int isValidMonth(int month);
int isValidDay(int day, int month, int year);
int isValidDate(const char* date);
int validarValorPositivo(float valor);
int validarParcelas(const char* parcelasStr);

#endif // VER_NOME_H