/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elbarry <elbarry@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 10:24:30 by larchimb          #+#    #+#             */
/*   Updated: 2026/01/21 12:19:44 by elbarry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_put_unsigned_int(unsigned int nb)
{
	int		i;
	size_t	len;
	char	str[10];

	i = 1;
	len = 0;
	str[0] = nb % 10 + '0';
	while (nb >= 10)
	{
		nb = nb / 10;
		str[i] = nb % 10 + '0';
		i++;
	}
	while (i >= 1)
	{
		write(2, &str[i - 1], 1);
		len++;
		i--;
	}
	return (len);
}

size_t	ft_print_hexa_low(unsigned long nb)
{
	unsigned int	len;
	char			*base;

	len = 1;
	base = "0123456789abcdef";
	if (nb > 16 - 1)
		len = len + ft_print_hexa_low(nb / 16);
	write(2, &base[nb % 16], 1);
	return (len);
}

size_t	ft_print_hexa_up(unsigned int nb)
{
	unsigned int	len;
	char			*base;

	len = 1;
	base = "0123456789ABCDEF";
	if (nb > 16 - 1)
		len = len + ft_print_hexa_up(nb / 16);
	write(2, &base[nb % 16], 1);
	return (len);
}

size_t	ft_print_void_pointer(void *ptr)
{
	size_t	len;

	if (!ptr)
	{
		write(2, "(nil)", 5);
		return (5);
	}
	len = 0;
	write(2, "0x", 2);
	len += 2;
	len += ft_print_hexa_low((unsigned long)ptr);
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	arguments;
	size_t	i;
	size_t	counter;

	if (!str)
		return (-1);
	counter = 0;
	va_start(arguments, str);
	i = 0;
	while (str[i])
	{
		if (str[i + 1] && str[i] == '%' && ft_is_charset(str[i + 1]) == 1)
		{
			counter += ft_write_a_valor(arguments, str[i + 1]);
			i = i + 2;
		}
		else
		{
			write(1, &str[i++], 1);
			counter++;
		}
	}
	va_end(arguments);
	return (counter);
}
