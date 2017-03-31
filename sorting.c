//
// Created by Andriy Poplavskyi on 3/20/17.
//
#include "push_swap.h"

static int		partition(int a[], int less, int high, int i)
{
	int			pivot;
	int			j;
	int			t;

	pivot = a[less];
	j = high + 1;
	while(1)
	{
		while(++i <= high && a[i] <= pivot)
			;
		while(--j && a[j] > pivot )
			;
		if(i >= j)
			break;
		t = a[i];
		a[i] = a[j];
		a[j] = t;
	}
	t = a[less];
	a[less] = a[j];
	a[j] = t;
	return (j);
}

void			ft_qsort(int a[], int less, int high)
{
	int			j;

	if(less < high)
	{
		j = partition(a, less, high, less);
		ft_qsort( a, less, j-1);
		ft_qsort( a, j+1, high);
	}
}

int				if_need_swap(t_stacks *stack)
{
	if (stack->next != NULL && stack->next->next != NULL)
		return (stack->next->x > stack->next->next->x ? 1 : 0);
	else
		return (-1);
}

int            if_need_rotate(t_stacks *stack, char **command, int f)
{
	if (f == 1)
		if (if_need_swap(stack->next) == 1)
		{
			ft_rotate(stack->next, stack);
			write_opr(RA, command);
			return (1);
		}
	if (f == 2)
		if (!if_need_swap(stack->next))
		{
			ft_rotate(stack->next, stack);
			write_opr(RB, command);
			return (1);
		}
	return (0);
}

void			ft_sort_top(t_stacks *stack_a, t_stacks *stack_b, char **command)
{
	int			fa;
	int			fb;

	if (if_need_swap(stack_a) == 1 && ft_swap_stack(stack_a->next))
		write_opr(SA, command);
	if (!if_need_swap(stack_b) && ft_swap_stack(stack_b->next))
		write_opr(SB, command);
	fa = if_need_rotate(stack_a, command, 1);
	fb = if_need_rotate(stack_b, command, 2);
	if (fa && ft_swap_stack(stack_a->next))
		write_opr(SA, command);
	if (fb && ft_swap_stack(stack_b->next))
		write_opr(SB, command);
	if (fa && ft_rrotate(stack_a->next, stack_a))
		write_opr(RRA, command);
	if (fb && ft_rrotate(stack_b->next, stack_b))
		write_opr(RRB, command);
	if (if_need_swap(stack_a) == 1 && ft_swap_stack(stack_a->next))
		write_opr(SA, command);
	if (!if_need_swap(stack_b) && ft_swap_stack(stack_b->next))
		write_opr(SB, command);
}
