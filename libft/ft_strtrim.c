/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelissao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 16:39:07 by aelissao          #+#    #+#             */
/*   Updated: 2021/12/01 16:39:08 by aelissao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	check(char const *set, char c)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
		{
			return (1);
		}
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	char	*tab;
	int		j;
	int		n;

	i = 0;
	n = 0;
	if (!set)
		ft_strdup(s1);
	if (!s1)
		return (NULL);
	j = ft_strlen(s1) - 1;
	while (check(set, s1[i]) == 1)
		i++;
	while (check(set, s1[j]) == 1 && i < j)
		j--;
	tab = malloc (sizeof(char) * (j - i) + 2);
	if (s1[i] == '\0' || set[n] == '\0')
		tab[n] = '\0';
	if (tab == NULL)
		return (NULL);
	while (i <= j)
		tab[n++] = s1[i++];
	tab[n] = '\0';
	return (tab);
}
