/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 11:47:26 by artmarti          #+#    #+#             */
/*   Updated: 2023/07/04 11:47:29 by artmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include "ft_printf/ft_printf.h"

size_t	ft_strsize(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_finish_string(char *dest, char *s1)
{
	int	i;

	if (s1 == NULL)
	{
		dest = malloc(sizeof(char) * 1);
		dest[0] = '\0';
		return (dest);
	}
	dest = malloc(sizeof(char) * (ft_strsize(s1) + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin_char(char *s1, char c)
{
	char	*dest;
	size_t	i;

	dest = malloc(sizeof(char) * (ft_strsize(s1) + 2));
	if (!dest)
		return (NULL);
	i = 0;
	if (s1 == NULL)
	{
		dest[i] = c;
		dest[i + 1] = '\0';
		return (dest);
	}
	while (s1[i] != '\0')
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = c;
	dest[i + 1] = '\0';
	free(s1);
	return (dest);
}

void	handler(int sig)
{
	static int	count_bit;
	static char	c;
	static char	*dest;
	char		*str;

	str = NULL;
	if (sig == SIGUSR1)
		c |= 1 << count_bit;
	count_bit++;
	if (count_bit == 8)
	{
		str = dest;
		if (c == '\0')
		{
			dest = ft_finish_string(NULL, str);
			ft_printf("%s\n", dest);
			free(dest);
			dest = NULL;
		}
		else
			dest = ft_strjoin_char(str, c);
		c = 0;
		count_bit = 0;
	}
}

int	main(int argc, char **argv)
{
	if (argc != 1)
		return (0);
	(void)argv;
	signal(SIGUSR1, &handler);
	signal(SIGUSR2, &handler);
	ft_printf("PID is %d\n", getpid());
	while (1)
		;
	return (0);
}
