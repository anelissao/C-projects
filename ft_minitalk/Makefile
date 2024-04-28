# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aelissao <aelissao@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/04 13:33:09 by aelissao          #+#    #+#              #
#    Updated: 2022/06/04 13:33:13 by aelissao         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

HEADER = minitalk.h

SERVER_SRCS = server.c srcs/ft_print.c srcs/ft_isdigit.c
CLIENT_SRCS = client.c srcs/ft_atoi.c srcs/ft_print.c srcs/ft_isdigit.c

SERVER_SRCS_BONUS = server_bonus.c srcs/ft_print.c srcs/ft_isdigit.c
CLIENT_SRCS_BONUS = client_bonus.c srcs/ft_atoi.c srcs/ft_print.c srcs/ft_isdigit.c

SERVER_OBJS = $(SERVER_SRCS:.c=.o)
CLIENT_OBJS = $(CLIENT_SRCS:.c=.o)

SERVER_OBJS_BONUS = $(SERVER_SRCS_BONUS:.c=.o)
CLIENT_OBJS_BONUS = $(CLIENT_SRCS_BONUS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf 

all: server client 

bonus: server_bonus client_bonus

client:$(CLIENT_OBJS)
	$(CC) $(CFLAGS) $(CLIENT_OBJS) -o client

server:$(SERVER_OBJS)
	$(CC) $(CFLAGS) $(SERVER_OBJS) -o server

client_bonus:$(CLIENT_OBJS_BONUS)
	$(CC) $(CFLAGS) $(CLIENT_OBJS_BONUS) -o client_bonus

server_bonus:$(SERVER_OBJS_BONUS)
	$(CC) $(CFLAGS) $(SERVER_OBJS_BONUS) -o server_bonus

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(SERVER_OBJS) $(CLIENT_OBJS) $(SERVER_OBJS_BONUS) $(CLIENT_OBJS_BONUS)

fclean:clean
	$(RM) client server client_bonus server_bonus 

re: fclean all

.PHONY: all client server_bonus client_bonus clean fclean re
