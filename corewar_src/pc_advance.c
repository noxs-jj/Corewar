/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pc_advance.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/18 16:02:50 by vjacquie          #+#    #+#             */
/*   Updated: 2015/03/09 11:30:45 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void	pc_advance(t_data *d, t_header *player, int adv)
{
	player->PC->present = false;
	player->indexPC = (player->indexPC + MEM_SIZE + adv + 1) % MEM_SIZE;
	player->PC = &d->map[player->indexPC];
	player->PC->present = true;
}
