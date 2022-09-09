#include "monty.h"

/**
 * add - Adds the top two elements of the stack. 
 * @stack: A pointer to a pointer to the beginning of the stack
 * implementation list.
 * @line_number: Line number.
 *
 */

void add(stack_t **stack, unsigned int line_number)
{
	stack_t *head = *stack, *next = NULL;
	int sum, len = dlistint_len(*stack);

	if (len < 2)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	next = head->next;
	sum = (*stack)->n + (((*stack)->next)->n);
	next->n = sum;
	*stack = next;
	free(head);
}

/**
 * nop - Does nothing.
 * @stack: A pointer to a pointer to the begining of the stack
 * implementation list.
 * @line_number: Line number.
 *
 */

void nop(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	(void)stack;
}

/**
 * sub - subtracts the top element of the stack from the
 * second top element of the stack.
 * @stack: A pointer that points to the beginning of the stack implementation
 * @line_number: Line number
 *
 */

void sub(stack_t **stack, unsigned int line_number)
{
	int diff, len;
	stack_t *temp = *stack;

	len = dlistint_len(*stack);
	if (len < 2)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	diff = (temp->next->n) - (temp->n);
	temp->next->n = diff;
	temp->next->prev = NULL;
	*stack = temp->next;
	free(temp);
}

/**
 * divt - divides the second top element of the stack by the top element.
 * @stack: a pointer to a pointer to the beginning of the stack implementation
 * @line_number: Line number
 *
 */

void divt(stack_t **stack, unsigned int line_number)
{
	int quotient;
	stack_t *temp = *stack;
	int len = dlistint_len(*stack);

	if (len < 2)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (temp->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	quotient = (temp->next->n) / (temp->n);
	temp->next->n = quotient;
	temp->next->prev = NULL;
	*stack = temp->next;
	free(temp);
}

/**
 * mul - multiplies the second top element of the stack with the top element.
 * @stack: a pointer to a pointer to the beginning of the stack implementation
 * @line_number: Line number
 *
 */

void mul(stack_t **stack, unsigned int line_number)
{
	int pro;
	stack_t *temp = *stack;
	int len = dlistint_len(*stack);

	if (len < 2)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	pro = (temp->n) * (temp->next->n);
	temp->next->n = pro;
	temp->next->prev = NULL;
	*stack = temp->next;
	free(temp);
}
