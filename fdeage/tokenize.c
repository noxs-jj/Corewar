/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeage <fdeage@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/14 18:53:07 by fdeage            #+#    #+#             */
/*   Updated: 2015/02/14 22:13:18 by fdeage           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

//extern t_op	g_op_tab[17];

//virer
void print_token(t_token *token)
{
	fprintf(stderr, "\n---------------------\ntoken #%d  -  type %d\n", token->id, token->type);
	fprintf(stderr, "l. %d, col. %d\n", token->line, token->col);
	if (token->op)
		fprintf(stderr, "str: |%s|  ->  opcode %d\n---------------------\n", token->data, token->op->opcode);
	else
		fprintf(stderr, "str: |%s|\n---------------------\n", token->data);
}

static int		get_inst(t_token *token)
{
    register size_t	i;

	fprintf(stderr, "get_instruction begin - data=%s\n", token->data);
    i = 0;
    while (i < 16)
    {
		fprintf(stderr, "before strcmp\n");
		if (!ft_strcmp(token->data, (g_op_tab[i]).name))
		{
			fprintf(stderr, "in strcmp\n");
			if (!(token->op = (t_op *)malloc(sizeof(t_op))))
				RET("Malloc() failed.\n", EXIT_FAILURE);
			ft_memcpy((void *)token->op, (void *)&(g_op_tab[i]), sizeof(t_op));
			return (EXIT_SUCCESS);
		}
		fprintf(stderr, "after strcmp\n");
        ++i;
    }
	fprintf(stderr, "get_instruction end\n");
    return (EXIT_FAILURE);
}

static int		check_label(char *s)
{
	register size_t	i;
	char			*check;

	check = LABEL_CHARS;
	i = 0;
	while (s[i] && s[i] != LABEL_CHAR)
	{
		if (!ft_strchr(check, s[i]))
			return (EXIT_FAILURE);
		++i;
	}
	return (EXIT_SUCCESS);
}

static int		get_token_type(t_token *token)
{
	size_t	len;

	len = ft_strlen(token->data);
	if (token->id == 0)
	{
		if ((token->data)[len - 1] == LABEL_CHAR)
		{
			token->type = T_LABEL;
			if (check_label(token->data) == EXIT_FAILURE)
				RET("Wrong chars used in label.\n", EXIT_FAILURE);
		}
		else
			token->type = T_INSTRUCTION;
	}
	else if ((token->data)[0] == DIRECT_CHAR)
	{
		if ((token->data)[1] == LABEL_CHAR)
			token->type = T_DIRECT_LABEL;
		else
			token->type = T_DIRECT;
	}
	else if ((token->data)[0] == REGISTER_CHAR)
		token->type = T_REGISTER;
	else
		token->type = T_INDIRECT;
	return (EXIT_SUCCESS);
}

//OK - 23L
static t_token	*init_token(char *data, int i, int j, int id)
{
	t_token			*token;

	fprintf(stderr, "init token begin.\n");
	if (!(token = (t_token *)malloc(sizeof(t_token))))
		RET("Malloc() failed.\n", NULL);
	if (!(token->data = (char *)malloc(sizeof(char) * (j - i + 1))))
		RET("Malloc() failed.\n", NULL);
	ft_strncpy(token->data,  &(data[i]), j - i);
	token->data[j - i] = 0;
	token->id = id;
	token->col = i;
	token->op = NULL;
	token->type = T_UNKNOWN;
	if (get_token_type(token) == EXIT_FAILURE)
		return (NULL);
	if (token->type == T_UNKNOWN)
		RET("No token type found.\n", NULL);
	print_token(token);
	if (token->type == T_INSTRUCTION)
	{
		if (get_inst(token) == EXIT_FAILURE)
		RET("No matching opcode for the instruction.\n", NULL);
	}
	fprintf(stderr, "init token end.\n");
	return (token);
}

//OK - 24L
int				tokenize_line(t_file *file, t_line *line)
{
	register size_t	i;
	register size_t	j;
	size_t			token_id;
	t_token			*token;

	fprintf(stderr, "tokenize begin\n");
	i = 0;
	token_id = 0;
	token = NULL;
	//7 is a mistake: too many tokens
	while (token_id < 7)
	{
		if (token_id == 6)
			RET("Too many tokens in line.\n", EXIT_FAILURE);
		while (line->str[i] && ft_isspace(line->str[i]))
			++i;
		//fprintf(stderr, "i=%d s=|%s|\n", (int)i, &(line->str[i]));
		j = i;
		while (line->str[j] && !ft_isspace(line->str[j]) && line->str[j] != SEPARATOR_CHAR)
			++j;
		fprintf(stderr, "test1\n");
		//if token exists
		if (!(token = init_token(line->str, i, j, (token ? token_id - 1 : token_id))))
			RET("Init_token() failed.\n", EXIT_FAILURE);
		fprintf(stderr, "test2\n");
		token->line = line->id;
		//push_token ! memleaks
		ft_lstadd_back(&(line->tokens), ft_lstnew((void *)token, sizeof(t_token));
		//print_token(token);
		//token = NULL;
		i = j + 1;
		if (!line->str[i - 1])
			break ;
		//++i;
		//fprintf(stderr, "i=%d j=%d s=|%s|\n", (int)i, (int)j, &(line->str[i]));
		++token_id;
	}
	(void)file;
	fprintf(stderr, "tokenize end\n");
	return (EXIT_SUCCESS);
}
