# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmeier <jmeier@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/29 11:12:33 by jmeier            #+#    #+#              #
#    Updated: 2017/11/30 11:47:57 by jmeier           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
FILES = ft_printf \
		parse_flags parse_flags2 int_cast h_cast hh_cast l_cast ll_cast j_cast \
		z_cast

C_LOC = src/
C_NAM = $(addsuffix .c, $(FILES))
C_SRC = $(addprefix $(C_LOC), $(C_NAM))

O_LOC = obj/
O_NAM = $(addsuffix .o, $(FILES))
O_SRC = $(addprefix $(O_LOC), $(O_NAM))

LIB_LOC = libft/
LIB_NAM = libft.a
LIB_SRC = $(LIB_LOC)/$(LIB_NAM))

H_LOCS = -I inc -I libft/inc

C_FLAGS = -Wall -Werror -Wextra

all: $(LIBFT) $(NAME)

$(NAME): $(C_SRC) | $(O_SRC)
	@echo Compiling $@ library...
	@ar rcs $@ $(O_SRC)
	@ranlib $(NAME)

$(O_LOC)%.o: $(C_LOC)%.c
	@echo Re-compiling $< file...
	@gcc  $(H_LOCS) -o $@ -c $<

clean:
	@echo Cleaning .o files ...
	@make clean -C $(LIB_LOC)
	@/bin/rm -rf $(O_SRC)
	@echo ... Successfully removed .o files

fclean:
	@make fclean -C $(LIB_LOC)
	@echo Cleaning .o files...
	@/bin/rm -rf $(O_SRC)
	@echo Successfully removed .o files
	@echo Cleaning $(NAME) ...
	@/bin/rm -f $(NAME)
	@echo ...Successfully removed $(NAME)

re: fclean all

$(LIBFT):
	@$(MAKE) -C $(LIB_LOC)

.PHONY: all test clean fclean re