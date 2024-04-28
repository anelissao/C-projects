/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_data_to_stack.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelissao <aelissao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 20:18:52 by aelissao          #+#    #+#             */
/*   Updated: 2023/02/25 20:18:54 by aelissao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_stack_with_numbers(t_stack *stack_a, char **numbers)
{
	int	i;
	int	num;

	i = 0;
	while (numbers[i] != NULL)
	{
		num = ft_atoi(numbers[i]);
		stack_a->data[i] = num;
		i++;
	}
	stack_a->size = i;
}
