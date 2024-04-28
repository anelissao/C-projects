/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_num_algo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelissao <aelissao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 21:21:51 by aelissao          #+#    #+#             */
/*   Updated: 2023/02/25 21:36:03 by aelissao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rest_of_three_algo(int *elements, t_stack *stack_a)
{
	if (elements[1] > elements[2] && elements[0] < elements[2])
	{
		ft_putstr_fd("sa\n", 1);
		swap(stack_a);
		ft_putstr_fd("ra\n", 1);
		shift_up(stack_a);
	}
	else if (elements[0] < elements[1] && elements[0] > elements[2])
	{
		ft_putstr_fd("rra\n", 1);
		shift_down(stack_a);
	}
}

void	three_num_algo(t_stack *stack_a)
{
	int	*elements;

	elements = stack_a->data;
	if (elements[0] > elements[1] && elements[0] < elements[2])
	{
		ft_putstr_fd("sa\n", 1);
		swap(stack_a);
	}
	else if (elements[0] > elements[1] && elements[1] > elements[2])
	{
		ft_putstr_fd("sa\n", 1);
		ft_putstr_fd("rra\n", 1);
		swap(stack_a);
		shift_down(stack_a);
	}
	else if (elements[0] > elements[1] && elements[1] < elements[2])
	{
		ft_putstr_fd("ra\n", 1);
		shift_up(stack_a);
	}
	else
		rest_of_three_algo(elements, stack_a);
}
