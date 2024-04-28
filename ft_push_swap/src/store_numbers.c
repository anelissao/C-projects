/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelissao <aelissao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 20:18:47 by aelissao          #+#    #+#             */
/*   Updated: 2023/02/25 22:41:05 by aelissao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_check_argument(char *argument)
{
	int	len;
	int	i;
	int	number_found;

	i = 0;
	number_found = 0;
	len = ft_strlen(argument);
	while (i < len)
	{
		if (ft_strchr("0123456789", argument[i]))
			number_found = 1;
		i++;
	}
	if (number_found == 0)
		exit_with_error();
}

char	**store_numbers(char **av, int ac)
{
	char	**numbers;
	char	*line;
	int		i;
	char	*temp;

	i = 1;
	line = ft_strdup("");
	while (i < ac)
	{
		temp = line;
		ft_check_argument(av[i]);
		line = ft_strjoin(line, av[i]);
		free(temp);
		temp = line;
		line = ft_strjoin(line, " ");
		free(temp);
		i++;
	}
	numbers = ft_split(line, ' ');
	free(line);
	return (numbers);
}

void	free_numbers(char **numbers)
{
	int	i;

	i = 0;
	while (numbers[i])
	{
		free(numbers[i]);
		i++;
	}
	free(numbers);
}
