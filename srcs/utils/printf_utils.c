/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elbarry <elbarry@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 12:43:09 by larchimb          #+#    #+#             */
/*   Updated: 2026/01/21 12:18:48 by elbarry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_is_charset(char c)
{
	size_t	i;
	char	*set;

	i = 0;
	set = "cspdiuxX%";
	while (set[i] && c != set[i])
		i++;
	if (i == 9)
		return (0);
	return (1);
}

static size_t	ft_putstr(char *str)
{
	size_t	i;
	size_t	len;

	if (!str)
	{
		write(2, "(null)", 6);
		return (6);
	}
	i = 0;
	len = 0;
	while (str[i])
	{
		write(2, &str[i], 1);
		len++;
		i++;
	}
	return (len);
}

static size_t	ft_putchar(int c)
{
	write(2, &c, 1);
	return (1);
}

static size_t	ft_put_int(int nb)
{
	size_t			len;
	unsigned int	nbr;

	len = 0;
	if (nb < 0)
	{
		write(2, "-", 1);
		nbr = -nb;
		len++;
	}
	else
		nbr = nb;
	len = len + ft_put_unsigned_int(nbr);
	return (len);
}

size_t	ft_write_a_valor(va_list arguments, int c)
{
	size_t	len;

	len = 0;
	if (c == 'c')
		len = ft_putchar(va_arg(arguments, int));
	else if (c == 's')
		len = ft_putstr(va_arg(arguments, char *));
	else if (c == 'p')
		len = ft_print_void_pointer(va_arg(arguments, void *));
	else if (c == 'd' || c == 'i')
		len = ft_put_int((va_arg(arguments, int)));
	else if (c == 'u')
		len = ft_put_unsigned_int((va_arg(arguments, unsigned int)));
	else if (c == 'x')
		len = ft_print_hexa_low((unsigned int)(va_arg(arguments, long)));
	else if (c == 'X')
		len = ft_print_hexa_up((unsigned int)(va_arg(arguments, int)));
	else if (c == '%')
		len = ft_putchar('%');
	return (len);
}
