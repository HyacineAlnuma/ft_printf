# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: halnuma <halnuma@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/18 08:45:55 by halnuma           #+#    #+#              #
#    Updated: 2024/11/25 09:23:38 by halnuma          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re libft

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
CC				= cc
AR				= ar -rcs
CFLAGS			= -Wall -Wextra -Werror

# ------ PATHS ------

P_OBJ 			= obj/
P_SRC 			= src/
P_UTILS			= $(P_SRC)utils/
P_INC			= includes/
P_LIB			= libft/

# ------ FILES ------

MAIN			= ft_printf	

UTILS			= ft_printchar				ft_printstr			\
				ft_printnbr					ft_printptr			\
				ft_printhex		

SRC_MAIN		= $(addprefix $(P_SRC), $(addsuffix .c, $(MAIN)))
OBJ_MAIN 		= $(addprefix $(P_OBJ), $(addsuffix .o, $(MAIN)))
SRC_UTILS		= $(addprefix $(P_UTILS), $(addsuffix .c, $(UTILS)))
OBJ_UTILS 		= $(addprefix $(P_OBJ), $(addsuffix .o, $(UTILS)))

SRC_ALL			= $(SRC_MAIN) $(SRC_UTILS)
OBJ_ALL 		= $(OBJ_MAIN) $(OBJ_UTILS)
LIBFT			= $(P_LIB)libft.a
HEADERS			= $(P_INC)libft.h 			$(P_INC)ft_printf.h

# ------ RULES ------

all: 			libft $(NAME)

$(NAME): 		$(OBJ_ALL) Makefile $(P_INC)
				@cp $(LIBFT) $(NAME)
				@$(AR) $(NAME) $(OBJ_ALL)
				@echo "$(_GREEN)ft_printf compiled!$(_END)"

$(P_OBJ):
				@mkdir -p $(P_OBJ)

$(P_OBJ)%.o:	$(P_SRC)%.c Makefile $(HEADERS) | $(P_OBJ)
				@echo "$(_YELLOW)Compiling $<$(_END)"
				@$(CC) $(CFLAGS) -I $(P_INC) -c $< -o $@

$(P_OBJ)%.o:	$(P_UTILS)%.c Makefile $(HEADERS) | $(P_OBJ)
				@echo "$(_YELLOW)Compiling $<$(_END)"
				@$(CC) $(CFLAGS) -I $(P_INC) -c $< -o $@

libft:		
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
