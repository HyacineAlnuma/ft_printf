NAME = ft_printf.a

SRC = ft_printf.c 

OBJ = $(SRC:.c=.o)

OBJALL = $(SRCALL:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror

all: make_libft $(NAME)

#	%.o	= all what ends by ".o" 
#	$@	= the file name of the target of the rule
#	$<	= the name of the first prerequisite
#	$^	= is the name of all the prerequisites, with spaces between them
#	$?	= the name of all the prerequisites that are newer than the target, with spaces between them. 
#		  If the target does not exist, all prerequisites will be included
#
# Example :
#
#	hello: one two
#		@echo $@
#		@echo $<
#		@echo $?
#		@echo $^
#	->
#	hello
#	one
#	one two
#	one two

%.o : %.c Makefile $(HEADER)
	$(CC) $(CFLAGS) -I . -I ./libft -c $< -o $@

make_libft:
	$(MAKE) -C libft/

$(NAME): $(OBJ) Makefile ./libft/libft.a
	ar -rcs $(NAME) $(OBJ)

bonus: 
	@make OBJ="$(OBJALL)"

clean: 
	rm -rf *.o

fclean:
	$(MAKE) clean
	$(MAKE) -C libft/ fclean --no-print-directory
	rm -rf libft.a

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all clean fclean re


