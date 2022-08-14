#include "escalonador.h"

/*

Por exemplo, forma de executar o programa:
./trabalho_escalonador tarefas.txt 2

Arquivo de entrada
“tarefas.txt”
a1 5
a2 1
a3 10
b1 10
b2 3
b3 7
b4 8
c1 8
c2 2

Arquivo de saída
Processador_1
a2;0;1
b2;1;4
b3;4;11
c1;11;19
b1;19;29
Processador_2
c2;0;2
a1;2;7
b4;7;15
a3;15;25

*/

int main (int argc, char **argv)
{
	int		fd;
	char	buffer[BUFFER_SIZE];
	char	**splited;

	if(argc != 3)
	{
		printf("use: %s <arquivo de entrada> <qtd de nucleos>\n", argv[0]);
		printf("Exemplo: %s entrada.txt 2\n", argv[0]);
		exit(1);
	}

	fd = open(argv[1], O_RDONLY);
	read(fd, buffer, BUFFER_SIZE);
	close(fd);

	splited = ft_strsplit(buffer, '\n');

	if (escalonador(splited, ft_atoi(argv[2])) == -1)
	{
		printf("Erro ao escalonar\n");
		exit(1);
	}
	return (0);
}