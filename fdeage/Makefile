#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fdeage <fdeage@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/29 16:38:06 by fdeage            #+#    #+#              #
#    Updated: 2015/02/14 22:04:13 by fdeage           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME		=	asm

SRC 		=	main.c	\
				read.c	\
				write.c	\
				parse.c	\
				tokenize.c	\
				convert.c	\
				error.c	\
				exit.c	\
				op.c

OBJ			=	$(SRC:.c=.o)

INC			=	-I./includes -I./libft/includes -Llibft -lft

FLAGS		=	$(CFLAGS)
CFLAGS		=	-Wall -Wextra -Werror -g3
P			=	-pedantic
EXTRAFLAGS	=	--analyze -Weverything -Wno-missing-prototypes -Qunused-arguments

CC			=	/usr/local/bin/gcc
RM			=	/bin/rm -v

all			:	$(NAME)

$(NAME)		:	$(OBJ)
				make -C ./libft
				$(CC) $(FLAGS) $(INC) $(OBJ) -o $(NAME)
clean		:
				make -C ./libft clean
				$(RM) $(OBJ)

fclean		:	clean
				make -C ./libft fclean
				$(RM) $(NAME)

re			:	fclean all

extra       :   FLAGS += $(EXTRAFLAGS)
extra       :   re

%.o			:	%.c
				$(CC) $(FLAGS) $(INC) -c $< -o $@
