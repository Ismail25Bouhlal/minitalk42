/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouhlal <ibouhlal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 12:33:58 by ibouhlal          #+#    #+#             */
/*   Updated: 2022/03/26 23:52:55 by ibouhlal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	check_pid(char *c)
{
	int	i;
	int	pid;

	pid = ft_atoi(c);
	if (pid <= 0)
		return (-1);
	i = kill(pid, 0);
	if (i < 0)
		return (-1);
	return (pid);
}

void	send_byte(char c, int pid)
{
	unsigned char	bit;

	bit = 128;
	while (bit)
	{
		if (bit & c)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		bit >>= 1;
		usleep (900);
	}
}

void	send_message(char *str, int pid)
{
	int	i;

	i = 0;
	while (str[i])
	{
		send_byte(str[i], pid);
		i++;
	}
	send_byte(str[i], pid);
}

int	main(int ac, char *av[])
{
	int		server_pid;
	char	*msg;

	if (ac != 3)
		return (ft_putstr("ARGUMENT INCORRECT !"), 0);
	server_pid = check_pid(av[1]);
	if (server_pid <= 0)
		return (ft_putstr("PID INCORRECT !"), 0);
	msg = av[2];
	send_message (msg, server_pid);
	return (0);
}
