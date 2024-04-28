/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelissao <aelissao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 19:12:14 by aelissao          #+#    #+#             */
/*   Updated: 2023/02/26 02:43:04 by aelissao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*gnl_str_join(char const *str1, char const *str2)
{
	char	*ret_code;
	size_t	stot_len;
	size_t	str1_len;
	size_t	str2_len;

	if (!str1 && !str2)
		return (0);
	str1_len = custom_strlen((char *)str1);
	str2_len = custom_strlen((char *)str2);
	stot_len = str1_len + str2_len + 1;
	ret_code = malloc(sizeof(char) * stot_len);
	if (!ret_code)
		return (0);
	ft_memmove(ret_code, str1, str1_len);
	ft_memmove(ret_code + str1_len, str2, str2_len);
	ret_code[stot_len - 1] = '\0';
	free((char *)str1);
	return (ret_code);
}

size_t	custom_strlen(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

int	got_new_line(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

// void	*ft_memmove(void *dst, const void *src, size_t len)
// {
// 	char	*d;
// 	char	*s;

// 	d = (char *)dst;
// 	s = (char *)src;
// 	if (dst == src)
// 		return (dst);
// 	if (s < d)
// 	{
// 		while (len--)
// 			*(d + len) = *(s + len);
// 		return (dst);
// 	}
// 	while (len--)
// 		*d++ = *s++;
// 	return (dst);
// }
