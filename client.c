# include <signal.h>
# include "./libft/libft.h"

int	main	(void)
{
	struct sigaction firstSig;
	firstSig.sa_flags = SA_SIGINFO;
	firstSig.sa_sigaction = ft_name;
	sigaction(signalName, &firstSig, NULL);
	signal(SIGINT, handler);
	return(0);
}