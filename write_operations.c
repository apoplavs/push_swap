/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoplavs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/02 17:07:28 by apoplavs          #+#    #+#             */
/*   Updated: 2017/04/02 17:07:29 by apoplavs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				write_opr(char opr, char **command)
{
	char		*p;

	p = *command;
	if (opr == SA)
		*command = ft_strjoin(*command, "sa\n");
	else if (opr == SB)
		*command = ft_strjoin(*command, "sb\n");
	else if (opr == PA)
		*command = ft_strjoin(*command, "pa\n");
	else if (opr == PB)
		*command = ft_strjoin(*command, "pb\n");
	else if (opr == RA)
		*command = ft_strjoin(*command, "ra\n");
	else if (opr == RB)
		*command = ft_strjoin(*command, "rb\n");
	else if (opr == RRA)
		*command = ft_strjoin(*command, "rra\n");
	else if (opr == RRB)
		*command = ft_strjoin(*command, "rrb\n");
	else
		return (0);
	free(p);
	return (1);
}

void			replace_opr(char **command, char *opr, char *new_opr)
{
	char		*s;
	char		*p;
	char		*ps;
	int			i[2];
	char		*new_inst;

	i[0] = 0;
	s = *command;
	ps = s;
	new_inst = ft_strnew(ft_strlen(*command));
	p = ft_strstr(s, opr);
	while (s != p)
	{
		new_inst[i[0]] = *s;
		i[0]++;
		s++;
	}
	ft_strcat(new_inst, new_opr);
	i[1] = (int)ft_strlen(opr);
	while (--i[1] >= 0)
		s++;
	ft_strcat(new_inst, s);
	*command = new_inst;
	free(ps);
}

int				optim1(char **command)
{
	if (ft_strstr(*command, "sa\nsb\n") != NULL)
		replace_opr(command, "sa\nsb\n", "ss\n");
	else if (ft_strstr(*command, "sb\nsa\n") != NULL)
		replace_opr(command, "sb\nsa\n", "ss\n");
	else if (ft_strstr(*command, "\nra\nrb\n") != NULL)
		replace_opr(command, "\nra\nrb\n", "\nrr\n");
	else if (ft_strstr(*command, "rra\nrrb\n") != NULL)
		replace_opr(command, "rra\nrrb\n", "rrr\n");
	else if (ft_strstr(*command, "rrb\nrra\n") != NULL)
		replace_opr(command, "rrb\nrra\n", "rrr\n");
	else if (ft_strstr(*command, "rb\npa\nrrb\n") != NULL)
		replace_opr(command, "rb\npa\nrrb\n", "sb\npa\n");
	else if (ft_strstr(*command, "ra\npb\nrra\n") != NULL)
		replace_opr(command, "ra\npb\nrra\n", "sa\npb\n");
	else if (ft_strstr(*command, "rb\nsb\nrrb\npa\n") != NULL)
		replace_opr(command, "rb\nsb\nrrb\npa\n", "pa\nsb\n");
	else
		return (0);
	return (1);
}

int				optim2(char **command)
{
	if (ft_strstr(*command, "pb\nrra\npa\n") != NULL)
		replace_opr(command, "pb\nrra\npa\n", "rra\nsa\n");
	else if (ft_strstr(*command, "pb\nrb\nsb\nrrb\npa\n") != NULL)
		replace_opr(command, "pb\nrb\nsb\nrrb\npa\n", "sb\n");
	else if (ft_strstr(*command, "\nrra\nra\n") != NULL)
		replace_opr(command, "\nrra\nra\n", "\n");
	else if (ft_strstr(*command, "\nrrb\nrb\n") != NULL)
		replace_opr(command, "\nrrb\nrb\n", "\n");
	else if (ft_strstr(*command, "\npb\npa\n") != NULL)
		replace_opr(command, "\npb\npa\n", "\n");
	else if (ft_strstr(*command, "\npa\npb\n") != NULL)
		replace_opr(command, "\npa\npb\n", "\n");
	else if (ft_strstr(*command, "sb\nrb\nsb\nrrb\nsb\npa\npa\npa\n") != NULL)
		replace_opr(command, "sb\nrb\nsb\nrrb\nsb\npa\npa\npa\n",
					"sb\npa\nsb\npa\nsa\npa\n");
	else
		return (0);
	return (1);
}

void			optimization_opr(char **command)
{
	while (1)
	{
		if (optim1(command) == 0 && optim2(command) == 0)
			break ;
	}
}
