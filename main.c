#include "monty.h"
stack_t *head;

/**
 * main - Entry Point
 * @argc: Number of command line arguments.
 * @argv: An array containing the arguments.
 * Return: Always Zero.
 */
int main(int argc, char **argv)
{
	head = NULL;
	if (argc < 2 || argc > 2)
		err(1);
	open_file(argv[1]);
	return (0);
}
