/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouhlal <ibouhlal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 10:53:32 by ibouhlal          #+#    #+#             */
/*   Updated: 2022/03/23 19:24:15 by ibouhlal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_data
{
	int		i;
	char	s;
	int		client_pid;
}	t_data;

int		ft_atoi(const char *str);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr(char *str);
void	ft_putnbr(int nb);
void	send_byte(char s, int pid);
void	send_message(char *str, int pid);
void	send_mesg(void);
void	handler(int sig, siginfo_t *info, void *ucontext);

#endif
