/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeage <fdeage@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/13 17:30:01 by fdeage            #+#    #+#             */
/*   Updated: 2015/02/16 21:35:25 by fdeage           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	get_param_value(t_token *token)
{
	t_list	*tmp;

	if (token->type == T_A_REG || token->type == T_A_DIR)
		token->value = ft_atoi(token->data + 1);
	else if (token->type == T_A_IND)
		token->value = ft_atoi(token->data);
	else if (token->type == T_A_DLAB)
	{
		g
	}
	return ;
}

//bytecode[8]
static void	translate_params(t_list *tokens, size_t nb_param, char *bytecode,
	int has_pcode)
{
	t_list	*tmp;
	size_t	i;

	i = 0;
	tmp = tokens;
	while (tmp && i < nb_param)
	{
		get_param_value(TOKEN);
		//bytecode[has_pcode + 2 * i] = ;
		//bytecode[has_pcode + 2 * i + 1] = ;
		++i;
		tmp = tmp->next;
	}
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

int			convert_file(t_file *file)
{
	t_list	*tmp;
	t_token	*token;
	t_op	*op;

	fprintf(stderr, "CONVERT0\n");
	tmp = file->lines;
	while (tmp)
	{
		fprintf(stderr, "CONVERT loop - %s - type: %d\n", LINE->str, LINE->type);
		if (LINE->type == T_EXEC && LINE->tokens)
		{
			fprintf(stderr, "CONVERT loop 2 - %p\n", LINE->tokens);
			token = (t_token *)(LINE->tokens->content);
			fprintf(stderr, "CONVERT loop 3 - str = %s\n", token->data);
			op = token->op;
			if (!op)
				return (EXIT_FAILURE);
			get_inst_code(op, LINE->bytecode);
			fprintf(stderr, "CONVERT loop 4a - bytecode = %s\n", LINE->bytecode);

			if (!(LINE->tokens->next))
				return (EXIT_FAILURE);
			fprintf(stderr, "CONVERT loop 4b\n");
			token = (t_token *)(LINE->tokens->next->content);
			fprintf(stderr, "CONVERT loop 5\n");
			if (op->has_pcode)
				get_pcode(LINE->tokens->next, LINE->bytecode);
			fprintf(stderr, "CONVERT loop 6 - bytecode = %s\n", LINE->bytecode);

			//refiler file->lines to get label values
			translate_params(LINE->tokens, LINE->nb_param, LINE->bytecode,
				op->has_pcode);
			fprintf(stderr, "CONVERT loop 7\n");
		}
		tmp = tmp->next;
	}
	fprintf(stderr, "CONVERT1\n");
	return (EXIT_SUCCESS);
}
