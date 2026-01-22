/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larchimb <larchimb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 12:17:54 by larchimb          #+#    #+#             */
/*   Updated: 2026/01/22 15:47:32 by larchimb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	is_empty(const char *ptr)
{
	int	i;

	i = 0;
	if (ft_strncmp(ptr, "", 1) == 0)
		return (1);
	while (ptr[i])
	{
		if (ptr[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	size_t	len_of_s1;
	size_t	len_of_s2;
	size_t	len;

	if (!s1 || !s2 || is_empty(s2) == 1)
		return (NULL);
	len_of_s1 = ft_strlen(s1);
	len_of_s2 = ft_strlen(s2);
	len = len_of_s1 + len_of_s2;
	ptr = malloc(sizeof(char) * len + 2);
	if (!ptr)
		return (NULL);
	ft_memcpy(ptr, s1, len_of_s1);
	ft_memcpy(ptr + len_of_s1, s2, len_of_s2);
	ptr[len] = ' ';
	ptr[len + 1] = '\0';
	return (ptr);
}
