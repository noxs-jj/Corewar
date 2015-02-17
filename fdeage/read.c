/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeage <fdeage@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/27 13:44:48 by fdeage            #+#    #+#             */
/*   Updated: 2015/02/17 18:55:42 by fdeage           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "asm.h"
#include "libft.h"

static int	init_line(t_file *file, char *str, size_t i, int line_type)
{
	t_line	*line;

	if (!(line = (t_line *)malloc(sizeof(t_line))))
		return (EXIT_FAILURE);
	line->id = i;
	line->str = ft_strdup(str);
	line->code_len = 0;
	//line->str_len = ft_strlen(line->str);
	line->type = line_type;
	line->nb_param = -1;
	line->tokens = NULL;
	line->pcode = -1;
	ft_bzero(line->bytecode, 20);
	ft_lstadd_back(&(file->lines), ft_lstnew((void *)line, sizeof(t_line)));
	free(line);
	return (EXIT_SUCCESS);
}

static int	has_label(char *str)
{
	register int	i;

	i = 0;
	while (str[i] && ft_isspace(str[i]))
		++i;
	while (str[i] && !ft_isspace(str[i]) && str[i] != SEPARATOR_CHAR)
		++i;
	--i;
	if (str[i] == LABEL_CHAR)
		return (i);
	return (0);
}

static int	add_line(t_file *file, char *str, size_t *i, int has_label)
{
	if (has_label)
	{
		//add label line
		str[has_label + 1] = 0;
		if (init_line(file, str, *i, T_LABEL) == EXIT_FAILURE)
			RET("Init_line() failed.\n", EXIT_FAILURE);
		str[has_label + 1] = ' ';
		(*i)++;
		init_line(file, str + has_label + 1, *i, 0);
	}
	else
	{
		//add regular line
		if (init_line(file, str, *i, T_UNKNOWN) == EXIT_FAILURE)
			RET("Init_line() failed.\n", EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

//OK - 25L
int			read_file(t_file *file)
{
	size_t	i;
	char	*str;

	//fprintf(stderr, "TEST2a\n");
	str = NULL;
	file->lines = NULL;
	i = 0;
	while ((file->ret = get_next_line(file->fd_s, &str)) > 0 || *str)
	{
		if (str && !(*str))
		{
			free(str);
			continue ;
		}
		//fprintf(stderr, "TEST2b - i=%d\n", i);
		if (add_line(file, str, &i, has_label(str)))
			return (EXIT_FAILURE);
		free(str);
		++i;
	}
	//fprintf(stderr, "TEST2c\n");
	if (file->ret == -1)
		return (EXIT_FAILURE);
	free(str);
	file->nb_line = i;
	if (i == 0)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
