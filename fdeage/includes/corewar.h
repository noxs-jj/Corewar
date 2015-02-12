/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeage <fdeage@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/08 21:55:48 by fdeage            #+#    #+#             */
/*   Updated: 2015/02/11 16:46:16 by fdeage           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include <stdlib.h>
# include <unistd.h>
# include "libft.h"
# include "op.h"

# define COMMENT_CHAR2		';'
# define COMMENT_CHAR3		','
# define CMD_STRING_CHAR	'.'
# define SPC_CHAR			' '
# define TAB_CHAR			'\t'
# define HEADER_CHAR		'.'

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
	char					*str;
	char					*type;
	int						code;
	int						line;
}							t_line;

t_op						g_op_tab[17];

#endif
