/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeage <fdeage@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/12 17:08:19 by fdeage            #+#    #+#             */
/*   Updated: 2015/02/13 19:40:04 by fdeage           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "asm_fn.h"
#include "libft.h"

static void	check_name(t_file *file, t_list *tmp)
{
	char	*s;
	int		name_begin;
	int		name_end;
	int		blank;

	blank = 0;
	while (ft_isspace((LINE->str)[blank]))
		++blank;
	s = LINE->str + blank;
	if (ft_strncmp(s, NAME_CMD_STRING, ft_strlen(NAME_CMD_STRING)) == 0)
	{
		fprintf(stderr, "TEST4b - name detected\n");
		name_begin = ft_strlen(NAME_CMD_STRING);
		while (s && s[name_begin] && s[name_begin] != '"')
			++name_begin;
		++name_begin;
		name_end = name_begin;
		while (s && s[name_end] && s[name_end] != '"')
			++name_end;
		fprintf(stderr, "TEST4ba - beg: %d end: %d\n", name_begin, name_end);
		ft_strncpy(file->header.prog_name, (const char *)s + name_begin,
			name_end - name_begin);
	}
	return ;
}

static void	check_comment(t_file *file, t_list *tmp)
{
	char	*s;
	int		name_begin;
	int		name_end;
	int		blank;

	blank = 0;
	while (ft_isspace((LINE->str)[blank]))
		++blank;
	s = LINE->str + blank;
	if (ft_strncmp(s, COMMENT_CMD_STRING,
		ft_strlen(COMMENT_CMD_STRING)) == 0)
	{
		fprintf(stderr, "TEST4d - comment detected\n");
		LINE->type = T_INIT_COMMENT;
		name_begin = ft_strlen(COMMENT_CMD_STRING);
		while (s && s[name_begin] && s[name_begin] != '"')
			++name_begin;
		++name_begin;
		name_end = name_begin;
		while (s && s[name_end] && s[name_end] != '"')
			++name_end;
		fprintf(stderr, "TEST4e - beg: %d end: %d\n", name_begin, name_end);
		ft_strncpy(file->header.comment, (const char *)s + name_begin,
			name_end - name_begin);
	}
	return ;
}

static void	check_inst(t_file *file, t_list *tmp)
{
	(void)file;
	(void)tmp;
	return ;
}

int			parse_file(t_file *file)
{
	t_list	*tmp;

	tmp = file->lines;
	while (tmp)
	{
		if (!(file->header.prog_name[0]))
			check_name(file, tmp);
		fprintf(stderr, "TEST4a - name: %s\n", file->header.prog_name);
		if (!(file->header.comment[0]))
			check_comment(file, tmp);
		fprintf(stderr, "TEST4c - comment: %s\n", file->header.comment);
		check_inst(file, tmp);
		tmp = tmp->next;
	}
	return (1);
}
