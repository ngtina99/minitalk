/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thuy-ngu <thuy-ngu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 21:29:39 by thuy-ngu          #+#    #+#             */
/*   Updated: 2024/02/22 16:53:19 by thuy-ngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h> //SIGfunctions
# include <stdlib.h> //free, malloc
# include <unistd.h> //write+getpid

void	ft_endsign(int pid);
void	ft_errorhandler(int sign);
void	ft_sendsignal(int pid, int *bin, int k);

#endif