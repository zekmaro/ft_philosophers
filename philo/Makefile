NAME	:= philo
CC		:= cc
CFLAGS	:= -Wextra -Wall -fsanitize=thread -g
SRC		:=	ft_memset.c \
			ft_atoi.c	\
			ft_itoa.c	\
			ft_memcpy.c	\
			ft_strlen.c \
			ft_strncmp.c \
			philo.c
OBJ		:= $(SRC:.c=.o)
LIBS	:= ft_printf/libftprintf.a 

all:	$(NAME)

$(NAME): $(OBJ) philo.h
	make -C ft_printf all
	$(CC) $(OBJ) $(CFLAGS) $(LIBS) -o $(NAME)

clean:
	make -C ft_printf clean
	rm -f $(OBJ)

fclean:
	make -C ft_printf fclean
	rm -f $(OBJ) $(NAME)

re: fclean all

.PHONY	: all clean fclean re