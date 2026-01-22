/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larchimb <larchimb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 12:17:54 by larchimb          #+#    #+#             */
/*   Updated: 2026/01/22 13:23:21 by larchimb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	size_t	len_of_s1;
	size_t	len_of_s2;
	size_t	len;

	if (!s1 || !s2 || ft_strncmp(s2, "", 1) == 0)
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
