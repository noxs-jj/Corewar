/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeage <fdeage@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/12 17:30:15 by fdeage            #+#    #+#             */
/*   Updated: 2015/02/27 12:57:20 by fdeage           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "libft.h"
# include "op.h"

# define LINE				((t_line *)(tmp->content))
# define TOKEN				((t_token *)(tmp->content))
# define FC(x, y)			ft_putstr_color(x , y );

# define RET(x, y)	{FC("ERR: ",COL_RED);FC( x ,COL_LIGHT_RED);return( y );}

enum						e_error_type
{
	T_TOO_MANY_PARAMS = 0,
	T_NOT_ENOUGH_PARAMS
};

enum						e_token_type
{
	T_UNKNOWN = 0,
	T_CMD_NAME,
	T_CMD_COMMENT,
	T_COMMENT,
	T_EXEC,
	T_STRING,
	T_LABEL,
	T_INSTRUCTION,
	T_A_REG = 9,
	T_A_DIR = 10,
	T_A_IND = 12,
	T_A_DLAB,
	T_A_INDLAB,
};

# define T_DIR_LEN			4
# define T_DLAB_LEN			2
# define T_IND_LEN			2
# define T_REG_LEN			1

typedef struct				s_token
{
	t_op					*op;
	char					*str;
	size_t					id;
	int						value;
	enum e_token_type		type;
}							t_token;

typedef struct				s_line
{
	t_list					*tokens;
	size_t					id;
	size_t					code_len;
	char					*str;
	size_t					nb_params;
	enum e_token_type		type;
	char					bytecode[14];
	char					pcode;
}							t_line;

# define T_OPTION_VERBOSE	1
# define T_OPTION_LEAKS		2

typedef struct				s_file
{
	int						options;
	t_header				header;
	t_list					*lines;
	char					*name_s;
	char					*name_cor;
	size_t					nb_line;
	size_t					has_name;
	int						ret;
	int						fd_s;
	int						fd_cor;
}							t_file;

#endif
