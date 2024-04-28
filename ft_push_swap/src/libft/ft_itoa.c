/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelissao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 17:58:40 by aelissao          #+#    #+#             */
/*   Updated: 2021/12/01 16:32:09 by aelissao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_postive(int n, char *res, char len)
{
	while (len > 0)
	{
		res[len - 1] = (n % 10) + 48;
		n /= 10;
		len--;
	}
	return (res);
}

char	*ft_negative(int n, int len, char *res)
{
	if (n == 0)
		res[0] = '0';
	else
	{
		n *= -1;
		res[0] = '-';
		while (len > 1)
		{
			res[len - 1] = (n % 10) + 48;
			n /= 10;
			len--;
		}
	}
	return (res);
}

int	ft_len(int n)
{
	int	i;

	i = 0;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*res;
	int		len;

	len = ft_len(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		len = 1;
	if (n < 0)
		len += 1;
	res = (char *)malloc((len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	res[len] = '\0';
	if (n < 0 || n == 0)
		ft_negative(n, len, res);
	else
	{
		ft_postive(n, res, len);
	}
	return (res);
}
