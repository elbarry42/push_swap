/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elbarry <elbarry@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 11:38:16 by larchimb          #+#    #+#             */
/*   Updated: 2026/01/07 16:56:59 by elbarry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

int	len_for_int(int n)
{
	int				len;
	unsigned int	nbr;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		nbr = -n;
		len++;
	}
	else
		nbr = n;
	while (nbr > 0)
	{
		nbr = nbr / 10;
		len++;
	}
	return (len);
}

char	*put_nnegatif_in_ptr(char *ptr, int n, int len)
{
	unsigned int	nbr;

	nbr = -n;
	ptr[0] = '-';
	while (len >= 1)
	{
		ptr[len--] = nbr % 10 + 48;
		nbr = nbr / 10;
	}
	return (ptr);
}

char	*put_npositif_in_ptr(char *ptr, int n, int len)
{
	while (len >= 0)
	{
		ptr[len--] = n % 10 + 48;
		n = n / 10;
	}
	return (ptr);
}

char	*ft_itoa(int n)
{
	int				len;
	char			*ptr;

	len = len_for_int(n);
	ptr = malloc(sizeof(char) * len + 1);
	if (!ptr)
		return (NULL);
	ptr[len] = '\0';
	len--;
	if (n < 0)
		return (put_nnegatif_in_ptr(ptr, n, len));
	else
		return (put_npositif_in_ptr(ptr, n, len));
}
