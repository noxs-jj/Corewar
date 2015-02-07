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

CC = gcc

CFLAGS = -Wall -Werror -Wextra -w -pedantic

HEADER = corewar.h

LIB = libft/libft.a

COREWAR = corewar
CORE-OBJ = $(CORE-SRC:.c=.o)
CORE-SRC = 


COMPILATEUR = asm
ASM-OBJ = $(ASM-SRC:.c=.o)
ASM-SRC = 	asm_main.c \
			asm_getASMdata.c \
			asm_init_start.c \
			asm_sti.c


%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -o $@ $^

all: $(NAME)

$(LIB):
	make -C libft

$(NAME): $(LIB) $(OBJ) asm corewar
	@echo "asm & corewar compiled"
	

asm: $(LIB) $(ASM-OBJ)
	$(CC) $(CFLAGS) $(ASM-OBJ) -o $(COMPILATEUR) -lncurses -L libft -lft

corewar: $(LIB) $(CORE-OBJ)
	$(CC) $(CFLAGS) $(ASM-OBJ) -o $(COMPILATEUR) -lncurses -L libft -lft

clean:
	make clean -C libft
	rm -rf $(ASM-OBJ)
	rm -rf $(CORE-OBJ)

fclean: clean
	make fclean -C libft
	rm -rf $(COREWAR)
	rm -rf $(COMPILATEUR)

re: fclean all

.PHONY: all clean fclean re asm corewar
