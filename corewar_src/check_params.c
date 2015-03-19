/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoiroux <jmoiroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/19 12:30:38 by jmoiroux          #+#    #+#             */
/*   Updated: 2015/03/19 12:30:39 by jmoiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

static int	check_number(t_data *d, int n)
{
	t_header *tmp;

	if ((tmp = d->prog) == NULL)
		return (0);
	while (tmp != NULL)
	{
		if (n == (int)tmp->number)
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
		|| check_number(d, ft_atoi(av[i])) == -1)
		return (-1);
	add_prog(d, new_prog(ft_atoi(av[i])));
	prog = last_prog(d);
	if (++i >= ac || ft_strstr(av[i], ".cor") == NULL)
		return (-1);
	prog->filename = av[i];
	return (i);
}

static int	champion(t_data *d, int ac, char **av, int i)
{
	int			number;
	t_header	*prog;

	(void)ac;
	number = 1;
	if (++d->players >= MAX_PLAYERS)
		return (-1);
	while (check_number(d, number) == -1 && number <= MAX_PLAYERS)
		number++;
	add_prog(d, new_prog(number));
	prog = last_prog(d);
	prog->filename = av[i];
	return (i);
}

static int	checkparam_2(t_data *d, int ac, char **av, int *i)
{
	if (ft_strcmp(av[(*i)], "-dump") == 0)
	{
		if (++(*i) >= ac || d->dump != -1 || (d->dump = ft_atoi(av[(*i)])) <= 0)
			return (print_error(ERR_PARAM));
	}
	else if (ft_strcmp(av[(*i)], "-n") == 0)
		(*i) = champion_number(d, ac, av, (*i));
	else if (ft_strstr(av[(*i)], ".cor") != NULL)
		(*i) = champion(d, ac, av, (*i));
	else if (ft_strcmp(av[(*i)], "-log") == 0)
		set_option_log(d);
	else if (ft_strcmp(av[(*i)], "-g") == 0)
	{
		d->graph_activ = true;
		d->pause = true;
	}
	else
		return (print_error(ERR_PARAM));
	return (0);
}

int			checkparam(t_data *d, int ac, char **av)
{
	int i;

	i = 1;
	while (i < ac)
	{
		if (checkparam_2(d, ac, av, &i) < 0)
			return (-1);
		if (i == -1)
			return (print_error(ERR_PARAM));
		if (REG_SIZE < 4)
			return (print_error("REG_SIZE invalid"));
		i++;
	}
	d->real_players = d->players + 1;
	if (d->players < 1)
		return (print_error("Min 2 Players"));
	return (0);
}
