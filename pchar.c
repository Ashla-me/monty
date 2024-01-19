#include "monty.h"

/**
 * pstr - mod top of stack y second top stack
 * @stack: pointer to lists for monty stack
 * @line_number: number of line opcode occurs on
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	int y = 0;

	(void)line_number;


	while (tmp)
	{
		y = tmp->n;
		if (y == 0 || _isalpha(y) == 0)
			break;
		putchar(y);
		tmp = tmp->next;
	}
	putchar('\n');
}

/**
 * _rotl_ - mod top of stack y second top stack
 * @stack: pointer to lists for monty stack
 * @line_number: number of line opcode occurs on
 */
void _rotl_(stack_t **stack, unsigned int line_number)
{
	stack_t *run = *stack;


	int aux = 0;

	if (!line_number || !stack || !*stack || !(*stack)->next)
		return;

	aux = run->n;

	while (run->next)
	{
		run = run->next;
		run->prev->n = run->n;
	}

	run->n = aux;
}

/**
 * _rotr_ - mod top of stack y second top stacks
 * @stack: pointer to lists for monty stack
 * @line_number: number of line opcode occurs on
 */
void _rotr_(stack_t **stack, unsigned int line_number)
{
	stack_t *run = *stack;

	int aux = 0;

	if (!line_number || !stack || !*stack || !(*stack)->next)
		return;

	while (run->next)
		run = run->next;

	aux = run->n;

	while (run->prev)
	{
		run = run->prev;
		run->next->n = run->n;
	}

	run->n = aux;
}
