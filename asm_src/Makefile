#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fdeage <fdeage@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/29 16:38:06 by fdeage            #+#    #+#              #
#    Updated: 2015/03/13 12:49:08 by vjacquie         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME		=	asm

SRC 		=	main.c	\
				read.c	\
				write.c	\
				parse.c	\
				tokenize.c	\
				convert.c	\
				get_param_value.c	\
				error.c	\
				exit.c	\
				op.c	\
				check.c

OBJ			=	$(SRC:.c=.o)

INC			=	-I ../includes -I ../libft/includes
LINK		=	-L../libft -lft

FLAGS		=	$(CFLAGS)
CFLAGS		=	-Wall -Wextra -Werror -g3
P			=	-pedantic
EXTRAFLAGS	=	--analyze -Weverything -Wno-missing-prototypes	\
				-Qunused-arguments

CC			=	$(CLANG)
GCC			=	/usr/local/bin/gcc
CLANG		=	/usr/bin/clang
RM			=	/bin/rm -fv

all			:	$(NAME)

$(NAME)		:	$(OBJ)
				make -C ../libft
				$(CC) $(FLAGS) $(INC) $(LINK) $(OBJ) -o $(NAME)
clean		:
				make -C ../libft clean
				$(RM) $(OBJ)

fclean		:	clean
				make -C ../libft fclean
				$(RM) $(NAME)

re			:	fclean all

extra       :   FLAGS += $(EXTRAFLAGS)
extra       :   re

%.o			:	%.c
				$(CC) $(FLAGS) $(INC) -c $< -o $@
