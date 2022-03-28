/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouhlal <ibouhlal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 12:14:04 by ibouhlal          #+#    #+#             */
/*   Updated: 2022/03/22 15:38:02 by ibouhlal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

static int	ft_is_space(char c)
{
	if (c == '\t' || c == '\n'
		|| c == '\r' || c == '\v'
		|| c == ' ' || c == '\f')
	{
		return (1);
	}
	return (0);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	n;
	int	j;

	j = 0;
	i = 0;
	n = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			n = n * 10 + str[i] - 48;
			i++;
			j++;
		}
		else
			return (-1);
		if (j > 6)
			return (-1);
	}
	return (n);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write (1, &str[i], 1);
		i++;
	}
}

void	ft_putnbr(int nb)
{
	long	nbr;
	char	c;

	nbr = nb;
	if (nbr < 0)
	{
		write (1, "-", 1);
		nbr *= -1;
	}
	if (nbr >= 10)
	{
		ft_putnbr(nbr / 10);
		ft_putnbr(nbr % 10);
	}
	else if (nbr < 10)
	{
		c = nbr + 48;
		write (1, &c, 1);
	}
}
