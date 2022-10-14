NAME	= philo
SRCS	= $(shell find "." -name "*.c")
OBJS	= $(SRCS:.c=.o)
CC		= gcc
RM		= rm -f
FLAGS	= -Wall -Wextra -Werror -I.

.c.o : 
		$(CC) $(FLAGS) -c $< -o $(<:.c=.o)

all : $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) -o $(NAME) $(OBJS)

clean :
		$(RM) $(OBJS)

fclean : clean
		$(RM) $(NAME)

re : fclean all 

.PHONY: all clean fclean re