//
// Created by Andriy Poplavskyi on 3/18/17.
//
#include "push_swap.h"
#include <stdio.h>

int         recursive_sort(t_stacks *stack_a, int n, int *max, char opr, char **command)
{
	write_opr(opr, command);
	if (n <= *max && check_solve(stack_a->next, NULL))
		return (1);
	if (n > *max)
	{
		cancel_opr(opr, stack_a, *command);
		return (0);
	}
	if (opr != SA && ft_swap_stack(stack_a->next))
		if (recursive_sort(stack_a, n + 1, max, SA, command))
			return (1);
	if (opr != RRA && ft_rotate(stack_a->next, stack_a))
		if (recursive_sort(stack_a, n + 1, max, RA, command))
				return (1);
	if (opr != RA && ft_rrotate(stack_a->next, stack_a))
		if (recursive_sort(stack_a, n + 1, max, RRA, command))
				return (1);
	if (n > 0)
		cancel_opr(opr, stack_a, *command);
	return (0);
}

void        ft_sort_stack(t_stacks *stack_a, int len)
{
	t_stacks *stack_b;
	char     *command;

	stack_b = malloc(sizeof(*stack_b));
	stack_b->next = NULL;
	command = ft_strnew(1);
	a_to_b(stack_a, stack_b, &command, stack_len(stack_a));
	optimization_opr(&command);
	del_stack(stack_a);
	del_stack(stack_b);
	ft_putstr(command);
	free(command);
}


void        a_to_b(t_stacks *stack_a, t_stacks *stack_b, char **command, int len)
{
	int     max;

	if (stack_len(stack_a) < 7)
	{
		max = 4;
		while (recursive_sort(stack_a, 0, &max, '\0', command) == 0)
			max++;
		return ;
	}
	if (stack_len(stack_a) <= 3 || check_solve(stack_a->next, NULL))
	{
		ft_sort_top(stack_a, stack_b, command);
		return ;
	}
	len = ft_separate_a(stack_b, stack_a, command, len);
	a_to_b(stack_a, stack_b, command, len);
	b_to_a(stack_a, stack_b, command, len);
}

void        b_to_a(t_stacks *stack_a, t_stacks *stack_b, char **command, int len)
{
	int     len_b;

	if (len <= 3)
	{
		ft_sort_top(stack_a, stack_b, command);
		while (--len >= 0)
		{
			ft_push(stack_b->next, stack_a->next, stack_b, stack_a);
			write_opr(PA, command);
		}
		return ;
	}
	len_b = len;
	len = ft_separate_b(stack_a, stack_b, command, len);
	if (len <= 3)
		b_to_a(stack_a, stack_b, command, len_b - len);
	else
	{
		a_to_b(stack_a, stack_b, command, len);
		b_to_a(stack_a, stack_b, command, len_b - len);
	}
}
