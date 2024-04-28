/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_long_inc_subseq.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelissao <aelissao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 21:27:12 by aelissao          #+#    #+#             */
/*   Updated: 2023/02/25 21:27:14 by aelissao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*get_lis_indexes_values(int *elems, int elems_len, int *max)
{
	int	*lis_indexes;
	int	i;
	int	j;

	lis_indexes = (int *)malloc(sizeof(int) * elems_len);
	lis_indexes[0] = 1;
	i = 1;
	*max = 0;
	while (i < elems_len)
	{
		lis_indexes[i] = 1;
		j = 0;
		while (j < i)
		{
			if (elems[i] > elems[j] && lis_indexes[i] < lis_indexes[j] + 1)
			{
				lis_indexes[i] = lis_indexes[j] + 1;
				if (lis_indexes[i] > *max)
					*max = lis_indexes[i];
			}
			j++;
		}
		i++;
	}
	return (lis_indexes);
}

t_stack	*start_long_inc_subseq_algo(t_stack temp_stack)
{
	int			i;
	int			j;
	int			max;
	t_stack		*long_inc_subseq;
	int			*lis_indexes;

	lis_indexes = get_lis_indexes_values(temp_stack.data,
			temp_stack.size, &max);
	long_inc_subseq = (t_stack *)malloc(sizeof(t_stack));
	long_inc_subseq->data = malloc(sizeof(int) * temp_stack.size);
	long_inc_subseq->size = 0;
	i = temp_stack.size - 1;
	j = 0;
	while (i >= 0)
	{
		if (lis_indexes[i] == max)
		{
			long_inc_subseq->data[j++] = temp_stack.data[i];
			long_inc_subseq->size = long_inc_subseq->size + 1;
			max--;
		}
		i--;
	}
	free(lis_indexes);
	return (long_inc_subseq);
}

void	shift_min_num_to_top(t_stack *stack)
{
	int	min_index;

	min_index = locate_min_num(stack);
	if (min_index > ((stack->size - 1) / 2))
	{
		while (min_index < stack->size)
		{
			shift_down(stack);
			min_index++;
		}
	}
	else
	{
		while (min_index > 0)
		{
			shift_up(stack);
			min_index--;
		}
	}
}

t_stack	*get_long_inc_subseq(t_stack *stack_a)
{
	t_stack		*long_inc_subseq;
	t_stack		temp_stack;
	int			i;

	i = 0;
	temp_stack.data = malloc(sizeof(int) * stack_a->size);
	while (i < stack_a->size)
	{
		temp_stack.data[i] = stack_a->data[i];
		i++;
	}
	temp_stack.size = i;
	shift_min_num_to_top(&temp_stack);
	long_inc_subseq = start_long_inc_subseq_algo(temp_stack);
	free(temp_stack.data);
	return (long_inc_subseq);
}
