#ifndef __MONTY__H
#define __MONTY__H

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>



/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcoode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern stack_t *head;

/*File operations*/
void open_file(char *);
void read_file(FILE *);
int len_chars(FILE *);
void interpret_line(char *, int);
void find_func(char *, char *, int);

/*Stack operations*/
stack_t *create_node(int n);
void print_stack(stack_t **, unsigned int);
void add_to_stack(stack_t **, unsigned int);
void call_fun(void (*f)(stack_t **, unsigned int), char *, char *, int);
void print_top(stack_t **, unsigned int);
void pop_top(stack_t **, unsigned int);

/*Error hanlding*/
void err(int error_code, ...);


#endif /*__MONTY__H*/
