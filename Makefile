# Variáveis
CC = gcc                      # Compilador
CFLAGS = -Wall -g              # Flags de compilação (mostrar avisos e incluir debug)
OBJ = byc_V6.o cliente.o funcionario.o relatorio.o valid_client.o valid_func.o valid_vechi.o veiculo.o venda.o # Arquivos objetos
EXEC = programa                # Nome do executável

# Regra padrão: compilar o executável
$(EXEC): $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)   # Linkar os arquivos objetos para gerar o executável

# Regras para compilar cada arquivo .c em .o
byc_V6.o: byc_V6.c valid_func.h valid_client.h valid_vechi.h veiculo.h
	$(CC) $(CFLAGS) -c byc_V6.c

cliente.o: cliente.c valid_client.h
	$(CC) $(CFLAGS) -c cliente.c

funcionario.o: funcionario.c valid_func.h
	$(CC) $(CFLAGS) -c funcionario.c

relatorio.o: relatorio.c
	$(CC) $(CFLAGS) -c relatorio.c

valid_client.o: valid_client.c valid_func.h
	$(CC) $(CFLAGS) -c valid_client.c

valid_func.o: valid_func.c valid_func.h
	$(CC) $(CFLAGS) -c valid_func.c

valid_vechi.o: valid_vechi.c veiculo.h
	$(CC) $(CFLAGS) -c valid_vechi.c

veiculo.o: veiculo.c veiculo.h
	$(CC) $(CFLAGS) -c veiculo.c

venda.o: venda.c valid_func.h
	$(CC) $(CFLAGS) -c venda.c

# Limpar arquivos objetos e executável
clean:
	rm -f $(OBJ) $(EXEC)

# Regra para garantir que 'make' seja executado com o alvo padrão
.PHONY: all clean
