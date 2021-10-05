#include <signal.h>
#include <sys/types.h>
#include "./libft/libft.h"

typedef struct {
	int si_siginfo;
	int si_code;
	union sigval si_value;

}
void	ft_name(int firstSig, siginfo_t *sig, void context)

int	main	(void)
{
	ft_putstr_fd("", 1);
	struct sigaction firstSig;
	firstSig.sa_flags = SA_SIGINFO;
	firstSig.sa_sigaction = ft_name;
	sigaction(signalName, &firstSig, NULL);
	signal(SIGINT, handler);
	return(0);
}