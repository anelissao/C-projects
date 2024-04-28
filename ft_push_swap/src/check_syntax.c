/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelissao <aelissao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 20:16:43 by aelissao          #+#    #+#             */
/*   Updated: 2023/02/25 20:16:45 by aelissao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_syntax(char *num)
{
	int	i;

	i = 0;
	if (num[0] == '-' && num[1] != '\0')
		i = 1;
	if (num[0] == '+' && num[1] != '\0')
		i = 1;
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
			exit_with_error();
		i++;
	}
	check_int_range(num);
	return (0);
}

int	check_numbers(char **numbers)
{
	int	i;

	i = 0;
	while (numbers[i])
	{
		check_syntax(numbers[i]);
		i++;
	}
	check_if_repeated(numbers);
	return (1);
}

int	is_stack_not_sorted(t_stack stack)
{
	int	i;

	i = 0;
	while (i < stack.size - 1)
	{
		if (stack.data[i] > stack.data[i + 1])
			return (1);
		i++;
	}
	return (0);
}
