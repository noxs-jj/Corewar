/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeage <fdeage@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/12 17:30:15 by fdeage            #+#    #+#             */
/*   Updated: 2015/02/16 21:35:52 by fdeage           ###   ########.fr       */
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

//TODO ERROR:
//reg number > REG_NUMBER
//label en dehors du file
//type d'arg incorrect

//macro conversion T_DIRECT_LABEL

# define LINE				((t_line *)(tmp->content))
# define TOKEN				((t_token *)(tmp->content))

//# define COL(x)				ft_putstr_color( x )

# define RET(x, y)			{ft_putstr_color("ERR: ",COL_RED);ft_putstr_color( x ,COL_LIGHT_RED);return( y );}

#define OP_NAME				0
#define OP_ARG_NB			1
#define OP_ARG_TYPE			2
#define OP_CODE				3
#define OP_CYCLES			4
#define OP_DESC				5
#define OP_HAS_PCODE		6
#define OP_HAS_IDX			7

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
	T_EXEC,  //4
	T_STRING, //5
	T_LABEL, //6
	T_INSTRUCTION, //7
	T_A_REG, //8
	T_A_IND, //9
	T_A_DIR, //10
	T_A_DLAB, //11
};

typedef struct				s_token
{
	size_t					id;
	size_t					col;
	char					*data; //malloc
	int						value;
	t_op					*op; //malloc
	enum e_token_type		type;
}							t_token; //malloc !

typedef struct				s_line
{
	size_t					id;
	size_t					len;
	char					*str; //malloc
	enum e_token_type		type;
	size_t					nb_param;
	char					bytecode[8]; //1 + 1 + 2 + 2 + 2
	char					pcode;
	t_list					*tokens;
}							t_line;

typedef struct				s_file
{
	t_header				header;
	t_list					*lines; //malloc
	char					*name_s; //malloc
	char					*name_cor; //malloc
	size_t					size;
	size_t					nb_line;
	int						ret;
	int						fd_s;
	int						fd_cor;
	//int						error; //cf e_error_type
}							t_file;

#endif
