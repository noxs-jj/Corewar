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

HEADER =


COREWAR = corewar
CORE-OBJ = $(SRC:.c=.o)
CORE-SRC = 


COMPILATEUR = asm
ASM-OBJ = $(SRC:.c=.o)
ASM-SRC = 


%.c.o: %.c $(HEAD)
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ) asm corewar
	

asm: $(ASM-OBJ)

corewar: $(CORE-OBJ)

clean:
	rm -rf $(ASM-OBJ)
	rm -rf $(CORE-OBJ)

fclean: clean
	rm -rf $(COREWAR)
	rm -rf $(COMPILATEUR)

re: fclean all

.PHONY: all clean fclean re asm corewar
