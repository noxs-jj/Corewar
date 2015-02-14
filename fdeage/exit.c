/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeage <fdeage@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/12 16:17:22 by fdeage            #+#    #+#             */
/*   Updated: 2015/02/14 18:30:13 by fdeage           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "asm.h"

/*
** exit_asm() doesn't exit itself but returns to the main
*/

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
		if (LINE->bytecode)
			free(LINE->bytecode);
		free(LINE);
		free(tmp);
		tmp = next;
	}
}

void		exit_asm(t_file *file)
{
	ft_putstr_color("TRY EXITING... ", COL_GREEN);
	free_lines(file);
	close(file->fd_s);
	close(file->fd_cor);
	if (file->name_s)
		free(file->name_s);
	if (file->name_cor)
		free(file->name_cor);
	free(file);
	ft_putstr_color("SUCCESSFUL EXIT!\n", COL_GREEN);
	return ;
}
