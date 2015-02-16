/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeage <fdeage@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/13 17:30:01 by fdeage            #+#    #+#             */
/*   Updated: 2015/02/16 21:18:26 by fdeage           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
static void	char_to_hex(unsigned char n, int print_all, char *tab)
{
	unsigned int    g;
	unsigned int    d;
	int				shift;

	g = n / 16;
	d = n - (g * 16);
	shift = 0;
	if (g >= 10)
	{
		tab[0] = g + 87;
		shift++;
	}
	else if (print_all == 1 || g > 0)
	{
		tab[0] = g + '0';
		shift++;
	}
	if (d >= 10)
		tab[shift] = d + 87;
	else
		tab[shift] = d + '0';
}
*/

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

/*
static void	get_pcode(t_list *tokens, char *bytecode)
{
	t_list	*tmp;
	char	pcode[9];
	uint8_t	pcode2;
	int		i;

	ft_memset(pcode, '0', 8);
	pcode[8] = 0;
	i = 0;
	tmp = tokens;
	while (tmp)
	{
		fprintf(stderr, "data = %s type = %d\n", TOKEN->data, TOKEN->type);
		if (TOKEN->type == T_A_DLAB || TOKEN->type == T_A_DIR || TOKEN->type == T_A_IND)
			pcode[i + 0] = '1';
		if (TOKEN->type == T_A_REG || TOKEN->type == T_A_IND)
			pcode[i + 1] = '1';
		i += 2;
		tmp = tmp->next;
	}
	fprintf(stderr, "pcode = %s\n", pcode);
	pcode2 = 0;
	i = 7;
	while (i >= 0)
	{
		fprintf(stderr, "c1=%d\n", pcode[7 - i]);
		fprintf(stderr, "c2=%u\n", (pcode[7 - i] - '0') << i);
		fprintf(stderr, "c3=%u\n\n", 1 << i);
		pcode2 |= ((pcode[7 - i] - '0') << i);
		--i;
	}
	fprintf(stderr, "pcode char c=%c=%d\n", pcode2, pcode2);
	bytecode[1] = pcode2;
	return ;
}
*/


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

			translate_params(LINE->tokens);
			fprintf(stderr, "CONVERT loop 7\n");
		}
		tmp = tmp->next;
	}
	fprintf(stderr, "CONVERT1\n");
	return (EXIT_SUCCESS);
}
