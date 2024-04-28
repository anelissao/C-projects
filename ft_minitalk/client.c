/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelissao <aelissao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 13:33:42 by aelissao          #+#    #+#             */
/*   Updated: 2022/06/04 13:38:55 by aelissao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"minitalk.h"

void	send_char(char c, int pid)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		usleep(300);
		kill(pid, (c >> i & 1) + SIGUSR1);
		i--;
	}
}

int	main(int ac, char **av)
{
	int		pid;
	char	*s;
	int		i;

	i = 0;
	if (ac != 3)
	{
		write(2, "Invalid Arguments Please Enter Server ", 39);
		write(2, "Pid Followed By Message\n", 25);
		return (0);
	}
	else if (!(ft_isdigit(av[1])))
	{
		write(2, "Invalid Pid You Must Use Number\n", 33);
		return (0);
	}
	pid = ft_atoi(av[1]);
	if (pid <= 0)
		return (write(2, "error\n", 8), 0);
	s = av[2];
	while (s[i])
	{
		send_char(s[i], pid);
		i++;
	}
}
