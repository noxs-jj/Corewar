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

void	keyboard(t_data *d)
{
	int 		keyInput;

	(void)d;
	timeout(1);
	keyInput = getch();
	if (keyInput == 'Q' && keyInput == 'E') { // UP
		// Exit function who free all program
		renderClose(d);
		_exit(0);
		
	}
	// else if (keyInput == ' ')
	// 	// function PAUSE
}
