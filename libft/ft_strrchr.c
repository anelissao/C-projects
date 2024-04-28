/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelissao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 16:38:53 by aelissao          #+#    #+#             */
/*   Updated: 2021/12/01 16:38:54 by aelissao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int		i;
	char	n1;

	i = ft_strlen(str);
	n1 = (char)c;
	while (i != -1)
	{
		if (str[i] == n1)
		{
			return ((char *)str + i);
		}
		i--;
	}
	return (NULL);
}
