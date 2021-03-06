/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoplavs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 09:56:15 by apoplavs          #+#    #+#             */
/*   Updated: 2017/03/15 09:56:20 by apoplavs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				main(int argc, char **argv)
{
	t_stacks	*stack;
	t_flag		flag;

	if (argc < 2)
		return (1);
	stack = read_args(argc, argv, &flag);
	ft_sort_stack(stack);
	return (0);
}
