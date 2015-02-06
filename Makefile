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


COREWAR = corewar
CORE-OBJ = $(CORE-SRC:.c=.o)
CORE-SRC = 


COMPILATEUR = asm
ASM-OBJ = $(ASM-SRC:.c=.o)
ASM-SRC = 	asm_main.c \
			asm_getASMdata.c \
			asm_sti.c \
			init_start.c

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ) asm corewar
	@echo "asm & corewar compiled"
	

asm: $(ASM-OBJ)
	$(CC) $(CFLAGS) $(ASM-OBJ) -o $(COMPILATEUR)

corewar: $(CORE-OBJ)
	$(CC) $(CFLAGS) $(ASM-OBJ) -o $(COMPILATEUR)

clean:
	rm -rf $(ASM-OBJ)
	rm -rf $(CORE-OBJ)

fclean: clean
	rm -rf $(COREWAR)
	rm -rf $(COMPILATEUR)

re: fclean all

.PHONY: all clean fclean re asm corewar
