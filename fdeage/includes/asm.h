/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeage <fdeage@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/12 17:30:15 by fdeage            #+#    #+#             */
/*   Updated: 2015/02/20 17:51:40 by fdeage           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "libft.h"
# include "op.h"

//TODO:
/* virer */
#include<stdio.h>
//si erreur, pas de fichier zork.cor
//error_handling: globale t_error ?
//TODO: Makefile harmonise
//TODO: libft unique
//TODO : commentaites en ";" en fin de ligne (pas oblig)
//TODO: check if params type are legit

//TODO ERROR:
// - reg number > REG_NUMBER
// - label en dehors du file
// - type d'arg incorrect
// - is not number nor label -> lexical error
// - %:label: is label_chars

//macro conversion T_DIRECT_LABEL

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

typedef struct				s_op
{
	char					*name;
	int						nb_params;
	int						param_types[4];
	int						opcode;
	int						nb_cycles;
	char					*description;
	int						has_pcode;
	int						has_idx;
}							t_op;

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
	T_A_REG, //9
	T_A_IND, //10
	T_A_DIR, //11
	T_A_DLAB, //12
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
	size_t					col;
	int						value;
	enum e_token_type		type;
}							t_token; //malloc !

typedef struct				s_line
{
	t_list					*tokens;
	size_t					id;
	size_t					code_len;
	char					*str; //malloc
	size_t					nb_param;
	enum e_token_type		type;
	int						has_final_comment;
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
