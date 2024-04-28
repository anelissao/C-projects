/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_num_algo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelissao <aelissao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 21:23:19 by aelissao          #+#    #+#             */
/*   Updated: 2023/02/25 21:23:21 by aelissao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_two_smallest_nums(t_stack *stack_a, t_stack *stack_b, int *mins)
{
	while (stack_a->size > 3)
	{
		if (mins[0] == stack_a->data[0] || mins[1] == stack_a->data[0])
		{
			ft_putstr_fd("pb\n", 1);
			push_from_to(stack_a, stack_b);
		}
		else
		{
			ft_putstr_fd("ra\n", 1);
			shift_up(stack_a);
		}
	}
}

void	push_two_min_num_to_b(t_stack *stack_a, t_stack *stack_b)
{
	t_stack		temp;
	int			smallest_num_indx;
	int			i;
	int			j;
	static int	smallest_nums_values[2];

	temp.data = malloc(sizeof(int) * stack_a->size);
	smallest_num_indx = locate_min_num(stack_a);
	smallest_nums_values[0] = stack_a->data[smallest_num_indx];
	i = 0;
	j = 0;
	while (i < stack_a->size)
	{
		if (smallest_num_indx != i)
		{
			temp.data[j] = stack_a->data[i];
			j++;
		}
		i++;
	}
	temp.size = j;
	smallest_num_indx = locate_min_num(&temp);
	smallest_nums_values[1] = temp.data[smallest_num_indx];
	free(temp.data);
	push_two_smallest_nums(stack_a, stack_b, smallest_nums_values);
}

void	push_min_num_to_b(t_stack *stack_a, t_stack *stack_b)
{
	int			i;
	int			smallest_num_indx;
	int			smallest_num_value;

	i = 0;
	smallest_num_indx = locate_min_num(stack_a);
	smallest_num_value = stack_a->data[smallest_num_indx];
	while (i < stack_a->size)
	{
		if (smallest_num_value == stack_a->data[0])
		{
			ft_putstr_fd("pb\n", 1);
			push_from_to(stack_a, stack_b);
			break ;
		}
		else
		{
			ft_putstr_fd("ra\n", 1);
			shift_up(stack_a);
		}
	}
}

void	push_smallest_nums(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size == 5)
		push_two_min_num_to_b(stack_a, stack_b);
	else if (stack_a->size == 4)
		push_min_num_to_b(stack_a, stack_b);
}

void	five_num_algo(t_stack *stack_a, t_stack *stack_b)
{
	int		*elements;

	push_smallest_nums(stack_a, stack_b);
	if (stack_b->size == 2)
	{
		elements = stack_b->data;
		if (elements[0] < elements[1])
		{
			ft_putstr_fd("sb\n", 1);
			swap(stack_b);
		}
	}
	three_num_algo(stack_a);
	ft_putstr_fd("pa\n", 1);
	push_from_to(stack_b, stack_a);
	if (stack_b->size == 1)
	{
		ft_putstr_fd("pa\n", 1);
		push_from_to(stack_b, stack_a);
	}
}
