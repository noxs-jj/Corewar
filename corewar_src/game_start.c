/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_start.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/13 16:15:00 by vjacquie          #+#    #+#             */
/*   Updated: 2015/03/17 18:45:02 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

static void	game_start_2(t_data *d)
{
	check_next_op(d);
	exec_op(d);
	if (true == d->graphActiv)
		render_draw(d);
	else
		render_shell(d);
	if (d->dump != -1 && (int)d->cycle == d->dump)
	{
		if (true == d->graphActiv)
			render_close(d);
		d->run = false;
		arg_dump(d);
	}
	checkCyles(d);
}

int	game_start(t_data *d)
{
	d->run = true;
	if (true == d->graphActiv)
		render_draw(d);
	else
		co_show_init_players(d);
	while (d->run == true)
	{
		usleep(d->ncurseSpeed);
		if (false == d->pause)
			game_start_2(d);
		render_keyboard(d);
		if (true == d->pause)
			usleep(100000);
	}
	draw_result_console(d);
	return (0);
}
