#include "ft_putnbr_fd.c"
#include "ft_putstr_fd.c"
#include <string.h>

int	ft_sigusr(int ret, int count, int usr, int ver)
{
	static int		i;

	if (ver == -10)
	{
		if (count == 0)
			i = 16;
		ret = ret + i * usr;
		i = i / 2;
	}
	else
	{
		if (ret == 0)
		{
			if (count > 1)
				i = 1;
			while (count-- > 1)
				i = i * 2;
		}
		ret = ret + i * usr;
		i = i / 2;
	}
	return (ret);
}

void	ft_hdl_ser(int sig, siginfo_t *info, void *context)
{
	static int	n[4];
	char		c;

	(void)context;
	if (n[0] == 0)
		n[0] = info->si_pid;
	if (n[1] < 5)
	{
		ft_putstr_fd("\ncount -  ", 1);
		ft_putnbr_fd(n[1], 1);
		ft_putstr_fd("      length - ", 1);
		ft_putnbr_fd(n[2], 1);
		ft_putstr_fd("     obj - ", 1);
		ft_putnbr_fd(n[3], 1);
		if (sig == SIGUSR1)
		{
			n[2] = ft_sigusr(n[2], n[1]++, 0, -10);
			ft_putstr_fd("    sigusr -  ", 1);
			ft_putnbr_fd(SIGUSR1, 1);
			if (kill(n[0], SIGUSR1) == -1)
				ft_putstr_fd("Error", 1);
		}
		else if (sig == SIGUSR2)
		{
			n[2] = ft_sigusr(n[2], n[1]++, 1, -10);
			ft_putstr_fd("    sigusr -  ", 1);
			ft_putnbr_fd(SIGUSR2, 1);
			if (kill(n[0], SIGUSR1) == -1)
				ft_putstr_fd("Error", 1);
		}
	}
	else if (n[2] > 0)
	{
		ft_putstr_fd("\nget - ", 1);
		ft_putnbr_fd(n[2], 1);
		if (sig == SIGUSR1)
		{
			n[3] = ft_sigusr(n[3], n[2], 0, n[2]);
			if (kill(n[0], SIGUSR1) == -1)
				ft_putstr_fd("Error", 1);
			ft_putstr_fd("    value - ", 1);
			ft_putnbr_fd(n[3], 1);
			ft_putstr_fd("    count - ", 1);
			ft_putnbr_fd(n[2], 1);
			ft_putstr_fd("    sigusr -  ", 1);
			ft_putnbr_fd(SIGUSR1, 1);
		}
		else if (sig == SIGUSR2)
		{
			n[3] = ft_sigusr(n[3], n[2], 1, n[2]);
			if (kill(n[0], SIGUSR1) == -1)
				ft_putstr_fd("Error", 1);
			ft_putstr_fd("    value - ", 1);
			ft_putnbr_fd(n[3], 1);
			ft_putstr_fd("    count - ", 1);
			ft_putnbr_fd(n[2], 1);
			ft_putstr_fd("    sigusr -  ", 1);
			ft_putnbr_fd(SIGUSR2, 1);
		}
		n[2]--;
	}
	if ((n[2] == 0) && (n[3] != 0))
	{
		c = n[3];
		write(1, &c, 1);
		n[0] = 0;
		n[1] = 0;
		n[3] = 0;
		n[2] = 0;
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