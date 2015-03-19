/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_indirect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/14 12:23:55 by vjacquie          #+#    #+#             */
/*   Updated: 2015/03/14 12:33:18 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

int		is_indirect(t_header *player, int arg_nbr)
{
	if (ft_strncmp(&player->codage[arg_nbr * 2], "11", 2) != 0)
		return (-1);
	return (0);
}
