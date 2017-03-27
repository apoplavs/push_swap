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

void                ft_push_a_b(char *str, t_stacks *stack_a, t_stacks *stack_b)
{
	if (str[1] == 'a' && stack_b != NULL)
		ft_push(stack_b->next, stack_a->next, stack_b, stack_a);
	else if (str[1] == 'b')
	{
			ft_push(stack_a->next, stack_b->next, stack_a, stack_b);
	}
}

void            run_inst(char *str, t_stacks *stack)
{
	if (str[0] == 's')
		ft_swap_stack(stack->next);
	else if (str[0] == 'r' && str[1] == 'r')
		ft_rrotate(stack->next, stack);
	else if (str[0] == 'r')
		ft_rotate(stack->next, stack);
}

int             ft_sort(t_stacks *stack_a, t_list *inst)
{
	t_stacks    *stack_b;

	if (inst == NULL)
		return (check_solve(stack_a, NULL));
	stack_b = malloc(sizeof(*stack_b));
	stack_b->next = NULL;
	while (inst != NULL)
	{
		if (ft_strcmp((char*)inst->content, "pa") == 0 || ft_strcmp((char*)inst->content, "pb") == 0)
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
		inst = inst->next;
	}
	stack_a = stack_a->next;
	//printf("%d %d %d %d %d", stack_a->x, stack_a->next->x, stack_a->next->next->x, stack_a->next->next->next->x, stack_a->next->next->next->next->x);
	/* need free for top staks */
	return (check_solve(stack_a, stack_b->next));
}

int		        main(int argc, char **argv)
{
	t_stacks	*stack;
	t_list      *instruction;

	if (argc < 2)
		return (1);
	stack = read_args(argc, argv);
	//ft_putstr("Checked stack\n");
	instruction = read_instructions(0);
	//ft_putstr("Checked instructions\n");
	ft_putstr(ft_sort(stack, instruction) == 1 ? "OK\n" : "KO\n");
	printf("\nstack_a\n");
	while (stack->next)
	{
		stack = stack->next;
		printf("%d\n", stack->x);
	}
	return (0);
}