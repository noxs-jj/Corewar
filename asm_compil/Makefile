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

CFLAGS = -Wall -Werror -Wextra -w -pedantic

HEADER = ../includes/corewar.h

LIB = ../libft/libft.a

NAME = asm

SRCS =	asm_getASMdata.c \
		asm_init_start.c \
		asm_main.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(LIB):
	make -C ../libft

%.o: %.c $(HEADER)
	@$(CC) -o $@ -c $< $(CFLAGS)


$(NAME): $(LIB) $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -lncurses $(LIB)

clean:
	make clean -C ../libft
	rm -rf $(OBJS)

fclean: clean
	make fclean -C ../libft
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
