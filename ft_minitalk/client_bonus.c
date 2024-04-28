/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelissao <aelissao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 13:33:35 by aelissao          #+#    #+#             */
/*   Updated: 2022/06/04 13:35:19 by aelissao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"minitalk.h"

void	send_char(char c, int pid)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		kill(pid, (c >> i & 1) + SIGUSR1);
		usleep(500);
		i--;
	}
}

void	handler(int sig)
{
	(void)sig;
	write(1, "Server: successfully recieved\n", 31);
	exit(0);
}

int	main(int ac, char **av)
{
	int		pid;
	char	*s;
	int		i;

	i = 0;
	if (ac != 3)
	{
		write(1, "Invalid Arguments Please Enter ", 32);
		write(1, "Server Pid Followed By Message\n", 32);
		return (0);
	}
	else if (!(ft_isdigit(av[1])))
	{
		write(1, "Invalid Pid You Must Use Number\n", 33);
		return (0);
	}
	pid = ft_atoi(av[1]);
	s = av[2];
	signal(SIGUSR1, handler);
	while (s[i])
	{
		send_char(s[i], pid);
		i++;
	}
	send_char(0, pid);
}
