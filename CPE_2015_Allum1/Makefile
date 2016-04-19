NAME	= allum1

CC	= gcc

LIB	= -lmy -Llib/my/

RM	= rm -f

CFLAGS += -Iinclude -Wextra -Wall -ansi -pedantic

LDFLAGS =

SRCS	= main.c \
	  functions.c \
	  init.c \
	  ai.c \
	  ai2.c \
	  analyse.c

OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(LIB) $(LDFLAGS)

addlib:
	mkdir include
	mkdir lib
	mkdir lib/my
	cp /home/maison_m/lib/my/libmy.a lib/my/
	cp /home/maison_m/lib/my/my.h include/

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
