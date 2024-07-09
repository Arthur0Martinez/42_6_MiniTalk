/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_takecareofp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 09:59:41 by artmarti          #+#    #+#             */
/*   Updated: 2023/03/22 09:59:46 by artmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_convert_myp(size_t nbr, int b)
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
	else if (nbr >= 10 && nbr < 16)
	{
		if (b == 1)
			c = nbr + 87;
		else if (b == -1)
			c = nbr + 55;
		write (1, &c, 1);
	}
	else
	{
		ft_convert_myp(nbr / 16, b);
		ft_convert_myp(nbr % 16, b);
	}
}

void	ft_convert_hexa_adresse(size_t nbr, int b)
{
	write (1, "0", 1);
	write (1, "x", 1);
	ft_convert_myp(nbr, b);
}

int	ft_takecareofp(size_t n, char c)
{
	int	i;

	i = 0;
	if (c == 'p')
	{
		if (!n)
		{
			write (1, "(nil)", 5);
			return (5);
		}
		i += 2;
		ft_convert_hexa_adresse(n, 1);
	}
	if (n == 0)
	{
		write (1, "0", 1);
		return (1);
	}
	while (n > 0)
	{
		n = n / 16;
		i++;
	}
	return (i);
}
