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
BIN_COREWAR =	corewar/corewar

LIBFT = 		libft/libft.a

all:
	make -C libft
	make -C corewar
	make -C asm_compil
	cp $(BIN_COREWAR) .
	cp $(BIN_ASM) .

corewar:
	make -C libft
	make -C corewar

asm:
	make -C libft
	make clean -C asm_compil

clean:
	make clean -C libft
	make clean -C corewar
	make clean -C asm_compil

fclean:
	make fclean -C libft
	make fclean -C corewar
	make fclean -C asm_compil
	rm $(BIN_ASM) .
	rm $(BIN_COREWAR) .

re: fclean all

.PHONY: all clean fclean re corewar asm
