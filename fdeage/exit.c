/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeage <fdeage@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/12 16:17:22 by fdeage            #+#    #+#             */
/*   Updated: 2015/02/13 17:28:26 by fdeage           ###   ########.fr       */
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
    t_list  *tmp;
    t_list  *next;

	int temp=0;

    tmp = file->lines;
    while (tmp)
    {
		tmp = next;
		fprintf(stderr, "i=%d s=%s\n", temp, LINE->str);
		if (LINE->str)
			free(LINE->str);
        free(LINE);
        next = next->next;
		temp++;
    }
}

void        exit_asm(t_file *file)
{
    ft_putstr_color("TRY EXITING... ", COL_LIGHT_GREEN);

	//while (42);
    free_lines(file);
    ft_putstr_color("TEST1", COL_LIGHT_GREEN);
    close(file->fd_s);
    close(file->fd_cor);
    ft_putstr_color("TEST2", COL_LIGHT_GREEN);
	if (file->name_s)
		free(file->name_s);
    ft_putstr_color("TEST3", COL_LIGHT_GREEN);
	if (file->name_cor)
		free(file->name_cor);
    ft_putstr_color("TEST4", COL_LIGHT_GREEN);
    free(file);
    ft_putstr_color("SUCCESSFUL EXIT!\n", COL_GREEN);
    return (EXIT_SUCCESS);
}
