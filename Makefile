all: 
	gcc -Wall byc_V6.c cliente.c veiculo.c funcionario.c venda.c relatorio.c -o buyyourcar

run: 
	./buyyourcar 
