/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_best_item.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelissao <aelissao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 20:16:50 by aelissao          #+#    #+#             */
/*   Updated: 2023/02/25 20:22:16 by aelissao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_total_instru(t_stack *stack_a, t_stack *stack_b, int idx_in_a,
		int idx_in_b)
{
	int	total_instru;

	if (idx_in_a < stack_a->size - idx_in_a)
		total_instru = idx_in_a;
	else
		total_instru = stack_a->size - idx_in_a;
	if (idx_in_b < stack_b->size - idx_in_b)
		total_instru = total_instru + idx_in_b;
	else
		total_instru = total_instru + stack_b->size - idx_in_b ;
	return (total_instru);
}

int	rest_of_locate_pos(t_stack *stack_a, int number, int last_index)
{
	int	min_num_index;
	int	max_num_index;
	int	*elements;

	elements = stack_a->data;
	min_num_index = locate_min_num(stack_a);
	max_num_index = locate_max_num(stack_a);
	if (number > elements[max_num_index])
	{
		if (max_num_index + 1 > last_index)
			return (0);
		else
			return (max_num_index + 1);
	}
	if (number < elements[min_num_index])
		return (min_num_index);
	return (0);
}

int	locate_pos_in_stack_a(t_stack *stack_a, int number)
{
	int	i;
	int	*elements;
	int	last_index;

	i = 0;
	elements = stack_a->data;
	last_index = stack_a->size - 1;
	while (i < last_index)
	{
		if ((number > elements[i] && number < elements[i + 1]))
			return (i + 1);
		i++;
	}
	if (elements[last_index] < number && number < elements[0])
		return (0);
	return (rest_of_locate_pos(stack_a, number, last_index));
}

int	get_num_index_with_lowest_instru(t_stack *stack_a, t_stack *stack_b)
{
	int			i;
	int			pos_in_stack_a;
	int			lowest_instru_index;
	int			instru_count;
	t_stack		instru_counts;

	i = 0;
	instru_counts.size = 0;
	instru_counts.data = malloc(sizeof(int) * stack_b->size);
	while (i < stack_b->size)
	{
		pos_in_stack_a = locate_pos_in_stack_a(stack_a, stack_b->data[i]);
		instru_count = count_total_instru(stack_a, stack_b, pos_in_stack_a, i);
		instru_counts.data[i] = instru_count;
		instru_counts.size = instru_counts.size + 1;
		i++;
	}
	lowest_instru_index = locate_min_num(&instru_counts);
	free(instru_counts.data);
	return (lowest_instru_index);
}
