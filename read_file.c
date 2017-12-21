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
		err(2, file_name);
	/*Checks if the file exists*/
	file_check = access(file_name, R_OK);
	if (file_check == -1)
		err(2, file_name);
	fd = fopen(file_name, "r");
	if (fd == NULL)
		err(2, file_name);

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
		err(2, "file_name");

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
 * @line_number: Line number for the opcode.
 */
void interpret_line(char *lineptr, int line_number)
{
	const char *delim;
	char *opcode;
	char *value;

	if (lineptr == NULL)
		err(4);
	delim = "\n ";
	opcode = strtok(lineptr, delim);

	/*hanlding blank lines*/
	if (opcode == NULL)
		return;
	value = strtok(NULL, delim);
	find_func(opcode, value, line_number);
}

/**
 * find_func - Finds the appropite function to run the opcode instructions.
 * @opcode: The operation code, It could be push, pall, ...
 * @value: The possible value for the operation.
 * @line_number: Line number for the opcode.
 */
void find_func(char *opcode, char *value, int line_number)
{
	int i;
	int flag;

	instruction_t func_list[] = {
		{"push", add_to_stack},
		{"pall", print_stack},
		{"pint", print_top},
		{"pop", pop_top},
		{"nop", nop},
		{"swap", swap_nodes},
		{"add", add_nodes},
		{NULL, NULL}
	};
	flag = 1;
	/*Iterates through list to find the right function*/
	for (i = 0; func_list[i].opcode != NULL; i++)
	{
		/*When 0 found the right opcode*/
		if (strcmp(opcode, func_list[i].opcode) == 0)
		{
			call_fun(func_list[i].f, opcode, value, line_number);
			flag = 0;
		}
	}
	if (flag == 1)
		err(3, line_number, opcode);
}

/**
 * call_fun - Calls the required function.
 * @f: Pointer to the function that is about to be called.
 * @op: string representing the opcode.
 * @val: string representing a numeric value.
 * @ln: line numeber for the instruction.
 */
void call_fun(void (*f)(stack_t **, unsigned int), char *op, char *val, int ln)
{
	stack_t *node;
	int flag;
	int i;

	flag = 1;
	if (strcmp(op, "push") == 0)
	{
		/*Checks if the number is negative and moves the val ptr*/
		if (val != NULL && val[0] == '-')
		{
			val = val + 1;
			flag = -1;
		}
		/*val is not a digit is the return value is 0*/
		if (val == NULL)
			err(5, ln);
		for(i = 0; val[i] != '\0'; i++)
		{
			if (isdigit(val[i]) == 0)
				err(5, ln);
		}
		node = create_node(atoi(val) * flag);
		f(&node, ln);
	}
	else
		f(&head, ln);
}
