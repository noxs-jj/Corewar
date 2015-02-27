/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeage <fdeage@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/14 18:53:07 by fdeage            #+#    #+#             */
/*   Updated: 2015/02/27 14:57:04 by fdeage           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "asm_fn.h"

extern t_op	g_op_tab[17];

static int	get_inst(t_token *token)
{
	register size_t	i;

	i = 0;
	while (i < 16)
	{
		if (!ft_strcmp(token->str, (g_op_tab[i]).name))
		{
			if (!(token->op = (t_op *)malloc(sizeof(t_op))))
				RET("Malloc() failed.\n", EXIT_FAILURE);
			ft_memcpy((void *)token->op, (void *)&(g_op_tab[i]), sizeof(t_op));
			return (EXIT_SUCCESS);
		}
		++i;
	}
	RET("Couldn't retrieve the instruction.\n", EXIT_FAILURE);
}

static int	get_token_type(t_token *token, size_t len)
{
	if (token->id == 0)
	{
		if ((token->str)[len - 1] == LABEL_CHAR)
			token->type = T_LABEL;
		else
			token->type = T_INSTRUCTION;
	}
	else if ((token->str)[0] == DIRECT_CHAR)
	{
		if ((token->str)[1] == LABEL_CHAR)
			token->type = T_A_DLAB;
		else
			token->type = T_A_DIR;
	}
	else if ((token->str)[0] == REGISTER_CHAR)
		token->type = T_A_REG;
	else if ((token->str)[0] == LABEL_CHAR)
		token->type = T_A_INDLAB;
	else if (ft_aredigits(token->str))
		token->type = T_A_IND;
	else
		RET("No type found for the token.\n", EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static int	add_token(t_line *line, int i, int j, int id)
{
	t_token			*token;

	if (!(token = (t_token *)malloc(sizeof(t_token))))
		RET("Malloc() failed.\n", EXIT_FAILURE);
	if (!(token->str = (char *)malloc(sizeof(char) * (j - i + 1))))
		RET("Malloc() failed.\n", EXIT_FAILURE);
	ft_strncpy(token->str, &(line->str[i]), j - i);
	token->op = NULL;
	token->str[j - i] = 0;
	token->id = id;
	token->value = -1;
	token->type = T_UNKNOWN;
	if (get_token_type(token, ft_strlen(token->str)) == EXIT_FAILURE)
		RET("Wrong token type.\n", EXIT_FAILURE);
	if (check_param(token, token->str))
		RET("Bad parameter.\n", EXIT_FAILURE);
	if (token->type == T_UNKNOWN)
		RET("No token type found.\n", EXIT_FAILURE);
	if (token->type == T_INSTRUCTION && get_inst(token) == EXIT_FAILURE)
		RET("No matching opcode for the instruction.\n", EXIT_FAILURE);
	ft_lstadd_back(&(line->tokens), ft_lstnew((void *)token, sizeof(t_token)));
	free(token);
	return (EXIT_SUCCESS);
}

int			tokenize_line(t_line *line)
{
	register size_t	i;
	register size_t	j;
	size_t			token_id;

	i = 0;
	token_id = 0;
	while (token_id < 7)
	{
		if (token_id == 6)
			RET("Too many tokens in line.\n", EXIT_FAILURE);
		while (line->str[i] && ft_isspace(line->str[i]))
			++i;
		j = i;
		while (line->str[j] && !ft_isspace(line->str[j])
			&& line->str[j] != SEPARATOR_CHAR)
			++j;
		if ((add_token(line, i, j, token_id)) == EXIT_FAILURE)
			RET("Init_token() failed.\n", EXIT_FAILURE);
		i = j + 1;
		if (!line->str[i - 1])
			break ;
		++token_id;
	}
	line->nb_params = token_id;
	return (EXIT_SUCCESS);
}
