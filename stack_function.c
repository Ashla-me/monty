#include "monty.h"
/**
 * _swap_ - swap top of stack y second top stack
 * @stack: pointer to lists for monty stack
 * @line_number: number of line opcode occurs on
 */

void _swap_(stack_t **stack, unsigned int line_number)
{
        stack_t *run;
        int tmp;

        run = *stack;
        if (run == NULL || run->next == NULL)
        {
                fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
                exit(EXIT_FAILURE);
        }
        tmp = run->n;
        run->n = run->next->n;
        run->next->n = tmp;
}

/**
 * _addn - add top of stack y second top stack
 * @stack: pointer to lists for monty stack
 * @line_number: number of line opcode occurs on
 */

void _addn(stack_t **stack, unsigned int line_number)
{
        stack_t *tmp = *stack;
        int sum = 0, b = 0;

        if (tmp == NULL)
        {
                fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
                exit(EXIT_FAILURE);
        }

        while (tmp)
        {
                tmp = tmp->next;
                b++;
        }

        if (stack == NULL || (*stack)->next == NULL || b <= 1)
        {
                fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
                exit(EXIT_FAILURE);
        }
        sum = (*stack)->next->n + (*stack)->n;
        _pop_(stack, line_number);

        (*stack)->n = sum;
}

/**
 * _nop_ - nop top of stack y second top stack
 * @stack: pointer to lists for monty stack
 * @line_number: number of line opcode occurs on
 */

void _nop_(__attribute__ ((unused))stack_t **stack,
                __attribute__ ((unused)) unsigned int line_number)
{
        ;
}

/**
 * pchar - prints the ASCII value of a number
 * @stack: pointer to the top of the stack
 * @line_number: the index of the current line
 *
 */
void pchar(stack_t **stack, unsigned int line_number)
{
        int all;

        if (stack == NULL || *stack == NULL)
        {
                fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
                free(var_global.buffer);
                fclose(var_global.file);
                _free_dlistint(*stack);
                exit(EXIT_FAILURE);
        }

        all = (*stack)->n;
        if (all > 127 || all < 0)
        {
                fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
                free(var_global.buffer);
                fclose(var_global.file);
                _free_dlistint(*stack);
                exit(EXIT_FAILURE);
        }

        putchar(all);
        putchar('\n');
}

/**
 * _isalpha_ - checks if int is in alphabet
 * @c: int
 * Return: 1 if yes, 0 if no
 */
int _isalpha_(int c)
{
        if ((c >= 97 && c <= 122) || (c >= 65 && c <= 90))
                return (1);
        else
                return (0);
}
