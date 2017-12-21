#include "monty.h"

/**
 * err - Prints appropiate error messages determined by their error code.
 * @error_code: The error codes are the following:
 * (1) ~> The user does not give any file or more than one file to the program.
 * (2) ~> The file provided is not a file that can be opened or read.
 * (3) ~> The file provided contains an invalid instruction.
 * (4) ~> When the program is unable to malloc more memory.
 * (5) ~> When the parameter passed to the instruction "push" is not an int.
 * (6) ~> When the stack it empty for pint.
 * (7) ~> When the stack it empty for pop.
 * (8) ~> When stack is too short for operation.
 */
void err(int error_code, ...)
{
	va_list ag;
	char *op;
	int l_num;

	va_start(ag, error_code);
	switch (error_code)
	{
		case 1:
			printf("USAGE: monty file\n");
			break;
		case 2:
			printf("Error: Can't open file %s\n",
				va_arg(ag, char *));
			break;
		case 3:
			l_num = va_arg(ag, int);
			op = va_arg(ag, char *);
			printf("L%d: unknown instruction %s\n", l_num, op);
			break;
		case 4:
			printf("Error: malloc failed\n");
			break;
		case 5:
			printf("L%d: usage: push integer\n", va_arg(ag, int));
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}

/**
 * more_err - handles errors.
 * @error_code: The error codes are the following:
 * (6) ~> When the stack it empty for pint.
 * (7) ~> When the stack it empty for pop.
 * (8) ~> When stack is too short for operation.
 */
void more_err(int error_code, ...)
{
	va_list ag;
	char *op;
	int l_num;

	va_start(ag, error_code);
	switch (error_code)
	{
		case 6:
			printf("L%d: can't pint, stack empty\n",
				va_arg(ag, int));
			break;
		case 7:
			printf("L%d: can't pop an empty stack\n",
				va_arg(ag, int));
			break;
		case 8:
			l_num = va_arg(ag, unsigned int);
			op = va_arg(ag, char *);
			printf("L%d: can't %s, stack too short\n", l_num, op);
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}
