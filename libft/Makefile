.PHONY: all clean fclean re loading

# ----- COLORS -----

_END			= \033[0m
_GREY			= \033[0;30m
_RED			= \033[0;31m
_GREEN			= \033[0;32m
_YELLOW			= \033[0;33m
_BLUE			= \033[0;34m
_PURPLE			= \033[0;35m
_CYAN			= \033[0;36m

# ----- VARIABLES -----

NAME			= libft.a
CC 				= cc
CFLAGS 			= -Wall -Wextra -Werror

# ----- PATHS -----

P_INC			= ../includes/

# ----- FILES -----

SRC 			= ft_atoi.c 			ft_bzero.c 					\
        		ft_calloc.c 			ft_isalnum.c 				\
				ft_isalpha.c 			ft_isascii.c 				\
				ft_isdigit.c 			ft_isprint.c 				\
				ft_memchr.c 			ft_memcmp.c 				\
				ft_memcpy.c 			ft_memmove.c 				\
				ft_memset.c 			ft_strchr.c 				\
				ft_strdup.c 			ft_strlcat.c 				\
				ft_strlcpy.c 			ft_strlen.c 				\
				ft_strncmp.c 			ft_strnstr.c 				\
				ft_strrchr.c 			ft_tolower.c 				\
				ft_toupper.c 			ft_substr.c 				\
				ft_substr.c 			ft_strjoin.c 				\
				ft_strtrim.c 			ft_split.c 					\
				ft_itoa.c 				ft_strmapi.c 				\
				ft_striteri.c 			ft_putchar_fd.c 			\
				ft_putstr_fd.c 			ft_putendl_fd.c 			\
				ft_putnbr_fd.c

BONUS 			= ft_lstnew_bonus.c 	ft_lstadd_front_bonus.c		\
				ft_lstsize_bonus.c 		ft_lstlast_bonus.c 			\
				ft_lstadd_back_bonus.c 	ft_lstdelone_bonus.c 		\
				ft_lstclear_bonus.c 	ft_lstiter_bonus.c 			\
				ft_lstmap_bonus.c 

SRCALL 			= $(SRC) $(BONUS)
OBJ 			= $(SRC:.c=.o)
OBJALL 			= $(SRCALL:.c=.o)
HEADER 			= $(P_INC)libft.h

# ----- RULES -----

all: 			$(NAME)

$(NAME): 		$(OBJ) Makefile $(HEADER)
				@ar -rcs $(NAME) $(OBJ)
				@echo "$(_GREEN)Libft compiled!$(_END)"

%.o : 			%.c Makefile $(HEADER) | loading
				@$(CC) $(CFLAGS) -I $(P_INC) -c $< -o $@

loading:
				@echo "$(_YELLOW)Compiling Libft...$(_END)"

bonus: 
				@make OBJ="$(OBJALL)"

# ----- BASIC RULES -----

clean: 
				@rm -rf *.o

fclean:
				@$(MAKE) clean
				@rm -rf libft.a


re:
				@$(MAKE) fclean
				@$(MAKE) all


