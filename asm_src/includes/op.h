/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaz <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/04 11:33:27 by zaz               #+#    #+#             */
/*   Updated: 2015/02/24 12:39:14 by fdeage           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OP_H
# define OP_H

# define COMMENT_CHAR			'#'
# define FINAL_COMMENT_CHAR		';'

# define LABEL_CHAR				':'
# define REGISTER_CHAR			'r'
# define DIRECT_CHAR			'%'
# define SEPARATOR_CHAR			','

# define LABEL_CHARS			"abcdefghijklmnopqrstuvwxyz_0123456789"

# define NAME_CMD_STRING		".name"
# define COMMENT_CMD_STRING		".comment"

# define REG_NUMBER				16

/*
** T_OP STRUCT
*/

typedef struct					s_op
{
	char						*name;
	int							nb_params;
	int							param_types[4];
	int							opcode;
	int							nb_cycles;
	char						*description;
	int							has_pcode;
	int							has_idx;
}								t_op;

/*
** T_ARG_TYPE
*/

typedef char					t_arg_type;


# define T_REG					1
# define T_DIR					2
# define T_IND					4
# define T_LAB					8

/*
** EXEC
*/

# define PROG_NAME_LENGTH		(128)
# define COMMENT_LENGTH			(2048)
# define COREWAR_EXEC_MAGIC		0xea83f3

/*
** HEADER STRUCT
*/

typedef struct					s_header
{
	unsigned int				magic;
	char						prog_name[PROG_NAME_LENGTH + 1];
	unsigned int				prog_size;
	char						comment[COMMENT_LENGTH + 1];
}								t_header;

#endif
