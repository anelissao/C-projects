/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelissao <aelissao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 20:19:10 by aelissao          #+#    #+#             */
/*   Updated: 2023/02/26 00:11:59 by aelissao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <limits.h>
# include "libft/libft.h"

typedef struct s_stack
{
	int	*data;
	int	size;
}				t_stack;

int			calc_table_len(char **arr);
void		free_numbers(char **data);
char		**store_numbers(char **argv, int argc);
int			is_stack_not_sorted(t_stack stack);
int			check_numbers(char **data);
void		check_int_range(char *data);
void		check_if_repeated(char **data);
void		exit_with_error(void);
void		push_swap(char **data);
void		swap(t_stack *stack);
void		push_from_to(t_stack *stack_from, t_stack *stack_to);
void		shift_up(t_stack *stack);
void		shift_down(t_stack *stack);
void		swap_both_stacks(t_stack *stack_a, t_stack *stack_b);
void		shift_up_both_stacks(t_stack *stack_a, t_stack *stack_b);
void		shift_down_both_stacks(t_stack *stack_a, t_stack *stack_b);
double		finding_the_median(t_stack *stack);
void		five_num_algo(t_stack *stack_a, t_stack *stack_b);
void		two_num_algo(t_stack *stack);
void		three_num_algo(t_stack *stack);
void		start_stack_sorting(t_stack *stack_a, t_stack *stack_b);
void		long_inc_subseq_algo(t_stack *stack_a, t_stack *stack_b);
int			locate_min_num(t_stack *stack);
int			locate_max_num(t_stack *stack);
void		get_min_max_nums(int *items, int len, int *min, int *max);
int			locate_pos_in_stack_a(t_stack *stack, int number);
t_stack		*get_long_inc_subseq(t_stack *stack_a);
int			get_num_index_with_lowest_instru(t_stack *stack_a,
				t_stack *stack_b);
void		shift_stack_a_to_be_sorted(t_stack *stack_a);
void		shift_stacks_for_right_spot(t_stack *stack_a, t_stack *stack_b,
				int move_a, int move_b);
void		fill_stack_with_numbers(t_stack *stack, char **data);
void		stack_init(t_stack *given_stack, int alloc_size);
int			get_next_line(int fd, char **line);
#endif