/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_l.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/09 17:53:59 by jmoiroux          #+#    #+#             */
/*   Updated: 2015/02/23 18:11:42 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void	write_l(char *str)
{
	static t_data *d = NULL;

	if (d == NULL)
		d = get_data();
	if (1 == d->option_log)
		ft_putendl_fd(str, d->fdDebugg);
}
