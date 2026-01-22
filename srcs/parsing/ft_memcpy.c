/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larchimb <larchimb@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 11:05:54 by larchimb          #+#    #+#             */
/*   Updated: 2025/11/20 14:48:56 by larchimb         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*s;
	unsigned char	*d;

	i = 0;
	s = (unsigned char *)src;
	d = (unsigned char *)dest;
	if (!src && !dest)
		return (NULL);
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (d);
}
/*
#include <string.h>
#include <stdio.h>

int	main(void)
{
//	size_t	i = 0;
	size_t	n = 3 ;
//	int	src[] = {};
//	int	dest[n];
	char 	src[] = "";
	char	dest[] = "";
	char	dest2[] = "";

	memcpy(dest, src, n);
	ft_memcpy(dest2, src, n);
	printf("%s\nft :\n%s", dest, dest2);
}
*/
