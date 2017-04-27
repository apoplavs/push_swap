/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoplavs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/02 16:40:11 by apoplavs          #+#    #+#             */
/*   Updated: 2017/04/02 16:40:12 by apoplavs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				init_flag(int ac, char **av, t_flag *flag)
{
	int			i;

	i = 0;
	ft_bzero(flag, sizeof(flag));
	while (++i < ac)
	{
		if (ft_strcmp(av[i], "-c") == 0)
			flag->color = 1;
		if (ft_strcmp(av[i], "-a") == 0)
			flag->count_opr = 1;
		if (ft_strcmp(av[i], "-v") == 0)
			flag->s_status = 1;
		if (ft_strcmp(av[i], "-t") == 0)
			flag->time_step = 1;
		if (ft_strcmp(av[i], "-e") == 0)
			flag->fail_opr = 1;
		if (ft_isdigit((int)av[i][0]) || ft_isdigit((int)av[i][1]))
			break ;
	}
	return (i - 1);
}

void			print_result(char *str, t_flag *flag)
{
	if (flag->color)
	{
		if (ft_strcmp(str, "OK\n") == 0)
			ft_printf("%s%s%s", GREEN, str, NORMAL);
		else
			ft_printf("%s%s%s", RED, str, NORMAL);
	}
	else
		ft_printf("%s", str);
}

void			print_stacks(t_stacks *stack_a, t_stacks *stack_b)
{
	ft_printf("\n------------------------------\n");
	while (stack_a || stack_b)
	{
		if (stack_a)
			stack_a = stack_a->next;
		if (stack_b)
			stack_b = stack_b->next;
		if (stack_a)
			ft_printf("|  %9d  |", stack_a->x);
		else
			ft_printf("|             |");
		if (stack_b)
			ft_printf("|  %9d  |", stack_b->x);
		else
			ft_printf("|             |");
		ft_putchar('\n');
	}
	ft_printf("------------------------------\n");
	ft_printf("|  stack A    ||    stack B  |\n");
	ft_printf("------------------------------\n");
	ft_putchar('\n');
}
