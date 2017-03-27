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
# define SS 9
# define RR 10
# define RRR 11

#include "get_next_line.h"
#include <stdio.h>

typedef struct		s_stacks
{
	int				x;
	struct s_stacks	*next;
}					t_stacks;

/* init_argc.c */
t_stacks        	*read_args(int ac, char **av);
t_stacks        	*ft_init_stack(int *mas, int len);
t_list              *read_instructions(int fd);

/* check_args.c */
void				ft_maxint(const char *str);
void				check_duplicates(int *a, int len);
void				check_args(int ac, char **av);
void				ft_error();
void                check_instructions(char *inst);

/* operations.c */
int                ft_swap_stack(t_stacks *stack);
int                ft_push(t_stacks *stack1, t_stacks *stack2, t_stacks *top_s1, t_stacks *top_s2);
int                ft_rotate(t_stacks *stack, t_stacks *top_s);
int                ft_rrotate(t_stacks *stack, t_stacks *top_s);
int                check_solve(t_stacks *stack_a, t_stacks *stack_b);

/* found_solution.c */
void                ft_sort_stack(t_stacks *stack_a, int len);
void                a_to_b(t_stacks *stack_a, t_stacks *stack_b, char **command, int len);
void                b_to_a(t_stacks *stack_a, t_stacks *stack_b, char **command, int len);

/* sorting.c */
void                ft_qsort(int a[], int less, int high);
int					write_opr(char opr, char **command);

/* support_sort.c */
t_stacks            *get_end(t_stacks *src, int len);
int					stack_len(t_stacks *stack);
int                 is_have_less(t_stacks *stack, t_stacks *end, int medium);
int					find_medium(t_stacks *stack, int i);
int                 is_have_over(t_stacks *stack, t_stacks *end, int medium);
int					find_medium_in_part(t_stacks *stack, int i, t_stacks *end);

/* write_operations.c */
int					write_opr(char opr, char **command);
void                optimization_opr(char **command);
void          	    cancel_opr(char opr, t_stacks *stack_a, t_stacks *stack_b, char *command);

/* separate_stacks.c */
int                 ft_separate_b(t_stacks *dst, t_stacks *src, char **command, int len);
int                 ft_separate_a(t_stacks *dst, t_stacks *src, char **command, int len);

#endif