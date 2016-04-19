NAME	= client/client

NAME1	= server/server

CC	= gcc

LIB	= -lmy -Llib/my/

RM	= rm -f

CFLAGS += -Iinclude -Wextra -Wall

LDFLAGS =

SRCS	= client/main.c

SRCS1	= server/main.c

OBJS	= $(SRCS:.c=.o)

OBJS1	= $(SRCS1:.c=.o)

all: $(NAME) $(NAME1)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(LIB) $(LDFLAGS)

$(NAME1): $(OBJS1)
	$(CC) $(OBJS1) -o $(NAME1) $(LIB) $(LDFLAGS)

addlib:
	mkdir include
	mkdir lib
	mkdir lib/my
	cp /home/maison_m/lib/my/libmy.a lib/my/
	cp /home/maison_m/lib/my/my.h include/

clean:
	@$(RM) $(OBJS) $(OBJS1)

fclean: clean
	@$(RM) $(NAME) $(NAME1)

re: fclean all

.PHONY: all clean fclean re
