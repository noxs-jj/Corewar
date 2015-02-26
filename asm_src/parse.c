/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeage <fdeage@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/12 17:08:19 by fdeage            #+#    #+#             */
/*   Updated: 2015/02/26 19:47:22 by fdeage           ###   ########.fr       */
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

//TODO - 26L
static void	get_line_code_len(t_line *line)
{
	t_list	*tmp;
	t_op	*op;

	if (!(tmp = line->tokens))
		return ;
	op = TOKEN->op;
	line->code_len = 1;
	fprintf(stderr, "getlinecode2 - type = %d\n", TOKEN->type);
	if (TOKEN->type == T_CMD_NAME || TOKEN->type == T_CMD_COMMENT
		|| TOKEN->type == T_COMMENT)
		return ;
	if (op && op->has_pcode)
		(line->code_len)++;
	while (tmp)
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
	fprintf(stderr, "code len = %d\n", (int)line->code_len);
}

//OK - 24L
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
		//fprintf(stderr, "TEST4b - name detected\n");
		file->has_name = 1;
		line->type = T_CMD_NAME;
		name_begin = ft_strlen(NAME_CMD_STRING);
		while (s && s[name_begin] && s[name_begin] != '"')
			++name_begin;
		++name_begin;
		name_end = name_begin;
		while (s && s[name_end] && s[name_end] != '"')
			++name_end;
		//fprintf(stderr, "TEST4ba - beg: %d end: %d\n", name_begin, name_end);
		ft_strncpy(file->header.prog_name, (const char *)s + name_begin,
			name_end - name_begin);
	}
	return ;
}

//OK - 24L
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
		//fprintf(stderr, "TEST4d - comment detected\n");
		line->type = T_CMD_COMMENT;
		name_begin = ft_strlen(COMMENT_CMD_STRING);
		while (s && s[name_begin] && s[name_begin] != '"')
			++name_begin;
		++name_begin;
		name_end = name_begin;
		while (s && s[name_end] && s[name_end] != '"')
			++name_end;
		//fprintf(stderr, "TEST4e - beg: %d end: %d\n", name_begin, name_end);
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
	if ((line->str)[i] == COMMENT_CHAR || (line->str)[i] == FINAL_COMMENT_CHAR)
	{
		line->type = T_COMMENT;
		return (true);
	}
	return (false);
}

//OK - 23L
int			parse_file(t_file *file)
{
	t_list	*tmp;

	tmp = file->lines;
	while (tmp)
	{
		//fprintf(stderr, "PARSE s=%s\n", LINE->str);
		if (!is_comment(LINE))
		{
			if (LINE->type != T_LABEL)
				LINE->type = T_EXEC;
			if (!(file->header.prog_name[0]))
				check_name(file, LINE);
			if (!(file->header.comment[0]))
				check_comment(file, LINE);
			fprintf(stderr, "\n\n--------------------------------------------------------------------------------------------\nLINE #%d -- str: |%s|    --  type: %d\n--------------------------------------------------------------------------------------------\n", (int)LINE->id, LINE->str, LINE->type);
			if ((LINE->type == T_EXEC) && ((tokenize_line(LINE) == EXIT_FAILURE)
				|| (!has_right_params(LINE))))
				return (EXIT_FAILURE);
			if (LINE->type == T_LABEL)
				(LINE->str)[ft_strpos(LINE->str, LABEL_CHAR)] = 0;
			else //?
				get_line_code_len(LINE);
		}
		tmp = tmp->next;
	}
	if (!file->has_name)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
