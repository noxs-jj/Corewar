/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writeL.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoiroux <jmoiroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/09 17:53:59 by jmoiroux          #+#    #+#             */
/*   Updated: 2015/02/09 17:54:01 by jmoiroux         ###   ########.fr       */
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