#include "monty.h"

/**
 * main - Entry Point
 * @argc: Number of command line arguments.
 * @argv: An array containing the arguments.
 * Return: Always Zero.
 */
int main(int argc, char **argv)
{

	extern stack_t *head;
	head = NULL;
	if (argc < 2 || argc > 2)
		printf("call error(1)not file name or more than one file\n");
	open_file(argv[1]);
	printf("head->n %d\n", head->n);
	return (0);
}
