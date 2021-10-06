#include "ft_putnbr_fd.c"
#include "ft_putstr_fd.c"
#include <time.h>

int	ft_transform(int serverPid, int c)
{
	int		i;
	int		j;
	int		k;
	char	utf[32];

	i = 0;
	while (c > 0)
	{
		utf[i++] = c % 2 + 48;
		c = c / 2;
	}
	j = i;
	k = 4;
	while (k-- > -1)
	{
		utf[i++] = j % 2 + 48;
		j = j / 2;
	}
	utf[i] = 0;
	while (i-- > 0)
	{
		ft_putstr_fd("go\n", 1);
		usleep(1000);
		if (utf[i] == '0')
			kill(serverPid, SIGUSR1);
		else
			kill(serverPid, SIGUSR2);
	}
	return (serverPid);
}

int	main(int argc, char **argv)
{
	int	serverPid;
	int	i;

	if (argc != 3)
		ft_putstr_fd("Error: 2 args required", 1);
	serverPid = ft_atoi(argv[1]);
	i = 0;
	while (argv[2][i++])
		ft_transform(serverPid, argv[2][i - 1]);
	return(0);
}