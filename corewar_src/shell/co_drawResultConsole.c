/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   co_drawResultConsole.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoiroux <jmoiroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/13 15:00:49 by jmoiroux          #+#    #+#             */
/*   Updated: 2015/02/13 15:00:50 by jmoiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/render.h"

//le joueur x(nom_champion) a gagne

void	drawResultConsole(t_data *d)
{
	(void)d;
	ft_putstr("le joueur ");
	ft_putstr(S_DEFAULT_VALUE); // player number
	ft_putstr(" a gagne\n");
}
