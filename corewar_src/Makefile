# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/07 13:06:38 by vjacquie          #+#    #+#              #
#    Updated: 2015/03/12 14:16:03 by vjacquie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Werror -Wextra -w -pedantic -lncurses

HEADER = ../includes/corewar.h

LIB = ../libft/libft.a

NAME = corewar

SRCS =	arg_dump.c \
		changeMemVal.c \
		checkNextOp.c \
		cycle.c \
		execOp.c \
		exit_free.c \
		ft_hex2Dec.c \
		gameStart.c \
		get_arg_int.c \
		get_arg_modulo.c \
		getData.c \
		getOpArgs.c \
		init_mem.c \
		init_prog.c \
		init_start.c \
		isValidRegister.c \
		load_champions.c \
		lst_prog.c \
		main.c \
		ncurse/nc_close_free.c \
		ncurse/nc_color_champ1.c \
		ncurse/nc_color_champ2.c \
		ncurse/nc_color_champ3.c \
		ncurse/nc_color_champ4.c \
		ncurse/nc_draw_scene.c \
		ncurse/nc_init.c \
		ncurse/nc_keyboard.c \
		ncurse/nc_legend_column.c \
		ncurse/nc_legend_info_value.c \
		ncurse/nc_legend_player_sentence.c \
		ncurse/nc_legend_player_value.c \
		ncurse/nc_legend_sentence.c \
		ncurse/nc_render_legend_player_value1.c \
		ncurse/nc_render_legend_player_value2.c \
		ncurse/nc_render_legend_player_value3.c \
		ncurse/nc_render_legend_player_value4.c \
		op/op_add.c \
		op/op_aff.c \
		op/op_and.c \
		op/op_fork.c \
		op/op_ld.c \
		op/op_ldi.c \
		op/op_lfork.c \
		op/op_live.c \
		op/op_lld.c \
		op/op_lldi.c \
		op/op_or.c \
		op/op_st.c \
		op/op_sti.c \
		op/op_sub.c \
		op/op_xor.c \
		op/op_zjump.c \
		pcAdvance.c \
		print_error.c \
		putHexNbr.c \
		read_files.c \
		readOpCode.c \
		shell/co_draw_result_console.c \
		shell/co_info_player1.c \
		shell/co_info_player2.c \
		shell/co_info_player3.c \
		shell/co_info_player4.c \
		shell/co_render_shell.c \
		shell/co_show_init_players.c \
		shell/co_troll.c \
		writeL.c \
		hex_to_reg.c

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
