#include "ft_putnbr_fd.c"
#include "ft_putstr_fd.c"
#include <string.h>

void	ft_hdl(int sig, siginfo_t *info, void *context)
{
	int	pid;

	pid = 0;
	(void)context;
	if (info->si_pid)
		pid = info->si_pid;
	if (sig == SIGUSR1)
		ft_putnbr_fd(0 ,1);
	else if (sig == SIGUSR2)
		ft_putnbr_fd(1, 1);
	if (kill(pid, SIGUSR1) == -1)
		ft_putstr_fd("3\n", 1);
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
	sa.sa_sigaction = &ft_hdl;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_putnbr_fd(getpid(), 1);
	ft_putstr_fd("\n", 1);
	while (1)
		pause();
	return(0);
}