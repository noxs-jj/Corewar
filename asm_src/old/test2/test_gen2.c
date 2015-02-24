#include <libft.h>
#include <stdio.h>
#include <sys/types.h> /* DIR */
#include <dirent.h> /* dirent */
#include <unistd.h> /* access, fork */
#include <stdlib.h> /* exit */

#define MAX_ARGS_NUMBER			4

typedef char	t_arg_type;

#define T_REG					1
#define T_DIR					2
#define T_IND					4
#define T_LAB					8

typedef struct	s_op
{
	char		*name;
	int			nb_params;
	t_arg_type	params[MAX_ARGS_NUMBER];
	int			code;
	int			nb_cycles;
	char		*desc;
	int			cod_oc;
	int			has_idx;
}				t_op;

static t_op    op_tab[17] =
{
	{"live", 1, {T_DIR}, 1, 10, "alive", 0, 0},
	{"ld", 2, {T_DIR | T_IND, T_REG}, 2, 5, "load", 1, 0},
	{"st", 2, {T_REG, T_IND | T_REG}, 3, 5, "store", 1, 0},
	{"add", 3, {T_REG, T_REG, T_REG}, 4, 10, "addition", 1, 0},
	{"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, "soustraction", 1, 0},
	{"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, 6,
		"et (and  r1, r2, r3   r1&r2 -> r3", 1, 0},
	{"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7, 6,
		"ou  (or   r1, r2, r3   r1 | r2 -> r3", 1, 0},
	{"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8, 6,
		"ou (xor  r1, r2, r3   r1^r2 -> r3", 1, 0},
	{"zjmp", 1, {T_DIR}, 9, 20, "jump if zero", 0, 1},
	{"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 25,
		"load index", 1, 1},
	{"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 25,
		"store index", 1, 1},
	{"fork", 1, {T_DIR}, 12, 800, "fork", 0, 1},
	{"lld", 2, {T_DIR | T_IND, T_REG}, 13, 10, "long load", 1, 0},
	{"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 50,
		"long load index", 1, 1},
	{"lfork", 1, {T_DIR}, 15, 1000, "long fork", 0, 1},
	{"aff", 1, {T_REG}, 16, 2, "aff", 1, 0},
	{0, 0, {0}, 0, 0, 0, 0, 0}
};

void	split_free(char **splitted)
{
	char	**tmp;

	if (!splitted)
		return ;
	tmp = splitted;
	while (*tmp && **tmp)
	{
		free(*tmp);
		tmp++;
	}
	free(splitted);
}

void	test_asm_on(char *asm_f, char *file)
{
	int		pid;
	char	*args[3];

	args[0] = asm_f;
	args[1] = ft_strjoin("autotest/", file);
	args[2] = NULL;
	pid = fork();
	if (pid == 0)
	{
		execve(asm_f, args, NULL);
		perror("execve :");
		exit(-1);
	}
	else
		wait(0);
	free(args[1]);
}

int	file_should_exist(char *name)
{
	char	**split;
	int		i;
	int		j;

	split = ft_strsplit(name, '-');
	i = 0;
	while (ft_strcmp(op_tab[i].name, split[0]) != 0)
		++i;
	if (op_tab[i].nb_params != ft_atoi(split[1]))
		return (0);
	j = -1;
	while (++j < op_tab[i].nb_params)
	{
		if ((ft_strcmp(split[2 + j], "REG") == 0)
			&& ((T_REG & op_tab[i].params[j]) != T_REG))
				return (0);
		if ((ft_strcmp(split[2 + j], "DIR") == 0)
			&& ((T_DIR & op_tab[i].params[j]) != T_DIR))
				return (0);
		if ((ft_strcmp(split[2 + j], "IND") == 0)
			&& ((T_IND & op_tab[i].params[j]) != T_IND))
				return (0);
	}
	split_free(split);
	return (1);
}

void	test_files(char *name, int param, int i)
{
	char	*join1;
	char	*join2;

	if (param == op_tab[i].nb_params)
	{
		join1 = ft_strjoin(name, ".cor");
		if (access(join1, F_OK) == -1)
			printf("%s doesn't exist and should\n", join1);
		ft_strdel(&join1);
		return ;
	}
	if (op_tab[i].params[param] & T_REG)
	{
		join1 = ft_strjoin(name, "REG");
		if (param < op_tab[i].nb_params)
		join2 = ft_strjoin(join1, "-");
		ft_strdel(&join1);
		test_files(join2, param + 1, i);
		ft_strdel(&join2);
	}
	if (op_tab[i].params[param] & T_DIR)
	{
		join1 = ft_strjoin(name, "DIR");
		if (param < op_tab[i].nb_params)
		join2 = ft_strjoin(join1, "-");
		ft_strdel(&join1);
		test_files(join2, param + 1, i);
		ft_strdel(&join2);
	}
	if (op_tab[i].params[param] & T_IND)
	{
		join1 = ft_strjoin(name, "IND");
		if (param < op_tab[i].nb_params)
		join2 = ft_strjoin(join1, "-");
		ft_strdel(&join1);
		test_files(join2, param + 1, i);
		ft_strdel(&join2);
	}
}

void	test_existing_files()
{
	int		i;
	int		j;
	char	*join1;
	char	*join2;

	i = -1;
	while (op_tab[++i].name)
	{
		join1 = ft_strjoin("autotest/", op_tab[i].name);
		join2 = ft_strjoin(join1, "-");
		ft_strdel(&join1);
		join1 = ft_strjoin(join2, ft_itoa(op_tab[i].nb_params));
		ft_strdel(&join2);
		join2 = ft_strjoin(join1, "-");
		ft_strdel(&join1);
		test_files(join2, 0, i);
		ft_strdel(&join2);
	}
}

int main (int argc, char **argv)
{
	DIR				*dp;
	struct dirent	*ep;

	if (argc != 2 || access(argv[1], F_OK | X_OK))
	{
		printf("usage : %s your_asm\n", argv[0]);
		return (0);
	}
	dp = opendir ("./autotest");
	if (dp == NULL)
	{
		perror ("Couldn't open the directory");
		return (0);
	}
	while ((ep = readdir(dp)))
	{
		if (*(ep->d_name) != '.'
		&& ft_strcmp(ep->d_name + ft_strlen(ep->d_name) - 2, ".s") == 0)
			test_asm_on(argv[1], ep->d_name);
	}
	closedir(dp);
	dp = opendir("./autotest");
	while ((ep = readdir(dp)))
	{
		if (ft_strcmp(ep->d_name + ft_strlen(ep->d_name) - 4, ".cor") == 0)
		{
			if (!(file_should_exist(ep->d_name)))
				printf("%s shouldn't exist\n", ep->d_name);
		}
	}
	closedir(dp);
	test_existing_files();
	return (0);
}