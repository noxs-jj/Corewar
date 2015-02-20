/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeage <fdeage@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/14 18:53:07 by fdeage            #+#    #+#             */
/*   Updated: 2015/02/20 17:52:26 by fdeage           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "asm_fn.h"

extern t_op	g_op_tab[17];

//virer
static void print_token(t_token *token)
{
	//return ;
	fprintf(stderr, "\n---------------------\ntoken #%d  -  type %d\n", (int)token->id, token->type);
	fprintf(stderr, "col. %d\n", (int)token->col);
	if (token->op)
		fprintf(stderr, "str: |%s|  ->  opcode %d\n---------------------\n", token->str, token->op->opcode);
	else
		fprintf(stderr, "str: |%s|\n---------------------\n", token->str);
}

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
	return (EXIT_FAILURE);
}

static int	check_label(char *s)
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

//TODO: check label chars in a separate file/function
static int	get_token_type(t_token *token)
{
	size_t	len;

	len = ft_strlen(token->str);
	if (token->id == 0)
	{
		if ((token->str)[len - 1] == LABEL_CHAR)
		{
			token->type = T_LABEL;
			//separate function
			if (check_label(token->str) == EXIT_FAILURE)
				RET("Wrong chars used in label.\n", EXIT_FAILURE);
		}
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
	else if ((token->str)[0] == FINAL_COMMENT_CHAR)
		token->type = T_F_COMMENT;
	else
		token->type = T_A_IND;
	return (EXIT_SUCCESS);
}

//OK - 23L
static int	add_token(t_line *line, int i, int j, int id)
{
	t_token			*token;

	//fprintf(stderr, "add_token() begin.\n");
	if (!(token = (t_token *)malloc(sizeof(t_token))))
		RET("Malloc() failed.\n", EXIT_FAILURE);
	if (!(token->str = (char *)malloc(sizeof(char) * (j - i + 1))))
		RET("Malloc() failed.\n", EXIT_FAILURE);
	ft_strncpy(token->str,  &(line->str[i]), j - i);
	token->op = NULL;
	token->str[j - i] = 0;
	token->id = id;
	token->col = i;
	token->value = -1;
	token->type = T_UNKNOWN;
	if (get_token_type(token) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (token->type == T_UNKNOWN)
		RET("No token type found.\n", EXIT_FAILURE);
	if (token->type == T_INSTRUCTION && get_inst(token) == EXIT_FAILURE)
		RET("No matching opcode for the instruction.\n", EXIT_FAILURE);
	if (token->type == T_COMMENT)
		line->has_final_comment = 1;
	print_token(token);
	ft_lstadd_back(&(line->tokens), ft_lstnew((void *)token, sizeof(t_token)));
	free(token);
	return (EXIT_SUCCESS);
}

//OK - 24L - file solely needed for error report

//TODO: if last is comment
int				tokenize_line(t_line *line)
{
	register size_t	i;
	register size_t	j;
	size_t			token_id;

	//fprintf(stderr, "tokenize begin\n");
	i = 0;
	token_id = 0;
	while (token_id < 7 && !has_final_comment(line))
	{
		if (token_id - line->has_final_comment == 6)
			RET("Too many tokens in line.\n", EXIT_FAILURE);
		while (line->str[i] && ft_isspace(line->str[i]))
			++i;
		j = i;
		while (line->str[j] && !ft_isspace(line->str[j])
			&& line->str[j] != SEPARATOR_CHAR)
			++j;
		if (add_token(line, i, j, token_id) == EXIT_FAILURE)
			RET("Init_token() failed.\n", EXIT_FAILURE);
		i = j + 1;
		if (!line->str[i - 1])
			break ;
		++token_id;
	}
	line->nb_param = token_id - 1;
	fprintf(stderr, "tokenize end\n");
	return (EXIT_SUCCESS);
}
