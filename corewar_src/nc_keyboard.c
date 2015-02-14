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
	static t_data	*d = NULL;
	int				keyInput;

	if (d == NULL)
		d = getData();
	timeout(1);
	keyInput = getch();
	if (keyInput == 113 || keyInput == 101 || keyInput == 27) { // Q E ECHAP
		exitFree();
	}
	else if (keyInput == 112 || keyInput == 32) // P SPACE
		d->pause = (d->pause == true) ? false : true;

	writeL(ft_itoa(keyInput));
}
