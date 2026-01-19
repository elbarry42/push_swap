/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elbarry <elbarry@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 13:03:30 by elbarry           #+#    #+#             */
/*   Updated: 2026/01/19 15:22:51 by elbarry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"
#include "../../include/push_swap.h"

void	ft_putchar_fd(char c, int fd)
{
	write (fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	if (!s)
	{
		write(2, "null", 4);
		return ;
	}
	i = 0;
	while (s[i])
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	long	tmp;

	tmp = n;
	if (tmp < 0)
	{
		tmp = -tmp;
		ft_putchar_fd('-', fd);
	}
	if (tmp < 10)
		ft_putchar_fd((tmp + 48), fd);
	else
	{
		ft_putnbr_fd((tmp / 10), fd);
		ft_putchar_fd(((tmp % 10) + 48), fd);
	}
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	if (!s1 || !s2)
		return (-1);
	
	i = 0;
	while (s1[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	ft_putdouble_fd(double n, int fd)
{
	int	integer_part;
	int	decimal_part;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = -n;
	}
	integer_part = (int)n;
	// On récupère les 2 chiffres après la virgule
	decimal_part = (int)((n - integer_part) * 100 + 0.5);
	ft_putnbr_fd(integer_part, fd);
	ft_putchar_fd('.', fd);
	if (decimal_part < 10)
		ft_putchar_fd('0', fd);
	ft_putnbr_fd(decimal_part, fd);
}

// #include <stdio.h>
// int main(void)
// {
// 	printf("%d", ft_strcmp(NULL, "barry"));
// }