NAME = libft.a

HEADER = libft.h

SRC = ft_atoi.c \
    	ft_bzero.c \
        ft_calloc.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_memset.c \
		ft_strchr.c \
		ft_strdup.c \
		ft_strlcat.c \
		ft_strlcpy.c \
		ft_strlen.c \
		ft_strncmp.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_substr.c \
		ft_substr.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_split.c \
		ft_itoa.c \
		ft_strmapi.c \
		ft_striteri.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \

BONUS = ft_lstnew_bonus.c \
    	ft_lstadd_front_bonus.c \
        ft_lstsize_bonus.c \
		ft_lstlast_bonus.c \
		ft_lstadd_back_bonus.c \
		ft_lstdelone_bonus.c \
		ft_lstclear_bonus.c \
		ft_lstiter_bonus.c \
		ft_lstmap_bonus.c \

SRCALL = $(SRC) $(BONUS)

OBJ = $(SRC:.c=.o)

OBJALL = $(SRCALL:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

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
	$(CC) $(CFLAGS) -I . -c $< -o $@

$(NAME): $(OBJ) Makefile $(HEADER)
	ar -rcs $(NAME) $(OBJ)

bonus: 
	@make OBJ="$(OBJALL)"

clean: 
	rm -rf *.o

fclean:
	$(MAKE) clean
	rm -rf libft.a

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all clean fclean re


