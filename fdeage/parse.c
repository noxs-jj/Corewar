/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeage <fdeage@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/12 17:08:19 by fdeage            #+#    #+#             */
/*   Updated: 2015/02/14 19:24:16 by fdeage           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "asm_fn.h"
#include "libft.h"

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
		line->type = T_NAME;
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
		line->type = T_INIT_COMMENT;
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
	while (line->str && line->str[i] && ft_isspace(line->str[i]))
		++i;
	if (line->str[i] == COMMENT_CHAR || line->str[i] == COMMENT_CHAR2
		|| line->str[i] == COMMENT_CHAR3)
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
			LINE->type = T_INST;
			if (!(file->header.prog_name[0]))
				check_name(file, LINE);
			//fprintf(stderr, "TEST4a - name: %s\n", file->header.prog_name);
			if (!(file->header.comment[0]))
				check_comment(file, LINE);
			//fprintf(stderr, "TEST4c - comment: %s\n", file->header.comment);
			tokenize_line(file, LINE);
		}
		tmp = tmp->next;
	}
	return (EXIT_SUCCESS);
}
