/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeage <fdeage@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/12 16:17:22 by fdeage            #+#    #+#             */
/*   Updated: 2015/02/12 17:32:48 by fdeage           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "asm.h"

static void	free_lines(t_file *file)
{
    t_list  *tmp;
    t_list  *next;

    tmp = file->lines;
    while (tmp)
    {
        next = tmp->next;
        free(LINE->str);
        free(LINE);
        tmp = next;
    }
}

void        exit_asm(t_file *file)
{
    ft_putstr_color("TRY EXITING... ", COL_LIGHT_GREEN);
    free_lines(file);
    close(file->fd_s);
    close(file->fd_cor);
	free(file->name_s);
	free(file->name_cor);
	if (file->champ_name)
		free(file->champ_name);
	if (file->comment)
		free(file->comment);
    free(file);
    ft_putstr_color("SUCCESSFUL EXIT!\n", COL_GREEN);
    exit(EXIT_SUCCESS);
}
