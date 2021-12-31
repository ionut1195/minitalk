/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itomescu <itomescu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 10:04:24 by itomescu          #+#    #+#             */
/*   Updated: 2021/12/29 17:39:41 by itomescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int	ft_atoi(const char *nptr)
{
	int	result;
	int	sign;
	int	itr;

	sign = 1;
	itr = 0;
	result = 0;
	while ((nptr[itr] >= 7 && nptr[itr] <= 13) || nptr[itr] == ' ')
		itr++;
	if (nptr[itr] == '-')
		sign = -1;
	if (nptr[itr] == '-' || nptr[itr] == '+')
		itr++;
	while (nptr[itr] >= '0' && nptr[itr] <= '9' && nptr[itr])
	{
		result = result * 10 + (nptr[itr] - '0');
		nptr++;
	}
	return (sign * result);
}

void	send_message(const char *str, int s_pid)
{
	unsigned char	mask;
	size_t			i;

	i = 0;
	while (str[i])
	{
		mask = 0b10000000;
		while (mask)
		{
			if (str[i] & mask)
				kill(s_pid, SIGUSR1);
			else
				kill(s_pid, SIGUSR2);
			usleep(50);
			mask = mask >> 1;
		}
		i++;
	}
	exit(EXIT_SUCCESS);
}

void	handle_sigusr(int signal)
{
	if (signal == SIGUSR1)
		;
	else
		exit(EXIT_SUCCESS);
}

int	main(int argc, const char *argv[])
{
	struct sigaction	s;
	int					spid;

	spid = ft_atoi(argv[1]);
	if (argc != 3 || (!spid))
	{
		write(1, "Wrong arguments", 15);
		return (0);
	}
	s.sa_handler = handle_sigusr;
	sigaction(SIGUSR1, &s, NULL);
	sigaction(SIGUSR2, &s, NULL);
	send_message(argv[2], spid);
	while (1)
		pause();
	return (0);
}
