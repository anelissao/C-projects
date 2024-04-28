/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelissao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 16:33:23 by aelissao          #+#    #+#             */
/*   Updated: 2021/12/01 16:33:25 by aelissao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	int		i;
	char	*mydst;
	char	*mysrc;

	if (dst == NULL && src == NULL)
		return (NULL);
	mydst = (char *)dst;
	mysrc = (char *)src;
	if (!n)
		return (dst);
	i = n - 1;
	if (mysrc > mydst)
		return (ft_memcpy(dst, src, n));
	while (i >= 0)
	{
		mydst[i] = mysrc[i];
		i--;
	}
	return (dst);
}
