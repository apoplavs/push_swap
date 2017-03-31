#******************************************************************************#                                                                
#                                                                              #                                                                
#                                                         :::      ::::::::    #                                                                
#    Makefile                                           :+:      :+:    :+:    #                                                                
#                                                     +:+ +:+         +:+      #                                                                
#    By: apoplavs <marvin@42.fr>                    +#+  +:+       +#+         #                                                                
#                                                 +#+#+#+#+#+   +#+            #                                                                
#    Created: 2017/03/01 13:38:47 by apoplavs          #+#    #+#              #                                                                
#    Updated: 2017/03/20 15:59:49 by apoplavs         ###   ########.fr        #
#                                                                              #                                                                
#******************************************************************************#                                                                

NAME1 = push_swap

NAME2 = checker

CC = gcc

LIBFT = libft/libft.a

SRC = check_args.c init_args.c get_next_line.c operations.c found_solution.c\
sorting.c support_sort.c write_operations.c separate_a.c separate_b.c

OBJ = $(SRC:.c=.o)

HEADERS = libft/libft.h push_swap.h get_next_line.h

FLAGS = -Wall -Wextra -Werror

all: $(NAME1) $(NAME2)

$(NAME1): push_swap_main.o $(OBJ) $(LIBFT)
	$(CC) -o $(NAME1) $(OBJ) push_swap_main.o $(LIBFT)

$(NAME2): checker_main.o $(OBJ) $(LIBFT)
	$(CC) -o $(NAME2) $(OBJ) checker_main.o $(LIBFT)

push_swap_main.o: push_swap_main.c
	$(CC) -c $(FLAGS) push_swap_main.c

checker_main.o: checker_main.c
	$(CC) -c $(FLAGS) checker_main.c

$(OBJ): %.o: %.c
	$(CC) -c $(FLAGS) $< -o $@

$(LIBFT):
	make -C libft/

libft_clean:
	make -C libft/ clean

libft_fclean:
	make -C libft/ fclean

clean: libft_clean
	rm -f $(OBJ) push_swap.h.gch push_swap_main.o checker_main.o get_next_line.h.gch *~

fclean: clean libft_fclean
	rm -f $(NAME1) $(NAME2)

re: fclean all
