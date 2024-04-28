/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelissao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 16:36:52 by aelissao          #+#    #+#             */
/*   Updated: 2021/12/01 16:36:53 by aelissao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	l;
	size_t	i;
	size_t	s;
	size_t	r;

	i = 0;
	s = 0;
	r = 0;
	while (dst[i] != '\0')
		i++;
	l = dstsize - ft_strlen(dst) - 1;
	if (dstsize > ft_strlen(dst))
	{		
		while (src[s] != '\0' && l > 0)
		{
			dst[i++] = src[s++];
			l--;
		}
		while (src[s++] != '\0')
			r++;
		dst[i] = '\0';
		return (ft_strlen(dst) + r);
	}
	return (ft_strlen(src) + dstsize);
}
