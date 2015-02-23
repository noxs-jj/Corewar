/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nc_draw_scene.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/09 12:42:44 by jmoiroux          #+#    #+#             */
/*   Updated: 2015/02/18 16:32:11 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewar.h"
#include "../../includes/render.h"

void	renderDraw(t_data *d)
{
	int			i = 0;
	int			x = L_X_MAP_START;
	int 		y = L_Y_MAP_START;
	short int 	v;

	werase(d->window);
	wborder(d->window, '|', '|', '-', '-', '+', '+', '+', '+');
	
	renderLegendColumn(d);
	renderLegendSentence(d);
	renderLegendPlayerSentence(d); 
	renderLegendPlayerValue(d);
	renderLegendInfoValue(d);

	while (y < L_Y_MAP_END)
	{
		x = L_X_MAP_START;
		while (x < L_X_MAP_END && i < MEM_SIZE)
		{
			if (d->map[i].champ == 0)
				v = COLOR_PAIR(0);
			else if (d->map[i].champ == 1)
			{
				if (d->map[i].live > 0)
				{
					v = COLOR_PAIR(21);
					d->map[i].live;
				}
				else if (d->map[i].recent > 0)
				{
					v = COLOR_PAIR(31);
					d->map[i].recent--;
				}
				else
					v = (d->map[i].present == false) ? COLOR_PAIR(1) : COLOR_PAIR(11);
			}
			else if (d->map[i].champ == 2)
			{
				if (d->map[i].live > 0)
				{
					v = COLOR_PAIR(22);
					d->map[i].live;
				}
				else if (d->map[i].recent > 0)
				{
					v = COLOR_PAIR(32);
					d->map[i].recent--;
				}
				else
					v = (d->map[i].present == false) ? COLOR_PAIR(2) : COLOR_PAIR(12);
			}
			else if (d->map[i].champ == 3)
			{
				if (d->map[i].live > 0)
				{
					v = COLOR_PAIR(23);
					d->map[i].live;
				}
				else if (d->map[i].recent > 0)
				{
					v = COLOR_PAIR(33);
					d->map[i].recent--;
				}
				else
					v = (d->map[i].present == false) ? COLOR_PAIR(3) : COLOR_PAIR(13);
			}
			else if (d->map[i].champ == 4)
			{
				if (d->map[i].live > 0)
				{
					v = COLOR_PAIR(24);
					d->map[i].live;
				}
				else if (d->map[i].recent > 0)
				{
					v = COLOR_PAIR(34);
					d->map[i].recent--;
				}
				else
					v = (d->map[i].present == false) ? COLOR_PAIR(4) : COLOR_PAIR(14);
			}
			mvwaddch(d->window, y, x, d->map[i].hex[0] | v);
			mvwaddch(d->window, y, x + 1, d->map[i].hex[1] | v);
			x += 3;
			i++; // case mem jump
		}
		y++;
	}

	refresh();
	wrefresh(d->window);
}

// void	renderDraw(t_data *d)
// {
// 	int			i = 0;
// 	int			x = L_X_MAP_START;
// 	int 		y = L_Y_MAP_START;
// 	short int 	v;

// 	werase(d->window);
// 	wborder(d->window, '|', '|', '-', '-', '+', '+', '+', '+');
	
// 	renderLegendColumn(d);
// 	renderLegendSentence(d);
// 	renderLegendPlayerSentence(d); 
// 	renderLegendPlayerValue(d);
// 	renderLegendInfoValue(d);

// 	while (y < L_Y_MAP_END)
// 	{
// 		x = L_X_MAP_START;
// 		while (x < L_X_MAP_END && i < MEM_SIZE)
// 		{
// 			if (d->map[i].champ == 0)
// 				v = COLOR_PAIR(0);
// 			else if (d->map[i].champ == 1)
// 				v = (d->map[i].present == false) ? COLOR_PAIR(1) : COLOR_PAIR(11);
// 			else if (d->map[i].champ == 2)
// 				v = (d->map[i].present == false) ? COLOR_PAIR(2) : COLOR_PAIR(12);
// 			else if (d->map[i].champ == 3)
// 				v = (d->map[i].present == false) ? COLOR_PAIR(3) : COLOR_PAIR(13);
// 			else if (d->map[i].champ == 4)
// 				v = (d->map[i].present == false) ? COLOR_PAIR(4) : COLOR_PAIR(14);
// 			mvwaddch(d->window, y, x, d->map[i].hex[0] | v);
// 			mvwaddch(d->window, y, x + 1, d->map[i].hex[1] | v);
// 			x += 3;
// 			i++; // case mem jump
// 		}
// 		y++;
// 	}

// 	refresh();
// 	wrefresh(d->window);
// }
