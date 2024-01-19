#include "monty.h"
global_var var_global;
/**
 * main - driver function for monty program
 * @argc: int num of arguments
 * @argv: opcode file
 * Return: 0
 */
int main(int argc, char **argv)
{
	stack_t *stack;

	stack = NULL;
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	_read_file(arv[1], &stack);
    /* recordar liberar memorias */
	_free_dlistint(stack);
	return (0);
}
