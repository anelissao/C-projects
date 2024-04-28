/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelissao <aelissao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 20:19:21 by aelissao          #+#    #+#             */
/*   Updated: 2023/02/25 20:19:23 by aelissao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_min_max_nums(int *items, int len, int *min, int *max)
{
	int	i;

	i = 0;
	*max = INT_MIN;
	*min = INT_MAX;
	while (i < len)
	{
		if (items[i] < *min)
			*min = items[i];
		if (items[i] > *max)
			*max = items[i];
		i++;
	}
}

int	locate_max_num(t_stack *stack)
{
	int	i;
	int	min;
	int	max;

	i = 0;
	min = 0;
	max = 0;
	get_min_max_nums(stack->data, stack->size, &min, &max);
	while (i < stack->size - 1)
	{
		if (stack->data[i] == max)
			break ;
		i++;
	}
	return (i);
}

int	locate_min_num(t_stack *stack)
{
	int	i;
	int	min;
	int	max;

	i = 0;
	min = 0;
	max = 0;
	get_min_max_nums(stack->data, stack->size, &min, &max);
	while (i < stack->size - 1)
	{
		if (stack->data[i] == min)
			break ;
		i++;
	}
	return (i);
}

void	start_stack_sorting(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size == 2)
		two_num_algo(stack_a);
	else if (stack_a->size == 3)
		three_num_algo(stack_a);
	else if (stack_a->size <= 5)
		five_num_algo(stack_a, stack_b);
	else
		long_inc_subseq_algo(stack_a, stack_b);
}
