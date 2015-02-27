/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeage <fdeage@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/12 17:08:19 by fdeage            #+#    #+#             */
/*   Updated: 2015/02/27 14:39:14 by fdeage           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "asm_fn.h"
#include "libft.h"

/*
**  - get_line_code_len() get the line length once translated into bytecode;
**  this is needed later when preprocessing the %:label arguments
**  - check_name() and check_comment() just look for the .name and .comment
** lines, remove the '"' and save them;
** - in the main parse_file() function, the label lines lose their final ':' to
** ease further comparisons with the labels of tokens in the middle
*/

static void	get_line_code_len(t_line *line)
{
	t_list	*tmp;
	t_op	*op;

	if (!(tmp = line->tokens))
		return ;
	op = TOKEN->op;
	line->code_len = 1;
	if (TOKEN->type == T_CMD_NAME || TOKEN->type == T_CMD_COMMENT
		|| TOKEN->type == T_COMMENT)
		return ;
	if (op && op->has_pcode)
		(line->code_len)++;
	while (tmp && op)
	{
		if (TOKEN->type == T_A_DIR && !(op->has_idx))
			line->code_len += T_DIR_LEN;
		else if (TOKEN->type == T_A_DLAB
			|| (TOKEN->type == T_A_DIR && op->has_idx))
			line->code_len += T_DLAB_LEN;
		else if (TOKEN->type == T_A_IND || TOKEN->type == T_A_INDLAB)
			line->code_len += T_IND_LEN;
		else if (TOKEN->type == T_A_REG)
			line->code_len += T_REG_LEN;
		tmp = tmp->next;
	}
}

static void	check_name(t_file *file, t_line *line)
{
	char	*s;
	int		name_begin;
	int		name_end;
	int		blank;

	blank = 0;
	while (ft_isspace((line->str)[blank]))
		++blank;
	s = line->str + blank;
	if (ft_strncmp(s, NAME_CMD_STRING, ft_strlen(NAME_CMD_STRING)) == 0)
	{
		file->has_name = 1;
		line->type = T_CMD_NAME;
		name_begin = ft_strlen(NAME_CMD_STRING);
		while (s && s[name_begin] && s[name_begin] != '"')
			++name_begin;
		++name_begin;
		name_end = name_begin;
		while (s && s[name_end] && s[name_end] != '"')
			++name_end;
		ft_strncpy(file->header.prog_name, (const char *)s + name_begin,
			name_end - name_begin);
	}
	return ;
}

static void	check_comment(t_file *file, t_line *line)
{
	char	*s;
	int		name_begin;
	int		name_end;
	int		blank;

	blank = 0;
	while (ft_isspace((line->str)[blank]))
		++blank;
	s = line->str + blank;
	if (ft_strncmp(s, COMMENT_CMD_STRING,
		ft_strlen(COMMENT_CMD_STRING)) == 0)
	{
		line->type = T_CMD_COMMENT;
		name_begin = ft_strlen(COMMENT_CMD_STRING);
		while (s && s[name_begin] && s[name_begin] != '"')
			++name_begin;
		++name_begin;
		name_end = name_begin;
		while (s && s[name_end] && s[name_end] != '"')
			++name_end;
		ft_strncpy(file->header.comment, (const char *)s + name_begin,
			name_end - name_begin);
	}
	return ;
}

static int	is_comment(t_line *line)
{
	register size_t	i;

	i = 0;
	while (line->str && (line->str)[i] && ft_isspace((line->str)[i]))
		++i;
	if ((line->str)[i] == COMMENT_CHAR)
	{
		line->type = T_COMMENT;
		return (true);
	}
	return (false);
}

int			parse_file(t_file *file)
{
	t_list	*tmp;

	tmp = file->lines;
	while (tmp)
	{
		if (!is_comment(LINE))
		{
			if (LINE->type != T_LABEL)
				LINE->type = T_EXEC;
			if (!(file->header.prog_name[0]))
				check_name(file, LINE);
			if (!(file->header.comment[0]))
				check_comment(file, LINE);
			if ((LINE->type == T_EXEC) && ((tokenize_line(LINE) == EXIT_FAILURE)
				|| (!has_right_params(LINE))))
				RET("Parsing failure.\n", EXIT_FAILURE);
			if (LINE->type == T_LABEL)
				(LINE->str)[ft_strpos(LINE->str, LABEL_CHAR)] = 0;
			else
				get_line_code_len(LINE);
		}
		tmp = tmp->next;
	}
	return (EXIT_SUCCESS);
}
