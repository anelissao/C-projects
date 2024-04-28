/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelissao <aelissao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 18:11:16 by aelissao          #+#    #+#             */
/*   Updated: 2023/02/26 02:43:38 by aelissao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include "libft/libft.h"

# define BUFFER_SIZE 100
# define ERROR -1

int		get_next_line(int fd, char **line);
int		got_new_line(char *str);
char	*gnl_str_join(const char *str1, const char *str2);
size_t	custom_strlen(const char *s);

#endif