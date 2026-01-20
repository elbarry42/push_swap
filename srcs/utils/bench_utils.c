/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elbarry <elbarry@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 13:03:30 by elbarry           #+#    #+#             */
/*   Updated: 2026/01/20 15:42:16 by elbarry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"
#include "../../include/push_swap.h"

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

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*s_bis;

	i = 0;
	s_bis = (unsigned char *) s;
	while (i < n)
	{
		s_bis[i] = (unsigned char) c;
		i++;
	}
	return (s);
}

char *detect_complexity(int ops, int n)
{
	double ratio;

	ratio = (double)ops / n;
	if (ratio < 5)
		return ("O(n)");
	if (ratio < 20)
		return ("O(n log n)");
	return ("O(n²)");
}
