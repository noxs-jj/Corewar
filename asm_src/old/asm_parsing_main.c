/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeage <fdeage@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/12 17:08:19 by fdeage            #+#    #+#             */
/*   Updated: 2015/02/12 17:08:34 by fdeage           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "libft.h"

void	push_eol_end(t_list *root, char c, int nb_line)
{
	t_line	*eol;

	if (!(eol = (t_line *)malloc(sizeof(t_line))))
		exit(EXIT_FAILURE);
	eol->str = " ";
	eol->code = 0;
	if (c == '\n')
		eol->type = "endline    ";
	else if (c == 0)
		eol->type = "END        ";
	else if (c == 'p')
		eol->type = "param_code ";
	eol->line = nb_line;
	list_pushback(root, eol);
}

void	parse_file_tests(t_list *root, char *line, t_line *new, int nb_line)
{
	new->line = nb_line;
	if (line[0] == COMMENT_CHAR || line[0] == COMMENT_CHAR2)
	{
		free(new);
		free(line);
		return ;
	}
	else if (ft_strcmp(NCS, ft_strtrunc(line, ft_strlen(NCS))) == 0)
	{
		new->str = ft_strdup(get_name_comment(line));
		new->type = ".name      ";
		list_pushback(root, new);
	}
	else if (ft_strcmp(CCS, ft_strtrunc(line, ft_strlen(CCS))) == 0)
	{
		new->str = ft_strdup(get_name_comment(line));
		new->type = ".comment   ";
		list_pushback(root, new);
	}
	else
		get_others(root, line, new, nb_line);
}

void	parse_file(t_list *root, int fd_file)
{
	char	*line;
	t_line	*new;
	int		nb_line;

	nb_line = 1;
	while (get_next_line(fd_file, &line))
	{
		if (!(new = (t_line *)malloc(sizeof(t_line))))
			exit(EXIT_FAILURE);
		if (ft_strcmp(line, "") == 0)
		{
			free(line);
			free(new);
			continue ;
		}
		parse_file_tests(root, line, new, nb_line);
		free(line);
		push_eol_end(root, '\n', nb_line);
		nb_line++;
	}
	push_eol_end(root, '\0', nb_line);
}

void	get_others(t_list *root, char *line, t_line *new, int nb_line)
{
	char	**par;

	while (line)
	{
		if (!(new = (t_line *)malloc(sizeof(t_line))))
			exit(EXIT_FAILURE);
		if ((new->str = get_label(&line)))
		{
			new->type = "label      ";
			new->line = nb_line;
			list_pushback(root, new);
			continue ;
		}
		else
		{
			new->str = get_cmd(&line);
			new->type = "instruction";
			new->line = nb_line;
			list_pushback(root, new);
			push_eol_end(root, 'p', nb_line);
			par = ft_strsplit(line, SEPARATOR_CHAR);
			get_args(root, par, new, nb_line);
			return ;
		}
	}
}
