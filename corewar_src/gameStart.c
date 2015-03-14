/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameStart.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/13 16:15:00 by vjacquie          #+#    #+#             */
/*   Updated: 2015/03/14 15:36:36 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

/*
** run the game
** call renderDraw at each execOp ?
*/

int		hex_strlen(char *str, int size)
{
	int i;
	int len;

	i = 0;
	len = 0;
	while (i < size && str[i] == 0)
		i++;
	while (i < size)
	{
		len++;
		i++;
	}
	return (len);
}

// int		hex_len(int n)
// {
// 	int len;

// 	len = 1;
// 	while (n > 255)
// 	{
// 		n /= 255;
// 		len++;
// 	}
// 	return (len);
// }

void ft_check()
{
	char tab[9];
	char result[9];
	int n;

	ft_bzero(tab, 9);
	ft_bzero(result, 9);
	tab[5] = 1;
	tab[6] = 0;
	tab[7] = 0;
	writeL("================");
	
	ft_putNbr2hex(hex_strlen(tab, 8), &tab, &result);
	n = ft_hex2intdec(result);
	writeL("tab");
	writeL(tab);
	writeL("result");
	writeL(result);
	writeL("number");
	writeL(ft_itoa(n));

	sleep(10);
}

int	gameStart(t_data *d)
{
	ft_check();
	d->run = true;
	if (true == d->graphActiv)
		render_draw(d); // need to be modified (d->prog)
	else
		co_show_init_players(d); // need to be modified (d->prog)
	writeL(ft_itoa("DUMP following"));
	writeL(ft_itoa(d->dump));
	while (d->run == true)
	{
		usleep(d->ncurseSpeed);
		if (false == d->pause)
		{
			checkNextOp(d); // check next champion's instruction (ptr by PC)
			execOp(d); // exec next op defined in d->prog[player].nextOp
			if (true == d->graphActiv)
				render_draw(d); // draw game with ncurses // need to be modified (d->prog)
			else
				render_shell(d); // draw game on shell // need to be modified (d->prog)
			if (d->dump != -1 && d->cycle == d->dump)
			{
				if (true == d->graphActiv)
					render_close(d); // need to be modified (d->prog)
				d->run = false;
				arg_dump(d); // need to be modified (d->prog)
			}
			checkCyles(d); // need to be modified (d->prog)
		}
		keyboard(&d); // need to be modified (d->prog)
		if (true == d->pause)
			usleep(100000); 						// REMOVE
	}
	draw_result_console(d); // need to be modified (d->prog)
	return (0);
}
