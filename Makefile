# Definindo o compilador
CC = gcc

# Definindo as flags de compilação
CFLAGS = -Wall -Wextra -pedantic

# Definindo o nome do executável
EXEC = byc_programa

# Lista de arquivos objeto (todos os arquivos .c do projeto)
OBJ = byc_V6.o cliente.o funcionario.o relatorio.o veiculo.o venda.o entradas.o validacao.o

# Regra padrão: compilar o programa
$(EXEC): $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

# Regras para compilar os arquivos .c em .o (objetos)
byc_V6.o: byc_V6.c
	$(CC) $(CFLAGS) -c byc_V6.c

cliente.o: cliente.c
	$(CC) $(CFLAGS) -c cliente.c

funcionario.o: funcionario.c
	$(CC) $(CFLAGS) -c funcionario.c

relatorio.o: relatorio.c
	$(CC) $(CFLAGS) -c relatorio.c

veiculo.o: veiculo.c
	$(CC) $(CFLAGS) -c veiculo.c

venda.o: venda.c
	$(CC) $(CFLAGS) -c venda.c

entradas.o: entradas.c
	$(CC) $(CFLAGS) -c entradas.c

validacao.o: validacao.c
	$(CC) $(CFLAGS) -c validacao.c

# Regra para limpar arquivos objetos e executáveis
clean:
	rm -f $(OBJ) $(EXEC)

# Regra para rodar o programa (se necessário)
run: $(EXEC)
	./$(EXEC)
