NAME	= mysh

CC	= gcc

LIB	= -lmy -Llib/my/

RM	= rm -f

CFLAGS += -Iinclude -W -Wall -Wextra -ansi -pedantic

LDFLAGS =

SRCS	= main.c \
	  init.c \
	  utils.c \
	  built_in.c \
	  my_cd.c \
	  search.c \
	  setenv.c \
	  unsetenv.c \
	  realloc.c \
	  prompt.c \
	  new_epur_str.c \
	  divide.c \
	  pipe.c \
	  my_str_to_tab.c

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
