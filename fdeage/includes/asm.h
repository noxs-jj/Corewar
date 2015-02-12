/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeage <fdeage@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/12 17:30:15 by fdeage            #+#    #+#             */
/*   Updated: 2015/02/12 17:33:52 by fdeage           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

//# include <stdlib.h>
//# include <unistd.h>
# include "libft.h"
# include "op.h"


/* virer */
#include<stdio.h>

# define COMMENT_CHAR2		';'
# define COMMENT_CHAR3		','
# define CMD_STRING_CHAR	'.'
# define SPC_CHAR			' '
# define TAB_CHAR			'\t'
# define HEADER_CHAR		'.'

# define LINE				((t_line *)(tmp->content))

# define CCS				COMMENT_CMD_STRING
# define NCS				NAME_CMD_STRING

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

typedef struct				s_line
{
	size_t					nb;
	char					*str;
	//t_line_type				type;
	char					*bytecode;
	int						param[4];
	int						param_types[4];

}							t_line;

typedef struct              s_file
{
	t_header				header;
	t_list					*lines;
    char                    *name_s; //malloc
    char                    *name_cor; //malloc
	char					*champ_name; //malloc
	char					*comment; //malloc
	size_t					size;
	size_t					nb_line;
	int						ret;
	int						fd_s;
	int						fd_cor;
}                           t_file;

typedef char				t_line_type;

#define T_TRALALA1			1
#define T_TRALALA2			2
#define T_TRALALA3			3
#define T_TRALALA4			4

t_op						g_op_tab[17];

#endif
