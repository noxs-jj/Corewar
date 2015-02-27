/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeage <fdeage@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/13 17:30:01 by fdeage            #+#    #+#             */
/*   Updated: 2015/02/27 14:37:25 by fdeage           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "asm_fn.h"

/*
** translate_token_value() handles negative values by casting to size_t so that
** the % and / operators work as expected
*/

static void	translate_token_value(int value, char *code, int size, size_t *i)
{
	size_t	j;

	j = 0;
	if (size == 1)
		code[j] = ((size_t)value) % 256;
	else if (size == 2)
	{
		code[j] = ((size_t)value) / 256;
		code[j + 1] = ((size_t)value) % 256;
	}
	else if (size == 4)
	{
		code[j] = ((size_t)value) / (256 * 256 * 256);
		code[j + 1] = (((size_t)value) - code[j] * 256 * 256 * 256)
			/ (256 * 256);
		code[j + 2] = (((size_t)value) - code[j + 1] * 256 * 256) / 256;
		code[j + 3] = (((size_t)value) - code[j + 2] * 256) % 256;
	}
	*i += size;
	return ;
}

static int	translate_params(t_file *file, t_line *line, t_op *op)
{
	t_list	*tmp;
	size_t	i;

	i = 0;
	tmp = line->tokens->next;
	while (tmp)
	{
		if (get_param_value(file->lines, line, TOKEN) == EXIT_FAILURE)
			RET("Couldn't translate parameters.\n", EXIT_FAILURE);
		if (TOKEN->type == T_A_REG)
			translate_token_value(TOKEN->value, &(line->bytecode[1
				+ op->has_pcode + i]), T_REG_LEN, &i);
		else if (TOKEN->type == T_A_IND || TOKEN->type == T_A_INDLAB)
			translate_token_value(TOKEN->value, &(line->bytecode[1
				+ op->has_pcode + i]), T_IND_LEN, &i);
		else if (TOKEN->type == T_A_DLAB || (TOKEN->type == T_A_DIR
				&& (op->has_idx)))
			translate_token_value(TOKEN->value, &(line->bytecode[1
				+ op->has_pcode + i]), T_DLAB_LEN, &i);
		else if (TOKEN->type == T_A_DIR)
			translate_token_value(TOKEN->value, &(line->bytecode[1
				+ op->has_pcode + i]), T_DIR_LEN, &i);
		tmp = tmp->next;
	}
	return (EXIT_SUCCESS);
}

static void	get_pcode(t_list *tokens, char *bytecode)
{
	t_list	*tmp;
	uint8_t	pcode2;
	int		i;

	pcode2 = 0;
	i = 0;
	tmp = tokens;
	while (tmp)
	{
		if (TOKEN->type == T_A_DLAB || TOKEN->type == T_A_DIR
			|| TOKEN->type == T_A_IND || TOKEN->type == T_A_INDLAB)
			pcode2 |= (1 << (7 - i));
		if (TOKEN->type == T_A_REG || TOKEN->type == T_A_IND
			|| TOKEN->type == T_A_INDLAB)
			pcode2 |= (1 << (6 - i));
		i += 2;
		tmp = tmp->next;
	}
	bytecode[1] = pcode2;
	return ;
}

static t_op	*get_inst_code(t_line *line)
{
	t_token	*token;
	t_op	*op;

	token = (t_token *)(line->tokens->content);
	if (!(op = token->op))
		return (NULL);
	if (op->has_pcode)
		get_pcode(line->tokens->next, line->bytecode);
	line->bytecode[0] = op->opcode;
	return (op);
}

int			convert_file(t_file *file)
{
	t_list	*tmp;
	t_op	*op;

	tmp = file->lines;
	while (tmp)
	{
		if (LINE->type == T_EXEC && LINE->tokens)
		{
			if (!(op = get_inst_code(LINE)))
				RET("No instruction.\n", EXIT_FAILURE);
			if (!(LINE->tokens->next))
				RET("No parameters for the instruction.\n", EXIT_FAILURE);
			if (translate_params(file, LINE, op) == EXIT_FAILURE)
				return (EXIT_FAILURE);
		}
		tmp = tmp->next;
	}
	return (EXIT_SUCCESS);
}
