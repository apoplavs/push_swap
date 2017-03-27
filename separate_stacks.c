//
// Created by Andriy Poplavskyi on 3/26/17.
//

#include "push_swap.h"

int             separate_full_b(t_stacks *dst, t_stacks *src, t_stacks *end, char **command)
{
	int         medium;
	int         count;

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
		{
			ft_rotate(src->next, src);
			write_opr(RB, command);
		}
	}
	return (count);
}

int             separate_part_b(t_stacks *dst, t_stacks *src, t_stacks *end, char **command)
{
	int         medium;
	int         count;
	int         count_rr;


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
			ft_rotate(src->next, src);
			write_opr(RB, command);
			count_rr++;
		}
	}
	while (--count_rr >= 0)
	{
		ft_rrotate(src->next, src);
		write_opr(RRB, command);
	}
	return (count);
}

int             ft_separate_b(t_stacks *dst, t_stacks *src, char **command, int len)
{
	t_stacks    *end;

	end = get_end(src->next, len);
	if (end->next == NULL)
		return (separate_full_b(dst, src, end, command));
	else
		return (separate_part_b(dst, src, end, command));
}

int             separate_full_a(t_stacks *dst, t_stacks *src, t_stacks *end, char **command)
{
	int         medium;
	int         count;

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
		{
			ft_rotate(src->next, src);
			write_opr(RA, command);
		}
	}
	return (count);
}

int             separate_part_a(t_stacks *dst, t_stacks *src, t_stacks *end, char **command)
{
	int         medium;
	int         count;
	int         count_rr;


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
			ft_rotate(src->next, src);
			write_opr(RA, command);
			count_rr++;
		}
	}
	while (--count_rr >= 0)
	{
		ft_rrotate(src->next, src);
		write_opr(RRA, command);
	}
	return (count);
}

int             ft_separate_a(t_stacks *dst, t_stacks *src, char **command, int len)
{
	t_stacks    *end;

	end = get_end(src->next, len + 2);
	if (end->next == NULL)
		return (separate_full_a(dst, src, end, command));
	else
		return (separate_part_a(dst, src, end, command));
}
