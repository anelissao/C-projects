/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelissao <aelissao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 18:11:00 by aelissao          #+#    #+#             */
/*   Updated: 2023/02/26 02:36:17 by aelissao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/libft.h"

int	free_and_return(char *str)
{
	free(str);
	return (-1);
}

char	*get_line(char *str)
{
	int		i;
	char	*rtn;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	rtn = malloc(sizeof(char) * (i + 1));
	if (!rtn)
		return (0);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		rtn[i] = str[i];
		i++;
	}
	rtn[i] = '\0';
	return (rtn);
}

char	*get_keep(char *keep)
{
	char	*rtn;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!keep)
		return (0);
	while (keep[i] && keep[i] != '\n')
		i++;
	if (!keep[i])
	{
		free(keep);
		return (0);
	}
	rtn = malloc(sizeof(char) * ((ft_strlen(keep) - i) + 1));
	if (!rtn)
		return (0);
	i++;
	while (keep[i])
		rtn[j++] = keep[i++];
	rtn[j] = '\0';
	free(keep);
	return (rtn);
}

int	get_next_line(int fd, char **line)
{
	static char		*keep;
	char			*buff;
	int				ret_code;

	ret_code = 1;
	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (-1);
	while (!got_new_line(keep) && ret_code != 0)
	{
		ret_code = read(fd, buff, BUFFER_SIZE);
		if (ret_code == -1)
			return (free_and_return(buff));
		buff[ret_code] = '\0';
		keep = gnl_str_join(keep, buff);
	}
	free(buff);
	*line = get_line(keep);
	keep = get_keep(keep);
	if (ret_code == 0)
		return (0);
	return (1);
}
