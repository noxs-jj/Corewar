# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/07 13:06:38 by vjacquie          #+#    #+#              #
#    Updated: 2015/02/16 15:55:00 by vjacquie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Werror -Wextra -w -pedantic -lncurses

HEADER = ../includes/corewar.h

LIB = ../libft/libft.a

NAME = corewar

SRCS =	main.c \
		init_start.c \
		print_error.c \
		writeL.c \
		getData.c \
		ncurse/nc_LegendColumn.c \
		ncurse/nc_LegendInfoValue.c \
		ncurse/nc_LegendPlayerValue.c \
		ncurse/nc_LegendSentence.c \
		ncurse/nc_close_free.c \
		ncurse/nc_draw_scene.c \
		ncurse/nc_init.c \
		ncurse/nc_keyboard.c \
		ncurse/nc_legendPlayerSentence.c \
		ncurse/nc_renderLegendPlayerValue1.c \
		ncurse/nc_renderLegendPlayerValue2.c \
		ncurse/nc_renderLegendPlayerValue3.c \
		ncurse/nc_renderLegendPlayerValue4.c \
		exit_free.c \
		read_files.c \
		init_prog.c \
		init_mem.c \
		putHexNbr.c \
		load_champions.c \
		gameStart.c \
		execOp.c \
		checkNextOp.c \
		readOpCode.c

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
