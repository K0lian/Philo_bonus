NAME =  philo_bonus
INCLUDE = philo.h
SRC =		fork.c \
			main.c \
			structs_setup.c \
			ft_atoi.c \
			utils.c 

OBJ_NAME	= $(SRC:.c=.o)
CC			= gcc -g -O2 -Wall -Wextra -Werror
RM	= rm -f
$(NAME):	$(OBJ_NAME) philo.h
			$(CC) -o $(NAME) $(OBJ_NAME)
all:		$(NAME)
clean:
			$(RM) $(OBJ_NAME)
fclean:		clean
			$(RM) ${NAME}
re:			fclean all