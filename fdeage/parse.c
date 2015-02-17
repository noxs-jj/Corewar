/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeage <fdeage@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/12 17:08:19 by fdeage            #+#    #+#             */
/*   Updated: 2015/02/17 19:10:33 by fdeage           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "asm_fn.h"
#include "libft.h"


//TODO: check if params are legit at the same time!
static void	get_line_code_len(t_line *line)
{
	t_list	*tmp;

	if (!(tmp = line->tokens))
		return ;
	line->code_len = 1;
	fprintf(stderr, "getlinecode2 - type = %d\n", TOKEN->type);
	if (TOKEN->type == T_CMD_NAME || TOKEN->type == T_CMD_COMMENT
		|| TOKEN->type == T_COMMENT)
		return ;
	if (TOKEN->op && TOKEN->op->has_pcode)
		(line->code_len)++;
	while (tmp)
	{
		if (TOKEN->type == T_A_DIR || TOKEN->type == T_A_DLAB)
			line->code_len += T_DIR_LEN;
		else if (TOKEN->type == T_A_IND)
			line->code_len += T_IND_LEN;
		else if (TOKEN->type == T_A_REG)
			line->code_len += T_REG_LEN;
		tmp = tmp->next;
	}
	fprintf(stderr, "code len = %d\n", (int)line->code_len);
}

# define T_DIR_LEN          4
# define T_DLAB_LEN         4
# define T_IND_LEN          2
# define T_REG_LEN          1

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
	if ((line->str)[i] == COMMENT_CHAR || (line->str)[i] == COMMENT_CHAR2
		|| (line->str)[i] == COMMENT_CHAR3)
	{
		line->type = T_COMMENT;
		return (true);
	}
	return (false);
}

//OK - 20L
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
			fprintf(stderr, "\n\n--------------------------------------------------------------------------------------------\nLINE #%d -- str: |%s|    --  type: %d\n--------------------------------------------------------------------------------------------\n", (int)LINE->id, LINE->str, LINE->type);
			if (LINE->type == T_EXEC
				&& tokenize_line(file, LINE) == EXIT_FAILURE)
				return (EXIT_FAILURE);
			//if LINE->type == T_EXEC then
			get_line_code_len(LINE);
		}
		tmp = tmp->next;
	}
	return (EXIT_SUCCESS);
}
