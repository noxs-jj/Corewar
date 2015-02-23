/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writeL.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/09 17:53:59 by jmoiroux          #+#    #+#             */
/*   Updated: 2015/02/23 18:11:42 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void	writeL(char *str)
{
	static t_data *d = NULL;

	if (d == NULL)
		d = getData();
	if (1 == LOG)
		ft_putendl_fd(str, d->fdDebugg);
}