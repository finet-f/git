NAME	= libmy.a

RM	= rm -f

SRCS	= flag.c \
	  flag3.c \
	  flag2.c \
	  my_putchar.c \
	  my_putstr.c \
	  my_strlen.c \
	  my_put_nbr.c \
	  my_put_nbr_long.c \
	  my_printf2.c \
	  my_printf.c

OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
