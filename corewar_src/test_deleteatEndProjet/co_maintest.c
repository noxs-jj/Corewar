#include "../../includes/corewar.h"
#include "../../includes/render.h"
#include <time.h>

int	main(void)
{
	t_data	*d = getData();
	d->players = 4;

	init_mem(d);

	ft_strcpy(d->prog[0].prog_name, "Tartiflette");
	ft_strcpy(d->prog[1].prog_name, "champions for ever");
	ft_strcpy(d->prog[2].prog_name, "born2code");
	ft_strcpy(d->prog[3].prog_name, "noob posted");

	ft_strcpy(d->prog[0].comment, "En haute savoie");
	ft_strcpy(d->prog[1].comment, "nobbs suxx !");
	ft_strcpy(d->prog[2].comment, "where ths skill is...");
	ft_strcpy(d->prog[3].comment, "Kevin !!!");

	d->prog[0].prog_size = 1337;
	d->prog[1].prog_size = 2015;
	d->prog[2].prog_size = 103;
	d->prog[3].prog_size = 42;

	co_showInitPlayers(d);
	sleep(1);
	drawResultConsole(d);	


	return (0);
}
