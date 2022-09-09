#include "monty.h"

/**
 * mod - calculates the remainder of the stack's top element's division by the 
 * second-top element.
 * @stack: A pointer to a pointer to the beginning of the stack
 * @line_number: Line number.
 *
 */

void mod(stack_t **stack, unsigned int line_number)
{
	int rem;
	stack_t *temp = *stack;
	int len = dlistint_len(*stack);

	if (len < 2)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (temp->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	rem = (temp->next->n) % (temp->n);
	temp->next->n = rem;
	temp->next->prev = NULL;
	*stack = temp->next;
	free(temp);
}

/**
 * pchar - prints a new line after the char currently at the top of the stack.
 * @stack: A pointer to a pointer to the beginning of the stack
 * implementation list.
 * @line_number: Line number.
 *
 */

void pchar(stack_t **stack, unsigned int line_number)
{
	if (!(*stack))
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%c\n", (*stack)->n);
}

/**
 * pstr - prints the string starting at the top of the stack,
 * followed by a new line.
 * @stack: A pointer to a pointer to the beginning of the stack
 * implementation list.
 * @line_number: Line number.
 *
 */

void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *traverse = *stack;

	(void)line_number;

	while (traverse && traverse->n > 0 && traverse->n < 127)
	{
		printf("%c", traverse->n);
		traverse = traverse->next;
	}
	putchar('\n');
}

/**
 * rotl -  Rotates the stack to the top.
 * @stack: A pointer to a pointer to the beginning of the stack
 * implementation list.
 * @line_number: Line number.
 *
 */

void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	(void)line_number;
	if (*stack == NULL || (*stack)->next == NULL)
		return;

	temp = *stack;
	*stack = temp->next;
	(*stack)->prev = NULL;
	add_dnodeint_end(stack, temp->n);
	free(temp);
}

/**
 * rotr -  Rotates the stack to the bottom.
 * @stack: A pointer to a pointer to the beginning of the stack
 * implementation list.
 * @line_number: Line number.
 *
 */

void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	(void)line_number;
	if (*stack == NULL || (*stack)->next == NULL)
		return;

	temp = get_dnodeint_at_index(*stack,  dlistint_len(*stack) - 1);
	add_dnodeint(stack, temp->n);
	delete_dnodeint_at_index(stack, dlistint_len(*stack) - 1);
}
