/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_register.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/14 12:23:55 by vjacquie          #+#    #+#             */
/*   Updated: 2015/03/14 12:31:22 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

int		is_register(t_header *player, int arg_nbr)
{
	if (ft_strncmp(&player->codage[arg_nbr * 2], "01", 2) != 0)
		return (-1);
	if (isValidRegister(ft_hex2Dec(player->opArgs[arg_nbr])) < 0)
		return (-1);
	return (0);
}
