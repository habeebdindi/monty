#include "monty.h"

int main(int argc, char *argv[])
{
	char *reader = malloc(sizeof(char) * LIM)
	if (argc < 2 || argc > 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		EXIT_FAILURE;
	}

	bytecode = open(argv[1], O_RDONLY);/* Open monty bytecode for reading */
	if (bytecode == -1)
	{
		fprintf("Error: Can't open file %s", argv[1]);
		EXIT_FAILURE;
	}
	while (1)
	{

	}	

	close(bytecode);
	return 0;
}
