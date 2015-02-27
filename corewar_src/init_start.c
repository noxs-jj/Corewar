/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_start.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/09 11:55:15 by vjacquie          #+#    #+#             */
/*   Updated: 2015/02/26 14:15:52 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

static int	checkNumber(t_data *d, int n)
{
	t_header *tmp;

	if ((tmp = d->prog) == NULL)
		return (0);

	while (tmp != NULL)
	{
		if (n == tmp->number)
			return (-1);
		tmp = tmp->next;
	}
	return (0);
}

static int	champion_number(t_data *d, int ac, char **av, int i)
{
	t_header *prog;

	if (++i >= ac || ft_atoi(av[i]) <= 0
		|| ft_atoi(av[i]) > MAX_PLAYERS || ++d->players >= MAX_PLAYERS
		|| checkNumber(d, ft_atoi(av[i])) == -1)
		return (-1);
	addProg(d, newProg(ft_atoi(av[i])));
	prog = lastProg(d);
	if (++i >= ac || ft_strstr(av[i], ".cor") == NULL)
		return (-1);
	prog->filename = av[i];
	return (i);
}

static int	champion(t_data *d, int ac, char **av, int i)
{
	int number;
	t_header *prog;

	number = 1;
	if (++d->players >= MAX_PLAYERS)
		return (-1);
	while (checkNumber(d, number) == -1 && number <= MAX_PLAYERS)
		number++;
	addProg(d, newProg(number));
	prog = lastProg(d);
	prog->filename = av[i];
	return (i);
}

int 		checkparam(t_data *d, int ac, char **av)
{
	int i;

	i = 1;
	while (i < ac)
	{
		if (ft_strcmp(av[i], "-dump") == 0)
		{
			if (++i >= ac || d->dump != -1 || (d->dump = ft_atoi(av[i])) <= 0)
				return (print_error(ERR_PARAM));
		}
		else if (ft_strcmp(av[i], "-n") == 0)
			i = champion_number(d, ac, av, i);
		else if (ft_strstr(av[i], ".cor") != NULL)
			i = champion(d, ac, av, i);
		else if (ft_strcmp(av[i], "-g") == 0)
			{
				d->graphActiv = true;
				d->pause = true;
			}
		else
			return (print_error(ERR_PARAM));
		if (i == -1)
			return (print_error(ERR_PARAM));
		if (REG_SIZE < 4)
			return (print_error("REG_SIZE invalid"));
		i++;
	}
	d->realPlayers = d->players + 1; // copy real number champions without fork for ncurses show 
	if (d->players < 1)
		return (print_error("Min 2 Players"));
}
int			init_start(t_data *d, int ac, char **av)
{
	if (ac < 3 || ac > MAX_ARGS_NUMBER)
		return (print_error(ERR_PARAM));
	if (LOG == 1)
	{
		d->fdDebugg = open(PATH_DEBUGG, O_WRONLY|O_CREAT|O_APPEND, 0644);
		if (d->fdDebugg < 0)
			return (print_error(ERR_FILE_DEBUGG));
	}
	d->dump = -1;
	d->pause = false;
	d->players = -1;
	d->cycleDie = CYCLE_TO_DIE;
	d->cycle = 0;
	d->livesCurrent = 0;
	d->iMaxCheck = 0;
	d->nbrWinner = 999;
	d->graphActiv = false;
	// init_prog(d);
	// writeL("init start before checkparam");
	return (checkparam(d, ac, av));
}
