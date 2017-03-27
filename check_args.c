/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoplavs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 13:15:28 by apoplavs          #+#    #+#             */
/*   Updated: 2017/03/13 13:15:48 by apoplavs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_maxint(const char *str)
{
	int		i;
	long	res;

	i = 0;
	res = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] <= '9' && str[i] >= '0')
	{
		res *= 10;
		res += str[i] - 48;
		i++;
	}
	if (res > 2147483647)
		ft_error();
}

void		check_duplicates(int *a, int len)
{
	int		i;
	int		j;

	i = -1;
	while (++i < len)
	{
		j = -1;
		while (++j < len)
			if (i != j && a[i] == a[j])
				ft_error();
	}
}

void		check_args(int ac, char **av)
{
	int		j;
	int		i;

	i = 0;
	while (++i < ac)
	{
		j = 0;
		while (av[i][j])
			if (ft_isdigit((int)av[i][j++]) == 0)
				ft_error();
		ft_maxint(av[i]);
	}
}

void        check_instructions(char *inst)
{
    if (ft_strcmp(inst, "sa") == 0 || ft_strcmp(inst, "sb") == 0
        || ft_strcmp(inst, "ss") == 0 || ft_strcmp(inst, "pa") == 0
        || ft_strcmp(inst, "pb") == 0 || ft_strcmp(inst, "ra") == 0
        || ft_strcmp(inst, "rb") == 0 || ft_strcmp(inst, "rr") == 0
        || ft_strcmp(inst, "rra") == 0 || ft_strcmp(inst, "rrb") == 0
        || ft_strcmp(inst, "rrr") == 0 || ft_strcmp(inst, "") == 0)
        return ;
    else
        ft_error();
}

void		ft_error()
{
	write(2, "Error\n", 6);
    exit(1);
}
