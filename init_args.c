/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoplavs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 13:23:40 by apoplavs          #+#    #+#             */
/*   Updated: 2017/03/13 13:23:59 by apoplavs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stacks        *read_args(int ac, char **av)
{
	int			i;
	int			*mas;

	i = 0;
	check_args(ac, av);
	mas = malloc(sizeof(int) * ac);
	while (++i < ac)
		mas[i - 1] = ft_atoi(av[i]);
	check_duplicates(mas, ac - 1);
/*	ft_qsort(mas, 0, ac - 2);
	i = -1;
	while (++i < ac - 1)
		printf("%d ", mas[i]);*/
    return (ft_init_stack(mas, ac - 1));
}

t_stacks        *ft_init_stack(int *mas, int len)
{
    int         i;
    t_stacks	*stack;
    t_stacks	*p;
	t_stacks	*top;

    i = 0;
    stack = malloc(sizeof(*stack));
	top = stack;
	top->x = 0;
	stack = malloc(sizeof(*stack));
	stack->x = mas[0];
	top->next = stack;
    while (++i < len)
    {
        p = stack;
        stack = malloc(sizeof(*stack));
        p->next = stack;
        stack->x = mas[i];
    }
    stack->next = NULL;
	free(mas);
    return (top);
}

t_list          *read_instructions(int fd)
{
    t_list      *inst;
    t_list      *first;
    char        *str;
    t_list      *p;
	int         i;

    inst = ft_lstnew(NULL, 0);
    first = inst;
    p = inst;
    while (get_next_line(fd, &str))
    {
        check_instructions(str);
        inst = ft_lstnew(str, ft_strlen(str) + 1);
        p->next = inst;
        p = inst;
	    i = 0;
	    while (i < 100)
		    i++;
    }
	inst->next = NULL;
    return (first->next);
}