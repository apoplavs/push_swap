

#include "push_swap.h"

int				ft_swap_stack(t_stacks *stack)
{

	if ( stack != NULL && stack->next != NULL)
	{
		ft_swap(&stack->x, &stack->next->x);

		return (1);
	}
	return (0);
}

int				ft_push(t_stacks *stack1, t_stacks *stack2, t_stacks *top_s1, t_stacks *top_s2)
{
	t_stacks    *temp;

	if (stack1 != NULL)
	{
		temp = stack1;
		stack1 = stack1->next;
		top_s1->next = stack1;
		temp->next = stack2;
		top_s2->next = temp;
		return (1);
	}
		return (0);
}

int				ft_rotate(t_stacks *stack, t_stacks *top_s)
{
	t_stacks	*temp;

	if (stack == NULL || stack->next == NULL)
		return (0);
	temp = stack;
	stack = stack->next;
	top_s->next = stack;
	while (stack->next != NULL)
		stack = stack->next;
	stack->next = temp;
	temp->next = NULL;
	return (1);
}

int				ft_rrotate(t_stacks *stack, t_stacks *top_s)
{
	t_stacks	*temp;
	t_stacks	*pre_last;

	if (stack == NULL || stack->next == NULL)
		return (0);
	temp = stack;
	while (stack->next->next != NULL)
		stack = stack->next;
	pre_last = stack;
	stack = stack->next;
	stack->next = temp;
	pre_last->next = NULL;
	top_s->next = stack;
	return (1);
}

int				check_solve(t_stacks *stack_a, t_stacks *stack_b)
{
	int			t;

	if (stack_b != NULL)
		return (0);
	while (stack_a->next != NULL)
	{
		t = stack_a->x;
		stack_a = stack_a->next;
		if (t > stack_a->x)
			return (0);
	}
	return (1);
}