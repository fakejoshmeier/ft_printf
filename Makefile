# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmeier <jmeier@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/30 12:37:35 by jmeier            #+#    #+#              #
#    Updated: 2017/11/30 12:45:40 by jmeier           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libftprintf.a

CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra -c
LIB			=	ar rc
RLIB		=	ranlib

SRC_DIR		=	src
SRC_FILE	=	ft_printf.c h_cast.c hh_cast.c int_cast.c j_cast.c l_cast.c \
				ll_cast.c z_cast.c parse_flags.c parse_flags2.c
SRCS		=	$(addprefix $(SRC_DIR)/, $(SRC_FILE))

OBJ_DIR		=	obj
OBJ_FILE	=	$(SRC_FILE:.c=.o)
OBJS		=	$(addprefix $(OBJ_DIR)/, $(OBJ_FILE))

LIBFT_DIR	=	libft
LIBFT_LIB	=	libft.a
LIBFT_INC	=	inc
LIBFT		=	$(LIBFT_DIR)/$(LIBFT_LIB)

INC_DIR		=	-I $(LIBFT_DIR)/$(LIBFT_INC) -I inc

.PHONY: libft all clean fclean re

all: $(LIBFT) $(NAME)

$(NAME): $(SRCS) | $(OBJS)
	@echo Compiling $(NAME)...
	@$(LIB) $@ $(OBJS)
	@$(RLIB) $(NAME)
	@#@$(CC) $(CFLAGS) $(LIBFT) $(OBJS) $(INC_DIR) -o $(NAME)
	@echo $(NAME) compiled

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) -c $^ $(CFLAGS) $(INC_DIR) -o $@

clean:
	@cd $(LIBFT_DIR) && make clean
	@echo Cleaning .o files...
	@rm -rf $(OBJ_DIR)
	@echo Done

fclean: clean
	@cd $(LIBFT_DIR) && make fclean
	@echo Cleaning $(NAME)...
	@rm -f $(NAME)
	@echo Done

re: fclean all

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)
