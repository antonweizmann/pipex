# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: antonweizmann <antonweizmann@student.42    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/08 16:57:44 by aweizman          #+#    #+#              #
#    Updated: 2024/01/17 10:49:41 by antonweizma      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= pipex

LIBFT	= ./libft

CC		= cc

CFLAGS	= -Wall -Wextra -Werror

HEADERS = -I./pipex.h -I$(LIBFT)/include/ft_printf.h

SRCS	= main utils

OBJ_DIR		= obj/
SRC		= 	$(addsuffix .c, $(SRCS))
OBJ 	= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRCS)))
OBJ_CHECK		=	.cache_exists
all : $(NAME)

$(NAME): $(SRC) $(LIBFT)/libftprintf.a $(OBJ)
	@echo "compiling pipex.."
	@$(CC) $(CFLAGS) -o $(NAME) $(SRC) $(LIBFT)/libftprintf.a $(HEADERS)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJ_CHECK)
		@$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

$(LIBFT)/libftprintf.a:
	@make -C $(LIBFT)

$(OBJ_CHECK):
		@mkdir -p $(OBJ_DIR)
clean:
	@echo "cleaning up..."
	@rm -fr $(OBJ_DIR)
	@make clean -C $(LIBFT)

fclean: clean
	@echo "full cleaning up..."
	@make fclean -C $(LIBFT)
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

