#include "ft_putnbr_fd.c"

void ft_putchar(int i)
{
	static int	i;
	static int	n;

	i = 2;
	n = 0;

}

void	ft_handler_sigusr1(int sig)
{

	ft_putnbr_fd(1, 1);
}

void	ft_handler_sigusr2(int sig)
{
	ft_putnbr_fd(1, 1);
}

int	main	(void)
{
	/*struct sigaction sa = { 0 };

	sa.sa_handler = &ft_handler;
	sigaction(SIGUSR1, &sa, NULL);*/
	ft_putnbr_fd(getpid(), 1);
	return(0);
}