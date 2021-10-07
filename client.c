#include "ft_putnbr_fd.c"
#include "ft_putstr_fd.c"
#include <time.h>

int	ft_postman(int serverPid, char *s)
{
	static char	*str;
	//int			i;

	if (s != NULL)
		str = s;
	ft_putnbr_fd(serverPid, 1);
	ft_putstr_fd(str, 1);
	/*if (str[i] == '0')
		kill(serverPid, SIGUSR1);
	else if (str[i] == '1')
		kill(serverPid, SIGUSR2);
	i++;*/
	return(0);
}
/*
int	ft_hdl_cl(int sig, siginfo_t *info, void *context)
{
	(void)context;
	if (sig == SIGUSR1)
		ft_postman(info->si_pid, NULL);
	else
		exit (0);
	return (0);
}
*/
char	*ft_transform(char *s, int length)
{
	int		n[5];
	char	utf[length * 26];

	n[0] = 0;
	n[1] = 0;
	while (s[n[0]])
	{
		n[3] = n[1];
		while (s[n[0]] > 0)
		{
			utf[n[1]++ + 5] = s[n[0]] % 2 + 48;
			s[n[0]] = s[n[0]] / 2;
		}
		n[2] = 5;
		n[4] = n[1];
		while (n[2]-- > 0)
		{
			utf[n[3]++] = n[4] % 2 + 48;
			n[4] = n[4] / 2;
		}
		n[0]++;
	}
	utf[n[3]] = 0;
	return (utf);
}

int	main(int argc, char **argv)
{
	/*struct sigaction	sa;
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
	sigaction(SIGUSR2, &sa, NULL);*/
	ft_postman(ft_atoi(argv[1]), ft_transform((argv[2]), ft_strlen(argv[2])));
	while (1)
		pause();
	return(0);
}