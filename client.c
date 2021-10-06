#include "ft_putnbr_fd.c"
#include "ft_putstr_fd.c"

int	ft_transform(int serverPid, long long int c)
{
	int		i;
	int		j;
	int		k;
	char	*utf[32];

	i = 0;
	while (c > 0)
	{
		utf[i++] = c % 2 + 48;
		c = c / 2;
	}
	j = i;
	k = 5;
	while (k-- > -1)
	{
		utf[i++] = j % 2 + 48;
		j = j / 2;
	}
	while (i >= 0)
		if (utf[i--] == 48)
			kill(serverPid, SIGUSR1);
		else
			kill(serverPid, SIGUSR2);
	return (0);
}

int	main	(int argc, char **argv)
{
	int	serverPid;
	int	i;

	if (argc != 3)
		ft_putstr_fd("Error: 2 args required", 1);
	serverPid = ft_atoi(argv[1]);
	ft_putnbr_fd(argv[2][0], 1);
	i = 0;
	while (argv[2][i])
		ft_transform(srverPid, argv[2][i++]);
	return(0);
}