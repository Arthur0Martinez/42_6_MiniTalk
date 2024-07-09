/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 11:47:15 by artmarti          #+#    #+#             */
/*   Updated: 2023/07/04 11:47:16 by artmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	j;
	int	resultat;

	i = 0;
	j = 1;
	resultat = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == 43 || nptr[i] == 45)
	{
		if (nptr[i] == '-')
			j *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		resultat *= 10;
		resultat += (nptr[i] - 48);
		i++;
	}
	if (resultat == 0)
		return (0);
	return (resultat * j);
}

void	take_char(int pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if (c & (1 << bit))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(250);
		bit++;
	}
}

void	take_str(int pid, char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		take_char(pid, str[i]);
		i++;
	}
	take_char(pid, str[i]);
}

int	main(int argc, char **argv)
{
	if (argc != 3)
		return (0);
	take_str(ft_atoi(argv[1]), argv[2]);
	return (0);
}
