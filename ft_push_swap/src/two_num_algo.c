/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two_num_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelissao <aelissao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 21:21:33 by aelissao          #+#    #+#             */
/*   Updated: 2023/02/25 21:21:35 by aelissao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	two_num_algo(t_stack *stack_a)
{
	int	*elements;

	elements = stack_a->data;
	if (elements[0] > elements[1])
	{
		ft_putstr_fd("sa\n", 1);
		swap(stack_a);
	}
}
