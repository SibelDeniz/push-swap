NAME	= push_swap

CC		= cc
CFLAGS	= -Wall -Wextra -Werror

SRCS	= main.c \
		  parse.c \
		  stack_utils.c \
		  indexing.c \
		  commandes.c \
		  commandes_extra.c \
		  greedy_cost.c \
		  lis_keep.c \
		  lis_greedy.c \
		  small_sort.c

OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
