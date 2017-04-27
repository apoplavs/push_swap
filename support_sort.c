/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoplavs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/02 17:06:04 by apoplavs          #+#    #+#             */
/*   Updated: 2017/04/02 17:06:05 by apoplavs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stacks		*get_end(t_stacks *src, int len)
{
	int			i;

	i = 0;
	while (++i < len && src->next)
		src = src->next;
	return (src);
}

int				is_have_less(t_stacks *stack, t_stacks *end, int medium)
{
	while (stack->next && stack != end)
	{
		stack = stack->next;
		if (stack->x < medium)
			return (1);
	}
	return (0);
}

int				is_have_over(t_stacks *stack, t_stacks *end, int medium)
{
	while (stack->next && stack != end)
	{
		stack = stack->next;
		if (stack->x >= medium)
			return (1);
	}
	return (0);
}

int				find_medium(t_stacks *stack, int i)
{
	int			len;
	int			*mas;

	len = stack_len(stack);
	mas = malloc(sizeof(int) * len);
	while (stack->next)
	{
		stack = stack->next;
		mas[++i] = stack->x;
	}
	ft_qsort(mas, 0, len - 1);
	i = mas[len / 2];
	free(mas);
	return (i);
}

int				find_medium_in_part(t_stacks *stack, int i, t_stacks *end)
{
	int			*mas;
	t_stacks	*p;
	int			len;

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
	free(mas);
	return (i);
}
