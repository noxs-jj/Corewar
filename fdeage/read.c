/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeage <fdeage@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/27 13:44:48 by fdeage            #+#    #+#             */
/*   Updated: 2015/02/12 17:31:30 by fdeage           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "asm.h"
#include "libft.h"

static int	add_line(t_file *file, char *str, int i)
{
	t_line	*line;

	line = NULL;
	if (!(line = (t_line *)malloc(sizeof(t_line))))
		return (-1);
	line->nb = i;
	line->str = ft_strdup(str);
	line->bytecode = NULL;
//	line->type = 0;
	ft_bzero(line->param, sizeof(int) * 4);
	ft_bzero(line->param_types, sizeof(int) * 4);
	ft_lstadd_back(&(file->lines), ft_lstnew((void *)line, sizeof(t_line)));
	free(line);
	return (0);
}

int			read_file(t_file *file)
{
	int		i;
	char	*str;

	str = NULL;
	file->lines = NULL;
	i = 0;
	while ((file->ret = get_next_line(file->fd_s, &str)) > 0 || *str)
	{
		if (str && !(*str))
		{
			free(str);
			continue;
		}
		if (add_line(file, str, i))
			return (-1);
		free(str);
		++i;
	}
	if (file->ret == -1)
		return (-1);
	free(str);
	file->nb_line = i;
	if (i == 0)
		return (-1);
	return (0);
}