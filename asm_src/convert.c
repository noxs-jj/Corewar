/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeage <fdeage@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/13 17:30:01 by fdeage            #+#    #+#             */
/*   Updated: 2015/02/23 21:03:33 by fdeage           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "asm_fn.h"

//virer
void print_token(t_token *token)
{
    fprintf(stderr, "\n---------------------\ntoken #%d  -  type %d\n", (int)token->id, token->type);
    fprintf(stderr, "col. %d\n", (int)token->col);
    if (token->op)
        fprintf(stderr, "str: |%s|  ->  opcode %d\n---------------------\n", token->str, token->op->opcode);
    else
        fprintf(stderr, "str: |%s|\n---------------------\n", token->str);
}

/*
** translate_token_value() handles negative values by casting to size_t so that
** the % and / operators work as expected
*/

//OK - 20L
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

//OK - 23L
static void	translate_params(t_file *file, t_line *line, t_op *op)
{
	t_list	*tmp;
	size_t	i;


	fprintf(stderr, "\nTEST s = %s\n", line->str);

	i = 0;
	while (i < (size_t)(line->code_len))
		fprintf(stderr, "%d ", (line->bytecode)[i++]);
	fprintf(stderr, "\n");

	(void)file;
	i = 0;
	tmp = line->tokens->next;

	while (tmp)
	{
		print_token(TOKEN);
		//get_param_value(file->lines, TOKEN);
		get_param_value(file->lines, line, TOKEN);
		fprintf(stderr, "type=%d val=%d\n", (int)TOKEN->type, (int)TOKEN->value);
		if (TOKEN->type == T_A_REG)
			translate_token_value(TOKEN->value, &(line->bytecode[1
				+ op->has_pcode + i]), T_REG_LEN, &i);
		else if (TOKEN->type == T_A_IND)
			translate_token_value(TOKEN->value, &(line->bytecode[1
				+ op->has_pcode + i]), T_IND_LEN, &i);
		else if (TOKEN->type == T_A_DLAB || (TOKEN->type == T_A_DIR
				&& (op->has_idx)))
			translate_token_value(TOKEN->value, &(line->bytecode[1
				+ op->has_pcode + i]), T_DLAB_LEN, &i);
		else if (TOKEN->type == T_A_DIR)
			translate_token_value(TOKEN->value, &(line->bytecode[1
				+ op->has_pcode + i]), T_DIR_LEN, &i);

		int j = 0;
		//virer
		while (j < (int)line->code_len)
			fprintf(stderr, "%d ", (line->bytecode)[j++]);
		fprintf(stderr, "\n");

		tmp = tmp->next;
	}
	return ;
}


//OK - 17L
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
		fprintf(stderr, "data = %s type = %d\n", TOKEN->str, TOKEN->type);
		if (TOKEN->type == T_A_DLAB || TOKEN->type == T_A_DIR
			|| TOKEN->type == T_A_IND || TOKEN->type == T_A_INDLAB)
		{
			pcode2 |= (1 << (7 - i));
			fprintf(stderr, "c3=%u\n", 1 << (7 - i));
		}
		if (TOKEN->type == T_A_REG || TOKEN->type == T_A_IND)
		{
			pcode2 |= (1 << (6 - i));
			fprintf(stderr, "c4=%u\n", 1 << (6 - i));
		}
		i += 2;
		tmp = tmp->next;
	}
	fprintf(stderr, "pcode char c=%d\n\n", pcode2);
	bytecode[1] = pcode2;
	return ;
}

static t_op	*get_inst_code(t_line *line)
{
	t_token	*token;
	t_op	*op;

	token = (t_token *)(line->tokens->content);
	//fprintf(stderr, "CONVERT loop 3 - str = %s\n", token->data);
	if (!(op = token->op))
		return (NULL);
	fprintf(stderr, "\npcode = %d\n", op->has_pcode);
	if (op->has_pcode)
		get_pcode(line->tokens->next, line->bytecode);
	line->bytecode[0] = op->opcode;
	return (op);
}


//OK - 24L
int			convert_file(t_file *file)
{
	t_list	*tmp;
	//t_token	*token;
	t_op	*op;

	fprintf(stderr, "\n\n-------\nCONVERT:\n--------------------------------------------------------------------------------------------\n--------------------------------------------------------------------------------------------\n\n");
	tmp = file->lines;
	while (tmp)
	{
		fprintf(stderr, "CONVERT loop - s=|%s| - type: %d\n", LINE->str, LINE->type);
		//else ERROR
		if (LINE->type == T_EXEC && LINE->tokens)
		{
			if (!(op = get_inst_code(LINE)))
				return (EXIT_FAILURE);
			fprintf(stderr, "CONVERT loop 4a - op = %d  hasp = %d\n", op->opcode, op->has_pcode);

			if (!(LINE->tokens->next))
				return (EXIT_FAILURE);
			fprintf(stderr, "CONVERT loop 6 - bytecode = %s\n", LINE->bytecode);

			translate_params(file, LINE, op);
            fprintf(stderr, "\n\n--------------------------------------------------------------------------------------------\nLINE #%d -- str: |%s|    --  type: %d\n                 ", (int)LINE->id, LINE->str, LINE->type);
			int i =0;
			while (i < (int)LINE->code_len)
				fprintf(stderr, "%d ", LINE->bytecode[i++]);
			fprintf(stderr, "\n--------------------------------------------------------------------------------------------\n");
		}
		tmp = tmp->next;
	}
	//fprintf(stderr, "CONVERT1\n");
	return (EXIT_SUCCESS);
}
