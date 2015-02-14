/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeage <fdeage@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/12 17:30:15 by fdeage            #+#    #+#             */
/*   Updated: 2015/02/14 22:46:12 by fdeage           ###   ########.fr       */
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

# define LINE				((t_line *)(tmp->content))

# define RET(x, y)			{ft_putstr_color("ERR: ",COL_RED);ft_putstr_color( x ,COL_LIGHT_RED);return( y );}

/*
typedef char				t_line_type;

#define T_INIT_COMMENT		1
#define T_NAME				2
#define T_COMMENT			3
#define T_INST				4
*/

#define OP_NAME				0
#define OP_ARG_NB			1
#define OP_ARG_TYPE			2
#define OP_CODE				3
#define OP_CYCLES			4
#define OP_DESC				5
#define OP_HAS_PCODE		6
#define OP_HAS_IDX			7

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

enum						e_error_type
{
    T_TOO_MANY_PARAMS = 0,
	T_NOT_ENOUGH_PARAMS
};

enum            			e_token_type
{
    T_UNKNOWN = 0,
    T_CMD_NAME,
    T_CMD_COMMENT,
	T_COMMENT,
	T_EXEC,
    T_STRING,
    T_INSTRUCTION,
    T_REGISTER,
    T_LABEL,
    T_INDIRECT,
    T_DIRECT,
    T_DIRECT_LABEL,
};

typedef struct				s_token
{
	int						id;
	//int						line;
	int						col;
	char					*data;
	t_op					*op;
	enum e_token_type		type;
}							t_token;

typedef struct				s_line
{
	size_t					id;
	size_t					len;
	char					*str; //malloc
    enum e_token_type       type;
	//t_line_type				type;
	char					*bytecode; //malloc
	char					pcode;
	t_list					*tokens;
	//t_inst					inst;
	//int						param[4];
	//int						param_types[4];
}							t_line;

typedef struct              s_file
{
	t_header				header;
	t_list					*lines; //malloc
    char                    *name_s; //malloc
    char                    *name_cor; //malloc
	size_t					size;
	size_t					nb_line;
	int						ret;
	int						fd_s;
	int						fd_cor;
	//int						error; //cf e_error_type
}                           t_file;

t_op						g_op_tab[17];

#endif
