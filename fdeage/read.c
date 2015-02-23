/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeage <fdeage@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/27 13:44:48 by fdeage            #+#    #+#             */
/*   Updated: 2015/02/23 19:09:05 by fdeage           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "asm.h"
#include "asm_fn.h"
#include "libft.h"

static int	init_line(t_file *file, char *str, size_t i, int line_type)
{
	t_line	*line;

	//fprintf(stderr, "READINIT0=%s\n", str);
	if (!(line = (t_line *)malloc(sizeof(t_line))))
		return (EXIT_FAILURE);
	line->tokens = NULL;
	line->id = i;
	line->code_len = 0;
	line->str = ft_strtrim(str);
	line->nb_params = -1;
	line->type = line_type;
	line->has_final_comment = 0;
	ft_bzero(line->bytecode, 14);
	line->pcode = -1;
	ft_lstadd_back(&(file->lines), ft_lstnew((void *)line, sizeof(t_line)));
	//fprintf(stderr, "READ INIT=%s\n", line->str);
	free(line);
	return (EXIT_SUCCESS);
}

/*
** has_label() returns 0 if no ':' is found at the end of the token, else returns
** the position of it
*/

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

/*
** if the line is of the type 'label: inst', add_line() splits the line
** into two lines: 'label:' and 'inst'.
** WARNING: if no inst follows the label, then only adds the label!
*/

static int	add_line(t_file *file, char *str, size_t *i, int has_label)
{
	size_t	len;

	len = ft_strlen(str);
	if (has_label)
	{
		fprintf(stderr, "ADD LABEL: |%s| len=%d has_label=%d\n", str, (int)len, has_label);
		str[has_label + 1] = 0;
		fprintf(stderr, "has label READ INIT=%s\n", str);
		if (init_line(file, str, *i, T_LABEL) == EXIT_FAILURE)
			RET("Init_line() failed.\n", EXIT_FAILURE);
		str[has_label + 1] = ' ';
		//?
		(*i)++;
		if ((int)len != has_label + 1 && !is_only_whitespace(&(str[has_label + 2])))
		{
			fprintf(stderr, "ADD INST POST LABEL: |%s| len=%d has_label=%d - only whitespace = %d\n", &(str[has_label + 2]), (int)len, has_label, is_only_whitespace(&(str[has_label + 2])));
			init_line(file, str + has_label + 2, *i, 0);
		}
	}
	else
	{
		fprintf(stderr, "no label  READ INIT=%s\n", str);
		if (init_line(file, str, *i, T_UNKNOWN) == EXIT_FAILURE)
			RET("Init_line() failed.\n", EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

//OK - 24L
int			read_file(t_file *file)
{
	char	*str;
	size_t	i;

	str = NULL;
	i = 0;
	while ((file->ret = get_next_line(file->fd_s, &str)) > 0 || *str)
	{
		if (str && (!(*str) || is_only_whitespace(str)))
		{
			free(str);
			continue ;
		}
		fprintf(stderr, "READ s=%s\n", str);
		if (add_line(file, str, &i, has_label(str)))
			return (EXIT_FAILURE);
		free(str);
		++i;
	}
	if (file->ret == -1)
		return (EXIT_FAILURE);
	free(str);
	file->nb_line = i;
	if (i == 0)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
