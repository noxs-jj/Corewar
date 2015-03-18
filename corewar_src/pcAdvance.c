/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pcAdvance.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/18 16:02:50 by vjacquie          #+#    #+#             */
/*   Updated: 2015/03/09 11:30:45 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void	pcAdvance(t_data *d, t_header *player, int adv)
{
	player->PC->present = false;
	// writeL("index:");
	// writeL(ft_itoa(player->indexPC));
	// writeL("adv:");
	// writeL(ft_itoa(adv));
	player->indexPC = (player->indexPC + MEM_SIZE + adv + 1) % MEM_SIZE;
	// writeL("hello2");
	// writeL(d->map[player->indexPC].hex);
	player->PC = &d->map[player->indexPC];
	// writeL("index:");
	//  writeL(ft_itoa(player->indexPC));
	player->PC->present = true;
}
