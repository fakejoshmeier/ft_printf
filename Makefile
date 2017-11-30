# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmeier <jmeier@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/30 14:06:03 by jmeier            #+#    #+#              #
#    Updated: 2017/11/30 14:09:38 by jmeier           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a

SRC		= ./src/*.c ./libft/src/*.c

OBJ		= $(SRC:.c=.o)
CFLAG	= -Wall -Wextra -Werror
HEADER	= inc/

all: $(NAME)

$(NAME):
	gcc $(CFLAG) -c -I$(HEADER) -I ./libft/inc $(SRC)
	ar rc $(NAME) *.o
	ranlib $(NAME)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
