/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 08:25:07 by artmarti          #+#    #+#             */
/*   Updated: 2023/03/10 08:49:27 by artmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>

int	ft_print_char(char c);
int	ft_print_str(char *s);
int	size_t_countchar(unsigned int n, char c);
int	ft_takecareofp(size_t n, char c);
int	ft_strlen(const char *s);
int	countchar_long(int n);
int	countchar_unsigned_int(unsigned int n);
int	ft_printf(const char *format, ...);

#endif
