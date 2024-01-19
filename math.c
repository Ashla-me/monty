#include "monty.h"

/**
 * _subn - sub top of stack y second top stack
 * @stack: pointer to lists for monty stack
 * @line_number: number of line opcode occurs on
 */
void _subn(stack_t **stack, unsigned int line_number)
{
        stack_t *tmp = *stack;
        int sub = 0, a = 0;

        if (tmp == NULL)
        {
                fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
                exit(EXIT_FAILURE);
        }

        while (tmp)
        {
                tmp = tmp->next;
                a++;
        }

        if (stack == NULL || (*stack)->next == NULL || a <= 1)
        {
                fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
                exit(EXIT_FAILURE);
        }
        sub = (*stack)->next->n - (*stack)->n;
        _pop_(stack, line_number);

        (*stack)->n = sub;
}

/**
 * _muln - mul top of stack y second top stack
 * @stack: pointer to lists for monty stack
 * @line_number: number of line opcode occurs on
 */
void _muln(stack_t **stack, unsigned int line_number)
{
        int aux;

        if (*stack == NULL || (*stack)->next == NULL)
        {
                fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
                free(var_global.buffer);
                fclose(var_global.file);
                _free_dlistint(*stack);
                exit(EXIT_FAILURE);
        }
        else
        {
                aux = (*stack)->n;
                _pop_(stack, line_number);
                (*stack)->n *= aux;
        }
}

/**
 * _divn - divide top of stack by second top stack
 * @stack: pointer to lists for monty stack
 * @line_number: number of line opcode occurs on
 */
void _divn(stack_t **stack, unsigned int line_number)
{
        int div = 0;

        if (*stack == NULL || (*stack)->next == NULL)
        {
                fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
                free(var_global.buffer);
                fclose(var_global.file);
                _free_dlistint(*stack);
                exit(EXIT_FAILURE);
        }
        else if ((*stack)->n == 0)
        {
                fprintf(stderr, "L%d: division by zero\n", line_number);
                free(var_global.buffer);
                fclose(var_global.file);
                _free_dlistint(*stack);
                exit(EXIT_FAILURE);
        }
        else
        {
                div = (*stack)->n;
                _pop_(stack, line_number);
                (*stack)->n /= div;
        }
}

/**
 * _modn - mod top of stack y second top stack
 * @stack: pointer to lists for monty stack
 * @line_number: number of line opcode occurs on
 */
void _modn(stack_t **stack, unsigned int line_number)
{
        int mod = 0;

        if (*stack == NULL || (*stack)->next == NULL)
        {
                fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
                free(var_global.buffer);
                fclose(var_global.file);
                _free_dlistint(*stack);
                exit(EXIT_FAILURE);
        }
        else if ((*stack)->n == 0)
        {
                fprintf(stderr, "L%d: division by zero\n", line_number);
                free(var_global.buffer);
                fclose(var_global.file);
                _free_dlistint(*stack);
                exit(EXIT_FAILURE);
        }
        else
        {
                mod = (*stack)->n;
                _pop_(stack, line_number);
                (*stack)->n %= mod;
        }
}
