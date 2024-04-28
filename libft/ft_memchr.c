/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelissao <aelissao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 19:33:16 by aelissao          #+#    #+#             */
/*   Updated: 2021/11/26 20:35:17 by aelissao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t		i;
	char		*ptr;
	char		n1;

	n1 = (char)c;
	ptr = (char *)str;
	i = 0;
	while (i < n)
	{
		if (ptr[i] == n1)
		{
			return ((char *)ptr + i);
		}
		i++;
	}
	return (NULL);
}
