/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouhlal <ibouhlal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 18:19:40 by ibouhlal          #+#    #+#             */
/*   Updated: 2022/03/26 23:55:29 by ibouhlal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

t_data	g_data;

void	send_signal(int signum, int pid)
{
	if (kill(pid, signum) == -1)
		exit(EXIT_FAILURE);
}

void	reset_data(void)
{
	g_data.i = 0;
	g_data.s = 0;
	g_data.client_pid = 0;
}

void	handler(int sig, siginfo_t *info, void *ucontext)
{
	(void)ucontext;
	sig -= SIGUSR1;
	if (g_data.client_pid != info -> si_pid)
		reset_data();
	g_data.s = g_data.s << 1 | sig;
	g_data.i++;
	if (g_data.i == 8)
	{
		if (!g_data.s)
			send_signal(SIGUSR1, info->si_pid);
		else
			write (1, &g_data.s, 1);
		reset_data();
	}
	g_data.client_pid = info->si_pid;
}

int	main(void)
{
	struct sigaction	sa;

	reset_data();
	ft_putstr("pid :   ");
	ft_putnbr(getpid());
	ft_putstr("\n");
	sa.sa_sigaction = &handler;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
}
