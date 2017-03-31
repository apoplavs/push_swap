/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoplavs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 09:58:43 by apoplavs          #+#    #+#             */
/*   Updated: 2017/03/15 09:59:45 by apoplavs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stdio.h"

void			ft_push_a_b(char *str, t_stacks *stack_a, t_stacks *stack_b)
{
	if (str[1] == 'a' && stack_b != NULL)
		ft_push(stack_b->next, stack_a->next, stack_b, stack_a);
	else if (str[1] == 'b')
		ft_push(stack_a->next, stack_b->next, stack_a, stack_b);
}

void			run_inst(char *str, t_stacks *stack)
{
	if (str[0] == 's')
		ft_swap_stack(stack->next);
	else if (str[0] == 'r' && str[1] == 'r')
		ft_rrotate(stack->next, stack);
	else if (str[0] == 'r')
		ft_rotate(stack->next, stack);
}

void			init_instruction(t_stacks *stack_a, t_stacks *stack_b,
	t_list *inst)
{
	if (ft_strcmp((char*)inst->content, "pa") == 0
		|| ft_strcmp((char*)inst->content, "pb") == 0)
		ft_push_a_b((char*)inst->content, stack_a, stack_b);
	else if (ft_strchr(inst->content, 'a'))
		run_inst((char*)inst->content, stack_a);
	else if (ft_strchr(inst->content, 'b'))
		run_inst((char*)inst->content, stack_b);
	else if (ft_strcmp((char*)inst->content, "ss") == 0
		 && ft_swap_stack(stack_a->next))
		ft_swap_stack(stack_b->next);
	else if (ft_strcmp((char*)inst->content, "rr") == 0
			 && ft_rotate(stack_a->next, stack_a))
		ft_rotate(stack_b->next, stack_b);
	else if (ft_strcmp((char*)inst->content, "rrr") == 0
			 && ft_rrotate(stack_a->next, stack_a))
		ft_rrotate(stack_b->next, stack_b);
}

int				ft_sort(t_stacks *stack_a, t_list *inst)
{
	t_stacks	*stack_b;
	int			f;
	t_list		*p;

	p = inst;
	if (inst == NULL)
		return (check_solve(stack_a, NULL));
	stack_b = malloc(sizeof(*stack_b));
	stack_b->next = NULL;
	while (inst != NULL)
	{
		init_instruction(stack_a, stack_b, inst);
		inst = inst->next;
	}
	if (check_solve(stack_a->next, stack_b->next) == 1)
		f = 1;
	else
		f = 0;
	del_stack(stack_a);
	del_stack(stack_b);
	del_inst(p);
	return (f);
}

int				main(int argc, char **argv)
{
	t_stacks	*stack;
	t_list		*instruction;

	if (argc < 2)
		return (1);
	stack = read_args(argc, argv);
	instruction = read_instructions(0);
	ft_putstr(ft_sort(stack, instruction) == 1 ? "OK\n" : "KO\n");
	//sleep(100);
/*
	printf("\nstack_a\n");
	while (stack->next)
	{
		stack = stack->next;
		printf("%d\n", stack->x);
	}*/
	return (0);
}