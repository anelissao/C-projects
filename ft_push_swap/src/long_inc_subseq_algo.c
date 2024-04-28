/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_inc_subseq_algo.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelissao <aelissao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 20:17:29 by aelissao          #+#    #+#             */
/*   Updated: 2023/02/25 20:28:55 by aelissao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_num_not_in_seq(int number, t_stack *longet_inc_sequence)
{
	int	i;
	int	*items;

	i = 0;
	items = longet_inc_sequence->data;
	while (i < longet_inc_sequence->size)
	{
		if (number == items[i])
			return (0);
		i++;
	}
	return (1);
}

void	push_none_lis_to_b(t_stack *stack_a, t_stack *stack_b,
		t_stack *longet_inc_sequence)
{
	int	i;
	int	first_num;

	i = 0;
	while (stack_a->size > longet_inc_sequence->size)
	{
		first_num = stack_a->data[0];
		if (is_num_not_in_seq(first_num, longet_inc_sequence))
		{
			ft_putstr_fd("pb\n", 1);
			push_from_to(stack_a, stack_b);
			i++;
		}
		else
		{
			ft_putstr_fd("ra\n", 1);
			shift_up(stack_a);
		}
	}
}

int	count_instru_in_stack_b(t_stack *stack_b, int lowest_instru_index)
{
	int	instru_count;
	int	sign;

	if (lowest_instru_index == stack_b->size)
		return (-1);
	sign = 1;
	if (lowest_instru_index < stack_b->size - lowest_instru_index)
		instru_count = lowest_instru_index;
	else
	{
		sign = -1;
		instru_count = (stack_b->size - lowest_instru_index);
	}
	return (sign * instru_count);
}

int	count_instru_in_stack_a(t_stack *stack_a, int best_number)
{
	int	half_stack;
	int	best_number_place;

	half_stack = (stack_a->size + 1) / 2;
	best_number_place = locate_pos_in_stack_a(stack_a, best_number);
	if (best_number_place == 0)
		return (0);
	if (best_number_place == stack_a->size)
		return (-1);
	else
	{
		if (half_stack < best_number_place)
			return ((stack_a->size - best_number_place) * -1);
		else
			return (best_number_place);
	}
}

void	long_inc_subseq_algo(t_stack *stack_a, t_stack *stack_b)
{
	t_stack		*long_inc_subseq;
	int			instru_count_a;
	int			instru_count_b;
	int			lowest_instru_index;

	long_inc_subseq = get_long_inc_subseq(stack_a);
	push_none_lis_to_b(stack_a, stack_b, long_inc_subseq);
	free(long_inc_subseq->data);
	free(long_inc_subseq);
	while (stack_b->size > 0)
	{
		lowest_instru_index = get_num_index_with_lowest_instru(stack_a,
				stack_b);
		instru_count_a = count_instru_in_stack_a(stack_a,
				stack_b->data[lowest_instru_index]);
		instru_count_b = count_instru_in_stack_b(stack_b,
				lowest_instru_index);
		shift_stacks_for_right_spot(stack_a, stack_b,
			instru_count_a, instru_count_b);
		ft_putstr_fd("pa\n", 1);
		push_from_to(stack_b, stack_a);
	}
	shift_stack_a_to_be_sorted(stack_a);
}
