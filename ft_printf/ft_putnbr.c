/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 17:37:42 by artmarti          #+#    #+#             */
/*   Updated: 2023/03/13 17:37:43 by artmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

void	ft_putnbr(int nbr)
{
	char	c;

	if (nbr >= 0 && nbr < 10)
	{
		c = nbr + 48;
		write (1, &c, 1);
	}
	else
	{
		ft_putnbr (nbr / 10);
		ft_putnbr (nbr % 10);
	}
}

void	ft_putnbr_unsigned(unsigned int nbr)
{
	char	c;

	if (nbr == 0)
	{
		c = '0';
		write (1, &c, 1);
	}
	else if (nbr >= 1 && nbr < 10)
	{
		c = nbr + 48;
		write (1, &c, 1);
	}
	else
	{
		ft_putnbr (nbr / 10);
		ft_putnbr (nbr % 10);
	}
}

int	countchar_long(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (write(1, "0", 1));
	else if (n == -2147483648)
		return (write (1, "-2147483648", 11));
	else if (n < 0)
	{
		n = n * -1;
		write (1, "-", 1);
		i++;
	}
	ft_putnbr(n);
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

int	countchar_unsigned_int(unsigned int n)
{
	int	i;

	i = 0;
	if (n == 0)
	{
		write (1, "0", 1);
		return (1);
	}
	ft_putnbr_unsigned(n);
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}
