/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_hexa.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 07:52:40 by artmarti          #+#    #+#             */
/*   Updated: 2023/03/16 07:53:59 by artmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(char c)
{
	int	i;

	write(1, &c, 1);
	i = 1;
	return (i);
}

int	ft_print_str(char *s)
{
	int	i;

	i = 0;
	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (s[i] != '\0')
	{
		write (1, &s[i], 1);
		i++;
	}
	return (i);
}

void	ft_convert_hexa(unsigned int nbr, int b)
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
		ft_convert_hexa(nbr / 16, b);
		ft_convert_hexa(nbr % 16, b);
	}
}

int	size_t_countchar(unsigned int n, char c)
{
	int	i;

	i = 0;
	if (n == 0)
	{
		write (1, "0", 1);
		return (1);
	}
	else if (c == 'x')
		ft_convert_hexa(n, 1);
	else if (c == 'X')
		ft_convert_hexa(n, -1);
	while (n > 0)
	{
		n = n / 16;
		i++;
	}
	return (i);
}
