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
	char *lineprt;
	size_t n;

	lineprt = NULL;
	n = 0;

	if (fd == NULL)
		exit(EXIT_FAILURE);

	/*Getting each line in the file*/
	while (getline(&lineprt, &n, fd) != EOF)
	{
		interpret_line(lineprt);
	}
	free(lineprt);
}


/**
 * interpret_line - Separates each line into tokens to determine
 * which function to call.
 * @lineptr: String representing a line in a file.
 */
void interpret_line(char *lineptr)
{
	const char *delim;
	char *token;

	if (lineprt == NULL)
		exit(EXIT_FAILURE);

	delim = "\n ";
	token = strtok(lineptr, delim);

	while (token != NULL)
	{
		printf("%s\n", token);
		token = strtok(NULL, delim);
	}
}
