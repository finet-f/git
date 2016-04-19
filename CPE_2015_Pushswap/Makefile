NAME	= push_swap

CC	= gcc

LIB	= -lmy -Llib/my/

RM	= rm -f

CFLAGS += -Iinclude/
CFLAGS += -Wextra -Wall -Werror

LDFLAGS =

SRCS	= main.c \
	  main2.c \
	  check_error.c \
	  ra.c \
	  pa.c \
	  pb.c \
	  aff.c

OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(LIB) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
