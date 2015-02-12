# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/07 13:06:38 by vjacquie          #+#    #+#              #
#    Updated: 2015/02/11 15:50:34 by vjacquie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Werror -Wextra -pedantic -lncurses

HEADER = ../includes/corewar.h

LIB = ../libft/libft.a

NAME = corewar

SRCS =	main.c \
		init_start.c \
		print_error.c \
		writeL.c \
		getData.c \
		nc_init.c \
		nc_draw_scene.c \
		nc_close_free.c \
		nc_keyboard.c \
		nc_LegendColumn.c \
		nc_legendPlayerSentence.c \
		nc_LegendSentence.c \
		nc_LegendPlayerValue.c \
		nc_LegendInfoValue.c \
		read_files.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(LIB):
	make -C ../libft

%.o: %.c $(HEADER)
	@$(CC) -o $@ -c $< $(CFLAGS)


$(NAME): $(LIB) $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIB)

clean:
	make clean -C ../libft
	rm -rf $(OBJS)

fclean: clean
	make fclean -C ../libft
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
