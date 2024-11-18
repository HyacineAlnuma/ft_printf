# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: halnuma <halnuma@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/18 08:45:55 by halnuma           #+#    #+#              #
#    Updated: 2024/11/18 12:00:50 by halnuma          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re loading

# ------ COLORS ------

_END			= \033[0m
_GREY			= \033[0;30m
_RED			= \033[0;31m
_GREEN			= \033[0;32m
_YELLOW			= \033[0;33m
_BLUE			= \033[0;34m
_PURPLE			= \033[0;35m
_CYAN			= \033[0;36m

# ------ VARIABLES ------

NAME			= libftprintf.a
CC 				= cc
AR				= ar -rcs
CFLAGS 			= -Wall -Wextra -Werror

# ------ PATHS ------

P_OBJ 			= obj/
P_SRC 			= src/
P_INC			= includes/
P_LIB			= libft/

# ------ FILES ------

FILES			= ft_printf
SRC				= $(addprefix $(P_SRC), $(addsuffix .c, $(FILES)))
OBJ 			= $(addprefix $(P_OBJ), $(addsuffix .o, $(FILES)))

# ------ RULES ------

all: 			make_libft $(NAME)

$(NAME): 		$(OBJ) Makefile $(P_LIB)libft.a
				@$(AR) $(NAME) $(OBJ)
				@echo "$(_GREEN)ft_printf compiled!$(_END)"

$(P_OBJ):
				@mkdir -p $(P_OBJ)

$(P_OBJ)%.o:	$(P_SRC)%.c | $(P_OBJ) loading
				@$(CC) $(CFLAGS) -I $(P_INC) -c $< -o $@

loading:
				@echo "$(_YELLOW)Compiling ft_printf...$<$(_END)"

make_libft:
				@$(MAKE) -C $(P_LIB) bonus --no-print-directory

# ------ BASIC RULES ------

clean: 
				@rm -rf $(P_OBJ)
				@$(MAKE) -C $(P_LIB) clean --no-print-directory
				@echo "$(_CYAN)ft_printf cleaned!$(_END)"

fclean:
				@$(MAKE) clean --no-print-directory
				@$(MAKE) -C $(P_LIB) fclean --no-print-directory
				@rm -rf libftprintf.a 
				@echo "$(_CYAN)ft_printf full cleaned!$(_END)"

re:
				@$(MAKE) fclean --no-print-directory
				@$(MAKE) all --no-print-directory
				@echo "$(_CYAN)ft_printf rebuilt!$(_END)"
