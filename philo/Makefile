NAME	:= philo
CC		:= cc
CFLAGS	:= -Wextra -Wall -Wextra -g #-fsanitize=thread

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
			safe_get_and_set.c \
			simulation.c \
			utils.c

OBJ		:= $(SRC:%.c=$(OBJDIR)/%.o)

$(shell mkdir -p $(OBJDIR))

all:	$(NAME)

$(NAME): $(OBJ) philo.h
	$(CC) $(OBJ) $(CFLAGS) $(LIBS) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean:
	rm -f $(OBJ) $(NAME)

re: fclean all

$(OBJDIR)/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY	: all clean fclean re