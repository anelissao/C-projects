/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelissao <aelissao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 20:17:19 by aelissao          #+#    #+#             */
/*   Updated: 2023/02/25 20:27:34 by aelissao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack)
{
	int	temp;

	if (stack->size > 1)
	{
		temp = stack->data[0];
		stack->data[0] = stack->data[1];
		stack->data[1] = temp;
	}
}

void	push_from_to(t_stack *stack_from, t_stack *stack_to)
{
	int	i;
	int	num_to_push;

	if (stack_from->size >= 1)
	{
		if (stack_to->size > 0)
		{
			i = stack_to->size;
			while (i > 0)
			{
				stack_to->data[i] = stack_to->data[i - 1];
				i--;
			}
		}
		num_to_push = stack_from->data[0];
		stack_to->data[0] = num_to_push;
		stack_to->size = stack_to->size + 1;
		i = 0;
		while (i < stack_from->size - 1)
		{
			stack_from->data[i] = stack_from->data[i + 1];
			i++;
		}
		stack_from->size = stack_from->size - 1;
	}
}

void	shift_up(t_stack *stack)
{
	int		i;
	int		first_num;

	i = 0;
	if (stack->size > 1)
	{
		first_num = stack->data[0];
		while (i < stack->size - 1)
		{
			stack->data[i] = stack->data[i + 1];
			i++;
		}
		stack->data[stack->size - 1] = first_num;
	}
}

void	shift_down(t_stack *stack)
{
	int		i;
	int		old_last_elem;

	i = stack->size - 1;
	if (stack->size > 1)
	{
		old_last_elem = stack->data[stack->size - 1];
		while (i > 0)
		{
			stack->data[i] = stack->data[i - 1];
			i--;
		}
		stack->data[0] = old_last_elem;
	}
}
