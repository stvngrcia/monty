#include "monty.h"

/**
 * open_file - Opens a file.
 * @file_name: String with the name of the file.
 */

void open_file(char *file_name)
{
	int file_check;
	FILE *fd;

	if (file_name == NULL)
		exit(EXIT_FAILURE);
	/*Checks if the file exists*/
	file_check = access(file_name, R_OK);
	if (file_check == -1)
		printf("call error(2)file does not exist cant open file!\n");
	fd = fopen(file_name, "r");
	if (fd == NULL)
		printf("call error(2)file does not exist cant open file!\n");

	/*errors should be handled inside this function*/
	read_file(fd);
	/*might need to check for errors on closing a file.*/
	fclose(fd);
}

/**
 * read_file - Reads the content of a file line by line.
 * @fd: Pointer to a file descriptor of an open file
 */

void read_file(FILE *fd)
{
	int line_n;
	char *lineprt;
	size_t n;

	lineprt = NULL;
	n = 0;

	if (fd == NULL)
		exit(EXIT_FAILURE);

	/*Getting each line in the file*/
	for (line_n = 1; getline(&lineprt, &n, fd) != EOF; line_n++)
	{
		interpret_line(lineprt, line_n);
	}
	free(lineprt);
}


/**
 * interpret_line - Separates each line into tokens to determine
 * which function to call.
 * @lineptr: String representing a line in a file.
 */
void interpret_line(char *lineptr, int line_number)
{
	const char *delim;
	char *opcode;
	char *value;

	if (lineptr == NULL)
		exit(EXIT_FAILURE);

	delim = "\n ";
	opcode = strtok(lineptr, delim);
	if (opcode == NULL)
	{
		printf("err when opcode is NULL\n");
		exit(1);
	}
	value = strtok(NULL, delim);
	
	find_func(opcode, value, line_number);
}

/**
 * find_func - Finds the appropite function to run the opcode instructions.
 * @opcode: The operation code, It could be push, pall, ...
 * @value: The possible value for the operation.
 * Return: TBD.s
 */

int find_func(char *opcode, char *value, int line_number)
{
	int i;

	instruction_t func_list[] = {
		{"push", add_to_stack},
		{"pall", print_stack},
		{NULL, NULL}
	};

	/*Iterates through list to fid the right function*/
	for (i = 0; func_list[i].opcode != NULL; i++)
	{
		/*When 0 found the right opcode*/
		if (strcmp(opcode, func_list[i].opcode) == 0)
		{
			call_fun(func_list[i].f, opcode, value, line_number);
		}
	}
	/*printf("opcode: %s\nvalue: %s\nline: %d\n",opcode, value, line_number);*/
	return (0);
}


void call_fun(void (*f)(stack_t **, unsigned int), char *op, char *val, int ln)
{
	extern stack_t *head;
	stack_t *node;

	if (strcmp(op, "push") == 0)
	{
		if (isdigit(*val) == 0)
		{
			printf("is digit error\n");
			exit(1);
		}
		node = create_node(atoi(val));
		f(&node, ln);
	}
	else if (strcmp(op, "pall") == 0)
		f(&head, ln);
}
