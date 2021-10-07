#include "ft_putnbr_fd.c"
#include "ft_putstr_fd.c"
#include <string.h>

int	ft_sigusr(int ret, int count, int usr, int ver)
{
	int		i;
	char	c;

	i = 1;
	while (--count > 0)
		i = i * 2;
	ret = ret + i * usr;
	if ((n[2] == 0) && (ver == 2))
	{
		c = ret;
		write(1, &c, 1);
	}
	return (k);
}

void	ft_hdl_ser(int sig, siginfo_t *info, void *context)
{
	static int	n[4];

	(void)context;
	if (n[0] == 0)
		n[0] = info->si_pid;
	if (n[1] < 5)
	{
		if (sig == SIGUSR1)
			if (kill(n[0], SIGUSR1) != -1)
				n[2] = ft_sigusr(n[2], n[1]++, 0, 1);
		else if (sig == SIGUSR2)
			if (kill(n[0], SIGUSR1) != -1)
				n[2] = ft_sigusr(n[2], n[1]++, 1, 1);
	}
	else 
	{
		if (n[2]-- > 1)
			if (sig == SIGUSR1)
				if (kill(n[0], SIGUSR1) != -1)
					n[3] = ft_sigusr(n[3], n[2], 0, 2);
			else if (sig == SIGUSR2)
				if (kill(n[0], SIGUSR1) != -1)
					n[3] = ft_sigusr(n[3], n[2], 1, 2);
		else
		{
			n[0] = 0;
			n[1] = 0;
			n[3] = 0;
		}
	}
}

int	main	(void)
{
	struct sigaction	sa;
	sigset_t			block_mask;

	sigemptyset(&block_mask);
	sigaddset(&block_mask, SIGINT);
	sigaddset(&block_mask, SIGQUIT);
	sa.sa_handler = 0;
	sa.sa_flags = SA_SIGINFO;
	sa.sa_mask = block_mask;
	sa.sa_sigaction = &ft_hdl_ser;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_putnbr_fd(getpid(), 1);
	ft_putstr_fd("\n", 1);
	while (1)
		pause();
	return(0);
}