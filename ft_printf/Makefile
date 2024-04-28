NAME = libftprintf.a

SRC = ft_print_hex.c ft_print_string.c ft_print_u.c ft_printf.c ft_putchar_count.c ft_putnbr.c\


HEADER = ft_printf.h

OBJ = $(SRC:.c=.o)

CC = gcc

FLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJ)
	ar rc $@ $^

%.o : %.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@ 
	
clean :
	rm -f $(OBJ)

fclean :  clean
	rm -rf $(NAME)

re : fclean all
