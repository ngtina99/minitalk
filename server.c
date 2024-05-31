/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thuy-ngu <thuy-ngu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 21:29:27 by thuy-ngu          #+#    #+#             */
/*   Updated: 2024/02/22 16:54:44 by thuy-ngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include "./libft/libft.h"

void	ft_decodesignal(int sig, siginfo_t *info, void *context)
{
	static int unsigned	bits = 0;
	static unsigned int	i = 0;
	unsigned int		value;

	(void)context;
	i = i << 1;
	if (sig == SIGUSR1)
		value = 0;
	else
		value = 1;
	i += value;
	bits++;
	if (bits == 8)
	{
		if (i == 0)
			kill(info->si_pid, SIGUSR1);
		else
			ft_printf("%c", i);
		bits = 0;
		i = 0;
	}
}

int	main(void)
{
	struct sigaction	signal;
	sigset_t			bitset;
	pid_t				pid;

	pid = getpid();
	ft_printf("Server process ID: %d\n", pid);
	sigemptyset(&signal.sa_mask);
	sigaddset(&bitset, SIGUSR1);
	sigaddset(&bitset, SIGUSR2);
	signal.sa_flags = SA_SIGINFO;
	signal.sa_sigaction = ft_decodesignal;
	if (sigaction(SIGUSR1, &signal, NULL) == -1) 
	{
		ft_printf("Error: invalid signal setup");
		exit(1);
	}
	if (sigaction(SIGUSR2, &signal, NULL) == -1)
	{
		ft_printf("Error: invalid signal setup");
		exit(1);
	}
	while (1)
		pause();
	return (0);
}
