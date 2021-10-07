#include "ft_putnbr_fd.c"
#include "ft_putstr_fd.c"
#include <time.h>

int	ft_postman(int i, int serverPid, char *s)
{
	static char	*str;
	int			serPid;

	if (s != NULL)
		str == s;
	if (str[i] == '0')
		kill(serverPid, SIGUSR1);
	else if (str[i] == '1')
		kill(serverPid, SIGUSR2);
	return(0);
}

int	ft_hdl_cl(int sig, siginfo_t *info, void *context)
{
	static int	i;

	(void)context;
	if (sig == SIGUSR1)
		ft_postman(++i, info->si_pid, NULL);
	else
		exit (0);
	return (0);
}

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
	return (serverPid);
}

int	main(int argc, char **argv)
{
	int	serverPid;
	int	i;
	struct sigaction	sa;
	sigset_t			block_mask;

	if (argc != 3)
		ft_putstr_fd("Error: 2 args required", 1);
	sigemptyset(&block_mask);
	sigaddset(&block_mask, SIGINT);
	sigaddset(&block_mask, SIGQUIT);
	sa.sa_handler = 0;
	sa.sa_flags = SA_SIGINFO;
	sa.sa_mask = block_mask;
	sa.sa_sigaction = &ft_hdl_cl;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_postman(0, ft_atoi(argv[1]), ft_transform(argv[2]));
	while (1)
		pause();
	return(0);
}