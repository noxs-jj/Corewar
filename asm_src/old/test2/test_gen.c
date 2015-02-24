#include <libft.h> /* ft_strjoin needs  + ft_strdel */
#include <fcntl.h> /* open */
#include <unistd.h> /* write */
#include <sys/stat.h> /* mkdir */

#define MAX_ARGS_NUMBER			4
#define DIRECT_CHAR				"%" /* ATTENTION, " et non ' */
#define SEPARATOR_CHAR			","	/* ATTENTION, " et non ' */

#define NAME_CMD_STRING			".name"
#define COMMENT_CMD_STRING		".comment"

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

char	*ft_strjoin(char const *s1, char const *s2)
{
	char const	*addr;
	char		*res;
	size_t		length_s1;
	size_t		length_s2;
	size_t		i;

	if (!s1 && !s2)
		return (NULL);
	if (!s1 || !s2)
	{
		addr = (!s1) ? s2 : s1;
		res = ft_strnew(ft_strlen(addr));
		ft_strcpy(res, addr);
		return (res);
	}
	length_s1 = ft_strlen(s1);
	length_s2 = ft_strlen(s2);
	res = (char *) malloc(sizeof(char) * (length_s1 + length_s2 + 1));
	if (!res)
		return (NULL);
	i = 0;
	ft_strcpy(res, s1);
	ft_strcpy(res + length_s1, s2);
	return (res);
}

char	*gen_file_name(char *name, int param, int args[])
{
	int		i;
	char	*param_str;
	char	*join1;
	char	*join2;

	join1 = ft_strjoin("autotest/", name);
	join2 = ft_strjoin(join1, "-");
	ft_strdel(&join1);
	param_str = ft_itoa(param);
	join1 = ft_strjoin(join2, param_str);
	ft_strdel(&join2);
	join2 = ft_strjoin(join1, "-");
	ft_strdel(&join1);
	i = -1;
	while (++i < param)
	{
		if (args[i] == 1)
			join1 = ft_strjoin(join2, "REG");
		else if (args[i] == 2)
			join1 = ft_strjoin(join2, "IND");
		else if (args[i] == 3)
			join1 = ft_strjoin(join2, "DIR");
		ft_strdel(&join2);
		join2 = ft_strjoin(join1, "-");
		ft_strdel(&join1);
		if (i == param - 1)
			join1 = ft_strjoin(join2, ".s");
	}
	return (join1);
}

void	gen_file(char *name, int param, int args[])
{
	int		i;
	int		fd;
	char	*file_name;

	file_name = gen_file_name(name, param, args);
	if ((fd = open(file_name, O_WRONLY | O_CREAT | O_TRUNC, 448)) == -1)
		return ;
	ft_strdel(&file_name);
	write(fd, (char *)NAME_CMD_STRING, ft_strlen((char *)NAME_CMD_STRING));
	write(fd, " \"\"\n", 4);
	write(fd, (char *)COMMENT_CMD_STRING, ft_strlen((char *)COMMENT_CMD_STRING));
	write(fd, " \"\"\n\n", 5);
	write(fd, name, ft_strlen(name));
	write(fd, " ", 1);
	i = -1;
	while (++i < param)
	{
		if (args[i] == 1)
			write(fd, "r1", 2);
		else if (args[i] == 2)
			write(fd, "414141", 6);
		else if (args[i] == 3)
		{
			write(fd, (char *)DIRECT_CHAR, 1);
			write(fd, "414141", 6);
		}
		if (i < param - 1)
			write(fd, (char *)SEPARATOR_CHAR, 1);
		else
			write(fd, "\n", 1);
	}
	close(fd);
}

void	gen_all_files(int param, int cur_arg, int args[], char *file)
{
	int	k;

	k = 0;
	while (++k < 4)
	{
		args[cur_arg] = k;
		if (cur_arg == param)
			gen_file(file, param, args);
		else
			gen_all_files(param, cur_arg + 1, args, file);
	}
}

int	main(void)
{
	int		i;
	int		param;
	int		args[MAX_ARGS_NUMBER];

	i = -1;
	while (op_tab[++i].name)
	{
		param = 0;
		while (++param < MAX_ARGS_NUMBER)
		{
			ft_bzero(args, MAX_ARGS_NUMBER);
			gen_all_files(param, 0, args, op_tab[i].name);
		}
	}
	return (0);
}