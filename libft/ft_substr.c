/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelissao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 16:39:20 by aelissao          #+#    #+#             */
/*   Updated: 2021/12/01 16:39:22 by aelissao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t		j;
	char		*ptr;

	j = 0;
	if (!s)
		return (NULL);
	if (len >= ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	if (start > ft_strlen(s))
		len = 0;
	ptr = (char *) malloc(len + 1);
	if (ptr == NULL)
		return (NULL);
	if (start >= ft_strlen(s))
		len = 0;
	while (j < len)
	{
		ptr[j] = (char)s[start];
		start++;
		j++;
	}
	ptr[j] = '\0';
	return (ptr);
}
