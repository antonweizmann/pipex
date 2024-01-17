	# **************************************************************************** #
	#                                                                              #
	#                                                         :::      ::::::::    #
	#    Makefile                                           :+:      :+:    :+:    #
	#                                                     +:+ +:+         +:+      #
	#    By: aweizman <aweizman@student.42.fr>          +#+  +:+       +#+         #
	#                                                 +#+#+#+#+#+   +#+            #
	#    Created: 2023/10/16 13:04:28 by aweizman          #+#    #+#              #
	#    Updated: 2023/10/16 14:31:18 by aweizman         ###   ########.fr        #
	#                                                                              #
	# **************************************************************************** #

	NAME		= libftprintf.a
	INCLUDE		= include
	LIBFT		= libft
	SRC_DIR		= src/
	OBJ_DIR		= obj/
	CC			= gcc
	CFLAGS		= -Wall -Werror -Wextra -I
	RM			= rm -f
	AR			= ar rcs

	SRCS		=	ft_printf ft_getstr ft_getnbr
	BONUS_SRCS	=	ft_printf_bonus ft_getstr_bonus ft_getnbr_bonus

SRC 		= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRCS)))
OBJ 		= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRCS)))
BONUS_SRC	= 	$(addprefix $(SRC_DIR), $(addsuffix .o, $(BONUS_SRCS)))
BONUS_OBJ	= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(BONUS_SRCS)))
OBJ_CHECK		=	.cache_exists

all:	$(NAME)

$(NAME):	$(OBJ)
		@make bonus -C $(LIBFT)
		@cp	$(LIBFT)/libft.a $(NAME)
		@$(AR) $(NAME) $(OBJ)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJ_CHECK)
		@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(OBJ_CHECK):
		@mkdir -p $(OBJ_DIR)

clean:
		@$(RM) -r $(OBJ_DIR)
		@make clean -C $(LIBFT)

fclean: clean
		@$(RM) $(NAME)
		@$(RM) $(LIBFT)/libft.a

re: fclean all

bonus: $(BONUS_OBJ)
		@make -C $(LIBFT)
		@cp	$(LIBFT)/libft.a $(NAME)
		@$(AR) $(NAME) $(BONUS_OBJ)

.PHONY:		all clean fclean re bonus
