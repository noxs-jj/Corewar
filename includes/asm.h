/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeage <fdeage@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/12 17:30:15 by fdeage            #+#    #+#             */
/*   Updated: 2015/02/26 19:06:22 by fdeage           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "libft.h"
# include "op.h"

//TODO:
/* virer */
#include<stdio.h>
//error_handling: globale t_error ?
//TODO: Makefile harmonise
//TODO: libft unique
//TODO : commentaites en ";" en fin de ligne (pas oblig)
//TODO: if ref to a label that doesnt exist
//TODO: check if params type are legit

//TODO ERROR:
// - reg number > REG_NUMBER
// - label en dehors du file
// - type d'arg incorrect
// - is not number nor label -> lexical error
// - %:label: is label_chars
// file that doenst exist: error message

# define LINE				((t_line *)(tmp->content))
# define TOKEN				((t_token *)(tmp->content))

//# define COL(x)				ft_putstr_color( x )

# define RET(x, y)			{ft_putstr_color("ERR: ",COL_RED);\
		ft_putstr_color( x ,COL_LIGHT_RED);return( y );}

enum						e_error_type
{
	T_TOO_MANY_PARAMS = 0,
	T_NOT_ENOUGH_PARAMS
};

enum						e_token_type
{
	T_UNKNOWN = 0,
	T_CMD_NAME,  //1
	T_CMD_COMMENT,  //2
	T_COMMENT,  //3
	T_F_COMMENT,  //4
	T_EXEC,  //5
	T_STRING, //6
	T_LABEL, //7
	T_INSTRUCTION, //8
	T_A_REG = 9,
	T_A_DIR = 10,
	T_A_IND = 12,
	T_A_DLAB, //13
	T_A_INDLAB, //14
};

# define T_DIR_LEN			4
# define T_DLAB_LEN			2
# define T_IND_LEN			2
# define T_REG_LEN			1

typedef struct				s_token
{
	t_op					*op; //malloc
	char					*str; //malloc
	size_t					id;
	int						value;
	enum e_token_type		type;
}							t_token; //malloc !

typedef struct				s_line
{
	t_list					*tokens;
	size_t					id;
	size_t					code_len;
	char					*str; //malloc
	size_t					nb_params;
	enum e_token_type		type;
	int						has_final_comment; //doubl0on ?
	char					bytecode[14]; //MAX: 1 + 1 + 4 + 4 + 4, no EOL
	char					pcode;
}							t_line;

# define T_OPTION_VERBOSE	1
# define T_OPTION_LEAKS		2

typedef struct				s_file
{
	int						options;
	t_header				header;
	t_list					*lines; //malloc
	char					*name_s; //malloc
	char					*name_cor; //malloc
	size_t					nb_line;
	int						ret;
	int						fd_s;
	int						fd_cor;
	//int						error; //cf e_error_type
}							t_file;

#endif
