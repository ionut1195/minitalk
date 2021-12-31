/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itomescu <itomescu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 10:04:19 by itomescu          #+#    #+#             */
/*   Updated: 2021/12/29 17:51:14 by itomescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	handle_sigusr(int signal, siginfo_t *siginfo, void *v)
{
	static unsigned char	i = 0;
	static unsigned char	mask = 0b10000000;

	(void)v;
	i |= mask * (signal == SIGUSR1);
	mask = mask >> 1;
	if (!mask)
	{
		write(1, &i, 1);
		if (!i)
			kill(siginfo->si_pid, SIGUSR2);
		mask = 0b10000000;
		i = 0;
	}
}

int	main(void)
{
	struct sigaction	s;

	ft_printf("server pid - %d\n", getpid());
	s.sa_flags = SA_SIGINFO;
	s.sa_sigaction = handle_sigusr;
	sigaction(SIGUSR1, &s, NULL);
	sigaction(SIGUSR2, &s, NULL);
	while (1)
		pause();
	return (0);
}
