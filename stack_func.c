#include "monty.h"

void add_to_stack(stack_t **stack, unsigned int line_number)
{
	extern stack_t *head;

	(void) line_number;
	if (stack == NULL || *stack == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *stack;
	}
}
void print_stack(stack_t **stack, unsigned int line_number)
{	(void) stack;
	(void) line_number;
	printf("---print_stack---\n");
}


/**
 * create_node - Creates and populates a node.
 * @n: Number to go inside the node.
 * Return: Upon sucess a pointer to the node. Otherwise NULL.
 */
stack_t *create_node(int n)
{
	stack_t *node;

	node = malloc(sizeof (stack_t));
	if (node == NULL)
		return (NULL);
	node->next = NULL;
	node->prev = NULL;
	node->n = n;
	return (node);
}