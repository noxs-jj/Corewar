# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/07 13:06:38 by vjacquie          #+#    #+#              #
#    Updated: 2015/03/14 13:16:28 by vjacquie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Werror -Wextra -pedantic

HEADER = ../includes/corewar.h

LIB = ../libft/libft.a

NAME = corewar

SRCS =	arg_dump.c \
		changeMemVal.c \
		check_next_op.c \
		cycle.c \
		exec_op.c \
		exit_free.c \
		convert/arg_to_dec.c \
		convert/ft_hex_2_dec.c \
		convert/get_int_from_dec.c \
		convert/hex_strlen.c \
		convert/int_hex_len.c \
		convert/map_to_reg.c \
		convert/nbr2dec.c \
		convert/nbr2hex.c \
		convert/reg_to_int.c \
		convert/str_hex_len.c \
		convert/str_to_reg.c \
		convert/int_to_reg.c \
		convert/ft_put_nbr_2_hex.c \
		convert/ft_put_hex_nbr.c \
		convert/ft_put_hex_b_nbr.c \
		prog/add_prog.c \
		prog/del_all.c \
		prog/copy_prog.c \
		prog/del_prog.c \
		prog/new_prog.c \
		prog/search_prog.c \
		prog/last_prog.c \
		game_start.c \
		get_arg_int.c \
		get_arg_modulo.c \
		get_data.c \
		get_op_args.c \
		init_mem.c \
		init_reg.c \
		cpy_reg.c \
		init_start.c \
		is_valid_register.c \
		load_champions.c \
		option_log.c \
		main.c \
		ncurse/nc_close_free.c \
		ncurse/nc_color_champ1.c \
		ncurse/nc_color_champ2.c \
		ncurse/nc_color_champ3.c \
		ncurse/nc_color_champ4.c \
		ncurse/nc_draw_scene.c \
		ncurse/nc_init.c \
		ncurse/nc_key_plus.c \
		ncurse/nc_key_pause.c \
		ncurse/nc_key_minus.c \
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
		pc_advance.c \
		print_error.c \
		read_files.c \
		read_op_code.c \
		shell/co_draw_result_console.c \
		shell/co_info_player1.c \
		shell/co_info_player2.c \
		shell/co_info_player3.c \
		shell/co_info_player4.c \
		shell/co_render_shell.c \
		shell/co_show_init_players.c \
		shell/co_troll.c \
		write_l.c \
		is_register.c \
		is_indirect.c \
		is_direct.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(LIB):
	make -C ../libft

%.o: %.c $(HEADER)
	@$(CC) $(CFLAGS) -o $@ -c $< $(CFLAGS)


$(NAME): $(LIB) $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIB) -lncurses

clean:
	make clean -C ../libft
	rm -rf $(OBJS)

fclean: clean
	make fclean -C ../libft
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
