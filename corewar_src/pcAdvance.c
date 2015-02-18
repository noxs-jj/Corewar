/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pcAdvance.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/18 16:02:50 by vjacquie          #+#    #+#             */
/*   Updated: 2015/02/18 18:35:30 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void pcAdvance(t_header *player, t_data *d, int adv)
{
	player->PC->present = false;
	player->indexPC = (player->indexPC + adv) % MEM_SIZE;
	player->PC = &d->map[player->indexPC];
	player->PC->present = true;
}