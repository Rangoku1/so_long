NAME = so_long

LIBFT = libft/libft.a
CC = cc
FLAGS = -Wall -Wextra -Werror

RM = rm -rf

SRC = mapcheck.c so_long.c

all : $(LIBFT) 
	$(CC) $(FLAGS) $(SRC) $(LIBFT) -o $(NAME)

$(LIBFT) :
	make -C libft

clean :
	$(RM) $(NAME)
	make clean -C libft

re : clean all