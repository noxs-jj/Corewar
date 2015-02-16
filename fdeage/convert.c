/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeage <fdeage@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/13 17:30:01 by fdeage            #+#    #+#             */
/*   Updated: 2015/02/16 15:55:33 by fdeage           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
** converts tokens into bytecode
*/

/*
//virer
static void print_token(t_list *tmp)
{
	fprintf(stderr, "  token #%d - %s", (int)TOKEN->id, TOKEN->data);
	if (TOKEN->op)
		fprintf(stderr, "  - op = %d\n", TOKEN->op->opcode);
	else
		fprintf(stderr, "\n");
}
*/

static void	translate_params(t_list *tokens)
{
	(void)tokens;
	return ;
}

static void	get_pcode(t_list *tokens)
{
	t_list	*tmp;
	char	pcode[8];
	int		i;
	//t_token	*token[3];

	ft_bzero(pcode, 8);
	i = 0;
	tmp = tokens;
	while (tmp)
	{
		//	TOKEN->












		tmp = tmp->next;
	}
	return ;
}

static void	get_inst_code(t_op *op, char *bytecode)
{
	char	tab[5];

	ft_bzero(tab, 5);
	ft_itoatab(op->opcode, tab);
	fprintf(stderr, "INST code = %s\n", tab);
	ft_strncpy(bytecode, tab, 2);
}

int			convert_file(t_file *file)
{
	t_list	*tmp;
	t_token	*token;

	fprintf(stderr, "CONVERT0\n");
	tmp = file->lines;
	while (tmp)
	{
		fprintf(stderr, "CONVERT loop - %s - type: %d\n", LINE->str, LINE->type);
		if (LINE->type != T_COMMENT && LINE->tokens)
		{
			fprintf(stderr, "CONVERT loop 2 - %p\n", LINE->tokens);
			token = (t_token *)(LINE->tokens->content);
			fprintf(stderr, "CONVERT loop 3\n");
			get_inst_code(token->op, LINE->bytecode);
			fprintf(stderr, "CONVERT loop 4\n");

			if (token->op->has_pcode)
				get_pcode(LINE->tokens);
			fprintf(stderr, "CONVERT loop 5\n");

			translate_params(LINE->tokens);
			fprintf(stderr, "CONVERT loop 6\n");
		}
		tmp = tmp->next;
	}
	fprintf(stderr, "CONVERT1\n");
	return (EXIT_SUCCESS);
}
