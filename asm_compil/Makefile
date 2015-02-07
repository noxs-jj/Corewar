#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmoiroux <jmoiroux@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/07 13:25:28 by jmoiroux          #+#    #+#              #
#    Updated: 2015/02/07 13:25:29 by jmoiroux         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CC = gcc

NAME = asm

CFLAGS = -Wall -Werror -Wextra -pedantic

PATH_LIB = ../libft
LIBFT = libft.a

HEAD = asm_compil.h

SRC = 	asm_getASMdata.c \
		asm_main.c \
		asm_init_start.c \
		asm_lst.c

OBJ = $(SRC:.c=.o)

%.o: %.c $(HEAD)
	@$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

alone: $(OBJ)
	make -C ../libft
	cp ../libft/libft.a .
	$()

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
