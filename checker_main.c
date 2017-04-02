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

void			ft_push_a_b(char *str, t_stacks *stack_a,
							t_stacks *stack_b, int *f_count)
{
	if (str[1] == 'a' && stack_b != NULL)
		*f_count += ft_push(stack_b->next, stack_a->next, stack_b, stack_a);
	else if (str[1] == 'b')
		*f_count += ft_push(stack_a->next, stack_b->next, stack_a, stack_b);
}

void			run_inst(char *str, t_stacks *stack, int *f_count)
{
	if (str[0] == 's')
		*f_count += ft_swap_stack(stack->next);
	else if (str[0] == 'r' && str[1] == 'r')
		*f_count += ft_rrotate(stack->next, stack);
	else if (str[0] == 'r')
		*f_count += ft_rotate(stack->next, stack);
}

void			init_instruction(t_stacks *stack_a, t_stacks *stack_b,
	t_list *inst, int *f_count)
{
	if (ft_strcmp((char*)inst->content, "pa") == 0
		|| ft_strcmp((char*)inst->content, "pb") == 0)
		ft_push_a_b((char*)inst->content, stack_a, stack_b, f_count);
	else if (ft_strchr(inst->content, 'a'))
		run_inst((char*)inst->content, stack_a, f_count);
	else if (ft_strchr(inst->content, 'b'))
		run_inst((char*)inst->content, stack_b, f_count);
	else if (ft_strcmp((char*)inst->content, "ss") == 0
		&& ft_swap_stack(stack_a->next))
		*f_count += ft_swap_stack(stack_b->next);
	else if (ft_strcmp((char*)inst->content, "rr") == 0
			&& ft_rotate(stack_a->next, stack_a))
		*f_count += ft_rotate(stack_b->next, stack_b);
	else if (ft_strcmp((char*)inst->content, "rrr") == 0
			&& ft_rrotate(stack_a->next, stack_a))
		*f_count += ft_rrotate(stack_b->next, stack_b);
}

int				ft_sort(t_stacks *stack_a, t_list *inst,
	t_flag *flag, int *f_count)
{
	t_stacks	*stack_b;
	int			count;

	count = 0;
	if (inst == NULL)
		return (check_solve(stack_a, NULL));
	stack_b = malloc(sizeof(*stack_b));
	stack_b->next = NULL;
	while (inst != NULL)
	{
		init_instruction(stack_a, stack_b, inst, f_count);
		inst = inst->next;
		if (flag->s_status)
			print_stacks(stack_a, stack_b);
		if (flag->time_step)
			sleep(1);
		count++;
	}
	del_stack(stack_b);
	if (flag->count_opr)
		ft_printf("the total number of operations = %d\n", count);
	return (check_solve(stack_a->next, stack_b->next) == 1 ? 1 : 0);
}

int				main(int argc, char **argv)
{
	t_stacks	*stack;
	t_list		*instruction;
	t_flag		flag;
	int			f_count;

	if (argc < 2)
		return (1);
	f_count = 0;
	stack = read_args(argc, argv, &flag);
	instruction = read_instructions(0);
	print_result(ft_sort(stack, instruction, &flag, &f_count) == 1
		? "OK\n" : "KO\n", &flag);
	del_stack(stack);
	del_inst(instruction);
	if (flag.fail_opr)
		ft_printf("number of operations which were executed = %d\n", f_count);
	return (0);
}
