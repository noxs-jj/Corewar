/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_parsing_fn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeage <fdeage@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/01 17:16:03 by fdeage            #+#    #+#             */
/*   Updated: 2014/02/02 23:19:35 by fdeage           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

char	*get_name_comment(char *line)
{
	int		i;

	while (*line && *line != '"')
		line++;
	line++;
	i = 0;
	while (line[i] && line[i] != '"')
		++i;
	line[i] = '\0';
	return (line);
}

char	*get_label(char **line)
{
	int		i;
	char	*label;

	label = ft_getfirststr(*line);
	i = 0;
	while (label[i + 1])
		++i;
	if (label[i] == LABEL_CHAR)
	{
		*line += ft_strlen(label);
		return (label);
	}
	else
	{
		free(label);
		return (NULL);
	}
}

char	*get_cmd(char **line)
{
	int		i;
	char	*cmd;

	i = 0;
	while (**line && (**line == SPC_CHAR || **line == TAB_CHAR))
		(*line)++;
	cmd = ft_getfirststr(*line);
	i = 0;
	while (cmd[i + 1])
		++i;
	if (cmd[i] != SPC_CHAR && cmd[i] != TAB_CHAR && cmd[i] != LABEL_CHAR)
	{
		*line += ft_strlen(cmd);
		return (cmd);
	}
	else
	{
		free(cmd);
		return (NULL);
	}
}

void	get_args(t_list *root, char **par, t_line *new, int nb_line)
{
	int	i;

	i = 0;
	while (par[i])
	{
		if (!(new = (t_line *)malloc(sizeof(t_line))))
			exit(EXIT_FAILURE);
		par[i] = ft_strtrim(par[i]);
		if (par[i][0] == 'r')
			new->type = "T_REG      ";
		else if (par[i][0] == DIRECT_CHAR)
		{
			if (par[i][1] == LABEL_CHAR)
				new->type = "T_DIR_LABEL";
			else
				new->type = "T_DIR      ";
		}
		else
			new->type = "T_IND      ";
		new->str = par[i];
		new->line = nb_line;
		list_pushback(root, new);
		++i;
	}
}

