/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   separate_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoplavs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 16:04:18 by apoplavs          #+#    #+#             */
/*   Updated: 2017/03/29 16:04:20 by apoplavs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			rt_rrt(t_stacks *stack, char **command, char opr,
	int (*f)(t_stacks*, t_stacks*))
{
	f(stack->next, stack);
	write_opr(opr, command);
}

int				separate_full_b(t_stacks *dst, t_stacks *src,
	t_stacks *end, char **command)
{
	int			medium;
	int			count;

	medium = find_medium(src, -1);
	count = 0;
	while (is_have_over(src, end, medium))
	{
		while (src->next->x >= medium)
		{
			ft_push(src->next, dst->next, src, dst);
			write_opr(PA, command);
			count++;
		}
		if (is_have_over(src, end, medium))
			rt_rrt(src, command, RB, &ft_rotate);
	}
	return (count);
}

int				separate_part_b(t_stacks *dst, t_stacks *src,
	t_stacks *end, char **command)
{
	int			medium;
	int			count;
	int			count_rr;

	medium = find_medium_in_part(src, -1, end);
	count = 0;
	count_rr = 0;
	while (is_have_over(src, end, medium))
	{
		while (src->next->x >= medium)
		{
			ft_push(src->next, dst->next, src, dst);
			write_opr(PA, command);
			count++;
		}
		if (is_have_over(src, end, medium))
		{
			rt_rrt(src, command, RB, &ft_rotate);
			count_rr++;
		}
	}
	while (--count_rr >= 0)
		rt_rrt(src, command, RRB, &ft_rrotate);
	return (count);
}

int				ft_separate_b(t_stacks *dst, t_stacks *src,
	char **command, int len)
{
	t_stacks	*end;

	end = get_end(src->next, len);
	if (end->next == NULL)
		return (separate_full_b(dst, src, end, command));
	else
		return (separate_part_b(dst, src, end, command));
}
