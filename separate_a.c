/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   separate_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoplavs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 16:04:10 by apoplavs          #+#    #+#             */
/*   Updated: 2017/03/29 16:04:12 by apoplavs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				separate_full_a(t_stacks *dst, t_stacks *src,
	t_stacks *end, char **command)
{
	int			medium;
	int			count;

	medium = find_medium(src, -1);
	count = 0;
	while (is_have_less(src, end, medium))
	{
		while (src->next->x < medium)
		{
			ft_push(src->next, dst->next, src, dst);
			write_opr(PB, command);
			count++;
		}
		if (is_have_less(src, end, medium))
			rt_rrt(src, command, RA, &ft_rotate);
	}
	return (count);
}

int				separate_part_a(t_stacks *dst, t_stacks *src,
	t_stacks *end, char **command)
{
	int			medium;
	int			count;
	int			count_rr;

	medium = find_medium_in_part(src, -1, end);
	count = 0;
	count_rr = 0;
	while (is_have_less(src, end, medium))
	{
		while (src->next->x < medium)
		{
			ft_push(src->next, dst->next, src, dst);
			write_opr(PB, command);
			count++;
		}
		if (is_have_less(src, end, medium))
		{
			rt_rrt(src, command, RA, &ft_rotate);
			count_rr++;
		}
	}
	while (--count_rr >= 0)
		rt_rrt(src, command, RRA, &ft_rrotate);
	return (count);
}

int				ft_separate_a(t_stacks *dst, t_stacks *src,
	char **command, int len)
{
	t_stacks	*end;

	end = get_end(src->next, len + 2);
	if (end->next == NULL)
		return (separate_full_a(dst, src, end, command));
	else
		return (separate_part_a(dst, src, end, command));
}

void			cancel_opr(char opr, t_stacks *stack_a, char *command)
{
	int			i;
	
	i = 0;
	if (opr == SA)
		ft_swap_stack(stack_a->next);
	else if (opr == RA)
		ft_rrotate(stack_a->next, stack_a);
	else if (opr == RRA)
		ft_rotate(stack_a->next, stack_a);
	while (command[i + 1])
		i++;
	while (i > 0 && command[i - 1] != '\n')
		i--;
	command[i] = '\0';
	command[i + 1] = '\0';
}

int				stack_len(t_stacks *stack)
{
	int			i;

	i = 0;
	while (stack->next)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

