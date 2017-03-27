//
// Created by Andriy Poplavskyi on 3/22/17.
//
#include "push_swap.h"

t_stacks        *get_end(t_stacks *src, int len)
{
	int         i;

	i = 0;
	while (++i < len && src->next)
		src = src->next;
	return (src);
}


int					stack_len(t_stacks *stack)
{
	int				i;

	i = 0;
	while (stack->next)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

int                 is_have_less(t_stacks *stack, t_stacks *end, int medium)
{
	while (stack->next && stack != end)
	{
		stack = stack->next;
		if (stack->x < medium)
			return (1);
	}
	return (0);
}

int                 is_have_over(t_stacks *stack, t_stacks *end, int medium)
{
	while (stack->next && stack != end)
	{
		stack = stack->next;
		if (stack->x > medium)
			return (1);
	}
	return (0);
}

int					find_medium(t_stacks *stack, int i)
{
	int             len;
	int             *mas;

	len = stack_len(stack);
	mas = malloc(sizeof(int) * len);
	while (stack->next)
	{
		stack = stack->next;
		mas[++i] = stack->x;
	}
	ft_qsort(mas, 0, len - 1);
	i = mas[len / 2];
	return (i);
}

int					find_medium_in_part(t_stacks *stack, int i, t_stacks *end)
{
	int             *mas;
	t_stacks        *p;
	int             len;

	len = 0;
	p = stack;
	while (p->next != end)
	{
		p = p->next;
		len++;
	}
	mas = malloc(sizeof(int) * len + 2);
	while (stack->next && stack->next != end)
	{
		stack = stack->next;
		mas[++i] = stack->x;
	}
	ft_qsort(mas, 0, len - 1);
	i = mas[len / 2];
	return (i);
}

int     check_end_stack(t_stacks *stack, t_stacks *end_stack)
{
	while (stack->next)
		stack = stack->next;
	if (end_stack == stack)
		return (1);
	return (0);
}




















