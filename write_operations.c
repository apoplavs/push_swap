//
// Created by Andriy Poplavskyi on 3/26/17.
//

#include "push_swap.h"

void            putlalala(char *lol)
{
	int     i;

	i = 0;
	while (lol[i])
	{
		if (lol[i] != '\n')
			ft_putchar(lol[i]);
		else
			ft_putchar(' ');
		i++;
	}
	ft_putchar('\n');
}

int					write_opr(char opr, char **command)
{
	char			*p;

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

void            replace_opr(char **command, char *opr, char *new_opr)
{
	char       *s;
	char       *p;
	char       *ps;
	int         i;
	char        *new_inst;
	int         len;

	i = 0;
	s = *command;
	ps = s;
	//printf("\nзайшли в функцію заміни\n");
	new_inst = ft_strnew(ft_strlen(*command));
	//printf("\nвиділили нову память\n");
	p = ft_strstr(s, opr);
	//printf("\nзнайшли початок операції\n");
	while (s != p)
	{
		//printf("\ns = %p     p = %p\n command = %s", s, p, *command);
		new_inst[i] = *s;
		i++;
		s++;
	}
	//printf("\nзаписали першу частину операцій\n");
	ft_strcat(new_inst, new_opr);
	len = ft_strlen(opr);
	while (len > 0)
	{
		s++;
		len--;
	}
	ft_strcat(new_inst, s);
	*command = new_inst;
	//printf("\n%s", *command);
		free(ps);
}



void            optimization_opr(char **command)
{
	while (1)
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

		else if (ft_strstr(*command, "pb\nrra\npa\n") != NULL)
			replace_opr(command, "pb\nrra\npa\n", "rra\nsa\n");
		else if (ft_strstr(*command, "ra\npb\nrra\n") != NULL)
			replace_opr(command, "ra\npb\nrra\n", "    |||||||||||||||||||sa\npb\n");

		else if (ft_strstr(*command, "\nrra\nra\n") != NULL)
			replace_opr(command, "\nrra\nra\n", "\n");
		else if (ft_strstr(*command, "\nrrb\nrb\n") != NULL)
			replace_opr(command, "\nrrb\nrb\n", "\n");

		else if (ft_strstr(*command, "\npb\npa\n") != NULL)
			replace_opr(command, "\npb\npa\n", "\n");
		else if (ft_strstr(*command, "\npa\npb\n") != NULL)
			replace_opr(command, "\npa\npb\n", "\n");

		else if (ft_strstr(*command, "sb\nrb\nsb\nrrb\nsb\npa\npa\npa\n") != NULL)
			replace_opr(command, "sb\nrb\nsb\nrrb\nsb\npa\npa\npa\n", "sb\npa\nsb\npa\nsa\npa\n");

		else if (ft_strstr(*command, "rb\nsb\nrrb\nsb\npa\npa\npa\n") != NULL)
			replace_opr(command, "rb\nsb\nrrb\nsb\npa\npa\npa\n", "pa\nsb\npa\nsa\npa\n");
		else
			break ;
	}

//	printf("\nперед пошуком оптимізації\n");



}


void          	cancel_opr(char opr, t_stacks *stack_a, t_stacks *stack_b, char *command)
{
	int			i;

	i = 0;
	if (opr == SA)
		ft_swap_stack(stack_a->next);
	else if (opr == SB)
		ft_swap_stack(stack_b->next);
	else if (opr == PA)
		ft_push(stack_a->next, stack_b->next, stack_a, stack_b);
	else if (opr == PB)
		ft_push(stack_b->next, stack_a->next, stack_b, stack_a);
	else if (opr == RA)
		ft_rrotate(stack_a->next, stack_a);
	else if (opr == RB)
		ft_rrotate(stack_b->next, stack_b);
	else if (opr == RRA)
		ft_rotate(stack_a->next, stack_a);
	else if (opr == RRB)
		ft_rotate(stack_b->next, stack_b);
	while (command[i + 1])
		i++;
	while (i > 0 && command[i - 1] != '\n')
		i--;
	command[i] = '\0';
	command[i + 1] = '\0';
}
