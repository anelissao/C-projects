# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aelissao <aelissao@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/25 20:19:57 by aelissao          #+#    #+#              #
#    Updated: 2023/02/26 00:20:32 by aelissao         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_DIR = ./src
NAME = push_swap
CHECKER = checker
OBJ_DIR = ./obj


CC = gcc
CFLAGS = -Wall -Werror -Wextra
LIBFF_DIR = ./src/libft

SRC_NAME = check_syntax.c\
	check_errors.c\
	push_swap.c\
	instructions.c\
	start_stack_sorting.c\
	store_numbers.c\
	fill_stack_with_numbers.c\
	instructions_for_both_stacks.c\
	long_inc_subseq_algo.c\
	shift_stacks_for_right_spot.c\
	get_num_index_with_lowest_instru.c\
	calc_table_len.c \
	get_long_inc_subseq.c \
	two_num_algo.c \
	three_num_algo.c \
	five_num_algo.c\
	stack_init.c

CHECKER_SRC = checker.c\
	store_numbers.c\
	check_syntax.c\
	check_errors.c\
	fill_stack_with_numbers.c\
	get_next_line.c\
	calc_table_len.c \
	instructions.c\
	instructions_for_both_stacks.c\
	get_next_line_utils.c\
	stack_init.c

OBJ_NAME = $(SRC_NAME:.c=.o)
HEDAERS = src/push_swap.h
CHECKER_HEADER =  src/checker.h
CHECKER_OBJ = $(CHECKER_SRC:.c=.o)
OBJ1 = $(addprefix $(OBJ_DIR)/,$(CHECKER_OBJ)) 
OBJ = $(addprefix $(OBJ_DIR)/,$(OBJ_NAME))
all: $(NAME)

$(NAME): $(OBJ)
	make -C src/libft
	$(CC) $(OBJ) $(LIBFF_DIR)/libft.a -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEDAERS)
	@mkdir obj 2> /dev/null || true
	$(CC) $(CFLAGS) -c $< -o $@

bonus:  $(CHECKER)

$(CHECKER): $(OBJ1)
	make -C src/libft
	$(CC) $(OBJ1) $(LIBFF_DIR)/libft.a -o $@

clean:
	rm -rf $(OBJ_DIR)/*.o
	rm -rf $(OBJ_DIR)
	rm -rf src/libft/*.o

fclean: clean
	rm -rf $(NAME)
	rm -rf src/libft/libft.a
	rm -rf checker

re: fclean all