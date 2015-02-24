/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeage <fdeage@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/13 17:30:01 by fdeage            #+#    #+#             */
/*   Updated: 2015/02/18 14:20:36 by fdeage           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	get_param_value(t_list *tokens, t_token *token)
{
	t_list	*tmp;

	if (token->type == T_A_REG || token->type == T_A_DIR)
		token->value = ft_atoi(token->data + 1);
	else if (token->type == T_A_IND)
		token->value = ft_atoi(token->data);
	else if (token->type == T_A_DLAB)
	{
		tmp = tokens;
		//get label value
		while (tmp)
		{



			tmp = tmp->next;
		}
	}
	(void)tokens;
	return ;
}

//bytecode[8]
//static void	translate_params(t_list *tokens, size_t nb_param, char *bytecode,
static void	translate_params(t_file *file, t_line *line, int has_pcode)
{
	t_list	*tmp;
	size_t	i;

	i = 0;
	tmp = line->tokens;
	while (tmp && i < line->nb_param)
	{
		get_param_value(line->tokens, TOKEN);
		if (TOKEN->type == T_A_REG)
		{
			line->bytecode[has_pcode + 2 * i] = TOKEN->value;
			++i;
		}
		else if (TOKEN->type == T_A_IND)
		{
			line->bytecode[has_pcode + 2 * i] = TOKEN->value;
			line->bytecode[has_pcode + 2 * i] = TOKEN->value;
			i += 2;
		}
		//	T_A_IND, //9
		//	T_A_DIR, //10
		//	T_A_DLAB,

		tmp = tmp->next;
	}
	(void)file;
	(void)has_pcode;
	return ;
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
		fprintf(stderr, "data = %s type = %d\n", TOKEN->data, TOKEN->type);
        if (TOKEN->type == T_A_DLAB || TOKEN->type == T_A_DIR || TOKEN->type == T_A_IND)
		{
			pcode2 |= (1 << (7 - i));
			fprintf(stderr, "c3=%u\n\n", 1 << (7 - i));
		}
        if (TOKEN->type == T_A_REG || TOKEN->type == T_A_IND)
		{
			pcode2 |= (1 << (6 - i));
			fprintf(stderr, "c4=%u\n\n", 1 << (6 - i));
		}
		i += 2;
		tmp = tmp->next;
	}
	//fprintf(stderr, "pcode = %s\n", pcode);
	fprintf(stderr, "pcode char c=%c=%d\n", pcode2, pcode2);
	bytecode[1] = pcode2;
	return ;
}

static void	get_inst_code(t_op *op, char *bytecode)
{
	bytecode[0] = op->opcode;
}


//OK - 24L
int			convert_file(t_file *file)
{
	t_list	*tmp;
	t_token	*token;
	t_op	*op;

	//fprintf(stderr, "CONVERT0\n");
	tmp = file->lines;
	while (tmp)
	{
		fprintf(stderr, "CONVERT loop - %s - type: %d\n", LINE->str, LINE->type);
		if (LINE->type == T_EXEC && LINE->tokens)
		{
			fprintf(stderr, "CONVERT loop 2 - %p\n", LINE->tokens);
			token = (t_token *)(LINE->tokens->content);
			fprintf(stderr, "CONVERT loop 3 - str = %s\n", token->data);
			if (!(op = token->op))
				return (EXIT_FAILURE);
			get_inst_code(op, LINE->bytecode);
			fprintf(stderr, "CONVERT loop 4a - bytecode = %s\n", LINE->bytecode);

			if (!(LINE->tokens->next))
				return (EXIT_FAILURE);
			if (op->has_pcode)
				get_pcode(LINE->tokens->next, LINE->bytecode);
			fprintf(stderr, "CONVERT loop 6 - bytecode = %s\n", LINE->bytecode);

			translate_params(file, LINE, op->has_pcode);
            fprintf(stderr, "\n\n--------------------------------------------------------------------------------------------\nLINE #%d -- str: |%s|    --  type: %d\n                 ", (int)LINE->id, LINE->str, LINE->type);
			int i =0;
			while (i < 14)
				fprintf(stderr, "%d ", LINE->bytecode[i++]);
			fprintf(stderr, "\n--------------------------------------------------------------------------------------------\n");
		}
		tmp = tmp->next;
	}
	//fprintf(stderr, "CONVERT1\n");
	return (EXIT_SUCCESS);
}
