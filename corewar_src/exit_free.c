/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/13 11:33:54 by vjacquie          #+#    #+#             */
/*   Updated: 2015/02/13 11:34:30 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void	exitFree(void)
{
	t_data *d;

	d = get_data();
	render_close(d);
	if (1 == d->option_log)
	{
		write_l("Exit Success !!!");
		close(d->fdDebugg);
	}
	if (d->map != NULL)
		ft_memdel((void **)&d->map);
	if (d != NULL)
		ft_memdel((void **)&d);
	exit(0);
}
