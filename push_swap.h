/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoplavs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 13:02:19 by apoplavs          #+#    #+#             */
/*   Updated: 2017/03/13 13:02:20 by apoplavs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define SA 1
# define SB 2
# define PA 3
# define PB 4
# define RA 5
# define RB 6
# define RRA 7
# define RRB 8

# include "get_next_line.h"

typedef struct		s_stacks
{
	int				x;
	struct s_stacks	*next;
}					t_stacks;

typedef struct		s_flag
{
	int color		: 1;
	int count_opr	: 1;
	int s_status	: 1;
	int time_step	: 1;
	int fail_opr	: 1;
}					t_flag;

/*
** init_args.c
*/
void				del_inst(t_list *inst);
void				del_stack(t_stacks *stack);
t_stacks			*read_args(int ac, char **av, t_flag *flag);
t_stacks			*ft_init_stack(int *mas, int len);
t_list				*read_instructions(int fd);

/*
** check_args.c
*/
void				ft_maxint(const char *str);
void				check_duplicates(int *a, int len);
void				check_args(int ac, char **av, int i);
void				ft_error();
void				check_instructions(char *inst);

/*
** operations.c
*/
int					ft_swap_stack(t_stacks *stack);
int					ft_push(t_stacks *stack1, t_stacks *stack2,
	t_stacks *top_s1, t_stacks *top_s2);
int					ft_rotate(t_stacks *stack, t_stacks *top_s);
int					ft_rrotate(t_stacks *stack, t_stacks *top_s);
int					check_solve(t_stacks *stack_a, t_stacks *stack_b);

/*
** found_solution.c
*/
void				ft_sort_stack(t_stacks *stack_a);
void				a_to_b(t_stacks *stack_a, t_stacks *stack_b,
	char **command, int len);
void				b_to_a(t_stacks *stack_a, t_stacks *stack_b,
	char **command, int len);

/*
** sorting.c
*/
void				ft_qsort(int a[], int less, int high);
int					write_opr(char opr, char **command);
void				ft_sort_top(t_stacks *stack_a, t_stacks *stack_b,
	char **command);

/*
** support_sort.c
*/
t_stacks			*get_end(t_stacks *src, int len);
int					is_have_less(t_stacks *stack, t_stacks *end, int medium);
int					find_medium(t_stacks *stack, int i);
int					is_have_over(t_stacks *stack, t_stacks *end, int medium);
int					find_medium_in_part(t_stacks *stack, int i, t_stacks *end);

/*
** write_operations.c
*/
int					write_opr(char opr, char **command);
void				optimization_opr(char **command);

/*
** separate_stack_a.c
*/
int					ft_separate_a(t_stacks *dst, t_stacks *src,
	char **command, int len);
void				cancel_opr(char opr, t_stacks *stack_a, char *command);
int					stack_len(t_stacks *stack);

/*
** separate_stack_b.c
*/
void				rt_rrt(t_stacks *stack, char **command, char opr,
	int (*f)(t_stacks*, t_stacks*));
int					ft_separate_b(t_stacks *dst, t_stacks *src,
	char **command, int len);

/*
** flags.c
*/
int					init_flag(int ac, char **av, t_flag *flag);
void				print_result(char *str, t_flag *flag);
void				print_stacks(t_stacks *stack_a, t_stacks *stack_b);

#endif
