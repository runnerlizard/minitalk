/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cluco <cluco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 19:46:11 by cluco             #+#    #+#             */
/*   Updated: 2021/10/14 20:37:45 by cluco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	ft_postman(int serverPid, char *s)
{
	static char	*str;
	static int	i;

	if (serverPid == -10)
	{
		free(str);
		exit (0);
	}
	if (s != NULL)
		str = s;
	if (str[i] == '0')
		kill(serverPid, SIGUSR1);
	else if (str[i] == '1')
		kill(serverPid, SIGUSR2);
	else
		exit(1);
	i++;
	return (serverPid);
}

void	ft_hdl_cl(int sig, siginfo_t *info, void *context)
{
	(void)context;
	usleep(100);
	if (sig == SIGUSR1)
		ft_postman(info->si_pid, NULL);
	else
		ft_postman(-10, NULL);
}

static char	*ft_tr(char *s, int length, int n0)
{
	static int		n[5];
	char			*utf;
	char			temp[32];

	utf = (char *)malloc(length * 26 + 1);
	while (s[++n0])
	{
		n[1] = 0;
		while (s[n0] > 0)
		{
			temp[n[1]++] = s[n0] % 2 + 48;
			s[n0] = s[n0] / 2;
		}
		n[2] = n[1];
		n[3] = 5;
		while (n[3]-- > 0)
		{
			temp[n[1]++] = n[2] % 2 + 48;
			n[2] = n[2] / 2;
		}
		while (n[1]-- > 0)
			utf[n[4]++] = temp[n[1]];
	}
	utf[n[4]] = 0;
	return (utf);
}

int	main(int argc, char **argv)
{
	struct sigaction	sa_cl;
	sigset_t			block_mask;

	sigemptyset(&block_mask);
	sigaddset(&block_mask, SIGINT);
	sigaddset(&block_mask, SIGQUIT);
	sa_cl.sa_handler = 0;
	sa_cl.sa_flags = SA_SIGINFO;
	sa_cl.sa_mask = block_mask;
	sa_cl.sa_sigaction = &ft_hdl_cl;
	sigaction(SIGUSR1, &sa_cl, NULL);
	sigaction(SIGUSR2, &sa_cl, NULL);
	if (argc != 3)
		ft_putstr_fd("Error: 2 args required", 1);
	ft_postman(ft_atoi(argv[1]), ft_tr((argv[2]), ft_strlen(argv[2]), -1));
	while (1)
		pause();
	return (0);
}
