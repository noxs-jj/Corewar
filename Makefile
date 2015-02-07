#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmoiroux <jmoiroux@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/06 14:35:17 by jmoiroux          #+#    #+#              #
#    Updated: 2015/02/06 14:35:18 by jmoiroux         ###   ########.fr        #
#                                                                              #
#******************************************************************************#


COMPIL = 		gcc -Wall -Wextra -Werror
#COMPIL = /usr/bin/clang -Wall -Wextra -Werror
#COMPIL = /usr/local/bin/gcc -Wall -Wextra -Werror
#COMPIL = /usr/bin/gcc -Wall -Wextra -Werror

BIN_ASM =		asm_compil/asm
BIN_COREWAR =	corewar_src/corewar

LIBFT = 		libft/libft.a

all:
	make -C libft
	make -C corewar_src
	make -C asm_compil
	cp $(BIN_COREWAR) .
	cp $(BIN_ASM) .

corewar:
	make -C libft
	make -C corewar_src
	cp $(BIN_COREWAR) .

asm:
	make -C libft
	make -C asm_compil
	cp $(BIN_ASM) .

clean:
	make clean -C libft
	make clean -C corewar_src
	make clean -C asm_compil

fclean:
	make fclean -C libft
	make fclean -C corewar_src
	make fclean -C asm_compil
	rm -rf log/*.log
	rm asm
	rm corewar

clog:
	rm -rf log/*.log

re: fclean all

.PHONY: all clean fclean re corewar asm
