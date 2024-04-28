/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_errors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelissao <aelissao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 20:17:02 by aelissao          #+#    #+#             */
/*   Updated: 2023/02/25 21:28:12 by aelissao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exit_with_error(void)
{
	ft_putstr_fd("Error\n", 1);
	exit(EXIT_FAILURE);
}

long int	convert_to_long_int(char *str)
{
	long int	number;
	int			i;
	int			sign;

	sign = 1;
	i = 0;
	number = 0;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		number = number * 10 + (str[i] - '0');
		i++;
	}
	return (sign * number);
}

void	check_int_range(char *num)
{
	long int	number;

	number = 0;
	number = convert_to_long_int(num);
	if (number < INT_MIN || number > INT_MAX)
		exit_with_error();
}

void	check_if_repeated(char **numbers)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (numbers[i])
	{
		j = 0;
		while (numbers[j])
		{
			if (i != j && (ft_atoi(numbers[i]) == ft_atoi(numbers[j])))
			{
				exit_with_error();
			}
			j++;
		}
		i++;
	}
}
