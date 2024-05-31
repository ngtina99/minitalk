/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thuy-ngu <thuy-ngu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 16:43:48 by thuy-ngu          #+#    #+#             */
/*   Updated: 2024/02/22 16:54:15 by thuy-ngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include "./libft/libft.h"

void	ft_endsign(int pid)
{
	int	bin[8];
	int	k;
	int	i;

	i = 0;
	while (i < 8)
	{
		bin[i] = 0;
		i++;
	}
	k = 0;
	while (k < 8)
	{
		ft_sendsignal(pid, bin, k);
		k++;
	}
}

void	ft_errorhandler(int sign)
{
	if (sign == 1)
		ft_printf("%s\n", "Error: invalid number of arguments");
	else if (sign == 2)
		ft_printf("%s\n", "Error: invalid PID");
	else if (sign == 3)
		ft_printf("%s\n", "Error: empty message");
	exit(1);
}
