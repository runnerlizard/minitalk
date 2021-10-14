/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cluco <cluco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 19:46:33 by cluco             #+#    #+#             */
/*   Updated: 2021/10/14 21:47:09 by cluco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	ft_sigusr(int ret, int count, int usr, int ver)
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
	ft_putstr_fd("\0", 1);
	if ((n[1] < 5) && (sig == SIGUSR1))
		n[2] = ft_sigusr(n[2], n[1]++, 0, -10);
	else if ((n[1] < 5) && (sig == SIGUSR2))
		n[2] = ft_sigusr(n[2], n[1]++, 1, -10);
	else if ((n[1] > 4) && (n[2] > 0) && (sig == SIGUSR1))
		n[3] = ft_sigusr(n[3], n[2]--, 0, 10);
	else if ((n[1] > 4) && (n[2] > 0) && (sig == SIGUSR2))
		n[3] = ft_sigusr(n[3], n[2]--, 1, 10);
	usleep(100);
	if (kill(info->si_pid, SIGUSR1) == -1)
		ft_putstr_fd("Error", 1);
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

int	main(void)
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
	return (0);
}
