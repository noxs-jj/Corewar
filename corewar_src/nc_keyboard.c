/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nc_keyboard.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoiroux <jmoiroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/09 13:39:53 by jmoiroux          #+#    #+#             */
/*   Updated: 2015/02/09 13:39:54 by jmoiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"
#include "../includes/render.h"

void	keyboard()
{
	int 		keyInput;

	timeout(1);
	keyInput = getch();
	if (keyInput == 113 // Q
		|| keyInput == 101 // E
		|| keyInput == 27) { // ECHAP
		exitFree();
	}
}
