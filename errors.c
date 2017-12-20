#include "monty.h"

/**
 * err - Prints appropiate error messages determined by their error code.
 * @error_code: The error codes are the following:
 * (1) ~> The user does not give any file or more than one file to the program.
 * (2) ~> The file provided is not a file that can be opened or read.
 * (3) ~> The file provided contains an invalid instruction.
 * (4) ~> When the program is unable to malloc more memory.
 * (5) ~> When the parameter passed to the instruction "push" is not an int.
 *
 */
void err(int error_code, ...)
{
	va_list args;
	char *opcode;
	int l_num;

	va_start(args, error_code);

	switch (error_code)
	{
		case 1:
			printf("USAGE: monty file\n");
			break;
		case 2:
			printf("Error: Can't open file %s\n",
				va_arg(args, char *));
			break;
		case 3:
			l_num = va_arg(args, int);
			opcode = va_arg(args, char *);
			printf("L%d: unknown instruction %s\n", l_num, opcode);
			break;
		case 4:
			printf("Error: malloc failed\n");
			break;
		case 5:
			printf("L%d: usage: push integer\n", va_arg(args, int));
			break;
		default:
			break;
	}
	exit(EXIT_FAILURE);
}
