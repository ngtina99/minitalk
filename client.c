/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thuy-ngu <thuy-ngu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 21:29:21 by thuy-ngu          #+#    #+#             */
/*   Updated: 2024/05/31 19:52:31 by thuy-ngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include "./libft/libft.h"

void	ft_convertbin(int n, int *bin, int k)
{
	if ((n & 1) == 0)
		bin[k] = 0;
	else if ((n & 1) == 1)
		bin[k] = 1;
}

void	ft_sendsignal(int pid, int *bin, int k)
{
	int	signal;

	if (bin[k] == 0)
		signal = SIGUSR1;
	if (bin[k] == 1)
		signal = SIGUSR2;
	if (kill(pid, signal) == -1)
		exit(1);
	usleep(600);
}

void	ft_sendmessage(int pid, char *str)
{
	int	bin[8];
	int	n;
	int	i;
	int	k;

	i = 0;
	while (str[i])
	{
		n = str[i];
		k = 7;
		while (k >= 0)
		{
			ft_convertbin(n, bin, k);
			n = n >> 1;
			k--;
		}
		k = 0;
		while (k < 8)
		{
			ft_sendsignal(pid, bin, k);
			k++;
		}
		i++;
	}
}

void	ft_signalhandler(int signal)
{
	(void)signal;
	ft_printf("%s\n", "The message has been delivered");
}

int	main(int argc, char **argv)
{
	pid_t				pid;
	struct sigaction	signal;

	pid = 0;
	if (argc != 3)
		ft_errorhandler(1);
	pid = ft_atoi(argv[1]);
	if (pid <= 0 || pid > 2147483647)
		ft_errorhandler(2);
	signal.sa_handler = ft_signalhandler;
	sigaction(SIGUSR1, &signal, NULL);
	sigaction(SIGUSR2, &signal, NULL);
	if (argv[2][0])
		ft_sendmessage(pid, argv[2]);
	else
		ft_errorhandler(3);
	ft_endsign(pid);
	return (0);
}
