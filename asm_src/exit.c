/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeage <fdeage@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/12 16:17:22 by fdeage            #+#    #+#             */
/*   Updated: 2015/02/28 17:19:17 by fdeage           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "asm.h"

/*
** exit_asm() doesn't exit itself but returns to the main
*/

static void	free_token_list(t_list *tokens)
{
	t_list	*tmp;
	t_list	*next;

	tmp = tokens;
	while (tmp)
	{
		next = tmp->next;
		free(TOKEN->str);
		if (TOKEN->op)
			free(TOKEN->op);
		free(TOKEN);
		free(tmp);
		tmp = next;
	}
}

static void	free_lines(t_file *file)
{
	t_list	*tmp;
	t_list	*next;

	tmp = file->lines;
	while (tmp)
	{
		next = tmp->next;
		if (LINE->str)
			free(LINE->str);
		free_token_list(LINE->tokens);
		free(LINE);
		free(tmp);
		tmp = next;
	}
}

int			exit_asm(t_file *file)
{
	int	leaks;

	ft_putstr_color("TRY EXITING... ", COL_GREEN);
	free_lines(file);
	close(file->fd_s);
	close(file->fd_cor);
	if (file->name_s)
		free(file->name_s);
	if (file->name_cor)
		free(file->name_cor);
	leaks = file->options;
	free(file);
	ft_putstr_color("SUCCESSFUL EXIT!\n", COL_GREEN);
	if ((leaks & T_OPTION_LEAKS) == T_OPTION_LEAKS)
	{
		ft_putstr_color("Leaks mode activated...\n", COL_YELLOW);
		while (42)
			usleep(10000);
	}
	return (EXIT_SUCCESS);
}
