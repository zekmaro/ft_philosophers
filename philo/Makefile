NAME	:= philo
CC		:= cc
CFLAGS	:= -Wextra -Wall #-fsanitize=thread -g

OBJDIR	:= obj

SRC		:=	forks.c \
			ft_atoi.c	\
			ft_calloc.c \
			ft_itoa.c	\
			ft_memcpy.c	\
			ft_memset.c \
			ft_strlen.c \
			ft_strncmp.c \
			initialisation_and_parsing.c \
			main_functionality.c \
			monitoring.c \
			philo_actions.c \
			philo.c	\
			printing.c \
			protections.c \
			save_get_and_set.c \
			simulation.c \
			utils.c

OBJ		:= $(SRC:%.c=$(OBJDIR)/%.o)
LIBS	:= ft_printf/libftprintf.a 

$(shell mkdir -p $(OBJDIR))

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

$(OBJDIR)/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY	: all clean fclean re