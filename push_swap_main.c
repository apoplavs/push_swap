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

int			    main(int argc,  char **argv)
{
	t_stacks *stack;

	if (argc < 2)
		return (1);
	stack = read_args(argc, argv);
	ft_sort_stack(stack, argc - 1);
	return (0);
}

