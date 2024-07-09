/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 10:56:31 by artmarti          #+#    #+#             */
/*   Updated: 2023/03/10 10:57:29 by artmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

size_t	ft_check_format(const char *format, int a, va_list args)
{
	if (format[a] == 'c')
		return (ft_print_char(va_arg(args, int)));
	else if (format[a] == 's')
		return (ft_print_str(va_arg(args, char *)));
	else if (format[a] == 'p')
		return (ft_takecareofp(va_arg(args, size_t), 'p'));
	else if (format[a] == 'd')
		return (countchar_long(va_arg(args, int)));
	else if (format[a] == 'i')
		return (countchar_long(va_arg(args, int)));
	else if (format[a] == 'u')
		return (countchar_unsigned_int(va_arg(args, unsigned int)));
	else if (format[a] == 'x')
		return (size_t_countchar(va_arg(args, unsigned int), 'x'));
	else if (format[a] == 'X')
		return (size_t_countchar(va_arg(args, unsigned int), 'X'));
	else if (format[a] == '%')
		return (write(1, "%", 1));
	else
		return (ft_print_char(format[a - 1]) + ft_print_char(format[a]));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		j;

	va_start(args, format);
	i = 0;
	j = 0;
	while (i < ft_strlen(format))
	{
		if (format[i] == '%')
		{
			j += ft_check_format(format, i + 1, args);
			i += 2;
		}
		else
		{
			write(1, &format[i], 1);
			i++;
			j++;
		}
	}
	va_end(args);
	return (j);
}
